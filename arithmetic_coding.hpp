#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifndef _ARITHEMIC_CODING_HPP_
#define _ARITHEMIC_CODING_HPP_


class arithmetic_coding{
	public:
		arithmetic_coding(std::string text, std::map<char, float> symbols_prob);
		~arithmetic_coding();
		void print_info();
		void encode();
		void decode();

	private:
		std::string _symbols;
		std::vector<char> codeword;
		std::map<char, std::vector<float> > _symbols_prob;
		std::pair<float, float> _encoded_interval;

		void binary_search();

};

#endif