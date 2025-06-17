#include "Ejercicios.h"

ListaOrdInt Enlistar(NodoABInt* a)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	PilaInt copiaP1 = clon(p1);
	PilaInt copiaP2 = clon(p2);
	int i = cantidadElementos(copiaP1);
	int j = cantidadElementos(copiaP2);
	PilaInt aux = crearPilaInt();
	int comp = 0;

	while (i>=0) {
		int dato1 = top(copiaP1);
		bool encontre = false;
		while (j >= 0) {
			int dato2 = top(copiaP2);
			if (dato1 == dato2) {
				comp++;
				pop(copiaP2);
				encontre = true;
				break;
			} else {
				push(aux, dato2);
				pop(copiaP2);
			}
			j--;
		} 
		if (!encontre) {
			destruir(aux);
			destruir(copiaP1);
			destruir(copiaP2);
			return false;
		}
		while (!esVacia(aux)) {
			push(copiaP2, top(aux));
			pop(aux);
		}
		pop(copiaP1);
		i--;
	}

	destruir(aux);
	destruir(copiaP1);
	destruir(copiaP2);
	return true;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	if()
}

