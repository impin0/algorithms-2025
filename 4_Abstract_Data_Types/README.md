# Abstract Data Types

#### Contents:
- Introduction to ADT
- Abstract objects and collections of objects
- Pushdown Stack ADT
- Creation of a new ADT
- FIFO queues and generalized queues
- Duplicate and index items
- First class ADTs

### Introduction to ADT
**What are Abstract Data Types (ADT)?**  
An ADT is a data type (set of values and collection of operations on those values) that is accessed *only* through an *interface*.  
The part of the program that uses the ADT is referred as *client*, and the part that specifies the data type is the *implementation*

**Why they are important?**  
Because they allow us to build programs that use *high-level abstractions*, by separating the conceptual transformation that our programs perform on our data from any particular data-structure representation and algorithm implementation. In addition ADTs:
- have emerged as an efficient mechanism for organizing large modern software systems
- interface also defines a contact point between users and implementors

**What is an opaque interface?**  
We say that the interface is opaque when the representation of data and the functions that implement the operations are in the implementation and are completely *separated* from the client by the interface

### Abstract objects and Collections of objects

**What are the operations that build up collections of objects?**  
- *insert* a new object into the collection
- *delete* an object from the collection

**What is the ADT referred by those two operations?**  
They are *generalized queues* of ADT objects. We also need to include explicit operations to *initialize* the data structure and to *count* the number of items in the data structure (or test if empty), those operations can be put together the insert & delete operations by defining appropriate return values

### Pushdown Stack ADT
**Which is the most important data types that support insert and delete for collections of objects?**  
The *pushdown stack* is an ADT that comprises two basic operations: insert (push) a new item, and delete (pop) the item that was most recently inserted. Following the LIFO discipline

**Why the pushdown stack abstraction is so critical?**  
Because many computers implement basic stack operations in hardware to implement the function-call mechanism: save the current environment on entry to a function by pushing information onto a stack, and restore the environment by popping the information present on the stack

**How can we implement the stack ADT?**  
We can use:
- Arrays: where the items are put in the array, keeping track of the index of the top of the stack. Doing the *push* operation amount to storing the item in the array position indicated by the top-of-stack index, then incrementing the index. Doing the *pop* operation amounts to decrementing the index, then returning the item that is designates. The *initialize* operation involves allocating an array of the indicated size, and the *test if empty* operation involves checking whether the index is 0
- Linked lists, allowing our stack to grow and shrink gracefully. We keep the stack in reverse order (from the array implementation) from the most recently inserted element to the least recently inserted element. To *pop* we remove the node from the front of the list and return his item, to *push* we create a new node and add it to the front of the list. The *initiate* operation is not used.

**What are the difference between the two implementations?**  
They differ only by their performance characteristics (time and space used). The linked list uses more time for the push and pop operation, to allocate memory for each push and deallocate for each pop, if our application performs these operations a huge number of times we might prefer the array implementation.  
The array implementation uses the amount of space necessary to hold the maximum number of items expected throughout the computation, while the list implementation uses space proportional to the number of items but always uses extra space for one link per item. If we need a huge stack usually nearly full we prefer the array implementation, if such stack size varies dramatically we might prefer the list implementation

**What is a constrain of the array implementation?**  
We need to know the maximum size of the array before using it. This *constraint* is an artificial of our choice to use an array implementation; it is not an essential part of the stack ADT. If we use a high value this implementation will make inefficient use of space, if we choose too small out program might not work at all

### Creation of a new ADT
**How can we design a new ADT?**  
We can use the following process:  
1. Starting from developing a client program to solve an application problem, we identify the operations that seem crucial (what would we like to do with our data?)
2. Define an interface and write client code to test the hypothesis that the existence of the new ADT would make it easier to implement the client program
3. Are we able to implement the operations in the ADT with reasonable efficiency, if not we should understand the cause of this inefficiency and modify the interface to include operations better suited to efficient implementation
4. These modification affect the client program, and we modify it accordingly
5. After few iterations, we have a working client program and a working implementation. So we freeze the interface. At this point the development of the client program and implementation are separable

**Why splitting the program into three parts is a more effective approach?**  
- Separates the task of solving the high level problem from the task of solving the low level problem, allowing us to work on the problems independently
- Gives us a natural way to compare different algorithms and data structures for solving the problem
- Gives us an abstraction that we can use to build other algorithms
- Defines through the interface a way to check that the software is operating as expected
- Provide a mechanism that allow us to upgrade to new representations without changing the client program

### FIFO queues and generalized queues
**What is another fundamental ADT?**  
A FIFO (First In First Out) queue is an ADT that comprises two basic operations: insert (put) a new item, and delete (get) the item that was least recently inserted.

**How can we implement a FIFO queue?**  
- We can use a *linked list*, keeping the items in the list in order from least recently to most recently (reverse from the stack implementation). We also maintain two pointers into the list: one to the beginning (so we can get the first element) and one to the end (so we can put a new element onto the queue)  
- We can also use *arrays* but with care to keep the running time constant for both the put and get operations. The performance goal dictates that we can not move the elements of the queue in the array, we maintain two indices into the array: one to the beginning of the queue and one to the end of the queue. We consider the contents of the queue to be the elements between the indices. To get an element we remove it from the beginning (head) of the queue and increment the head index, to put an element we add it to the end (tail) of the queue and increment the tail index. When it hits the end if the array we arrange it for it to wrap around to the beginning.

WE CAN IMPLEMENT THE GET AND PUT OPERATIONS FOR THE FIFO QUEUE ADT IN CONSTANT TIME USING EITHER ARRAYS OR LINKED LISTS

**What are the pros and cons of using an implementation vs another?**  
The same consideration discussed for Stack ADT apply to space resources used by FIFO queues.

**What is the most frequent uses of queues and stack?**  
They are used to postpone computation. Although many applications (that involve a queue of pending work) operate correctly no matter what rule is used for delete, the overall running time or other resource usage may be dependent on the rule.

**How can we evaluate the effectiveness of a particular ADT?**  
We need to consider two costs: 
- implementation cost: which depends on our choice of algorithm and data structure for the implementation
- decision-making rule cost: is the performance cost arising from how the client uses the ADT's operations

**What ADT is a super set of the Stack and FIFO queues?**  
The *generalized queue* is the general ADT of Stack and FIFO queues. Those instances of generalized queues differ in only the rule used to remove an item. 

**What are other instances of the generalized queue ADT?**  
- The *random queue* where the rule is to remove a random item, the client get any items on the queue with equal probability. We can implement the operations in constant time using an array representation. It is an important ADT because serves as the basis for randomized algorithms
- The *priority queue* where the items have keys and the rule for deletion is "remove the item with the smallest key"
- The *symbol tables* are generalized queues where the items have keys and the rule for deletion is "remove an item whose key is equal to a given key, if there is one"

**How can we describe queues in a different way?**  
Instead of identify items according to the time that they were inserted into the queue we can describe them in terms of a sequential listing of the items in order, and refer to the operation of inserting and deleting items from the beginning and the end of the list:
- Insert at the end, delete at the end -> we get a stack (array implementation)
- Insert at the beginning, delete at the beginning -> we also get a stack (linked list implementation)
- Insert at the end, delete at the beginning -> we get a FIFO queue (linked list implementation)
- Insert at the beginning, delete at the end -> we also get a FIFO queue (can be build in an array)
- Inserting and deleting at either end -> *deque ADT*

### Duplicate and index items
**Who has the responsibility of enforcing policies in ADTs?**  
We want to detect and resolve duplicates as part of the problems that ADT resolve, not leaving it up to the client. 

**What are the consequence of such decision?**  
This create a change in the abstraction because the behavior of the implementation changes, whenever we modify the specification of an ADT we get a completely new ADT, with different properties.  
When we informally use a term such: pushdown stack, FIFO queue, deque, priority queue or symbol table we are potentially referring to a family of ADTs, each with different sets of defined operations each with a different implementation to support those operations efficiently

**What is the other decision that has to be made when incorporate such behavior?**  
We have a policy decision to make when a client makes an insert request for an item that is already in the data structure:
- Proceed as the request never happened
- Proceed as client had performed a delete followed by an insert

**What is a simple solution of disallow duplicate items?**  
One way to implement a stack with no duplicates using an ignore-new-item policy is to maintain two data structures; the first contains the items in the stack, the second is an array that allows us to keep track of which items are in the stack, by using the items as index

### First class ADTs
**How can we manipulate ADTs in the same way that we manipulate built-in types?**  
By using *First Class ADTs*, which allow us to treat abstract objects like built-in types: we can assign them to variables, pass ass function arguments and return them from functions

**What is a first class ADT?**  
A first-class data type is one for which we can create many instances, assign them to variables and use them in expressions. Just like built-in types 

**To which data types does this method apply?**  
To any data type: in particular it applies to generalized queues, for example join two queues etc.. Providing us the capability to write programs that manipulate stacks and FIFO queues in much the same way that we manipulate others type of data in C.

**How do we build a first class ADT in C?**  
We illustrate the basic approach by building a first-class data type for complex numbers.  
The goal is to perform algebraic operations on complex numbers using operation defined in the ADT. Such as addition and multiplication implemented as function (because C does not support operator overloading)

**What distinguishes the client program from the previous client programs?**  
It declares variables of type `Complex` and assign values to them, treating the ADT like a built-in type

**What happens if the representation is exposed in the interface?**  
If the interface exposes the representation (example: a struct with Re and Im fields):
- Advantage: client can directly manipulate the fields
- Disadvantage: the representation cannot be changed without modifying all clients
Therefore it is NOT and abstract data type because the representation is not hidden

**Why the representation must be hidden?**  
Because the ability to change the representation is essential for applications with complex data structures. A First Class ADT lets clients manipulate the data only through exported operations, allowing the internal representation to be changed without effecting client code

**How do we describe a reference to an abstract object?**  
We use a *handle*, a handle lets client programs refer to abstract objects in assignments, as arguments and as return values, like built in types, while keeping the representation hidden

