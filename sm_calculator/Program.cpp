#include "ModularArithmetic.h"

int main()
{
	setlocale(LC_ALL, "");

	int Enter;

	cout << "\t\t\t\t����: " << endl;
	cout << "1. �������� ����i��." << endl;
	cout << "2. �������� ��������� ��������." << endl;
	cout << "3. ���������� �������� ����i��." << endl;
	cout << "4. �������� ����������� ���������� �������� �� �������." << endl;
	cout << "5. ��������� ������� ��� �����." << endl;
	cout << "6. ������� �����." << endl;
	cout << "7. ���i�." << endl;

	cout << endl;
	cout << "����i�� ����i���� ����� � ����: ";
	cin >> Enter;
	cout << endl;

	Menu(Enter);

	system("pause");
	return 0;
}