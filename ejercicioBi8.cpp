/*Escribe un programa en C++ que permita el usuario introducir elementos a una matriz del mismo 
numero de filas y columnas y asgine un puntero a cada elemento.*/

#include<iostream>


using namespace std;

int main(){
    int filas,columnas;
    while(true){
        cout<<"Introduzca el numero de filas que desea:";
        cin>>filas;
        if(filas > 0){
            break;
        }
    }
    for(;;){
        cout<<"Introduzca el numero de columnas que desea:";
        cin>>columnas;
        if(columnas > 0){
            break;
        }
    }
    cout<<endl;
    if(filas!=columnas){
        cout<<"Recuerde que el numero de filas y de columnas deben de ser iguales."<<endl;
        cout<<endl;
        main();
    }





    return 0;
}