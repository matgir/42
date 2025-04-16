from channels.generic.websocket import AsyncWebsocketConsumer
from channels.db import database_sync_to_async
import json
# import logging ####
# logger = logging.getLogger(__name__) ####

class OnlineStatusConsumer(AsyncWebsocketConsumer):
	async def connect(self):
		# logger.info(f"WS CONNECT ATTEMPT ON : {self.scope['user']}") ####
		if self.scope["user"].is_authenticated:
			# logger.info(f"{self.scope['user']} connected") ####
			await self.set_online(True)
		await self.accept()

	async def disconnect(self, close_code):
		if self.scope["user"].is_authenticated:
			await self.set_online(False)

	@database_sync_to_async
	def set_online(self, status):
		user = self.scope["user"]
		if user.is_authenticated:
			user.online_status = status
			user.save()