//include "camisas.h"
//
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef enum tamanho {
P = 0,
M = 1,
G = 2
}TAMANHO;

typedef struct no {
char *nomeAluno;
TAMANHO tamanhoCamiseta; //P, M ou G
struct no *proximoNo;
} NO_PESSOA;


typedef struct cor {
char *cor;
struct cor *proximaCor;
NO_PESSOA *noInicial;
int quantidadeNo;
} NO_COR;

typedef struct listaCor {
NO_COR *corInicial;
int quantidadeCor;
} LISTA_COR;
	
void inserircor(LISTA_COR *lista,char cor)
{
	NO_COR *novo;
	//novo->cor = cor;
	novo = malloc(sizeof(NO_COR));
	//strcpy (novo->cor,cor);
	novo->quantidadeNo= 0;
	novo->proximaCor = NULL;
	novo->noInicial = NULL;
	
}
/*
void inicio(LISTA_COR *lista)
{
	printf("oi");
}
					  
	
void inserir(char cor, char nome, int tam)
{
	printf("oi");
}*/