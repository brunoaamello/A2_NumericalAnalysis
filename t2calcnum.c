/* Assignment 2 - Numerical Analysis
 * 2nd semester of 2018
 * by: Bruno Arantes
 */
/* Trabalho 2 - Calculo Numerico
 * 2o semestre de 2018
 * USP Sao Carlos
 * Bruno Arantes de Achilles Mello - 9866490
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_INT 0x7F
#define SIG_DIGITS 7

typedef struct function {
	double (*f)(double);
	double max2;
	double max4;
} Function;

void printDouble(double number){
	printf("%+.*e ", SIG_DIGITS, number);
}

double myFunc(double x){
	return exp(-0.5*x*x);
}

int main(){
	
	Function func;
	
	func.f = myFunc;
	func.max2 = 1.0;
	func.max4 = 3.0;
	
	
	return 0;
}
