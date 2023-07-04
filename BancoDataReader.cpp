#include <iostream>
#include <list>
#include "Banco.cpp"
#include "Cuenta.cpp"
#include "Persona.cpp"
#include "Servicio.cpp"
//C -> aplique el principio de singleton a la clase BancoDataReader
class BancoDataReader {
private:
	//referencia a la unica instancia posible de la clase
	static BancoDataReader* instance;

	//constructor private para evitar que se creen objetos desde otro sitio
	BancoDataReader() {

	}
public:
	//referencia a la unica instancia posible de la clase
	static BancoDataReader* getInstance() {
		if (instance == nullptr) {
			instance = new BancoDataReader;
		}
		return instance;
	}

	static list<Banco> getBancos()
	{
		list<Cuenta> listaDatosCuentas;
		list<Banco> listaDatosBancos;
		return listaDatosBancos;
	}
};

// Inicialización estática de la instancia,
BancoDataReader* BancoDataReader::instance = nullptr;