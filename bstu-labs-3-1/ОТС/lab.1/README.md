# Random numbers generators

### Generators

Generators are listed in generators.h.
Format of generators:

```cpp
double generateRandomNumbers_<method name>(std::vector<double> params)
{...}
```

where `<method name>` is name of method used to generated a
random number, `<params>` - parameters for random numbers
generation.

### Analysis

To make analysis of a generator you
can use Analysis class. It gets in
random number generator and generator
for its parameters.

#### Usage of analysis:

```c++
Analysis mixed(
		generateRandomNumbers_mixed,
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				double(i),      // lambda
					1.0,	    //mu
					1000.0,	    //M
					123.0,	    // X<0>
					100		    // number of iterations
			};
		});
	mixed.setGeneratorName("Mixed");
	mixed.setAnalizedParameterName("Lambda");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot(false);
```

The above example demonstrates how to use main
facilities of the Analysis class. Lambda expression
(second parameter of the constructor) represents
generator of parameters for random number generator.
