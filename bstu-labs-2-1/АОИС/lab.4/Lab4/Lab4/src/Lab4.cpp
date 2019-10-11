#include <iostream>
#include <algorithm>
#include <vector>
#include "hammnet.h"
#include "nnet.h"

#define endl std::cout << std::endl
#define out(a) std::for_each(a.begin(), a.end(), [](int i) {std::cout << i << " "; })
#define proc(a) net.process(a, test_result)


void swap(std::vector<int>& a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool nextSet(std::vector<int>& a, int n, int m)
{
	int j;
	do  // повторяем пока не будет найдено следующее размещение
	{
		j = n - 2;
		while (j != -1 && a[j] >= a[j + 1])
		{
			j--;
		}
		if (j == -1)
			return false; // больше размещений нет
		int k = n - 1;
		while (a[j] >= a[k]) k--;
		swap(a, j, k);
		int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
		while (l < r)
			swap(a, l++, r--);
	} while (j > m - 1);
	return true;
}

template<int N, int NUM_OF_SAMPLES>
int numOfWrongBits(Net::Sample<N> sample, HammingNetwork::HNet<N, NUM_OF_SAMPLES> net, int numOfSample)
{
	int num = N;
	while (num != 0)
	{
		Net::Sample<N> sample_copy = sample;
		std::vector<int> mask(N);
		for (int i = 0; i < N; i++)
			mask[i] = i;
		bool ok = true;
		do
		{

			for (int i = 0; i < num; i++)
				sample_copy[mask[i]] = (sample_copy[mask[i]] + 1)%2;
			std::vector<int> res(N);
			net.process(sample_copy, res);
			if (!res[numOfSample])
			{
				ok = false;
				break;
			}
			sample_copy = sample;

		} while (nextSet(mask, N, num));
		if (ok)
			break;
		num--;
	}
	return num;
}

int main()
{
	constexpr int N = 15;
	constexpr int NUM_OF_SAMPLES = 4;
	typedef Net::Sample<N> Sample;
	typedef Net::SampleSet<N, NUM_OF_SAMPLES> SampleSet;
	typedef HammingNetwork::HNet<N, NUM_OF_SAMPLES> Net;

	Sample s4 = { 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 };
	Sample s11 = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 };
	Sample s8 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1 };
	Sample s7 = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	SampleSet set = { s4, s11, s8, s7 };
	Net net(set);

	std::vector<int> test_result(NUM_OF_SAMPLES);

	proc(s4);
	out(test_result);
	endl;

	proc(s11);
	out(test_result);
	endl;

	proc(s8);
	out(test_result);
	endl;

	proc(s7);
	out(test_result);
	endl;

	Sample test = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };

	proc(test);
	out(test_result);
	endl;

	/*std::cout << numOfWrongBits({ 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 }, net, 0); endl;
	std::cout << numOfWrongBits({ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }, net, 1); endl;
	std::cout << numOfWrongBits({ 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1 }, net, 2); endl;
	std::cout << numOfWrongBits({ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 }, net, 3); endl;*/



	std::cin.get();
}
