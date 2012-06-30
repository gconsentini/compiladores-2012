#ifndef ESTRUTURA_LISTA_H
#define ESTRUTURA_LISTA_H

#define MAXLENGTH 400

int prox_end_relativo=0;
int numero_simbolos=0;

typedef struct
{
    char *nome;
    int tipo;
    double valorf;
    int valori;
    unsigned int end_relativo;
    int contexto;
}simbolo;

simbolo *tabela;

int getEndRelativo();
void alocaTabelaSimbolos();
void realocaTabelaSimbolos(int novo_tamanho);
void realoca (simbolo **p, int novo_tamanho);
void insere (simbolo p);
void insereVarInt (char *nome, int contexto);
void insereVarReal (char *nome, int contexto);
void insereParamInt (char *nome, int contexto);
void insereParamReal (char *nome, int contexto);
void insereNumInt (char *nome, int valor, int contexto);
void insereNumReal (char *nome, double valor, int contexto);
void insereConstInt (char *nome, int valor, int contexto);
void insereConstReal (char *nome, double valor, int contexto);
void insereProcedure (char *nome, int contexto);
void insereProgram (char *nome);
void printTabela();
int deleta (simbolo *tabela, simbolo p, int tamanho);

#endif // GMP_MONTE_CARLO_PAR_


