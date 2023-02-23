/*En una estacion meteo se toman meidiciones 7x24 matriz filas son dias y columnas temperaturas*/
#include<iostream>
#include<iomanip>

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
    cout<<"Temperatura maxima de la semana: "<<temp_max<<endl;
    //Imprimimos la temperatura minima de la semana
    cout<<"Temperatura minima de la semana: "<<temp_min<<endl;
    //Calcular la temperaturas maximas y minimas de cada dia
    for(int i=0;i<NUM_DIAS;i++){
        temp_max = temperaturas[i][0];
        temp_min = temperaturas[i][0];
        for(int j=0;j<NUM_HORAS;j++){
            if(temperaturas[i][j]> temp_max){
                temp_max = temperaturas[i][j];
            }
            if(temperaturas[i][j]<temp_min){
                temp_min = temperaturas[i][j];
            }
        }
    }
    //Imprimimos la temperatura maxima del dia
    cout<<"La temperatura maxima del dia "<<i+1<<": "<<temp_max<<endl;
    //Imprimimos la temperatura minima del dia
    cout<<"La temperatura minima del dia "<<i+1<<": "<<temp_min<<endl;
    //Calculemos la temperatura media de la semana
    double temp_suma=0;
    for(int i=0;i<NUM_DIAS;i++){
        for(int j=0;j<NUM_HORAS;j++){
            temp_suma += temperaturas[i][j];

        }
    }
    double temp_media = temp_suma / (NUM_DIAS*NUM_HORAS);
    cout<<"La temperatura media de la semana es: "<<temp_media<<"."<<endl;
    //Calculemos la temperatura media de cada dia
    
    for(int i=0;i<NUM_DIAS;i++){
        double media_cada_dia=temperaturas[i][0];
        for(int j=0;j<NUM_HORAS;j++){
            media_cada_dia +=
            

        }

    }


    return 0;

}