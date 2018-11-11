#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo 
#define Lista struct lista

Nodo{//-------------------------------------------------------------------------Definición del nuevo tipo de dato
	int dato;
	Nodo *siguiente;
};

Lista{//------------------------------------------------------------------------Definición de los apuntadores de las listas
	Nodo *inicio;
	Nodo *final;
};

Lista crearLista(){//-----------------------------------------------------------Función para crear la nueva lista
	Lista lista;
	lista.inicio=NULL;
	lista.final=NULL;
	return lista;
}

void insertar(Lista *lista,int dato){//-----------------------------------------Función para insertar elementos en la lista
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(lista->inicio==NULL){
		lista->inicio=nuevo;
		lista->final=nuevo;
	}
	else{
		nuevo->siguiente=lista->inicio;
		lista->inicio=nuevo;
	}
}

void borrarPila(Lista *lista){//------------------------------------------------Función para recuperar el primer elemento de una Pila
	Nodo *aux=lista->inicio;
	if(aux!=NULL){
		lista->inicio=aux->siguiente;
		free(aux);
	}
}

void borrarCola(Lista *lista){//------------------------------------------------Función para recuperar el primer elemento de la cola
	Nodo *aux=lista->inicio;
	if(aux!=NULL){
		if(aux==lista->final){
			lista->inicio=NULL;
			lista->final=NULL;
		}
		else{
			Nodo *ant=NULL;
			while(aux->siguiente!=NULL){
				ant=aux;
				aux=aux->siguiente;
			}
			ant->siguiente=NULL;
			lista->final=ant;
		}
		free(aux);
	}
}

void imprimir(Lista lista){//---------------------------------------------------Función para imprimir las listas
	Nodo *aux=lista.inicio;
	while(aux!=NULL){
		printf("%i ",aux->dato);
		aux=aux->siguiente;
	}
}

int main(int argc, char *argv[]) {//--------------------------------------------Función principal MAIN
	Lista Cola=crearLista();
	Lista Pila=crearLista();
	int N,i,dato;
	printf("Digite el número de elementos a ingresar en la lista:\n");
	scanf("%i",&N);
	for(i=0;i<N;i++){
		printf("\nIngrese el dato:\n");
		scanf("%i",&dato);
		insertar(&Cola,dato);
		insertar(&Pila,dato);
	}
	printf("---------------\n");
	printf("Pila: ");
	imprimir(Pila);
	printf("\nCola ");
	imprimir(Cola);
	printf("\n---------------\n");
	borrarPila(&Pila);
	borrarCola(&Cola);
	printf("Pila: ");
	imprimir(Pila);
	printf("\nCola ");
	imprimir(Cola);
	printf("\n---------------\n");
	return 0;
}

