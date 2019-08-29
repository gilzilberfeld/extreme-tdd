package extreme.tdd.pastamaker;


public class Dish {

	public SauceType sauce;
	public PastaType pasta;

	public Dish(SauceType sauce, PastaType pasta)
    {
        this.sauce = sauce;
        this.pasta = pasta;
    }

    public String toString()
    {
        String result = "Sauce: " +
        				sauce.toString() +
        				" Pasta : " +
        				pasta.toString() + "\n";
        return result;
    }

}
