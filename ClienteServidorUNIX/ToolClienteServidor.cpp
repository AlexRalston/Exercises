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
        cout << "Selecciona una opcion e introduzca el numero correspondiente: " << endl;
        cout << "1. DHCP" << endl;
        cout << "2. Backup" << endl;
        cout << "3. Serverconfig" << endl;
        cout << "4. FTP" << endl;
        cout << "5. SSH" << endl;
        cout << "6. Actualizar SO." << endl;
        // Agregar una pausa para evitar que el programa muestre el menú demasiado rápido
        usleep(100000);
        cout<<"Introduzca la opcion que desea:";
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
                string backup_file_name = "/etc/dhcp/backups/dhcpd.conf.bak";
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
 // Instalar servidor FTP y herramientas
    system("sudo apt-get update");
    system("sudo apt-get install vsftpd ftp");

    // Crear el archivo a enviar
    string file_name = "archivo.txt";
    ofstream file(file_name);
    file << "Este es un archivo para poder probar el funcionamiento del protocolo FTP.";
    file.close();

    // Crear el comando FTP
    string command = "ftp -n 192.168.1.100 <<EOF\nuser usuario contrasena\nbinary\nput " + file_name + "\nquit\nEOF";

    // Ejecutar el comando en la terminal
    system(command.c_str());

    cout << "Archivo enviado con éxito." << endl;
    }
    case5:{
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

    // Encriptar la contraseña para pasarla como argumento del comando SSH
    string encrypted_password = "openssl enc -aes-256-cbc -a -salt -pbkdf2 -pass pass:" + password + " -in /dev/null";

    // Crear el comando SSH
    string command = "sshpass -e ssh " + user + "@" + host + " 'sudo su'";

    // Ejecutar el comando en la terminal
    system((encrypted_password + " | " + command).c_str());

    cout << "Conexión SSH finalizada." << endl;

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