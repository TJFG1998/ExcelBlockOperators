/*
Trabalho Realizado por:
-Ricardo Costa 13240
-Tiago Gonçalves 13250
-Joao Pedro Magalhaes 14155
ESI Laboral 2017-2018
Trabalho Pratico de Processamento de Linguagens - Enunciado 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "Excel.h"

double Mult(double a, double b){
    return (double)a*b;
}

double Sub (double a, double b){
    return (double)a-b;
}

double Div(double a, double b){
    if(b!=0){
        return (double)a/b;
    }
    return 0;
}

double Soma(double a, double b){
    return (double)a+b;
}


int Define_valor_coluna(char * var){

    if(var[0] == 'A'){return 0;}
    else if(var[0] == 'B'){return 1;}
    else if(var[0] == 'C'){return 2;}
    else if(var[0] == 'D'){return 3;}
    else if(var[0] == 'E'){return 4;}
    else if(var[0] == 'F'){return 5;}
    else if(var[0] == 'G'){return 6;}
    else if(var[0] == 'H'){return 7;}
    else if(var[0] == 'I'){return 8;}
    else if(var[0] == 'J'){return 9;}
    else if(var[0] == 'K'){return 10;}
    else if(var[0] == 'L'){return 11;}
    else if(var[0] == 'M'){return 12;}
    else if(var[0] == 'N'){return 13;}
    else if(var[0] == 'O'){return 14;}
    else if(var[0] == 'P'){return 15;}
    else if(var[0] == 'Q'){return 16;}
    else if(var[0] == 'R'){return 17;}
    else if(var[0] == 'S'){return 18;}
    else if(var[0] == 'T'){return 19;}
    else if(var[0] == 'U'){return 20;}
    else if(var[0] == 'V'){return 21;}
    else if(var[0] == 'W'){return 22;}
    else if(var[0] == 'X'){return 23;}
    else if(var[0] == 'Y'){return 24;}
    else if(var[0] == 'Z'){return 25;}

    else{
        return -1;
    } 
}

double Procurar_valor(char * var, double matriz[1000][26]){
    int tamanho;
    int valor_coluna;
    //matriz[1000][26];
        
    tamanho = strlen(var);
    
    valor_coluna = Define_valor_coluna(var);
    
    memmove(&var[0],&var[1],tamanho);//Retira o caracter
    
    int valor_linha = atoi(var);//transforma string para doubleeiro
    
    return (double)matriz[valor_linha][valor_coluna];
}


void Define_valor_da_variavel(char *var,double valor, double matriz[1000][26]){
    int length;
    int valor_coluna;
    
    length = strlen(var);

    valor_coluna = Define_valor_coluna(var);

    memmove(&var[0],&var[1],length);//Retira o caracter

    int valor_linha = atoi(var);//transforma string para doubleeiro

    matriz[valor_linha][valor_coluna] = (double)valor;
}

void Inicializa_matrix(double matriz[1000][26]){
    int i, j;

        // atribuir um valor inicial a cada celula
        for(i=0;i<1000;i++){
            for(j=0;j<26;j++){
               matriz[i][j]= 0.00;
            }
        }    
}

double Random(){
    int x = rand() % 101;

    double y = (double)x/100;
}

double Sum(char* var1, char* var2,double matriz[1000][26]){
    double valor_var1 = Procurar_valor(var1,matriz);
    double valor_var2 = Procurar_valor(var2,matriz);

    return (double)valor_var1 + valor_var2;
}

double Raiz (char * var,double matriz[1000][26]){
    double valor = Procurar_valor(var,matriz);

    double raiz = (double)sqrt(valor);

    return raiz;
}


double Abs ( char* var1, char *var2, double matriz[1000][26]){
    double valor_var1 = Procurar_valor(var1,matriz);
    double valor_var2 = Procurar_valor(var2,matriz);

    double sub = (double)valor_var1 - valor_var2;

    if(sub>=0){
        return sub;
    }
    else{
        return -sub;
    }
}


double Avg(char * var1, char* var2,double matriz[1000][26]){

    double valor_var1 = Procurar_valor(var1,matriz);
    double valor_var2 = Procurar_valor(var2,matriz);
    
    double soma = (double)valor_var1 + valor_var2;

    double media = (double)soma/2;

    return media;
}

/*void Show(char* var, double matriz[1000][26]){
    char * var1 = var;
    double valor = Procurar_valor(var1,matriz);

    prdoublef("%s = %d\n ",var,valor);
}



void CriaFicheiroHtml(char* ficheiro,double matriz[1000][26]){
    intj,i;
    char string[2000] = "<html><head><meta charset='UTF-8'><title>Matriz</title></head><body><table>";
    
    int f = open("folha.html", O_CREAT);
    close(f);
    f = open("folha.html", O_RDWR);

    char conteudo[1000];

    snprintf(conteudo,1000,%f,numero);
    
    for(i=0;i<1000;i++){
        for(i=0;i<26;i++){
            
        }
    }
    
    // Meter o conteudo que queres na variavel que vais usar para escrever no ficheiro
    strcat(string, conteudo);
    
    // Fechar as tags que estavam abertas
    strcat(string, "</table></body></html>");
    int t = strlen(string);
    
    write(f, string, t);
    
    close(f);
    
    return 0;
}*/
