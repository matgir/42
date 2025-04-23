document.addEventListener('DOMContentLoaded', () => {
  const loadPage = async (htmlPath, cssPath, jsPath, params) => {
    try {
      // Load HTML
      let htmlResponse
      const csrftoken = document.querySelector('[name=csrfmiddlewaretoken]').value;
      if (params != null) {
        htmlResponse = await fetch(htmlPath, {
          method: 'POST',
          body: params,
          headers: {'X-CSRFToken': csrftoken},
          mode: 'same-origin' // Do not send CSRF token to another domain.
        });
      } else {
        htmlResponse = await fetch(htmlPath);
      }
      if (!htmlResponse.ok) throw new Error('HTML not found');
      const html = await htmlResponse.text();
      
      document.getElementById('app-content').innerHTML = html;

      // Load CSS
      const oldStyle = document.querySelector('#page-style');
      if (oldStyle) oldStyle.remove();

      const style = document.createElement('link');
      style.id = 'page-style';
      style.rel = 'stylesheet';
      style.href = cssPath;
      document.head.appendChild(style);

      // Load JS
      const oldScript = document.querySelector('#page-script');
      if (oldScript) oldScript.remove();

      const script = document.createElement('script');
      script.id = 'page-script';
      script.src = jsPath;
      script.type = 'module';  // Important for ES6 modules
      script.defer = true;
      document.body.appendChild(script);

    } catch (err) {
      console.error('Loading error:', err);
      document.getElementById('app-content').innerHTML = `
        <div class="error-message">
          Loading error: ${err.message}
        </div>
      `;
    }
  };

  // Map IDs to their respective page loading configurations
  const pageRoutes = {
    'go_to_signup_page': ['/go_to_signup_page/', '/static/css/signup.css', '/static/js/home.js'],
    'avatar': ['/avatar/', '/static/css/avatar.css', '/static/js/avatar.js'],
    'avatar': ['/avatar/', '/static/css/avatar.css', '/static/js/avatar.js'],
    'game_home': ['/game_home/', '/static/css/game_home.css', '/static/js/game_home.js'],
    'pong': ['/pong/', '/static/css/pong.css', '/static/js/pong.js'],
    'profil': ['/users/profil/', '/users/static/users/css/profil.css', '/static/js/home.js'],
    'user_profil': ['/users/user_profil/', '/users/static/users/css/profil.css', '/users/static/users/js/profil.js'],
    'testeur': ['/testeur/', '/static/css/testeur.css', '/static/js/testeur.js'],
    '1_space_cubes': ['/1_space_cubes/', '/static/css/1_space_cubes.css', '/static/js/1_space_cubes.js'],
    '2_pink_cubes': ['/2_pink_cubes/', '/static/css/2_pink_cubes.css', '/static/js/2_pink_cubes.js'],
    '3_blue_rubix': ['/3_blue_rubix/', '/static/css/3_blue_rubix.css', '/static/js/3_blue_rubix.js'],
    '4_fall': ['/4_fall/', '/static/css/4_fall.css', '/static/js/4_fall.js'],
    '5_torus_knot': ['/5_torus_knot/', '/static/css/5_torus_knot.css', '/static/js/5_torus_knot.js'],
    '6_torus': ['/6_torus/', '/static/css/6_torus.css', '/static/js/6_torus.js'],





    // Add other routes here if needed, e.g., 'home', 'go_to_signin_page' from commented code
  };

  // Event delegation for dynamically loaded content
  document.body.addEventListener('click', (event) => {
    const targetId = event.target.id;
    let view_param = null;
    view_param = document.getElementById(event.target.id).getAttribute("params");
    console.log(view_param)
    

    if (targetId && pageRoutes[targetId]) {
        event.preventDefault(); // Prevent default link behavior if the target is an anchor
        if (targetId === 'avatar') {
          console.log("avatar clicked via delegation");
        }
        const [htmlPath, cssPath, jsPath] = pageRoutes[targetId];
        loadPage(htmlPath, cssPath, jsPath, view_param);
    }
    // Handle other clicks if necessary
  });


  // --- Remove or comment out old direct event listeners ---

  // document.getElementById('home')?.addEventListener('click', () => 
  //   loadPage(
  //     '/templates/base.html',
  //     '/static/css/home.css',
  //     '/static/js/home.js'
  //   )
  // );

  // document.getElementById('go_to_signin_page')?.addEventListener('click', () => 
  //   loadPage(
  //     '/go_to_signin_page/',
  //     '/static/css/home.css',
  //     '/static/js/home.js'
  //   )
  // );

  // !!!! ATTENTION , vont tous les deux a la home , et son inutilsé car 
  // on fait un HREF , pb a corriger pour une spa mais pour 
  // l'instant nik sa grande daronne


  // document.getElementById('go_to_signup_page')?.addEventListener('click', () => 
  //   loadPage(
  //     '/go_to_signup_page/',
  //     '/static/css/signup.css',
  //     '/static/js/home.js'
  //   )
  // );

  // document.getElementById('avatar')?.addEventListener('click', () => 
  //   loadPage(
  //     '/avatar/',
  //     '/static/css/avatar.css',
  //     '/static/js/avatar.js'
  //   ) 
  // );

  // document.getElementById('avatar')?.addEventListener('click', () => {
  //   console.log("avatar");
  //   return loadPage(
  //     '/avatar/',
  //     '/static/css/avatar.css',
  //     '/static/js/avatar.js'
  //   ) }
  // );

  // document.getElementById('game_home')?.addEventListener('click', () => 
  //   loadPage(
  //     '/game_home/',
  //     '/static/css/game_home.css',
  //     '/static/js/game_home.js'
  //   )
  // );

  // document.getElementById('pong')?.addEventListener('click', () => 
  //   loadPage(
  //     '/pong/',
  //     '/static/css/pong.css',
  //     '/static/js/pong.js'
  //   )
  // );

  // document.getElementById('profil')?.addEventListener('click', () => 
  //   loadPage(
  //     '/profil/',
  //     '/static/css/profil.css',
  //     '/static/js/profil.js'
  //   )
  // );

  // document.getElementById('testeur')?.addEventListener('click', () => 
  //   loadPage(
  //     '/testeur/',
  //     '/static/css/testeur.css',
  //     '/static/js/testeur.js'
  //   )
  // );


  // document.getElementById('avatar_update')?.addEventListener('click', () => {
  //   loadPage(
  //     '/avatar/', 
  //     '/static/css/avatar.css',
  //      '/static/js/avatar.js');
  // });
  // !!!! ATTENTION  si tu fais ça tu utilise deux fois l'id "avatar" et ça va pas link 





  // document.getElementById("avatar").addEventListener("click", function(e) {
  //   e.preventDefault();
  //   loadPage(
  //     '/profil/avatar/',       // Le chemin vers le HTML
  //     '/static/css/avatar.css', // Le chemin vers le CSS
  //     '/static/js/avatar.js'    // Le chemin vers le JS
  //   );
});




