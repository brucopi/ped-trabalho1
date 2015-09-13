
/*
 * Programa para testar o trabalho 1 sobre organização de camisetas
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "camisas.h"


/* Inicializa uma lista */
void inicLista(Lista *lista){
	lista->corInicial = NULL;
	lista->quantidadeCor = 0;	
}

//verificar se é necessario
void inicCor(Cor *cores)
{
	cores->cor=NULL;
	cores->proximaCor=NULL;
	cores->noInicial=NULL;
	cores->quantidadeNo=0;
}

void quantcor(Lista *lista,int quant)
{
	lista->quantidadeCor=quant;
}
void mostraquantcor(Lista *lista)
{
	printf("Quantidade de cor = %d\n",lista->quantidadeCor);
}

void inserircor(Lista *lista, char *cores)
{
	Cor *novo;
	//novo->cor = cor;
	novo = malloc(sizeof(Cor));
	//novo->cor=cores;
	//printf("Erro no strdup\n"); //teste
	//strcpy(novo->cor,cores); //erro aqui	
	novo->cor=strdup(cores);
	//printf("Não tem erro no strdup\n");//teste
	novo->quantidadeNo= 0;
	novo->proximaCor = NULL;
	novo->noInicial = NULL;	
	//se a lista estiver vazia
	if(lista->corInicial == NULL)
		lista->corInicial = novo;
	//insere no inicio
	novo->proximaCor = lista->corInicial;
	lista->corInicial = novo;
	
	
}

void mostracor(Lista *lista)
{
	Cor *cores;
	cores=lista->corInicial;
	int  x=0;//teste
	/*if(lista->corInicial == NULL)
		return;
	
	printf("Entrou\n");
	*/
	//while(cores->proximaCor != NULL)
	for(x=0;x<lista->quantidadeCor;x++)
	{
		printf("Cor= %s\n",cores->cor);
		printf("Quantidade de nó= %d\n",cores->quantidadeNo);
		//printf("%d\n",x);//teste
		//printf("Endereço do proximo nó de cor = %d\n",cores->proximaCor);
		//printf("Endereço do proximo nó de usuario=%d\n",cores->noInicial);
		cores=cores->proximaCor;
		//x=x+1;//teste
	}
	//printf("Cor= %s\n",cores->cor);
	//printf("Quantidade de nó= %d\n",cores->quantidadeNo);
}

int main(){


	int numCores, quantCamisetas;
	char cor[20];
	char nome[100];
	char tam[20];
	char cor2[20];
	Lista l;
	
	
	inicLista(&l);
	
		
	printf("Digite o número de cores\n");//opcional
	scanf("%d", &numCores);
	
	
	while (numCores != 0){
		quantcor(&l,numCores);
		
		printf("Digite as cores\n");
		for(; numCores > 0; numCores--) 
		{
			scanf("%s", cor);
			//printf("%s\n",cor);//opcional
			//envia uma cor por vez
			inserircor(&l,cor);
		}
		
		
	
	
		printf("Digite a quantidade de camisas\n");//Opcional
		scanf("%d",&quantCamisetas);
		while (quantCamisetas != 0){
			printf("Digite o nome\n");//Opcional
			scanf("%s",nome);
			printf("Digite a cor e tamanho\n");//Opcional
			scanf("%s%s", cor2,tam);
			//printf("Nome=%s\tCor=%s\ttam=%s\n",nome,cor2,tam);//Opcional
			quantCamisetas--;
		}
		
		//mostrar a saida da lista
		//saida tem que ser ordenada
		//free na lista
		mostracor(&l);//mostra as cores
		//mostraquantcor(&l);//só  teste tem que tirar
		
		printf("Digite o número de cores\n");//opcional
		scanf("%d", &numCores);
	}
  
return 0;
}