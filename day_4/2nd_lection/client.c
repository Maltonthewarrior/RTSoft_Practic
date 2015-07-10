#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	printf("hi");
	char messages[5][30];
	printf("hi");
	strcpy(messages[0], "Hi, I'm Paul!\n");
	printf("1");
	strcpy(messages[1], "Why so angry?\n");
	//printf("2");
	strcpy(messages[2], "I'm just want to tell You my beautifull story.\n");
	//printf("3");
	strcpy(messages[3], "..well, someday...\n");
	//printf("4");
	strcpy(messages[4], "Please just listen to me!\n");
	//printf("5");
	//char message[] = "Hi, I'm Paul!\n";
	char buf[1024];
	int sock;
	struct sockaddr_in addr;
	int bytes_read;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("socket");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3428);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		return 1;
	}
printf("hi");
	//send(sock, message, sizeof(message), 0);


	//while(1)
	//{
		//sock = accept(listener, NULL, NULL);
		//if(sock < 0)
		//{
		//	perror("accept");
		//	return 1;
		//}
		while(1)
		{
			int i;
			i = rand(4);
			printf("%d", i);
			send(sock, messages[i], sizeof(messages[i]), 0);
			sleep(1);
			bytes_read = recv(sock, buf, 1024, 0);
			if(bytes_read <= 0)
			{
				break;
			}
			printf("Receive message: %s\n", buf);
		}
		//close(sock);
	//}





	close(sock);
	printf("Client socket closed");

	return 0;
}