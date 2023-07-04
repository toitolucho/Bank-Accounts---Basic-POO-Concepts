#include <iostream>
#include "Banco.cpp"
#include "BancoDataReader.cpp"

using namespace std;


//esta funcion permite volcar cualquier numero n pequenio
//por ejemplo si n = 12, entonces la respuesta sera x = 21
short volcar(short n)
{
    short x,d;
    x = 0;
    while(n!=0)
    {
        d = n%10;
        n = n/10;
        x = x*10+d;
    }
    return x;
}

int obtenerSigHoraPalindroma(short h, short m)
{
    short h1=h, m1=m;  
    do
    {
        m1++;
        if(m1==60)
        {
            m1=0;
            h1 = h1+1 ;   
        }        
        if(h1 == 24)
            h1 = 0;
        cout<<h1<<" "<<m1<<endl;
    }
    while(h1!= volcar(m1));
    
    return h1*60+m1;
}
int main()
{
    // short h1,m1;
    // cin>>h1>>m1;
    // if(h1 == volcar(m1))
    // {
    //     //aca se deben considerar condiciones de formato
    //     cout<<h1<<":"<<m1<<":00 Hora Palindroma"<<endl;
    // }
    // else
    // {
    //     //aca se deben considerar condiciones de formato
    //     cout<<h1<<":"<<m1<<":00 No es Hora Palindroma"<<endl;
    // }
    // int sighp = obtenerSigHoraPalindroma(h1,m1);
    // //aca se deben considerar condiciones de formato
    // cout<<sighp/60<<":"<<sighp%60<<endl;


    Banco b1;
    b1.verInfo();
    cout<<b1.obtenerCapital()<<endl;
    BancoDataReader* b = BancoDataReader::getInstance();

    return 0;


}