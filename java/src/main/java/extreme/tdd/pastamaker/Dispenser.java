package extreme.tdd.pastamaker;

public interface Dispenser {
	Ingredient getIngredient(IngredientType ingredient, Place place);
	Ingredient getPasta(PastaType pasta, Place place);
}
