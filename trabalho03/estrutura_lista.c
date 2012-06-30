#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estrutura_lista.h"

#define NUM_INT 0 
#define NUM_REAL 1 
#define CONST_INT 2 
#define CONST_REAL 3 
#define PROCEDURE 4 
#define PROGRAM 5
#define VAR_INT 6 
#define VAR_REAL 7 
#define PARAM_INT 8
#define PARAM_REAL 9

/*
 * 0 - NUM_INT
 * 1 - NUM_REAL
 * 2 - CONST_INT
 * 3 - CONST_REAL
 * 4 - PROCEDURE
 * 5 - PROGRAM
 * 6 - VAR_INT
 * 7 - VAR_REAL
 */

int getEndRelativo(){
	int ret=prox_end_relativo;
	prox_end_relativo++;
	return ret;
}

void alocaTabelaSimbolos()
{
  tabela = (simbolo *) malloc(MAXLENGTH * sizeof(simbolo)); 
}

void realocaTabelaSimbolos(int novo_tamanho)
{
    realoca(&tabela, novo_tamanho);
}

void realoca (simbolo **p, int novo_tamanho)
{
        simbolo *realocado;
        realocado = realloc ((*p), novo_tamanho * sizeof(simbolo));
        (*p) = realocado;
        
}

void insere (simbolo p)
{
     int i=0,j;
     while(i<numero_simbolos && strcmp(tabela[i].nome,p.nome)<0)
        ++i;
     
     for(j=numero_simbolos;j>i;--j)
          tabela[j]= tabela[j-1];
     
     tabela[i]=p;
}

void insereNumInt (char *nome, int valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 0;
    p.contexto = contexto;
    p.valori=valor;
	p.end_relativo=getEndRelativo();
	p.valorf=-1.0;
    insere(p);
    ++numero_simbolos;
}

void insereNumReal (char *nome, double valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 1;
    p.contexto = contexto;
    p.valorf=valor;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
    insere(p);
    ++numero_simbolos;
}

void insereVarInt (char *nome, int contexto)
{
	simbolo p;
	p.nome=nome;
	p.tipo = VAR_INT;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	insere(p);
	++numero_simbolos;
}

void insereVarReal (char *nome, int contexto)
{
	simbolo p;
	p.nome=nome;
	p.tipo = VAR_REAL;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	insere(p);
	++numero_simbolos;
}

void insereParamInt (char *nome, int contexto)
{
	simbolo p;
	p.nome=nome;
	p.tipo = PARAM_INT;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	insere(p);
	++numero_simbolos;
}

void insereParamReal (char *nome, int contexto)
{
	simbolo p;
	p.nome=nome;
	p.tipo = PARAM_REAL;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	insere(p);
	++numero_simbolos;
}

void insereConstInt (char *nome, int valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 2;
    p.contexto = contexto;
    p.valori=valor;
	p.end_relativo=getEndRelativo();
	p.valorf=-1.0;
    insere(p);
    ++numero_simbolos;
}

void insereConstReal (char *nome, double valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 3;
    p.contexto = contexto;
    p.valorf=valor;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
    insere(p);
    ++numero_simbolos;
}

void insereProcedure (char *nome, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 4;
    p.contexto = contexto;
    insere(p);
    ++numero_simbolos;
}

void insereProgram (char *nome)
{
	simbolo p;
	p.nome=nome;
	p.tipo = 5;
	p.valorf=-1;
	p.valori=-1;
	p.contexto = 0;
	p.end_relativo=-1;
	insere(p);
	++numero_simbolos;
}



int deleta (simbolo *tabela, simbolo p, int tamanho)
{
     int i=0,j;
     while(i<tamanho && strcmp(tabela[i].nome,p.nome)!= 0)
        ++i;
     /*saiu porque encontrou*/
     if(i<tamanho)
     {
      for(j=i;j<tamanho-1;++j)
          tabela[j]= tabela[j+1];
      return 1;
     }
     return 0;
}

void printTabela(){
	int i;
	printf("|Nro\tTipo\tNome\t\tValor Int\tValor Float\tEnd Relativo\tContexto\t|\n");
	for(i=0;i<numero_simbolos; i++){
		printf("|%d\t%d\t%s\t\t%8d\t%lf\t%d\t\t%d\t\t|\n",i,tabela[i].tipo,tabela[i].nome, tabela[i].valori, tabela[i].valorf, tabela[i].end_relativo, tabela[i].contexto);
	}
}
/*
int main(int argc, char **argv)
{
    alocaTabelaSimbolos();
    
    insereNumInt("baaaa",12,0);
    insereNumReal("aaaa",12.876,0);
    insereConstInt("vahne",12,0);
    insereConstReal("fabio",1.2,0);
    insereProcedure("isa",0);
    
    printf("%s %lf\n",tabela[0].nome,tabela[0].valorf);
    printf("%s %d\n",tabela[1].nome,tabela[1].valori);  
     printf("%s %lf\n",tabela[2].nome,tabela[2].valorf); 
     printf("%s\n",tabela[3].nome);  
     printf("%s %d\n",tabela[4].nome,tabela[4].valori);
     
    return 0;
}*/
