#include<iostream>
#include<stdlib.h>

#include<time.h>//Necesario para generar numeros aleatorios
using namespace std;



void loop (char m[3][3]);
void primera (char m[3][3]);

void tablero (char m[3][3]);
void Intro_Yo(char m[3][3]);
void Intro_aleatorio(char m[3][3]);
int main(){
    char m[3][3];
    loop(m);//Llama a todas las funciones fundamentales y refresh
    system("PAUSE");
    return 0;
}

void loop(char m[3][3]){
    int i;

    i=0;

    primera(m);
    cout<<endl;
    cout<<endl;
    tablero(m);

    do{ 
        system("cls");
        tablero(m);

        if(i%2==0){
            Intro_Yo(m);
        }
        else{
            Intro_aleatorio(m);
        }
        i++;

    }while (i<=9);
    

}

void primera (char m[3][3]){

    char aux;

    aux = '1';

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m[i][j]=aux++;
            

        }
    }
}
void tablero (char m[3][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j<2){
                printf(" %c |",m[i][j]);
            }
            else{
                printf(" %c ",m[i][j]);
            }

        }
        if(i<2){
        printf("\n-----------\n");}
    }
}

void Intro_Yo(char m[3][3]){
    int i, j, k;
    char aux;

    do{
        do{
            cout<<endl;
            cout<<endl;
            printf("Coloca una ficha sobre el tablero: ");
            cout<<endl;
            cout<<endl;

            fflush(stdin);
            scanf("%c",&aux);

        }while(aux < '1' || aux > '9');
    k=0;
    switch (aux){
        case '1':{
            i = 0;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre."<<endl;
                cout<<endl;

            }
            break;
        }
        case '2':{
            i = 0;
            j = 1;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '3':{
            i = 0;
            j = 2;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '4':{
            i = 1;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '5':{
            i = 1;
            j = 1;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '6':{
            i = 1;
            j = 2;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '7':{
            i = 2;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '8':{
            i = 2;
            j = 1;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }
        case '9':{
            i = 2;
            j = 2;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre"<<endl;
                cout<<endl;

            }
            break;
        }

        
    }

}while(k==1);

m[i][j] = 'X';
}

void Intro_aleatorio(char m[3][3]){
    int i,j,k;
    
    srand(time(NULL));
    do{
    i= rand() % 3;
    j= rand() % 3;
    k=0;

    if(m[i][j] == 'X' || m[i][j] == 'O'){
        k=1;
    }

    }while(k==1);


    m[i][j] = 'O';


}
   




