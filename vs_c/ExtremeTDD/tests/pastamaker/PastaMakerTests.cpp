#include "..\\..\\pch.h"

#include <string>
using namespace std;

#include "..//..//ApprovalTests.hpp"
using namespace ApprovalTests;


extern "C"
{
#include "..\\..\\src\\pastamaker\Ingredient.h"
#include "..\\..\\src\\pastamaker\IngredientType.h"
#include "..\\..\\src\\pastamaker\PastaType.h"
#include "..\\..\\src\\pastamaker\PlaceType.h"
#include "..\\..\\src\\pastamaker\SauceType.h"
#include "..\\..\\src\\pastamaker\Dispenser.h"
#include "..\\..\\src\\pastamaker\PastaMaker.h"
}

#include "Dish.h"
TEST(PastaMakerTests, theTest)
{
	string log;
	InitPastaMaker(&MainDispenser_GetIngredient, &MainDispenser_GetPasta);

	Dish dish(Alfredo, FreshSpaghetti);
	log.append(dish.ToString());
	Cook(Alfredo, FreshSpaghetti);

	Approvals::verify(log);

}