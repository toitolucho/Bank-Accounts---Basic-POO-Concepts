#include <iostream>
using namespace std;

class Servicio
{
    private:
        string nombre;
        float costo;

    public:
        Servicio()
        {
            nombre = "Pago Servicio de Alumbrado Electrico";
            costo = 150;
        }
        Servicio(string name, float cost)
        {
            nombre = name;
            costo = cost;
        }

        void setNombre(string n)
        {
            nombre = n;
        }
        void setCosto(float cost)
        {
            costo = cost;
        }
        string getNombre()
        {
            return nombre;
        }
        float getCosto()
        {
            return costo;
        }
};