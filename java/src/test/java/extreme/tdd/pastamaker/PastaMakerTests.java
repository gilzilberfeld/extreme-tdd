package extreme.tdd.pastamaker;

import java.util.List;

import org.approvaltests.Approvals;
import org.approvaltests.reporters.DiffReporter;
import org.approvaltests.reporters.UseReporter;
import org.junit.Test;

@UseReporter(DiffReporter.class)
public class PastaMakerTests {

	@Test
	public void pastaMakerTest() {
	      StringBuilder log = new StringBuilder();
	      Dispenser dispenser = new MainDispenser();
	      PastaMaker maker = new PastaMaker(dispenser);
	      
	      Dish dish = new Dish(SauceType.Alfredo, PastaType.FreshSpaghetti);
          log.append(dish.toString());
          maker.cook(dish.sauce, dish.pasta);

          Approvals.verify(log);
	}
}
