#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct nodoCola {
	nodoCola* ant;
	nodoCola* sig;
	int dato;

	nodoCola(int dato) : dato(dato), ant(NULL), sig(NULL) {}
	nodoCola(int dato, nodoCola* ant, nodoCola* sig) : dato(dato), ant(ant), sig(sig) {}
};

struct _representacionCola {

	nodoCola* ppio;
	nodoCola* fin;
	int largo;

	_representacionCola() : largo(0), ppio(NULL), fin(NULL) {}
};

typedef _representacionCola* ColaInt;

ColaInt crearColaInt() {
	return new _representacionCola();
}


void encolar(ColaInt& c, int e) {
	if (c->fin) {
		c->fin->sig = new nodoCola(e);
		c->fin = c->fin->sig;

	} else {
	 c->fin = c->ppio = new nodoCola(e);
	}
	c->largo++;
}

int principio(ColaInt c) {
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	nodoCola* aBorrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete aBorrar;
	c->largo--;
	if (!c->ppio) {
		c->fin = NULL;
	}
	else {
		c->ppio->ant = NULL;
	}
}

bool esVacia(ColaInt c) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(ColaInt c) {
	// NO IMPLEMENTADO
	return 0;
}

ColaInt clon(ColaInt c) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
}

#endif