from channels.generic.websocket import AsyncWebsocketConsumer
import json

class OnlineStatusConsumer(AsyncWebsocketConsumer):
    async def connect(self):
		await self.accept()
		self.scope["user"].online_status = True
		await self.scope["user"].save()
  
	async def disconnect(self, close_code):
		self.scope["user"].online_status = False
		await self.scope["user"].save()