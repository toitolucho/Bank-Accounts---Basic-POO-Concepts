#include <iostream>
using namespace std;

//declaring Fecha struct
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

class Persona
{
    private:
        int ci;
        Fecha fechaNacimiento;
    public:
        string nombres;
        string apellidos;

        Persona()
        {
            nombres = "Luis";
            apellidos = "Molina";
        }

        string getNombreCompleto()
        {
            return nombres + " " + apellidos;
        }
};
