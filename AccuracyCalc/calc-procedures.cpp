#include "calc-procedures.h"

double Dichotom(Func f, double a, double b, double eps)
// ���������� ��������� ������ ������쳿
{
	double fa = f(a);
	while (b - a > eps)
	{
		double c = (a + b) * 0.5; // �������� �������
		double fc = f(c);
		if (fa * fc < 0) b = c;   // ����� � � ��� ������� �������
		else                      // ����� � ��������
		{
			a = c; fa = fc;
		}
	}
	return (a + b) * 0.5;
}

double DichotomRecursive(Func f, double a, double b, double eps)
// ���������� ��������� ������ ������쳿
{
	double c = (a + b) * 0.5;
	if (b - a <= eps)     // ������� ��������� �����
		return c;
	if (f(a)*f(c) < 0)    // ������ ����� �� ��� �������
		return DichotomRecursive(f, a, c, eps);
	else                  // ������ ����� �� ����� �������
		return DichotomRecursive(f, c, b, eps);
}

double LeftRect(double a, double b, Func f, double eps)
// �������� �� f �� ������� [a; b] ������� ���� ������������
// I_2n - �������� I(2n); I_n - �������� I(n); sum - ���������������
// ��� ��������� ����������� ���� ������� f(x_i)
// ��������� �� ����� 12 ������� ���� ������������
{
	int n = 10;
	double h = (b - a) / n;
	double sum = 0.;
	for (int i = 0; i < n; ++i) sum += f(a + i * h);
	double I_2n = sum * h;  // ����� �������� ���������
	double I_n = 0.;        // �������� ��������
	int doublings = 0;      // ������� ������� ����� ������������
	while (abs(I_2n - I_n) / 3. > eps && doublings < 13)
	{
		++doublings;
		I_n = I_2n;                  // ���������� �������� I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			sum += f(a2 + i * h);  // ��������� ����
		I_2n = sum * h2;             // �������� ���� �������� I(2n)
		h = h2; n += n;              // ������� ������� �������
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
	double I_2n = sum * h;  // ����� �������� ���������
	double I_n = 0.;        // �������� ��������
	int doublings = 0;      // ������� ������� ����� ������������
	while (abs(I_2n - I_n) / 3. > eps && doublings < 13)
	{
		++doublings;
		I_n = I_2n;                  // ���������� �������� I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			sum += f(a2 + i * h);  // ��������� ����
		I_2n = sum * h2;             // �������� ���� �������� I(2n)
		h = h2; n += n;              // ������� ������� �������
	}
	if (doublings > 12) cout << "leftRec::WARNING: Accuracy loss is possible\n";
	return I_2n;
}
