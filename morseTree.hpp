#include<iostream>
#include<vector>
#include<sstream>
#ifndef MORSETREE_H
#define MORSETREE_H


#define ALPHASIZE 26+10 //Alphabet + 0-9


class morseTree{

public:
struct morseNode{
    const char data;
    const morseNode* const dah;
    const morseNode* const dit;
    morseNode(const char d, const morseNode* const s = 0, const morseNode* const q = 0):data(d),dah(s),dit(q){};
};


public:
    static std::string alphabetToMorse(std::string in){
	std::string result = "";
	for (auto i : in)
	    {
		switch(i)
		    {
		    case '.': result+=".-.-.- ";
			break;
		    case ',': result+="--..-- ";
			break;
		    case ' ': result+="  ";
			break;
		    }
		int temp(int(i)-int('a'));
		if(temp >= 0 && temp < 26)
		    {
			result+=alphaArray[temp]+" ";
		    }
		temp= (int(i)-int('A'));
		if(temp >= 0 && temp < 26)
		    {
			result+=alphaArray[temp]+" ";
		    }

		temp=(int(i)-int('0'));
		if (temp>= 0 && temp < 11)
		    {
			result+=alphaArray[26+temp]+" ";
		    }


	    }
	return result;	
    };
    static std::string morseToAlphabet(std::string in)
    {
	generate();
	std::string result("");
	std::size_t found = in.find("  ");
	while(found != std::string::npos)
	    {
		result+=getWord(in.substr(0,found))+" ";
		in = in.substr(found+2,in.length());
		found = in.find("  ");

	    }
	return result+getWord(in);

    };
    static void clear(){

	clearHelper(morseHead);
	morseHead = 0;
    }
			  

private:
    static void clearHelper(const morseNode* temp)
    {
	if (temp->dah != 0)
	    {clearHelper(temp->dah);}

	if (temp->dit != 0)
	    {clearHelper(temp->dit);}
	delete temp;

    }
    static std::string getWord(std::string in)
    {

	//	std::cout << "read in a" << in << std::endl;
	std::string result = "";

	std::size_t found = in.find(" ");
	while(found != std::string::npos)
	    {
		result+=getChar(in.substr(0,found));
		in = in.substr(found+1,in.length());
		found = in.find(" ");

	    }
	if (in.size() != 0)
	    {
		result+= getChar(in);
	    }
	return result;
	
    }
    static char getChar(std::string in)
    {
	//std::cout << "read in B" << in << std::endl;
	const morseNode* temp = morseHead;
	for (auto i : in)
	    {
		if (i == '-')
		    {
			temp = temp->dah;
		    }
		else if (i == '.')
		    {
			temp= temp->dit;
		    }
		else{ throw "logic error";}
		if (temp == 0)
		    {
			throw "logic error";
		    }

	    }
	return temp->data;

    };
    static const morseNode* morseHead;
    static const std::string alphaArray[ALPHASIZE];
    static void generate()
    {
	if (morseHead != 0)
	    {
		return;
	    }
	//Bottom level
	const morseNode* const zero = new morseNode('0');
	const morseNode* const nine = new morseNode('9');
	const morseNode* const eight = new morseNode('8');
	const morseNode* const seven = new morseNode('7');
	const morseNode* const six = new morseNode('6');
	const morseNode* const one = new morseNode('1');
	const morseNode* const two = new morseNode('2');
	const morseNode* const three = new morseNode('3');
	const morseNode* const four = new morseNode('4');
	const morseNode* const five = new morseNode('5');
	//Second to bottom level
	const morseNode* const comma = new morseNode(',',zero,nine);
	const morseNode* const period = new morseNode('.',0,eight);
	const morseNode* const q = new morseNode('q');
	const morseNode* const z = new morseNode('z',0,seven);
	const morseNode* const y = new morseNode('y');
	const morseNode* const c = new morseNode('c');
	const morseNode* const x = new morseNode('x');
	const morseNode* const b = new morseNode('b',0,six);
	const morseNode* const j = new morseNode('j',one,0);
	const morseNode* const p = new morseNode('p');
	const morseNode* const l = new morseNode('l');
	const morseNode* const dash = new morseNode('-',two,0);
	const morseNode* const f = new morseNode('f');
	const morseNode* const v = new morseNode('v',three,0);
	const morseNode* const h = new morseNode('h',four,five);
	//Middle level
	const morseNode* const o = new morseNode('o',comma,period);
	const morseNode* const g = new morseNode('g',q,z);
	const morseNode* const k = new morseNode('k',y,c);
	const morseNode* const d = new morseNode('d',x,b);
	const morseNode* const w = new morseNode('w',j,p);
	const morseNode* const r = new morseNode('r',0,l);
	const morseNode* const u = new morseNode('u',dash,f);
	const morseNode* const s = new morseNode('s',v,h);
	//One below top
	const morseNode* const m = new morseNode('m',o,g);
	const morseNode* const n = new morseNode('n',k,d);
	const morseNode* const a = new morseNode('a',w,r);
	const morseNode* const i = new morseNode('i',u,s);
	//Top level
	const morseNode* const t = new morseNode('t',m,n);
	const morseNode* const e = new morseNode('e',a,i);

	//MorseHead
	morseHead = new morseNode('#',t,e);




    }
    morseTree(){};


};

#endif /* MORSETREE_H */
