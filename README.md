# CPP02
*This project has been created as part of the 42 curriculum by jlager*

## Discription

Again not doint anything I dont have to so no ex03/

This module works with Orthodox Canonical Form (OCF) = class must have these 4:
1. Default constructor
2. Copy constructor
3. opy assignment operator overload
4. Destructor

**ex00/ My First Class in Orthodox Canonical Form** - understanding the difference betweeen fixed and floating numbers and how they can be used in C++... untill now every number we used was basically either an integer or a floating-point number

**ex01/ Towards a more useful fixed-point number class** - 

**ex02/ Now we’re talking** - 

## Instructions
...as usual: 
**Available commands for each excercise:**
- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove objects and executable
- `make re` - Recompile everything if there were any changes to the code (especially in the header file *.hpp or Makefile)

### Execution
```bash
./[executable-name]
```

## Resources
- [Printing floating point numbers | Cprogramming.com](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html) - gives a readable code example for printing floating point numbers
- [Article from Berkeley University](https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) - explains how using fixed-point numbers allows for efficient arithmetic operations, but sacrifices range and precision compared to floating point numbers

### AI Usage
- Concept clarification: I had Claude explain the topics


# CPP02
*This project has been created as part of the 42 curriculum by jlager*

## Discription

Again not doint anything I dont have to so no ex03/

This module works with Orthodox Canonical Form (OCF) = class must have these 4: 
1. Default constructor 
2. Copy constructor 
3. Copy assignment operator overload 
4. Destructor 

**ex00/ My First Class in Orthodox Canonical Form** - understanding the difference betweeen fixed and floating numbers and how they can be used in C++... untill now every number we used was basically either an integer or a floating-point number.
this one is just the "skeleton" where we set up the raw bit storage and the canonical form basics.

**ex01/ Towards a more useful fixed-point number class** - making the class actually hold real values.  added constructors for `int` and `float` that use bit-shifting (shifting left by 8) and `roundf` to scale numbers into our fixed-point format. also added `toFloat()` and `toInt()` to get our values back, plus an `operator<<` overload so we can finally just `std::cout` the object directly. 

**ex02/ Now we’re talking** - the final "useful" version where we overload basically everything.  added comparison operators (like `>`, `<`, `==`), arithmetic operators (`+`, `-`, `*`, `/`), and both pre/post increment/decrement operators.  also threw in some static `min` and `max` functions so we can compare fixed-point objects easily.  multiplication and division are the tricky parts here because you have to adjust the scaling so the decimal point stays in the right spot.

## Instructions
...as usual: 
**Available commands for each excercise:**
- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove objects and executable
- `make re` - Recompile everything if there were any changes to the code (especially in the header file *.hpp or Makefile)

### Execution
```bash
./[executable-name]
```

## Resources
- [Printing floating point numbers | Cprogramming.com](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html) - gives a readable code example for printing floating point numbers
- [Article from Berkeley University](https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) - explains how using fixed-point numbers allows for efficient arithmetic operations, but sacrifices range and precision compared to floating point numbers

### AI Usage
- Concept clarification: I had Gemini explain the topics and help me with the bit-shifting logic for the math operators.
- Gemini filled in the information in this readme
