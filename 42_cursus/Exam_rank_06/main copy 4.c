#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

int					sockfd, connfd, fd_max;
socklen_t			len;
fd_set				_fds, _fds_write, _fds_read;
struct sockaddr_in	servaddr, cli;
int					clientnbr = 0;
int					_usr[65000];
char				*_msg[65000];
char				buffer[4096];
char				send_info[50];

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;
	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;
	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void	send_all(int from, char *msg)
{
	for (int fd = 0; fd <= fd_max; fd++)
		if (FD_ISSET(fd, &_fds_write) && fd != from)
			send(fd, msg, strlen(msg), 0);
}

void	error(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		error("Wrong number of arguments\n");

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		error("Fatal error\n");

	bzero(&servaddr, sizeof(servaddr));
	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));
	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		error("Fatal error\n");
	if (listen(sockfd, 500) != 0)
		error("Fatal error\n");
	FD_ZERO(&_fds);
	FD_SET(sockfd, &_fds);
	fd_max = sockfd;

	for (;;)
	{
		_fds_read = _fds_write = _fds;
		if (select(fd_max + 1, &_fds_read, &_fds_write, 0, 0) < 0)
			error("Fatal error\n");
		for (int fd = 0; fd <= fd_max; fd++)
		{
			if (!FD_ISSET(fd, &_fds_read))
				continue;
			if (fd == sockfd)
			{
				len = sizeof(cli);
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0)
					error("Fatal error\n");
				if (fd_max < connfd)
					fd_max = connfd;
				_usr[connfd] = clientnbr;
				clientnbr++;
				_msg[connfd] = NULL;
				sprintf(send_info, "server: client %d just arrived\n", _usr[connfd]);
				send_all(connfd, send_info);
				FD_SET(connfd, &_fds);
				break;
			}
			else
			{
				int ret = recv(fd, buffer, 4096, 0);
				if (ret <= 0)
				{
					sprintf(send_info, "server: client %d just left\n", _usr[fd]);
					send_all(fd, send_info);
					close(fd);
					free(_msg[fd]);
					_msg[fd] = NULL;
					FD_CLR(fd, &_fds);
					break;
				}
				buffer[ret] = '\0';
				_msg[fd] = str_join(_msg[fd], buffer);
				for (char *msg = NULL; extract_message(&_msg[fd], &msg);)
				{
					sprintf(send_info, "client %d: ", _usr[fd]);
					send_all(fd, send_info);
					send_all(fd, msg);
					free(msg);
					msg = NULL;
				}
			}
		}
	}
	return (0);
}
