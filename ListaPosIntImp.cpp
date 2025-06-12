#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct nodoListaPos {
	int dato;
	int pos;
	nodoListaPos* sig;
	nodoListaPos* ant;
	nodoListaPos(int dato, unsigned int pos) : dato(dato), pos(pos), sig(NULL), ant(NULL) {};
	nodoListaPos(int dato, unsigned int pos, nodoListaPos* ant, nodoListaPos* sig) : dato(dato), pos(pos), sig(sig), ant(ant) {};
};

struct _representacionListaPosInt {
	nodoListaPos* ppio;
	nodoListaPos* fin;
	int cant;
	_representacionListaPosInt() : ppio(NULL), fin(NULL), cant(0) {};
};

ListaPosInt crearListaPosInt()
{
	return new _representacionListaPosInt();
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{	
	nodoListaPos* nodo = new nodoListaPos(e, pos);
	nodoListaPos* aux = l->ppio;

	while (aux != NULL) {

	}
	
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
}

int elemento(ListaPosInt l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	return 0;
}

bool esVacia(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return true;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return 0;
}

ListaPosInt clon(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

void destruir(ListaPosInt& l)
{
	//IMPLEMENTAR SOLUCION
}


#endif