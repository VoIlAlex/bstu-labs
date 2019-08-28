#pragma once
#include <iostream>
#include <vector>

namespace HopfieldNetwork
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
				if(i<N)
					sample[i++] = x;
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
			if(message!="\0")
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
	template<int N, int SIZE_OF_SET>
	class Net
	{
		int W[N][N];
		int T[N];
	public:
		Net(SampleSet<N, SIZE_OF_SET> samples)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					W[i][j] = 0;
					for (int k = 0; k < SIZE_OF_SET; k++)
					{
						if (i == j)
						{
							break;
						}
						W[i][j] += (2 * samples[k][i] - 1)*(2 * samples[k][j] - 1);
					}
				}
			}
			for (int j = 0; j < N; j++)
			{
				T[j] = 0;
				for (int k = 0; k < SIZE_OF_SET; k++)
				{
					T[j] -= (2 * samples[k][j] - 1);
				}
			}
		}
		int F(int S)
		{
			if (S > 0)
				return 1;
			else
				return 0; //
		}
		void process(Sample<N>& input)
		{
			int numOfIter = 0;
			
				Sample<N> last = input;
				do
				{
					numOfIter++;
					last = input;
#ifdef SYNCH
					Sample<N> copy = input;
#endif
					for (int i = 0; i < N; i++)
					{
						int S = 0;
						for (int j = 0; j < N; j++)
							S += W[j][i] * input[j]; 
						S -= T[i];
#ifdef SYNCH
						copy[i] = F(S);
#else
						input[i] = F(S);
#endif
					}
#ifdef SYNCH
					input = copy;
#endif
				} while (!(last == input));
				std::cout << "Number of iteration: " << numOfIter << std::endl;
		}
	};
}