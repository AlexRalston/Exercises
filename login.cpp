#include<iostream>
#include<fstream>


using namespace std;


int main(){


    string usuario, contrasenia;

    ifstream archivo("tablaLog.txt");

    if(!archivo.is_open()){

        cout<<"Error al abrir el archivo"<<endl;
        return 1;


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


    }
    {
        /* code */
    }
    


}