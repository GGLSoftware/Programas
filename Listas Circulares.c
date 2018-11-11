#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo{//-------------------------------------------------------------------------Creación de un nuevo tipo de dato
	int dato;
	Nodo *siguiente;
};
Nodo *inicio=NULL;

void insertar(int dato){//------------------------------------------------------Función para insertar datos en la lista
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(inicio==NULL){
		inicio=nuevo;
		nuevo->siguiente=inicio;
	}
	else{
		Nodo *aux=inicio;
		while(aux->siguiente!=inicio){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
		nuevo->siguiente=inicio;
	}
}

void imprimir(){//--------------------------------------------------------------Función para imprimir los datos de la lista
	if(inicio!=NULL){
		Nodo *aux=inicio;
		do{
			printf("%i ",aux->dato);
			aux=aux->siguiente;
		} while(aux!=inicio);
	}
}

int main(int argc, char *argv[]) {//--------------------------------------------Función Main
	int n,i,dato;
	scanf("%i",&n);
	for(i=0;i<n;i++){
		scanf("%i",&dato);
		insertar(dato);
	}
	imprimir();
	return 0;
}
