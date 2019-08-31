import React from 'react';
//import OperationType from 'OperationType.js';

const OperationType  = {
	Plus: 0,
	Div: 1
};

function CalculatorApp() {
  return (
    <div >
      <header>
        <p>
          Result: <textarea value={this.state.value} />
        </p>
      </header>
    </div>
  );
}

class Calculator {
	
	
	lastArgument=0;
	newArgument = false;
	shouldReset = false;
	
	constructor(externalDisplay){
		this.externalDisplay = externalDisplay;
		this.display = "";
		
	}

	get theDisplay() {
		return this.display;
	}
		
	press(key) {
		if (key === "C") {
				this.display = "";
		}
		else {
			if (key === "+") {
				this.lastOperation = OperationType.Plus;	
				this.lastArgument =  parseInt(this.display);
				this.newArgument = true;
			} 
			else {
				if (key === "/") {
					this.lastOperation = OperationType.Div;	
					this.lastArgument =  parseInt(this.display);
					this.newArgument = true;
				}
				else 
					if (key === "=") {
						this.currentArgument = parseInt(this.display);
						if (this.lastOperation === OperationType.Plus) {
							this.display = (this.lastArgument + this.currentArgument).toString();
						}
						this.shouldReset = false;
					}
					else {
						if (this.shouldReset === true) {
							this.display = "";
							this.shouldReset = false;
						}
						if (this.newArgument) {
							this.display ="";
							this.newArgument = false;
						}
						this.display += key;
					}
				}
			}

			if (this.externalDisplay!= null) 
				if (this.externalDisplay.isConnected())
					this.externalDisplay.show(this.display);
		
			//setState({value: this.theDisplay});
		};


}       


export default Calculator;

