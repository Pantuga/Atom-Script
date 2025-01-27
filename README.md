# Atom Script

An esotheric programming language writen only with elements from the periodic table

## Version

0.1.0 - More or less fleshed out

# The Language

Atom Script is an interpreted esotheric programing language, where all you write is elements from the periodic table.
It is inspired in other esotheric languages, such as brainfuck.

It works by changing or reading the values of three C++ vectors, one for each data type in the language: `int`, `bool`(still unnused) and `string`, and a `pointer`, which tells the code where to read from those vectors.

For more detail on how to use the language, see the wiki.
*Note: the wiki only has information about the version 0.0.2. For information on the latest version, read the comments inside the `ats_interpreter.hpp` source file (after each `case [element]:`).*