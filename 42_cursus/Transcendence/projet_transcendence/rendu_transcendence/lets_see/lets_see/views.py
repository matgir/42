from django.shortcuts import render
from django.http import HttpResponse
from django.template.loader import render_to_string
from django.views.decorators.csrf import ensure_csrf_cookie
from django.conf import settings
import os

@ensure_csrf_cookie
def base_view(request, template_name='home.html'):
    """
    Base view that renders the base template with SPA architecture.
    This is used for all routes to maintain the SPA behavior.
    
    Parameters:
    - template_name: The template to load in the app-content div if accessed directly
    """
    # Render the base template which contains our SPA structure
    response = render(request, 'base.html')
    
    # Check if it's an AJAX request
    is_ajax_request = request.headers.get('X-Requested-With') == 'XMLHttpRequest'
    
    # Only inject content if not an AJAX request (i.e., a direct page load)
    if not is_ajax_request:
        # Get environment variables safely
        client_id = os.environ.get('CLIENT_ID', '')
        redirect_uri = os.environ.get('URI', '')
        
        # Render the specific template content
        initial_content = render_to_string(template_name, {
            'env_client_id': client_id, 
            'env_uri': redirect_uri,
            'user': request.user
        })
        
        # Add the content to the app-content div
        response.content = response.content.replace(
            b'<!-- Initial home page content loaded here -->', 
            f'<!-- Initial content from {template_name} -->\n{initial_content}'.encode()
        )
    
    return response

def home_view(request):
    """Main home page view"""
    return base_view(request, 'home.html')
