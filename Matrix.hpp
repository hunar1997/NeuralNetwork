#pragma once

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<double> Row;
typedef vector<Row> Matrix;

int matrix_random_seed = time(nullptr);

void set_matrix_random_seed(int seed=matrix_random_seed){
	srand(seed);
}

enum creation_type {
	all_zeros,
	all_ones,
	random_values
};

Matrix create_matrix(int rows, int cols, creation_type c_type=random_values){
	
	Matrix new_matrix;
	
	for (int r=0; r<rows; r++)
	{
		Row this_row;
		for (int c=0; c<cols; c++)
		{
			if (c_type==all_ones)
				this_row.push_back(1);
			else if(c_type==all_zeros)
				this_row.push_back(0);
			else
				this_row.push_back( (rand()%100)/10.0-5 );
		}
		new_matrix.push_back(this_row);
	}
	return new_matrix;
}

Matrix operator *(Matrix &m1, Matrix &m2){
	Matrix new_matrix = create_matrix(m1.size(), m2[0].size());
	for (unsigned j=0; j<new_matrix.size(); j++){
		for (unsigned i=0; i<new_matrix[0].size(); i++){
			double sum = 0;
			for (unsigned k=0; k<m2.size(); k++){
				sum += m1[j][k] * m2[k][i];
			}
			new_matrix[j][i] = sum;
		}
	}
	return new_matrix;
}

Matrix operator *(Matrix &m, double n){
	Matrix new_matrix = create_matrix(m.size(), m[0].size());
	for (unsigned j=0; j<new_matrix.size(); j++){
		for (unsigned i=0; i<new_matrix[0].size(); i++){
			new_matrix[j][i] = m[j][i] * n;
		}
	}
	return new_matrix;
}

Matrix operator -(Matrix &m1, Matrix &m2){
	Matrix new_matrix = create_matrix(m1.size(), m1[0].size());
	for (unsigned j=0; j<new_matrix.size(); j++){
		for (unsigned i=0; i<new_matrix[0].size(); i++){
			new_matrix[j][i] = m1[j][i] - m2[j][i];
		}
	}
	return new_matrix;
}

Matrix apply_function(Matrix &m, double(*function)(double)){
	Matrix new_matrix = create_matrix(m.size(), m[0].size());
	for (unsigned j=0; j<m.size(); j++)
		for (unsigned i=0; i<m[0].size(); i++)
			new_matrix[j][i] = function(m[j][i]);
	return new_matrix;
}

void print_matrix(Matrix m, string name="Matrix"){
	printf("%s:\n", name.c_str());
	for (auto j:m){
		printf("\t");
		for (auto i:j){
			printf("%-4.1f ", i);
		}
		printf("\n");
	}
}

