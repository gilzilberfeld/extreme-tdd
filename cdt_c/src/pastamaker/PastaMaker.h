#pragma once

void InitPastaMaker(GetIngredient_ptr getIngredient, GetPasta_ptr getPasta);
void Cook(SauceType sauce, PastaType pasta);
void AddIngredient(Ingredient* newIngredient);
void AddAll(Ingredient* others, int numberOfOthers);
void Fill(Ingredient* sauceIngredients);
void Prepare(Ingredient* ingredient);
void CookPasta();
void AddSauce();
Ingredient* GetAllButFirst();
Ingredient* GetAllButLast();
Ingredient* GetLast();