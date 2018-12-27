#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void insertList(Nodo *&lista, int n);
void showList(Nodo *lista);
void searchList(Nodo *lista, int n);
void deleteElementList(Nodo *&lista, int n);
void deleteAllList(Nodo *&lista);
void reverseList(Nodo *&lista);
void printReverse(Nodo *lista);

#endif