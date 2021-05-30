#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void push(Elem*& top, Info value);
Info pop(Elem*& top);
void read(fstream& fin, int i);
void InsertK(Elem*& top, int n);
void InsertF(Elem*& top, char* filename);

void read(Elem*& top, fstream& fin)
{
	char line[80];
	while (!fin.eof())
	{
		fin.getline(line, sizeof(int));
		cout << line << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* top1 = NULL;
	Elem* top2 = NULL;

	char* filename = 0; // ??

	// створення стеку

	cout << "Виберіть ввід:";
	char* ch;
	int n = 5;
	InsertK(top1, n);
	InsertF(top1, filename);

	cout << "Перший стек:" << " "; cin >> n;
	InsertK(top1, n);
	InsertK(top2, n);

	int k;
	cout << "Другий стек:" << " "; cin >> k;
	InsertF(top1, filename);
	InsertF(top2, filename);
	cout << endl;

	fstream fin;
	read(top1, fin);

	// вилучення та вивід елементів
	while (top1 != NULL)
		cout << pop(top1) << " ";
	cout << endl;

	return 0;
}

void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}

Info pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}

void InsertK(Elem*& top, int n)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		cout << "x = ? "; cin >> x;
		push(top, x);
	}
}

void InsertF(Elem*& top, char* filename)
{
	ifstream f(filename); // відкриваємо файл
	int x;
	while (f >> x)
	{
		push(top, x);
	}
}