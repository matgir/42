/**
 * JWT Authentication Utility
 * 
 * This utility manages JWT tokens for authentication:
 * - Checks for token expiration
 * - Refreshes access tokens automatically
 * - Handles API requests with authentication
 */

class JWTAuth {
    constructor() {
        this.accessToken = this.getCookie('jwt_access');
        this.refreshToken = this.getCookie('jwt_refresh');
        this.tokenRefreshInterval = null;
        
        // Start token refresh cycle if we have tokens
        if (this.accessToken && this.refreshToken) {
            this.startTokenRefresh();
        }
    }
    
    /**
     * Get a cookie by name
     * 
     * @param {string} name - The cookie name
     * @returns {string|null} - The cookie value or null if not found
     */
    getCookie(name) {
        const cookieValue = document.cookie
            .split('; ')
            .find(row => row.startsWith(name + '='))
            ?.split('=')[1];
        
        return cookieValue || null;
    }
    
    /**
     * Parse a JWT token payload
     * 
     * @param {string} token - JWT token
     * @returns {object|null} - Decoded token payload or null if invalid
     */
    parseJwt(token) {
        try {
            const base64Url = token.split('.')[1];
            const base64 = base64Url.replace(/-/g, '+').replace(/_/g, '/');
            const jsonPayload = decodeURIComponent(atob(base64).split('').map(c => {
                return '%' + ('00' + c.charCodeAt(0).toString(16)).slice(-2);
            }).join(''));
            
            return JSON.parse(jsonPayload);
        } catch (e) {
            console.error('Error parsing JWT token:', e);
            return null;
        }
    }
    
    /**
     * Check if the access token is expired
     * 
     * @returns {boolean} - True if expired or about to expire (within 1 minute)
     */
    isTokenExpired() {
        if (!this.accessToken) return true;
        
        const payload = this.parseJwt(this.accessToken);
        if (!payload) return true;
        
        // Check if token will expire in the next minute
        const expirationTime = payload.exp * 1000;  // Convert to milliseconds
        const currentTime = Date.now();
        const bufferTime = 60000;  // 1 minute in milliseconds
        
        return currentTime + bufferTime > expirationTime;
    }
    
    /**
     * Refresh the access token using the refresh token
     * 
     * @returns {Promise<boolean>} - True if refresh was successful
     */
    async refreshAccessToken() {
        if (!this.refreshToken) return false;
        
        try {
            const response = await fetch('/api/users/token/refresh/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    refresh: this.refreshToken,
                }),
            });
            
            if (!response.ok) {
                throw new Error('Failed to refresh token');
            }
            
            const data = await response.json();
            document.cookie = `jwt_access=${data.access}; path=/; SameSite=Lax; max-age=3600`;
            this.accessToken = data.access;
            
            return true;
        } catch (error) {
            console.error('Error refreshing token:', error);
            return false;
        }
    }
    
    /**
     * Start the token refresh cycle
     * Checks token expiration every minute and refreshes if needed
     */
    startTokenRefresh() {
        // Clear any existing interval
        if (this.tokenRefreshInterval) {
            clearInterval(this.tokenRefreshInterval);
        }
        
        // Check every minute if token needs refresh
        this.tokenRefreshInterval = setInterval(async () => {
            if (this.isTokenExpired()) {
                const success = await this.refreshAccessToken();
                if (!success) {
                    // If refresh fails, clear tokens and redirect to login
                    this.logout();
                }
            }
        }, 60000);  // Check every minute
    }
    
    /**
     * Log the user out by removing tokens
     */
    logout() {
        document.cookie = 'jwt_access=; path=/; expires=Thu, 01 Jan 1970 00:00:01 GMT;';
        document.cookie = 'jwt_refresh=; path=/; expires=Thu, 01 Jan 1970 00:00:01 GMT;';
        this.accessToken = null;
        this.refreshToken = null;
        
        if (this.tokenRefreshInterval) {
            clearInterval(this.tokenRefreshInterval);
        }
        
        // Redirect to home page
        window.location.href = '/';
    }
    
    /**
     * Make an authenticated API request with the JWT token
     * 
     * @param {string} url - API endpoint
     * @param {object} options - Fetch options
     * @returns {Promise<Response>} - Fetch response
     */
    async apiRequest(url, options = {}) {
        // Check if token is expired and refresh if needed
        if (this.isTokenExpired()) {
            const refreshed = await this.refreshAccessToken();
            if (!refreshed) {
                // If refresh failed, redirect to login
                this.logout();
                throw new Error('Authentication required');
            }
        }
        
        // Set up headers with authentication
        const headers = options.headers || {};
        headers['Authorization'] = `Bearer ${this.accessToken}`;
        
        // Make the request
        return fetch(url, {
            ...options,
            headers,
        });
    }
    
    /**
     * Check if the user is authenticated
     * 
     * @returns {boolean} - True if user has a valid access token
     */
    isAuthenticated() {
        return !!this.accessToken && !this.isTokenExpired();
    }
}

// Create a global auth instance
window.auth = new JWTAuth();

// Add an event listener to automatically authenticate API requests
document.addEventListener('DOMContentLoaded', () => {
    // Automatically use JWT token for fetch requests to our API
    const originalFetch = window.fetch;
    window.fetch = async function(url, options = {}) {
        // Only add authentication for API requests
        if (url.startsWith('/api/') && window.auth && window.auth.isAuthenticated()) {
            const headers = options.headers || {};
            headers['Authorization'] = `Bearer ${window.auth.accessToken}`;
            options.headers = headers;
        }
        return originalFetch(url, options);
    };
});