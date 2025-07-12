1. A higher-order function takes a function as an argument, 
and also returns a function as well, 
an example of which is a decorator.
Versus a functor, 
which are simply object that are treated like a function

2. a first class object is an object that has every right that all other variables have,
including getting passed as a parameter, passing a value as a parameter, 
be constructed at runtime, returned, assigned to a variable, among much more

3. inner functions are functions defined inside of other functions, 
so the inner function of a nested function so to speak. 
It is mainly used to be the closest python gets to encapsulation,
a core programming concept that is absent in python.
The inner function is the actual thing that gets passed when a decorator is called.

4. The @ symbol is called syntactic sugar because it is 
very easy to read and understand what is going on in code. 
The advantage of using it with decorators is it extends the 
functionality of the function or classes defined within the decorator

5. @property and @<property_name>.setter used within a class attributes 
the private instance value to the method below it using these allows us 
to implement functional encapsulation within our code when using classes.
Something that is otherwise unavailable to us when coding in python.
For example:
@property
def someGetterFunction(self)
	return self.__someGetterFunction
allows us to access the value of this method, but will no longer allow 
us to modify the value within it (without using the proper setter method)
vs just using
def someGetterFunction(self)
	return self.__someGetterFunction
we can still change the value in this method at any point at any time we want