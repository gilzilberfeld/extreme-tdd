#include <string>
using namespace std;

#include "..\\..\\pch.h"

extern "C"
{
#include "..\\..\\src\calculator\Display.h"
#include "..\\..\\src\calculator\Calculator.h"
}
TEST(CalculatorTests, CancelTheFirstNumber) {
	Init;
	Press('1');
	Press('C');
	string display = GetDisplay();
    EXPECT_EQ(display, "0");
}


TEST(CalculatorTests, CancelTheFirstNumber2) {
	Init();
	Press('1');
	Press('C');
	Press('2');
	string display = GetDisplay();
	EXPECT_EQ(display, "2");
}

TEST(CalculatorTests, CancelAfterOperation) {
	Init();
	Press('1');
	Press('+');
	Press('C');
	string display = GetDisplay();
	EXPECT_EQ(display, "0");
}

TEST(CalculatorTests, NotEnoughInfo) {
	Init();
	Press('1');
	string display = GetDisplay();
	EXPECT_EQ(display, "1");
}

TEST(CalculatorTests, TwoNumbers) {
	Init();
	Press('1');
	Press('2');
	string display = GetDisplay();
	EXPECT_EQ(display, "12");
}

TEST(CalculatorTests, TwoNumbersOp) {
	Init();
	Press('1');
	Press('C');
	Press('+');
	string display = GetDisplay();
	EXPECT_EQ(display, "0");
}

