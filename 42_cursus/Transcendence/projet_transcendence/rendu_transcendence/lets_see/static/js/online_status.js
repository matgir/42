// online status js

const socket = new WebSocket("ws://" + window.location.host + "/ws/status/");

socket.onopen = () => console.log("WebSocket connected");
socket.onclose = () => console.log("WebSocket disconnected");
socket.onerror = (err) => console.log("WebSocket error", err);