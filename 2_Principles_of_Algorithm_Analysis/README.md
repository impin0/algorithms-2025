# Chapter two: Principles of algorithm analysis

#### Key Concepts:
- Implementation and Empirical Analysis
- Growth of functions
- Notations
- Basic Recurrences

### Implementation and Empirical analysis

**What is the goal of algorithm analysis?**  
To give us an understanding of the *performance characteristics* of the algorithm

**What is the first step of algorithm analysis?**  
The *empirical analysis*: given two algorithms to solve the same problem we run both to see which one takes longer.
The challenges of empirical analysis are:
1. Is to develop a correct and complete *implementation* (can be really hard for some complex algorithms)
2. Determine the *nature of the input data* and other factor that directly influence on the experiments to be performed
3. The implementation of both algorithms must be coded with the same *attention*

**What type of input data we could have?**  
- *Actual data*: enable us to truly measure the cost of the program in use 
- *Random data*: assure that our experiments test the algorithm and not the data
- *Perverse data*: assure that our programs can handle any input presented to them

**What are the most common mistakes when selecting an algorithm?**  
- Ignore performance characteristics
- Pay to much attention to performance characteristics

**What is a limit of empirical analysis?**  
When empirical studies start to consume a significant amount of time, *mathematical analysis* is called for, it also consume less resources and is more informative then empirical analysis

### Growth functions

**How can we perform mathematical analysis?**  
1. *Identify* the abstract operations on which the algorithm is based, separating the analysis from the implementation, allowing us to compare algorithms independent of particular implementations or particular computers
2. Determine the most *frequently* executed parts of the program for some sample runs
3. Study the data and model the *input* that might be presented to the algorithm

**What are the most often assumed type of input?**  
- Where the input is random -> we study the *average-case* performance of the program,  even though might be a mathematical fiction that is not representative of the data on which the program is being used
- Where the input is perverse -> we study the *worst-case* performance of the program, even though might be a bizarre construction that would never occur in practice

**What does it means to confront two algorithms through mathematical analysis?**  
Verifying what happen to the *time requirements* of an algorithm when the dimension of the *input grow*
Most algorithms have a *primary parameter N* that effects the running time most significantly.
The goal of using such parameter is to *express the resource requirements* of our programs in terms of N, using mathematical formulas that are as simple as possible and accurate for large values of the parameters

**What are the typically running times of most algorithms?**  
Most algorithms typically have running times proportional to one of the following functions:
- *1*: most instruction of most programs are executed once or just a few times, if the all the instruction of the program have this property we say that the program's running time is *constant*
- *log N*: When the running time of a program is *logarithmic*, the program gets slightly slower as N grows. This commonly occurs in programs that solve a big problem by transformation into a series of smaller problems. We can consider the running time to be less then a large constant
- *N*: Where the running time of a program is *linear*, is the case when a small amount of processing is done on each input element
- *N log N*: the N log N running time arises when algorithms solve a problem by breaking it up into smaller sub-problems, solving them independently and then combining the solutions
- *N^2*: when the running time of an algorithm is *quadratic*, that algorithm is practical for use on only relatively small problems. Usually are algorithms that process all pairs of data items (double-nested loops)
- *N^3*: when the running time of an algorithm is *cubic*, that algorithm is practical for use on only small problems. Usually are algorithms that process all triples of data items (triple-nested loops)
- *2^N*: few algorithms with *exponential* running time are likely to be appropriate for practical use, even though such algorithms arise naturally as brute-force solution to problems
- *N!*: *factorial* complexity (maximum complexity)

### Notations

**What allows us to suppress detail when we are analyzing algorithms?**  
To compute the complexity of an algorithm we use *asymptotic analysis*, which allow us to compare the growth rate of one function with another. In this case we apply it to the algorithm's execution time as a function of input size T(n). There are three asymptotic notations:
- O: Big O is the *asymptotic upper bound*
- Ω: Omega is the *asymptotic lower bound*
- θ: Theta is the *asymptotic tight bound*
 
**How the Big O notation works?**  
Given two functions $f(n)$ and $g(n)$, we say that $f(n) = O(g(n))$ "f(n) is bounded above by g(n) asymptotically" if there exist positive constant $c$ such that:

$$
0 <= f(n) <= c*g(n) for every n >= n_0
$$

**How the Omega Ω notation works?**  
Given two functions $f(n)$ and $g(n)$, we say that $f(n) = Ω(g(n))$ "f(n) is bounded below by g(n) asymptotically" if there exist positive constant $c$ such that:

$$
0 <= c*g(n) <= f(n) \text{for every} n >= n_0
$$

**How the Theta θ notation works?**  
Given two functions $f(n)$ and $g(n)$, we say that $f(n) = θ(g(n))$ "f(n) is tightly bounded by g(n) asymptotically" if there exist two positive constants $c_1$ $c_2$ such that:

$$
0 <= c_1*g(n) <= f(n) <= c_2*g(n) for every n >= n_0
$$

**What are some useful functions to convert real numbers in integers?**  
When `x` is a real number :  
`⌊x⌋` *floor of x*: largest integer lees then or equal to x
`⌈x⌉` *ceiling of x*: smallest integer greater than or equal to x
In C we can use `floor()` or `ceil()` from `math.h` to compute them when we are operating on floating point numbers

### Basic recurrence

**What are the recurrence relations?**  
Recurrence relations are formulas that express how the ==running time== of an algorithm for an ==input of size N== depends on the running time for smaller inputs.
They describe precisely the performance of recursive algorithms: by solving them, we can determine how the total running time growth as N increases

**What is the recursive relation that arise for a program that loops through the input to eliminate one item?**  
Example: eliminate an element at the time for an array of N elements, cost to eliminate the first element = N, cost to eliminate the second element = N - 1, cost to eliminate the third element = N - 2, ... , cost to eliminate the N element = 1
$C_N$ = Cost to eliminate N elements
$C_N = C_N-1 + N$    for    $N >= 2$    with    $C_1 = 1$
$= N(N + 1) / 2$ -> $O(N^2)$

**What is the recursive relation that arise for a recursive program that halves the input in one step?**  
$C_N = C_N/_2 + 1$    for    $N >= 2$    with    $C_1 = 1$
Solution: $C_N$ is $lg N$ assuming $N = 2^N$ -> $O(log(N)$

**What is the recursive relation that arise for a recursive program that halves the input but perhaps must examine every item in the input?**  
$C_N = C_N/_2 + N$     for     $N >= 2$      with     $C_1 = 0$
Solution: $C_N$ is about   $2N$ -> $O(N)$
Only precisely defined when N is a power of 2

**What is the recursive relation that arise for a recursive program that has to make a linear pass through the input, before, during, or after splitting that input into two halves:?**  
$C_N = 2C_N/_2 + N$      for     $N >= 2$      with     $C_1 = 0$
Solution: $C_N$ is about $NlgN$ 
Is the solution used for the divide-and-conquer algorithms

**What is the recursive relation that arise for a recursive program splits the input into two halves and then does a constant amount of other work:?**  
$C_N = 2C_N/_2 + 1$     for     $N >= 2$      with     $C_1 = 1$
Solution: $C_N$ is about $2N$
