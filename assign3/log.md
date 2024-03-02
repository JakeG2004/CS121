# Assignment 3: Stacks <br> Jake Gendreau <br> March 1, 2024 <br> Program Log

## Time Requirements

* This program took me about 9 hours to complete. However, the character implementation only took about 5 hours. Getting multi-character numbers to work took a while extra.

## Things I encountered while making this program

* I didn't understand how the provided process works until I tried to implement it from a more vague set of instructions. Once I understood it, implementing it was significantly easier.

* I initially had it reading character by character, which does work for the provided problems, but I wanted to make it work with all of the natural numbers instead. Getting that to work was a little harder, and I ended up implementing a que to hold the tokens.

* I learned how to use valgrind to check for memory leaks, and how to use the GDB CLI to debug programs. It was very helpful for keeping track of where bugs were coming from.

* I forgot how to make my .h and its implementation to compile, but a quick text to friends helped me out there.

* My pop() function kept throwing errors. It turns out that I didn't have any sort of integrated protection for reading outside of bounds. GDB helped me to identify and fix the issue.