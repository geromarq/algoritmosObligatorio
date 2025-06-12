#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct nodoColaPI {                 
	int dato;
	int prioridad;
	nodoColaPI* sig;
	nodoColaPI(int d, int p) : dato(d), prioridad(p), sig(nullptr) {}
};

struct _representacionColaPrioridadInt {
	nodoColaPI* ppio;          // primero en salir
	unsigned int largo;    // elementos actuales
	unsigned int cota;     // capacidad máx.

	_representacionColaPrioridadInt(unsigned int k): ppio(nullptr), largo(0), cota(k) {
	}
};


ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	return new _representacionColaPrioridadInt();
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	// NO IMPLEMENTADO
}

int principio(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return 0;
}

int principioPrioridad(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return 0;
}

void desencolar(ColaPrioridadInt& c) {
	// NO IMPLEMENTADO
}

bool esVacia(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return true;
}

bool esLlena(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return false;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return 0;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ColaPrioridadInt& c) {
	// NO IMPLEMENTADO
}

#endif