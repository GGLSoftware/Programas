#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo {
    int dato;
    Nodo *siguiente;
};

Nodo *mezclar(Nodo*lista1,Nodo*lista2);
Nodo *anadir_nodo_lista(Nodo nodo,Nodo *lista);
void mostrar_lista(Nodo *lista);
int longitud_lista(Nodo *lista);
Nodo *mergeSort(Nodo *lista);
Nodo *obtener_lista2(Nodo *lista);
Nodo *insertar(Nodo*lista,int dato);

int main(){
    Nodo *lista=NULL,*Ordenada=NULL;
    int i,N,dato;
    printf("No. de datos:");
    scanf("%i",&N);
    for (i=0; i<N; i++) {
        scanf("%i",&dato);
        lista=insertar(lista,dato);
    }
    printf("Lista :  ");
    mostrar_lista(lista);
    Ordenada = mergeSort(lista);
    printf("Sale");
    printf("Lista ordenada:  ");
    mostrar_lista(Ordenada);

    return 0;
}

Nodo *mezclar(Nodo *lista1, Nodo *lista2) {
    Nodo *lista_mezclada=NULL;
    Nodo *aux1=NULL, *aux2=NULL;

    aux1=lista1;
    aux2=lista2;
    while (aux1!=NULL && aux2!=NULL) {
        if (aux1->dato < aux2->dato) {
            lista_mezclada = insertar(lista_mezclada,aux1->dato);
            aux1=aux1->siguiente;
        }else{
            lista_mezclada = insertar(lista_mezclada,aux2->dato);
            aux2=aux2->siguiente;
        }
   }
    while (aux1!=NULL) {
        lista_mezclada = insertar(lista_mezclada,aux1->dato);
        aux1=aux1->siguiente;
    }
    while (aux2!=NULL) {
        lista_mezclada = insertar(lista_mezclada,aux2->dato);
        aux2=aux2->siguiente;
    }

    return lista_mezclada;
}

int longitud_lista(Nodo *lista) {
    int longitud=0;
    Nodo *aux=NULL;
    aux = lista;
    while (aux!=NULL) {
        longitud++;
        aux = aux->siguiente;
    }
    return longitud;
}

Nodo *insertar(Nodo *lista,int dato) {
    Nodo *aux=lista,*ant=NULL;
    Nodo*nuevo=(Nodo*)malloc(sizeof(Nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    if(lista==NULL){
    	lista=nuevo;
    }else {
        while(aux!=NULL){
            ant=aux;
            aux=aux->siguiente;
        }
        ant->siguiente=nuevo;
    }
    return lista;
}

void mostrar_lista(Nodo *lista) {
    Nodo *aux=lista;
    while (aux != NULL) {
        printf("%d  ", aux->dato);
        aux = aux->siguiente;
    }
    printf("\n");
}

Nodo *obtener_lista2(Nodo *lista) {
    Nodo *list=NULL,*aux=NULL;
    int longitud=0,mitad=0;
    list=(Nodo*)malloc(sizeof(Nodo));
    longitud=longitud_lista(lista);
    if (longitud%2==0)
        mitad = longitud/2;
    else
        mitad = (longitud/2) + 1;
    aux=lista;
    while (mitad-1 > 0) {
        aux=aux->siguiente;
        mitad--;
    }
    list=aux->siguiente;
    aux->siguiente=NULL;
    return list;
}

Nodo *mergeSort(Nodo *lista) {
    Nodo *lista1=NULL,*lista2=NULL,*lista3=NULL,*lista4=NULL,*Ordenada=NULL;
    if (longitud_lista(lista)<=1){
        return lista;
    }else{
        lista1 = lista;
        lista2 = obtener_lista2(lista);
        lista3 = mergeSort(lista1);
        lista4 = mergeSort(lista2);
        Ordenada = mezclar(lista3, lista4);
        return Ordenada;
    }
}
