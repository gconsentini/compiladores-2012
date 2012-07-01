gcc -c estrutura_lista.c 
bison lalg.y -d -v
gcc -c lalg.tab.c
flex lalg.lex
gcc -c lex.yy.c 
gcc -o Compiler lex.yy.o estrutura_lista.o lalg.tab.o
