/*Realizar un programa que sume dos matrices.La dimension de las mismas y sus elementos se pediran por teclado.
Para simplificar, podemos suponer que la dimension maxima para cada matriz es de 10x10*/


#include<iostream>

using namespace std;


int main(){



    int filas,columnas;
    
    do{
        cout<<"Ingrese el numero de filas que desea en la matriz(maximo 10): ";
        cin>>filas;
    }while(filas <= 0 || filas >10);
    do{

        cout<<"Ingrese el numero de columnas que desea en la matriz(maximo 10): ";
        cin>>columnas;
    }while(columnas <= 0 || columnas > 10);
    
    int matrizA[filas][columnas];
    int matrizB[filas][columnas];
    int matrizC[filas][columnas];
    //Primero llenamos la matriz A



    cout<<"Introduzca los valores para la matriz A: "<<endl;
    for(int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y la columna "<<j+1<<" :"<<endl;
            cin>>matrizA[i][j];



        }
    }
    cout<<endl;
    cout<<"Introduzca los valores para la matriz B: "<<endl;

    //Llenamos la matriz B
    for(int i=0;i<filas;i++){


        for(int j=0;j<columnas;j++){


            cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<" :"<<endl;
            cin>>matrizB[i][j];
        }
    }

    //Sumamos la matriz A y B y la metemos en la matriz C
    
    for(int i=0;i<filas;i++){


        for(int j=0;j<columnas;j++){

            matrizC[i][j]= matrizA[i][j] + matrizB[i][j];
        }
    } 

    //Salida de datos
    cout<<"La matriz A es: "<<endl;
    cout<<endl;
    for(int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            
            cout<<matrizA[i][j]<<" | ";

            
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"La matriz B es: "<<endl;
    cout<<endl;
    for(int i=0; i<filas;i++){

        for(int j=0;j<columnas;j++){
            
            cout<<matrizB[i][j]<<" | ";

        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"La matriz C es: "<<endl;
    cout<<endl;
    for(int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            cout<<matrizC[i][j]<<" | ";
        }
        cout<<endl;
    }
    return 0;
}