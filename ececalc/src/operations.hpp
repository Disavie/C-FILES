#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

//takes inputs seperated by ' ' and returns them as individual strins in vector
std::vector<std::string> parseInput(std::string const & str);

//performs parallel resistance calculations
std::string parallel(double r1, double r2);
//performs current division on r1 given r1 || r2
//
std::string cur_div(double Is, double r1, double r2);
//
//performs voltage division on r1 given r1 ser r2
std::string volt_div(double Vs, double r1, double r2);

//parses arthemetic expression with +-*/()
double evaluateExpression(const std::string& expression, double d);


std::string mesh_current(int size, double last);

//forms matrix of rows rows, cols columns
std::vector<std::vector<double>> formMatrix(int rows,int cols,double last);

//solves determinant of 2x2 matrix
double smallDeterminant(std::vector<std::vector<double>> matrix);

//gets the minor matrix of matrix by removing row and col from matrix
std::vector<std::vector<double>> mMinor(std::vector<std::vector<double>> matrix,int row, int col);

//helper, returns (-1)^(a+b)
double cofactor(double a, double b);

//solves determinant of NxN matrix given N>2
double largeDeterminant(std::vector<std::vector<double>> matrix);

//solves Ax=B matrix by using Cramer's rule:
//			
//			[x_1] = det(A_1)/det(A)
//			[x_2] = det(A_2)/det(A)
//			[x_3] = det(A_3)/det(A)
//			
std::vector<double> solveAxB(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);

void printMatrix(std::vector<std::vector<double>> matrix);
