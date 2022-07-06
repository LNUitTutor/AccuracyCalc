#include <Windows.h>
#include "calc-procedures.h"

int main()
{
	// Обчислення з заданою точністю

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Обчислення суми ряду Тейлора\n"
			<< " 2 - Обчислення суми знакозмінного ряду\n 3 - Метод поділу відрізка навпіл\n"
			<< " 4 - Числове інтегрування\n 5 - Числове інтегрування з лямбда-виразами\n"
			<< " 6 - Завершення роботи\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: SinSeriesSum(); break;
		case 2: SumOfSeriesB(); break;
		case 3: Dichotomy(); break;
		case 4: NumericalIntegration(); break;
		case 5: LambdaIntegration(); break;
		default: cout << "До побачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}