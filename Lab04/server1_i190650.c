// Server side implementation of UDP client-server model
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
	char hello[] = "";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n,v=0;
	len = sizeof(cliaddr); //len is value/resuslt




	while(1){
		
		printf("Waiting for client\n");

		n = recvfrom(sockfd, (char *)buffer, MAXLINE,            //reciving bytes
					0, ( struct sockaddr *) &cliaddr,
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
		printf("Client: Number of bytes: : %d\n", n);
		printf("Client: Number of vowels: : %d\n", v);
		printf("ENTER Message to client: .\n");
		scanf("%s",hello);
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &cliaddr,
				len);
v=0;
		printf("message sent.\n");
	}



	return 0;
}
