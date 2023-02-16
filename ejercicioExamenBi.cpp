#include<iostream>


using namespace std;


int main(){


    int filas;
    int columnas;
    do{
    cout<<"Introduzca el numero de filas que desea: "<<endl;
    cin>>filas;
    cout<<"Introduzca el numero de columnas que desea:"<<endl;
    cin>>columnas;}while(filas != columnas && columnas != filas);

    int matrizA[filas][columnas];
    int matrizB[filas][columnas];
    int matrizC[filas][columnas];
    cout<<"Rellena la matrizA: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            do{
            cout<<"Introduzca el elemento correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<":"<<endl;
            cin>>matrizA[i][j];
            }while(matrizA[i][j]<0);
        }


    }
    cout<<"Rellena la matrizB: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            do{
            cout<<"Introduzca el elemento correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<":"<<endl;
            cin>>matrizB[i][j];}while(matrizB[i][j]<0);

        }


    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matrizC[i][j]=matrizA[i][j]*matrizB[i][j];
        }


    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"La matriz resultante es: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matrizC[i][j]<<" | ";

        }
        cout<<endl;
    }


    return 0;
}