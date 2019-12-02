#include <stdio.h>
#include <string.h>
#include "common.hpp"

udp udp0("0.0.0.0",4001);

int main(int argc, char **argv){
	udp0.bind();
	
	while (1){
		std::string rdata = udp0.receive();
		printf("recv:%s\n", rdata.c_str());
	}
	
	return 0;
}
