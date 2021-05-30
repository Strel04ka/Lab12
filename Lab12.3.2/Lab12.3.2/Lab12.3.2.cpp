#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* next;
	Elem* prev;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void Create(Elem*& first, Elem*& last, int n, int i)
{
	if (i < n)
	{
		enqueue(first, last, 0 + rand() % (5));
		Create(first, last, n, i + 1);
	}
}

void Print(Elem* L)
{
	if (L != NULL)
	{
		cout << L->info << "  ";
		Print(L->next);
	}
	else
		cout << endl;
}

bool Scan(Elem* L)
{
	if (L != NULL && L->next != NULL)
	{
		if (L->info > L->next->info)
			return false;
		else
			return Scan(L->next);
	}
	return true;
}

int main()
{
	Elem* first = NULL;
	Elem* last = NULL;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "довжина= "; cin >> n;
	Create(first, last, n, 0);

	Print(first);
	cout << endl;

	cout << Scan(first) << endl;

	return 0;
}