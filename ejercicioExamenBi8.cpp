/*10.-Queremos almacenar en una matriz las notas de informática
 de los alumnos de un instituto.
 Suponiendo que hay 4 grados distintos, 
 15 alumnos por grado, 
 se pide:
a.Ingresar las notas que ha sacado cada alumno de cada grado.
b.Imprimir cuál es la nota promedio de cada grado.
c.Imprimir la mayor nota en general.
d.Imprimir todas las notas.
e. Imprimir cuántos alumnos aprobaron y cuántos suspendieron de cada grado.*/
#include<iostream>

using namespace std;


int main(){
//Declaramos las constantes para la matriz de alumnos
const int filas = 2;//15
const int columnas = 2; //4




//Declaramos el array
int matriz[filas][columnas];
//Rellenamos
for(int i=0;i<filas;i++){
    for(int j = 0;j<columnas;j++){
        cout<<"Introduzca la nota  del alumno "<<i+1<<" correspondiente a la asignatura "<<j+1<<"es:"<<endl;
        cin>>matriz[i][j];
    }

}
//Imprimimos cual es la nota promedio de cada asignatura
for(int j=0;j<columnas;j++){
    int  suma_asignatura = 0;
    for(int i = 0;i<filas;i++){
        suma_asignatura += matriz[i][j];
        
    }
    float promedio_asignatura = static_cast<float>(suma_asignatura) / filas;
    cout<<"La nota promedio de la asignatura "<<j+1<<" es: "<<suma_asignatura<<endl;
    cout<<endl;
    cout<<endl;
}


    return 0;
}