// 24.02.2018
// ������������ ������ �9
// ����: ��������� 
// �����: ���� ���� �������������

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
const int Notname = system("color f0");
/** ����������, �������� ������ � ���������� **/
struct sotrudnik
{
	unsigned y_of_b : 15; // ��� ��������
	bool isSInt : 1; // ������������� �� ��������
					 // ����������� ��� ��������
	union
	{
		int s_int; // ��� ������������� �������
		double s_double; // ��� ��������������� �������
	}salary;
	// ���������
	enum
	{
		cleaner = 1,
		programmer,
		director
	}position;
	char last_name[100], name[100], patronymic[100]; // �������, ���, ��������
	int num;
};
/**********************************************/
// ��������� �������� � ������ ����������
void output_sotr(sotrudnik sotr)
{
	cout << "��������� �" << sotr.num << endl << endl;
	cout << "�������: " << sotr.last_name << endl;
	cout << "���: " << sotr.name << endl;
	cout << "��������: " << sotr.patronymic << endl;
	cout << "��� ��������: " << sotr.y_of_b << endl;
	cout << "���������: " << ((sotr.position == 1) ? "�������" : ((sotr.position == 2) ? "�����������" : "��������")) << endl;
	cout << "��������: " << ((sotr.isSInt) ? sotr.salary.s_int : sotr.salary.s_double) << endl << endl;
}
int main()
{
	setlocale(LC_ALL, "russian");
	sotrudnik* sotr = new sotrudnik[1]; // ��������� ��� ������� �������� 
	int sotr_num; // ���������� �����������
	double isSotr = false; // ����������, ���������� �� ���������
	while (1)
	{
		system("cls");
		/** ���� **/
		int input_menu;
		cout << " 1. ���� ������� �����������\n";
		cout << " 2. ����� ������� �����������\n";
		cout << " 3. ���������� ������� �����������\n";
		cout << " 4. ����� � ������� ����������� �� ��������� ���������\n";
		cout << " 5. ��������� ��������� ����������\n";
		cout << " 6. �������� ���������� �� �������\n";
		cout << " 7. �����\n";
		cout << "����: "; cin >> input_menu;
		/***********/
		system("cls");
		// ���� ����� ������ ������ ��������
		if (input_menu == 1)
		{
			isSotr = true;
			// �������� ������� � �������� ����������� �����������
			cout << "������� ���������� �����������: "; cin >> sotr_num;
			delete[] sotr;
			sotr = new sotrudnik[sotr_num];
			// ���������� ��������� ������� ����������
			for (int i = 0; i < sotr_num; i++)
			{
				system("cls");
				sotr[i].num = i + 1;
				cout << "��������� �" << sotr[i].num << endl << endl;
				// �������, ���, ��������
				cout << "������� �������: "; cin >> sotr[i].last_name; cout << endl;
				cout << "������� ���: "; cin >> sotr[i].name; cout << endl;
				cout << "������� ��������: "; cin >> sotr[i].patronymic; cout << endl;
				// ��� ��������
				int y_of_b;
				cout << "������� ��� ��������: "; cin >> y_of_b; cout << endl;
				sotr[i].y_of_b = y_of_b;
				// ���������
				int pos;
				cout << "�������� ��������� (1 - uborshik, 2 - programmist, 3 - direktor): "; cin >> pos; cout << endl;
				if (pos == 1)sotr[i].position = sotrudnik::cleaner;
				else if (pos == 2)sotr[i].position = sotrudnik::programmer;
				else if (pos == 3)sotr[i].position = sotrudnik::director;
				else { system("pause");  return 0; };
				// ��������
				double sal;
				cout << "������� ��������: "; cin >> sal; cout << endl;
				if ((sal - (double)((int)sal)) == 0) { sotr[i].salary.s_int = sal; sotr[i].isSInt = true; }
				else { sotr[i].salary.s_double = sal; sotr[i].isSInt = false; }
			}
		}
		// ���� ����� ������� ������ ��������
		else if (input_menu == 2)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // ���� ����������� ���, �� ����� ��������� ������ 1-� �����
																	  // ����� ������� ��������
			for (int i = 0; i < sotr_num; i++)
			{
				output_sotr(sotr[i]);
			}
			system("pause");
		}
		// ���� ����� ����������� ������ ��������
		else if (input_menu == 3)
		{
			if (!isSotr || (sotr_num < 2)) { cout << "Error!"; Sleep(1000); continue; } // ���� ����������� ���
			int type_sort; // ��� ����������
			cout << " 1. �� ������� \n 2. �� ���� �������� \n 3. �� ���������\n����: "; cin >> type_sort;
			sotrudnik sotr_copy; //����� ����������
			for (int i = 0; i < (sotr_num - 1); i++)
			{
				// ���������� �� �������
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
				// ���������� �� ���� ��������
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
				// ���������� �� ���������
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
		// ���� ����� ����������� ����� � ������� �� ��������� ���������
		else if (input_menu == 4)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // ���� ����������� ���
			int type_search; // �������� ������
			cout << " 1. �� �������\n 2. �� �����\n 3. �� ��������\n 4. �� ���� ��������\n 5. �� ���������\n 6. �� ��������\n����: ";
			cin >> type_search;
			system("cls");
			// ����� �� �������
			if (type_search == 1)
			{
				char last_name[100] = ""; cout << "����: "; cin >> last_name;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(last_name, sotr[i].last_name))
						output_sotr(sotr[i]);
				system("pause");
			}
			// ����� �� �����
			else if (type_search == 2)
			{
				char name[100] = ""; cout << "����: "; cin >> name;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(name, sotr[i].name))
						output_sotr(sotr[i]);
				system("pause");
			}
			// ����� �� ��������
			else if (type_search == 3)
			{
				char patronymic[100] = ""; cout << "����: "; cin >> patronymic;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (!strcmp(patronymic, sotr[i].patronymic))
						output_sotr(sotr[i]);
				system("pause");
			}
			// ����� �� ���� ��������
			else if (type_search == 4)
			{
				int y_of_b; cout << "����: "; cin >> y_of_b;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (y_of_b == sotr[i].y_of_b)
						output_sotr(sotr[i]);
				system("pause");
			}
			// ����� �� ���������
			else if (type_search == 5)
			{
				int position; cout << "����: "; cin >> position;
				system("cls");
				for (int i = 0; i < sotr_num; i++)
					if (position == sotr[i].position)
						output_sotr(sotr[i]);
				system("pause");
			}
			// ����� �� ��������
			else if (type_search == 6)
			{
				bool isSInt = false;
				double salary; cout << "����: "; cin >> salary;
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
		// ���� ����� �������� �������� ���������
		else if (input_menu == 5)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // ���� ����������� ���
			unsigned short num; // ����� ����������
			cout << "����� ����������: "; cin >> num;
			unsigned short i = num - 1; // ����� ���������� - 1 (��� ������ � ��������)
										// ���� ����������� ������ ����� ����������
			if (num > sotr_num || num == 0) { cout << "Error!"; continue; }
			system("cls");
			cout << "��������� �" << sotr[i].num << endl << endl;
			// �������, ���, ��������
			cout << "������� �������: "; cin >> sotr[i].last_name; cout << endl;
			cout << "������� ���: "; cin >> sotr[i].name; cout << endl;
			cout << "������� ��������: "; cin >> sotr[i].patronymic; cout << endl;
			// ��� ��������
			int y_of_b;
			cout << "������� ��� ��������: "; cin >> y_of_b; cout << endl;
			sotr[i].y_of_b = y_of_b;
			// ���������
			int pos;
			cout << "�������� ��������� (1 - uborshik, 2 - programmist, 3 - direktor): "; cin >> pos; cout << endl;
			if (pos == 1)sotr[i].position = sotrudnik::cleaner;
			else if (pos == 2)sotr[i].position = sotrudnik::programmer;
			else if (pos == 3)sotr[i].position = sotrudnik::director;
			else { system("pause");  return 0; };
			// ��������
			double sal;
			cout << "������� ��������: "; cin >> sal; cout << endl;
			if ((sal - (double)((int)sal)) == 0) { sotr[i].salary.s_int = sal; sotr[i].isSInt = true; }
			else { sotr[i].salary.s_double = sal; sotr[i].isSInt = false; }
			system("cls");
			cout << "Success!";
			Sleep(1000);
		}
		// ���� ����� ������� ���������� �� �������
		else if (input_menu == 6)
		{
			if (!isSotr) { cout << "Error!"; Sleep(1000); continue; } // ���� ����������� ���
			unsigned short num; // ����� ����������
			cout << "����� ����������: "; cin >> num;
			// ���� ����������� ������ ����� ����������
			if (num > sotr_num || num == 0) { cout << "Error!"; continue; }
			// ���� � ������� ����� ���� �������
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
			// ����� 
			for (unsigned short i = num - 1; i < sotr_num; i++)
			{
				int sotr_i_num = sotr[i].num;
				sotr[i].num = sotr[i + 1].num;
				sotr[i + 1].num = sotr_i_num;
				sotr[i] = sotr[i + 1];
			}
			// ������ �����, � ������� ��������� ������ ������
			sotrudnik * sotr_copy = new sotrudnik[sotr_num];
			for (int i = 0; i < sotr_num; i++)
			{
				sotr_copy[i] = sotr[i];
			}
			// �������� ������������ ������ ����������� 
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
		// �����
		else if (input_menu == 7)
			break;
		// ���� �� ������ �� ���� ����� ����
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

