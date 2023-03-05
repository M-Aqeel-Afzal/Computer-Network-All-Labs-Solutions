// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char hello[] ="";
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n, len,v=0;
	while(1){
		printf("ENTER Message.\n");
		scanf("%s",hello);
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
		printf("Message sent.\n");
			
	

		n = recvfrom(sockfd, (char *)buffer, MAXLINE,       //reciving bytes
					0, (struct sockaddr *) &servaddr,
					&len);
		buffer[n] = '\0';
		char* ip_addr=inet_ntoa(servaddr.sin_addr);
for(int i=0;i<n;i++)
		{
		if(buffer[i]=='A'||buffer[i]=='a'||buffer[i]=='i'||buffer[i]=='I'||buffer[i]=='o'||buffer[i]=='O'||buffer[i]=='u'||buffer[i]=='U'||buffer[i]=='e'||buffer[i]=='E')
{
v++;
}
		}
		printf("Client: Port number : %d\n", ntohs(servaddr.sin_port));
                printf("Client: IP Address : %s\n", ip_addr);
		printf("Client: Number of vowels: : %d\n", v);
		printf("Server:Number of bytes : %d\n", n);
	v=0;
	}
	close(sockfd);
	return 0;
}
