from rest_framework_simplejwt.tokens import RefreshToken
from django.utils.deprecation import MiddlewareMixin
from django.contrib.auth import get_user_model
import jwt
from django.conf import settings
from rest_framework_simplejwt.exceptions import InvalidToken, TokenError
from django.utils.functional import SimpleLazyObject
from django.contrib.auth.models import AnonymousUser
from django.http import JsonResponse, HttpResponse
from django.shortcuts import redirect
from functools import wraps
import re
from django.contrib import messages
from django.utils.translation import gettext as _

def get_tokens_for_user(user):
    """
    Generate JWT tokens for a given user
    
    Args:
        user: The user to generate tokens for
        
    Returns:
        dict: A dictionary containing access and refresh tokens
    """
    refresh = RefreshToken.for_user(user)
    
    return {
        'refresh': str(refresh),
        'access': str(refresh.access_token),
    }

def get_user_from_jwt(request):
    User = get_user_model()
    user = None
    
    token = request.COOKIES.get('jwt_access')
    
    if not token and 'HTTP_AUTHORIZATION' in request.META:
        auth = request.META['HTTP_AUTHORIZATION'].split()
        if len(auth) == 2 and auth[0].lower() == 'bearer':
            token = auth[1]
            
    if token:
        try:
            payload = jwt.decode(
                token, 
                settings.SECRET_KEY,
                algorithms=['HS256']
            )
            user_id = payload.get('user_id')
            if user_id:
                user = User.objects.get(id=user_id)
        except (jwt.PyJWTError, User.DoesNotExist):
            pass
            
    return user or AnonymousUser()

class JWTAuthenticationMiddleware(MiddlewareMixin):
    def process_request(self, request):
        request.user = SimpleLazyObject(lambda: get_user_from_jwt(request))

class JWTProtectionMiddleware(MiddlewareMixin):
    """
    Middleware that enforces JWT authentication for all paths
    except for the explicitly excluded ones.
    """
    
    # Paths that are always allowed without authentication
    PUBLIC_PATHS = [
        r'^/$',                        # Home page
        r'^/home/?$',                  # Home page alternative
        r'^/api/home/?$',              # Home page API route
        r'^/credits/?$',               # Credits page 
        r'^/api/credits/?$',           # Credits page API route
        r'^/4_fall/?$',                # 4_fall page (Credits)
        r'^/api/4_fall/?$',            # 4_fall API route
        r'^/users/accounts/login/?$',  # Login page
        r'^/users/accounts/signup/?$', # Signup page
        r'^/api/users/accounts/login/?$',  # Login API endpoint
        r'^/api/users/accounts/signup/?$', # Signup API endpoint



        r'^/api/users/accounts/two_factor/login/?$', # Login 2FA API endpoint

        # Update these paths to match your actual URL structure
        r'^/fortytwo/?$',                     # Base 42 route
        r'^/fortytwo/oauth_callback/?$',      # 42 OAuth callback 
        r'^/fortytwo/fortytwo_username/?$',   # 42 username setup
        
        # Keep the API versions if they are also used
        # r'^/api/fortytwo/?$',   
        # r'^/api/fortytwo/oauth_callback/?$',
        # r'^/api/fortytwo/fortytwo_username/?$',



        r'^/static/.*$',               # Static files
        r'^/media/.*$',                # Media files
        r'^/jsi18n/?$',                # JavaScript i18n catalog
        r'^/setlang/?$',               # Set language
        r'^/api/users/token/refresh/?$',  # Token refresh endpoint
        r'^/api/go_to_signup_page/?$',    # Signup page redirect
        r'^/users/token/refresh/?$',      # Token refresh page
    ]
    
    def process_request(self, request):
        # Check if the current path is in the excluded paths
        path = request.path_info
        
        # Allow if path is in PUBLIC_PATHS
        for pattern in self.PUBLIC_PATHS:
            if re.match(pattern, path):
                return None
                
        # Check if user is authenticated via JWT
        user = get_user_from_jwt(request)
        
        if not user.is_authenticated:
            # If requesting an API path, return JSON response
            if path.startswith('/api/'):
                print("\n\n\n/////////////////USER NOT AUTHENTICATED///////////////////\n\n\n")
                print(f"User not authenticated for path: {path}")
                return (redirect('home'))
                # return JsonResponse({'error': 'Authentication required', 'redirect': '/'}, status=401)
            
            # For non-API paths, use JavaScript to force a hard refresh to home page
            html = """
            <!DOCTYPE html>
            <html>
            <head>
                <script>
                    // This will cause a hard page refresh to the home page
                    window.location.href = '/';
                </script>
                <title>Redirecting...</title>
            </head>
            <body>
                <p>Authentication required. Redirecting to home...</p>
            </body>
            </html>
            """
            return HttpResponse(html)

def jwt_login_required(view_func=None, redirect_url='/'):
    """Decorator to protect views with JWT authentication"""
    def decorator(view_func):
        @wraps(view_func)
        def _wrapped_view(request, *args, **kwargs):
            user = get_user_from_jwt(request)
            if user.is_authenticated:
                return view_func(request, *args, **kwargs)
            
            # Store the original URL to redirect back after login
            request.session['next'] = request.get_full_path()
            request.session.modified = True
            
            # Add a message
            messages.warning(request, _("Authentication required. Please login to access this page."))
            
            # Use simple JavaScript redirect for guaranteed page refresh
            html = """
            <!DOCTYPE html>
            <html>
            <head>
                <script>
                    window.location.href = '/';
                </script>
                <title>Redirecting...</title>
            </head>
            <body>
                <p>Authentication required. Redirecting to home...</p>
            </body>
            </html>
            """
            return HttpResponse(html)
        return _wrapped_view
    
    if view_func:
        return decorator(view_func)
    return decorator

def jwt_api_required(view_func):
    """Decorator for API views that require JWT authentication"""
    @wraps(view_func)
    def _wrapped_view(request, *args, **kwargs):
        user = get_user_from_jwt(request)
        if user.is_authenticated:
            return view_func(request, *args, **kwargs)
        return (redirect('home'))
        # return JsonResponse({'error': 'Authentication required', 'redirect': '/'}, status=401)
    return _wrapped_view
