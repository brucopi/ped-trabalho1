
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
	//strcpy(novo->cor,cores); //erro aqui	
	novo->cor=strdup(cores);
	novo->quantidadeNo= 0;
	novo->proximaCor = NULL;
	novo->noInicial = NULL;	
	//se a lista estiver vazia
	if(lista->corInicial == NULL)
	{
		lista->corInicial = novo;
		return;
	}
	//######################################################
	//insere no inicio (funcionando)
	//novo->proximaCor = lista->corInicial;
	//lista->corInicial = novo;
	//######################################################
	//strcmp(maior,menor) == 1
	//strcmp(menor,maior) == -1 
	//strcmp(grande,grande) == 0     
	//insere ordenado
	Cor *cores2,*ant;
	cores2=lista->corInicial;
	int x,y;
	x= strcmp(novo->cor, cores2->cor);
	//insere no inicio
	if(x == 0 || x == -1)
	{
		novo->proximaCor = lista->corInicial;
		lista->corInicial = novo;
		return;
	}
	//insere no meio (erro de quando insere duas letras iguais)
	for(y=0;y<lista->quantidadeCor;y++)
	{
		if(cores2->proximaCor == NULL)
		{
			cores2->proximaCor = novo;
			return;
		}
		ant=cores2;
		cores2=cores2->proximaCor;
		x= strcmp(novo->cor, cores2->cor);
		if(x == 0 || x == -1)
		{
			novo->proximaCor = ant->proximaCor;
			ant->proximaCor = novo;
			return;
		}
	}
	
	
	
}

void mostracor(Lista *lista)
{
	Cor *cores;
	cores=lista->corInicial;
	int  x=0;//teste
	/*if(lista->corInicial == NULL)
		return;
	
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
	
	}
	//printf("Cor= %s\n",cores->cor);
	//printf("Quantidade de nó= %d\n",cores->quantidadeNo);
}

void mostrarpessoa(Cor *cores)
{
	printf("Nome= %s\n",aluno->nomeAluno);
	printf("Tamanho da camiseta= %i",aluno->tamanhoCamiseta);
}
void inserepessoa(Lista *lista,char *nome,  int tam, char *cor )
{
	Pessoa *novo;
	novo = malloc(sizeof(Pessoa));
	novo->nomeAluno=strdup(nome);
	novo->tamanhoCamiseta=tam;
	novo->proximoNo = NULL;
	Cor *cores;
	cores=lista->corInicial;
	int x,y;
	for(y=0;y<lista->quantidadeCor;y++)
	{
		x= strcmp(cor, cores->cor);
		//strcmp(grande,grande) == 0  
		if(x == 0)
		{//insere no inicio (funcionando)
			novo->proximoNo = cores->noInicial;
			cores->noInicial = novo;
			cores->quantidadeNo  =cores->quantidadeNo +1;
			return;
		}
		cores=cores->proximaCor;
	}
}				  
				  
				  
int main(){


	int numCores, quantCamisetas;
	char cor[20];
	char nome[100];
	int tam;
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
			scanf("%s%d", cor2,tam);
			//printf("Nome=%s\tCor=%s\ttam=%s\n",nome,cor2,tam);//Opcional
			inserepessoa(&l,nome, tam, cor2 );
			quantCamisetas--;
		}
		
		//mostrar a saida da lista
		//saida tem que ser ordenada
		//free na lista
		mostracor(&l);//mostra as cores
		//mostraquantcor(&l);//só  teste tem que tirar
		printf("\n");
		printf("Digite o número de cores\n");//opcional
		scanf("%d", &numCores);
	}
  
return 0;
}