#include <Windows.h>
#include "calc-procedures.h"

int main()
{
	// ���������� � ������� �������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ���������� ���� ���� �������\n"
			<< " 2 - ���������� ���� ������������ ����\n 3 - ����� ����� ������ �����\n"
			<< " 4 - ������� ������������\n 5 - ������� ������������ � ������-��������\n"
			<< " 6 - ���������� ������\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: SinSeriesSum(); break;
		case 2: SumOfSeriesB(); break;
		case 3: Dichotomy(); break;
		case 4: NumericalIntegration(); break;
		case 5: LambdaIntegration(); break;
		default: cout << "�� ���������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}