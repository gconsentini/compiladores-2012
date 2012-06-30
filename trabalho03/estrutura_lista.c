#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estrutura_lista.h"


/*
 * 0 - NUM_INT
 * 1 - NUM_REAL
 * 2 - CONST_INT
 * 3 - CONST_REAL
 * 4 - PROCEDURE
 *
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
    insere(p);
    ++numero_simbolos;
}

void insereNumReal (char *nome, float valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 1;
    p.contexto = contexto;
    p.valorf=valor;
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
    insere(p);
    ++numero_simbolos;
}

void insereConstReal (char *nome, float valor, int contexto)
{
    simbolo p;
    p.nome=nome;
    p.tipo = 3;
    p.contexto = contexto;
    p.valorf=valor;
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
}
