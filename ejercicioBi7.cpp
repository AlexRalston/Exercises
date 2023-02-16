#include<iostream>

using namespace std;


int main(){

    int filas;
    int columnas;

    cout<<"Introduzca el numero de filas que desea: "<<endl;
    cin>>filas;
    cout<<"Introduzca el numero de columnas que desea: "<<endl;
    cin>>columnas;
    
    double media=0.0;

    int matriz[filas][columnas];
    cout<<"Rellena la matriz: "<<endl;
    for(int i=0;i<filas;i++){
        media=0.0;
        for(int j=0;j<columnas;j++){
            cout<<"Introduzca el elemento correspondiente a la fila "<<i+1<<" y a la columna "<<j+1<<":"<<endl;
            cin>>matriz[i][j];
            media=media+matriz[i][j];
        }
        media=media/filas;
        cout<<"La media correspondiente a la fila "<<i+1<<" es: "<<media<<endl;
    }

    for(int j=0;j<columnas;j++){
        media
        for(int i=0;i<filas;i++){


            
        }
    }







    


}