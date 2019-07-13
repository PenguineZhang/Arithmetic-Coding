#include <arithmetic_coding.hpp>
#include <cassert>

arithmetic_coding::arithmetic_coding(std::string text, std::map<char, float> symbols_prob):_symbols(text){
	float current_cdf = 0.0;
	for( auto& pair: symbols_prob){
		_symbols_prob[pair.first].push_back(pair.second);
		_symbols_prob[pair.first].push_back(current_cdf);
		_symbols_prob[pair.first].push_back(current_cdf + pair.second);
		current_cdf += pair.second;
	}
	assert(current_cdf == 1.0);
}

arithmetic_coding::~arithmetic_coding(){}

void arithmetic_coding::print_info(){
	std::cout << "text to encode: " << "\033[1;31m" << _symbols << "\033[0m" << std::endl;
	std::cout << "Symbol probabilities: " << std::endl;
	for (auto& i : _symbols_prob){
		std::cout << "\033[1;31m" << i.first << ": " << "\033[0m";
		for (auto& j: _symbols_prob[i.first]){
			std::cout << "\033[1;32m" << j << " " ;
		}
		std::cout << "\033[0m" << std::endl;
	}
}

void arithmetic_coding::encode(){
	float interval_lower_bound = 0.0;
	float interval_upper_bound = 0.0;
	for ( auto& letter: _symbols ){

		int selected_interval = _symbols_prob[ letter ][2] - _symbols_prob[ letter ][1];

	}
}

void arithmetic_coding::decode(){

}