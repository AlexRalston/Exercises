/*Escribir un programa que inicialice cada elemento de una matriz de enteros 
con el valor de la suma de su numero de fila y columna.*/


#include <iostream>
using namespace std;

int main() {
    int filas,columnas;
    cout<<"Introduzca el numero de filas que desea en la matriz: "<<endl;
    cin>>filas;
    cout<<"Introduzca el numero de columnas que desea en la matriz: "<<endl;
    cin>>columnas;

    int matriz[filas][columnas];
    
    // Inicializar la matriz con la suma de su número de fila y columna
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i + j;
        }
    }
    
    // Mostrar la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
    
    return 0;
}
