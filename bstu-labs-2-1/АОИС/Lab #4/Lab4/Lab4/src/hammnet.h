#pragma once
#include "nnet.h"

namespace HammingNetwork
{
	template<int N, int SIZE_OF_SET>
	class HNet
	{
		const double e;
		double W[N][SIZE_OF_SET];
		int numOfNeurones;
		double T[SIZE_OF_SET];
		double V[SIZE_OF_SET][SIZE_OF_SET];
	public:
		HNet(Net::SampleSet<N, SIZE_OF_SET> samples)
			: e(1.0/N - 1.0/(10.0*N)), numOfNeurones(N)
		{
			for(int j = 0; j < SIZE_OF_SET; j++)
			{
				for(int i = 0; i < numOfNeurones; i++)
					W[i][j] = samples[j][i] / 2.0;
				T[j] = - N/2.0;
			}
			for(int j = 0; j < SIZE_OF_SET; j++)
				for(int k = 0; k < SIZE_OF_SET; k++)
					V[j][k] = (j == k)?(1):(-e);
		}
		double F(double S)
		{
			if(S > 0)
				return S;
			else 
				return 0;
		}
		void process(Net::Sample<N>& sample, std::vector<int>& result)
		{
			double P[SIZE_OF_SET];
			for(int j = 0; j < SIZE_OF_SET; j++)
			{				
				P[j] = 0;
				for(int i = 0; i < N; i++)
					P[j]+=W[i][j]*sample[i];
				P[j] -= T[j];
			}
			double Z[SIZE_OF_SET];
			for(int k = 0; k < SIZE_OF_SET; k++)
			{
				Z[k] = 0;
				for(int j = 0; j < SIZE_OF_SET; j++)
					Z[k] += V[j][k]*P[j];
			}
			double S[SIZE_OF_SET]; 
			while(1)
			{
				for(int i = 0; i < SIZE_OF_SET; i++)
					S[i] = Z[i];
				for(int k = 0; k < SIZE_OF_SET; k++)
				{
					for(int j = 0; j < SIZE_OF_SET; j++)
						Z[k]+=V[j][k]*S[j];
					Z[k] = F(Z[k]);
				}
				bool isDif = false; // is last Z different to current Z
				for(int i = 0; i < SIZE_OF_SET; i++)
					if(S[i] != Z[i])
					{
						isDif = true;
						break;
					}
				if(!isDif)
				{
					for(int i = 0; i < SIZE_OF_SET; i++)
						result[i] = (Z[i]!=0)?(1):(0);
					return;
				}
			}
		}
	};
}