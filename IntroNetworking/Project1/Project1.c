#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	int sd; /* socket descriptor */
	int rc;
	struct sockaddr_in sin_addr;

	int portNumber;
	if (argc < 3) {
		printf("Usage is: client <portNumber> <ipaddress> \n");
		exit(1);
	}


	// get the port number
	portNumber = atoi(argv[1]);

	// create a socket, note i do NOT have to bind to it since
	// this is a client. 
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("error opening stream socket");
		exit(1);
	}

	/* add in SERVER address information i got from command line*/
	sin_addr.sin_family = AF_INET;
	sin_addr.sin_port = htons(portNumber);

	// this is a funky function that will convert something like
	// 9.1.2.44 into the address for the computer/network needs
	char* ipaddress = argv[2];
	rc = inet_pton(AF_INET, ipaddress, &(sin_addr.sin_addr));
	if (rc < 0) {
		printf("failed to convert ip address\n");
		exit(1);
	}

	/* establish connection with server, since this is a stream socket, connection is required */
	// if the server says "NO I CAN"T TALK, i need to handle that
	rc = connect(sd, (struct sockaddr*)&sin_addr, sizeof(struct sockaddr_in));
	if (rc < 0) {
		close(sd); // clean up!
		perror("error connecting stream socket");
		exit(1);
	}
	/* if here then the socket has been connected */