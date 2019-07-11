#include <arithmetic_coding.hpp>

int main(int argc, char** argv){
	arithmetic_coding ac(19);
	std::cout << ac.square() << std::endl;
	return 0;
}