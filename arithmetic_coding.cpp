#include <arithmetic_coding.hpp>

arithmetic_coding::arithmetic_coding(std::string text, std::map<char, float> symbols_prob):_symbols(text){
	for( auto& pair: symbols_prob){
		_symbols_prob[pair.first].push_back(pair.second);
	}
}

arithmetic_coding::~arithmetic_coding(){}

void arithmetic_coding::print_info(){
	std::cout << "text to encode: " << "\033[1;31m" << _symbols << "\033[0m" << std::endl;
	std::cout << "Symbol probabilities: " << std::endl;
	for (auto& i : _symbols_prob){
		std::cout << "\033[1;31m" << i.first << ": " << i.second << "\033[0m" << std::endl;
	}
}

void arithmetic_coding::encode(){
	for ( auto& letter: _symbols ){

	}
}

void arithmetic_coding::decode(){

}