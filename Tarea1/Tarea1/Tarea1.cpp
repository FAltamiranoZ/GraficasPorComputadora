#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::malloc;
using std::free;

typedef struct list_int {
	int n;
	struct list_int *ptr;
} LISTA;

LISTA *init_list, *aux, *e, *aux2;
int Elems = 1, res = 1, res2 = 1, a, cont = 1;

int main() {
	cout << "Dar 5 elementos ordenados a la lista\n";
	e = (LISTA*)malloc(sizeof(LISTA));
	cout << "Elemento " << Elems << "  ";
	cin >> e->n;
	e->ptr = NULL;
	aux = e;
	init_list = e;
	Elems++;
	while (Elems <= 5) {
		e = (LISTA*)malloc(sizeof(LISTA));
		cout << "Elemento " << Elems << "  ";
		cin >> e->n;
		aux->ptr = e;
		e->ptr = NULL;
		aux = e;
		Elems++;
	}
	cout << "Los valores son: \n";
	aux = init_list;
	while (aux != NULL) {
		cout << aux->n << "\n";
		aux = aux->ptr;
	}
	while (res2 == 1) {
		cout << "¿Quieres agregar un elemento? \n";
		cout << "Si -> 1, No -> 0 \n";
		cin >> res;
		if (res == 1) {
			cout << "Inserta el numero que quieres agregar: \n";
			cin >> a;
			aux = init_list;
			cont = 1;
			while (cont < Elems && a > aux->n) {
				aux2 = aux;
				aux = aux->ptr;
				cont++;
			}
			if (cont == 1) {
				e = (LISTA*)malloc(sizeof(LISTA));
				e->n = a;
				e->ptr = aux;
				init_list = e;
				Elems++;
				cout << "Los valores son: \n";
				aux = init_list;
				while (aux != NULL) {
					cout << aux->n << "\n";
					aux = aux->ptr;
				}
			}
			else
			{
				e = (LISTA*)malloc(sizeof(LISTA));
				e->n = a;
				e->ptr = aux;
				aux2->ptr = e;
				Elems++;
				cout << "Los valores son: \n";
				aux = init_list;
				while (aux != NULL) {
					cout << aux->n << "\n";
					aux = aux->ptr;
				}
			}
		}
		else {
			cout << "¿Quieres eliminar un elemento? \n";
			cout << "Si -> 1, No -> 0 \n";
			cin >> res2;
			if (res2 == 1) {
				cout << "Inserta el numero que quieres eliminar: \n";
				cin >> a;
				aux = init_list;
				cont = 2;
				while (cont < Elems && a != aux->n) {
					aux2 = aux;
					aux = aux->ptr;
					cont++;
				}
				if (cont == 2){
					init_list = aux->ptr;
					Elems--;
					cout << "Los valores son 11111: \n";
					aux = init_list;
					while (aux != NULL) {
						cout << aux->n << "\n";
						aux = aux->ptr;
					}
				}
				else if(cont == Elems && a == aux->n) {
					Elems--;
					aux2->ptr = NULL;
					free(aux);
					cout << "Los valores son 22222: \n";
					aux = init_list;
					while (aux != NULL) {
						cout << aux->n << "\n";
						aux = aux->ptr;
					}

				}
				else if(cont == Elems && a != aux->n){
					cout << "Ese numero no se encuentra en la lista \n";
				}
				else{
					aux2->ptr = aux->ptr;
					free(aux);
					Elems--;
					cout << "Los valores son 33333: \n";
					aux = init_list;
					while (aux != NULL) {
						cout << aux->n << "\n";
						aux = aux->ptr;
					}
				}

			}
		}
	}
	cin.get();
	cin.get();
	return 0;
}



