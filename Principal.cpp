#include <iostream>
#include <vector>
#include "Banco.cpp"
#include "BancoDataReader.cpp"
#include "Probador.cpp"
using namespace std;
const int NumeroArchivos = 3;

void MostrarDatos(vector<vector<Banco>> banco) {

    
	for (int k = 0; k < NumeroArchivos; k++) {
		cout << "Mostrando los datos cargados del TXT " << k+1 << " ..." << endl;
		for (int i = 0; i < banco[k].size(); i++) {
			cout << banco[k][i].getIdBanco() << endl;
			cout << banco[k][i].nombre << endl;
			cout << banco[k][i].getDireccion() << endl;

			list<Cuenta>::iterator it = banco[k][i].getListaCuentas().begin();

			for (int j = 0; j < banco[k][i].getListaCuentas().size(); j++) {
				cout << it->nroCuenta << " " << it->saldo << " " << it->getTipo() << " " << it->duenio.getCi() << " " << it->duenio.getNombreCompleto();
				cout << " " << it->duenio.getFechaNacimiento().dia;
				cout << " " << it->duenio.getFechaNacimiento().mes;
				cout << " " << it->duenio.getFechaNacimiento().anio << endl;
				it++;
			}
			cout << endl;
		}
	}
}


//A) Realize un metodo que permita generar 12 Pagos de sueldos a TODAS las cuentas de un Banco, 
//considerando que representaran los pagos de cada mes y las mismas se realizan cada primero del mes
void generarDepositos(Banco &b1, float monto)
{
    
}

//B) Realize un metodo que permita visualizar todas las transacciones que se hicieron a lo largo de un periodo de tiempo
void visualizarTransacciones (Banco b1, int mesInicio, int mesFin)
{
    //Debe visualizar, El duennio(Nombre Apellido), el tipo de Transaccion, el Monto, y el Mes
}

//C) Dado un vector de bancos, obtenga el total de capital acumulado de todos los bancos
float obtenerCapitalTotal(vector<Banco> b1)
{
    return 0;
}


//D) Obtenga dentro de un vector la lista de los clientes cumpleanieros de un banco considerando el mes de una fecha
vector<Banco> obtenerListaCumpleanieros(Banco b1, Fecha f1)
{
    //utilize la funcion, cumpleEsteMes()
    vector<Banco>  resp;

    return resp;
}

int main()
{


    // Banco b1;
    // b1.verInfo();
    // cout<<b1.obtenerCapital()<<endl;
    // BancoDataReader* b = BancoDataReader::getInstance();
    Probador verif;

    // MostrarDatos(verif.LeerDatosPrueba());
    vector<Banco> listaBancos = verif.LeerDatosPrueba()[0];

    MostrarDatos(verif.LeerDatosPrueba());
   // cout<< listaBancos[1].nombre<<endl;

    //Pregunta A
    generarDepositos(listaBancos[1], 1000);
    //Pregunta B
    visualizarTransacciones(listaBancos[1], 1,12);
     //Pregunta C
    cout<<"Capital Total"<< obtenerCapitalTotal(listaBancos);
    return 0;


}