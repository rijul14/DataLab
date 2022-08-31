# DataLab

Your goal is to modify `bits.c` so that it passes all the tests in `btest`
without violating any of the coding guidelines of `dlc`.


## How to Start Coding

- Connect to the server on the terminal and clone your assignment repository.
- Connect to the server with VS Code remote and open the assignment directory.
- You can build with `CTRL + SHIFT + b` or by running `make` in the terminal.


## Coding Rules

For each function in `bits.c`, you should replace the `return 2` statement with
one or more lines of C code that satisfies the given specification using only
the allowed number/type of operators.

There are strict rules for your code:

- **Variable declarations should be all at the beginning of a function**,
  like this (the dlc compiler requires this):

  ```c
  int f(arg1, arg2, ...) {
      int var1 = Expr1;       /* all variables declared here      */
      ...
      int varM = ExprM;

      varJ = ExprJ;           /* no declarations after this point */
      ...
      varN = ExprN;
      return ExprR;
  }
  ```

- Do not include the `<stdio.h>` header (it confuses the `dlc` compiler). You
  can still use `printf` for debugging; but **remove any `printf` before
  submitting your solution.**

- For **integer puzzles**, each "Expr" should use only:
  1. Integer constants `0` through `255` (`0xFF`), inclusive. You are
      not allowed to use big constants such as `0xffffffff`.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations `!` `~`
  4. Binary integer operations `&` `^` `|` `+` `<<` `>>`

  Some of the problems restrict the set of allowed operators even further. But
  you can never:
  1. Use control constructs (`if`, `do`, `while`, `for`, `switch`)
  2. Use/define macros.
  3. Define additional functions inside `bits.c`.
  4. Call any functions.
  5. Use any other operations, such as `&&`, `||`, `-`, or `?:`
  6. Use any form of casting.
  7. Use any data type other than `int` (e.g., arrays, structs, or unions.)

  Example of allowed coding style:

  ```c
  int multiply2(int x) {
     return x << 1;
  }

  int multiply2_add1(int x) {
     int result = (x << 1);
     result += 1;
     return result;
  }
  ```

- For **floating-point puzzles**, the coding rules are less strict.
  You are allowed to use:
  - Looping and conditional control;
  - `int` and `unsigned int`;
  - Arbitrary integer and unsigned constants;
  - Any arithmetic, logical, or comparison operations on int or unsigned data.

  You are still forbidden to:
  1. Use/define macros.
  2. Define additional functions inside `bits.c`.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than `int` / `unsigned int`
     (e.g., arrays, structs, or unions.)
  6. Use floating point data types, operations, or constants.


## How to Check Your Grade

**Use `dlc` to check legality:** `./dlc bits.c`

Each function has a maximum number of operations (integer, logical, or
comparison) that you are allowed to use for its implementation (note that
assignment `=` is not counted; you may use as many of these as you want without
penalty.)

`dlc` returns silently if there are no problems with your code; otherwise it
prints messages that flag any problems.  Running `./dlc -e bits.c` causes `dlc`
to print counts of the number of operators used by each function.

**Use `btest` to check correctness:** `./btest`

The `Makefile` in this directory compiles your version of `bits.c` with
additional code to create a program named `btest` used to test the correctness
of your solution.

To compile and run `btest`, type `make` and `./btest`. **You will need to
recompile `btest` each time you change your `bits.c` solution.**

When `btest` detects an error in one of your functions, it prints out the test
that failed, the incorrect result, and the expected result, and then terminates
the testing for that function.

Here are the command line options for `btest`:

  ```shell
  ./btest -h
  Usage: ./btest [-hg] [-r <n>] [-f <name> [-1|-2|-3 <val>]*] [-T <time limit>]
    -1 <val>  Specify first function argument
    -2 <val>  Specify second function argument
    -3 <val>  Specify third function argument
    -f <name> Test only the named function
    -g        Format output for autograding with no error messages
    -h        Print this message
    -r <n>    Give uniform weight of n for all problems
    -T <lim>  Set timeout limit to lim
  ```

Examples:

- Test all functions for correctness and print out error messages:

  ```shell
  ./btest
  ```

- **Test function `foo` for correctness:** (faster)

  ```shell
  ./btest -f foo
  ```

- **Test function `foo` for correctness with specific arguments:** (much faster)

  ```shell
  ./btest -f foo -1 27 -2 0xf
  ```


## How to Submit

Before submitting, run `./grade` to check your grade.

To submit:

- Add your changes to the index: `git add .`
- Commit your changes: `git commit -m "My submission"`
- Push to GitHub: `git push`

The push date/time will be used to compute late days. So, don't push other
commits after the deadline (unless you want to use late days).
