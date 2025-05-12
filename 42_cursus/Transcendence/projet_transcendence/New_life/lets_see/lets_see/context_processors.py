import os
from django.utils.translation import gettext as _

def client_id_context(request):
    return {
        "env_client_id": os.getenv("OAUTH_CLIENT_ID", _("Value does not exist"))
    }

def uri_context(request):
    return {
        "env_uri": os.getenv("REDIRECT_URI", _("Value does not exist"))
    }
