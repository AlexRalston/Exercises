/*En una estacion meteo se toman meidiciones 7x24 matriz filas son dias y columnas temperaturas*/
#include<iostream>
#include<iomanip>


using namespace std;

int main(){
    const int NUM_DIAS=7;
    const int NUM_HORAS=24;

    //Declaracion del array
    int temperaturas[NUM_DIAS][NUM_HORAS];

    //El usuario introduce datos por pantalla en el array
    for(int i=0;i<NUM_DIAS;i++){

        cout<<"Temperaturas del dia " << i+1 <<":"<<endl;

        for(int j=0;j<NUM_HORAS;j++){
            cout<<"Hora "<<j+1<<": ";
            cin>>temperaturas[i][j];

        }

    }
    //Creamos las variables correspondientes a la temperatura maxima y la temperatura minima de la semana
    int temp_max = temperaturas[0][0];
    int temp_min  = temperaturas[0][0];
    //Bucle que añade valores maximos y minimos
    for(int i=0;i<NUM_DIAS;i++){
        for(int j=0;j<NUM_HORAS;j++){

            if(temperaturas[i][j] > temp_max){
                temp_max = temperaturas[i][j];
            }
            if(temperaturas[i][j] < temp_min){
                temp_min = temperaturas[i][j];
            }
        }
    }
    //Imnprimimos la temperatura maxima de la semana
    cout<<"Temperatura maxima de la semana: "<<temp_max<<"ºC"<<endl;
    //Imprimimos la temperatura minima de la semana
    cout<<"Temperatura minima de la semana: "<<temp_min<<"ºC"<<endl;
    //Calcular la temperaturas maximas y minimas de cada dia
    for(int i=0;i<NUM_DIAS;i++){
        temp_max = temperaturas[i][0];
        temp_min = temperaturas[i][0];
        for(int j=0;j<NUM_HORAS;j++){
            if(temperaturas[i][j] > temp_max){
                temp_max = temperaturas[i][j];
            }
            if(temperaturas[i][j] < temp_min){
                temp_min = temperaturas[i][j];
            }
        }
        cout<<"La temperatura maxima del dia "<<i+1<<" es: "<<temp_max<<"ºC"<<endl;
        cout<<endl;
        cout<<"La temperatura minima del dia "<<i+1<<" es: "<<temp_min<<"ºC"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    //Calculemos la temperatura media de la semana
    double temp_suma=0;
    for(int i=0;i<NUM_DIAS;i++){
        for(int j=0;j<NUM_HORAS;j++){
            temp_suma += temperaturas[i][j];

        }
    }
    double temp_media = temp_suma / (NUM_DIAS*NUM_HORAS);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"La temperatura media de la semana es: "<<temp_media<<"ºC"<<"."<<endl;
    //Calculemos la temperatura media de cada dia
    cout<<endl;

    for(int i=0;i<NUM_DIAS;i++){
        double media_cada_dia=temperaturas[i][0];
        for(int j=0;j<NUM_HORAS;j++){
            media_cada_dia += temperaturas[i][j];
            

        }
        cout<<"La temperatura media del dia "<<i+1<<" es: "<<media_cada_dia<<"ºC"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    int num_dias_mayor_treinta=0;
    for(int i=0;i<NUM_DIAS;i++){
        for(int j = 0;j<NUM_HORAS;j++){
            if(temperaturas[i][j] > 30  ){
                num_dias_mayor_treinta++;
            }
             

        }

    }
    cout<<endl;
    cout<<"El numero de dias que superan los 30ºC es "<<num_dias_mayor_treinta<<".";



    return 0;

}