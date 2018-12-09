#pragma once
#include <deque>
#include "boost\optional.hpp"

class Optional
{
public:
	Optional();
	~Optional();
	void initOptional();
private:
	std::deque<char> queue;
	boost::optional<char> getAsyncData();
};

