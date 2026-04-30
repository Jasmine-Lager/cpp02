# CPP02
*This project has been created as part of the 42 curriculum by jlager*

## Discription

Again not doint anything I dont have to so no ex03/

This module works with Orthodox Canonical Form (OCF) = class must have these 4: 
1. Default constructor 
2. Copy constructor 
3. Copy assignment operator overload 
4. Destructor 

**ex00/ My First Class in Orthodox Canonical Form** - the "skeleton" class, it doesn't do math yet, just prints messages to show that the constructors and destructor are working correctly

**ex01/ Towards a more useful fixed-point number class** - making it hold real values, we added constructors to convert int and float into fixed-point using bit-shifting (scaling by 256)... also added toInt() and toFloat() to get those values back

**ex02/ Now we’re talking** - the "pro" version, we overloaded all the operators—math (`+, -, *, /`), comparison (`>, <, ==`), and increment/decrement (`++, --`) — so the class behaves like a built-in number type. added static min and max functions too

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
- Concept clarification: I had Claude and Gemini explain the topics and help me with the bit-shifting logic for the math operators