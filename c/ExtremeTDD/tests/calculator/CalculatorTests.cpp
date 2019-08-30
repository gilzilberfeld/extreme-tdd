#include "..\\..\\pch.h"

#include <string>
using namespace std;


extern "C"
{
#include "..\\..\\src\calculator\Display.h"
#include "..\\..\\src\calculator\Calculator.h"
#include "MockDisplay.h"
}

#include "MockDisplay.h";

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

TEST(CalculatorTests, CancelTheFirstNumber_WithExternalDisplay) {
	InitWithDisplay(&Mock_IsConnected, &Mock_Show);
	Press('1');
	string display1(externalDisplay);
	EXPECT_EQ(display1, "1");
	Press('2');
	string display2(externalDisplay);
	EXPECT_EQ(display2, "12");
}
