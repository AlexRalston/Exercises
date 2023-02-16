
/*Programacion Redes Implantacion  Media
Alejandro  3.0    4.0           5.0   0.0
Luis       7.0    3.0           2.0   0.0        
Juan       2.0    5.0           4.0   0.0
Antonio    6.0    2.0           8.0   0.0
Carlos     2.0    1.0           9.0   0.0
*/



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