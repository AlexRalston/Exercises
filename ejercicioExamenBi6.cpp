#include<iostream>


using namespace std;


int main(){
    system("intfred=$(ip link show | grep "eth0\|ens33\|wlan0" | grep "UP " | cut -d" " -f2 | tr ':' ' ')");
    system("echo "$(tput setaf 6)"");
    system("figlet IFPS PUENTEUROPA");
    system("echo "$(tput setaf 1)"");
    system("trap finish SIGINT ");
    


    


    }






    return 0;
}