#include "stdafx.h"
#include "Variant.h"
#include <string>
#include <iostream>
#include "boost\variant.hpp"

Variant::Variant() {
}

Variant::~Variant() {
}

void Variant::initVariant() {
	/// As we know union the datatype in union share the same memory size
	/// But there are constraint using union, as we can't use a string and int together
	/// Alternative to that is to use variant

	union { int i; float f; } u;
	u.i = 2;
	u.f = 2.3F; // u.i is overwritten

	std::cout << u.i << std::endl;

	// union { int i; string s; } u1; 

	boost::variant<int, std::string> u1, u2;
	u1 = 2;
	u2 = "Two";

	std::cout << u1 << ", " << u2 << std::endl;

	// u1 *= u1; // Cannot use operands
	u1 = boost::get<int>(u1) * 2;
	// std::string s = boost::get<std::string>(u1); // throws exception of bad get
	u1 = "some string"; // can be changed
	u2 = 10;

	boost::variant<int, std::string> u3;
	std::cout << u3 << std::endl;

	/// using get is convinient but one need to have a prior knowledge of which type to use
	/// for	example: void Double(boost::variant<int, string> v);
	/// One need to have knowledge of what type of v is
	/// We need a better way to fetch the data stored in variant

	// using visitor
	class DoubleVisitor : public boost::static_visitor<> {
	public:
		void operator() (int& i) const {
			i += i;
		}
		void operator() (std::string& str) const {
			str += str;
		}
	};

	u1 = 2;
	boost::apply_visitor(DoubleVisitor(), u1); // u1 = 4
	u2 = "hello";
	boost::apply_visitor(DoubleVisitor(), u2); // u2 = "hellohello"

	std::vector<boost::variant<int, std::string>> vec;
	vec.push_back("good");
	vec.push_back(1);
	vec.push_back("bad");
	vec.push_back(2);

	for (auto x : vec) {
		boost::apply_visitor(DoubleVisitor(), x);
	}

	std::cout << std::endl << u1 << std::endl;
	std::cout << u2 << std::endl;

}