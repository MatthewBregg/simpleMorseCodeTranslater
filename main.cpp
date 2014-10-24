#include<iostream>
#include"morseTree.hpp"
int main()
{
  while(true)
  {
    std::string in;
    std::getline(std::cin,in);
    if (in[0] == '-' || in[0] == '.')
    {
      std::cout << morseTree::morseToAlphabet(in) << std::endl;
    }
    else
    {
      std::cout << morseTree::alphabetToMorse(in) << std::endl;
    }
  }

}
