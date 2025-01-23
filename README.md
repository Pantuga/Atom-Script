# Atom Script

An esotheric programming language writen only with elements from the periodic table

## Version

0.0.1 - First tests

# The Language

Atom Script is an interpreted esotheric programing language, where all you write is elements from the periodic table.
It is inspired in other esotheric languages, such as brainfuck.

## Commands

As of now, the language is still extremely rudimentary, only containing 3 commands:
* H (hidrogen);
* He (helium);
* C (carbon).

Inside the interpreter, there are three important variables: `boolBuffer` (unnused yet), `intBuffer` and `strBuffer`.
All the commands do is change or read the values in these variables in some way.

### H (element no. 1)

`strBuffer = strBuffer + (char)intBuffer;`

The `H` command adds the value in `intBuffer` to the `strBuffer` string as a character.

**Note: the value coresponds to the ASCII charcater with that value**

### He (element no. 2)

`intBuffer += program[i];`

The `He _ He` command changes the `intBuffer` to the sum of every atomic number in between the two `He`s.

**For example:**

`He Li He` would make `intBuffer = 3`, as the atom number of lithium is 3.

### C (element no. 6)

`cout << strBuffer;`

The `C` command simply prints the value of `strBuffer` to the console.