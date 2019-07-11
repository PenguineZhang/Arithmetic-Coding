#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifndef _ARITHEMIC_CODING_HPP_
#define _ARITHEMIC_CODING_HPP_


class arithmetic_coding{
	public:
		int i;
		arithmetic_coding(int j):i(j){};
		~arithmetic_coding(){};
		
		// std::vector<float, float> coded_bounds;
		// std::map<char, float> distribution;

		int square();
};

#endif