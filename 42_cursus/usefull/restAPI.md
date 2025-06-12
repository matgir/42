# Comprehensive Guide to REST APIs

## Introduction
- **REST** stands for **Representational State Transfer**.
- It's an architectural style for designing networked applications, especially web services.
- A **REST API** allows communication between client and server using HTTP requests.

## Core Principles
- **Stateless:** Each request from client to server must contain all information needed to understand and process the request.
- **Client-Server:** Separation of concerns; the client handles the UI (User Interface), the server handles data and logic.
- **Uniform Interface:** Standardized way to interact (usually via HTTP methods).
- **Cacheable:** Responses must define themselves as cacheable or not to improve performance.
- **Layered System:** APIs can be composed of multiple layers (e.g., proxies, gateways).

## Resources & URIs
- **Resource**: Any object or data (user, order, file).
- **URI (Uniform Resource Identifier)**: Unique address for each resource.
  - Example: `/api/v1/users/42/orders/7`
- Everything is a **resource** (e.g., user, product, order).
- Resources are identified by **URLs** (e.g., `/users/123`).

### Representation
- Resources can have multiple representations (JSON, XML, HTML).
- The client specifies the desired format using the `Accept` header.

### Data Formats
- Most common: **JSON** (JavaScript Object Notation).
- Others: XML, YAML, etc.

## HTTP Methods in Depth

| Method  | Usage Example        | Idempotent? | Safe?  |
|---------|----------------------|-------------|--------|
| GET     | `/users/1`           | Yes         | Yes    |
| POST    | `/users`             | No          | No     |
| PUT     | `/users/1`           | Yes         | No     |
| PATCH   | `/users/1`           | No          | No     |
| DELETE  | `/users/1`           | Yes         | No     |

- **Idempotent**: Multiple identical requests have the same effect as one.
- **Safe**: Does not modify resources.

### 1. GET
- **Purpose:** Retrieve data from the server (read-only).
- **Idempotent:** Yes (multiple identical requests have the same effect).
- **Safe:** Yes (does not modify data).
- **Example:**
    ```
    GET /api/users/42
    ```
    **Response:**
    ```json
    {
      "id": 42,
      "name": "Alice",
      "email": "alice@example.com"
    }
    ```

### 2. POST
- **Purpose:** Create a new resource.
- **Idempotent:** No (multiple requests create multiple resources).
- **Safe:** No (modifies data).
- **Example:**
    ```
    POST /api/users
    Content-Type: application/json

    {
      "name": "Bob",
      "email": "bob@example.com"
    }
    ```
    **Response:**
    ```
    HTTP/1.1 201 Created
    Location: /api/users/43
    ```
    ```json
    {
      "id": 43,
      "name": "Bob",
      "email": "bob@example.com"
    }
    ```

### 3. PUT
- **Purpose:** Update/replace an existing resource (or create if it doesn't exist, depending on implementation).
- **Idempotent:** Yes (repeating the request has the same effect).
- **Safe:** No (modifies data).
- **Example:**
    ```
    PUT /api/users/42
    Content-Type: application/json

    {
      "name": "Alice Smith",
      "email": "alice.smith@example.com"
    }
    ```
    **Response:**
    ```
    HTTP/1.1 200 OK
    ```
    ```json
    {
      "id": 42,
      "name": "Alice Smith",
      "email": "alice.smith@example.com"
    }
    ```

### 4. PATCH
- **Purpose:** Partially update an existing resource.
- **Idempotent:** No (but can be, depending on implementation).
- **Safe:** No (modifies data).
- **Example:**
    ```
    PATCH /api/users/42
    Content-Type: application/json

    {
      "email": "alice.new@example.com"
    }
    ```
    **Response:**
    ```
    HTTP/1.1 200 OK
    ```
    ```json
    {
      "id": 42,
      "name": "Alice",
      "email": "alice.new@example.com"
    }
    ```

### 5. DELETE
- **Purpose:** Remove a resource.
- **Idempotent:** Yes (deleting the same resource multiple times has the same effect).
- **Safe:** No (modifies data).
- **Example:**
    ```
    DELETE /api/users/42
    ```
    **Response:**
    ```
    HTTP/1.1 204 No Content
    ```

## API Design Best Practices

### URL Design
- Use **nouns**, not verbs: `/users` not `/getUsers`
- Hierarchical: `/users/42/orders/7`
- Use query parameters for filtering, sorting, pagination:
  - `/users?role=admin&sort=name&page=2&limit=10`
- Avoid deep nesting (max 2-3 levels).

### Versioning
- **URI versioning**: `/api/v1/users`
- **Header versioning**: `Accept: application/vnd.example.v1+json`
- Versioning helps avoid breaking changes for clients.

### Pagination, Filtering, Sorting
- **Pagination**: `/users?page=2&limit=50`
- **Filtering**: `/users?role=admin`
- **Sorting**: `/users?sort=name,-created_at`

### HATEOAS (Hypermedia as the Engine of Application State)
- Advanced REST principle.
- Responses include links to related actions/resources.
```json
{
  "id": 1,
  "name": "Alice",
  "links": [
    { "rel": "self", "href": "/users/1" },
    { "rel": "orders", "href": "/users/1/orders" }
  ]
}
```

#### HATEOAS in Depth

##### What is HATEOAS?
- HATEOAS is one of the constraints that makes an API truly RESTful.
- It allows clients to navigate the API dynamically by following links provided in responses.
- The server communicates available actions to the client through hypermedia (links).

##### Benefits of HATEOAS
- **Self-discovery**: Clients can discover available actions without prior knowledge.
- **Loose coupling**: Clients depend on link relations, not hardcoded URLs.
- **API evolution**: Endpoints can change without breaking clients as long as link relations remain consistent.
- **State transitions**: Links represent valid state transitions for the client.

##### Implementation Approaches

###### Link Format Examples
1. **HAL (Hypertext Application Language)**:
```json
{
  "id": 42,
  "name": "Alice",
  "_links": {
    "self": { "href": "/users/42" },
    "orders": { "href": "/users/42/orders" },
    "update": { "href": "/users/42", "method": "PUT" },
    "delete": { "href": "/users/42", "method": "DELETE" }
  }
}
```

2. **JSON:API**:
```json
{
  "data": {
    "type": "users",
    "id": "42",
    "attributes": {
      "name": "Alice"
    },
    "relationships": {
      "orders": {
        "links": {
          "related": "/users/42/orders"
        }
      }
    },
    "links": {
      "self": "/users/42"
    }
  }
}
```

##### Real-World Use Case
When a user creates an order through an API:

1. **Initial POST Request**:
```
POST /orders
{ "productId": 123, "quantity": 2 }
```

2. **Response with HATEOAS links**:
```json
{
  "id": 456,
  "status": "pending",
  "productId": 123,
  "quantity": 2,
  "links": [
    { "rel": "self", "href": "/orders/456" },
    { "rel": "cancel", "href": "/orders/456/cancel", "method": "POST" },
    { "rel": "payment", "href": "/orders/456/payment", "method": "POST" },
    { "rel": "customer", "href": "/customers/789" }
  ]
}
```

3. The client can now discover that it can cancel the order or proceed to payment without needing to know these URLs in advance.

##### Implementation Considerations
- Choose a consistent link format (HAL, JSON:API, custom).
- Use meaningful and consistent relation names ("rel" values).
- Consider including the HTTP method to use with each link.
- Balance completeness with payload size (too many links can bloat responses).

## Status Codes
- **200 OK:** Success.
- **201 Created:** Resource created.
- **204 No Content:** Success, no data returned.
- **400 Bad Request:** Client error.
- **401 Unauthorized:** Authentication required.
- **404 Not Found:** Resource not found.
- **500 Internal Server Error:** Server error.

### Error Handling
- Use standard HTTP status codes.
- Include error details in the response body:
```json
{
  "error": "InvalidRequest",
  "message": "Email is required."
}
```

## Authentication & Security

### HTTPS
- **Always** use HTTPS to encrypt data between client and server.
- Prevents eavesdropping and man-in-the-middle attacks.
- Example:  
  ```
  https://api.example.com/users
  ```

### Authentication Methods

#### API Keys
- Simple token (string) sent in headers or query parameters.
- Example (header):
    ```
    GET /api/users
    X-API-Key: abc123xyz
    ```
- **Pros:** Easy to implement.
- **Cons:** Not user-specific, can be insecure if leaked.

#### Basic Authentication
- Username and password encoded in base64, sent in the `Authorization` header.
- Example:
    ```
    Authorization: Basic dXNlcjpwYXNzd29yZA==
    ```
- **Cons:** Not secure unless used with HTTPS; not recommended for production.

#### Bearer Token (JWT)
- Client authenticates and receives a token (often JWT).
- Token sent in `Authorization` header for each request.
- Example:
    ```
    Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...
    ```
- **Pros:** Stateless, scalable, widely used.

### JSON Web Token (JWT)

#### What is JWT?
- **JWT** is a compact, URL-safe token format used for securely transmitting information between parties as a JSON object.
- Commonly used for authentication and authorization in REST APIs.

#### Structure
A JWT has three parts, separated by dots:
```
header.payload.signature
```
Example:
```
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOjEyMywiZXhwIjoxNjg2MDAwMDB9.abc123signature
```

##### 1. Header
Specifies the token type and signing algorithm.
```json
{
  "alg": "HS256",
  "typ": "JWT"
}
```

##### 2. Payload
Contains the claims (data).
```json
{
  "userId": 123,
  "exp": 1686000000
}
```
- **exp**: Expiration time (Unix timestamp).

##### 3. Signature
Used to verify the token's integrity.
- Created by signing the header and payload with a secret key.

#### How JWT Works in REST APIs
1. **Login:** User sends credentials to `/login`.
2. **Token Issued:** Server verifies credentials and returns a JWT.
3. **Authenticated Requests:** Client sends JWT in the `Authorization` header:
    ```
    Authorization: Bearer <jwt-token>
    ```
4. **Server Verifies:** Server checks the signature and claims (e.g., expiration).
5. **Access Granted/Denied:** If valid, access is granted.

#### Pros & Cons
- **Pros:** Stateless, scalable, easy to use across domains.
- **Cons:** Cannot be revoked easily, token size can grow, must be stored securely on client.

#### OAuth 2.0
- Industry standard for delegated authorization.
- Used by Google, Facebook, GitHub, etc.
- User logs in via provider, receives access token.
- Example:
    ```
    Authorization: Bearer <oauth-access-token>
    ```

### OAuth 2.0

#### What is OAuth 2.0?
- **OAuth 2.0** is an authorization framework that allows third-party applications to access user data without exposing passwords.
- Used by Google, Facebook, GitHub, etc.

#### Key Concepts
- **Resource Owner:** The user.
- **Client:** The app requesting access.
- **Authorization Server:** Issues tokens (e.g., Google).
- **Resource Server:** API server with protected data.

#### OAuth 2.0 Grant Types (Flows)
1. **Authorization Code:** For web apps (most secure).
2. **Implicit:** For browser-based apps (less secure, now discouraged).
3. **Client Credentials:** For machine-to-machine (no user).
4. **Resource Owner Password:** For trusted apps (not recommended).

#### Example: Authorization Code Flow
1. **User Login:** User is redirected to the provider's login page.
2. **User Grants Access:** User approves the app.
3. **Authorization Code:** Provider redirects back with a code.
4. **Token Exchange:** App exchanges code for an access token (and optionally a refresh token).
5. **API Requests:** App uses the access token in the `Authorization` header:
    ```
    Authorization: Bearer <access-token>
    ```

#### Tokens in OAuth 2.0
- **Access Token:** Used to access APIs (often a JWT).
- **Refresh Token:** Used to obtain new access tokens without user login.

#### Example Flow Diagram

```
[User] --login--> [Auth Server] --code--> [Client App] --token exchange--> [Auth Server] --access token--> [Client App] --API call--> [Resource Server]
```

#### Pros & Cons
- **Pros:** Secure, supports delegated access, widely adopted.
- **Cons:** More complex to implement, requires secure storage of client secrets.

#### When to Use JWT vs OAuth 2.0
- **JWT:** Use for stateless authentication within your own API ecosystem.
- **OAuth 2.0:** Use when you need delegated access, third-party integrations, or want to leverage external identity providers.

### Other Security Considerations
- **Authorization**: Controls what authenticated users can do.
- **Rate Limiting**: Prevents abuse by limiting the number of requests per user/IP.
- **CORS (Cross-Origin Resource Sharing)**: Controls which domains can access your API.
- **Input Validation & Sanitization**: Always validate and sanitize user input.
- **Security Headers**: Use headers like `Strict-Transport-Security`, `Content-Security-Policy`.

## Tools & Libraries
- **Testing:** Postman, curl, Insomnia.
- **Frameworks:** Express (Node.js), Flask/Django (Python), Spring Boot (Java), FastAPI (Python).
- **Documentation:** Swagger/OpenAPI.

## Common Pitfalls
- Not using proper HTTP status codes.
- Over-nesting resources.
- Ignoring security (no HTTPS, no authentication).
- Not versioning the API.
- Poor documentation.

## Alternatives to REST
- **GraphQL**: Flexible queries, single endpoint.
- **gRPC**: High-performance, binary protocol.
- **SOAP**: XML-based, more rigid.