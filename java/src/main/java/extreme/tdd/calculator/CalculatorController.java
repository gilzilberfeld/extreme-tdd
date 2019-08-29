package extreme.tdd.calculator;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping ("/calculator")
public class CalculatorController {
	@Autowired private Calculator calculator;
	
	@PostMapping(value ="/press")
	public ResponseEntity<?> press(@RequestParam(value = "key") String key) {
		calculator.press(key);
		return ResponseEntity.ok(null);
	}
	
	@GetMapping(value = "/display") 
	public ResponseEntity<String> getDisplay() {
		return new ResponseEntity<String>(calculator.getDisplay(), HttpStatus.OK);
	}
	
}
