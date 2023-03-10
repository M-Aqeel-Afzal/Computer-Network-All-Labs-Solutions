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
	
	int len, n;
	len = sizeof(cliaddr); //len is value/resuslt
	while(1){
		
		printf("Waiting for client\n");

		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
		
		buffer[n] = '\0';
		printf("Server: STRING FROM CLIENT IS : %s\n", buffer);
		    int n1 = strlen(buffer);
 
		    
    			for (int i = 0; i < n1 / 2; i++){
    			    char temp=buffer[i];
				buffer[i]=buffer[n1 - i - 1];
				buffer[n1 - i - 1]=temp;
			}		
		sendto(sockfd, (const char *)buffer, strlen(buffer),
			0, (const struct sockaddr *) &cliaddr,
				len);
	int n=strlen(buffer),c=0,i=0;
 
    for(i;i<n/2;i++)  
    {
    	if(buffer[i]==buffer[n-i-1])
    	c++;
 
 	}
 	if(c==i)
 	    printf("Recivied string is palindrome\n");
    else
        printf("Recivied string is not palindrome\n");




		printf("REVERSED String sent to client.\n");
	}
	return 0;
}
