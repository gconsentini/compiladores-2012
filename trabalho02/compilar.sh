bison lalg.y 
gcc -c lalg.tab.c
flex lalg.lex
gcc -c lex.yy.c 
gcc -o Compiler lex.yy.o lalg.tab.o 
