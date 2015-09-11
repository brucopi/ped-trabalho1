 /*
 * Programa para testar o trabalho 1 sobre organização de camisetas
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

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
	
	
  
return 0;
}