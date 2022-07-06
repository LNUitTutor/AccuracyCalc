#include "calc-procedures.h"

double Dichotom(Func f, double a, double b, double eps)
// Ітеративна реалізація методу дихотомії
{
	double fa = f(a);
	while (b - a > eps)
	{
		double c = (a + b) * 0.5; // середина проміжку
		double fc = f(c);
		if (fa * fc < 0) b = c;   // корінь – у лівій половині проміжку
		else                      // корінь – праворуч
		{
			a = c; fa = fc;
		}
	}
	return (a + b) * 0.5;
}

double DichotomRecursive(Func f, double a, double b, double eps)
// Рекурсивна реалізація методу дихотомії
{
	double c = (a + b) * 0.5;
	if (b - a <= eps)     // проміжок достатньо малий
		return c;
	if (f(a)*f(c) < 0)    // шукати корінь на лівій половині
		return DichotomRecursive(f, a, c, eps);
	else                  // шукати корінь на правій половині
		return DichotomRecursive(f, c, b, eps);
}

double LeftRect(double a, double b, Func f, double eps)
// інтеграл від f на проміжку [a; b] методом лівих прямокутників
// I_2n - значення I(2n); I_n - значення I(n); sum - використовується
// для постійного накопичення суми значень f(x_i)
// дозволено не більше 12 подвоєнь сітки інтегрування
{
	int n = 10;
	double h = (b - a) / n;
	double sum = 0.;
	for (int i = 0; i < n; ++i) sum += f(a + i * h);
	double I_2n = sum * h;  // перше значення інтеграла
	double I_n = 0.;        // наступне значення
	int doublings = 0;      // кількість подвоєнь вузлів інтегрування
	while (abs(I_2n - I_n) / 3. > eps && doublings < 13)
	{
		++doublings;
		I_n = I_2n;                  // запам’ятали попереднє I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			sum += f(a2 + i * h);  // доповнили суму
		I_2n = sum * h2;             // отримали нове значення I(2n)
		h = h2; n += n;              // подвоїли кількість доданків
	}
	if (doublings > 12) cout << "leftRec::WARNING: Accuracy loss is possible\n";
	return I_2n;
}

double LeftRectIntegration(double a, double b, std::function<double(double)> f, double eps)
{
	int n = 10;
	double h = (b - a) / n;
	double sum = 0.;
	for (int i = 0; i < n; ++i) sum += f(a + i * h);
	double I_2n = sum * h;  // перше значення інтеграла
	double I_n = 0.;        // наступне значення
	int doublings = 0;      // кількість подвоєнь вузлів інтегрування
	while (abs(I_2n - I_n) / 3. > eps && doublings < 13)
	{
		++doublings;
		I_n = I_2n;                  // запам’ятали попереднє I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			sum += f(a2 + i * h);  // доповнили суму
		I_2n = sum * h2;             // отримали нове значення I(2n)
		h = h2; n += n;              // подвоїли кількість доданків
	}
	if (doublings > 12) cout << "leftRec::WARNING: Accuracy loss is possible\n";
	return I_2n;
}
