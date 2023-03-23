#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <dirent.h> // Agregar esta línea para usar DIR y dirent
#include<vector>
#include<libssh/libssh.h>

using namespace std;

int main() {
    int opcion;
    //CIN DE LA OPCION POR EL USUARIO
    while (true) {
        cout << "Selecciona una opcion: " << endl;
        cout << "1. DHCP" << endl;
        cout << "2. Backup" << endl;
        cout << "3. Serverconfig" << endl;
        cout << "4. FTP" << endl;
        cout << "5. SSH" << endl;
        cout << "6. Actualizar SO." << endl;
        // Agregar una pausa para evitar que el programa muestre el menú demasiado rápido
        usleep(100000);
        cin >> opcion;

        switch (opcion) { // Agregar el switch
            case 1: {
                // Definir la configuración del servidor DHCP
                string iface_name;
                string subnet;
                string dhcp_range_start;
                string dhcp_range_end;
                string dhcp_lease_time;

                // Pedir la información de configuración al usuario
                cout << "Nombre de la interfaz: ";
                cin >> iface_name;
                cout << "Dirección de la subred (en formato CIDR): ";
                cin >> subnet;
                cout << "Dirección de inicio del rango DHCP: ";
                cin >> dhcp_range_start;
                cout << "Dirección de fin del rango DHCP: ";
                cin >> dhcp_range_end;
                cout << "Tiempo de arrendamiento de IP (en segundos): ";
                cin >> dhcp_lease_time;

                // Crear el archivo de configuración del servidor DHCP
                string conf_file_name = "/etc/dhcp/dhcpd.conf";
                ofstream conf_file(conf_file_name);
                conf_file << "subnet " << subnet << " {\n";
                conf_file << "    range " << dhcp_range_start << " " << dhcp_range_end << ";\n";
                conf_file << "    option routers " << iface_name << ";\n";
                conf_file << "    option subnet-mask " << subnet << ";\n";
                conf_file << "    default-lease-time " << dhcp_lease_time << ";\n";
                conf_file << "    max-lease-time " << dhcp_lease_time << ";\n";
                conf_file << "}\n";
                conf_file.close();

                // Reiniciar el servicio del servidor DHCP
                system("systemctl restart isc-dhcp-server");

                cout << "Configuración completada. El servidor DHCP está en ejecución." << endl;

                break;
            }
            case 2: {
                // Crear una copia de seguridad del archivo de configuración del servidor DHCP
                string conf_file_name = "/etc/dhcp/dhcpd.conf";
                string backup_file_name = "/etc/dhcp/dhcpd.conf.bak";
    ifstream conf_file(conf_file_name);
    ofstream backup_file(backup_file_name);
    backup_file << conf_file.rdbuf();
    conf_file.close();
    backup_file.close();

    cout << "Copia de seguridad creada exitosamente." << endl;

    break;
    }
    case 3: {
    // Listar los archivos de backup en el directorio
    string backup_dir = "/etc/dhcp/backups/";
    DIR* dir;
    struct dirent* ent;
    vector<string> backup_files;

    if ((dir = opendir(backup_dir.c_str())) != NULL) {
        int i = 1;
        cout << "Seleccione el backup a cargar:\n";
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                backup_files.push_back(ent->d_name);
                cout << i << ". " << ent->d_name << endl;
                i++;
            }
        }
        closedir(dir);

        // Pedir al usuario que seleccione el número correspondiente al archivo que desea cargar
        int backup_selection;
        cout << "Ingrese el número correspondiente al backup que desea cargar: ";
        cin >> backup_selection;

        if (backup_selection > 0 && backup_selection <= backup_files.size()) {
            // Cargar el archivo de backup seleccionado
            string backup_file_name = backup_dir + backup_files[backup_selection-1];
            ifstream backup_file(backup_file_name);

            // Leer la configuración del archivo de backup y escribirla en el archivo de configuración
            string conf_file_name = "/etc/dhcp/dhcpd.conf";
            ofstream conf_file(conf_file_name);
            string line;
            while (getline(backup_file, line)) {
                conf_file << line << endl;
            }
            backup_file.close();
            conf_file.close();

            // Reiniciar el servicio del servidor DHCP
            system("systemctl restart isc-dhcp-server");

            cout << "El archivo de backup ha sido cargado con éxito." << endl;
        } else {
            cout << "El número ingresado es inválido." << endl;
        }
        } else {
        cout << "No se encontraron archivos de backup en el directorio " << backup_dir << endl;
        }
        break;
    }

    case 4:{

         // Crear el archivo a enviar
    string file_name = "archivo.txt";
    ofstream file(file_name);
    file << "Este es un archivo para poder probar el funcionamiento del protocolo FTP.";
    file.close();

    // Crear el socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        cerr << "Error al crear el socket." << endl;
        return 1;
    }

    // Establecer la dirección del servidor
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345); // Puerto arbitrario
    server_address.sin_addr.s_addr = inet_addr("192.168.1.100"); // Dirección IP del servidor

    // Conectar con el servidor
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        cerr << "Error al conectar con el servidor." << endl;
        return 1;
    }

    // Enviar el nombre del archivo
    char buffer[1024];
    strcpy(buffer, file_name.c_str());
    send(client_socket, buffer, strlen(buffer), 0);

    // Abrir el archivo para leer los datos
    ifstream file_to_send(file_name, ios::binary);

    // Leer y enviar los datos del archivo en bloques de 1024 bytes
    while (file_to_send) {
        file_to_send.read(buffer, sizeof(buffer));
        send(client_socket, buffer, file_to_send.gcount(), 0);
    }

    // Cerrar el archivo y el socket
    file_to_send.close();
    close(client_socket);

    cout << "Archivo enviado con éxito." << endl;





    }

    case 5: {
    // Definir las credenciales de acceso al servidor SSH
    string user;
    string host;
    string password;

    // Pedir las credenciales al usuario
    cout << "Nombre de usuario: ";
    cin >> user;
    cout << "Dirección del servidor: ";
    cin >> host;
    cout << "Contraseña: ";
    cin >> password;

    // Crear la conexión SSH
    ssh_session session = ssh_new();
    ssh_options_set(session, SSH_OPTIONS_HOST, host.c_str());
    ssh_options_set(session, SSH_OPTIONS_USER, user.c_str());
    ssh_options_set(session, SSH_OPTIONS_PASSWORD_AUTH, password.c_str());
    ssh_connect(session);

    // Iniciar sesión en el servidor SSH
    ssh_userauth_password(session, NULL, password.c_str());

    // Ejecutar un comando en la terminal como superusuario
    channel = ssh_channel_new(session);
    ssh_channel_open_session(channel);
    ssh_channel_request_pty(channel);
    ssh_channel_change_pty_size(channel, 80, 24);
    ssh_channel_request_exec(channel, "sudo su");
    char buffer[256];
    int nbytes;
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    while (nbytes > 0) {
        cout << buffer;
        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }

    // Cerrar la conexión SSH
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    ssh_disconnect(session);
    ssh_free(session);
    cout << "Conexión SSH finalizada." << endl;
    break;
    }   
    case 6:{

    int updateStatus = system("sudo apt-get update"); // Ejecuta el comando "sudo apt-get update"
    int upgradeStatus = system("sudo apt-get upgrade"); // Ejecuta el comando "sudo apt-get upgrade"

    if (updateStatus == 0 && upgradeStatus == 0) { // Verifica si ambos comandos fueron ejecutados correctamente
        cout << "El sistema ha sido actualizado exitosamente." << endl;
    } else {
        cout << "Ha ocurrido un error durante la actualización del sistema." << endl;
    }



    }

    return 0;

 
    }
    }


}