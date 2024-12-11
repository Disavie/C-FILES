#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "operations.hpp"




//ECE specific functions
std::string parallel(double r1, double r2){
	return  std::to_string((r1*r2)/(r1+r2));
}

std::string cur_div(double Is, double r1, double r2){
	double numerator = 1/r1;
	double denom = (1/r1)+(1/r2);
	return std::to_string(Is*numerator/denom);
}

std::string volt_div(double Vs, double r1, double r2){

	return std::to_string(Vs*((r1)/(r1+r2)));
}



std::string mesh_current(int size, double last){
	std::cout << "Form matrix A" << std::endl;
	auto A = formMatrix(size,size, last);

	std::cout << "Form matrix B" << std::endl;
	auto B = formMatrix(size,1, last);

	std::vector<double> x = solveAxB(A,B);
	std::string output = "[";
	for(double d : x){
		output+=std::to_string(d)+',';

	}
	output+=']';
	return output;
}
//SOLVING THIS MATRIX AS FORM Ax = C
//C = 1xN
//x = NxN
//A = 1xN
//		Determinant of 2x2 = [a,b][c,d] = ad-bc
// 		Determinant of 3x3 = [a,b,c][d,e,f][g,h,i] = (-1)^(n+1)det(A_n1) + (-1)^(n+1+1)det(A_n+1,1) ...
std::vector<std::vector<double>> formMatrix(int rows,int cols, double last){
	
	std::string input; 
	std::vector<std::string> inputs ;
	std::vector<std::vector<double>> matrix;
	double value;
	for(int i = 0 ; i < rows; i++){
		std::cout << "For row #" << i+1 << " provide " << cols << " entries" << std::endl;
		std::getline(std::cin,input);
		inputs = parseInput(input);
		matrix.push_back({});
		for(int j = 0; j < cols; j++){
			value = evaluateExpression(inputs[j],last);
			matrix[i].push_back(value);
		}

	}
	return matrix;
}

std::vector<double> solveAxB(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B){

	int sidelength = A.size();
	std::vector<double> results;

	/* Given a b c		x		x_1
			 d e f = A  y = B 	x_2 = X
			 g h i		z		x_3
			
			x_1 = det(A_1)/det(A)					x b c
			x_2 = det(A-2/det(A) 		where A_1 = y e f
			x_3 = det(A_3)/det(A)					z h i

	*/			
	double detA = largeDeterminant(A);	
	for(int n = 0; n < sidelength ; n++){
		std::vector<std::vector<double>> A_i = A;
		for(int i = 0 ; i < sidelength; i ++){
			A_i[i][n] = B[i][0];
		}
		double res = largeDeterminant(A_i)/detA;
		results.push_back(res);
	}
	return results;
}


double largeDeterminant(std::vector<std::vector<double>> matrix){

	double runningDeterminant = 0.0;
	double temp;
	if(static_cast<int>(matrix.size()) == 2){
	//	std::cout << "HERE" << std::endl;
		runningDeterminant+=smallDeterminant(matrix);
		return runningDeterminant;
	}else if(static_cast<int>(matrix.size()) <= 3){
		for(int i = 0 ; i < static_cast<int>(matrix.size());i++){
			temp = matrix[i][0] * cofactor(i+1,1)*smallDeterminant(mMinor(matrix,i,0));
			runningDeterminant+=temp;
		}
		return runningDeterminant;
	}
	for(int i=0; i < static_cast<int>(matrix.size()) ; i++){

		temp = matrix[i][0] * cofactor(i+1,1)*largeDeterminant(mMinor(matrix,i,0));
		runningDeterminant+=temp;
	}
	return runningDeterminant;
}
double cofactor(double a, double b){

	return pow(-1,a+b);
}
std::vector<std::vector<double>> mMinor(std::vector<std::vector<double>> matrix,int row, int col){
//given a,b,c
//		d,e,f
//		g,h,i
	if(matrix.size() < 3 ){
		return matrix;
	}

	std::for_each(matrix.begin(),matrix.end(),[=](auto & row){
			row.erase(row.begin()+col);	
			});
	matrix.erase(matrix.begin()+row);
	return matrix;
}

double smallDeterminant(std::vector<std::vector<double>> matrix){
	//ad-bc
	//		[a 	b]
	//		[c	d]
	//
	//printMatrix(matrix);
	return (matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]);
}




void printMatrix(std::vector<std::vector<double>> matrix){

	for(size_t i = 0 ; i < matrix.size() ; i++){
		for(size_t j = 0; j < matrix[0].size();j++){
			std::cout << matrix[i][j] << ' ';
			}
		std::cout << '\n';
	}
	std::cout << std::endl;


}



















