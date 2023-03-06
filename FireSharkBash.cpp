#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){


//Creamos la variable que nos permite ver la interfaz de red
system("intfred=$(ip link show | grep "eth0\|ens33\|wlan0" | grep "UP " | cut -d" " -f2 | tr ':' ' ')");
syst


return 0;
}