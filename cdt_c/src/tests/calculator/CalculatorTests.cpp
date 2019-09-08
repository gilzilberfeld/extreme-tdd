#include "../../Catch.hpp"

#include <string>
using namespace std;


extern "C"
{
#include "..\\..\\calculator\Display.h"
#include "..\\..\\calculator\Calculator.h"
#include "MockDisplay.h"
}

/*
TEST_CASE("CancelTheFirstNumber") {
	InitCalculator();
	Press('1');
	Press('C');
	string display = GetDisplay();
    REQUIRE(display == "0");
}


TEST_CASE("CancelTheFirstNumber2") {
	InitCalculator();
	Press('1');
	Press('C');
	Press('2');
	string display = GetDisplay();
	REQUIRE(display == "2");
}

TEST_CASE("CancelAfterOperation") {
	InitCalculator();
	Press('1');
	Press('+');
	Press('C');
	string display = GetDisplay();
	REQUIRE(display == "0");
}

TEST_CASE("NotEnoughInfo") {
	InitCalculator();
	Press('1');
	string display = GetDisplay();
	REQUIRE(display == "1");
}

TEST_CASE("TwoNumbers") {
	InitCalculator();
	Press('1');
	Press('2');
	string display = GetDisplay();
	REQUIRE(display == "12");
}

TEST_CASE("TwoNumbersOp") {
	InitCalculator();
	Press('1');
	Press('C');
	Press('+');
	string display = GetDisplay();
	REQUIRE(display == "0");
}

TEST_CASE("CancelTheFirstNumber_WithExternalDisplay") {
	InitCalculatorWithDisplay(&Mock_IsConnected, &Mock_Show);
	Press('1');
	string display1(externalDisplay);
	REQUIRE(display1 == "1");
	Press('2');
	string display2(externalDisplay);
	REQUIRE(display2 == "12");
}

*/
