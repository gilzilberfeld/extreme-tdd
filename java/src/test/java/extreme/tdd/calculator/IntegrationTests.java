package extreme.tdd.calculator;

import static org.junit.Assert.assertEquals;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

import java.io.UnsupportedEncodingException;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;


@ExtendWith(SpringExtension.class)
@ContextConfiguration(classes = {CalculatorTestConfiguration.class})
@SpringBootTest
@AutoConfigureMockMvc
public class IntegrationTests{


	@Autowired	private MockMvc mockMvc;
	


	@Test
	public void SimpleCalcuation() throws Exception {
		mockMvc.perform(
				post("/calculator/press").param("key", "1"));
		mockMvc.perform(
				post("/calculator/press").param("key", "+"));
		mockMvc.perform(
				post("/calculator/press").param("key", "2"));
		mockMvc.perform(
				post("/calculator/press").param("key", "="));
		MvcResult result = mockMvc.perform(get("/calculator/display"))
		.andExpect(status().isOk())
		.andReturn();

		assertEquals("3", result.getResponse().getContentAsString());

	}
	
	@Test
	public void ShowLastOperand_AfterOperation() throws Exception {
		pressKey("5");
		pressKey("+");
		pressKey("3");

		assertEquals("3", getDisplay());
	}
	
	private String getDisplay() throws Exception, UnsupportedEncodingException {
		MvcResult result = mockMvc.perform(get("/calculator/display"))
		.andExpect(status().isOk())
		.andReturn();

		String display = result.getResponse().getContentAsString();
		return display;
	}

	private void pressKey(String key) throws Exception {
		mockMvc.perform(
				post("/calculator/press").param("key", key));
	}
	
	
}
