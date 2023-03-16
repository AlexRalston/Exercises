#include<iostream>
#include<fstream>


using namespace std;


int main(){


    string usuario, contrasenia;

    ifstream archivo("C:/Users/ILCAPO/linux/.vscode/logeo/tablaLog.txt");

    archivo.open("tablaLog.txt");


    if(!archivo.is_open()){
        cout<<"El archivo no esta abierto. Abriendo archivo..."<<endl;
        archivo.open("tablaLog.txt");
        if(!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
        }

    }

    cout<<"Ingrese su usuario: ";

    cin>>usuario;

    cout<<"Ingrese su contrasenia: ";

    cin>>contrasenia;

    string linea;

    bool encontrado = false;

    while (getline(archivo,linea)){

        size_t pos = linea.find('-');

        string usuario_archivo = linea.substr(0,pos);//Desde posicion 0 de la cadena hasta el delimitador '-'
        string contraseña_archivo = linea.substr(pos+1);//El resto, es decir, la contraseña

        if(usuario == usuario_archivo && contrasenia == contraseña_archivo){
            encontrado = true;
            break;


        }

    }

    if(encontrado){

        cout<<"Acceso concedido."<<endl;
        cout<<endl;
        cout<<endl;
    }

    else{

        cout<<"Acceso denegado"<<endl;
        string respuesta;

        cout<<"¿Desea registrarse en el sistema?(si/no):";
        cin>>respuesta;
        if(respuesta == "si"){
            cout<<"Ingrese el nombre del usuario que desea registrar:  ";
            cin>>usuario;
            cout<<""
            ofstream archivo_salida("tablaLog.txt",ios::app);

            if(!archivo_salida.is_open()){

                cout<<"Error al abrir el archivo"<<endl;

                return 1;

            }

            archivo_salida<<usuario<<"-"<<contrasenia<<endl;
            cout<<"Registro exitoso"<<endl;
            
            archivo_salida.close();
        } 
    }

    return 0;
    
}
    



