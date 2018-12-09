#include "stdafx.h"
#include "Any.h"
#include <string>
#include <iostream>
#include "boost\any.hpp"

Any::Any() {
}

Any::~Any() {
}

void Any::initAny() {
	boost::any x, y, z;
	x = std::string("hello");
	y = 2.5;
	z = 'x';
	z = std::vector<int>();

	std::cout << boost::any_cast<std::string>(x) << std::endl; // return a copy of x's data: hello
	std::cout << boost::any_cast<double>(y) << std::endl;	   // return a copy of y's data: 2.5
	std::cout << boost::any_cast<char>(z) << std::endl;		   // return a copy of z's data: x
	std::cout << boost::any_cast<int>(x) << std::endl;		   // throws bad_any_cast
	std::cout << boost::any_cast<float>(y) << std::endl;	   // throws bad_any_cast

	boost::any_cast<std::vector<int>>(z).push_back(23);
	int i = boost::any_cast<std::vector<int>>(z).back();	   // crash

	int temp;
	boost::any p = &temp;
	int* pInt = boost::any_cast<int*>(p);
	std::cout << pInt << std::endl;

	struct property {
		std::string name;
		boost::any value;
	};
	std::vector<property> properties;

}