
%{
    #include <stdio.h>
    #include "GramaticaTP.h"
    #include "Excel.h"
%}


%%

[A-Z]([1-9]|[1-9][0-9]|[1-9][0-9]{2}|[1-9][0-9]{3}) {yylval.string = strdup(yytext);return VAR;}

":"                                                 {return ':';}

":="                                                {return OP;}

"="                                                 {return '=';}

((([1-9][0-9]*)|0).[0-9]*)                          {yylval.real = atof(yytext);return DOUBLE;}

"Random"                                            {return RANDOM;}

"Abs"                                               {return ABS;}

"Sqrt"                                              {return SQRT;}

"Sum"                                               {return SUM;}

"Avg"                                               {return AVG;}

"Show"                                              {return SHOW;}

"+"                                                 {return '+';}

"*"                                                 {return '*';}

"/"                                                 {return '/';}

"("                                                 {return '(';}

")"                                                 {return ')';}

";"                                                 {return ';';}

"-"                                                 {return '-';}

.                                                   {/* ignoramos qualquer outra coisa*/}

[ \t\n]                                             {/* ignoramos espaços*/}

<<EOF>>

%%

//é utilizada pelo flex para quando chegar ao fim do ficheiro que esta a processar
int yywrap(){
    return 1;
}

//é invocada pelo bison quando se depara com um erro
int yyerror(char const *s){
    fprintf(stderr, "Erro: %s \n", s);
    return 0;
}

int main(){
    yyparse();
    return 0;
}
