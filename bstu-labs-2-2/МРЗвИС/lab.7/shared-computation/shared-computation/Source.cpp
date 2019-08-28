#include<iostream>
#include<vector> 
#include<fstream>
#include<string>
#include<ctime>
#include<bitset>
using namespace std;
int INF = 1000;
float T = 0.3;
//размер матрицы n*n
int size_gr = 8;
//полносвязный граф с расстояниями между компьютерами 
vector<vector<int> > GRAF(size_gr, vector<int>(size_gr, 0));

void select_pair(vector<pair<pair<string, int>, pair<string, int>>>&, vector<pair<string, int>>);
pair<string, int> find_nearest(pair<string, int>, vector<pair<string, int>>);
int comp(string, string );
void crossing(vector<pair<pair<string, int>, pair<string, int>>>, vector<pair<string, int>>&);
void shake(int num, string& a, string& b);
int length_calc(pair<string, int>);
void bit_to_int(string& str);
void Mutation(vector<pair<string, int>>& population);
pair<string, int> in_pl_del(pair<string, int> a);
void sort(vector<pair<string, int>>& population);
void watch(int a, int& min);
int main()
{
	srand(time(0));

	string buff;
	int size_T, rand_num;
	int first, second;
	int min = 1000;
	//популяция
	vector<pair<string, int>> population;
	vector<pair<pair<string, int>, pair<string, int>>> pair_to_pop;

	ifstream f("graf.txt");
	for (int i = 0; i < size_gr; i++)
	{
		for (int j = 0; j < size_gr; j++)
		{
			f >> buff;
			if (buff == "I")
				GRAF[i][j] = INF;
			else
				GRAF[i][j] = stoi(buff);
			buff.clear();
		}

	}

	cout << "Enter computer numbers(0...7)";
	cin >> first;
	cin >> second;
	/////////////////////////////////////////////////////////////
	//////1.Инициализация начальной популяции из 4 хромосом//////
	/////////////////////////////////////////////////////////////
	buff = to_string(first) + "34" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "17" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "41" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "06" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "23" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "45" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "12" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "47" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "56" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "21" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	buff = to_string(first) + "64" + to_string(second);
	population.push_back(pair<string, int>(buff, 0));

	for (int k = 0; k < 100; k++){

		//////////////////////////////////////////////////////////
		////2.Вычисляем для хромосом их пригодность(длину пути)///
		//////////////////////////////////////////////////////////
		for (int i = 0; i < population.size(); i++)
		{
			population[i].second = length_calc(population[i]);
		}
		//cout << k + 1 << "population:\n";
		for (int q = 0; q < population.size(); q++)
		{
			//cout << population[q].first << " " << population[q].second << endl;
			watch(population[q].second, min);
		}
		//cout << "\n\n\n";

		////////////////////////////////////////////////////////////////////
		////3.Выбираем пару методом ИНБРИДИНГА(1-случайный,2-ближайший)/////
		////////////////////////////////////////////////////////////////////
		select_pair(pair_to_pop, population);

		////////////////////////////////////////////////////////////
		////4.проводим одноточечный кросинговер с парами хромосом///
		////////////////////////////////////////////////////////////
		crossing(pair_to_pop, population);

		////////////////////////////////////
		////5.Мутация(вставка+ удаление)////
		////////////////////////////////////
		Mutation(population);
		for (int i = 0; i < population.size(); i++)
		{
			population[i].second = length_calc(population[i]);
		}
		////////////////////////////////////////////////
		////6.Выборка нового покаления(метод усечки)////
		////////////////////////////////////////////////
		size_T = T*population.size();
		vector<pair<string, int>> population1;
		sort(population);
		for (int i = 0; i < 10; i++)
		{
			rand_num = rand() % size_T;
			population1.push_back(population[rand_num]);
		}
		population = population1;
	}
	///////////////////////////////////////////////////////////
	////7.повтор 2-6 пока не будет достигнут критерий конца////
	///////////////////////////////////////////////////////////
	cout << "\n\n\n\n MIN length-" << min << endl;
	system("pause");
	return 0;
}
//int main()
//{
//	srand(time(0));
//	
//	string buff;
//	int size_T,rand_num;
//	int first, second;
//	int min = 1000;
//	//популяция
//	vector<pair<string, int>> population;
//	vector<pair<pair<string, int>, pair<string, int>>> pair_to_pop;
//
//	ifstream f("graf.txt");
//	for (int i = 0; i < size_gr; i++)
//	{
//		for (int j = 0; j < size_gr; j++)
//		{
//			f >> buff;
//			if (buff == "I")
//				GRAF[i][j] = INF;
//			else
//				GRAF[i][j] = stoi(buff);
//			buff.clear();
//		}
//
//	}
//
//	cout << "Enter computer numbers(0...7)";
//	cin >> first;
//	cin >> second;
///////////////////////////////////////////////////////////////
////////1.Инициализация начальной популяции из 4 хромосом//////
///////////////////////////////////////////////////////////////
//	buff = to_string(first) + "34" + to_string(second);
//	population.push_back(pair<string, int>(buff, 0));
//	buff = to_string(first) + "17" + to_string(second);
//	population.push_back(pair<string, int>(buff, 0));
//	buff = to_string(first) + "41" + to_string(second);
//	population.push_back(pair<string, int>(buff, 0));
//	buff = to_string(first) + "06" + to_string(second);
//	population.push_back(pair<string, int>(buff, 0));
//	
//	
//	for (int k = 0; k < 100; k++){
//		
//		//////////////////////////////////////////////////////////
//		////2.Вычисляем для хромосом их пригодность(длину пути)///
//		//////////////////////////////////////////////////////////
//		for (int i = 0; i < population.size(); i++)
//		{
//			population[i].second = length_calc(population[i]);
//		}
//		cout << k + 1 << "population:\n";
//		for (int q = 0; q < population.size(); q++)
//		{
//			cout << population[q].first << " " << population[q].second << endl;
//			watch(population[q].second, min);
//		}
//		cout << "\n\n\n";
//
//		////////////////////////////////////////////////////////////////////
//		////3.Выбираем пару методом ИНБРИДИНГА(1-случайный,2-ближайший)/////
//		////////////////////////////////////////////////////////////////////
//		select_pair(pair_to_pop, population);
//
//		////////////////////////////////////////////////////////////
//		////4.проводим одноточечный кросинговер с парами хромосом///
//		////////////////////////////////////////////////////////////
//		crossing(pair_to_pop, population);
//
//		////////////////////////////////////
//		////5.Мутация(вставка+ удаление)////
//		////////////////////////////////////
//		Mutation(population);
//		for (int i = 0; i < population.size(); i++)
//		{
//			population[i].second = length_calc(population[i]);
//		}
//		////////////////////////////////////////////////
//		////6.Выборка нового покаления(метод усечки)////
//		////////////////////////////////////////////////
//		size_T = T*population.size();
//		vector<pair<string, int>> population1;
//		sort(population);
//		for (int i = 0; i < 4; i++)
//		{
//			rand_num = rand() % size_T;
//			population1.push_back(population[rand_num]);
//		}
//		population = population1;
//	}
//	///////////////////////////////////////////////////////////
//	////7.повтор 2-6 пока не будет достигнут критерий конца////
//	///////////////////////////////////////////////////////////
//	cout << "\n\n\n\n MIN length-" << min << endl;
//	system("pause");
//	return 0;
//}
int length_calc(pair<string, int> a)
{
	string way = a.first;
	string buff1,buff2;
	int res = 0;
	for (int i = 0; i < way.size() - 1; i++)
	{
		buff1 = way[i];
		buff2 = way[i+1];
		res += GRAF[stoi(buff1)][stoi(buff2)];
	}
	return res;
}
void select_pair(vector<pair<pair<string, int>, pair<string, int>>>& a, vector<pair<string, int>> population)
{
	srand(time(0));
	int rand_num;
	pair<pair<string, int>, pair<string, int>> buff;
	for (int i = 0; i < population.size(); i++)
	{
		rand_num = rand() % (population.size());//рандом от 0 до размера популяции;
		buff.first = population[rand_num];//первый родитель выбирается случайно, а второй явл ближайшим 
		buff.second = find_nearest(buff.first, population);
		a.push_back(buff);
	}
}
pair<string, int> find_nearest(pair<string, int> a, vector<pair<string, int>> population)
{
	bitset<3> bit;
	string str_bit,buff1,buff2;
	int min = 12,min_buff,min_int=0;
	for (int i = 0; i < a.first.size(); i++)
	{
		buff1 = a.first[i];
		bit = stoi(buff1);
		str_bit += bit.to_string();
	}
	for (int i = 0; i < population.size(); i++)
	{
		for (int j = 0; j < population[i].first.size(); j++)
		{
			if (population[i].first == a.first)
				break;
			buff1 = population[i].first[j];
			bit = stoi(buff1);
			buff2 += bit.to_string();
		}
		if (buff2.size()>0){
			min_buff = comp(str_bit, buff2);
			if (min_buff < min)
			{
				min = min_buff;
				min_int = i;
			}
		}
		buff2.clear();
	}
	return population[min_int];
}
int comp(string a, string b)
{
	int num = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			num++;
	}
	return num;
}
void crossing(vector<pair<pair<string, int>, pair<string, int>>> pop, vector<pair<string, int>>& population)
{
	srand(time(0));
	int rand_num;
	string str1, str2,buff1,buff2,buff3,buff4;
	bitset<3> bit;
	pair<string, int> buff;
	for (int i = 0; i < pop.size(); i++)
	{
		buff1 = pop[i].first.first;
		buff2 = pop[i].second.first;
		for (int j = 0; j < buff1.size(); j++)
		{
			buff3 = buff1[j];
			buff4 = buff2[j];
			bit = stoi(buff3);
			str1 += bit.to_string();
			bit = stoi(buff4);
			str2 += bit.to_string();
		}

		while (1){
			rand_num = rand() % (str1.size() - 4);
			if (rand_num > 2)
				break;
		}
		shake(rand_num, str1, str2);
		bit_to_int(str1);
		bit_to_int(str2);
		population.push_back(pair<string, int>(str1, 0));
		population.push_back(pair<string, int>(str2, 0));
		str1.clear();
		str2.clear();
	}
}
void shake(int num, string& a, string& b)
{
	string buff1, buff2;
	char c;
	for (int i = 0; i < a.size(); i++)
	{
		if (i <= num)
		{
			c = a[i];
			a[i] = b[i];
			b[i] = c;
		}
	}
}
void bit_to_int( string& str)
{
	bitset<3> bit;
	string buff,res;
	for (int i = 0; i < str.size(); i++)
	{
		buff += str[i];
		if (i % 3 == 2)
		{
			for (int j = 0; j < buff.size(); j++)
			{
				if (buff[j] == '1')
					bit.set(2 - j);
			}
			res += to_string(bit.to_ulong());
			bit.reset();
			buff.clear();
		}
	}
	str = res;
}
void Mutation(vector<pair<string, int>>& population)
{
	int rand_num;
	srand(time(0));
	for (int i = 0; i < population.size(); i++)
	{
		if (population[i].second != 0)
			continue;
		rand_num = rand() % 100;
		if (rand_num < 60)
		{
			population[i] = in_pl_del(population[i]);
		}
	}
}
pair<string, int> in_pl_del(pair<string, int> a)
{
	srand(time(0));
	int rand_num_inp, rand_num_del, rand_bit;
	string buff1,str_bit;
	bitset<3> bit;

	for (int i = 0; i < a.first.size(); i++)
	{
		buff1 = a.first[i];
		bit = stoi(buff1);
		str_bit += bit.to_string();
	}
	while (1){
		rand_num_inp = rand() % (str_bit.size()-3);
		if (rand_num_inp>2)
			break;
	}
	while (1){
		rand_num_del = rand() % (str_bit.size() - 3);
		if (rand_num_del>2)
			break;
	}
	
	//input
	str_bit += "0";
	for (int i = str_bit.size()-1; i>rand_num_inp; i--)
	{
		str_bit[i] = str_bit[i - 1];
	}
	rand_bit = rand() % 2;
	if (rand_bit==1)
	str_bit[rand_num_inp] = '1';
	else
		str_bit[rand_num_inp] = '0';
	//////
	////delete

	for (int i = rand_num_del; i < str_bit.size()-1; i++)
	{
		str_bit[i] = str_bit[i + 1];
	}
	bit_to_int(str_bit);

	return pair<string, int>(str_bit, 0);
}
void sort(vector<pair<string, int>>& population)
{
	pair<string, int> buff;
	for (int i = 0; i < population.size(); i++) 
	{            
		for (int j = population.size() - 1; j > i; j--) 
		{   
			if (population[j - 1].second > population[j].second) 
			{
				buff = population[j - 1];
				population[j - 1] = population[j];
				population[j] = buff;
			}
		}
	}
}
void watch(int a, int& min)
{
	if (a < min)
		min = a;
}