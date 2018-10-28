# Learning C the Hard way 

based on the book by the same name the exercises map to the one given in the book. 

## Pointers 
There are four useful things that you can do with pointers
* Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings and structs 
* Pass a large blocks of memory to functions with a pointer, so that you don't have to pass the whole thing. 
* Take address of a function, so you can use a dynamic call back. 
* Scan complex chuncks of memory, converting bytes off of a network socket into data structs or parsing files. 
For almost everything else we need to use arrays. 
