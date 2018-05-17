#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;
void cambiar(char*a,char*b){
    char aux=*a;
    *a=*b;
    *b=aux;
}
class juego{
public:
    char tab[4][4];
    char*vacio;
    juego(){
        char*e=*tab;
        for(;e<(*tab+15);e++){
            *e=65+(e-*tab);
        }
        *e=0;
        vacio=e;
    }
    void imprimir(){
        cout<<"################\n#\t       #\n#  ";
        for(char*e=*tab;e<*tab+16;e++){
            cout<<*e;
            if((e-*tab)%4==3)
                cout<<"  #\n#  ";
            else
                cout<<"  ";
        }
        cout<<"\t       #\n################";
    }
    bool mov(char c){
        if(c=='s'&&vacio-4>=*tab){
            cambiar(vacio,vacio-4);
            vacio-=4;
            return false;
        }if(c=='w'&&vacio+4<(*tab)+16){
            cambiar(vacio,vacio+4);
            vacio+=4;
            return false;
        }if(c=='d'&&(vacio-(*tab))%4){
            cambiar(vacio,vacio-1);
            vacio--;
            return false;
        }if(c=='a'&&(vacio-(*tab))%4!=3){
            cambiar(vacio,vacio+1);
            vacio++;
            return false;
        }
        return true;
    }
    bool comprobar(){
        for(char*e=*tab;e<*tab+15;e++){
            if(*e!=65+(e-*tab))
                return true;
        }
        return false;
    }
    void mezclar(){
        char aux;
        int auxi;
        srand(time(NULL));
        for(int i=0;i<100;i++){
            do{
                auxi=rand()%4;
                if(!auxi){
                    aux='w';
                }else if(auxi==1){
                    aux='s';
                }else if(auxi==2){
                    aux='a';
                }else{
                    aux='d';
                }
            }while(mov(aux));
        }
    }
    void run(){
        char j;
        mezclar();
        imprimir();
        do{
            do{
                cout<<"\ningresa un movimiento (w),(a),(s),(d)"<<endl;
                cin>>j;
            }while(mov(j));
            imprimir();
        }while(comprobar());
    }
};
int main(){
    juego algo=juego();
    algo.run();
    return 0;
}
