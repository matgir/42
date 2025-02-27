// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <sys/select.h>

// typedef struct s_client
// {
// 	int		id;
// 	char	msg[299000];
// }		t_client;

// t_client	clients[1024];
// fd_set		read_set, write_set, current;
// int			max_fd = 0, next_id = 0;
// char		send_buffer[300000], recv_buffer[300000];

// void	err(char *msg)
// {
// 	if (msg)
// 		write(2, msg, strlen(msg));
// 	else
// 		write(2, "Fatal error", 11);
// 	write(2, "\n", 1);
// 	exit(1);
// }

// void	send_to_all(int except)
// {
// 	for (int fd = 0; fd <= max_fd; fd++)
// 	{
// 		if (FD_ISSET(fd, &write_set) && fd != except)
// 			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
// 				err(NULL);
// 	}
// }

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		err("Wrong number of arguments");

// 	struct sockaddr_in	server_addr;
// 	socklen_t			len = sizeof(server_addr);
// 	int serverfd = socket(AF_INET, SOCK_STREAM, 0);

// 	if (serverfd == -1)
// 		err(NULL);
// 	max_fd = serverfd;

// 	FD_ZERO(&current);
// 	FD_SET(serverfd, &current);
// 	bzero(clients, sizeof(clients));
// 	bzero(&server_addr, sizeof(server_addr));

// 	server_addr.sin_family = AF_INET;
// 	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
// 	server_addr.sin_port = htons(atoi(av[1]));

// 	if (bind(serverfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1
// 		|| listen(serverfd, 100) == -1)
// 		err(NULL);

// 	while (1)
// 	{
// 		read_set = write_set = current;
// 		if (select(max_fd + 1, &read_set, &write_set, 0, 0) == -1)
// 			continue;

// 		for (int fd = 0; fd <= max_fd; fd++)
// 		{
// 			if (FD_ISSET(fd, &read_set))
// 			{
// 				if (fd == serverfd)
// 				{
// 					int clientfd = accept(serverfd, (struct sockaddr *)&server_addr, &len);
// 					if (clientfd == -1)
// 						continue;
// 					if (clientfd > max_fd)
// 						max_fd = clientfd;
// 					clients[clientfd].id = next_id++;
// 					FD_SET(clientfd, &current);
// 					sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
// 					send_to_all(clientfd);
// 				}
// 				else
// 				{
// 					int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
// 					if (ret <= 0)
// 					{
// 						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
// 						send_to_all(fd);
// 						FD_CLR(fd, &current);
// 						bzero(clients[fd].msg, sizeof(clients[fd].msg));
// 						close(fd);
// 						bzero(&clients[fd], sizeof(clients[fd]));
// 					}
// 					else
// 					{
// 						for (int i = 0, j = strlen(clients[fd].msg); i < ret && j < sizeof(clients[fd].msg) - 1; i++, j++)
// 						{
// 							clients[fd].msg[j] = recv_buffer[i];
// 							if (clients[fd].msg[j] == '\n')
// 							{
// 								clients[fd].msg[j] = '\0';
// 								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
// 								send_to_all(fd);
// 								bzero(clients[fd].msg, strlen(clients[fd].msg));
// 								j = -1;
// 							}
// 						}
// 					}
// 				}
// 				break;
// 			}
// 		}
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

typedef struct s_client {
	int id;
	char msg[299000];
} t_client;

t_client clients[1024];
fd_set read_set, write_set, current;
int max_fd = 0, next_id = 0;
char send_buffer[300000], recv_buffer[300000];

void err(char *msg) {
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void send_to_all(int except) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_set) && fd != except)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
	}
}

int main(int ac, char **av) {
	if (ac != 2)
		err("Wrong number of arguments");

	struct sockaddr_in server_addr;
	socklen_t len = sizeof(server_addr); // Initialize len properly

	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1)
		err("socket did not work");
	max_fd = serverfd;

	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(clients, sizeof(clients));
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(av[1]));

	if (bind(serverfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1
		|| listen(serverfd, 100) == -1)
		err("bind did not work");

	while (1) {
		read_set = write_set = current;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) == -1)
			err(NULL);
			// continue;

		for (int fd = 0; fd <= max_fd; fd++) {
			if (FD_ISSET(fd, &read_set)) {
				if (fd == serverfd) {  // New client connection
					int clientfd = accept(serverfd, (struct sockaddr *)&server_addr, &len);
					if (clientfd == -1)
						continue;
					if (clientfd > max_fd)
						max_fd = clientfd;
					clients[clientfd].id = next_id++;
					FD_SET(clientfd, &current);
					snprintf(send_buffer, sizeof(send_buffer), "server: client %d just arrived\n", clients[clientfd].id);
					send_to_all(clientfd);
				} else {  // Existing client message
					int ret = recv(fd, recv_buffer, sizeof(recv_buffer) - 1, 0);
					if (ret <= 0) {  // Client disconnected
						snprintf(send_buffer, sizeof(send_buffer), "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						FD_CLR(fd, &current);
						close(fd);
						bzero(&clients[fd], sizeof(clients[fd])); // Reset struct
					} else {  // Handle received data
						recv_buffer[ret] = '\0'; // Null-terminate
						unsigned int j = strlen(clients[fd].msg);

						for (int i = 0; i < ret && j < sizeof(clients[fd].msg) - 1; i++, j++) {
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n') {
								clients[fd].msg[j] = '\0';
								snprintf(send_buffer, sizeof(send_buffer), "client %d: %.299000s\n", clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(clients[fd].msg, sizeof(clients[fd].msg)); // Reset message buffer
								j = -1;
							}
						}
					}
				}
				break;
			}
		}
	}
	return (0);
}
