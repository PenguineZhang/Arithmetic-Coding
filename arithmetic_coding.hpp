#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifndef _ARITHEMIC_CODING_HPP_
#define _ARITHEMIC_CODING_HPP_


class arithmetic_coding{
	public:
		arithmetic_coding(std::string text);
		~arithmetic_coding();

		std::map<char, float> symbols_prob;
		
	private:
		std::string symbols;
		void calculate_distribution();

};

#endif