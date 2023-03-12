`This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.`

# Project overview :

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

# Coding plan:

My implementation will consider three steps as follows:

### 1/ Initializing & Parsing:

In this step we’ll need to first initialize stacks A and B, then parse the input to these stacks, at this phase we should make sure to handle errors related to input.

### 2/ Sorting stacks:

This is where it gets interesting, because this is where we’ll need an algorithm to sort stacks utilizing as few operations as possible.

### 3/ Freeing stacks and terminating:

This is the last step, where we’ll be freeing resources used by the program while handling leaks and errors related to memory.

so our main function will look something like this:

```c
int	main(int ac, char *av[])
{
	t_stacks	stacks;

	ft_init_stacks(&stacks, ac, av); //Initializing & Parsing
	ft_sort_stacks(&stacks); //Sorting stacks
	ft_clean_stacks(&stacks); //Freeing stacks and terminating 
	exit(EXIT_SUCCESS);
	return (0);
}
```

# Walking the walk:

## Parsing:

first we need to define our stacks, and for that we will use linked lists. linked lists are simply a [linear data structure](https://www.upgrad.com/blog/what-is-linear-data-structure/) which means each element is linked directly to its previous and next elements,

every linked lists consist of nodes, and each node consists of two parts, the first is where the data is stored, the second part contains the address of another node.

```c
                    |-------------|      |-------------|
          HEAD ---> | data | next | ---> | data | next | ---> NULL
                    |-------------|      |-------------|
```

so our linked list starts with a `HEAD` which saves the address of the first node, and the last node’s next portion points to `NULL`, which marks the end of our list.

so we’ll have something like this:

```c
/* This is our stack */
typedef struct s_stack
{
	long			nbr; //The number
	long			index; //I'll explain later on why I need this index
	struct s_stack	*next; //Next element
	struct s_stack	*prev; //Previous element
}t_stack;

/* We grouped both stacks for easier manipulation */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}t_stacks;
```

for the parsing step we’ll make the function `ft_init_stacks()`, it should first handle errors related to input,

```c
void	ft_init_stacks(t_stacks *stacks, int ac, char *av[])
{
	int		i;
	size_t	j;

	ft_bzero(&stacks, sizeof(t_stacks)); //to get rid of garbage values in stacks
	if (ac == 1) //if we have only one argument
		exit(EXIT_SUCCESS);
	i = 1;
	while (ac > i)
	{
		j = 0;
		if (!av[i][0]) //if one of the args is empty
			ft_error(stacks);
		while (av[i][j])
		{
			while (av[i][j] && ft_space(av[i][j]))
				j++;
			if (!av[i][j])
				break ;
			if (!ft_parser(&(stacks->a), &(av[i][j])))
				ft_error(stacks);
			while (av[i][j] && !ft_space(av[i][j]))
				j++;
		}
		i++;
	}
}
```

if we encounter an error, we’ll utilize the function `ft_error()` that will print an error message then it will free stacks by calling `ft_cleaner()`, if not, and everything went well, the `ft_parser()` function will handle the parsing,

```c
int	ft_parser(t_stack **stack, char *str)
{
	long	n;

	if (ft_type_check(&n, str) && ft_fill_stack(stack, n))
		return (1);
	return (0);
}
```

so first we will check the validity of our args with the help of `ft_type_check()` that will make sure that our args contain only digits, if so it will convert the content into an `int` and stores its value in `n`, then our stacks will be filled with `n` utilizing `ft_fill_stack()`.

## Sorting:

Now we arrived in the part where we’ll have to sort or stacks, I’ll divide this part into two portions, the first will discuss the algorithm used, while the other will focus on the implementation.

### The Algorithm:

there are many algorithms that we can adopt to sort our stacks. but again our main goal here is to have the full score, and to do that we must adopt an algorithm that will do the sorting in the most efficient way possible, one of the most popular algorithm is to divide the stacks into small little chunks, if your more into this algorithm you check this [article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a),

first we will try to deal with the three numbers case, which is the simplest one, and to do that we’ll split our function into three possibilities:

1. the first number is the smallest,
2. the first number is the biggest,
3. the first number is the middle one.

```c
void	ft_case_three(t_stack **a)
{
	t_stack	*last;

	last = ft_last(*a);
	if (*(*a)->nbr == ft_min_finder(*a)) //possibility 1
	{
		ft_rev_rot(a, 1);
		ft_swap(a, 1);
	}
	else if (*(*a)->nbr == ft_max_finder(*a)) //possibility 2
	{	
		ft_rotate(a, 1);
		if (!ft_check_sorting(*a))
			ft_swap(a, 1);
	}
	else //possibility 3
	{
		if (*last->nbr == ft_max_finder(*a))
			ft_swap(a, 1);
		else
			ft_rev_rot(a, 1);
	}
}
```

## Resources:

- [What is a stack?](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/)
- [Linked lists](https://www.programiz.com/dsa/linked-list)
- [Time Complexities of all Sorting Algorithms](https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/)
- [Counting Sort](https://brilliant.org/wiki/counting-sort/)
- [Radix Sort](https://www.javatpoint.com/radix-sort)
-
