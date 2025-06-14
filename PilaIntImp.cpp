#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct nodoPila {
	int dato;          
	nodoPila* sig;     

	nodoPila(int d) : dato(d), sig(nullptr) {}
};

struct _representacionPilaInt {
	nodoPila* top;        
	unsigned int largo;

	_representacionPilaInt() : top(nullptr), largo(0) {}
};

typedef _representacionPilaInt* Pila;

PilaInt crearPilaInt(){
	return new _representacionPilaInt();
}

void push(PilaInt& p, int e) {
	nodoPila* nodo = new nodoPila(e);
	nodo->sig = p->top;
	p->top = nodo;
	p->largo += 1;
}

int top(PilaInt p) {
	return p->top->dato;
}

void pop(PilaInt& p) {
	nodoPila* aBorrar = p->top;
	p->top = p->top->sig;
	delete aBorrar;
	p->largo -= 1;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->largo;
}

bool esVacia(PilaInt p) {
	return p->largo == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt clon = crearPilaInt();
	PilaInt aux = crearPilaInt();


	while (!esVacia(p)) {
		int x = top(p);
		pop(p);
		push(aux, x);
	}


	while (!esVacia(aux)) {
		int x = top(aux);
		pop(aux);

		push(p, x);       
		push(clon, x);   
	}
	destruir(aux);        
	return clon;

}


void destruir(PilaInt& p) {
	while (!esVacia(p)) {
		pop(p);
	}
	delete p;
	p = NULL;
}


#endif