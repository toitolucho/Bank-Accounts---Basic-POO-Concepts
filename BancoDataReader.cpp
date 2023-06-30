#include <iostream>
#include <list>
#include "Banco.cpp"
#include "Cuenta.cpp"
#include "Persona.cpp"
#include "Servicio.cpp"

//C -> aplique el principio de singleton a la clase BancoDataReader

class BancoDataReader
{
     private :
        //referencia a la unica instancia posible de la clase
        static list<Banco> getBancos()
        {
            list<Cuenta> listaDatosCuentas;
            list<Banco> listaDatosBancos;
            

            return listaDatosBancos;
        }
};