#include "calc-procedures.h"

void SinSeriesSum()
{
	cout << "\n *���������� ���� ���� ������� - �������� sin(x)*\n\n"
		<< "������ ����� ����� x = ";
	double x;
	cin >> x;
	const double eps = 1e-6;
	// ������������ �� ���������
	double x2 = -x * x; // ����� �������� �������
	double term = x;    // ������ ���� ����
	double sum = x;     // ���� ����
	unsigned n = 2;     // �������� ������� ��� ���������
	while (abs(term) > eps)
	{
		// �������� ���� ���� ���������� �� ����������� ��������
		term *= x2 / ((double)n * (n + 1));
		sum += term;  // ��������� ���� � ��� ����
		n += 2;
	}
	cout << "S = " << sum << "   sin(x) = " << sin(x) << '\n';
	return;
}
