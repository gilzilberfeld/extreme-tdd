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


TEST(CalculatorTests, EmptyTest) {
    EXPECT_EQ(true, false);
}
