#include <stdlib.h>
#include <stdbool.h>

#include "Ingredient.h"
#include "IngredientType.h"
#include "PlaceType.h"
#include "PastaType.h"

Ingredient* MainDispenser_GetIngredient(IngredientType ingredient, PlaceType place)
{
	Ingredient* theIngredient = (Ingredient*) malloc(sizeof(Ingredient));
	theIngredient->IsPastaType = false;
	return theIngredient;
}

Ingredient* MainDispenser_GetPasta(PastaType ingredient, PlaceType place)
{
	Ingredient* theIngredient = (Ingredient*) malloc(sizeof(Ingredient));
	theIngredient->IsPastaType = true;
	return theIngredient;

}
