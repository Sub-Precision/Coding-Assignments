#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <time.h>

// Data we will use to send request/reply to server
struct dhcp_packet {
     // Declare Variables
     uint8_t op;         // Operation code (1 = BOOTREQUEST, 2 = BOOTREPLY)
     uint32_t ciaddr;    // Client IP address (0 if client is in INIT state)
     uint32_t yiaddr;    // 'Your' (client) IP address
     uint32_t fromIPAddr; // should be 0.0.0.0 on client->server
     uint32_t toIPAddr;   // should be 255.255.255.255 on client->server
     uint16_t transID;    // transaction ID – random number client->server
};

// Function to create a socket and set it for broadcasting
// Turned this create a socket snippet of code from the instructions into a function so it's easier to call in main
// and use the socket variable in other calls in main
int create_broadcast_socket() {
     //Declare Variables
     int sockfd;
     // Set socket option to enable broadcast
     int broadcast_enable = 1;
     // Exception handling for DGRAM failure
     if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
          perror("Error opening DGRAM socket");
          exit(1);
     }
     // Given code in assignment
     if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable)) == -1) {
          perror("setsockopt failed");
          exit(EXIT_FAILURE);
     }
     // Return socket descriptor for further use
     return sockfd;
}

// Function to initialize the server address
void init_server_address(struct sockaddr_in* server_addr, int port) {
     // Adapted code from Lab1 to initialize server
     //memset used to initialize server address memory block with zeroes before inputting the actual server address into it
     memset(server_addr, 0, sizeof(struct sockaddr_in));
     server_addr->sin_family = AF_INET;
     server_addr->sin_port = htons(port);
     server_addr->sin_addr.s_addr = INADDR_BROADCAST;
}

// Function to create and send a DHCP packet
void send_dhcp_packet(int sockfd, struct sockaddr_in* server_addr) {
     //Declare variables
     struct dhcp_packet packet;
     srand(time(NULL));

     packet.op = 1; // BOOTREQUEST
     packet.ciaddr = 0;
     packet.yiaddr = 0;
     packet.fromIPAddr = htonl(INADDR_ANY);
     packet.toIPAddr = htonl(INADDR_BROADCAST);
     packet.transID = (uint16_t)rand();
     // More exception handling
     if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)server_addr, sizeof(*server_addr)) < 0) {
          perror("sendto");
          exit(EXIT_FAILURE);
     }
}

// Function to receive and validate the DHCP packet
void receive_and_validate_dhcp_packet(int sockfd) {
     // Declare variables
     struct dhcp_packet response_packet;
     struct sockaddr_in from_addr;
     socklen_t addr_len = sizeof(from_addr);
     int rc;

     rc = recvfrom(sockfd, &response_packet, sizeof(response_packet), 0, (struct sockaddr*)&from_addr, &addr_len);
     if (rc < 0) {
          perror("recvfrom");
          exit(EXIT_FAILURE);
     }

     // Printing recieved information to the console
     if (response_packet.op == 2 && response_packet.toIPAddr == htonl(INADDR_BROADCAST)) {
          printf("DHCP Packet is :\n");
          printf("op: %d\n", response_packet.op);
          printf("ciaddr: %s\n", inet_ntoa(*(struct in_addr*)&response_packet.ciaddr));
          printf("yiaddr: %s\n", inet_ntoa(*(struct in_addr*)&response_packet.yiaddr));
          printf("fromIPAddr: %s\n", inet_ntoa(*(struct in_addr*)&response_packet.fromIPAddr));
          printf("toIPAddr: %s\n", inet_ntoa(*(struct in_addr*)&response_packet.toIPAddr));
          printf("transID: %u\n", ntohs(response_packet.transID));
     }

     // Exception handling
     else {
          printf("Invalid DHCP offer received\n");
     }
}

int main(int argc, char* argv[]) {
     // Declare Variables
     int sockfd;
     struct sockaddr_in server_addr;
     int port;

     // Exception Handling
     if (argc < 2) {
          printf("Usage: %s <port>\n", argv[0]);
          exit(1);
     }

     // Call functions to do all of the requirements
     port = atoi(argv[1]);
     sockfd = create_broadcast_socket();
     init_server_address(&server_addr, port);
     send_dhcp_packet(sockfd, &server_addr);
     receive_and_validate_dhcp_packet(sockfd);

     close(sockfd);
     return 0;
}
