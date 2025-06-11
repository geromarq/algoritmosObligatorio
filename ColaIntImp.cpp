#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct nodoCola {
	nodoCola* ant;
	nodoCola* sig;
	int dato;

	nodoCola(int dato) : dato(dato), ant(NULL), sig(NULL) {}
	nodoCola(int dato, nodoCola* ant, nodoCola* sig) : dato(dato), ant(ant), sig(sig) {}
};

struct _representacionColaInt {

	nodoCola* ppio;
	nodoCola* fin;
	int largo;

	_representacionColaInt() : largo(0), ppio(NULL), fin(NULL) {}
};

ColaInt crearColaInt() {
	return new _representacionColaInt();
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
	return c->largo == 0;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->largo;
}

ColaInt clon(ColaInt c) {
	ColaInt copia = crearColaInt();
	for (nodoCola* it = c->ppio; it; it = it->sig) encolar(copia, it->dato);
	return copia;
}

void destruir(ColaInt& c) {
	while (!esVacia(c)) desencolar(c);
	delete c;
	c = nullptr;
}

#endif