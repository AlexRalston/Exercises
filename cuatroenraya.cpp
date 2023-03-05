#include<iostream>
#include<stdlib.h>

#include<time.h>//Necesario para generar numeros aleatorios
using namespace std;









void loop (char m[4][4]);
void primera (char m[4][4]);
void tablero (char m[4][4]);
void Intro_Yo(char m[4][4]);
void Intro_aleatorio(char m[4][4]);
int ganador(char m[4][4]);



















int main(){
    char m[4][4];
    loop(m);//Llama a todas las funciones fundamentales y refresh
    system("PAUSE");
    return 0;
}
























void loop(char m[4][4]){
    int i,j;

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
        j = ganador(m);
        i++;

    }while (i <= 16 && j == 2);

    system("cls");
    tablero(m);

    if(j == 0){
        cout<<"Enhorabuena!!Has ganado!!!";
        cout<<endl;
        cout<<endl;
    }
    else if(j == 1){
        cout<<"Has perdido, otra vez sera.";
    }
    else{
        cout<<endl;
        cout<<endl;

        cout<<"Has empatado, vuelvelo a intentar";
        cout<<endl;
        cout<<endl;
    }
    

}







void primera (char m[4][4]){

    char aux;

    aux = '1';

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            m[i][j]=aux++;
            

        }
    }
}

















void tablero (char m[4][4]){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j<3){
                printf(" %c |",m[i][j]);
            }
            else{
                printf(" %c ",m[i][j]);
            }

        }
        if(i<3){
        printf("\n---------------\n");}
    }
}























void Intro_Yo(char m[4][4]){
    int i, j, k;
    char aux;

    do{
        do{
            cout<<endl;
            cout<<endl;
            printf("Coloca una ficha sobre el tablero(los caracteres especiales se corresponden en orden a las letras A-G): ");
            cout<<endl;
            cout<<endl;

            fflush(stdin);
            scanf("%c",&aux);

        }while(aux < '1' || aux > 'G');
    k=0;
    switch (aux){
        case '1':{
            i = 0;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '2':{
            i = 0;
            j = 1;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '3':{
            i = 0;
            j = 2;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '4':{
            i = 0;
            j = 3;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '5':{
            i = 1;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '6':{
            i = 1;
            j = 1;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '7':{
            i = 1;
            j = 2;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '8':{
            i = 1;
            j = 3;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case '9':{
            i = 2;
            j = 0;
            if(m[i][j] == 'X' || m[i][j] == 'O'){
                k=1;
                cout<<"La casilla esta ocupada, intentalo con otra que este libre..."<<endl;
                cout<<endl;

            }
            break;
        }
        case 'A': {
        i = 2;
        j = 1;
    if (m[i][j] == 'X' || m[i][j] == 'O') {
        k = 1;
        cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
        cout << endl;
    }
    break;
}
    case 'B': {
        i = 2;
        j = 2;
        if (m[i][j] == 'X' || m[i][j] == 'O') {
            k = 1;
            cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
            cout << endl;
        }
            break;
}
    case 'C': {
            i = 2;
            j = 3;
        if (m[i][j] == 'X' || m[i][j] == 'O') {
            k = 1;
            cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
            cout << endl;
    }
    break;
}
case 'D': {
    i = 3;
    j = 0;
    if (m[i][j] == 'X' || m[i][j] == 'O') {
        k = 1;
        cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
        cout << endl;
    }
    break;
}
case 'E': {
    i = 3;
    j = 1;
    if (m[i][j] == 'X' || m[i][j] == 'O') {
        k = 1;
        cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
        cout << endl;
    }
    break;
}
case 'F': {
    i = 3;
    j = 2;
    if (m[i][j] == 'X' || m[i][j] == 'O') {
        k = 1;
        cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
        cout << endl;
    }
    break;
}
case 'G': {
    i = 3;
    j = 3;
    if (m[i][j] == 'X' || m[i][j] == 'O') {
        k = 1;
        cout << "La casilla esta ocupada, intentalo con otra que este libre..." << endl;
        cout << endl;
    }
    break;
}

        
    }

}while(k==1);

m[i][j] = 'X';
}





































void Intro_aleatorio(char m[4][4]){
    int i,j,k;
    
    srand(time(NULL));
    do{
    i= rand() % 4;
    j= rand() % 4;
    k=0;

    if(m[i][j] == 'X' || m[i][j] == 'O'){
        k=1;
    }

    }while(k==1);


    m[i][j] = 'O';


}












int ganador(char m[4][4]){

    // Comprobar si hay un ganador en las filas
    for(int i=0; i<4; i++){
        for(int j=0; j<1; j++){
            if(m[i][j] != '-' && m[i][j] == m[i][j+1] && m[i][j] == m[i][j+2] && m[i][j] == m[i][j+3]){
                if(m[i][j] == 'X'){
                    return 0; // Jugador 1 gana
                } else {
                    return 1; // Jugador 2 gana
                }
            }
        }
    }

    // Comprobar si hay un ganador en las columnas
    for(int i=0; i<1; i++){
        for(int j=0; j<4; j++){
            if(m[i][j] != '-' && m[i][j] == m[i+1][j] && m[i][j] == m[i+2][j] && m[i][j] == m[i+3][j]){
                if(m[i][j] == 'X'){
                    return 0; // Jugador 1 gana
                } else {
                    return 1; // Jugador 2 gana
                }
            }
        }
    }

    // Comprobar si hay un ganador en las diagonales descendentes
    for(int i=0; i<1; i++){
        for(int j=0; j<1; j++){
            if(m[i][j] != '-' && m[i][j] == m[i+1][j+1] && m[i][j] == m[i+2][j+2] && m[i][j] == m[i+3][j+3]){
                if(m[i][j] == 'X'){
                    return 0; // Jugador 1 gana
                } else {
                    return 1; // Jugador 2 gana
                }
            }
        }
    }

    // Comprobar si hay un ganador en las diagonales ascendentes
    for(int i=0; i<1; i++){
        for(int j=3; j<4; j++){
            if(m[i][j] != '-' && m[i][j] == m[i+1][j-1] && m[i][j] == m[i+2][j-2] && m[i][j] == m[i+3][j-3]){
                if(m[i][j] == 'X'){
                    return 0; // Jugador 1 gana
                } else {
                    return 1; // Jugador 2 gana
                }
            }
        }
    }

    // Si no hay ganador, devuelve 2
    return 2;
}





   




