#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nodo struct nodo
#define ListDob struct listadoble

struct nodo{//------------------------------------------------------------------Definición de un tipo de dato Nodo
	int  dato;
	Nodo* siguiente;
};

struct listadoble{//------------------------------------------------------------Definición del inicio y el final de las listas
	Nodo *inicio;
	Nodo *final;
};
Nodo *inicio=NULL;
Nodo *final=NULL;

void insertar(ListDob *list,int dato);//----------------------------------------Prototipos de las funciones
Nodo *nuevoElemento(int dato);
void visualizarLista(ListDob nlista);
int eliminarNodo(ListDob*lista);
void insertarI(ListDob *list,int dato);
int comparar(int esperar, int inicio);

int main(){//-------------------------------------------------------------------Función MAIN
	ListDob Lista1,Stack,Final;
	char palabra[100];
	int i,len;
	Lista1.inicio=Lista1.final=NULL;
	Stack.inicio=Stack.final=NULL;
	Final.inicio=Final.final=NULL;
	printf("Operandos Validos: + - * / ^ ( )\n");
	printf("Escribir formula:");
	gets(palabra);
	len=strlen(palabra);
	for(i=0;i<len;i++){
		printf("Caracter: %c\n",palabra[i]);
		insertar(&Lista1,palabra[i]);
	}
	Nodo *espera=Lista1.inicio;
	while(espera!=NULL){
		if((espera->dato>=40 && espera->dato<=47) || espera->dato==94 ){
			if(espera->dato!=41){
				if(Stack.inicio!=NULL){
					while(comparar(espera->dato,Stack.inicio->dato)!=0){
						insertar(&Final,eliminarNodo(&Stack));
						if(Stack.inicio==NULL){
							break;
						}
					}
				}
				insertarI(&Stack,espera->dato);
			}else{
				while(Stack.inicio->dato!=40){
					insertar(&Final,eliminarNodo(&Stack));
				}
				eliminarNodo(&Stack);
			}
		}else{
			insertar(&Final,espera->dato);
		}
		espera=espera->siguiente;
	}
	
	while(Stack.inicio!=NULL){
		insertar(&Final,eliminarNodo(&Stack));
	}
	printf("\n");
	printf("Resultado Final:");
	visualizarLista(Final);
	return 0;
}

void insertar(ListDob *list,int dato){//----------------------------------------Función para insertar elementos en las listas al final
	Nodo* nuevo=nuevoElemento(dato);
	if(list->inicio==NULL && list->final==NULL){
		list->inicio=nuevo;
		list->final=nuevo;
	}else{
		list->final->siguiente=nuevo;
		list->final=nuevo;
	}
}

Nodo *nuevoElemento(int dato){//------------------------------------------------Función para reservar espacio en memoria y crear un nuevo nodo
	Nodo *q=(Nodo*)malloc(sizeof(Nodo));
	q->dato=dato;
	q->siguiente=NULL;
	return q;
}

void visualizarLista(ListDob nlista){//-----------------------------------------Función para visualizar los elementos de una lista
	if(nlista.inicio!=NULL){
		Nodo* aux=nlista.inicio;
		while(aux!=NULL){
			printf("%c ",aux->dato);
			aux=aux->siguiente;
		}
	}
}

int eliminarNodo(ListDob*lista){//----------------------------------------------Función para eliminar nodos
	Nodo* aux=lista->inicio;
	int dato=aux->dato;
	lista->inicio=lista->inicio->siguiente;
	free(aux);
	return dato;
}

void insertarI(ListDob *list,int dato){//---------------------------------------Función para insertar elementos en una lista al inicio 
	Nodo *nuevo=nuevoElemento(dato);
	if(list->inicio==NULL && list->final==NULL){
		list->inicio=nuevo;
		list->final=nuevo;
	}else{
		nuevo->siguiente=list->inicio;
		list->inicio=nuevo;
	}
}

int comparar(int esperar, int inicio){//----------------------------------------Función para comparar los elementos de una lista
	int verificar;
	if((esperar==42 || esperar==43 || esperar==45 || esperar==47) && (inicio==94)){
		verificar=1;
	}else if((esperar==43 || esperar==45)&&(inicio==42 || inicio==47)){
		verificar=1;
	}else{
		verificar=0;
	}
	return verificar;
}
	
	
	
	
