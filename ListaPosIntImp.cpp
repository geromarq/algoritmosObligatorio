#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct nodoListaPos {
	int dato;
	nodoListaPos* sig;
	nodoListaPos(int dato) : dato(dato),sig(NULL){};
	nodoListaPos(int dato, nodoListaPos* sig) : dato(dato),sig(sig){};
};

struct _representacionListaPosInt {
	nodoListaPos* ppio;
	int largo;
	_representacionListaPosInt() : ppio(nullptr), largo(0) {}
};

ListaPosInt crearListaPosInt()
{
	return new _representacionListaPosInt();
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (pos >= l->largo) {
		pos = l->largo;
	}
	if (pos == 0 || l->ppio == NULL) {
		l->ppio = new nodoListaPos(e, l->ppio);
		++l->largo;
		return;
	}
	nodoListaPos* aux = l->ppio;
	unsigned int i = 1;
	while (i < pos) {
		aux = aux->sig;
		++i;
	}
	aux->sig = new nodoListaPos(e, aux->sig);
	++l->largo;
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos >= l->largo) return;
	if (pos == 0) {                       
		nodoListaPos* borrar = l->ppio;
		l->ppio = l->ppio->sig;
		delete borrar;
	}
	else {
		nodoListaPos* aux = l->ppio;
		for (unsigned int i = 0; i + 1 < pos;i++) {
			aux = aux->sig;
		}
		nodoListaPos* aborrar = aux->sig;
		aux->sig = aux->sig->sig;
		delete aborrar;
	}
	l->largo -= 1;
}

int elemento(ListaPosInt l, unsigned int pos)
{
	nodoListaPos* aux = l->ppio;
	for (int i = 0;i < pos;i++) {
		aux = aux->sig;
	}
	return aux->dato;
}

bool esVacia(ListaPosInt l)
{
	return l->largo == 0;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->largo;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt clon = crearListaPosInt();
	int pos = 0;
	for (nodoListaPos* nod = l->ppio; nod != NULL;nod = nod->sig) {
		agregar(clon, nod->dato,pos);
		pos++;
	}
	return clon;
}

void destruir(ListaPosInt& l)
{
	while (!esVacia(l)) {
		borrar(l, 0);
	}
}


#endif