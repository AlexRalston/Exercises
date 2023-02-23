/*Leer un array de N*M elementos y que guarda 0 en las posiciones pares y 1 en las posiciones impares.Imprimir el array resultante.*/

#include<iostream>

using namespace std;

int main(){




    int filas,columnas;


    cout<<"Introduzca el numero de filas:"<<endl;
    cin>>filas;
    cout<<"Introduzca el numero de columnas: "<<endl;
    cin>>columnas;
    int array[filas][columnas];
    cout<<"La matriz resultante es de "<<filas<<" filas y "<<columnas<<":"<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(array[i][j] % 2 == 0){
                array[i][j] = 0;

            }
            else{
                array[i][j] = 1;
            }


        }


    }
    cout<<"Imprimiendo matriz: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            cout<<array[i][j]<<" | ";

        }
        cout<<endl;
    }

}