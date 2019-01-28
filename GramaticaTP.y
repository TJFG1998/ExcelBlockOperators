/*
Trabalho Realizado por:
-Ricardo Costa 13240
-Tiago Gonçalves 13250
-Joao Pedro Magalhaes 14155
ESI Laboral 2017-2018
Trabalho Pratico de Processamento de Linguagens - Enunciado 3
*/

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "Excel.h"

    int yylex();
    int yyerror(char*);

    double matriz [1000][26];

    void Inicializa_matrix(double [1000][26]);

%}

%union {
    char * string;
    int inteiro;
    double real;
}

%token <string> VAR
%token <real> DOUBLE
%type <real> operacao soma sub div mult arg
%token <real> RANDOM SQRT ABS SUM AVG
%token SHOW OP


%%

prog: expressao restoprog
    ;

restoprog:
         |prog
         ;

expressao:VAR OP operacao';'           {Define_valor_da_variavel($1,$3,matriz);}
         |SHOW VAR ';'                 {printf("%f \n",Procurar_valor($2,matriz));}
         ;
        
operacao:soma                          {$$ = $1;}
        |sub                           {$$ = $1;}
        |mult                          {$$ = $1;}
        |div                           {$$ = $1;}
        |arg                           {$$ = $1;}
        |RANDOM'('')'                  {$$ = Random();}
        |ABS'('VAR'-'VAR')'            {$$ = Abs($3,$5,matriz);}
        |SQRT'('VAR')'                 {$$ = Raiz($3,matriz);}
        |SUM'('VAR':'VAR')'            {$$ = Sum($3,$5,matriz);}
        |AVG'('VAR':'VAR')'            {$$ = Avg($3,$5,matriz);}
        ;

soma:arg '+' operacao                  {$$ = Soma($1,$3);}
    ;

sub:arg '-' operacao                   {$$ = Sub($1,$3);}
   ;

mult:arg '*' operacao                  {$$ = Mult($1,$3);}
    ;

div:arg '/' operacao                   {$$ = Div($1,$3);}
   ;

arg:DOUBLE                             {$$ = $1;}                               
   |VAR                                {$$ = Procurar_valor($1,matriz);}
   ;



%%

