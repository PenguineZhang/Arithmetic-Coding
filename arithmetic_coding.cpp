#include <arithmetic_coding.hpp>

arithmetic_coding::arithmetic_coding(std::string text):symbols(text){
	calculate_distribution();
}

arithmetic_coding::~arithmetic_coding(){}

void arithmetic_coding::calculate_distribution(){
	for(int i = 0; i < symbols.length(); i++){
		if( symbols_prob.find(symbols[i]) == symbols_prob.end()){
			symbols_prob[symbols[i]] = 1.0;
		}else{
			symbols_prob[symbols[i]] += 1.0;
		}
	}

	int symbols_length = symbols.length();
	for (auto& i : symbols_prob){
		i.second /= symbols_length;
	}
}
