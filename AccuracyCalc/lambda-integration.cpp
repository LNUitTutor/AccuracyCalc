#include "calc-procedures.h"

void LambdaIntegration()
{
	cout << "\n *���������� ��������� � ������������� ������-������*\n\n";
	// ��������� ����������� ��������
	cout << "Integral(sin,0,Pi) = " << LeftRect(0., M_PI, sin) << '\n';
	// � ����� - ���� S(t)
	static double t;           // �������� ������������ �������
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i * 0.5;
		cout << "  " << t << '\t' 
			<< LeftRect(-1., 1., [](double x) {return pow(x * t, 2) + 1.; }, 1e-5) << '\n';
	}
	// � ������ - ��������
	static double X;           // ������ �������� ������������ �������
	cout << "\n �������� �������� ��������� �������� �������������\n";
	double I = LeftRect(0., 1., [](double x) { X = x; 
			return LeftRect(0., x, [](double y) { return pow(X + 2. * y, 2); }, 0.0001); }, 0.0001);
	cout << "Double integral = " << I << '\n';

	cout << "\n ����������� ��� function<double(double)>\n\n";
	cout << "Integral(sin,0,Pi) = " 
		<< LeftRectIntegration(0., M_PI, [](double x) { return sin(x); }) << '\n';
	// � ����� - ���� S(t)
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		double t = i * 0.5;
		cout << "  " << t << '\t'
			<< LeftRectIntegration(-1., 1., [t](double x) {return pow(x * t, 2) + 1.; }, 1e-5) << '\n';
	}
	// � ������ - ��������
	cout << "\n �������� �������� ��������� �������� �������������\n";
	I = LeftRectIntegration(0., 1., [](double x) {
	return LeftRectIntegration(0., x, [x](double y) { return pow(x + 2. * y, 2); }, 0.0001); }, 0.0001);
	cout << "Double integral = " << I << '\n';
	return;
}