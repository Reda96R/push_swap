# ::: push_swap :::

`This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.`

## Project overview :

This project is one of the algorithm projects that you’ll tackle on your way through the 42 network school curriculum, and it is about sorting a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) with the least amount of instructions possible (*less than 5500 is considered perfect*), and to make things more interesting the only way you can manipulate data in the stack is with a limited set of instructions.

so the project subject gives us two stacks, A and B, A contains a random list of unorganized negative and/or positive numbers, that should be sorted so that A is organized from smallest to largest, stack B is there to help us with the sorting.

we’re allowed to use a limited set of instructions or operations in order to manipulate the stacks:

- ***sa**: swap a — swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).*
- ***sb**: swap b — swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).*
- ***ss**: equivalent to as and sb combined.*
- ***pa**: push a — take the first element at the top of b and put it at the top of a. Do nothing if stack b is empty.*
- ***pb**: push b — take the first element at the top of a and put it at the top of b. Do nothing if stack a is empty.*
- ***ra**: rotate a — shift up all elements of stack a by 1. The first element becomes the last one.*
- ***rb**: rotate b — shift up all elements of stack b by 1. The first element becomes the last one.*
- ***rr**: equivalent to ra and rb combined.*
- ***rra**: reverse rotate stack a — shift down all elements of stack a by 1. The last element becomes the first one.*
- ***rrb**: reverse rotate stack b — shift down all elements of stack b by 1. The last element becomes the first one.*
- ***rrr**: equivalent to rra and rrb combined.*

first we should treat our stack depending on how many numbers it contains:

1. n = 3 : no more than 3 instructions,
2. n = 5 : no more than 12 instructions,
- n = 100 :
    - 5 points if the instructions are less than 700
    - 4 points if the instructions are less than 900
    - 3 points if the instructions are less than 1100
    - 2 points if the instructions are less than 1300
    - 1 points if the instructions are less than 1500
- n = 500 :
    - 5 points if the instructions are less than 5500
    - 4 points if the instructions are less than 7000
    - 3 points if the instructions are less than 8500
    - 2 points if the instructions are less than 10000
    - 1 points if the instructions are less than 11500

## Resources:

- [Radix sort](https://brilliant.org/wiki/radix-sort/)
- [Counting sort](https://brilliant.org/wiki/counting-sort/)
- [Counting Sort Algorithm](https://www.interviewcake.com/concept/java/counting-sort)
- [Radix Sort](https://www.javatpoint.com/radix-sort)
