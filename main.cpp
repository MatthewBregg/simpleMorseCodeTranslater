#include<iostream>
#include"morseTree.hpp"
int main()
{
    std::string in;
    while(true)
	{
	    std::getline(std::cin,in);
	    //	    std::cout << morseTree::morseToAlphabet(in) << std::endl;
	    std::cout << morseTree::alphabetToMorse(in) << std::endl;
	}

}
