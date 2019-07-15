#include <arithmetic_coding.hpp>
#include <algorithm>
#include <ctime>


int main(int argc, char** argv){

	std::map<char, float> symbol_prob;
	symbol_prob.insert(std::pair<char, float>('0', 0.2));
	symbol_prob.insert(std::pair<char, float>('1', 0.4));
	symbol_prob.insert(std::pair<char, float>('2', 0.4));

	std::string text("210");

	arithmetic_coding ac(text, symbol_prob);
	ac.print_info();
	ac.encode();
	ac.print_info();


	return 0;
}