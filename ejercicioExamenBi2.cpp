
/*Programacion Redes Implantacion  Media
Alejandro  3.0    4.0           5.0   0.0
Luis       7.0    3.0           2.0   0.0        
Juan       2.0    5.0           4.0   0.0
Antonio    6.0    2.0           8.0   0.0
Carlos     2.0    1.0           9.0   0.0
*/



#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Pedir al usuario los nombres de los estudiantes y las asignaturas
    int num_estudiantes, num_asignaturas;
    cout << "Introduzca el numero de estudiantes: "<<endl;
    cin >> num_estudiantes;
    cout << "Introduzca los nombres de los estudiantes:" << endl;
    vector<string> nombres_estudiantes(num_estudiantes);
    for (int i = 0; i < num_estudiantes; i++) {
        cout << "Estudiante " << i+1 << ": ";
        cin >> nombres_estudiantes[i];
    }
    cout << "Introduzca el número de asignaturas: ";
    cin >> num_asignaturas;
    cout << "Introduzca los nombres de las asignaturas:" << endl;
    string nombres_asignaturas[num_asignaturas];
    for (int i = 0; i < num_asignaturas; i++) {
        cout << "Asignatura " << i+1 << ": ";
        cin >> nombres_asignaturas[i];
    }

    // Definir el arreglo bidimensional para almacenar las notas de los estudiantes y las asignaturas
    double notas[num_estudiantes][num_asignaturas];

    // Pedir al usuario las notas de cada estudiante en cada asignatura
    for (int fila = 0; fila < num_estudiantes; fila++) {
        cout << "Introduzca las notas de " << nombres_estudiantes[fila] << ":" << endl;
        for (int columna = 0; columna < num_asignaturas; columna++) {
            cout << nombres_asignaturas[columna] << ": ";
            cin >> notas[fila][columna];
        }
    }

    // Imprimir las notas de cada estudiante y la media de cada uno a la derecha de todas sus notas
    cout << setw(15) << left << "Estudiante";
    for (int columna = 0; columna < num_asignaturas; columna++) {
        cout << setw(10) << right << nombres_asignaturas[columna];
    }
    cout << setw(15) << right << "Media" << endl;
    for (int fila = 0; fila < num_estudiantes; fila++) {
        cout << setw(15) << left << nombres_estudiantes[fila];
        double suma = 0.0;
        for (int columna = 0; columna < num_asignaturas; columna++) {
            cout << setw(10) << right << notas[fila][columna];
            suma += notas[fila][columna];
        }
        double media = suma / num_asignaturas;
        cout << setw(15) << right << media << endl;
    }

    // Calcular la media de cada asignatura y mostrarla al final de la tabla
    cout << setw(15) << left << "Media";
   for (int columna = 0; columna < num_asignaturas; columna++) {
    double suma = 0.0;
    for (int fila = 0; fila < num_estudiantes; fila++) {
        suma += notas[fila][columna];
    }
    double media = suma / num_estudiantes;
    cout << setw(10) << right << media;
}


    return 0;
}