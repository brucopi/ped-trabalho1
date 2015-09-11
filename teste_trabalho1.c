 /*
 * Programa para testar o trabalho 1 sobre organização de camisetas
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "camisas.c"

int main(){


	int numCores, quantCamisetas;
	char cor[20];
	
	
	
	printf("Digite o número de cores\n");//opcional
	scanf("%d", &numCores);
	while (numCores != 0){
	
		for(; numCores > 0; numCores--) 
		{
			scanf("%s", cor);
			printf("%s\n ",cor);
		}
	}
	
	printf("Tamanho = %d\n",P);
	
  
return 0;
}