#pragma once
#include <iostream>
#include <vector>

namespace Net
{
	template<int N>
	class Sample
	{
		std::vector<int> sample;
	public:
		Sample()
			: sample(N)
		{
			for (int i = 0; i < N; i++)
				sample[i] = -1;
		}
		Sample(int sample[N])
			: sample(N)
		{
			for (int i = 0; i < N; i++)
				this->sample.push_back(sample[i]);
		}
		Sample(std::initializer_list<int> list)
			: sample(N)
		{
			int i = 0;
			for (int x : list)
				if (i < N)
					sample[i++] = (2*x - 1);
			for (; i < N; i++)
				sample[i] = -1;

		}


		int& operator[](const int id)
		{
			try
			{
				if (id < 0)
					throw 1;
				if (id >= N)
					throw 2;
				return sample[id];
			}
			catch (int e)
			{
				std::cout << "int& HopfieldNetwork::Sample::operator[](const int id)\n"
					<< "Error - " << e << std::endl;
				system("pause");
				exit(0);
			}
		}
		bool operator==(const Sample<N>& other) const
		{
			for (int i = 0; i < N; i++)
				if (sample[i] != other.sample[i])
					return false;
			return true;
		}

		Sample& operator=(const Sample<N>& other)
		{
			for (int i = 0; i < N; i++)
				this->sample[i] = other.sample[i];
			return (*this);
		}

		int size() const
		{
			return N;
		}

		void view(const std::string& message = "\0", const int tab = 0)
		{
			if (message != "\0")
				std::cout << message.c_str() << ": ";
			for (int i = 0; i < tab; i++)
				std::cout << "\t";
			for (int i = 0; i < N; i++)
				std::cout << sample[i] << " ";
			std::cout << std::endl;
		}
	};

	template<int N, int SIZE_OF_SET>
	class SampleSet
	{
		std::vector<Sample<N>> samples;
	public:
		SampleSet(Sample<N> samples[SIZE_OF_SET])
			: samples(SIZE_OF_SET)
		{
			for (int i = 0; i < SIZE_OF_SET; i++)
				for (int j = 0; j < N; j++)
				{
					this->samples[i][j] = samples[i][j];
				}
		}
		SampleSet(std::initializer_list<Sample<N>> list)
			: samples(SIZE_OF_SET)
		{
			int i = 0;
			for (Sample<N> x : list)
				if (i < SIZE_OF_SET)
					samples[i++] = x;
			for (; i < SIZE_OF_SET; i++)
				samples[i] = Sample<N>();
		}
		Sample<N>& operator[](const int id)
		{
			try
			{
				if (id < 0)
					throw 1;
				if (id >= SIZE_OF_SET)
					throw 2;

				return samples[id];
			}
			catch (int e)
			{
				std::cout << "Sample& HopfieldNetwork::SampleSet::operator[](const int id)\n"
					<< "Error - " << e << std::endl;
				system("pause");
				exit(0);
			}
		}
	};
}