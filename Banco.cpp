
#include <list>
#include "Cuenta.cpp"
#include "Persona.cpp"
using namespace std;
#ifndef Banco_H
#define Banco_H
class Banco
{
    private:
        int idBanco;
        string direccion;
        list<Cuenta> cuentas;
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
        Banco(string nom, string dir, list<Cuenta> listaCuentas )
        {
            nombre = nom;
            direccion = dir;
            cuentas = listaCuentas;
        }
        void verInfo()
        {
            cout<<"Nombre Banco : "<<nombre<<endl;
            cout<<"Direccion "<<direccion<<endl;
        }
        //A) Complete la funcion para calcular el total de dinero que tiene actualmente el banco como fondo base por parte de sus clientes.
        //la funcion debe devolver el valor calculado, puede utilizar temporalmente la impresion en consola, se evaluara que el valor
        //sea invocada y visualizada desde la funcion principal        
        float obtenerCapital()
        {
            float total;
            for (list<Cuenta>::iterator it = cuentas.begin(); it != cuentas.end(); it++) {
                total = total + it->saldo;
            }
            return total;
        }
        //B) complete la funcion para obtener el cliente mas potencial, considerando aquel que tiene una cuenta con saldo grande
        //la funcion debe devolver a la persona como tal
        Persona *obtenerClientePotencial()
        {
           Persona* p = nullptr;
           float saldoGrande = 0;
            for (list<Cuenta>::iterator it = cuentas.begin(); it != cuentas.end(); it++) {
                if (it->saldo > saldoGrande) {
                    p = &it->duenio;
                    saldoGrande = it->saldo;
                }
            }
            return p;                
        }
        
        
};
#endif /* Banco_H */