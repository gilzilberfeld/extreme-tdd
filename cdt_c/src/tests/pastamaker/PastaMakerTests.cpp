#include "../../ApprovalTests.hpp"
using namespace ApprovalTests;

#include "../../Catch.hpp"

#include <string>
using namespace std;


extern "C"
{
#include "..\\..\\pastamaker\Ingredient.h"
#include "..\\..\\pastamaker\IngredientType.h"
#include "..\\..\\pastamaker\PastaType.h"
#include "..\\..\\pastamaker\PlaceType.h"
#include "..\\..\\pastamaker\SauceType.h"
#include "..\\..\\pastamaker\Dispenser.h"
#include "..\\..\\pastamaker\PastaMaker.h"
}

#include "Dish.h"
TEST_CASE("PastaMakerTests")
{
	string log;
	InitPastaMaker(&MainDispenser_GetIngredient, &MainDispenser_GetPasta);

	Dish dish(Alfredo, FreshSpaghetti);
	log.append(dish.ToString());
	Cook(Alfredo, FreshSpaghetti);

	Approvals::verify(log);
}

