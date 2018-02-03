#pragma once

#include <iostream>
#include <cmath>
#include "Matrix.hpp"

using namespace std;

typedef vector<unsigned> Topology;
typedef Matrix Layer;
typedef vector<Layer> Network;
typedef Matrix Weights;
typedef Network WeightsList;

double sigmoid(double x){
	return 1/(1+exp(-x));
}
double anti_sigmoid(double x){
	return exp(-x)/pow( 1+exp(-x), 2);
}


class NN
{
public:
	Topology topology;
	Network network;
	WeightsList weights_list;
	
	double (*activate)(double) = &sigmoid;
	double (*anti_activate)(double) = &anti_sigmoid;
	
	NN(Topology topology):topology(topology)
	{
		set_matrix_random_seed();	// nothing means random seed
		
		for (unsigned l=0; l<topology.size(); l++){
			Layer this_layer = create_matrix(topology[l], 1, all_zeros);
			network.push_back(this_layer);
			
			if (l!=topology.size()-1){
				weights_list.push_back(create_matrix(topology[l+1], topology[l]));
			}
		}
	}
	Matrix feed_forward(Matrix input){
		network[0] = input;
		for (unsigned l=1; l<network.size(); l++){
			network[l] = weights_list[l-1] * network[l-1];
			network[l] = apply_function(network[l], activate);
		}
		return network.back();
	}
};

