/*10.-Queremos almacenar en una matriz las notas de informática
 de los alumnos de un instituto.
 Suponiendo que hay 4 grados distintos, 
 15 alumnos por grado, 
 se pide:
a.Ingresar las notas que ha sacado cada alumno de cada grado.
b.Imprimir cuál es la nota promedio de cada grado.
c.Imprimir la mayor nota en general.
d. Imprimir cuántos alumnos aprobaron y cuántos suspendieron de cada grado.*/

#include<iostream>
#include<iomanip>
using namespace std;

const int filas=15;//15 alumnos 
const int columnas = 4;//4 grados
const string asignaturas[4]={"Redes","Programacion","Implantacion","Hardware"};


int main(){


//Declaramos el array
float matriz[filas][columnas];
string alumnos[15];
//Rellenamos
for(int i=0;i<filas;i++){
    cout<<"Ingrese el nombre del alumno "<<i+1<<": ";
    cin>>alumnos[i];
    for(int j = 0;j<columnas;j++){
        cout<<"Introduzca la nota  del alumno "<<alumnos[i]<<" correspondiente a la asignatura de "<<asignaturas[j]<<":"<<endl;
        cin>>matriz[i][j];
    }

}
















//Imprimimos las notas de los 15 alumnos en los 4 grados diferentes.
cout<<"Alumno";
cout<<endl;
for(int i = 0; i < filas; i++) {
    
    cout << left << setw(15) << alumnos[i];
    for(int j = 0; j < columnas; j++) {
        cout << setw(10) << right << matriz[i][j] << " | ";
    }
    cout << endl;
    if(i == 0) {
        cout << "-------------+------+------+------+------" << endl;
    }
}
cout << " Asignatura  ";
for(int j = 0; j < columnas; j++) {
    cout << setw(10) << right << asignaturas[j] << " | ";
}
cout << endl;
cout<<endl;
cout<<endl;
cout<<endl;

















//Imprimimos cual es la nota promedio de cada asignatura
for(int j=0;j<columnas;j++){
    int  suma_asignatura = 0;
    for(int i = 0;i<filas;i++){
        suma_asignatura += matriz[i][j];
        
    }
    float promedio_asignatura = static_cast<float>(suma_asignatura) / filas;
    cout<<"La nota promedio de la asignatura "<<asignaturas[j]<<" es: "<<promedio_asignatura<<endl;
    cout<<endl;
    cout<<endl;
}
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;














//Imprime la nota mas alta
float nota_mas_alta = matriz[0][0];


cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){

        if(matriz[i][j] > nota_mas_alta ){
            nota_mas_alta = matriz[i][j];
        }
        cout<<"La nota mas alta es del alumno "<<alumnos[i]<<" correspondiente a la asignatura "<<asignaturas[j]<<": "<<nota_mas_alta<<endl;
        cout<<endl;
    }

}








cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
//Imprimir cuantos alumnos aprobaron y cuantos suspendieron cada grado 

for(int j=0;j<columnas;j++){
    int num_aprobados=0;
    int num_suspensos=0;
    for(int i=0;i<filas;i++){
        if(matriz[i][j] > 5){

            num_aprobados++;

        }
        else{
            num_suspensos++;
        }


    }

    cout<<"Del grado de "<<asignaturas[j]<<","<<num_aprobados<<" aprobaron y "<<num_suspensos<<" suspendieron"<<endl;


}


    return 0;
}

