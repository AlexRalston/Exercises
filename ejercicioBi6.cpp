


//Matriz traspuesta


#include<iostream>


using namespace std;

int main(){
    int filas;
    int columnas;
    cout<<"Introduzca el numero de filas que desea: "<<endl;
    cin>>filas;
    cout<<"Introduzca el numero de columnas que desea: "<<endl;
    cin>>columnas;

    int matrizOriginal[filas][columnas];
    int matrizTraspuesta[columnas][filas];
    cout<<"Introduzca los valores de la matriz original: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            cout<<"Introduce el valor correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<":"<<endl;
            cin>>matrizOriginal[i][j];
        }
    }
    //Cambiamos las filas por las columnas

    for(int i=0;i<filas;i++){


        for(int j=0;j<columnas;j++){

            matrizTraspuesta[j][i]=matrizOriginal[i][j];
        }
    }
    cout<<endl;
    cout<<"La matriz original es: "<<endl;
    //Mostramos la matriz original
    for(int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            cout<<matrizOriginal[i][j]<<" | ";
        }
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<columnas;i++){

        for(int j=0;j<filas;j++){

            cout<<matrizTraspuesta[i][j]<<" | ";

        }
    }

return 0;
}




