from channels.generic.websocket import AsyncWebsocketConsumer
from channels.db import database_sync_to_async
import json

class OnlineStatusConsumer(AsyncWebsocketConsumer):
	async def connect(self):
		if self.scope["user"].is_authenticated:
			await self.set_online(True)
		await self.accept()

	async def disconnect(self, close_code):
		if self.scope["user"].is_authenticated:
			await self.set_online(False)

	@database_sync_to_async
	def set_online(self, status):
		from users.models import CustomUser
		CustomUser.objects.filter(id=self.scope["user"].id).update(online_status=status)