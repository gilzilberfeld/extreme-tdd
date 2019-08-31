import Calculator from '../apps/calculator/CalculatorDisplayApp';
  


it('display shows empty', () => {
  let c = new Calculator(null);
  var result = c.theDisplay;
  expect(result).toBe("");
});

it('display shows one', () => {
  let c = new Calculator(null);
  c.press("1");
  var result = c.theDisplay;
  expect(result).toBe("1");
});

it('display shows twelve', () => {
  let c = new Calculator(null);
  c.press("1");
  c.press("2");
  var result = c.theDisplay;
  expect(result).toBe("12");
});

it('CancelTheFirstNumber', () => {
  let c = new Calculator(null);
  c.press("1");
  c.press("C");
  var result = c.theDisplay;
  expect(result).toBe("");
});

it('CancelTheFirstNumber2', () => {
  let c = new Calculator(null);
  c.press("1");
  c.press("C");
  c.press("2");
  var result = c.theDisplay;
  expect(result).toBe("2");
});

it('CancelAfterOperation', () => {
  let c = new Calculator(null);
  c.press("1");
  c.press("+");
  c.press("C");
  var result = c.theDisplay;
  expect(result).toBe("");
});


it('CancelAfterOperation', () => {
  let c = new Calculator(null);
  c.press("1");
  c.press("C");
  c.press("+");
  var result = c.theDisplay;
  expect(result).toBe("");
});
