#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo{//-------------------------------------------------Definición de un nuevo tipo de datos
	int dato;
	Nodo *siguiente;
};
Nodo*inicio=NULL;//------------------------------------Declaración de apuntadores al principio y final de la lista
Nodo*final=NULL;

void insertarFinal(int dato){//-----------------------Función para insertar al final de la lista
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(inicio==NULL){
		inicio=nuevo;
		final=nuevo;
	}
	else{
		final->siguiente=nuevo;
		final=nuevo;
	}
}

void insertarInicio(int dato){//---------------------Función para insertar al inicio de la lista
	Nodo*nuevo=(Nodo*)malloc(sizeof(Nodo));
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

void impLista(){//----------------------------------Función para imprimir lista
	Nodo *aux=inicio;
	while(aux!=NULL){
		printf("%i ",aux->dato);
		aux=aux->siguiente;
	}
}

void borrarDato(int dato){//--------------------------------Función para borrar datos
	Nodo *aux=inicio,*ant=NULL;
	if(inicio!=NULL){
		while(aux!=NULL){
			if(aux->dato==dato){
				if(aux==inicio){
					inicio=inicio->siguiente;
					aux->siguiente=NULL;
					free(aux);
				}
				else{
					if(aux==final){
						final=ant;
						ant->siguiente=NULL;
						free(aux);
					}
					else{
						ant->siguiente=aux->siguiente;
						aux->siguiente=NULL;
						free(aux);
					}
				}
				return;
			}
			ant=aux;
			aux=aux->siguiente;
		}
	}
}

int main(){
	int N,i,dato,jeje;
	scanf("%i",&N);
	for(i=0;i<N;i++){
		scanf("%i",&dato);
		//insertarInicio(dato);
		insertarFinal(dato);
	}
	impLista();
	scanf("%i",&jeje);
	borrarDato(jeje);
	impLista();
	return 0;
}
