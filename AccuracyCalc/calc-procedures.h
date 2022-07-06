#ifndef _CALC_PROCEDURES_GUARD_
#define _CALC_PROCEDURES_GUARD_

#define _USE_MATH_DEFINES

#include <iostream>
#include <functional>
using std::cout;
using std::cin;

void SinSeriesSum();
void SumOfSeriesB();
void Dichotomy();
void NumericalIntegration();
void LambdaIntegration();

using Func = double(*)(double);

double Dichotom(Func f, double a, double b, double eps = 1e-8);
double DichotomRecursive(Func f, double a, double b, double eps = 1e-8);

double LeftRect(double a, double b, Func f, double eps = 1e-6);
double LeftRectIntegration(double a, double b, std::function<double(double)> f, double eps = 1e-6);

#endif