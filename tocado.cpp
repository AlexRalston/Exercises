#include<iostream>
#include<string>
/*Reglas.
1.No se puede disparar dos veces al mismo sitio.
2.Para eliminar un barco se necesita acertar en todas sus partes.
3.Cuando se dispara a una posicion, no se puede volver a disparar a la misma seccion nunca mas.
4.Existen 3 barcos(fragata,acorazado y portaviones), la fragata ocupa dos posiciones,el acorazado ocupa 
tres posiciones y el portaviones cuatro posiciones en el mar.
  */


using namespace std;


int main(){
    //Nombre del usuario que va a jugar a hundir la flota
    string nombre_user = " ";
    //Opcion a elegir"Si"o "No" para verificar que el nombre del usuario introducir es
    //correcto.
    int opcion;
    
    cout<<"BIENVENIDO AL JUEGO DE HUNDIR LA FLOTA."<<endl;
    cout<<"Por favor, introduzca su nombre: "<<endl;

    cin>>nombre_user;

    cout<<"Su nombre es: "<<nombre_user<<endl;
    cout<<"Es correcto?(1.Si/2.No)."<<endl;

    cin>>opcion;

        if(opcion == 1){
        cout<<"Prosigamos....";
        }
        else if(opcion == 2){
        main();
        }
        else{ 

        cout<<"Opcion invalida.";
        }
    //El tablero sera de 6x6 en todos los casos
    const int filas=6;
    const int columnas=6;


    //Declaramos el array correspondiente al tablero

    string tablero[filas][columnas]; 
    //fragata 2 posiciones, acorazado 3 posiciones y el portaviones 4 posiciones.
    string fragata = "fragata";
    string acorazado = "acorazado";
    string portaviones = "portaviones";

    tablero[0][1] = "fragata";
    tablero[0][2] = "fragata";
    tablero[1][3] = "acorazado";
    tablero[1][4] =  "acorazado";
    tablero[1][5] = "acorazado";
    tablero[2][1] = "portaviones";
    tablero[2][2] = "portaviones";
    tablero[2][3] = " ";
    tablero[2][4] =  


    //Bucle para asignar la fragata, el acorazado y el portaviones
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

        }

    }


    


return 0;
}