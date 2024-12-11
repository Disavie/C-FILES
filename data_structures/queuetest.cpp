#include "queue.hpp"
#include <iostream>
int main(){
	Queue<int> q;
	std::cout << q.pop() << std::endl;
	std::cout << q.pop() << std::endl;
	return 0;
}
