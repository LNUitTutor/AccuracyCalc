#include "calc-procedures.h"

void Dichotomy()
{
	cout << "\n *Обчислення корення рівняння методом дихотомії*\n\n";
	Func par = [](double x) -> double { return (x + 4.)*x - 32.; };
	double x1 = Dichotom(par, -8.4, -7.7, 1e-4);
	double x2 = Dichotom(par, 3.7, 4.2, 1e-4);
	double x3 = Dichotom([](double x){ return exp(2.*x) - 3.; }, 0.5, 1.);
	cout << " Ітеративно:\nкорені параболи   x1 = " << x1 << "   x2 = " << x2 << '\n'
		<< "корінь експоненти   x = " << x3 << '\n';
	x1 = DichotomRecursive(par, -8.4, -7.7, 1e-4);
	x2 = DichotomRecursive(par, 3.7, 4.2, 1e-4);
	x3 = DichotomRecursive([](double x){ return exp(2.*x) - 3.; }, 0.5, 1.);
	cout << "\n Рекурсивно:\nкорені параболи   x1 = " << x1 << "   x2 = " << x2 << '\n'
		<< "корінь експоненти   x = " << x3 << '\n';
	return;
}