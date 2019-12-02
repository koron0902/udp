#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <string.h>

class udp{
	static constexpr int BUF_SIZE_ = 512;
	int socket_;
	sockaddr_in addr_;

public:
	explicit udp(std::string _addr, int port){
		socket_ = socket(AF_INET, SOCK_DGRAM, 0);
		addr_.sin_family = AF_INET;
		addr_.sin_addr.s_addr = inet_addr(_addr.c_str());
		addr_.sin_port = htons(port);
	}


	void send(std::string _data){
		sendto(socket_, _data.c_str(), _data.length(), 0, reinterpret_cast<sockaddr*>(&addr_), sizeof(addr_));
	}

	void bind(){
		::bind(socket_, reinterpret_cast<const sockaddr*>(&addr_), sizeof(addr_));
	}

	std::string receive(){
		char buf[BUF_SIZE_];
		memset(buf, 0, sizeof(buf));
		recv(socket_, buf, sizeof(buf), 0);
		return std::string(buf);
	}

	void receive(char* _buf, int _size){
		memset(_buf, 0, _size);
		recv(socket_, _buf, _size, 0);
	}

	~udp(){
		close(socket_);
	}
};
