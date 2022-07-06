#include "calc-procedures.h"

void SinSeriesSum()
{
	cout << "\n *Обчислення суми ряду Тейлора - розкладу sin(x)*\n\n"
		<< "Введіть дійсне число x = ";
	double x;
	cin >> x;
	const double eps = 1e-6;
	// Приготування до обчислень
	double x2 = -x * x; // часто вживаний множник
	double term = x;    // перший член ряду
	double sum = x;     // сума ряду
	unsigned n = 2;     // черговий множник для факторіала
	while (abs(term) > eps)
	{
		// черговий член ряду обчислюємо за рекурентною формулою
		term *= x2 / ((double)n * (n + 1));
		sum += term;  // враховуємо його в сумі ряду
		n += 2;
	}
	cout << "S = " << sum << "   sin(x) = " << sin(x) << '\n';
	return;
}
