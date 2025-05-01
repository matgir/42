import json
from channels.generic.websocket import AsyncWebsocketConsumer

class MyWevbSocketConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        await self.accept()
        await self.send(text_data=json.dumps({"message": "Hello, WebSocket !"}))
        
    async def disconnect(self, close_code):
        pass
    
    async def receive(self, text_data):
        data = json.loads(text_data)
        message = data.get("message", "")
        await self.send(text_data=json.dumps({"response": f"You said: {message}"}))