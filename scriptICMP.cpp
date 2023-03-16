#include <iostream>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

int main() {
    const char* hostname = "www.google.es";
    const char* port = "80";
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, port, &hints, &res);

    if (status != 0) {
        cout << "Error en getaddrinfo: " << gai_strerror(status) << endl;
        cout << "No se pudo resolver la dirección IP de " << hostname << endl;
        cout << "El servicio DNS no funciona." << endl;
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd == -1) {
        cout << "Error en socket: " << strerror(errno) << endl;
        cout << "No se pudo crear el socket para conectarse a " << hostname << endl;
        return 1;
    }

    status = connect(sockfd, res->ai_addr, res->ai_addrlen);

    if (status == -1) {
        cout << "Error en connect: " << strerror(errno) << endl;
        cout << "No se pudo conectar a " << hostname << endl;
        cout << "No hay conectividad." << endl;
        close(sockfd);
        return 1;
    }

    cout << "Conectado a " << hostname << endl;
    cout << "Hay conectividad." << endl;

    close(sockfd);
    freeaddrinfo(res);

    return 0;
}
