#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MAX_STRING_SIZE 256

// Function to handle the connection and communication with the server
void handle_server_communication(int socket_descriptor) {
     char userInput[MAX_STRING_SIZE];
     int lengthOfInput;
     int networkLength;
     int rc;

     // Ask the user for an input string
     printf("Enter a string (max %d characters): ", MAX_STRING_SIZE - 1);
     fgets(userInput, MAX_STRING_SIZE, stdin);
     userInput[strcspn(userInput, "\n")] = '\0'; // Remove newline character if present

     // Calculate the length of the input string
     lengthOfInput = strlen(userInput);
     printf("Sending %d bytes\n", lengthOfInput);

     // Send the length of the string in network byte order
     networkLength = htonl(lengthOfInput);
     rc = write(socket_descriptor, &networkLength, sizeof(networkLength));
     if (rc < sizeof(networkLength)) {
          printf("Error sending string length\n");
          exit(1);
     }

     // Send the string itself
     rc = write(socket_descriptor, userInput, lengthOfInput);
     if (rc < lengthOfInput) {
          printf("Error sending string\n");
          exit(1);
     }

     // Receive the length of the echoed string from the server
     rc = read(socket_descriptor, &networkLength, sizeof(networkLength));
     
     if (rc < sizeof(networkLength)) {
          printf("Error receiving echoed string length\n");
          exit(1);
     }

     // Convert the length back to host byte order
     lengthOfInput = ntohl(networkLength);
     printf("Recieved %d bytes\n", lengthOfInput);

     // Allocate a buffer for the echoed string and receive it
     char echoedString[lengthOfInput + 1]; // +1 for null terminator

     rc = read(socket_descriptor, echoedString, lengthOfInput);
     if (rc < lengthOfInput) {
          printf("Error receiving echoed string\n");
          exit(1);
     }
     echoedString[lengthOfInput] = '\0'; // Null terminate the received string

     // Print the echoed string
     printf("Received echoed string: %s\n", echoedString);
}

int main(int argc, char* argv[]) {
     int sd; /* socket descriptor */
     int rc;
     struct sockaddr_in server_address;

     if (argc < 3) {
          printf("Usage: %s <portNumber> <ipAddress>\n", argv[0]);
          exit(1);
     }

     int portNumber = atoi(argv[1]);
     char* ipAddress = argv[2];

     // Create a socket
     if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
          perror("Error opening stream socket");
          exit(1);
     }

     // Setup server address structure
     server_address.sin_family = AF_INET;
     server_address.sin_port = htons(portNumber);

     // Convert the IP address from text to binary form
     rc = inet_pton(AF_INET, ipAddress, &server_address.sin_addr);
     if (rc <= 0) {
          printf("Invalid IP address\n");
          exit(1);
     }

     // Connect to the server
     rc = connect(sd, (struct sockaddr*)&server_address, sizeof(server_address));
     if (rc < 0) {
          perror("Error connecting to server");
          close(sd);
          exit(1);
     }

     // Handle the server communication as per assignment requirements
     handle_server_communication(sd);

     // Close the socket
     close(sd);

     return 0;
}