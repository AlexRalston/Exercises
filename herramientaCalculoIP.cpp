#include <iostream>        // Importacion de la biblioteca estándar de entrada/salida
#include <string>          // Importacion de la biblioteca para manejar cadenas de texto
#include <sstream>         // Import de la biblioteca para manejar flujos de texto
#include <bitset>          // Importacion de la biblioteca para manejar bits
#include <arpa/inet.h>     //   Importacion de la biblioteca para funciones de red

using namespace std;

string calcularDireccionRed(const string& ip, int cidr) {
    struct in_addr addr;                          // Estructura para almacenar una dirección IP
    inet_pton(AF_INET, ip.c_str(), &(addr.s_addr));  // Convierte una dirección IP de texto a binario

    uint32_t networkAddress = ntohl(addr.s_addr) & (0xFFFFFFFF << (32 - cidr));  // Calcula la dirección de red
    addr.s_addr = htonl(networkAddress);              // Convierte la dirección de red de binario a texto

    char buffer[INET_ADDRSTRLEN];                 // Búfer para almacenar la dirección de red en formato de texto
    inet_ntop(AF_INET, &(addr.s_addr), buffer, INET_ADDRSTRLEN);  // Convierte la dirección de red de binario a texto

    return buffer;                                // Devuelve la dirección de red como una cadena de texto
}

string calcularDireccionBroadcast(const string& ip, int cidr) {
    struct in_addr addr;                          // Estructura para almacenar una dirección IP
    inet_pton(AF_INET, ip.c_str(), &(addr.s_addr));  // Convierte una dirección IP de texto a binario

    uint32_t networkAddress = ntohl(addr.s_addr) & (0xFFFFFFFF << (32 - cidr));  // Calcula la dirección de red
    uint32_t broadcastAddress = networkAddress | (~0U >> cidr);  // Calcula la dirección de difusión
    addr.s_addr = htonl(broadcastAddress);          // Convierte la dirección de difusión de binario a texto

    char buffer[INET_ADDRSTRLEN];                 // Búfer para almacenar la dirección de difusión en formato de texto
    inet_ntop(AF_INET, &(addr.s_addr), buffer, INET_ADDRSTRLEN);  // Convierte la dirección de difusión de binario a texto

    return buffer;                                // Devuelve la dirección de difusión como una cadena de texto
}

string calcularPrimerIP(const string& ip, int cidr) {
    struct in_addr addr;                          // Estructura para almacenar una dirección IP
    inet_pton(AF_INET, ip.c_str(), &(addr.s_addr));  // Convierte una dirección IP de texto a binario

    uint32_t networkAddress = ntohl(addr.s_addr) & (0xFFFFFFFF << (32 - cidr));  // Calcula la dirección de red
    networkAddress += 1;                           // Incrementa la dirección de red para obtener la primera IP disponible
    addr.s_addr = htonl(networkAddress);              // Convierte la primera IP de binario a texto

    char buffer[INET_ADDRSTRLEN];                 // Búfer para almacenar la primera IP en formato de texto
    inet_ntop(AF_INET, &(addr.s_addr), buffer, INET_ADDRSTRLEN);  // Convierte la primera IP de binario a texto

    return buffer;                                // Devuelve la primera IP como una cadena de texto
}

string calcularUltimoIP(const string& ip, int cidr) {
    struct in_addr addr;                          // Estructura para almacenar una dirección IP
    inet_pton(AF_INET, ip.c_str(), &(addr.s_addr));  // Convierte una dirección IP de texto a binario

    uint32_t networkAddress = ntohl(addr.s_addr) & (0xFFFFFFFF << (32 - cidr));  // Calcula la dirección de red
    uint32_t broadcastAddress = networkAddress | (~0U >> cidr);  // Calcula la dirección de difusión
    broadcastAddress -= 1;                         // Decrementa la dirección de difusión para obtener la última IP disponible
    addr.s_addr = htonl(broadcastAddress);          // Convierte la última IP de binario a texto

    char buffer[INET_ADDRSTRLEN];                 // Búfer para almacenar la última IP en formato de texto
    inet_ntop(AF_INET, &(addr.s_addr), buffer, INET_ADDRSTRLEN);  // Convierte la última IP de binario a texto

    return buffer;                                // Devuelve la última IP como una cadena de texto
}

int calcularNumeroHosts(int cidr) {               //Funcion para calcular el numero de hosts pasando como parámetro el bloque CIDR

    return (1 << (32 - cidr)) - 2;                // Calcula el número de hosts en función de la máscara CIDR
}

int main() {   //Programa principal
    string ip;              // Dirección IP
    int cidr;               // Máscara CIDR

    cout<<"Ingrese la direccion IP: "; //Pregunta al usuario por una direccion IP
    cin>>ip; //Introduce la direccion IP

    cout<<"Ingrese el bloque CIDR: "; //Pregunta al usuario por un bloque CIDR
    cin>>cidr; //Introduce el bloque CIDR

    string direccionRed = calcularDireccionRed(ip, cidr);           // Calcula la dirección de red
    string direccionBroadcast = calcularDireccionBroadcast(ip, cidr); // Calcula la dirección de difusión
    string primerIP = calcularPrimerIP(ip, cidr);                 // Calcula la primera IP disponible
    string ultimoIP = calcularUltimoIP(ip, cidr);                 // Calcula la última IP disponible
    int numeroHosts = calcularNumeroHosts(cidr);                     // Calcula el número de hosts

    cout << "Direccion de red: " << direccionRed <<endl;               // Imprime la dirección de red
    cout << "Direccion de difusion: " << direccionBroadcast <<endl;   // Imprime la dirección de difusión
    cout << "Primer IP disponible: " << primerIP <<endl;             // Imprime la primera IP disponible
    cout << "Ultimo IP disponible: " << ultimoIP << endl;             // Imprime la última IP disponible
    cout << "Numero de hosts: " << numeroHosts << endl;               // Imprime el número de hosts

    return 0;
}
