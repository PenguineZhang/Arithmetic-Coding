#include <arithmetic_coding.hpp>

arithmetic_coding::arithmetic_coding(std::string text, std::map<char, float> symbols_prob):_symbols(text), _symbols_prob(symbols_prob){
	// calculate_distribution();
}

arithmetic_coding::~arithmetic_coding(){}

// void arithmetic_coding::calculate_distribution(){
// 	for(int i = 0; i < symbols.length(); i++){
// 		if( symbols_prob.find(symbols[i]) == symbols_prob.end()){
// 			symbols_prob[symbols[i]] = 1.0;
// 		}else{
// 			symbols_prob[symbols[i]] += 1.0;
// 		}
// 	}

// 	int symbols_length = symbols.length();
// 	for (auto& i : symbols_prob){
// 		i.second /= symbols_length;
// 	}
// }

void arithmetic_coding::print_info(){
	std::cout << "text to encode: " << "\033[1;31m" << _symbols << "\033[0m" << std::endl;
	std::cout << "Symbol probabilities: " << std::endl;
	for (auto& i : _symbols_prob){
		std::cout << "\033[1;31m" << i.first << ": " << i.second << "\033[0m" << std::endl;
	}
}

std::pair<float, float> arithmetic_coding::get_encoded_interval(){
	return _encoded_interval;
} 

void arithmetic_coding::encode(){
	
} 

void arithmetic_coding::decode(){

}