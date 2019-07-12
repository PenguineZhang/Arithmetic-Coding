#include <arithmetic_coding.hpp>
#include <algorithm>
#include <ctime>


int main(int argc, char** argv){

	std::map<char, float> symbol_prob;
	symbol_prob.insert(std::pair<char, float>('a', 0.8));
	symbol_prob.insert(std::pair<char, float>('b', 0.2));

	std::string text("aaba");

	arithmetic_coding ac(text, symbol_prob);
	ac.print_info();


	return 0;
}