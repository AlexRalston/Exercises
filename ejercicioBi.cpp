#include<iostream>


using namespace std;

const int filas=5;
const int columnas = 4;


int main(){

int matriz[filas][columnas];

int sumaFilas[filas]={0};

int sumaColumnas[columnas]={0};

cout<<"A continuación, introduzca los valores de la matriz: "<<endl;
//Introducir valores en la matriz
for(int i=0;i<filas;i++){

    for(int j=0;j<columnas;j++){
        cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y la columna "<<j+1<<" :"<<endl;
        cin>>matriz[i][j];
    }
}

//Bucle para sumar cada fila
for(int i=0;i<filas;i++){
    int sumaFila = 0;
    for(int j=0;j<columnas;j++){

        sumaFila+=matriz[i][j];
    }
    sumaFilas[i]=sumaFila;
}

//Bucle para sumar cada columna
for(int j=0;j<columnas;j++){
    int sumaColumna=0;

    for(int i=0;i<filas;i++){

        sumaColumna+=matriz[i][j];
    }
    sumaColumnas[j]=sumaColumna;
}

//Imprimimos la matriz 
cout<<"La matriz es: "<<"SUMA FILA"<<endl;
for(int i=0;i<filas;i++){

    for(int j=0;j<columnas;j++){

        cout<<matriz[i][j]<<" | ";
        
    }
    cout<<sumaFilas[i]<< endl;
}

//Imprimimos la suma de cada columna

for(int j=0;j<columnas;j++){

    cout<<sumaColumnas[j]<<"   ";

}

    return 0;
}