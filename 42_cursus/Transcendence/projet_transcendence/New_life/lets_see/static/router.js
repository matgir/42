document.addEventListener("DOMContentLoaded", () => {

  // Add a global path tracker
  window.currentPath = window.location.pathname + window.location.search;

  // Add a global function to get URL params from the SPA path
  window.getURLParams = function() {
    const queryString = window.currentPath.includes('?') ? 
      window.currentPath.split('?')[1] : '';
    return new URLSearchParams(queryString);
  };

  const loadPage = async (htmlPath, formData, updateHistory = true) => {
    try {
      console.log(
        `Loading page: ${htmlPath} with updateHistory=${updateHistory}`
      );

      // Update global path information
      window.currentPath = htmlPath;

      // Prefix API paths for content loading
      const apiPath = htmlPath.startsWith('/api/') ? htmlPath : `/api${htmlPath}`;

      // Load HTML
      let htmlResponse;
      let csrftoken = null;

      // Safely check if CSRF token is available
      const csrfElement = document.querySelector("[name=csrfmiddlewaretoken]");
      if (csrfElement) {
        csrftoken = csrfElement.value;
      }

      if (formData != null && csrftoken) {
        console.log("formData is not null and csrftoken is available");
        // Determine the appropriate content type and format based on formData type
        let headers = { 
          "X-CSRFToken": csrftoken,
          "X-Requested-With": "XMLHttpRequest"
        };
        
        // Set appropriate Content-Type header based on formData type
        if (formData instanceof FormData) {
          // FormData is already properly formatted for multipart/form-data
          // Don't set Content-Type as browser will set it with boundary
        } else if (typeof formData === 'object' && !(formData instanceof FormData)) {
          // JSON data
          headers["Content-Type"] = "application/json";
          formData = JSON.stringify(formData);
        } else if (typeof formData === 'string') {
          // URL encoded form data
          headers["Content-Type"] = "application/x-www-form-urlencoded";
        }
        
        htmlResponse = await fetch(apiPath, {
          method: "POST",
          body: formData,
          headers: headers,
          mode: "same-origin", // Do not send CSRF token to another domain.
        });
      } else {
        htmlResponse = await fetch(apiPath);
      }
      
      // Handle redirects (e.g., 302 Found)
      // fetch automatically follows redirects, so check response.redirected
      if (htmlResponse.redirected) {
        const redirectUrl = new URL(htmlResponse.url); // URL after following redirects
        // Ensure we are using the path relative to the domain for SPA routing
        const newPath = redirectUrl.pathname + redirectUrl.search + redirectUrl.hash; 
        console.log(`Redirect detected from ${apiPath} to: ${newPath}. Navigating...`);
        // Navigate to the new path, letting that navigateTo call handle history
        navigateTo(newPath, null); 
        return 'redirected'; // Signal that navigation was handled due to redirect
      }

      // If route doesn't exist, redirect to 404
      if (!htmlResponse.ok) {
        if (htmlResponse.status === 404) {
          console.error(`Page not found: ${htmlPath}`);
          // Load 404 page
          return loadPage("/404/", null, updateHistory);
        }
        throw new Error(`Failed to load page: ${htmlResponse.status} ${htmlResponse.statusText}`);
      }
      
      const html = await htmlResponse.text();

      // Create a temporary element to parse the HTML
      const tempDiv = document.createElement("div");
      tempDiv.innerHTML = html;

      // Extract the content to insert into main container
      // We need to keep container content clean (without <script> and <link> tags)
      // so that we don't load duplicated scripts/styles
      const contentOnly = tempDiv.cloneNode(true);

      // Remove all script and link tags from the content we'll insert
      contentOnly
        .querySelectorAll('script, link[rel="stylesheet"]')
        .forEach((node) => {
          node.remove();
        });

      // Update the content
      document.getElementById("app-content").innerHTML = contentOnly.innerHTML;

      // Find CSS links in the parsed HTML
      const cssLinks = Array.from(
        tempDiv.querySelectorAll('link[rel="stylesheet"]')
      );

      // Find JS scripts in the parsed HTML
      const jsScripts = Array.from(tempDiv.querySelectorAll("script[src]"));

      // Remove old style and add new styles from the parsed HTML
      const oldStyles = document.querySelectorAll("[data-dynamic-style]");
      oldStyles.forEach((style) => style.remove());

      cssLinks.forEach((cssLink, index) => {
        const style = document.createElement("link");
        style.setAttribute("data-dynamic-style", "true");
        style.rel = "stylesheet";
        style.href = cssLink.getAttribute("href");
        document.head.appendChild(style);
      });

      const oldScripts = document.querySelectorAll("[data-dynamic-script]");

      if (window.currentModuleCleanup) {
        window.currentModuleCleanup();
        window.currentModuleCleanup = null;
      }

      // Remove old scripts and add new scripts from the parsed HTML
      oldScripts.forEach((script) => script.remove());

      // Load scripts sequentially to maintain order
      for (let i = 0; i < jsScripts.length; i++) {
        const jsScript = jsScripts[i];
        await new Promise((resolve) => {
          const script = document.createElement("script");
          script.setAttribute("data-dynamic-script", "true");
          script.src = jsScript.getAttribute("src") + "?v=" + Date.now();

          // Preserve all original attributes, especially type="module"
          Array.from(jsScript.attributes).forEach((attr) => {
            if (attr.name !== "src" && attr.name !== "id") {
              script.setAttribute(attr.name, attr.value);
            }
          });

          script.onload = resolve;
          script.onerror = resolve; // Continue loading other scripts even if one fails
          document.body.appendChild(script);
        });
      }

      return true; // Successful page load

    } catch (err) {
      console.error("Loading error:", err);
      document.getElementById("app-content").innerHTML = `
        <div class="error-message">
          Loading error: ${err.message}
        </div>
      `;
      return false; // Failed page load
    }
  };

  // Track current page for fallback purposes
  let currentPage = "";

  // Function to navigate to a page and update browser history
  const navigateTo = async (path, formData = null) => {
    // Special case for root path
    const htmlPath = path === "/" ? "/home/" : path;

    // Prepare state object, but don't push history yet
    const stateObj = {
      path: path,
      formData: formData,
    };

    console.log(
      `Attempting navigation to: ${path}` // Updated log message
    );

    // Set global path variable - might be better to do this only on successful load?
    // window.currentPath = path; // Moved down

    // Load the page content first to make sure it exists/handle redirects
    const loadResult = await loadPage(htmlPath, formData, true); // Pass true for updateHistory intent initially
    
    // Only update history if page load was successful and not a redirect
    if (loadResult === true) { // Explicitly check for true success
      console.log(`Successfully loaded ${htmlPath}. Pushing state for ${path}.`);
      window.currentPath = path; // Update global path tracking
      path = path.replace('/api/', '/');
      window.history.pushState(stateObj, "", path);
      currentPage = path;
    } else if (loadResult === 'redirected') {
      console.log(`Redirect occurred while loading ${htmlPath}. Navigation and history handled by the redirect target.`);
      // History is handled by the navigateTo call triggered inside loadPage
    } else {
      // loadResult might be false or undefined if loadPage failed
      console.error(`Failed to load page ${htmlPath} (result: ${loadResult}). Navigation aborted for ${path}.`);
       // Consider if any cleanup or error display is needed here
    }
  };

  // Handler for form submissions
  const handleFormSubmit = (event) => {
    event.preventDefault();
    const form = event.target;
    const action = form.getAttribute('action') || window.location.pathname + window.location.search;
    const method = form.getAttribute('method')?.toUpperCase() || 'GET';
    
    console.log(`Form submission: ${method} ${action}`);
    
    if (method === 'GET') {
      // For GET requests, we build a query string and navigate
      const formData = new FormData(form);
      const queryParams = new URLSearchParams(formData).toString();
      const targetPath = action + (queryParams ? `?${queryParams}` : '');
      navigateTo(targetPath, null);
    } else if (method === 'POST') {
      // For POST requests, gather form data and send via loadPage
      const formData = new FormData(form);
      navigateTo(action, formData);
    }
  };

  // Event delegation for dynamically loaded content
  document.body.addEventListener("click", (event) => {
    // Find the closest anchor element to the clicked target
    let targetLink = event.target.closest('a');
    
    if (!targetLink) return;
    
    const href = targetLink.getAttribute('href');
    
    // Skip if no href, external link, or non-routing link
    if (!href || href.startsWith('http') || href.startsWith('#') || href.startsWith('mailto:') || href.startsWith('data:')) {
      return;
    }
    
    
    event.preventDefault();

    console.log(`Click on link with href: ${href}`);
    
    // Use the navigate function to handle both page loading and history
    navigateTo(href, null);
  });

  // Handle form submissions
  document.body.addEventListener("submit", (event) => {
    const form = event.target;
    const action = form.getAttribute('action') || window.location.pathname + window.location.search;
    console.log(`Form submission: ${action} with form data:`, form.elements);
    
    // Skip if the form has data-no-spa attribute
    if (form.hasAttribute('data-no-spa')) {
      return;
    }
    
    handleFormSubmit(event);
  });

  // Handle browser back/forward button
  window.addEventListener("popstate", (event) => {
    console.log("Popstate event triggered, state:", event.state);

    // First, try to use the state object to find the page
    if (event.state && event.state.path) {
      console.log(`Popstate: Loading page with path ${event.state.path}`);
      currentPage = event.state.path;
      window.currentPath = event.state.path;
      const htmlPath = event.state.path === "/" ? "/home/" : event.state.path;
      loadPage(htmlPath, event.state.formData, false);
      return;
    }

    // If no state exists, try to determine the page from URL
    const path = window.location.pathname + window.location.search;
    console.log(`Popstate: No state found, trying to match path: ${path}`);
    window.currentPath = path;

    // Special case for root path
    if (path === "/" || path === "") {
      console.log("Popstate: Handling root path");
      // Load home content for root path
      loadPage("/home/", null, false);
      return;
    }

    // Try to load the page directly - if it fails, 404 handling will take care of it
    loadPage(path, null, false);
  });

  // Initialize history for the first page load
  const initializeHistory = () => {
    // Determine the initial page based on URL
    const path = window.location.pathname + window.location.search;
    console.log(`Initializing history with path: ${path}`);
    window.currentPath = path;

    // Special case for root path
    if (path === "/" || path === "") {
      console.log("Initializing with root path");
      // Load home content on initial page load
      loadPage("/home/", null, false);
      const stateObj = { path: "/", formData: null };
      window.history.replaceState(stateObj, "", "/");
      currentPage = "/";
      window.currentPath = "/";
      return;
    }

    // Try to load the current path - 404 handling will kick in if needed
    loadPage(path, null, false).then(success => {
      if (success) {
        console.log(`Initializing history state with path: ${path}`);
        const stateObj = { path: path, formData: null };
        window.history.replaceState(stateObj, "", path);
        currentPage = path;
      }
    });
  };

  // Initialize the history state for the first page
  initializeHistory();
});