#include<iostream>
/*Realice un programa en C++ que permita al usuario introducir los valores de una matriz y en funcion de si son pares o impares saca la suma para los pares y el producto de los impares*/

using namespace std;


int main(){

int filas,columnas;
double suma=0.0;
double producto=1.0;

cout<<"Introduzca el numero de filas: "<<endl;
cin>>filas;
cout<<"Introduzca el numero de columnas: "<<endl;
cin>>columnas;

int matriz[filas][columnas];
cout<<"Introduzca los valores correspondientes de los elementos de la matriz: "<<endl;
for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<":"<<endl;
        cin>>matriz[i][j];

    }
}
cout<<endl;
cout<<endl;

for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        if(matriz[i][j] % 2 == 0){
            suma += matriz[i][j];

        }
        else{
            producto *= matriz[i][j];
        }
    }
}


cout<<endl;
cout<<endl;

for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){

        cout<<matriz[i][j]<<" | ";

    }
    cout<<endl;
}
cout<<endl;
cout<<endl;
cout<<"La suma de los elementos pares es: "<<suma<<endl;
cout<<"El producto de los elementos impares es: "<<producto<<endl;


    return 0;
}