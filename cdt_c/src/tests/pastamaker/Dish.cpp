
extern "C"
{
#include "..//..//pastamaker//SauceType.h"
#include "..//..//pastamaker//PastaType.h"
}

#include "stdlib.h"
#include <string>
using namespace std;
#include "Dish.h"


Dish::Dish(SauceType sauce, PastaType pasta)
{
	this->sauce = sauce;
	this->pasta = pasta;
}

string Dish::ToString()
{
	string line = "Sauce : " + to_string(sauce) +
		" Pasta : " + to_string(pasta);
	line.append("\n");
	return line;
}
