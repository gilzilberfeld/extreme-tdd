#include <string>

#include "../../lib/Catch.hpp"
using namespace std;


extern "C"
{
#include "..\\..\\calculator\Display.h"
#include "..\\..\\calculator\Calculator.h"
#include "MockDisplay.h"
}

TEST_CASE("Empty Test") {
	REQUIRE(true == false);
}

