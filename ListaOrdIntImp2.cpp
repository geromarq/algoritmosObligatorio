#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2


struct nodoLista {
	int dato;
	int repeticiones;
	nodoLista* sig;

	nodoLista(int dato, int rep) : dato(dato), repeticiones(rep), sig(NULL){}
};

struct _representacionListaOrdInt {
	nodoLista* ppio;         
	nodoLista* fin;          
	unsigned int largo;        

	_representacionListaOrdInt(): ppio(NULL), fin(NULL), largo(0) {}
};


///hacerlo para abb

ListaOrdInt crearListaOrdInt() {
	return new _representacionListaOrdInt();
}

void agregar(ListaOrdInt& l, int e) {
	nodoLista* nodo = new nodoLista(e, 1);
	if (!l) {
		
	}
}

void borrarMinimo(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}

void borrarMaximo(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}

void borrar(ListaOrdInt& l, int e) {
	// NO IMPLEMENTADO
}

int minimo(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

int maximo(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

bool existe(ListaOrdInt l, int e) {
	// NO IMPLEMENTADO
	return false;
}

bool esVacia(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

ListaOrdInt clon(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}



#endif