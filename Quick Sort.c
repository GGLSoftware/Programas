#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo{
	int dato;
	int orden;
	Nodo *siguiente;
	Nodo *anterior;
};

Nodo *inicio=NULL;
Nodo *final=NULL;
Nodo *inicio2=NULL;
Nodo *final2=NULL;

Nodo *nuevoNodo(int dato){
	Nodo *nuevo=NULL;
	nuevo=(Nodo *)malloc(sizeof(Nodo));
	nuevo->dato=dato;
	nuevo->orden=0;
	nuevo->siguiente=NULL;
	nuevo->anterior=NULL;
	return nuevo;
}

void insertar(int dato){
	Nodo *nuevo=NULL;
	nuevo= nuevoNodo(dato);
	if(inicio == NULL){
		inicio=nuevo;
		final=nuevo;
	}
	else{
		final->siguiente=nuevo;
		nuevo->anterior=final;
		final=nuevo;
	}
}

void imprimir(){
	Nodo *aux=inicio;
	while(aux!=NULL){
		printf(" %d",aux->dato);
		aux=aux->siguiente;
	}
}

void quickSort(Nodo* aux,Nodo* aux2){
	int temp,b=0;
	while(aux!=aux2){
		while(b==0){
			if(aux!=aux2){
			if(aux->dato>=aux2->dato){
			temp=aux->dato;
			aux->dato=aux2->dato;
			aux2->dato=temp;
			Nodo* piv=aux;
			aux=aux2;
			aux2=piv;
			b=1;
	    	}else{
	    	   aux2=aux2->anterior;
	        }
			}else{
			   b=1;
			}
		}
		b=0;
		while(b==0){
			if(aux!=aux2){
			if(aux->dato<aux2->dato){
				temp=aux->dato;
				aux->dato=aux2->dato;
				aux2->dato=temp;
				Nodo* piv=aux;
				aux=aux2;
				aux2=piv;
				b=1;
			}else{
			    aux2=aux2->siguiente;
			}
			}else{
				b=1;
			}
		}
		b=0;
		}
	aux->orden=1;
	Nodo* ant=aux->anterior;
	Nodo* in2=aux;
	Nodo* sig=aux->siguiente;
	Nodo* fin2=aux;
	while((in2->anterior!=NULL)&&(in2->anterior->orden!=1)){
		in2=in2->anterior;
	}
	while((fin2->siguiente!=NULL)&&(fin2->siguiente->orden!=1)){
		fin2=fin2->siguiente;
	}
	if((in2!=ant)&&(ant!=NULL)&&(ant->orden==0)){
		quickSort(in2,ant);
	}
	if((fin2!=aux->siguiente)&&(aux->siguiente!=NULL)&&(sig->orden==0)){
		quickSort(aux->siguiente,fin2);
	}
}

int main(int argc, char *argv[]) {
	int N,i,dato;
	printf("No. de elementos:");
	scanf("%i",&N);
	for(i=0; i<N; i++){
		scanf("%i",&dato);
		insertar(dato);	
	}
	printf("Lista\n");
	imprimir();
	quickSort(inicio,final);
	printf("\nOrdenada\n");
	imprimir();
	return 0;
}
