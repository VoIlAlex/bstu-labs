// 24.02.2018
// Лабораторная работа №9
// Тема: Структуры 
// Автор: Волк Илья Александрович

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
const int Notname = system("color f0");
/** Структрура, хронящая данные о сотруднике **/
struct sotrudnik
{
	unsigned y_of_b : 15; // год рождения
	bool isSInt : 1; // целочисленная ли зарплата
					 // объединение для зарплаты
	union
	{
		int s_int; // для целочисленных зарплат
		double s_double; // для нецелочисленных зарплат
	}salary;
	// Должность
	enum
	{
		cleaner = 1,
		programmer,
		director
	}position;
	char last_name[100], name[100], patronymic[100]; // фамилия, имя, отчество
	int num;
};
/**********************************************/
// выведение сведений о данном сотруднике
void output_sotr(sotrudnik sotr)
{
	cout << "Сотрудник №" << sotr.num << endl << endl;
	cout << "Фамилия: " << sotr.last_name << endl;
	cout << "Имя: " << sotr.name << endl;
	cout << "Отчество: " << sotr.patronymic << endl;
	cout << "Год рождения: " << sotr.y_of_b << endl;
	cout << "Должность: " << ((sotr.position == 1) ? "Уборщик" : ((sotr.position == 2) ? "Программист" : "Директор")) << endl;
	cout << "Зарплата: " << ((sotr.isSInt) ? sotr.salary.s_int : sotr.salary.s_double) << endl << endl;
}
int main()
{
	setlocale(LC_ALL, "russian");
	sotrudnik* sotr = new sotrudnik[1]; // указатель для массива структур 
	int sotr_num; // количество сотрудников
	double isSotr = false; // показывает, существует ли сотрудник
	while (1)
	{
		system("cls");
		/** меню **/
		int input_menu;
		cout << " 1. Ввод массива сотрудников\n";
		cout << " 2. Вывод массива сотрудников\n";
		cout << " 3. Сортировка массива сотрудников\n";
		cout << " 4. Поиск в массиве сотрудников по заданному параметру\n";
		cout << " 5. Изменение заданного сотрудника\n";
		cout << " 6. Удаление сотрудника из массива\n";
		cout << " 7. Выход\n";
		cout << "Ввод: "; cin >> input_menu;
		/***********/
		system("cls");
		// если нужно ввести массив структур
		if (input_menu == 1)
		{
			isSotr = true;
			// создание массива с заданным количеством сотрудников
			cout << "Введите колическво сотрудников: "; cin >> sotr_num;
			delete[] sotr;
			sotr = new sotrudnik[sotr_num];
			// заполнение структуры каждого сотрудника
			for (int i = 0; i < sotr_num; i++)
			{
				system("cls");
				sotr[i].num = i + 1;
				cout << "Сотрудник №" << sotr[i].num << endl << endl;
				// фамилия, имя, отчество
				cout << "Введите фамилию: "; cin >> sotr[i].last_name; cout << endl;
				cout << "Введите имя: "; cin >> sotr[i].name; cout << endl;
				cout << "Введите отчество: "; cin >> sotr[i].patronymic; cout << endl;
				// год рождения
				int y_of_b;
				cout << "Введите год рождения: "; cin >> y_of_b; cout << endl;
				sotr[i].y_of_b = y_of_b;
				// должность
				int pos;
				cout << "Выберите должность (1 - uborshik, 2 - programmist, 3 - direktor): "; cin >> pos; cout << endl;
				if (pos == 1)sotr[i].position = sotrudnik::cleaner;
				else if (pos == 2)sotr[i].position = sotrudnik::programmer;
				else if (pos == 3)sotr[i].position = sotrudnik::director;
				else { system("pause");  return 0; };
				// зарплата
				double sal;
				cout << "Введите зарплату: "; cin >> sal; cout << endl;
				if ((sal - (double)((int)sal)) == 0) { sotr[i].salary.s_int = sal; sotr[i].isSInt = true; }
				else { sotr[i].salary.s_double = sal; sotr[i].isSInt = false; }
			}
		}
		// если нужно вывести массив структур
		else if (input_menu == 2)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // если сотрудников нет, то можно выполнить только 1-й пункт
																	  // вывод массива структур
			for (int i = 0; i < sotr_num; i++)
			{
				output_sotr(sotr[i]);
			}
			system("pause");
		}
		// если нужно сортировать массив структур
		else if (input_menu == 3)
		{
			if (!isSotr || (sotr_num < 2)) { cout << "Error!"; Sleep(1000); continue; } // если сотрудников нет
			int type_sort; // тип сортировки
			cout << " 1. По фамилии \n 2. По году рождения \n 3. По должности\nВвод: "; cin >> type_sort;
			sotrudnik sotr_copy; //копия сотрудника
			for (int i = 0; i < (sotr_num - 1); i++)
			{
				// сортировка по фамилии
				if (type_sort == 1)
				{
					if (sotr[i].last_name[0]>sotr[i + 1].last_name[0]) {
						int sotr_i_num = sotr[i].num;
						sotr[i].num = sotr[i + 1].num;
						sotr[i + 1].num = sotr_i_num;
						sotr_copy = sotr[i];
						sotr[i] = sotr[i + 1];
						sotr[i + 1] = sotr_copy;
					}
				}
				// сортировка по году рождения
				else if (type_sort == 2)
				{
					if (sotr[i].y_of_b > sotr[i + 1].y_of_b)
					{
						int sotr_i_num = sotr[i].num;
						sotr[i].num = sotr[i + 1].num;
						sotr[i + 1].num = sotr_i_num;
						sotr_copy = sotr[i];
						sotr[i] = sotr[i + 1];
						sotr[i + 1] = sotr_copy;
					}
				}
				// сортировка по должности
				else if (type_sort == 3)
				{
					if (sotr[i].position > sotr[i + 1].position)
					{
						int sotr_i_num = sotr[i].num;
						sotr[i].num = sotr[i + 1].num;
						sotr[i + 1].num = sotr_i_num;
						sotr_copy = sotr[i];
						sotr[i] = sotr[i + 1];
						sotr[i + 1] = sotr_copy;
					}
				}
				else { cout << "Error sorting!"; continue; }
			}
			system("cls");
			cout << "Success!";
			Sleep(1000);
		}
		// если нужно производить поиск в массиве по заданному параметру
		else if (input_menu == 4)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // если сотрудников нет
			int type_search; // параметр поиска
			cout << " 1. По фамилии\n 2. По имени\n 3. По отчеству\n 4. По году рождения\n 5. По должности\n 6. По зарплате\nВвод: ";
			cin >> type_search;
			system("cls");
			// поиск по фамилии
			if (type_search == 1)
			{
				char last_name[100] = ""; cout << "Ввод: "; cin >> last_name;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(last_name, sotr[i].last_name))
						output_sotr(sotr[i]);
				system("pause");
			}
			// поиск по имени
			else if (type_search == 2)
			{
				char name[100] = ""; cout << "Ввод: "; cin >> name;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(name, sotr[i].name))
						output_sotr(sotr[i]);
				system("pause");
			}
			// поиск по отчеству
			else if (type_search == 3)
			{
				char patronymic[100] = ""; cout << "Ввод: "; cin >> patronymic;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(patronymic, sotr[i].patronymic))
						output_sotr(sotr[i]);
				system("pause");
			}
			// поиск по году рождения
			else if (type_search == 4)
			{
				int y_of_b; cout << "Ввод: "; cin >> y_of_b;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (y_of_b == sotr[i].y_of_b)
						output_sotr(sotr[i]);
				system("pause");
			}
			// поиск по должности
			else if (type_search == 5)
			{
				int position; cout << "Ввод: "; cin >> position;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (position == sotr[i].position)
						output_sotr(sotr[i]);
				system("pause");
			}
			// поиск по зарплате
			else if (type_search == 6)
			{
				bool isSInt = false;
				double salary; cout << "Ввод: "; cin >> salary;
				if ((salary - (double)((int)salary)) == 0.0) isSInt = true;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (((isSInt) ? (int)salary : salary) == ((sotr[i].isSInt) ? sotr[i].salary.s_int : sotr[i].salary.s_double))
						output_sotr(sotr[i]);
				system("pause");
			}
			else { cout << "Error searching!"; continue; }
			system("cls");
			cout << "Success!";
			Sleep(1000);
		}
		// если нужно изменить заданную структуру
		else if (input_menu == 5)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // если сотрудников нет
			unsigned short num; // номер сотрудника
			cout << "Номер сотрудника: "; cin >> num;
			unsigned short i = num - 1; // номер сотрудника - 1 (для работы с массивом)
										// если неправильно введен номер сотрудника
			if (num > sotr_num || num == 0) { cout << "Error!"; continue; }
			system("cls");
			cout << "Сотрудник №" << sotr[i].num << endl << endl;
			// фамилия, имя, отчество
			cout << "Введите фамилию: "; cin >> sotr[i].last_name; cout << endl;
			cout << "Введите имя: "; cin >> sotr[i].name; cout << endl;
			cout << "Введите отчество: "; cin >> sotr[i].patronymic; cout << endl;
			// год рождения
			int y_of_b;
			cout << "Введите год рождения: "; cin >> y_of_b; cout << endl;
			sotr[i].y_of_b = y_of_b;
			// должность
			int pos;
			cout << "Выберите должность (1 - uborshik, 2 - programmist, 3 - direktor): "; cin >> pos; cout << endl;
			if (pos == 1)sotr[i].position = sotrudnik::cleaner;
			else if (pos == 2)sotr[i].position = sotrudnik::programmer;
			else if (pos == 3)sotr[i].position = sotrudnik::director;
			else { system("pause");  return 0; };
			// зарплата
			double sal;
			cout << "Введите зарплату: "; cin >> sal; cout << endl;
			if ((sal - (double)((int)sal)) == 0) { sotr[i].salary.s_int = sal; sotr[i].isSInt = true; }
			else { sotr[i].salary.s_double = sal; sotr[i].isSInt = false; }
			system("cls");
			cout << "Success!";
			Sleep(1000);
		}
		// если нужно удалить структурту из массива
		else if (input_menu == 6)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // если сотрудников нет
			unsigned short num; // номер сотрудника
			cout << "Номер сотрудника: "; cin >> num;
			// если неправильно введен номер сотрудника
			if (num > sotr_num || num == 0) { cout << "Error!"; continue; }
			// если в массиве всего один элемент
			if (sotr_num == 1)
			{
				delete[] sotr;
				sotr = new sotrudnik[1];
				isSotr = false;
				system("cls");
				cout << "Success!";
				Sleep(1000);
				continue;
			}
			sotr_num = sotr_num - 1;
			// сдвиг 
			for (unsigned short i = num - 1; i < sotr_num; i++)
			{
				int sotr_i_num = sotr[i].num;
				sotr[i].num = sotr[i + 1].num;
				sotr[i + 1].num = sotr_i_num;
				sotr[i] = sotr[i + 1];
			}
			// создем копию, в которую размещаем нужный массив
			sotrudnik * sotr_copy = new sotrudnik[sotr_num];
			for (int i = 0; i < sotr_num; i++)
			{
				sotr_copy[i] = sotr[i];
			}
			// изменяем существующий массив сотрудников 
			delete[] sotr;
			sotr = new sotrudnik[sotr_num];
			for (int i = 0; i < sotr_num; i++)
			{
				sotr[i] = sotr_copy[i];
			}
			system("cls");
			cout << "Success!";
			Sleep(1000);
		}
		// выход
		else if (input_menu == 7)
			break;
		// если не выбран ни один пункт меню
		else
		{
			cout << " Error! ";
			Sleep(500);
			system("cls");
		}
	}
	system("pause");
	return 0;
}

