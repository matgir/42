document.addEventListener("DOMContentLoaded", () => {

  // Configuration for router
  const routerConfig = {
    // Paths that should bypass the SPA router completely
    excludedPaths: [
      '/api/users/accounts/logout/',
      '/api/users/accounts/login/',
      '/api/users/accounts/signup/'
    ],
    
    // Check if a path should be excluded from SPA routing
    isExcludedPath: function(path) {
      return this.excludedPaths.some(excluded => 
        path.startsWith(excluded) || path === excluded
      );
    }
  };

  const loadPage = async (htmlPath, params, updateHistory = true) => {
    try {
      console.log(
        `Loading page: ${htmlPath} with updateHistory=${updateHistory}`
      );

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

      if (params != null && csrftoken) {
        // Determine the appropriate content type and format based on params type
        let headers = { 
          "X-CSRFToken": csrftoken,
          "X-Requested-With": "XMLHttpRequest"
        };
        
        // Set appropriate Content-Type header based on params type
        if (params instanceof FormData) {
          // FormData is already properly formatted for multipart/form-data
          // Don't set Content-Type as browser will set it with boundary
        } else if (typeof params === 'object' && !(params instanceof FormData)) {
          // JSON data
          headers["Content-Type"] = "application/json";
          params = JSON.stringify(params);
        } else if (typeof params === 'string') {
          // URL encoded form data
          headers["Content-Type"] = "application/x-www-form-urlencoded";
        }
        
        htmlResponse = await fetch(apiPath, {
          method: "POST",
          body: params,
          headers: headers,
          mode: "same-origin", // Do not send CSRF token to another domain.
        });
      } else {
        htmlResponse = await fetch(apiPath);
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
  const navigateTo = async (path, params = null) => {
    // Special case for root path
    const htmlPath = path === "/" ? "/home/" : path;

    // Update browser history
    const stateObj = {
      path: path,
      params: params,
    };

    console.log(
      `Navigating to: ${path}, pushing state:`,
      stateObj
    );

    // Load the page content first to make sure it exists
    const success = await loadPage(htmlPath, params);
    
    if (success) {
      // Only update history if page load was successful
      window.history.pushState(stateObj, "", path);
      currentPage = path;
    }
  };

  // Handler for form submissions
  const handleFormSubmit = (event) => {
    event.preventDefault();
    const form = event.target;
    const action = form.getAttribute('action') || window.location.pathname;
    const method = form.getAttribute('method')?.toUpperCase() || 'GET';
    
    console.log(`Form submission: ${method} ${action}`);
    
    if (method === 'GET') {
      // For GET requests, we build a query string and navigate
      const formData = new FormData(form);
      const queryParams = new URLSearchParams(formData).toString();
      const targetPath = action + (queryParams ? `?${queryParams}` : '');
      navigateTo(targetPath);
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
    if (!href || href.startsWith('http') || href.startsWith('#') || href.startsWith('mailto:')) {
      return;
    }
    
    // Skip if the path is excluded from SPA routing
    if (routerConfig.isExcludedPath(href)) {
      console.log(`Path excluded from SPA routing: ${href}`);
      return;
    }
    
    event.preventDefault();
    
    // Check if the link has data-params attribute for JSON data
    const paramsAttr = targetLink.getAttribute('data-params');
    let params = null;
    
    if (paramsAttr) {
      try {
        // Try to parse as JSON if it looks like JSON
        if (paramsAttr.trim().startsWith('{')) {
          params = JSON.parse(paramsAttr);
        } else {
          params = paramsAttr;
        }
      } catch (e) {
        // If parsing fails, use as-is
        params = paramsAttr;
      }
    }
    
    console.log(`Click on link with href: ${href}, params:`, params);
    
    // Use the navigate function to handle both page loading and history
    navigateTo(href, params);
  });

  // Handle form submissions
  document.body.addEventListener("submit", (event) => {
    const form = event.target;
    const action = form.getAttribute('action') || window.location.pathname;
    
    // Skip if the form has data-no-spa attribute
    if (form.hasAttribute('data-no-spa')) {
      return;
    }
    
    // Skip if the action path is excluded from SPA routing
    if (routerConfig.isExcludedPath(action)) {
      console.log(`Form action excluded from SPA routing: ${action}`);
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
      const htmlPath = event.state.path === "/" ? "/home/" : event.state.path;
      loadPage(htmlPath, event.state.params, false);
      return;
    }

    // If no state exists, try to determine the page from URL
    const path = window.location.pathname;
    console.log(`Popstate: No state found, trying to match path: ${path}`);

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
    const path = window.location.pathname;
    console.log(`Initializing history with path: ${path}`);

    // Skip SPA initialization if the current path is excluded
    if (routerConfig.isExcludedPath(path)) {
      console.log(`Current path excluded from SPA routing: ${path}`);
      return;
    }

    // Special case for root path
    if (path === "/" || path === "") {
      console.log("Initializing with root path");
      // Load home content on initial page load
      loadPage("/home/", null, false);
      const stateObj = { path: "/", params: null };
      window.history.replaceState(stateObj, "", "/");
      currentPage = "/";
      return;
    }

    // Try to load the current path - 404 handling will kick in if needed
    loadPage(path, null, false).then(success => {
      if (success) {
        console.log(`Initializing history state with path: ${path}`);
        const stateObj = { path: path, params: null };
        window.history.replaceState(stateObj, "", path);
        currentPage = path;
      }
    });
  };

  // Initialize the history state for the first page
  initializeHistory();
});