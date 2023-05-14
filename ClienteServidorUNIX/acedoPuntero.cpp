#include <iostream>//Libreria predeterminada de C++
#include <string> //Libreria que nos importa todos los metodos necesarios para trabajar con strings o cadena de caracteres

using namespace std; // Necesario para no tener que escribir std:: en la E/S de datos

struct Libro { //Definimos la estrucutra del libro
  string titulo; //Titulo del libro en cuestion
  string autor; //Autor del libro 
};

int main() { //Programa principal
  int cantidadLibros; //Cantidad de libros que vamos a almacenar en el vector
  cout << "Ingrese la cantidad de libros que desea ingresar: "; //Salida de datos para preguntar al usuario cuantos libros desea ingresar
  cin >> cantidadLibros; //Datos entrantes

  Libro* biblioteca = new Libro[cantidadLibros]; //Usando el tipo definido creamos un vector llamado biblioteca en el que se almacenaran los datos de cada libro

  for (int i = 0; i < cantidadLibros; i++) { //Bucle que recorrera la biblioteca preguntando por los datos de cada libro

    cout << "Ingrese el titulo del libro " << i+1 << ": "; 
    cin >> biblioteca[i].titulo;
    cout << "Ingrese el autor del libro " << i+1 << ": ";
    cin >> biblioteca[i].autor;
  }

  cout << "Registro de libros ingresados:\n"; 
  for (int i = 0; i < cantidadLibros; i++) { //Bucle que recorre nuevamente la biblioteca imprimiendo los datos de cada libro
    cout << i+1 << ". " << biblioteca[i].titulo << " - " << biblioteca[i].autor << "\n";
  }

  delete[] biblioteca; //Desasignamos el espacio de memoria asignado a todos los elementos del vector biblioteca

  return 0;//El programa principal retorna valor 0
}




