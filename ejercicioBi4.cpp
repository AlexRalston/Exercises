/*Escribe un programa que lea una matriz de 3 filas y 3 columnas de valores enteros.
A continuacion, el programa debe de pedir un numero de fila. El programa debe de devolver el maximo de esa fila*/

#include<iostream>
#include<algorithm>
using namespace std;

//Define una constante porque el ejercicio lo pide
const int MAX= 3;

int main(){

int matriz[MAX][MAX];
int fila;

cout<<"Introduzca los valores de la matriz: "<<endl;
for(int i=0;i<MAX;i++){

    for(int j=0;j<MAX;j++){
        cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<endl;
        cin>>matriz[i][j];
    }
}
cout<<"La matriz introducida es: "<<endl;

for(int i=0;i<MAX;i++){

    for(int j=0;j<MAX;j++){
        cout<<matriz[i][j]<<" | ";
    }
    cout<<endl;
}
cout<<endl;
cout<<endl;

//Pide la fila

cout<<"Introduzca el numero de la fila que desea averiguar su maximo valor: ";cin>>fila;


int maximo=

cout<<endl;
cout<<"El valor maximo de la fila "<<fila<<" es "<<maximo<<"."<<endl;

return 0;


}