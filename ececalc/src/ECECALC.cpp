#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iterator>
#include "operations.hpp"




std::vector<std::string> parseInput(std::string const & str){
	std::vector<std::string> words;
	std::string word;
	for(size_t i = 0; i < str.size() ; i++){
		if(str.at(i) == ' '){
			words.push_back(word);
			word.clear();
			continue;
		}
		word.push_back(str.at(i));
		if(i == str.size()-1){
			words.push_back(word);
		}
	}
	return words;
}


int main(){


	std::string input;
	std::string output = "";
	std::vector<std::string> functions = {"idiv","vdiv","p","q","mcur","nvolt"};
	double last = 0.0;
	bool isOutputMatrix = false;


	std::cout << ">>> ";
	while(std::getline(std::cin,input)){

		std::vector<std::string> inputVec = parseInput(input);
		std::string fn = inputVec[0];

		//IF IS A FUNCTION AND NOT BASIC OPERATION
		if(std::find(functions.begin(),functions.end(),fn) != functions.end()){

			if (fn == "~"){
				std::cout << output << std::endl;
			}else if (fn == "idiv"){
				double value1 = evaluateExpression(inputVec[1],last);
				double value2 = evaluateExpression(inputVec[2],last);
				double value3 = evaluateExpression(inputVec[3],last);
				output=cur_div(value1,value2,value3);

			}else if (fn == "vdiv"){	
				double value1 = evaluateExpression(inputVec[1],last);
				double value2 = evaluateExpression(inputVec[2],last);
				double value3 = evaluateExpression(inputVec[3],last);
				output=volt_div(value1,value2,value3);

			}else if (fn == "p"){	
				double value1 = evaluateExpression(inputVec[1],last);
				double value2 = evaluateExpression(inputVec[2],last);
				output=parallel(value1,value2);

			}else if (fn == "mcur" || fn == "nvolt"){
				//Inputvec[1] = size of NxN matrix 
				std::cout << fn << std::endl;
				output = mesh_current(std::stoi(inputVec[1]), last);
				isOutputMatrix =true;	
			}else if (fn == "q"){
				break;
			}
		}else{ //Handles basic operations formatted as 'a + b' spaces required
			output = std::to_string(evaluateExpression(inputVec[0],last));
		}
		if (!isOutputMatrix)
			last = std::stod(output);
		std::cout << output << std::endl;
		std::cout << ">>> ";
	}
	return 0;
}


