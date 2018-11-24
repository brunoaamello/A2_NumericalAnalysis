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
#define SIG_DIGITS 8

typedef struct {
	double first;
	double second;
} pair_double;

typedef struct {
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

unsigned evaluateIntervals_tra(Function func, pair_double interval, double error);
double integrate_tra(Function func, pair_double interval, unsigned subIntervals);

unsigned evaluateIntervals_simp13(Function func, pair_double interval, double error);
double integrate_simp13(Function func, pair_double interval, unsigned subIntervals);

int main(){
	
	Function func;
	
	func.f = myFunc;
	func.max2 = 1.0;
	func.max4 = 3.0;
	
	
	return 0;
}

unsigned evaluateIntervals_tra(Function func, pair_double interval, double error){
	double interval_size = interval.second - interval.first;
	double result = (interval_size)/2;
	result *= sqrt((interval_size*func.max2)/(3*error));
	return (unsigned) ceil(result);
}

double integrate_tra(Function func, pair_double interval, unsigned subIntervals){
	double increment, x, result;
	unsigned i;
	increment = (interval.second-interval.first)/subIntervals;
	x = interval.first + increment;
	result = (func.f(interval.first)+func.f(interval.second))/2;
	for(i=1;i<subIntervals-1;i++, x+=increment){
		result+=func.f(x);
	}
	result*=increment;
	return result;
}

unsigned evaluateIntervals_simp13(Function func, pair_double interval, double error){
	double interval_size;
	double result = interval_size = interval.second - interval.first;
	result *= sqrt(sqrt((interval_size*func.max4)/(5*error))/6);
	return (unsigned) ceil(result);
}

double integrate_simp13(Function func, pair_double interval, unsigned subIntervals);
