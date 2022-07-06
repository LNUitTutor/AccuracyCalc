#include "calc-procedures.h"

// �������� ����
double t;
double X;

// ��������� ����������� �������
double ParameterizedFunction(double x)
{   // ��� ���������, ��������� �� ��������� t
	return pow(x * t, 2) + 1.;
}
// ��� ��������� ���������
double InnerFunction(double y)
{
	return pow(X + 2. * y, 2);
}
double OuterFunction(double x)
//�������, �� �������� �������� �������� � ����������
{
	X = x;  // ����������� ����� ����� ����� ���������
	return LeftRect(0., x, InnerFunction, 0.0001);
}
void NumericalIntegration()
{
	cout << "\n *���������� ��������� ������� ���� ������������*\n\n";
	// ��������� ����������� ��������
	cout << "Integral(sin,0,Pi) = " << LeftRect(0., M_PI, sin) << '\n';
	// � ����� - ���� S(t)
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i * 0.5;
		cout << "  " << t << '\t'
			<< LeftRect(-1., 1., ParameterizedFunction, 1e-5) << '\n';
	}
	// � ������ - ��������
	cout << "\n �������� �������� ��������� �������� �������������\n";
	cout << "Double integral = "
		<< LeftRect(0., 1., OuterFunction, 0.0001) << '\n';
	return;
}
