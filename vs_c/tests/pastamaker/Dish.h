#pragma once

class Dish
{
public:
	Dish(SauceType sauce, PastaType pasta);
	string ToString();
private:
	SauceType sauce;
	PastaType pasta;

};



