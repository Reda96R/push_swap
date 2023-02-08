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

## The algorithm:

There are many sorting algorithms out there, one of them is to use [Radix sort](https://brilliant.org/wiki/radix-sort/), or you can use any other sorting algorithm as long as it has the right complexity to get you full points, while many of my peers devided the stacks into small little chunks, I will try to find a more simple solution that can get me the fulll score.

my algorithm will take [Yigit Ogun](https://medium.com/@ayogun)’s algoithm as a starting point, it mainly consists of two parts, the first is to push everything to stack B in descending order, then push them back to stack A where they will be kind of automatically sorted.

So let’s get started:

### 1/ Pushing the starting numbers to B:

The first step in the first part is to push two random numbers from A to B, this step will set a strating point to which we’ll be sorting the numbers pushed in B, by comparing them to these two numbers.

### 2/ Finding the cheapest number:

From this point, we will search for the number that requires less operations in order to push it in the right place in stack B, so we will calculate one by one for each number in stack A until we find the cheapest one and push it in the right place in B, we will continue the calculations until we have only three numbers left.

### 3/ Last three numbers:

This case is the esiest to solve, because we don’t need to push enything, but instead we only need one operation in most cases, except for the case where we have numbers in descending order, in this case we’ll need two operations to sort everything.

### 4/ Pushing back to A:

It is time to push everything back from B to A, but before we make sure that it is pushed in the corect place, if not we’ll rotate A until the right position come up.

### 5/ The Grand Finale:

This is the final step, where put the minimum number at the top of the stack, and with that we’ll have our stack sorted and complete.

If you want a more detailed explanation of the algorithm with examples check this [article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

## Resources:

- [Time Complexities of all Sorting Algorithms](https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/)
- [Counting Sort](https://brilliant.org/wiki/counting-sort/)
- [Radix Sort](https://www.javatpoint.com/radix-sort)
