#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


int main(){
    int alumnos;
    int asignaturas;

    cout<<"Introduzca el numero de alumnos a evaluar: ";
    cin>>alumnos;
    cout<<"Introduzca el numero de asignaturas a evaluar: ";
    cin>>asignaturas;

    vector<int,string> matrizClase[alumnos][asignaturas];


    cout<<"Por favor, introduzca los nombres de los alumnos a evaluar: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            cout<<"Introduzca el nombre del alumno "<<i+1<<":"<<endl;
            
            cin>>matrizClase[i][0];
            
        }

    }
    cout<<"Por favor, introduzca los nombres de las asignaturas a evaluar: "<<endl;
    

    for(int i=0;i<alumnos;i++){
        for()

    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int i=0;i<alumnos;i++){
        for(int j=0;j<asignaturas;j++){
            cout<<matrizClase[i][j]<<" | "<<endl;
        }
    }



    return 0;
}