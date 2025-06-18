#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct nodoColaPI {                 
	int dato;
	int prioridad;
	nodoColaPI* sig;
	nodoColaPI(int d, int p) : dato(d), prioridad(p), sig(NULL) {}
};

struct _representacionColaPrioridadInt {
	nodoColaPI* ppio;          // primero en salir
	unsigned int largo;    // elementos actuales
	unsigned int cota;     // capacidad máx.

	_representacionColaPrioridadInt(unsigned int k) : ppio(nullptr), largo(0), cota(k) {};
};


ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	return new _representacionColaPrioridadInt(cota);
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	if (esLlena(c))return;
	nodoColaPI* nodo = new nodoColaPI(e, p);
	

	if (c->ppio == NULL || p > c->ppio->prioridad) {
		nodo->sig = c->ppio;
		c->ppio = nodo;
	} else {
		nodoColaPI* aux = c->ppio;
		while (aux->sig != NULL && aux->sig->prioridad >= p) {
			aux = aux->sig;
		}
		nodo->sig = aux->sig;
		aux->sig = nodo;
		delete aux;
	}
	
	c->largo++;
	
}

int principio(ColaPrioridadInt c) {
	return c->ppio->dato;
}

int principioPrioridad(ColaPrioridadInt c) {
	return c->ppio->prioridad;
}

void desencolar(ColaPrioridadInt& c) {
	nodoColaPI* aBorrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete aBorrar;
}

bool esVacia(ColaPrioridadInt c) {
	return c->ppio == NULL;
}

bool esLlena(ColaPrioridadInt c) {
	return c->largo == c->cota;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->largo;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	if (c == NULL)return NULL;
	ColaPrioridadInt copia = crearColaPrioridadInt(c->cota);
	for (nodoColaPI* it = c->ppio; it; it = it->sig) { 
		encolar(copia, it->dato, it->prioridad);
	}
	return copia;
}

void destruir(ColaPrioridadInt& c) {
	if (c->ppio == NULL)return;
	if (c->ppio->sig != NULL) {
		nodoColaPI* sig = c->ppio->sig;
		delete c->ppio;
		c->ppio = sig;
		destruir(c);
	} else {
		delete c->ppio;
		delete c;
	}
	

}

#endif