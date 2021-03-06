/// BoostInLearning.cpp : Calling all the functionalities of Boost library
/// 1. Lexical Cast
/// 2. Variant
/// 3. Any
/// 4. Optional

#include "stdafx.h"
#include <memory>
#include "LexicalCast.h"
#include "Variant.h"
#include "Any.h"
#include "Optional.h"

int main()
{
	// std::shared_ptr<LexicalCast> lcPtr;
	// lcPtr->initLexicalCast();

	// std::shared_ptr<Variant> vPtr;
	// vPtr->initVariant();

	// std::shared_ptr<Any> anyPtr;
	// anyPtr->initAny();

	std::shared_ptr<Optional> oPtr;
	oPtr->initOptional();

    return 0;
}

