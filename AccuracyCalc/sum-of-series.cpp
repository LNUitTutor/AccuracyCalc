#include "calc-procedures.h"

void SumOfSeriesB()
{
	cout << "\n *Обчислення суми ряду S( (-1)^k x^4k+3 / (2k+1)!(4k+3) )*\n\n"
		<< "Введіть дійсне число x = ";
	double x;
	cin >> x;
	cout << "Задайте точність обчислень eps = ";
	double eps;
	cin >> eps;
	// Приготування до обчислень
	double multiplier = x * x;
	double semiterm = x * multiplier; // перший член ряду без дільника (4k+3)
	double term = semiterm / 3; // член ряду
	double sum = term;          // сума ряду
	multiplier = -multiplier * multiplier;   // часто вживаний множник
	int k = 0;                  // номер врахованого доданка
	// Обчислення суми ряду
	while (abs(term) > eps)
	{
		// черговий член ряду обчислюємо за рекурентною формулою
		++k;
		semiterm *= multiplier / (2 * k * (2 * k + 1));
		term = semiterm / (4 * k + 3);
		sum += term;          // враховуємо його в сумі ряду
	}
	cout << "S(" << x << ") = " << sum << '\n';
	return;
}
