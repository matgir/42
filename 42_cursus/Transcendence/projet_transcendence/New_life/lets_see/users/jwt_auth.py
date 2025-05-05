from rest_framework_simplejwt.tokens import RefreshToken

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