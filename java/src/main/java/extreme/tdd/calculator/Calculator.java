package extreme.tdd.calculator;

public class Calculator {
	String display = "";
	Display externalDisplay;
	int lastArgument = 0;
	int result = 0; 
	Boolean newArgument = false;
	Boolean shouldReset = false;
	OperationType lastOperation;

	public Calculator() {}
	public Calculator(Display externalDisplay) {
		this.externalDisplay = externalDisplay;
	}
	
	public void press(String key) {
		if (key.equals("C"))
			display = "";
		else {
			if (key.equals("+")) {
				lastOperation = OperationType.Plus;	
				lastArgument =  Integer.parseInt(display);
				newArgument = true;
			} else {
				if (key.equals("/")) {
					lastOperation = OperationType.Div;	
					lastArgument =  Integer.parseInt(display);
					newArgument = true;
				}
				else if (key.equals("=")) {
					int currentArgument = Integer.parseInt(display);
					if (lastOperation == OperationType.Plus) {
						display = Integer.toString(lastArgument + currentArgument);
					}
					shouldReset = false;
				}
				else {
					if (shouldReset) {
						display = "";
						shouldReset = false;
					}
					if (newArgument) {
						display ="";
						newArgument = false;
					}
					display += key;
				}
			}
		}
		if (externalDisplay!= null) 
			if (externalDisplay.isConnected())
				externalDisplay.show(display);
	}

	public String getDisplay() {
		return display;
	}

}
