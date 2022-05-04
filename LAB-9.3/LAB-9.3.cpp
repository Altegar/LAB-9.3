// LAB-9.3.cpp
// Сушинський Ігор
// Лабораторія №9.3
// Опрацювання масиву структур.
// Варіант 18

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;

struct Price
{
    string tovar;
    string shop;
    float price;
};

void Create(Price* p, const int N);
void Print(Price* p, const int N);
void Sort(Price* p, const int N);
void SearchPrice(Price* p, const int N);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть кількість товарів N: "; cin >> N;

	Price* p = new Price[N];

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - вивід інформації про товар" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			SearchPrice(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Create(Price* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Товар № " << i + 1 << ":" << endl;

		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " назва товару: "; getline(cin, p[i].tovar);
		cout << " назва магазину: "; getline(cin, p[i].shop);
		cout << " вартість товару: "; cin >> p[i].price;
		cout << endl;
	}
}

void Print(Price* p, const int N)
{
	cout << "=========================================="
		 << endl;
	cout << "|  №  |   Товар   |  Магазин  | Вартість |"
		 << endl;
	cout << "------------------------------------------"
		 << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1;
		cout << " | " << setw(9) << right << p[i].tovar
			 << " | " << setw(9) << right << p[i].shop
			 << " | " << setw(8) << right << p[i].price << " |";
		cout << endl;
	}
	cout << "=========================================="
		 << endl;
	cout << endl;
}

void Sort(Price* p, const int N)
{
	Price tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод «бульбашки»
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].shop > p[i1 + 1].shop)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

void SearchPrice(Price* p, const int N)
{
	string tovar;
	int k = 0;

	cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
	cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

	cout << " назва товару: "; getline(cin, tovar);

	for (int i = 0; i < N; i++)
	{
		k++;
		if (p[i].tovar == tovar)
		{
			cout << "=========================================="
				 << endl;
			cout << "|  №  |   Товар   |  Магазин  | Вартість |"
				 << endl;
			cout << "------------------------------------------"
				 << endl;
			cout << "| " << setw(3) << k << " | " << setw(9) << p[i].tovar << " | "
				 << setw(9) << p[i].shop << " | " << setw(8) << p[i].price << " |"
				 << endl;
			cout << "=========================================="
				 << endl;
			cout << endl;
		}
	}
}