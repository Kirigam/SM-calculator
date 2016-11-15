#include "ModularArithmetic.h"

int main()
{
	setlocale(LC_ALL, "");

	int Enter;

	cout << "\t\t\t\tМеню: " << endl;
	cout << "1. Алгоритм Евклiда." << endl;
	cout << "2. Алгоритм пониження степення." << endl;
	cout << "3. Розшириний алгоритм Евклiда." << endl;
	cout << "4. Алгоритм знаходження оберненого елемента за модулем." << endl;
	cout << "5. Китайська теорема про лишки." << endl;
	cout << "6. Теорема Ферма." << endl;
	cout << "7. Вихiд." << endl;

	cout << endl;
	cout << "Введiть потрiбний пункт у меню: ";
	cin >> Enter;
	cout << endl;

	Menu(Enter);

	system("pause");
	return 0;
}