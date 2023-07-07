
#include <list >
#include <limits>
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
enum TipoTransaccion
{
	DEPOSITO, RETIRO, TRANSFERENCIA, PAGO_SERVICIO
};
class Transaccion {
public:
	Fecha fechaTransaccion;
	int nroTransaccion;
	float monto;
	TipoTransaccion tipo;
	Transaccion(int dia, int mes, int anio, int nroT, float _monto, TipoTransaccion _tipo) {
		fechaTransaccion.dia = dia;
		fechaTransaccion.mes = mes;
		fechaTransaccion.anio = anio;
		nroTransaccion = nroT;
		monto = _monto;
		tipo = _tipo;
	}
};
class Cuenta {
private:

	TipoCuenta tipo;
	Banco* entidad;
	list<Transaccion> transacciones;
	int nroT;
public:
	int nroCuenta;
	float saldo;
	Persona duenio;

	Cuenta()
	{
		nroCuenta = 123456;
		saldo = 0;
		tipo = TipoCuenta::CajaAhorro;
	}
	Cuenta(Persona titular)
	{
		nroCuenta = 123456;
		saldo = 0;
		tipo = TipoCuenta::CajaAhorro;
		// entidad = enti;
		duenio = titular;
	}

	Cuenta(Banco* b, Persona titular)
	{
		nroCuenta = 123456;
		saldo = 0;
		tipo = TipoCuenta::CajaAhorro;
		entidad = b;
		duenio = titular;
	}

	Cuenta(int _nro_cuenta, float _saldo,int _tipo, Persona _duenio) {
		nroCuenta = _nro_cuenta;
		saldo = _saldo;
		duenio = _duenio;
		switch (_tipo)
		{
		case 1: tipo = CajaAhorro; break;
		case 2: tipo = PlazoFijo; break;
		case 3: tipo = Empresarial; break;
		}
	}

	void depositar(float monto)
	{
		saldo += monto;

		nroT++;
		transacciones.push_back(Transaccion(2, 2, 2023, nroT, monto, DEPOSITO));

	}

	void depositar(float monto, Fecha f1)
	{
		saldo += monto;

		nroT++;
		transacciones.push_back(Transaccion(f1.dia, f1.mes, f1.anio, nroT, monto, DEPOSITO));

	}

	bool haySaldo()
	{
		return saldo > 0;
	}
	bool sePuedeRetirar(float monto)
	{
		return saldo - monto >= 0;
	}
	void retirar(float monto)
	{
		saldo -= monto;
		nroT++;
		transacciones.push_back(Transaccion(2, 2, 2023, nroT, monto, RETIRO));
	}
	void transferir(float monto, Cuenta destino)
	{
		if (haySaldo() && sePuedeRetirar(monto))
		{
			retirar(monto);
			destino.depositar(monto);

			nroT++;
			transacciones.push_back(Transaccion(2, 2, 2023, nroT, monto, TRANSFERENCIA));
		}
	}

	void pagarServicio(Servicio serv)
	{
		if (haySaldo() && sePuedeRetirar(serv.getCosto()))
		{
			retirar(serv.getCosto());

			nroT++;
			transacciones.push_back(Transaccion(2, 2, 2023, nroT, serv.getCosto(), PAGO_SERVICIO));

		}
	}
	void generarFactura(Servicio serv, Fecha fechaActual)
	{
		cout << "Son en total " << serv.getCosto() << "Bs por el pago del servicio" << serv.getNombre() << endl;
		cout << "Sucre " << fechaActual.dia << "del mes de " << fechaActual.mes << " del anio " << fechaActual.anio << endl;
	}

	void verSaldo()
	{
		cout << "Su saldo actual es " << saldo << endl;
	}
	void verInfo()
	{
		cout << "Nro de Cuenta" << nroCuenta << " correspondiente a" << duenio.getNombreCompleto() << endl;
		cout << "Su saldo actual es " << saldo << endl;
		// cout<<"Entidad Bancaria" << entidad.nombre<<endl;
	}

	list<Transaccion> getTransacciones()
	{
		return transacciones;
	}

	string getTipo() {
		switch (tipo)
		{
		case CajaAhorro: return "Caja de Ahorro";
			break;
		case PlazoFijo: return "Plazo Fijo";
			break;
		case Empresarial: return "Empresarial";
			break;
		}
	}
};
#endif 