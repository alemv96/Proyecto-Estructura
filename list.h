#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
	int valor;
	struct lista *sig;
}lista;


int vacio(lista *p){
	return (p==NULL);
}
