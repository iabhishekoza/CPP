#include "stdafx.h"
#include "LexicalCast.h"
#include <string>
#include <iostream>
#include "boost\lexical_cast.hpp"

LexicalCast::LexicalCast() {
}


LexicalCast::~LexicalCast() {
}

void LexicalCast::initLexicalCast()
{
	int iNum = 23;
	std::string sStr = boost::lexical_cast<std::string>(iNum);
	int iFinal = boost::lexical_cast<int>(sStr);

	std::cout << "String Cast: " << sStr << std::endl;
	std::cout << "Num Cast: " << iFinal << std::endl;

	std::array<char, 64> aMsg = boost::lexical_cast<std::array<char, 64>>(23);
	for (char c : aMsg) {
		std::cout << c;
	}
	std::cout << std::endl;
}