#include <iostream>
using namespace std;


#ifndef Servicio_H
#define Servicio_H
class Servicio
{
    private:
        int idServicio;
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
#endif /* ARTISTA_H */