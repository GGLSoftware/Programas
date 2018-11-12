#include <stdio.h>
#include <stdlib.h>

long fibonacci(long n)
{
	if(n<=1)
	{
		return n;
	}
	else
	   {
		return ((fibonacci(n-1))+(fibonacci(n-2))); 
	}
}
int main(int argc, char *argv[]) {
	int nu,i;
	printf("Ingrese un numero: ");
	scanf("%i",&nu);
	for(i=0;i<=nu;i++)
	{
		printf("%ld,",fibonacci(i));
	}
	return 0;
}

