

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

typedef NO_PESSOA Pessoa;

typedef struct cor {
char *cor;
struct cor *proximaCor;
NO_PESSOA *noInicial;
int quantidadeNo;
} NO_COR;

typedef NO_COR Cor;

typedef struct listaCor {
NO_COR *corInicial;
int quantidadeCor;
} LISTA_COR;

typedef LISTA_COR Lista;


/* Inicializa uma lista */
void inicLista(Lista *lista);
