#pragma once

#include <cmath>

namespace DeltaRule {

	constexpr double ALPHA = 0.05;

	template<int N>
	class Sample
	{
	protected:
		double * sample;
	public:
		Sample()
			: sample(new double[N])
		{
			for (int i = 0; i < N; i++)
			{
				sample[i] = 0;
			}
		}
		Sample(double * sample)
			: sample(new double[N])
		{
			for (int i = 0; i < N; i++)
				this->sample[i] = sample[i];
		}
		double& operator[](const int id) const
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
				std::cout << "double& Sample::operator[](const int) const\n"
					<< "Error - " << e << std::endl;
				system("pause");
				exit(0);
			}
		}
	};
	template<int N>
	class TrainingSample : public Sample<N>
	{
		double res;
	public:
		TrainingSample()
			: Sample<N>(), res(0) {}
		TrainingSample(double * sample, double result)
			: Sample<N>(sample), res(result) {}
		double& result()
		{
			return res;
		}
	};
	/*
	template<int N, int Nres = N>
	class TSampleMultRes : public Sample<N>
	{
		double res[Nres];
	public:
		TSampleMultRes()
			: Sample<N>()
		{
			for (double & el : res)
				el = 0;
		}
		TSampleMultRes(double * sample, double * result)
			: Sample<N>(sample)
		{
			for (int i = 0; i < Nres; i++)
				res[i] = result[i];
		}
		double& result(const int id)
		{
			try
			{
				if (id < 0)
					throw 1;
				if (id >= Nres)
					throw 2;
				return res[id];
			}
			catch (int e)
			{
				std::cout << "double& Sample::operator[](const int) const\n"
					<< "Error - " << e << std::endl;
				system("pause");
				exit(0);
			}
		}
	};

	template<int SIZE>
	struct NetResult
	{
		double res[SIZE];
	};*/

	template<int N>
	class Net
	{
		double W[N];
		double T;
	public:
		Net()
		{
			for (int i = 0; i < N; i++)
			{
				W[i] = (double)(rand() % 1001);
				W[i] /= 100.0;
			}
			T = ((double)(rand() % 1001 + 10));
			T /= 100.0;
		}
		double training(TrainingSample<N>& sample)
		{
			double y = process(sample);
			double t = sample.result();
			for (int j = 0; j < N; j++)
			{
				W[j] -= ALPHA * (y - t) * sample[j];
			}
			T += ALPHA * (y - t);
			return y - t;
		}

		/*double training_demo(TSampleMultRes<N> samples)
		{
			double y[3];
			for (int i = 0; i < 3; i++)
				y[i] = process(samples[i]);
			double t[3];
			for (int i = 0; i < 3; i++)
				t[i] = samples[i].result();

			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					W[j] -= ALPHA * (y[k] - t[k]) * samples[k][j];
					T[j] += ALPHA * (y[k] - t[k]);
				}
			}

			double E = 0;
			for (int k = 0; k < 3; k++)
				E += pow(y[k] - t[k], 2.0);
			E /= 2;
			return E;
		}

		NetResult<N> process_demo(Sample<N>& sample)
		{
			NetResult<N> res;
			for (int i = 0; i < N; i++)
			{

			}
		}*/

		double process(Sample<N>& sample)
		{
			double res = 0;
			for (int i = 0; i < N; i++)
			{
				res += W[i] * sample[i];
			}
			res -= T;
			return res;
		}
	};

} // DeltaRule