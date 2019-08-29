package extreme.tdd.calculator;


import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


public class CalculatorTests {


	@Test
	public void CancelTheFirstNumber() {
		Calculator c = new Calculator();
		c.press("1");
		c.press("C");
		String result = c.getDisplay();
		assertEquals("0", result);
	}

	@Test
	public void CancelTheFirstNumber2() {
		Calculator c = new Calculator();
		c.press("1");
		c.press("C");
		c.press("2");
		String result = c.getDisplay();
		assertEquals("2", result);
	}

	

	@Test
	public void CancelAfterOperation() {
		Calculator c = new Calculator();
		c.press("1");
		c.press("+");
		c.press("C");
		String result = c.getDisplay();
		assertTrue(result.equals("0"));
	}

	@Test
 	public void NotEnoughInfo() {
		Calculator c = new Calculator();
		c.press("1");
		String result = c.getDisplay();
		assertTrue(result.equals("1"));
	}

	@Test
	public void TwoNumbers() {
		Calculator c = new Calculator();
		c.press("1");
		c.press("2");
		String result = c.getDisplay();
		assertEquals(result, "12");
	}

	@Test
	public void TwoNumbersOp() {
		Calculator c = new Calculator();
		c.press("1");
		c.press("C");
		c.press("+");
		String result = c.getDisplay();
		assertEquals(result, "0");
	}
	

}
