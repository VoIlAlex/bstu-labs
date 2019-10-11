#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <thread>
#include <mutex>
#include <array>
#include <chrono>

const int N = 50;

void fillRand(const std::string& filename, int numOfBlocks)
{
	std::ofstream stream(filename, std::ios::out | std::ios::ate);
	if (!stream)
	{
		std::cerr << "Cannot open the file! (" << filename.c_str() << ")" << std::endl;
		return;
	}
	stream.clear();
	srand(time(0));
	while (numOfBlocks--)
	{
		for (int j = 0; j < N; j++)
			stream << rand() % 50 << ((j != N - 1) ? " " : "");
		if (numOfBlocks != 0)stream << "\n";
	}
	stream.close();
}
void clear(std::string filename)
{
	std::ofstream stream(filename);
	if (!stream)
	{
		std::cerr << "Cannot open the file! (" << filename.c_str() << ")" << std::endl;
		return;
	}
	stream.clear();
	stream.close();
}

struct PrResult
{
	int min;
	int max;
	double average;
};

enum ThreadQueue
{
	READ = 0,
	PROCESS,
	WRITE
};

int strToInt(std::string str)
{
	int res = 0;
	for (int i = 0; i < str.length(); i++)
	{
		res += (str[i] - 48) * pow(10, str.length() - i - 1);
	}
	return res;
}

bool proc = true;

void read(std::ifstream& stream, int arr[N], ThreadQueue& q)
{
	bool toBreak = false;
	while (!toBreak)
	{
		while (q != READ) std::this_thread::sleep_for(std::chrono::microseconds(10));
		toBreak = false;
		for (int i = 0; i < N; i++)
		{
			std::string str;
			while (true)
			{
				char ch;
				stream.read(&ch, sizeof(char));
				if (stream.eof())
				{
					toBreak = true;
					proc = false;
					break;
				}
				if (ch == '\n')
				{
					break;
				}
				else if (ch == ' ')
				{
					break;
				}
				else if (ch < 48 || ch > 57 && ch != ' ')
				{
					std::cerr << "Error. Unexpected character \"" << ch << "\"!" << std::endl;
					toBreak = true;
					break;
				}
				str += ch;
			}
			arr[i] = strToInt(str);
			q = PROCESS;
		}
	}
}
void write(std::ofstream& stream, int arr[N], PrResult &result, ThreadQueue& q)
{
	while (proc)
	{
		while (q != WRITE) std::this_thread::sleep_for(std::chrono::microseconds(10));
		for (int i = 0; i < N; i++)
		{
			if (i % 10 == 0)
				stream << '\n';
			else
				stream << ' ';
			stream << arr[i];
		}
		stream << std::endl << "Min - " << result.min << std::endl;
		stream << "Max - " << result.max << std::endl;
		stream << "Average - " << result.average << std::endl;
		q = READ;
	}
}
void process(int arr[N], PrResult &result, ThreadQueue& q)
{
	while (proc)
	{
		while (q != PROCESS) std::this_thread::sleep_for(std::chrono::microseconds(10));
		result.min = arr[0];
		result.max = arr[0];
		result.average = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] < result.min)
				result.min = arr[i];
			if (arr[i] > result.max)
				result.max = arr[i];
			result.average += arr[i];
		}
		result.average /= N;
		q = WRITE;

	}
}

int main()
{
	clear("res/2.txt");
	int arr[N];
	PrResult res;
	ThreadQueue q = READ;
	fillRand("res/1.txt", 4);
	std::ofstream out("res/2.txt");
	std::ifstream in("res/1.txt");

	std::thread readThread(read, std::ref(in), arr, std::ref(q));
	std::thread processThread(process, arr, std::ref(res), std::ref(q));
	std::thread writeThread(write, std::ref(out), arr, std::ref(res), std::ref(q));

	readThread.join();
	processThread.join();
	writeThread.join();

	out.close();
	in.close();

	std::cin.get();
	return 0;
}