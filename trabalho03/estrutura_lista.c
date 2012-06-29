#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 200

/*
 *
 *
 */

int prox_end_relativo=0;
typedef struct
{
    char *nome;
    int tipo;
	float valorf;
	int valori;
    unsigned int end_relativo;
	int contexto;
}simbolo;

int getEndRelativo(){
	int ret=prox_end_relativo;
	prox_end_relativo++;
	return ret;
}


void realoca (simbolo **p, int novo_tamanho)
{
        simbolo *realocado;
        realocado = realloc ((*p), novo_tamanho * sizeof(simbolo));
        (*p) = realocado;
        
}

void insere (simbolo *tabela, simbolo p, int tamanho)
{
     int i=0,j;
     while(i<tamanho && strcmp(tabela[i].nome,p.nome)<0)
        ++i;
     
     for(j=tamanho;j>i;--j)
          tabela[j]= tabela[j-1];
     
     tabela[i]=p;
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
    int numero_simbolos=0;
    simbolo *tabela;
    tabela = (simbolo *) malloc(MAXLENGTH * sizeof(simbolo));
    
    simbolo p;
    p.nome="meu";
    p.valor=987;
    insere(tabela, p,numero_simbolos);
    ++numero_simbolos;
    
    simbolo q;
    q.nome="b";
    q.valor=987; 
    insere(tabela, q,numero_simbolos);
    ++numero_simbolos;
    
    simbolo t;
    t.nome="a";
    t.valor=987; 
    insere(tabela, t,numero_simbolos);
    ++numero_simbolos;
    
    printf("Insercao\n");
    printf("%s %lf\n",tabela[0].nome,tabela[0].valor);
    printf("%s %lf\n",tabela[1].nome,tabela[1].valor);  
     printf("%s %lf\n",tabela[2].nome,tabela[2].valor); 
     
     if(deleta(tabela, t,numero_simbolos))
                       --numero_simbolos;
                       
     
     printf("Apos deletar o primeiro elemento\n");
     printf("%s %lf\n",tabela[0].nome,tabela[0].valor);
     printf("%s %lf\n",tabela[1].nome,tabela[1].valor);  
    
    system("pause");
    return 0;
}
