//#include "camisas.h"
//

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
} LISTA_COR