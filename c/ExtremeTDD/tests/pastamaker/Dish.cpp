
extern "C"
{
	
#include "..//..//src/pastamaker/SauceType.h"
#include "..//..//src/pastamaker/PastaType.h"
}

#include "stdlib.h"
#include <string>
using namespace std;
#include "Dish.h"


Dish::Dish(SauceType sauce, PastaType pasta)
{
	sauce = sauce;
	pasta = pasta;
}

string Dish::ToString()
{
	string line = "Sauce : " + to_string(sauce) + 
		"Pasta : " + to_string(pasta) + "\n";
	return line;
}
