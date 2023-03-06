
#include <iostream>
using namespace std;

void mat_en_cero(int mat[][10]);
void mat_en_x(int mat[][10]);
void parte1(int mat[][10]);
void parte2(int mat[][10]);
void parte3(int mat[][10]);
void parte4(int mat[][10]);
void batalla(int tir,int &j,int h[],int a[]);

int main(int argc, char *argv[]) {
            int cant;
            char jug[10][10];
            cout<<"Introduzca cantidad de jugadores: ";
            cin>>cant;
            for(int i=0;i<cant;i++){
                        cout<<"Introduzca el nombre del o los jugadores: "<<i+1<<" : ";
                        cin>>jug[i];
                        cout<<endl;
            }
            int tir;
           
            cout<<endl<<"Cuantos tiros quieres?"<<endl;
            cin>>tir;
            int h[4],a[4];
            int i=1,gan=0,seg=0;
            for(int f=0;f<cant;f++){
            batalla(tir,i,h,a);
            i++;
            cout<<endl<<endl<<"Turno seguiente jugador:"<<endl;}
            for(int j=0;j<cant;j++){
                
                        if(h[j+1]>seg){
                        if(seg>gan){
                        seg=gan;gan=h[j+1];}
                        else
                                   seg=h[j+1];
                        }
                       
            }
            cout<<"Ganador: "<<jug[gan]<<". Barcos Hundidos: "<<h[gan]<<endl;
           
                       
           
           
           
           
                                              
           
           
        
           
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
int fil,col;
cout<<"Barco de 1 parte"<<endl<<"Introduzca fila:"<<endl;
cin>>fil;
cout<<"Introduzca columna:"<<endl;
cin>>col;
mat[fil-1][col-1]=1;
}
void parte2(int mat[][10]){
            int fil,col;
            cout<<"Barco de 2 partes"<<endl;
            for(int i=0;i<2;i++){
            cout<<"Introduzca fila:"<<endl;
            cin>>fil;
            cout<<"Introduzca columna:"<<endl;
            cin>>col;
            mat[fil-1][col-1]=2;
            }
            
           
}
void parte3(int mat[][10]){
            int fil,col;
            cout<<"Barco de 3 partes"<<endl;
            for(int i=0;i<3;i++){
                        cout<<"Introduzca fila:"<<endl;
                        cin>>fil;
                        cout<<"Introduzca columna:"<<endl;
                        cin>>col;
                        mat[fil-1][col-1]=3;
            }
}
void parte4(int mat[][10]){
            int fil,col;
            cout<<"Barco de 4 partes"<<endl;
            for(int i=0;i<4;i++){
                        cout<<"Introduzca fila:"<<endl;
                        cin>>fil;
                        cout<<"Introduzca columna:"<<endl;
                        cin>>col;
                        mat[fil-1][col-1]=4;
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
                                   cout<<mat[i][j];}
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
                                   cout<<endl<<"Aguaaaa"<<endl<<endl;
                        }else{
                                   if(mat[fil-1][col-1]==1){
                                               cout<<"HUNDISTE EL BARCO DE 1 PARTE!!"<<endl;fal[fil-1][col-1]=1;h[j]++;}
                                   if(mat[fil-1][col-1]==2){
                                                           cout<<"Has averiado el navio de 2 partes."<<endl;fal[fil-1][col-1]=2;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==2){
                                                                                              cout<<"te falta una/s parte/s."<<endl;
                                                                                              a[j]++;k=0;}
                                                          
                                                           if(k==5){cout<<"BARCO HUNDIDO!!!"<<endl;h[j]++;}
                                                          
                                               }
                                   if(mat[fil-1][col-1]==3){
                                                           cout<<"Has averiado el navio de 3 partes."<<endl;fal[fil-1][col-1]=3;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==3){
                                                                                              cout<<"te falta una/s parte/s."<<endl;a[j]++;k=0;}
                                                           if(k==5){cout<<"BARCO HUNDIDO!!!"<<endl;h[j]++;}
                                                          
                                                          
                                                          
                                               }
                                   if(mat[fil-1][col-1]==4){
                                                           cout<<"Has averido el navio de 4 partes."<<endl;fal[fil-1][col-1]=4;
                                                           mat[fil-1][col-1]=0;
                                                           for(int i=0;i<10;i++)
                                                                       for(int j=0;j<10;j++)
                                                                                  if(mat[i][j]==4){
                                                                                              cout<<"te falta una/s parte/s."<<endl;a[j]++;k=0;}
                                                           if(k==5){cout<<"BARCO HUNDIDO!!!"<<endl;h[j]++;}             
                                               }
                                              
                        }
                        for(int i=0;i<10;i++){
                                   for(int j=0;j<10;j++){
                                               cout<<fal[i][j];}
                                   cout<<endl;
                        }
                        cout<<endl<<endl<<endl<<endl;
                        c1++;
                        k=5;
            }
           
           
           

}