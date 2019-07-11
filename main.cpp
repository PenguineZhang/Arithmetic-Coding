#include <arithmetic_coding.hpp>
#include <algorithm>
#include <ctime>


int main(int argc, char** argv){

	clock_t start, end;
	start = clock();
	
	arithmetic_coding ac("abcabcedfefegoigpo3eg");

	for (auto& t: ac.symbols_prob){
		std::cout << t.first << ": " << t.second << std::endl;
	}
	end = clock();

	std::cout << float(end - start) / float(CLOCKS_PER_SEC) << std::endl;
	return 0;
}