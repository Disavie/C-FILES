#include "forwardlist.hpp"
#include <iostream>
#include <ostream>

int main(){
    std::cout << "weenie" <<std::endl;

    ForwardList<int> fl;
    fl.push_back(2);
    std::cout << fl[0] << std::endl;
    std::cout << fl.remove(0) << std::endl;
    std::cout << "Is fl empty? " << fl.isEmpty() << std::endl;
    std::cout << "addiing new values" << std::endl;
    fl.push_back(5);
    std::cout << "added 5 " << std::endl;
    fl.push_back(8);
    std::cout << fl[0] << std::endl;
    std::cout << fl[1] << std::endl;
    fl.push_back(1);
    fl.push_back(2);
    fl.push_back(3);
    fl.push_back(4);
    std::cout << fl[2] << std::endl;
    std::cout << fl[3] << std::endl;
    fl.clear();
    std::cout << "cleared successfully" << std::endl;
    std::cout << fl.isEmpty() << std::endl;
}
    

