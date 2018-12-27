#include "stdafx.h"
#include <iostream>
#include "linkedList.h"

using namespace std;

//Insert elements on a list
void insertList(Nodo *&lista, int n) {
	//1.Create new node
	Nodo *new_nodo = new Nodo();
	
	//2.Add new data to the node
	new_nodo->dato = n;
	
	//3.Create 2 aux nodes and assign the first one
	Nodo *aux1 = lista;
	Nodo *aux2 = new Nodo();
	
	//4.Insert the element to the list
	//4.1. Void list
	//4.2. Only one node
	//4.3. Two or mode nodes
	//This while gives order to the list
	while ((aux1 != NULL) && (aux1->dato < n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	//If the element is the first one
	if (lista == aux1)
		lista = new_nodo;
	else
		aux2->siguiente = new_nodo;

	new_nodo->siguiente = aux1;

	cout << "Dato ingresao correctamente" << endl;
}

//Show elements of the list
void showList(Nodo *lista) {
	if (lista == NULL) {
		cout << endl << "List empty";
		return;
	}

	//1.Create new node
	Nodo *actual = new Nodo();

	//2.Refer the new node to the list
	actual = lista;

	//3.Check elements
	while (actual != NULL) {
		//Show data
		cout << actual->dato << " -> ";
		//Go to the next
		actual = actual->siguiente;
	}
	cout << endl;
}

//Search element
void searchList(Nodo *lista, int n) {
	int i = 1;
	bool flag = false;
	//1.Create new node
	Nodo *actual = new Nodo();

	//2.Refer the new node to the list
	actual = lista;

	//3.Check list
	//The second condition only works if our list is in ascendantorder
	while ((actual != NULL) && (actual->dato <= n)) {
		//4. Compare if data exists in the actual list
		if (actual->dato == n) {
			
			flag = true;
			break;
		}
		else //Go to the next
		{
			actual = actual->siguiente;
			++i;
		}
	}

	if (flag)
		cout << "Elementop encontrado en la posicion " << i << endl;
	else
		cout << "Elemento no existe" << endl;
}

void deleteElementList(Nodo *&lista, int n) {
	//1.Check if the list is empty
	if (lista != NULL) {
		//2.Create auxiliary pointers
		Nodo *aux_borrar = new Nodo();
		Nodo *anterior = NULL;

		//3.Initialize pointers
		aux_borrar = lista;

		//4.Check the list
		while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}

		//5.Delete the element
		//If the list was totally checked and the element was not found
		if (aux_borrar == NULL) {
			cout << "Elemento no encontrado" << endl;
			return;
		}
		
		//If the element is the first one
		if (anterior == NULL) {
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else {
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void deleteAllList(Nodo *&lista) {
	//1.Create aux node pointing at the first element of the list
	Nodo *aux_borrar = new Nodo();

	while (lista != NULL) {	
		//2.Save data to eliminate in aux
		aux_borrar = lista;

		//3.Go to the next node
		lista = aux_borrar->siguiente;
		//4.Eliminate aux
		delete aux_borrar;
	}
}

/* Function to reverse the linked list */
void reverseList(Nodo *&lista)
{
	// Initialize current, previous and 
	// next pointers 
	Nodo *current = lista;
	Nodo *prev = NULL, *next = NULL;

	//While elements on list exists
	while (current != NULL)
	{
		// Store next 
		next = current->siguiente;

		// Reverse current node's pointer 
		current->siguiente = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	//Save new list
	lista = prev;
}

//Print the list in reverse order
void printReverse(Nodo *lista)
{
	//Check if there are no elements
	if (lista != NULL)
	{
		//Use the recursion to get the last element
		printReverse(lista->siguiente);
		//At the end, print the last one
		//For recursion effect, print the next to the last and so
		cout << lista->dato << " -> ";
	}
}