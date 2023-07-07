
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

        int getIdBanco() {
		    return idBanco;
        }
        void setNombre(string _nombre) {
            nombre = _nombre;
        }
        void setDireccion(string _direccion) {
            direccion = _direccion;
        }
        void setIdBanco(int _id_banco) {
            idBanco = _id_banco;
        }

        list<Cuenta> &getListaCuentas() {
		    return cuentas;
        }
        string getDireccion() {
            return direccion;
        }

        
        float obtenerCapital()
        {
            float total=0;
            for (list<Cuenta>::iterator it = cuentas.begin(); it != cuentas.end(); it++) {
                total = total + it->saldo;
            }
            return total;
        }
        
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