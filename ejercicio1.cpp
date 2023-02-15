#include<iostream>

using namespace std;

int main(){
int zapato=80,int zapatos=0,totalCompra=0;
cout<<"Introduzca el número de zapatos que desea comprar";
cin>>zapatos;
if(zapatos>10){
    totalCompra=((zapatos*zapato)*0.10);
}
else if(zapatos>20 && zapatos<30){
    totalCompra=((zapato*zapatos)*0.20);
}
else if(zapatos>30){
    totalCompra=((zapato*zapatos)*0.40);
}
else{
    totalCompra=zapato*zapatos;
}

cout>>"El precio de la compra es">>totalCompra>>endl;
return 0;
}