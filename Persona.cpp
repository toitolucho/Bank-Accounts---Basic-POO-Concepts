#include <iostream>
//#include "Cuenta.cpp"
using namespace std;

#ifndef Persona_H
#define Persona_H

class Cuenta;

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
        Cuenta *cuentaPersonal;
    public:
        string nombres;
        string apellidos;

        Persona()
        {
            nombres = "Luis";
            apellidos = "Molina";
        }

        Persona(int _ci,int _dia, int _mes, int _anio, string _nombre, string _apellido) {
            nombres = _nombre;
            apellidos = _apellido;
            ci = _ci;
            fechaNacimiento.dia = _dia;
            fechaNacimiento.mes = _mes;
            fechaNacimiento.anio = _anio;
        }

        string getNombreCompleto()
        {
            return nombres + " " + apellidos;
        }

        int getCi()
        {
            return ci;
        }
        Fecha getFechaNacimiento()
        {
            return fechaNacimiento;
        }

        void setCi(int carnet)
        {
            ci = carnet;
        }

        void setFechaNacimiento(Fecha fecha)
        {
            fechaNacimiento = fecha;
        }

        string getProcedencia()
        {
            //calculamos la procedencia en funcion al ultimo digito del ci
            //cosnideramos el siguiente orden
            /*
            1.-La Paz
            2.-Oruro
            3.-Potosi
            4.-Cochabamba
            5.-Chuquisaca
            6.-Tarija
            7.-Pando
            8.-Beni
            9.-Santa Cruz
            */

           //calcular el ultimo digito
           int ud = ci%10;
           //creamos un data set acorde a los datos
           string departamentos[9] {"La Paz","Oruro","Potosi","Cochabamba","Chuquisaca","Tarija","Pando","Beni","Santa Cruz"};
           return departamentos[ud-1];
        }

        int getEdad(Fecha fechActual)
        {
            return fechActual.anio - fechaNacimiento.anio;
        }

        bool hoyEsCumpleanios(Fecha fechaActual)
        {
            return fechaActual.dia == fechaNacimiento.dia
                && fechaActual.mes == fechaNacimiento.mes;
        }

        bool cumpleEsteMes(Fecha fechaActual)
        {
            return fechaActual.mes == fechaNacimiento.mes;

        }
};

#endif /* Banco_H */