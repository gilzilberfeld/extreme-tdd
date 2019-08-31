
const IngredientType = {
    Cream : 0,
    Onion : 1,
    Tomato: 2,
    Basil: 3
};

const PastaType = {
	FreshSpaghetti : 0,
    Lasagnia : 1,
    Ravioly : 2,
    Macaroni: 3
};

const PlaceType = {
    Refrigarator : 0 ,
    Garden : 1,
    Cupboard : 2,
    Freezer :3
};

const SauceType = {
    Marinara : 0,
    Alfredo : 1,
    Bolognese : 2,
    Pesto : 3
};

class Ingredient {
    constructor(isPastaType) {
        this.IsPastaType = isPastaType;
    }
};

class MainDispenser {
    getIngredient(ingredient, place) {
        return new Ingredient(false);
    }

    getPasta(ingredient, place) {
        return new Ingredient(true);
    }
};


class PastaMaker {
	

	constructor( dispenser) {
		this.dispenser = dispenser;
	}
	
    fill(sauceIngredients) { }
    prepare(ingredient) { }
    cookPasta() { }
    addSauce() { }

    cook(sauce, pastaType) {
        var ingredients = [];
        if (sauce === SauceType.Alfredo)
        {
            ingredients.push(this.dispenser.getIngredient(IngredientType.Cream, Place.Refrigarator));
        }
        else if (sauce === SauceType.Bolognese || sauce === SauceType.Marinara)
        {
            ingredients.push(dispenser.getIngredient(IngredientType.Tomato, Place.Garden));
        }
        else if (pastaType === PastaType.Ravioly)
        {
            var tempIngredients = ingredients.slice();
            ingredients = [];
            ingredients.push(this.dispenser.getPasta(PastaType.Ravioly, PlaceType.Freezer));
            ingredients.push(tempIngredients);
        }
        else if (sauce === SauceType.Pesto || sauce === SauceType.Marinara)
        {
            ingredients.push(this.dispenser.getIngredient(IngredientType.Basil, PlaceType.Garden));
        }
        else if (sauce === SauceType.Marinara)
        {
            ingredients.push(this.dispenser.getIngredient(IngredientType.Onion, PlaceType.Garden));
        }
        else if (pastaType === PastaType.FreshSpaghetti)
        {
            ingredients.push(this.dispenser.getPasta(PastaType.FreshSpaghetti, PlaceType.Freezer));
        }
        if (ingredients[0].IsPastaType())
        {
            var fillingIngredients = ingredients.slice(1, ingredients.length);
            prepare(ingredients[0]);
            fill(fillingIngredients);
            cookPasta();
        }
        else
        {
            cookPasta();
            var sauceIngredients = ingredients.slice();
            prepare(ingredients[ingredients.length- 1]);
            fill(sauceIngredients);
            addSauce();
        }
    }

}
