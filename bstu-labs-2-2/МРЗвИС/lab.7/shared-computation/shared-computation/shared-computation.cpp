#include "pch.h"
#include <iostream>
#include <exception>
#include <math.h>
#include <utility>
#include <thread>
#include <random>
#include <functional>
#include <mutex>

using namespace std;
using namespace std::chrono_literals;

std::mutex g_mtx_cout;

class Server {
	std::vector<vector<int>> m_shared_memory;
	std::vector<int> m_shared_indexes;
	std::vector<vector<int>> m_population;
	int &m_notification_variable;
	bool m_trace;
public:
	Server(int &notification_variable, int population_size, int shared_memory_size, bool trace = true)
		: m_shared_memory(shared_memory_size),
		m_shared_indexes(shared_memory_size),
		m_population(population_size),
		m_notification_variable(notification_variable),
		m_trace(trace) {
		populationInit();
		sharedMemoryInit();
	}

	/*
	 *  Main processing is done here
	 */
	void operator()() {
		// Get values from shared_memory
		getSharedMemory();

		///////////////////////////////////
		// One epoch is processed here
		// ...
		///////////////////////////////////

		// fill population that will 
		// be processed on the server
		setSharedMemory();

		// says that it's done and
		// visualize the date if required
		m_notification_variable++;
		if (m_trace)
		{
			lock_guard<std::mutex> lck(g_mtx_cout);
			std::cout << *this << std::endl;
		}
	}
	vector<vector<int>> &sharedMemory() {
		return m_shared_memory;
	}
	friend std::ostream& operator << (std::ostream& stream, const Server& s);
private:
	void getSharedMemory()
	{
		// replace population entities with 
		// new elements come from net
		for (int i = 0; i < m_shared_memory.size(); i++)
			m_population[m_shared_indexes[i]] = m_shared_memory[i];
	}
	void setSharedMemory()
	{
		// get random indexes
		vector<int> idx;
		std::uniform_int_distribution<> distr{ 0,  static_cast<int>(m_population.size() - 1) };
		auto gen = bind(distr, default_random_engine(clock()));
		while (idx.size() != m_shared_memory.size())
		{
			int i = gen();
			if (find(idx.begin(), idx.end(), i) != idx.end())
				continue;
			idx.push_back(i);
		}

		for (int i = 0; i < idx.size(); i++)
			m_shared_memory[i] = m_population[idx[i]];
		m_shared_indexes = idx;
	}
	void sharedMemoryInit()
	{
		for (int i = 0; i < m_shared_memory.size(); i++)
		{
			m_shared_memory[i] = m_population[i];
			m_shared_indexes[i] = i;
		}
	}
	void populationInit()
	{
		std::uniform_int_distribution<> distr{ 0, 10 };
		auto gen = bind(distr, default_random_engine(clock()));
		for (auto& one : m_population)
			for (int i = 0; i < 10; i++)
				one.push_back(gen());
	}
};

std::ostream& operator << (std::ostream& stream, const Server& s)
{
	stream << "---- Server info ----" << std::endl;
	stream << "Population: " << std::endl; 
	for (auto& x : s.m_population)
	{
		for (auto& y : x)
			stream << y << " ";
		std::cout << std::endl;
	}
	stream << std::endl;
	stream << "Shared memory: ";
	for (auto& x : s.m_shared_memory)
	{
		for (auto& y : x)
			stream << y << " ";
		std::cout << std::endl;
	}
	return stream;
}

class Net {
	// matrix of sockets
	vector<vector<Server>> m_matrix;
	int m_size_1;
	int m_size_2;
	int m_total_size;
	int m_exchange_number;
	int m_notification_variable;
public:
	Net(int servers_number, int population_size, int exchange_number = 1)
		: m_exchange_number(exchange_number) {
		init(servers_number, population_size, exchange_number);
		while (true) {
			runServers();
			shuffleSharedMemories();
		}
	}

private:
	pair<int, int> factorization(int number) {
		int cur = static_cast<int>(sqrt(number));
		for (; cur > 1; cur--)
			if (number % cur == 0)
				break;
		return { cur, number / cur };
	}
	void init(int servers_number, int population_size, int exchange_number) {
		m_total_size = servers_number;
		pair<int, int> sizes = factorization(servers_number);
		m_size_1 = sizes.first;
		m_size_2 = sizes.second;
		m_matrix.resize(m_size_1);
		for (int i = 0; i < m_size_1; i++)
			for (int j = 0; j < m_size_2; j++)
				m_matrix[i].push_back(Server{ m_notification_variable, population_size, exchange_number});
	}
	void runServers() {
		vector<thread> threads;
		for (int i = 0; i < m_size_1; i++)
			for (int j = 0; j < m_size_2; j++)
				threads.emplace_back(thread{ m_matrix[i][j] });
		for (auto& thread : threads)
			thread.join();
	}
	void shuffleSharedMemories() {
		std::uniform_int_distribution<> distr_1{ 0, m_size_1 - 1 };
		std::uniform_int_distribution<> distr_2{ 0, m_size_2 - 1 };
		std::uniform_int_distribution<> distr_3{ 0, 3 };
		auto gen_x = bind(distr_1, default_random_engine(clock()));
		auto gen_y = bind(distr_2, default_random_engine(clock()));
		auto gen_direction = bind(distr_3, default_random_engine(clock()));

		// 10 exchanges
		for (int i = 0; i < 10; i++) {
			int i_x1 = gen_x(); // indexes of
			int i_y1 = gen_y(); // first instance

			int direction = gen_direction();

			int i_x2 = i_x1, i_y2 = i_y1;

			switch (direction) {
			case 0: // up
				i_y2--;
				if (i_y2 == -1)
					i_y2 = m_size_2 - 1;
				break;
			case 1: // right
				i_x2++;
				if (i_x2 == m_size_1)
					i_x2 = 0;
				break;
			case 2: // bottom
				i_y2++;
				if (i_y2 == m_size_2)
					i_y2 = 0;
				break;
			case 3: // left
				i_x2--;
				if (i_x2 == -1)
					i_x2 = m_size_1 - 1;
				break;
			default:
				break;
			}
			//swapTwoMemories(m_matrix[i_x1][i_y1].sharedMemory(), m_matrix[i_x2][i_y2].sharedMemory());
		}
	}
	/*static void swapTwoMemories(vector<int> &first, vector<int> &second) {
		vector<int> temp = move(first);
		first = second;
		second = first;
	}*/
	void swapTwoMemories(pair<int, int> a, pair<int, int> b)
	{
		auto x = move(m_matrix[a.first][a.second].sharedMemory());
		m_matrix[a.first][a.second].sharedMemory() = m_matrix[b.first][b.second].sharedMemory();
		m_matrix[b.first][b.second].sharedMemory() = move(x);
	}
};


int main() {
	Net net{ 4, 10 };
	return 0;
}