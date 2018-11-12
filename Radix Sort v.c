#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo
#define Lista struct lista

Nodo{//-------------------------------------------------------------------------Definición de las partes del dato Nodo
	int dato;
	Nodo *siguiente;
};

Lista{//------------------------------------------------------------------------Definición de las partes del dato Lista
	Nodo *inicio;
	Nodo *final;
}lista[10];

Nodo *desencolar(Lista *lista);//-----------------------------------------------Prototipos
void Insertar(Lista *lista,int dato);
int Maximo(int *array,int N);
Lista crearLista();
void Imprimir(Lista lista);
void Radix(int *array,int N);

int main(int argc, char *argv[]) {//--------------------------------------------Función Main
	int i,N,*array;
	printf("¿Cuántos elementos va a ingresar en el array?\n");
	scanf("%i",&N);
	array=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		printf("\nIngrese dato:\n");
		scanf("%i",&array[i]);
	}
	Radix(array,N);
	return 0;
}

Nodo *desencolar(Lista *lista){//-----------------------------------------------Función para desencolar los elementos de las listas
	Nodo *aux;
	if(lista->inicio==NULL && lista->final==NULL){
		return NULL;
	}
	else{
		aux=lista->inicio;
		lista->inicio=lista->inicio->siguiente;
		aux->siguiente=NULL;
		if(lista->inicio==NULL){
			lista->final=NULL;
		}
	}
	return aux;
}

void Insertar(Lista *lista,int dato){//-----------------------------------------Función para insertar datos en las listas
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(lista->inicio==NULL){
		lista->inicio=nuevo;
		lista->final=nuevo;
	}
	else{
		lista->final->siguiente=nuevo;
		lista->final=nuevo;
	}
}

int Maximo(int *array,int N){//-------------------------------------------------Función para determinar el número máximo de un arreglo
	int Max=array[0],i;
	for(i=0;i<N;i++){
		if(array[i]>Max){
			Max=array[i];
		}
	}
	return Max;
}

Lista crearLista(){//-----------------------------------------------------------Función para crear una lista
	Lista lista;
	lista.inicio=NULL;
	lista.final=NULL;
	return lista;
}

void Imprimir(Lista lista){//---------------------------------------------------Función para imprimir los elementos de las listas
	Nodo *aux=lista.inicio;
	while(aux!=NULL){
		printf("%i ",aux->dato);
		aux=aux->siguiente;
	}
}

void Radix(int *array,int N){//-------------------------------------------------Función del método RADIX
	int maximo=Maximo(array,N);
	int indice=1,i;
	Nodo *n;
	for(i=0;i<10;i++){
		lista[i]=crearLista();
	}
	while(maximo/indice>0){
		printf("\n-------------------------------\n");
		printf("%i\n",indice);
		for(i=0;i<N;i++){
			Insertar(&lista[(array[i]/indice)%10],array[i]);
		}
		for(i=0;i<10;i++){
			printf("%i: ",i);
			Imprimir(lista[i]);
			printf("\n");
		}
		int x=0;
		for(i=0;i<10;i++){
			do{
				n=desencolar(&lista[i]);
				if(n!=NULL){
					array[x]=n->dato;
					x++;
					free(n);
				}
			} while(n!=NULL);
		}
		printf("Lista ordenada: ");
		for(i=0;i<N;i++){
			printf("%i ",array[i]);
		}
		printf("\n");
		indice*=10;
	}
}
