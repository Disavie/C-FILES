#include <iostream>
#include "stack.hpp"



int main(){

	Stack<int> s;
	std::cout << "Created stack " << std::endl;
	s.push(1);
	s.push(2);
	std::cout << "pushed 2" << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.peek() << std::endl;
	return 0;
}
