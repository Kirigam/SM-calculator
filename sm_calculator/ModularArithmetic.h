#include<iostream>
using namespace std;

void Menu(int Numberic);

long long RelegationDegree(long long Numberic, long long DegreeNumbers, long long Module); //Алгоритм пониження степення

int InverseElement(int Numberic, int Module); // Алгоритм знаходження оберненого елемента за модулем

int NOD(int Numberic, int Module); // Алгоритм Евкліда

long long ModInverse(long long Numberic, long long Module); // Розшириний алгоритм Евкліда

long long ChineseTheorem(int p1, int q1, int p2, int q2, int p3, int q3); //Китайська теорема про лишки

long long TheoremFerma(int Numberic, int DegreeNumbers, int ClassResidues); // Теорема Ферма