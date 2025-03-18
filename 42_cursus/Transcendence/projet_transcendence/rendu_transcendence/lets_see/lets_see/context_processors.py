import os

def client_id_context(request):
    return {
        "env_client_id": os.getenv("OAUTH_CLIENT_ID", "Value does not exist")
    }

def uri_context(request):
    return {
        "env_uri": os.getenv("REDIRECT_URI", "Value does not exist")
    }
