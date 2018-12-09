#include "stdafx.h"
#include "Optional.h"
#include <string>
#include <iostream>
#include "boost\optional.hpp"
#include "boost\variant.hpp"

Optional::Optional() {
}

Optional::~Optional() {
}

void Optional::initOptional() {
	boost::variant<nullptr_t, char> v;
	boost::optional<char> op;

	op = 'A';
	op = getAsyncData();
	if (!op) {
		std::cout << "No data is available" << std::endl;
	}
	else {
		std::cout << "op contains: " << op.get() << std::endl;		// crashes if op is uninitialized
		std::cout << "op contains: " << *op << std::endl;			// crashes if op is uninitialized
	}

	op.reset();
	std::cout << op.get_value_or('z') << std::endl;					// return 'z' is op is empty

	struct tempStruct {
		std::string s;
		int v;
	} ts;

	boost::optional<tempStruct> opStruct1;
	boost::optional<tempStruct> opStruct2(ts);

	opStruct2->s = "Hello";
	opStruct2->v = 1;

	std::cout << opStruct2->s << ", " << opStruct2->v << std::endl;

}

boost::optional<char> Optional::getAsyncData() {
	if (!queue.empty()) {
		return boost::optional<char>(queue.back());
	}
	else {
		return boost::optional<char>();
	}
}