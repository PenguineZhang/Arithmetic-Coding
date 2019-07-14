#include <arithmetic_coding.hpp>
#include <algorithm>
#include <ctime>


int main(int argc, char** argv){

	std::map<char, float> symbol_prob;
	symbol_prob.insert(std::pair<char, float>('a', 0.4));
	symbol_prob.insert(std::pair<char, float>('b', 0.4));
	symbol_prob.insert(std::pair<char, float>('c', 0.2));

	std::string text("aabacc");

	arithmetic_coding ac(text, symbol_prob);
	// ac.print_info();
	ac.encode();
	ac.print_info();


	return 0;
}