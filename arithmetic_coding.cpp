#include <arithmetic_coding.hpp>
#include <algorithm>
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
			std::cout << "\033[1;32m" << j << "\t\t" ;
		}
		std::cout << std::endl;
	}
	std::cout << "Encoded interval: (" << _encoded_interval.first << ", " << _encoded_interval.second << ")\033[0m" << std::endl;
}

void arithmetic_coding::encode(){
	float symbols_lower, symbols_upper, selected_interval, new_start;
	for ( auto& letter: _symbols ){

		symbols_lower = _symbols_prob[ letter ][1];
		symbols_upper = _symbols_prob[ letter ][2];
		selected_interval = symbols_upper - symbols_lower;

		new_start = symbols_lower;

		for ( auto& i: _symbols_prob ){
			i.second[1] = new_start;
			i.second[2] = i.second[0] * selected_interval + i.second[1];
			new_start = i.second[2];
		}
	}
	std::map<char, std::vector<float>>::iterator it_begin = _symbols_prob.begin();
	std::map<char, std::vector<float>>::iterator it_end = _symbols_prob.rbegin();
	std::cout << it_begin->first << std::endl;
	std::cout << it_end->first << std::endl;
	_encoded_interval.first = _symbols_prob[it_begin->first][1];
	_encoded_interval.second = _symbols_prob[it_end->first][2];

}

void arithmetic_coding::decode(){

}