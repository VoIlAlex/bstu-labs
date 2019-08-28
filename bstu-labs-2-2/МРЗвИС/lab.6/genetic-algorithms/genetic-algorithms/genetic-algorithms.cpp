#include "pch.h"
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <string>
#include <algorithm>
#include <time.h>
#include <Windows.h>

using namespace std;
class Paths
{
private:
	vector<vector<double>> m_paths;
public:
	Paths(int size)
		: m_paths(size)
	{
		// resize matrix
		for (int i = 0; i < size; i++)
			m_paths[i].resize(size);
	

		std::uniform_real_distribution<double> distr{ 0.0, 100.0 };
		std::default_random_engine gen;
		Sleep(13);
		gen.seed(clock());
		auto distr_gen = std::bind(distr, gen);

		for (int i = 0; i < size; i++)
			for (int j = i; j < size; j++)
				m_paths[i][j] = m_paths[j][i] = distr_gen();
	}

	double& operator[](const pair<int, int>& idx)
	{
		return m_paths[idx.first][idx.second];
	}

	void Show()
	{
		std::cout << "Paths matrix: " << std::endl;
		for (int i = 0; i < m_paths.size(); i++)
		{
			for (int j = 0; j < m_paths[i].size(); j++)
				printf("%6.2f ", m_paths[i][j]);
			std::cout << std::endl;
		}
	}

	double ObjectiveFunction(std::vector<int> path)
	{
		double result = 0;
		for (int i = 1; i < path.size(); i++)
			result += m_paths[path[i - 1]][path[i]];
		return result;
	}
	
	std::vector<int> generateRandomPath(int size = -1, int begin=-1, int end=-1)
	{
		if (begin == -1) begin = 0;
		if (end == -1) end = m_paths.size() - 1;
		if (size == -1) size = m_paths.size();

		std::uniform_int_distribution<int> distr{ 0, static_cast<int>(m_paths.size() - 1) };
		std::default_random_engine gen;
		Sleep(13);
		gen.seed(clock());
		auto distr_gen = std::bind(distr, gen);

		std::vector<int> randomPath {begin};
		for (int i = 0; i < size - 2; i++)
			randomPath.push_back(distr_gen());
		randomPath.push_back(end);
		return randomPath;
	}

	static void ViewPath(const std::vector<int>& path, const std::string& caption = "", std::string end="\n")
	{
		if (caption != "") 
			std::cout << caption << ": " << std::endl;
		for (int i = 0; i < path.size(); i++)
		{
			if (i) std::cout << " -> ";
			std::cout << path[i];
		}
		std::cout << std::endl;
	}


};




int main()
{
	constexpr int numberOfServers = 10;
	constexpr int begin = 0, end = 5; // arbitrary 
	Paths p(numberOfServers);
	p.Show();

	// generation of population
	constexpr int populationSize = 10;
	vector<vector<int>> population(populationSize);
	std::for_each(population.begin(), population.end(), [&](auto& gen) {
		gen = p.generateRandomPath(numberOfServers, begin, end);
	});

	std::for_each(population.begin(), population.end(), [&](auto& gen) {
		Paths::ViewPath(gen, "", " ");
		std::cout << "Objective function: " << p.ObjectiveFunction(gen) << std::endl;
		
	});

	
	Paths::ViewPath(p.generateRandomPath(0, 3, 10), "Random path");
	system("pause");
}
