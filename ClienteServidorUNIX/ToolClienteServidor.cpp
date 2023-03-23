#include<iostream>
#include<libdhcp/dhcp.h>
#include<vector>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;



int main(){


    int opcion;

    while(true){

        cout<<"Selecciona una opcion: "<<endl;

        cout<<"1. DHCP"<<endl;
        cout<<"2. Backup"<<endl;
        cout<<"3.Serverconfig"<<endl;
        cout<<"4. FTP"<<endl;
        cout<<"5. SSH"<<endl;
        cout<<"6.Actualizar SO."<<endl;

    }



    case 1: {

    




    dhcp::ServerConfig config;


    //Primero, seleccionar interfaz de red a configurar
    vector<string> interfaces = dhcp::get_interfaces(); //Crea un vector o array en el que se almacenan los nombres de las interfaces de red.

    cout<<"Selecciona la interfaz de red a utilizar:" << endl; // Salida por pantalla


    for(int i = 0; i < interfaces.size(); i++){ //Bucle para recorrer las interfaces y mostrarlas

        cout<<i+1<<". " << interfaces[i]<<endl;

    }

    int opcion;

    while(true)  {  // Bucle para seleccionar una interfaz valida.
        cout<<"Selecciona la interfaz a configurar: ";
        cin >> opcion;
        if(opcion < 1 || opcion > interfaces.size()){ // Si opcion escogida es menor que uno o mayor que el numero total de interfaces

                       cerr << "Opción inválida. Introduce un número entre 1 y " << interfaces.size() << endl; // Error
                       continue;//Sale del bucle WHILE



        }
        config.interfaces = {interfaces[opcion-1]}; // almacena 
        break; // sale del loop
    }

    string ipstart, ipend; // variables rango de IP


    while (true){
        cout<<"Introduce el rango inicial de direcciones IPs: ";

        cin>>ipstart; // Direccion IP de comienzo

        cout<<"Introduce el rango final de direcciones IPs: ";

        cin>>ipend; // Direccion IP de finalizacion
        if(ipstart.empty() || ipend.empty()){

            cerr<<"Los rangos de direcciones IPs no pueden estar vacios. "<<endl;
            continue;
        }

        config.start = ipstart;
        config.end = ipend;
        break;

    }

    string mascara; // Mascara de subred
    while (true) {
        cout << "Introduce la máscara de subred: ";  //Introduce la mascara correspondiente al rango elegido
        cin >> mascara;
        if (mascara.empty()) {
            cerr << "La máscara de subred no puede estar vacía." << endl;
            continue;
        }
        config.mascara = mascara;
        break;
    }
    
    int tiempo_defecto; // Tiempo por defecto que dará la direccion 
    while (true) {
        cout << "Introduce el tiempo de arrendamiento por defecto (en segundos): ";
        cin >> tiempo_defecto; // Introduce el tiempo
        if (tiempo_defecto <= 0) {
            cerr << "El tiempo de arrendamiento por defecto debe ser mayor que cero." << endl;
            continue;
        }
        config.tiempo_defecto = tiempo_defecto;
        break;
    }

    int tiempo_maximo;
    while (true) {
        cout << "Introduce el tiempo máximo de arrendamiento (en segundos): ";
        cin >> tiempo_maximo;
        if (tiempo_maximo <= 0) {
            cerr << "El tiempo máximo de arrendamiento debe ser mayor que cero." << endl;
            continue;
        }
        config.tiempo_maximo = tiempo_maximo;
        break;
    }



    dhcp::Server server(config);
    server.run();


    }
    case 2: {


    void backup_config(dhcp::ServerConfig config) { //Recibe como parametro la configuracion del servidor DHCP


    //La organizacion en arbol permite un mejor manejo de los datos que una estructura de datos plana
    boost::property_tree::ptree arbol_copia;
    boost::property_tree::ptree arbol_interfaces;
    boost::property_tree::ptree comienzo_final_arbol;



    // Guardar interfaces de red
    for (auto interfaz : config.interfaces) {
        boost::property_tree::ptree arbol_interfaz;
        iface_tree.put("", interfaz);
        interfaces_tree.push_back(make_pair("", arbol_interfaz));
    }
    arbol_copia.add_child("interfaces", arbol_interfaces);




    // Guardar rango de IPs

    start_end_tree.put("comienzo", config.start);
    start_end_tree.put("final", config.end);
    backup_tree.add_child("rango_ip", comienzo_final_arbol);




    // Guardar máscara de subred
    backup_tree.put("mascara_subred", config.mascara);




    // Guardar tiempo de arrendamiento
    backup_tree.put("tiempo_arrendamiento_defecto", config.tiempo_defecto);
    backup_tree.put("tiempo_arrendamiento_maximo", config.tiempo_maximo);




    // Obtener la fecha y hora actual
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    std::string timestamp = boost::posix_time::to_iso_extended_string(now);





    // Crear archivo Excel de copia de seguridad con fecha y hora en el nombre
    boost::filesystem::path backup_path = boost::filesystem::current_path() / ("dhcp_backup_" + timestamp + ".xlsx");
    boost::property_tree::xml_writer_settings<char> settings('\t', 1);
    boost::property_tree::write_excel_xml(backup_path.string(), backup_tree, settings);
    std::cout << "Copia de seguridad creada en: " << backup_path << std::endl;
    }



    case 3:{







    }

    case 4:{




    }

    case 5:{



    }

    case 6:{





    }



 
    }
























































    return 0;




    
    





}