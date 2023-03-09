
#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void mat_en_cero(int mat[][10]);
void mat_en_x(int mat[][10]);
void parte1(int mat[][10]);
void parte2(int mat[][10]);
void parte3(int mat[][10]);
void parte4(int mat[][10]);
void batalla(int tiro,int &j,int h[],int a[]);

int main(int argc, char *argv[]) {
            int cantidad;
            char jugador[10][10];
            cout<<"Introduzca cantidad de jugadores: ";
            cin>>cantidad;
            for(int i=0;i<cantidad;i++){
                        cout<<"Introduzca el nombre del o los jugadores: "<<i+1<<" : ";
                        cin>>jugador[i];
                        cout<<endl;
            }
            int tiro;
           
            cout<<endl<<"Cuantos tiros quieres?"<<endl;
            cin>>tiro;
            int h[4],a[4];
            int i=1,ganador=0,segundo=0;
            for(int f=0;f<cantidad;f++){
            batalla(tiro,i,h,a);
            i++;
            cout<<endl<<endl<<"Turno seguiente jugador:"<<endl;}
            for(int j=0;j<cantidad;j++){
                
                        if(h[j+1]>segundo){
                        if(segundo>ganador){
                        segundo=ganador;ganador=h[j+1];}
                        else
                                   segundo=h[j+1];
                        }
                       
            }
            cout<<"Ganador: "<<jugador[ganador]<<". Barcos Hundidos: "<<h[ganador]<<endl;
           
                       
           
           
           
           
                                              
           
           
        
           
            return 0;
}




void mat_en_x(int fal [][10]){
            for(int i=0;i<10;i++)
                        for(int j=0;j<10;j++)
                                   fal[i][j]=0;
           
}
void mat_en_cero(int mat [][10]){
            for(int i=0;i<10;i++)
                        for(int j=0;j<10;j++)
                                   mat[i][j]=0;
           
}

void parte1(int mat[][10]){
    
    int fil, col;
    bool ocupado = true;
    srand(time(0)); //SEMILLA
    
    while (ocupado) {
        fil = rand() % 10; 
        col = rand() % 10; 
        if (mat[fil][col] == 0) { // verifica si la celda está vacía
            ocupado = false;
            mat[fil][col] = 1; // agrega la parte del barco en la celda vacía
        }
    }
}


void parte2(int mat[][10]){
    
    int fil, col;
    bool ocupado = true;
    srand(time(0)); // SEMILLA
    
    while (ocupado) {
        fil = rand() % 10; 
        col = rand() % 10; 
        int orientacion = rand() % 3; 
        if (orientacion == 0) { // orientación horizontal
            if (col < 9 && mat[fil][col] == 0 && mat[fil][col+1] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 2; 
                mat[fil][col+1] = 2; 
            }
        } else if (orientacion == 1) { // orientación vertical
            if (fil < 9 && mat[fil][col] == 0 && mat[fil+1][col] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 2; 
                mat[fil+1][col] = 2; 
            }
        } else { // orientación diagonal
            if (fil < 9 && col < 9 && mat[fil][col] == 0 && mat[fil+1][col+1] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 2; 
                mat[fil+1][col+1] = 2; 
            }
        }
    }
}

void parte3(int mat[][10]){
    
    int fil, col;
    bool ocupado = true;
    srand(time(0)); // SEMILLA
    
    while (ocupado) {
        fil = rand() % 10; 
        col = rand() % 10; 
        int orientacion = rand() % 3; 
        if (orientacion == 0) { // orientación horizontal
            if (col < 8 && mat[fil][col] == 0 && mat[fil][col+1] == 0 && mat[fil][col+2] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 3; 
                mat[fil][col+1] = 3; 
                mat[fil][col+2] = 3; 
            }
        } else if (orientacion == 1) { // orientación vertical
            if (fil < 8 && mat[fil][col] == 0 && mat[fil+1][col] == 0 && mat[fil+2][col] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 3; 
                mat[fil+1][col] = 3;
                mat[fil+2][col] = 3; 
            }
        } else { // orientación diagonal
            if (fil < 8 && col < 8 && mat[fil][col] == 0 && mat[fil+1][col+1] == 0 && mat[fil+2][col+2] == 0) { // verifica si las celdas están vacías
                ocupado = false;
                mat[fil][col] = 3; 
                mat[fil+1][col+1] = 3; 
                mat[fil+2][col+2] = 3; 
            }
        }
    }
}
void parte4(int mat[][10]){
    int fila,columna;


    // Generar aleatoriamente una posición inicial
    fila = rand() % 10;
    columna = rand() % 10;

    // Generar aleatoriamente la dirección del barco
    int dir = rand() % 3; // 0: horizontal, 1: vertical, 2: diagonal
    int f_inc = 0, c_inc = 0;
    if (dir == 0) { // horizontal
        c_inc = 1;
    } else if (dir == 1) { // vertical
        f_inc = 1;
    } else { // diagonal
        f_inc = 1;
        c_inc = 1;
    }

    // Verificar si es posible colocar el barco en la dirección generada
    bool puede_colocar = true;
    for (int i = 0; i < 4; i++) {
        int f = fila + i * f_inc;
        int c = columna + i * c_inc;
        if (f < 0 || f >= 10 || c < 0 || c >= 10 || mat[f][c] != 0) {
            puede_colocar = false;
            break;
        }
    }

    // Si es posible, colocar el barco en la dirección generada
    if (puede_colocar) {
        for (int i = 0; i < 4; i++) {
            int f = fila + i * f_inc;
            int c = columna + i * c_inc;
            mat[f][c] = 4;
        }
    } else { // Si no es posible, intentarlo de nuevo
        parte4(mat);
    }
}





void batalla(int tir,int &j,int h[],int a[]){
            h[j]=0;
            a[j]=0;
                       
            int mat[10][10];
            mat_en_cero(mat);
           
            parte1(mat);
            parte2(mat);
            parte3(mat);
            parte4(mat);

            for(int i=0;i<10;i++){

                        for(int j=0;j<10;j++){
                                    if(mat[i][j] > 0){
                                        cout<<"0"<<" | ";
                                    }
                                    else{
                                   cout<<mat[i][j]<<" | ";}
                        
}
cout<<endl;
            }
           
            int k=5;
            int fal[10][10],col,c1=0,fil;
            mat_en_x(fal);
            while(c1<tir){
                        cout<<"Seleccione coordenadas para disparar."<<endl<<endl;
                        cout<<"Introduzca columna: "<<endl;
                        cin>>col;
                        cout<<"Introduzca fila: "<<endl;
                        cin>>fil;
                        if(mat[fil-1][col-1]==0){
                                   cout<<endl<<"Agua. Recargando..."<<endl<<endl;
                        }else{
                                   if(mat[fil-1][col-1]==1){
                                                cout<<endl;
                                                cout<<endl;
                                               cout<<"HUNDISTE EL SUBMARINO!!"<<endl;fal[fil-1][col-1]=1;h[j]++;}
                                   if(mat[fil-1][col-1]==2){
                                                           cout<<"Has averiado la fragata."<<endl;fal[fil-1][col-1]=2;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==2){
                                                                                              cout<<"te falta una/s parte/s."<<endl;
                                                                                              a[j]++;k=0;}
                                                          
                                                           if(k==5){cout<<"FRAGATA HUNDIDA!!!"<<endl;h[j]++;}
                                                          
                                               }
                                   if(mat[fil-1][col-1]==3){
                                                           cout<<"Has averiado 55elacorazado."<<endl;fal[fil-1][col-1]=3;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==3){
                                                                                              cout<<"te falta una/s parte/s."<<endl;a[j]++;k=0;}
                                                           if(k==5){cout<<"ACORAZADO HUNDIDO!!!"<<endl;h[j]++;}
                                                          
                                                          
                                                          
                                               }
                                   if(mat[fil-1][col-1]==4){
                                                           cout<<"Has averiado el portaviones."<<endl;fal[fil-1][col-1]=4;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==4){
                                                                                              cout<<"te falta una/s parte/s."<<endl;a[j]++;k=0;}
                                                           if(k==5){cout<<"PORTAVIONES HUNDIDO BRAVO!!!"<<endl;h[j]++;}             
                                               }
                                              
                        }
                        for(int i=0;i<10;i++){
                                   for(int j=0;j<10;j++){
                                               cout<<fal[i][j]<<" | ";}
                                   cout<<endl;
                        }
                        cout<<endl<<endl<<endl<<endl;
                        c1++;
                        k=5;
            }
           
           
           

}