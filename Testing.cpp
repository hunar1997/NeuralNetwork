#include <iostream>
#include "NN.hpp"

using namespace std;

double tw(double n){
	return n*3;
}

int main()
{
	vector<Matrix> input_data{
		{
			{1},
			{1}
		},
		{
			{1},
			{0}
		},
		{
			{0},
			{1}
		},
		{
			{0},
			{0}
		}
	};
	vector<Matrix> output_data{
		{
			{0}
		},
		{
			{1}
		},
		{
			{1}
		},
		{
			{0}
		},
	};
	
	NN a( {2,3,1} );
	
	Matrix result = a.feed_forward(input_data[0]);
	print_matrix(a.weights_list[0],"first weights");
	print_matrix(a.weights_list[1],"second weights");
	print_matrix(a.network[1], "first hidden");
	print_matrix(result,"result");
	Matrix err = output_data[0]-result;
	print_matrix(err, "Error");
	
	return 0;
}