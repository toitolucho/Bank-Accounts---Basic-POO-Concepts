
#include <list >
#include "Persona.cpp"
// #include "Banco.cpp"
#include "Servicio.cpp"
using namespace std;
#ifndef Cuenta_H
#define Cuenta_H


class Banco;

enum TipoCuenta
{
    CajaAhorro, PlazoFijo, Empresarial
};


class Cuenta
{
    private:
        
        TipoCuenta tipo;
        
        Banco *entidad;

    public:
        int nroCuenta;
        float saldo;
        Persona duenio;
        Cuenta()
        {
            nroCuenta = 123456;
            saldo =0;
            tipo = TipoCuenta::CajaAhorro;
        }
        Cuenta(Persona titular)
        {
            nroCuenta = 123456;
            saldo =0;
            tipo = TipoCuenta::CajaAhorro;
            // entidad = enti;
            duenio = titular;
        }

        Cuenta(Banco *b,  Persona titular)
        {
            nroCuenta = 123456;
            saldo =0;
            tipo = TipoCuenta::CajaAhorro;
            entidad = b;
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
            // cout<<"Entidad Bancaria" << entidad.nombre<<endl;
        }


        //D) Incopore una clase Transaccion que permita representar todos los movimientos de una cuenta.
        // los mivimientos deben realizarse  en un DEPOSITO, RETIRO, TRANSFERENCIA Y UN PAGO SERVICIO
        // los attributos de la clase seran los siguientes: Fecha, NroTransaccion (Autoenumerable), Monto, Tipo(DEPOSITO, RETIRO, TRANSFERENCIA Y UN PAGO SERVICIO) enumeracion
};

#endif 