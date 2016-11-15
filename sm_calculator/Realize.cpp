#include "ModularArithmetic.h"

long long RelegationDegree(long long Numberic, long long DegreeNumbers, long long Module)
{
	long long  A = 1;
i:
	if ((DegreeNumbers % 2) == 0)
	{
		Numberic = (Numberic*Numberic) % Module;
		DegreeNumbers = DegreeNumbers / 2;
	}
	if (DegreeNumbers>1)
	if ((DegreeNumbers % 2) == 1)
	{
		A = Numberic;
		DegreeNumbers = DegreeNumbers - 1;
		Numberic = (Numberic*Numberic) % Module;
		DegreeNumbers = DegreeNumbers / 2;
	}

	if (DegreeNumbers>1)
		goto i;
	else
		Numberic = (A*Numberic) % Module;

	return Numberic;
}

int NOD(int Numberic, int Module)
{
	while (Numberic && Module)
	if (Numberic >= Module)
		Numberic %= Module;
	else
		Module %= Numberic;
	return Numberic | Module;
}

int InverseElement(int Numberic, int Module)
{
	long long res = ModInverse(Numberic, Module);
	res %= Module;
	return res;
}

long long ModInverse(long long Numberic, long long Module)
{
	long long i = Module, v = 0, d = 1;
	while (Numberic > 0)
	{
		long long t = i / Numberic, x = Numberic;
		Numberic = i % x;
		i = x;
		x = d;
		d = v - t * x;
		v = x;
	}
	v %= Module;
	if (v < 0) v = (v + Module) % Module;
	return v;
}

long long TheoremFerma(int Numberic, int DegreeNumbers, int ClassResidues)
{
	long long Q, P1, P2, P3;
	long long a1, a2, a3;
	long long A1, A2, A3;

	P1 = ClassResidues;
	P2 = (2 * ClassResidues) - 1;
	P3 = (2 * ClassResidues) + 1;
	Q = P1 * P2 * P3;

	a1 = InverseElement(Numberic, P1);
	a2 = InverseElement(Numberic, P2);
	a3 = InverseElement(Numberic, P3);

	A1 = RelegationDegree(a1, DegreeNumbers, P1);
	A2 = RelegationDegree(a2, DegreeNumbers, P2);
	A3 = RelegationDegree(a3, DegreeNumbers, P3);

	long long M = ((A1 * P2 * P3) + (A2 * P1 * P3) + (A3 * P1 * P2) % Q);

	return M;
}

long long ChineseTheorem(int p1, int q1, int p2, int q2, int p3, int q3)
{
	long Q = q1 * q2 * q3;

	long m1 = Q / q1;
	long m2 = Q / q2;
	long m3 = Q / q3;

	int M1 = InverseElement(m1, q1);
	int M2 = InverseElement(m2, q2);
	int M3 = InverseElement(m3, q3);

	long long M = ((M1 * m1 * p1) + (M2 * m2 * p2) + (M3 * m3 * p3)) % Q;

	return M;
}

void Menu(int Numberic)
{
	switch (Numberic)
	{
	case 1:
	{
			  int a, b;

			  system("cls");
			  cout << "�������� ����i��." << endl;
			  cout << "����i�� �����: "; cin >> a;
			  cout << "����i��  mod: "; cin >> b;

			  int res = NOD(a, b);
			  cout << a << " mod " << b << " = " << res << endl;

			  break;
	}

	case 2:
	{
			  int a, b, c;

			  system("cls");
			  cout << "�������� ��������� ��������." << endl;
			  cout << "����i�� �����: "; cin >> a;
			  cout << "����i�� ����i��: "; cin >> b;
			  cout << "����i��  mod: "; cin >> c;

			  long long res = RelegationDegree(a, b, c);
			  cout << a << " � ������i " << b << " mod " << b << " = " << res << endl;

			  break;
	}

	case 3:
	{
			  int a, b;

			  system("cls");
			  cout << "���������� �������� ����i��." << endl;
			  cout << "����i�� �����: "; cin >> a;
			  cout << "����i��  mod: "; cin >> b;

			  long long res = ModInverse(a, b);
			  cout << a << " mod " << b << " = " << res << endl;

			  break;
	}

	case 4:
	{
			  int a, b;

			  system("cls");
			  cout << "�������� ����������� ���������� �������� �� �������." << endl;
			  cout << "����i�� �����: "; cin >> a;
			  cout << "����i��  mod: "; cin >> b;

			  int res = InverseElement(a, b);
			  cout << a << " -1 mod " << b << " = " << res << endl;

			  break;
	}

	case 5:
	{
			  int a, b, c, a1, b1, c1;

			  system("cls");
			  cout << "��������� ������� ��� �����." << endl;
			  cout << "����i�� p1: "; cin >> a;
			  cout << "����i�� q1: "; cin >> a1;
			  cout << "����i�� p2: "; cin >> b;
			  cout << "����i�� q2: "; cin >> b1;
			  cout << "����i�� p3: "; cin >> c;
			  cout << "����i�� q3: "; cin >> c1;

			  int res = ChineseTheorem(a, a1, b, b1, c, c1);
			  cout << "M = " << res << endl;

			  break;
	}

	case 6:
	{
			  int a, b, c;

			  system("cls");
			  cout << "������� �����." << endl;
			  cout << "����i�� �����: "; cin >> a;
			  cout << "����i�� ����i��: "; cin >> b;
			  cout << "����i��  ������� �������� ������i� ����i�: "; cin >> c;

			  long long res = TheoremFerma(a, b, c);
			  cout << "��������� = " << res << endl;

			  break;
	}

	case 7:
	{
			  cout << "���i�." << endl;
			  break;
	}
	default:
	{
			   cout << "������� �� �i��� �����, ��������� �� ���..." << endl;

			   break;
	}
	}
}

