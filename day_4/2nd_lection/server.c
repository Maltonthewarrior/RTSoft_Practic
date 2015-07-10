#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	char message[] = "Hi Paul =(\n";
	int sock, listener;
	struct sockaddr_in addr;
	char buf[1024];
	int bytes_read;

	listener = socket(AF_INET, SOCK_STREAM, 0);
	if(listener < 0)
	{
		perror("socket");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3428);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind");
		return 1;
	}

	listen(listener, 1);
	while(1)
	{
		sock = accept(listener, NULL, NULL);
		if(sock < 0)
		{
			perror("accept");
			return 1;
		}
		while(1)
		{
			bytes_read = recv(sock, buf, 1024, 0);
			if(bytes_read <= 0)
			{
				break;
			}
			printf("Receive message: %s\n", buf);
			sleep(1);
			send(sock, message, sizeof(message), 0);
		}




		close(sock);
		printf("Server socket closed");
	}
	return 0;
}