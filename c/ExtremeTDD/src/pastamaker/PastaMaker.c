#include <stdbool.h>	
#include <stdlib.h>

#include "Ingredient.h"
#include "IngredientType.h"
#include "PastaType.h"
#include "PlaceType.h"
#include "SauceType.h"
#include "Dispenser.h"
#include "PastaMaker.h"

GetIngredient_ptr Dispenser_GetIngredient = 0;
GetPasta_ptr Dispenser_GetPasta = 0;

Ingredient ingredients[10];
int numberOfIngredients = 0;

void InitPastaMaker(GetIngredient_ptr getIngredient, GetPasta_ptr getPasta)
{
	Dispenser_GetIngredient = getIngredient;
	Dispenser_GetPasta = getPasta;
}

void Cook(SauceType sauce, PastaType pasta)
{
	memset(ingredients, 0, sizeof(Ingredient) * 10);

	if (sauce == Alfredo)
	{
		AddIngredient(Dispenser_GetIngredient(Cream, Refrigarator));
	}
	else if (sauce == Bolognese || sauce == Marinara)
	{
		AddIngredient(Dispenser_GetIngredient(Tomato, Garden));
	}
	else if (pasta = Ravioly)
	{
		Ingredient tempIngredients[10];
		int numberOfOthers = numberOfIngredients - 1;
		memcpy(tempIngredients, ingredients, sizeof(Ingredient) * 10);
		memset(ingredients, 0, sizeof(Ingredient) * 10);
		AddIngredient(Dispenser_GetPasta(Ravioly, Freezer));
		AddAll(tempIngredients, numberOfOthers);
	}
	else if (sauce == Pesto || sauce == Marinara)
	{
		AddIngredient(Dispenser_GetIngredient(Basil, Garden));
	}
	else if (sauce == Marinara)
	{
		AddIngredient(Dispenser_GetIngredient(Onion, Garden));
	}
	else if (pasta == FreshSpaghetti)
	{
		AddIngredient(Dispenser_GetPasta(FreshSpaghetti, Freezer));
	}
	if (ingredients[0].IsPastaType == true)
	{
		Ingredient* fillingIngredients = GetAllButFirst();
		Prepare(&ingredients[0]);
		Fill(fillingIngredients);
		CookPasta();
	}
	else
	{
		CookPasta();
		Ingredient* sauceIngredients = GetAllButLast();
		Prepare(GetLast());
		Fill(sauceIngredients);
		AddSauce();
	}
}

void AddIngredient(Ingredient* newIngredient)
{
	memcpy(&ingredients[numberOfIngredients], newIngredient, sizeof(Ingredient));
	numberOfIngredients++;
}

void AddAll(Ingredient* others, int numberOfOthers)
{
	memcpy(&ingredients[numberOfIngredients], others, sizeof(Ingredient) * numberOfOthers);
}

Ingredient* GetLast() 
{
	Ingredient* lastIngredient = (Ingredient*) malloc (sizeof(Ingredient));
	memcpy(lastIngredient, ingredients, sizeof(Ingredient));
	return lastIngredient;
}

Ingredient* GetAllButLast()
{
	Ingredient* allButLastIngredients = (Ingredient*) malloc(sizeof(Ingredient) * (numberOfIngredients - 1));
	memcpy(allButLastIngredients, ingredients, sizeof(Ingredient) * (numberOfIngredients - 1));
	return allButLastIngredients;
}


Ingredient* GetAllButFirst()
{
	Ingredient* allButFirstIngredients = (Ingredient*)malloc(sizeof(Ingredient) * (numberOfIngredients - 1));
	memcpy(allButFirstIngredients, ingredients[1], sizeof(Ingredient) * (numberOfIngredients - 1));
	return allButFirstIngredients;
}

void Fill(Ingredient* sauceIngredients) { }
void Prepare(Ingredient* ingredient) { }
void CookPasta() { }
void AddSauce() { }

