#include<iostream>
#include<stdlib.h>
using namespace std;



void loop (char m[3][3]);
void primera (char m[3][3]);
void tablero (char m[3][3]);

int main(){
    char m[3][3];
    loop(m);//Llama a todas las funciones fundamentales y refresh
    system("PAUSE");
    return 0;
}

void loop(char m[3][3]){
    primera(m);
    tablero(m);

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
    cout<<endl;
    cout<<endl;
    
    }




