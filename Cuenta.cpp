#include <iostream>
#include "Persona.cpp";
#include "Banco.cpp";
#include "Servicio.cpp";
using namespace std;
enum TipoCuenta
{
    CajaAhorro, PlazoFijo, Empresarial
};


class Cuenta
{
    private:
        Persona duenio;
        TipoCuenta tipo;
        int nroCuenta;
        float saldo;
        Banco entidad;

    public:
        Cuenta()
        {
            nroCuenta = 123456;
            saldo =0;
            tipo = TipoCuenta::CajaAhorro;
        }
        Cuenta(Banco enti, Persona titular)
        {
            nroCuenta = 123456;
            saldo =0;
            tipo = TipoCuenta::CajaAhorro;
            entidad = enti;
            duenio = titular;
        }

        void depositar(float monto)
        {
            saldo += monto;
        }

        bool haySaldo()
        {
            return saldo>0;
        }
        bool sePuedeRetirar(float monto)
        {
            return saldo-monto>=0;
        }
        void retirar(float monto)
        {
            saldo -= monto;
        }
        void transferir(float monto, Cuenta destino)
        {
            if(haySaldo() && sePuedeRetirar(monto))
            {
                retirar(monto);
                destino.depositar(monto);
            }
        }

        void pagarServicio(Servicio serv )
        {
            if(haySaldo() && sePuedeRetirar(serv.getCosto()))
            {
                retirar(serv.getCosto());
                
            }
        }
        void generarFactura(Servicio serv, Fecha fechaActual)
        {
            cout<<"Son en total "<< serv.getCosto() << "Bs por el pago del servicio"<< serv.getNombre()<<endl; 
            cout<<"Sucre "<<fechaActual.dia<< "del mes de "<<fechaActual.mes<< " del anio "<<fechaActual.anio<<endl;
        }

        void verSaldo()
        {
            cout<<"Su saldo actual es "<< saldo<<endl;
        }
        void verInfo()
        {
            cout<<"Nro de Cuenta" << nroCuenta<< " correspondiente a" << duenio.getNombreCompleto()<<endl;
            cout<<"Su saldo actual es "<< saldo<<endl;
            cout<<"Entidad Bancaria" << entidad.nombre<<endl;
        }
};