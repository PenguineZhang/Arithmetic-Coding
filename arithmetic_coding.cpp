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
	if(codeword.begin() == codeword.end()){
		std::cout<< "\033[1;31m" << "Codeword has not been generated" << "\033[0m" << std::endl;
	}else{
		std::cout << "Codeword: " << "\033[1;32m";
		for( auto& i: codeword){
			std::cout << i; 
		}
		std::cout << "\033[0m" << std::endl;
	}
}

void arithmetic_coding::encode(){
	
	// calculate 
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
	std::map<char, std::vector<float>>::iterator it_end = _symbols_prob.end();
	_encoded_interval.first = _symbols_prob[it_begin->first][1];
	_encoded_interval.second = _symbols_prob[(--it_end)->first][2];


	// generating codeword
	std::cout << _encoded_interval.first << " " << _encoded_interval.second << std::endl;
	binary_search();

}

void arithmetic_coding::binary_search(){
	float upper = 1.0, lower = 0.0;
	float mid;
	bool found_upper = false, found_lower=false;
	while(1){
		mid = (upper + lower) / 2;
		if (mid < _encoded_interval.first){
			lower = mid;
			codeword.push_back('1');
		}else if (mid > _encoded_interval.second){
			upper = mid;			
			codeword.push_back('0');
		}else if (mid > _encoded_interval.first && mid < _encoded_interval.second){
			if ((mid - _encoded_interval.first) > (_encoded_interval.second - mid)){
				upper = mid;
				codeword.push_back('0');
			}else{
				lower = mid;
				codeword.push_back('1');
			}
		}

		if (lower > _encoded_interval.first && upper < _encoded_interval.second){
			std::cout << "Finish encoding" << std::endl;
			break;
		}
		// std::cout << lower << " " << upper << std::endl;
		
	}
	
}


void arithmetic_coding::decode(){

}