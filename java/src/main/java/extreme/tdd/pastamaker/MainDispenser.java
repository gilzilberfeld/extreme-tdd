package extreme.tdd.pastamaker;

public class MainDispenser implements Dispenser {

	@Override
	public Ingredient getIngredient(IngredientType ingredient, Place place) {
		return new Ingredient(false);
	}

	@Override
	public Ingredient getPasta(PastaType pasta, Place place) {
		return new Ingredient(true);
	}

}
