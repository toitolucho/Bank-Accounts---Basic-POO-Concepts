#include <iostream>
using namespace std;

class Banco
{
    private:
        
        string direccion;

    public:
        string nombre;
        Banco()
        {
            nombre = "Banco Nacional de Bolivia";
            direccion = "Calle España Nro 154";
        }
        Banco(string nom)
        {
            nombre = nom;
            direccion = "Calle Arenales Nro 252";
        }
        Banco(string nom, string dir)
        {
            nombre = nom;
            direccion = dir;
        }
        void verInfo()
        {
            cout<<"Nombre Banco : "<<nombre<<endl;
            cout<<"Direccion "<<direccion<<endl;
        }
        
};