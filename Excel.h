#ifndef __EXCEL_H__
#define __EXCEL_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Mult(double a, double b);
double Sub (double a, double b);
double Div(double a, double b);
double Soma(double a, double b);

double Random();
double Avg(char * var1, char* var2,double matriz[1000][26]);
double Sum (char * var1, char* var2, double matriz[1000][26]);
double Raiz (char * var,double matriz[1000][26]);
double Abs ( char* var1, char *var2,double matriz[1000][26]);
void Show(char* var, double matriz[1000][26]);
void CriaFicheiroHtml(char* ficheiro);
int Define_valor_coluna(char * var);
double Procurar_valor(char * var,double matriz[1000][26]);
void Define_valor_da_variavel(char *var,double valor,double matriz[1000][26]);
void Inicializa_matrix(double matriz[1000][26]);




#endif
