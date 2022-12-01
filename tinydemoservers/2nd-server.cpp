#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int c, char **v)
{
	if (c <= 2)
	{
		printf("usage: %s ip_addr port_num\n", basename(v[0]));
		return 1;
	}
	const char *ip = v[1];
	int port = atoi(v[2]);

	sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	assert(sock >= 0);

	int ret = bind(sock, (sockaddr *)&address, sizeof(address));
	perror("errno is:");
	assert(ret != -1);

	ret = listen(sock, 5);
	assert(ret != -1);

	sleep(20);
	sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock, (sockaddr *)&client, &client_addrlength);
	if (connfd < 0)
		printf("errno is %d\n", errno);
	else
	{
		char remote[INET_ADDRSTRLEN];
		printf("connected with ip:%s and port:%d \n",
			   inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));
		close(connfd);
	}
	close(sock);
	return 0;
}
