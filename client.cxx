#include <iostream>
#include "common.hpp"

udp udp0("127.0.0.1", 4001);

int main(){
	while(true){
		std::string str;
		std::cin >> str;
		udp0.send(str);
	}
	return 0;
}
