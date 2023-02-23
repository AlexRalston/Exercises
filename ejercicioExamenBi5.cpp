#include <iostream>

using namespace std;

int main() {
    int N, M;
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> N;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> M;

    int matriz[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for (int i = 0; i < N; i++) {
        int maximo = matriz[i][0];
        int minimo = matriz[i][0];
        for (int j = 1; j < M; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
        cout << "El elemento mayor de la fila " << i << " es: " << maximo << endl;
        cout << "El elemento menor de la fila " << i << " es: " << minimo << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<N;i++){

        for(int j =0;j<M;j++){

            cout<<matriz[i][j]<<" | ";

        }
        cout<<endl;
    }

    return 0;
}
