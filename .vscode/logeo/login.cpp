#include<iostream>
#include<fstream>


using namespace std;


int main(){

    string usuario, contrasenia;
    int intentos = 4;
    bool acceso_concedido = false;

    ifstream archivo("tablaLog.txt");

    if(!archivo.is_open()){
        cout<<"El archivo no esta abierto. Abriendo archivo..."<<endl;
        archivo.open("tablaLog.txt");
        if(!archivo.is_open()){
        cout<<"Error al abrir el archivo."<<endl;
        return 1;
        }

    }

    while (intentos > 0 && !acceso_concedido){
        cout<<"Ingrese su usuario: ";
        cin>>usuario;
        cout<<"Ingrese su contrasenia: ";
        cin>>contrasenia;

        string linea;
        bool encontrado = false;
        archivo.clear();
        archivo.seekg(0, ios::beg);

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
            acceso_concedido = true;
            cout<<"Acceso concedido."<<endl;
            string juego;
            do{
            
            cout<<"¿Que desea jugar? (Cuatroenraya/HundirLaFlota): ";
            cin>>juego;

            cout<<endl;
            cout<<endl;

            }while(juego!="Cuatroenraya" && juego!="HundirLaFlota");

            if(juego  == "Cuatroenraya") {

                system("cuatroenraya.exe"); //accede al prompt del sistema y ejecuta cuatroenraya

            }
            else if(juego == "HundirLaFlota"){

                system("tocado.exe");
                 //accede al prompt del sistema y ejecuta hundir la flota

            }
            else{//Un poco redundante pero bueno, por si los bugs...

                cout<<"Juego no reconocido."<<endl;
            }
        }
        else{
            intentos--;
            if (intentos > 0){
                cout<<"Acceso denegado.Si no esta registrado,escriba si a continuacion. Intentos restantes: "<<intentos<<endl;
                string respuesta;
                cout<<"¿Desea registrarse en el sistema?(si/no):";
                cin>>respuesta;
                if(respuesta == "si"){
    cout<<"Ingrese el nombre del usuario que desea registrar:  ";
    cin>>usuario;
    cout<<"Ingrese la contrasenia que desea para su registro:";
    cin>>contrasenia;

    // Verificar si el usuario ya existe
    ifstream archivo_lectura("tablaLog.txt");
    string linea;
    while (getline(archivo_lectura, linea)) {
        size_t pos = linea.find('-');
        string usuario_archivo = linea.substr(0,pos);
        if (usuario == usuario_archivo) {
            cout<<endl;
            
            cout << "Usuario existente, porfavor registrase con otro nombre de usuario y/o contrasenia." << endl;
            cout<<endl;
            archivo_lectura.close();
            return 1;
        }
    }
    archivo_lectura.close();

    // Registrar el nuevo usuario
    ofstream archivo_salida("tablaLog.txt",ios_base::app);
    if(archivo_salida.is_open()){
        archivo_salida<<usuario<<"-"<<contrasenia<<endl;
        cout<<"Registro exitoso."<<endl;
        archivo_salida.close();
    }
    else{
        cout<<"Error al abrir el archivo."<<endl;
        return 1;
    }
}
            }
            else{
                cout<<"Acceso denegado. No quedan intentos restantes."<<endl;
            }
        }
    }

    return 0;
}
