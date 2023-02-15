/*Realiza un programa que lea una matriz de numeros enteros y que devuelva la suma de los elementos positivos de la matriz y la suma de los elementos negativos*/


#include<iostream>


using namespace std;


int main(){
    int arreglo1[3][3];

    int sumaPositivos = 0;
    int sumaNegativos =0;
    cout<<"Introduzca los valores de la matriz 3x3: "<<endl;
    for(int i=0;i<3;i++){
        
        for(int j=0;j<3;j++){

            cout<<"Introduzca el valor correspondiente a la fila "<<i+1<<" y la columna "<<j+1<<" :"<<endl;
            cin>>arreglo1[i][j];

        }
    }    
    //Sumamos los positivos
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arreglo1[i][j] > 0){

                sumaPositivos+=arreglo1[i][j];
            }


        }
    
    }
    //Sumamos los negativos
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arreglo1[i][j] < 0){
                sumaNegativos+=arreglo1[i][j];
        }
    }
    }
    cout<<"La matriz es: "<<endl;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
       cout<<arreglo1[i][j]<<" | "; 
    }
        cout<<endl;
    }
    cout<<endl;
    cout<<"La suma de los valores positivos es: "<<sumaPositivos<<endl;
    cout<<"La suma de los valores negativos es: "<<sumaNegativos<<endl;


    return 0;
}

