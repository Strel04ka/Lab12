#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "time.h"

typedef int Data;
struct elem {
	Data data;
	elem* next;
};

void insert(elem*& L, Data value);
void createList(elem*& L, int k);
void display(elem* L);
void add(elem* L, Data k);
void create_Circle_List_Rec(elem*& L, int n, elem* head, int k);
void display_Rec(elem* L, elem* first);
void add_Rec(elem*& L, Data k, elem* first);
void deleteListRec(elem* L, elem* current);
void deleteList(elem* L);


using namespace std;

int menu()
{
	int i;
	cout << endl;
	cout << "Виберіть режим роботи: " << endl << endl;
	cout << "1 - Ітераційне створення кільцевого списку " << endl;
	cout << "2 - Ітераційний перегляд кільцевого списку " << endl;
	cout << "3 - Рекурсивне створення кільцевого списку " << endl;
	cout << "4 - Рекурсивний перегляд кільцевого списку " << endl;
	cout << "5 - Ітераційне вилучення елементів кільцевого списку " << endl;
	cout << "6 - Рекурсивне вилучення елементів кільцевого списку " << endl;
	cout << "0 - Вихід " << endl;
	cin >> i;
	return i;
}

int main(int argc, TCHAR* argv[])

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int count, k;
	cout << "Задайте кількість елементу списку "; cin >> count;
	cout << "Задайте число, на яке будемо зменшувати "; cin >> k;
	elem* head = NULL;
	elem* Head = NULL;

	do
		switch (menu()) {
		case 1: createList(head, count); break;
		case 2: display(head); break;
		case 3: create_Circle_List_Rec(Head, count, Head, count); break;
		case 4: display_Rec(Head, Head); break;
		case 5: add(head, k); break;
		case 6: add_Rec(Head, k, Head); break;
		case 0: deleteListRec(Head, Head); deleteList(head); return 0; break;
		} while (true);

		system("pause");
}

void insert(elem*& L, Data value) {
	elem* tmp = new elem; tmp->data = value;
	if (L != NULL) {
		elem* T = L;
		while (T->next != L) T = T->next;
		T->next = tmp;
	}
	else L = tmp;
	tmp->next = L; // З'єднюю до початку
}
void createList(elem*& L, int k) {
	Data value;
	for (int i = 1; i <= k; i++) {
		cout << "Введіть значення "; cin >> value;
		insert(L, value);
	}
}
void display(elem* L) {
	if (L == NULL) return;
	elem* first = L;
	while (L->next != first) {
		cout << L->data << " "; L = L->next;
	}
	cout << L->data << endl;
}

void add(elem* L, Data k) {
	if (L == NULL) return;
	elem* first = L;
	while (L->next != first) {
		L->data = L->data - k; L = L->next;
	}
	L->data = L->data - k;
}

void create_Circle_List_Rec(elem*& L, int n, elem* head, int k) {
	if (n > 0) {
		L = new elem;
		if (n == k) head = L;
		cout << "Введіть значення "; cin >> L->data;
		L->next = NULL;
		if (n == 1)
			L->next = head;
		create_Circle_List_Rec(L->next, n - 1, head, k);
	}
}

void display_Rec(elem* L, elem* first) {
	if (L == NULL) return;
	else {
		if (L->next != first) {
			cout << L->data << " ";
			display_Rec(L->next, first);
		}
		else {
			cout << L->data << endl; return;
		}
	}
}

void add_Rec(elem*& L, Data k, elem* first) {
	if (L == NULL)
		return;
	else {
		if (L->next != first) {
			L->data = L->data - k;
			add_Rec(L->next, k, first);
		}
		else {
			L->data = L->data - k; return;
		}
	}
}

void deleteListRec(elem* L, elem* current) {
	elem* p = NULL;
	if (L == NULL)
		return;
	if (current == L) {
		delete current; return;
	}
	else {
		p = current;
		current = current->next; delete p;
		deleteListRec(L, current);
	}
}
void deleteList(elem* L) {
	if (L == NULL)
		return;
	elem* p = NULL;
	elem* current = L->next;
	while (current != L) {
		p = current;
		current = current->next; delete p;
	} delete L;
}