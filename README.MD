# Push_swap

Push_swap is a school42 project. The aim of this project is to create an optimized algorithm.
We have to create two programs: `checker` and `push_swap`.

### Checker
Checker program has to examing our `./push_swap` program and print `OK` if instructions sort stack properly or `KO` otherwise.

##### Checker algorithm
- checking flags and other arguments on valid input.
- checking instructions giving to our program(using AVL_tree to choose right operation functions) on valid input.
- checking that instructions sort stack properly.
- printing result: `OK` or `KO`.

Checker supports bonus flags:
- `./checker -f` reading numbers from file

### push_swap
push_swap is a main program. It has give to us list of instructions to sort stack *A* in ascending order(less number on the top of the stack a) using stack *B* as an assistant.
Moreover, this list should be as small as possible.

For example, we have to match following values:
- 3 numbers - 3 operation
- 5 numbers - 12 operations
- 100 numbers - 700 operations
- 500 numbers - 5400 operations

##### push_swap algorithm
I use algorithm based on quicksort.
I find a median(m1) of all numbers in stack *A* then find another median(m2) of all numbers that less than previous median.
I start pushing numbers that less than median(m1) to stack *B* and additionally sort these numbers according median(m2) - i push smaller numbers to the bot of stack *B* using `rrb` comand and leave bigger numbers on the top of the stack *B*.
So i do it until 3 numbers are left in stack *A*.
Then i am sorting them and start pushing numbers from *B* to *A*.
if i pushed more than 3 numbers i am doing the same algorithm from the start but applicable to stack *A* - find medians, smaller number pushing to *A* and in *A* additionaly sorting - greater number then second median leave on top of *A*, smaller going down by `rra` command.
And so its going on until the stack is sorted.

push_swap supports bonus flags:
- `./push_swap -f` reading numbers from file
- `./push_swap -v` print stack after execution every operation
- `./push_swap -c` print output in color

testing and compiling on MacOS Sierra 10.12.6, clang 900.0.39.2