# ::: push_swap :::

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

/* We grouped both stacks for easier manipulations */
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

<aside>
💡 The `->` operator has higher precedence than the `*` operator, so for example without the parentheses, the expression `*stack->next` would be interpreted as `*(stack->next)`. This would attempt to dereference the next member of stack before accessing its next member, which is not what we want.
By using parentheses to group together the expression `*stack`, we ensure that the `->` operator is applied to the inner pointer first, and then the `*` operator is applied to the result of that expression. This allows us to access the next member of the `t_stack` struct pointed to by `*stack` as intended.

</aside>

Now we’ll try to defrag more complex cases till we have our base case.

## First sort:

first thing we’ll try to do is to have a starting point and for that we’ll push the two first numbers from `stack a` to `stack b`, by this we’ve made ourselves a **max** and a **min** numbers in `b` , this will help us form a semi-sort by pushing numbers from `a` into the right place in `b`.

```c
void	ft_first_sort(t_stacks **stacks)
{
	int	counter;

	counter = 1;
	while (ft_stack_size((*stacks)->a) > 3 && counter++ < 3
		&& !ft_check_sorting((*stacks)->a))
		ft_push(&(*stacks)->b, &(*stacks)->a, 0);
}
```

the next step is to push all the numbers in a , till the last three numbers, but before every push, we’ll make our calculations so we push that number in the right place with the minimum operations possible, for that we’ll divide our work into three steps

### Finding the right place:

In this is step we’ll try to find the right place for our number in order to be pushed to b, and for that we’ll create this function:

```c
int ft_b_placer(t_stack stack, int nbr) //nbr is the number that we want to push
{
	int     i; //i repersents the index of the place where nbr should go
	t_stack *tmp;

	i = 1;
	if (nbr > *stack->nbr && nbr < *ft_last(stack)->nbr)
		i = 0;
}
```

the first case is where the number should go in the top of the stack, which means i = 0;

```c
else if (nbr > ft_max_finder(stack) || nbr < ft_min_finder(stack))
	i = ft_index_finder(stack, ft_max_finder);
```

the second case is where **nbr** is the new **min** or **max** in the stack, in this case we’ll try to put it close to the current max.

```c
else
{
	tmp = stack->next;
	while (*stack->nbr < nbr || *tmp->nbr > nbr)
	{
		stack = stack->next;
		tmp = stack->next;
		i++;
	}
}
```

this is the last case, where we’ll alternate through the whole stack until we find the right place, and to do that, we compare our number with the **current** and **next** in `stack a`.

### Choosing the best rotations combination:

next we need to find the operations needed to put **nbr** in the place that we calculated using `ft_b_placer()` , and by operations I mainly mean `rotations` and `push` , and to do that we need to calculate how many movements each rotation combination will need.

```c
int     ft_ra_rb(t_stacks *stacks, int nbr)
{
        int i;

        i = ft_b_placer(stacks->b, nbr); //here we identify our target id
        if (i < ft_index_finder(stacks->a, nbr))
                i = ft_index_finder(stacks->a, nbr);
        return (i);
}
```

to find how many rotations are needed , we simply rely on the index provided by `ft_b_placer()`

but bare in mind that we also calculating rotations for `stack_a` and for that we should consider the id of our number in `stack_a` .

```c
int ft_rra_rrb(t_stacks *stacks, int nbr)
{
	int i;

	i = 0;
	if (ft_b_placer(stacks->b, nbr))
		i = ft_stack_size(stacks->b) - ft_b_placer(stacks->b, nbr);
	if (ft_index_finder(stacks->a, nbr) && (i < ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr)))
		i = ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr);
	return (i);
}
```

this one is almost the same, the difference is that we need to check in reverse, in other words, instead of checking the `id`, we’ll check `stack_size - id` .

```c
int ft_rra_rb(t_stacks *stacks, int nbr)
{
	int i;

	i = 0;
	if (ft_index_finder(stacks->a, nbr))
		i = ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr);
	i = ft_b_placer(stacks->b, nbr) + i;
	return (i);

}
```

```c
int	ft_ra_rrb(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_b_placer(stacks->b, nbr))
		i = ft_stack_size(stacks->b) - ft_b_placer(stacks->b, nbr);
	i = ft_index_finder(stacks->a, nbr) + i;
	return (i);
}
```

after finding how many operations each rot_comb will need, now it’s time to choose the best one when it comes to efficiency, which is the work of `ft_rot_comb_ba()` .

### Applying the rotations:

after deciding which rotations will be made, now we comeback to our `ft_road_to_three()` function, where we’ll apply the rotations

```c
while (i >= 0) // each ft_app_x_y() returns -1 after applying the rotations
		{
			if (i == ft_ra_rb(*stacks, *tmp->nbr))
				i = ft_app_ra_rb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_rra_rrb(*stacks, *tmp->nbr))
				i = ft_app_rra_rrb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_ra_rrb(*stacks, *tmp->nbr))
				i = ft_app_ra_rrb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_rra_rb(*stacks, *tmp->nbr))
				i = ft_app_rra_rb(&tmp2, *tmp->nbr, 1);
			else
				tmp = tmp->next;
		}
```

for the application, each `ft_app_x_y()` will apply a certain amount of rotations until all conditions are satisfied, let’s take for example, `ft_app_ra_rb()` ,

```c
int	ft_app_ra_rb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr
			&& ft_b_placer(stacks->b, nbr) > 0) //when both rotations are required
			ft_rr(&stacks->a, &stacks->b, 1);
		while (*stacks->a->nbr != nbr) //only ra is required
			ft_rotate(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0) //only rb is required
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2); //pushing nbr into the right place in b
	}
}
```

and after every application of rotations, a push to `stack_b` is made.

now after we left only three elements in stack_a, we can sort them easily using `ft_case_three()` and we can proceed to the next step.

## Second sort:

at this point our `stack_b` is semi-sorted, and `stack_a` contains only three sorted elements, now it’s time to push all elements back to `stack_a` , and to do that we’re going to follow a similar process to what we did before, 

so the first thing is to find the best place for our number to be, and for that we’ll need `ft_a_placer()` ,

```c
int	ft_a_placer(t_stack *stack, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr < *stack->nbr && nbr > *ft_last(stack)->nbr)
		i = 0;
	else if (nbr > ft_max_finder(stack) || nbr < ft_min_finder(stack))
		i = ft_index_finder(stack, ft_min_finder(stack));
	else
	{
		tmp = stack->next;
		while (*stack->nbr > nbr || *tmp->nbr < nbr)
		{
			stack = stack->next;
			tmp = stack->next;
			i++;
		}
	}
	return (i);
}
```

after that we chose the best rotation combination using `ft_rot_comb_ba()` , and then we apply them using our **appliers.**

## The Grand Finale:

This is the last step where we have emptied `stack_b` and our `stack_a` contains all the elements that are sorted, the only problem is that we need to bring the **min** number to the top of the stack, t do that we simply keep **rotate/rev_rotate** our stack until **min** is on the top.

```c
if (i < ft_stack_size(stacks->a) - i)
		{
			while (*stacks->a->nbr != ft_min_finder(stacks->a))
				ft_rotate(&stacks->a, 1);
		}
		else
		{
			while (*stacks->a->nbr != ft_min_finder(stacks->a))
				ft_rev_rot(&stacks->a, 1);
		}
```

## Resources:

- [What is a stack?](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/)
- [Linked lists](https://www.programiz.com/dsa/linked-list)
- [Time Complexities of all Sorting Algorithms](https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/)
- [Counting Sort](https://brilliant.org/wiki/counting-sort/)
- [Radix Sort](https://www.javatpoint.com/radix-sort)
