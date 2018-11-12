#include <stdio.h>
#include<stdlib.h>
struct nodo {
	int dato;
	struct nodo *der;
	struct nodo *izq;
};
 
struct nodo *raiz=NULL;

void insertar (int x){
	struct nodo *nuevo;
	nuevo=malloc(sizeof(struct nodo));
	nuevo->dato=x;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	if(raiz==NULL)
	raiz=nuevo;
	else
		{
		struct nodo *anterior, *recorrido;
		anterior=NULL;
		recorrido=raiz;
		while (recorrido!=NULL)
		{
			anterior=recorrido;
			if(x<recorrido->dato)
				recorrido=recorrido->izq;
			else 
				recorrido=recorrido->der;
		}
		if(x<anterior->dato)
			   anterior->izq=nuevo;
		else
			anterior->der=nuevo;
		
	}
}

void in(struct nodo *recorrido)
{
	if(recorrido!=NULL)
	{
		in(recorrido->izq);
		printf("%i ", recorrido->dato);
		in(recorrido->der);
	}
}

void pre(struct nodo *recorrido)
{
	if(recorrido!=NULL)
	{
		printf("%i ", recorrido->dato);
		pre(recorrido->izq);
		pre(recorrido->der);
	}
}
void post(struct nodo *recorrido)
{
	if(recorrido!=NULL)
	{
		post(recorrido->izq);
		post(recorrido->der);
		printf("%i ", recorrido->dato);
	}
}
int main(int argc, char *argv[]) {
	int n,x;
	printf("Ingrese  un número: ");
	scanf("%d ",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		insertar(x);
	}
	printf("Pre orden:\n");
	pre(raiz);
	printf("\n");
	printf("Orden:\n");
	in(raiz);
	printf("\n");
	printf("Post orden:\n");
	post(raiz);
	printf("\n");
	return 0;
}

