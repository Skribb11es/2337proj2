# Requirements for program

The requirements can be found in `samples\F23_CS2337.pdf`, this outlines all that needs to be achieved and the restrictions upon which I am able to operate for this assignment. Unfortuonatly we are unallowed to use vectors, which presumibly would make my life a hell of a lot easier, but alas im stuck using arrays that break my program...

# Issue

`main.cpp` reaches lines 235 - 237, executes the loop, and then terminates the program. Every statement beyond the for loop is just completly ignored, why I dont know. It appears to be an issue with calling a function from the indexed class, however if the index is defined, not by a variable, the program runs just fine. 

Ex. `cout << regualrArr[0]->getAmtSpent() << endl;`

However, if the index of the array is a variable from a loop, it will still execute the code within the loop just fine, however any statements after that will be ignored. There are no errors, or warnings, it just terminates the program before running the remaining code.

# What has been tried thus far

I've tried using standard for loops
Ex. `for(int i = 0; i<regularLen; i++)` 
this got me nowhere...

I've tried using while loops for the same thing Ex. `int i = 0; while(i<regularLen) {i++}` which also got me nowhere...

I've tried to increment the pointers by using ++, this is the current implementation on lines 235-237

I've tried passing the index in to a function, function on line 35, again nothing, however if the index was hardcoded it ran fine, again an issue with the index being a variable.

And lastly I tried having the loops within the function, again to no avail, the function is called, and then it terminates the program. Doing the exact same thing it was without the function...

# IDK

I spent ~2 hours trying to fix this last night, however I was unable too, because every lick of my conventional knowledge about programming, apparently doesn't apply to C++. Why? I have no clue, but being a Python developer by trade is definitely not helping my case with already disliking low-level languages...