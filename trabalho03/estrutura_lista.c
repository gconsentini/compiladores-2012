#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estrutura_lista.h"


int getEndRelativo()
{
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

int insere (simbolo p)
{
     int i=0,j;
     while(i<numero_simbolos && strcmp(tabela[i].nome,p.nome)<0)
        ++i;
	 
	 /*caso exista alguma entrada na tabela de simbolos com o mesmo nome, deve-se verificar se eh permitido*/
	 if(i<numero_simbolos && strcmp(tabela[i].nome,p.nome)==0)
	 {
		 /*se as variaveis tem o mesmo tipo e pertencem ao mesmo escopo. ERRO: redeclaracao de variavel*/
		 while(i<numero_simbolos && strcmp(tabela[i].nome,p.nome)==0){
			if(tabela[i].tipo == p.tipo && tabela[i].contexto == p.contexto && p.tipo!=PARAM_INT && p.tipo!=PARAM_REAL)
				return REDECLARACAO;
			else if(tabela[i].tipo == p.tipo && tabela[i].contexto == p.contexto && (p.tipo==PARAM_INT || p.tipo!=PARAM_REAL) && strcmp(tabela[i].procedure,p.procedure)==0)
				return REDECLARACAO_PARAM;
			 
			 if(tabela[i].tipo != p.tipo && tabela[i].contexto == p.contexto && (tabela[i].tipo == PARAM_REAL || tabela[i].tipo ==PARAM_INT))
				 return REDECLARACAO_PARAM;
			
			/*se as variaveis nao tem o mesmo tipo, isso so eh permitido se alguma delas for PROGRAM ou PROCEDURE. ERRO: tipos conflitantes*/
			if(tabela[i].tipo != p.tipo && tabela[i].tipo != PROGRAM && tabela[i].tipo !=PROCEDURE && p.tipo != PROGRAM && p.tipo !=PROCEDURE && tabela[i].contexto == p.contexto)
				return CONFLITO;
			
			i++;
		 }
	 }
	 
     for(j=numero_simbolos;j>i;--j)
          tabela[j]= tabela[j-1];
     
     tabela[i]=p;
	 return OK;
}
int busca (char *nome,int tipo,int contexto)
{
	int i=0;

	while(i<numero_simbolos && strcmp(tabela[i].nome,nome)<0)
		++i;
	
	if(i<numero_simbolos && strcmp(tabela[i].nome,nome)==0)
	{
		while(i<numero_simbolos && strcmp(tabela[i].nome,nome)==0){
			if(tabela[i].contexto==contexto){
				if((tabela[i].tipo==VAR_INT || tabela[i].tipo==PARAM_INT)  && tipo==EXPRESSAO) return INTEGER;
				if((tabela[i].tipo==VAR_REAL || tabela[i].tipo==PARAM_REAL) && tipo==EXPRESSAO) return REAL;
				if((tabela[i].tipo==VAR_INT || tabela[i].tipo==PARAM_INT)  && tipo==ATTR) return INTEGER;
				if((tabela[i].tipo==VAR_REAL || tabela[i].tipo==PARAM_REAL) && tipo==ATTR) return REAL;
			}
			if(tabela[i].tipo==PROCEDURE && tipo==PROCEDURE) return tabela[i].ordem;
			if(tabela[i].tipo==CONST_INT  && tipo==EXPRESSAO) return INTEGER;
			if(tabela[i].tipo==CONST_REAL  && tipo==EXPRESSAO) return REAL;
			
			if(tipo==ATTR && (tabela[i].tipo==CONST_INT || tabela[i].tipo==CONST_REAL)){
				return CONST_FALSE;
			}
			i++;
		}
	}
	
	return NAO_EXISTE;
}

int buscaTipoParam(char *procedure,int ordem)
{
	int i=0;
	while(i<numero_simbolos){
		if(strcmp(tabela[i].procedure,procedure)==0 && tabela[i].ordem==ordem){
			if(tabela[i].tipo==PARAM_INT) return INTEGER;
			if(tabela[i].tipo==PARAM_REAL) return REAL;
		}
		i++;
	}
		
	return NAO_EXISTE;
}

int removeLocalVars()
{
	int i=0;
	while(i<numero_simbolos){
		if(tabela[i].contexto==1){
			if(tabela[i].tipo!=PARAM_INT && tabela[i].tipo!=PARAM_REAL && tabela[i].tipo!=PROCEDURE){
				removeTabela(tabela[i]);
				fflush(stdout);
				i--;
			}
		}
				i++;
	}
			
				return NAO_EXISTE;
}

int insereConstInt (char *nome, int valor, int contexto)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = CONST_INT;
	p.contexto = contexto;
	p.valori=valor;
	p.end_relativo=getEndRelativo();
	p.valorf=-1.0;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
 	return retorno;
}

int insereConstReal (char *nome, double valor, int contexto)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = CONST_REAL;
	p.contexto = contexto;
	p.valorf=valor;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
	return retorno;
}

int insereProcedure (char *nome, int contexto)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = PROCEDURE;
	p.valorf=-1;
	p.valori=-1;
	p.contexto = contexto;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	p.ordem=0;
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
	return retorno;
}

int insereProgram (char *nome)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = PROGRAM;
	p.valorf=-1;
	p.valori=-1;
	p.contexto = 0;
	p.end_relativo=-1;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
	return retorno;
}


int insereVarInt (char *nome, int contexto)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = VAR_INT;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
	return retorno;
}

int insereVarReal (char *nome, int contexto)
{
	int retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = VAR_REAL;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.valori=-1;
	p.valorf=-1.0;
	p.procedure=malloc(1*sizeof(char));
	p.procedure[0]='\0';
	retorno = insere(p);
	if(retorno ==OK)
		++numero_simbolos;
	return retorno;
}

int insereParamInt (char *nome, int contexto, char *proc, int ordem)
{
	int i=0,retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = PARAM_INT;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.ordem=ordem;
	p.procedure=proc;
	p.valori=-1;
	p.valorf=-1.0;
	retorno = insere(p);
	if(retorno ==OK)
	{
		++numero_simbolos;
		
		while(i<numero_simbolos && strcmp(tabela[i].nome,proc)<=0)
		{
			if(strcmp(tabela[i].nome,proc)==0 && tabela[i].tipo == PROCEDURE)
				tabela[i].ordem = tabela[i].ordem +1;
			++i;
		}
	}
	return retorno;
}

int insereParamReal (char *nome, int contexto, char *proc, int ordem)
{
	int i=0,retorno;
	simbolo p;
	p.nome=nome;
	p.tipo = PARAM_REAL;
	p.contexto = contexto;
	p.end_relativo=getEndRelativo();
	p.ordem=ordem;
	p.procedure=proc;
	p.valori=-1;
	p.valorf=-1.0;
	retorno = insere(p);
	if(retorno ==OK)
	{
		++numero_simbolos;
		
		while(i<numero_simbolos && strcmp(tabela[i].nome,proc)<=0)
		{
			if(strcmp(tabela[i].nome,proc)==0 && tabela[i].tipo == PROCEDURE)
				tabela[i].ordem = tabela[i].ordem +1;
			++i;
		}
	}
	return retorno;
}

int removeTabela(simbolo p)
{
     int i=0,j;
     while(i<numero_simbolos && strcmp(tabela[i].nome,p.nome)!= 0)
        ++i;
     /*saiu porque encontrou*/
     if(i<numero_simbolos)
     {
      for(j=i;j<numero_simbolos-1;++j)
          tabela[j]= tabela[j+1];
	  numero_simbolos--;
	  prox_end_relativo--;
	  return 1;
     }
     return 0;
}

void printTabela(){
	int i;
	printf("|Nro\tTipo\tNome\t\tValor Int\tValor Float\tEnd Relativo\tContexto\tProcedure\tOrdem\t|\n");
	for(i=0;i<numero_simbolos; i++){
		printf("|%d\t%d\t%8s\t%8d\t%lf\t%d\t\t%d\t%16s %8d\t|\n",i,tabela[i].tipo,tabela[i].nome, tabela[i].valori, tabela[i].valorf, tabela[i].end_relativo, tabela[i].contexto,tabela[i].procedure, tabela[i].ordem);
	}
}
