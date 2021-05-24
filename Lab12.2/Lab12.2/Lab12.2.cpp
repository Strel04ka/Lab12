#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
struct Node
{
	Node* next;
	int data;
	Node(int _data)
	{
		data = _data;
	}
};
struct ForwardList
{
private:
	Node* head;
	int count;
public:
	ForwardList()
	{
		count = 0;
		head = nullptr;
	}
	void push_back(int val)
	{
		if (head == nullptr)
		{
			head = new Node(val);
			head->next = nullptr;
		}
		else
		{
			Node* tmp = head;
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = new Node(val);
			tmp->next->next = nullptr;
		}
		count++;
	}
	int size()
	{
		return count;
	}
	int& operator[](int iter)
	{
		int t = 0;
		Node* tmp = head;
		while (tmp != nullptr)
		{
			if (t == iter)
				return tmp->data;
			tmp = tmp->next;
			t++;
		}
	}
};
ForwardList create(int size)
{
	ForwardList output;
	for (size_t i = 0; i < size; i++)
		output.push_back(rand() % (20) - 5);
	return output;
}
void print(ForwardList lst)
{
	for (size_t i = 0; i < lst.size(); i++)
		cout << lst[i] << "  ";
	cout << endl;
}
void task(ForwardList lst)
{
	int count = 0;
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst[i] < 0)
			count++;
	}
	cout << "Count : " << count << endl;
}
void main()
{
	system("color B");
	int size = 0;
	cout << "Size: "; cin >> size;
	ForwardList list = create(size);
	cout << "========created list:========" << endl;
	print(list);
	cout << "Task:" << endl;
	task(list);
	system("pause");
}
