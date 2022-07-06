#include "calc-procedures.h"

void SumOfSeriesB()
{
	cout << "\n *���������� ���� ���� S( (-1)^k x^4k+3 / (2k+1)!(4k+3) )*\n\n"
		<< "������ ����� ����� x = ";
	double x;
	cin >> x;
	cout << "������� ������� ��������� eps = ";
	double eps;
	cin >> eps;
	// ������������ �� ���������
	double multiplier = x * x;
	double semiterm = x * multiplier; // ������ ���� ���� ��� ������� (4k+3)
	double term = semiterm / 3; // ���� ����
	double sum = term;          // ���� ����
	multiplier = -multiplier * multiplier;   // ����� �������� �������
	int k = 0;                  // ����� ����������� �������
	// ���������� ���� ����
	while (abs(term) > eps)
	{
		// �������� ���� ���� ���������� �� ����������� ��������
		++k;
		semiterm *= multiplier / (2 * k * (2 * k + 1));
		term = semiterm / (4 * k + 3);
		sum += term;          // ��������� ���� � ��� ����
	}
	cout << "S(" << x << ") = " << sum << '\n';
	return;
}
