#pragma once
Ingredient* GetIngredient(IngredientType ingredient, PlaceType place);;
Ingredient *GetPasta(PastaType ingredient, PlaceType place);

typedef Ingredient*(*GetIngredient_ptr)(IngredientType, PlaceType);
typedef Ingredient*(*GetPasta_ptr)(PastaType, PlaceType);