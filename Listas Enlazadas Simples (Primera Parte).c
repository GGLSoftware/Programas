#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo{//--------------------------Definición de la estructura del nuevo dato
	int dato;
	Nodo *siguiente;
};
Nodo *inicio=NULL;//------------Apuntador al inicio de la lista

void insertarInicio(int dato){//Función para insertar datos al inicio de la lista
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(inicio==NULL){
		inicio=nuevo;
	}
	else{
		nuevo->siguiente=inicio;
		inicio=nuevo;
	}
}
//----------------------------Función para imprimir la lista
void imprimirLista(){
	Nodo *aux=inicio;
	while(aux!=NULL){
		printf("%i ",aux->dato);
		aux=aux->siguiente;
	}
}

int main(int argc, char *argv[]) {
	int N,i,dato;
	printf("Introduzca la cantidad de elementos a introducir en la lista\n");
	scanf("%i",&N);
	for(i=0;i<N;i++){
		printf("\nIngrese dato:\n");
		scanf("%i",&dato);
		insertarInicio(dato);
	}
	imprimirLista();
	return 0;
}
