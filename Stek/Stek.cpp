#include <iostream>
#include <clocale>

using namespace std;

struct Elem
{
	int x;
	Elem* next;
};

Elem* root = NULL;

void add(int d)
{

	Elem* c = new Elem;
	c->x = d;
	c->next = root;
	root = c;
}

void del()
{
	Elem* c = root;
	root = root->next;
	delete c;
}

void print() {

	Elem* c = root;
	while (c != 0)
	{
		cout << c->x << endl;
		c = c->next;
	}
}


void clean()
{
	while (root != 0)
	{
		del();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int reg = 2, a, n = 0;

	add(1);
	add(2);
	add(5);

	while (reg != 4)
	{
		cout << "Выберите действие " << endl;
		cout << "1 - Удалить верхний элемент из стека" << endl;
		cout << "2 - Вывести стек на экран консоли" << endl;
		cout << "3 - Добавить элемент в стек" << endl;
		cout << "4 - Выход" << endl;

		while (!(cin >> reg) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные, попробуйте снова" << endl;
		}

		switch (reg)
		{
			case 1:
			{
				cout << endl;
				del(); 
				system("pause");
				system("cls");
			}
			break;

			case 2:
			{
				cout << endl;
				print();
				clean();
				system("pause");
				system("cls");
			}
			break;

			case 3:
			{
				cout << endl << "Введите элемент, который хотите добавить" << endl;
				while (!(cin >> a) || (cin.peek() != '\n'))
				{
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					cout << "Некоректные данные, попробуйте снова" << endl;
				}
				add(a);
				cout << endl;
				system("pause");
				system("cls");
			}
			break;
		}
	}

	return 0;
}