import { MainDispenser, SauceType, PastaType, PastaMaker, PlaceType } from '../apps/pastamaker/PastaMaker'

class Dish {
  constructor (sauce, pasta) {
    this.sauce = sauce;
    this.pasta = pasta;
  }

  toString() {
    return "Sauce : ".concat(this.sauce," Pasta : ",this.pasta, "\n");
  }

}
it('should make pasta', () => {
  let dispenser  = new MainDispenser();
  let pastamaker = new PastaMaker(dispenser);
  let dish = new Dish(SauceType.Alfredo, PastaType.FreshSpaghetti);

  var logger = "Log: \n".concat(dish.toString());
  console.log(logger);

  pastamaker.cook(dish.sauce, dish.pasta);
  expect(logger).toMatchSnapshot();
});
