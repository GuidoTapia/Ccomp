#include <iostream>

using namespace std;
class michi3d{
public:
    char tab[3][3][3];
    int x,y,z;
    char jugadores[2];
    bool flag;
    char*pos;
    michi3d(){
        for(char*i=(char*)tab;i<(char*)tab+27;i++){
            *i=0;
        }
        *jugadores='x';
        *(jugadores+1)='o';
        flag=1;
        pos=NULL;
    }
    void mostrar(){
        cout<<"-------\n";
        for(char(*i)[3][3]=tab;i<tab+3;i++){
            for(char(*j)[3]=*i;j<*i+3;j++){
                cout<<'|';
                for(char*k=*j;k<*j+3;k++){
                    cout<<*k<<'|';
                }
                cout<<'\n';
            }
            cout<<"-------\n";
        }
    }
    bool jugada(){
        pos=*(*(tab+x)+y)+z;
        if(*pos==0){
           *pos=*(jugadores+flag);
           return false;
        }
        return true;
    }
    bool comp(){
        char*i=pos-(9*x);
        while(*i==*(jugadores+flag)){
            if(i>=pos+(9*(2-x))){
                return false;
            }
            i+=9;
        }
        i=pos-(3*y);
        while(*i==*(jugadores+flag)){
            if(i>=pos+(3*(2-y))){
                return false;
            }
            i+=3;
        }
        i=pos-z;
        while(*i==*(jugadores+flag)){
            if(i>=pos+(2-z)){
                return false;
            }
            i++;
        }
        if(x==y){
            i=pos-(12*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(12*(2-x))){
                    return false;
                }
                i+=12;
            }
        }
        if(x+y==2){
            i=pos-(6*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(6*(2-x))){
                    return false;
                }
                i+=6;
            }
        }
        if(x==z){
            i=pos-(10*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(10*(2-x))){
                    return false;
                }
                i+=10;
            }
        }
        if(x+z==2){
            i=pos-(8*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(8*(2-x))){
                    return false;
                }
                i+=8;
            }
        }
        if(z==y){
            i=pos-(y*4);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(4*(2-y))){
                    return false;
                }
                i+=4;
            }
        }
        if(z+y==2){
            i=pos-(2*y);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(2*(2-y))){
                    return false;
                }
                i+=2;
            }
        }
        if(x==y&&y==z){
            i=pos-(13*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(13*(2-x))){
                    return false;
                }
                i+=13;
            }
        }
        if(x==y&&y+z==2){
            i=pos-(11*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(11*(2-x))){
                    return false;
                }
                i+=11;
            }
        }
        if(x==z&&y+x==2){
            i=pos-(7*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(7*(2-x))){
                    return false;
                }
                i+=7;
            }
        }
        if(z==y&&x+z==2){
            i=pos-(5*x);
            while(*i==*(jugadores+flag)){
                if(i>=pos+(5*(2-x))){
                    return false;
                }
                i+=5;
            }
        }
        return true;
    }
    void play(){
        do{
            flag= !flag;
            mostrar();
            do{
                cout<< "ingresa jugada de player "<<flag+1<<endl;
                cin>>x>>y>>z;
            }while(jugada());
        }while(comp());
        mostrar();
        cout<< "gano player "<<flag+1<<endl;
    }
};
int main(){
    michi3d nuevo=michi3d();
    nuevo.play();
    return 0;
}
