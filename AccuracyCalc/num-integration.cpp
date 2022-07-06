#include "calc-procedures.h"

// глобальні змінні
double t;
double X;

// спеціальні підінтегральні функції
double ParameterizedFunction(double x)
{   // для інтеграла, залежного від параметра t
	return pow(x * t, 2) + 1.;
}
// для подвійного інтеграла
double InnerFunction(double y)
{
	return pow(X + 2. * y, 2);
}
double OuterFunction(double x)
//функція, що обчислює внутрішній інтеграл у повторному
{
	X = x;  // передавання другої змінної через глобальну
	return LeftRect(0., x, InnerFunction, 0.0001);
}
void NumericalIntegration()
{
	cout << "\n *Обчислення інтегралів методом лівих прямокутників*\n\n";
	// обчислимо одновимірний інтеграл
	cout << "Integral(sin,0,Pi) = " << LeftRect(0., M_PI, sin) << '\n';
	// а тепер - серію S(t)
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i * 0.5;
		cout << "  " << t << '\t'
			<< LeftRect(-1., 1., ParameterizedFunction, 1e-5) << '\n';
	}
	// і нарешті - подвійний
	cout << "\n Подвійний інтеграл повторним числовим інтегруванням\n";
	cout << "Double integral = "
		<< LeftRect(0., 1., OuterFunction, 0.0001) << '\n';
	return;
}
