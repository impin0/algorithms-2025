# Chapter three Elementary data structures

## Key Concepts:
- Building blocks
- Arrays
- Linked lists
- Strings
- Compound data structures

### 3.1 Building blocks
**What is the essential step in developing a program?**
Choosing the appropriate data structure for the problem, once the data is organized correctly, the algorithms needed to process it become simpler.

**Why does the choice of a specific data structure matter?**
Different data structures require different amount of space and time for common operations.
The choice directly affects the efficiency and performance of the algorithm

**What is a data type?**
A data type is a *set of values* and a collection of *operation* on those values (operations are associated with types, not the other way around)

**What are the kind of operations associated with a data type?**
- With standard data types many operations are built into the C language (arithmetic operations)
- Found in the form of functions that are defined in standard function libraries
- Found in the form of functions that we define in our programs

**What is the goal that we have when writing programs?**
Is to organize the program such that they apply to as broad variety of situations as possible, to do that we must understand and specify precisely what a program does and the operations that it performs
But we need to strike a balance between the level of generality that we chose and the ease of implementation

**What is the recommended practice to support data types?**
Is to split the program in three files:
- *Interface* which defines the data structure and declares the (operations) functions to be used to manipulate the data structure
- *Implementation* of the functions declared in the interface
- *Client* program that uses the functions declared in the interface to work at a higher level of abstraction

### 3.2 Arrays
**Who is the fundamental data structure?**
The array, defined as a *fixed* collection of *homogeneous* elements (same-type data) that are stored *contiguously* and are accessible by *index*

**What are the key advantages of arrays?**
- They have a direct correspondence with *memory systems* -> array access such `a[i]` translates to just few machine instructions -> we can access efficiently any item of the array given that item's index
- They correspond directly to *natural method of organizing data* for applications. For example arrays correspond directly to vectors

**What is a simple example of the use of arrays?**
The *sieve of Eratosthenes*, which prints out all prime numbers less than N.
```
for(i = 2; i < N; i++){
    a[i] = 1;
}
for(i = 2; i < N; i++){
    if(a[i]){
        for(j = i; i * j < N; j++){
            a[i*j] = 0;
        }
    }
}
for(i = 2; i < N; i++){
    if(a[i]){
        printf("%4d ", i);
    }
}
```

### 3.3 Linked Lists
**What is a linked list?**
A linked list is either a *null link* or a link to a node that contains an item and a link to a linked list

**Why they are important?**
Is the data structure that we chose when our interest is to go through a collection of items sequentially.

**What are the advantages of linked lists over arrays?**
- *Flexibility*: the primary advantage is that links provide us with capability to rearrange the items efficiently, this flexibility is gained at the expense of quick access of any arbitrary item in the list, because the only way to get to an item is to follow links one node to the next
- Sequential organization is not provided implicitly (yes in arrays)

**What are the conventions used for the link in the final node?**
- is a *null link* that points to no node
- it refers to a *dummy node* that contains no item
- it refers back to the first node, making the list a *circular list*

**How linked lists are defined in C?**
```
typedef <standard-type> Item;
typedef struct node *link;
struct node{
    Item item;
    link next;
};
```

**How linked lists are created in C?** 
``` 
link create_list(link x, int n_nodes){
    if(!x){
        fprintf(stderr, "link provided is NULL\n");
        return NULL;
    }
    link first = x;
    link x = malloc(sizeof *x);
    if(x == NULL){
        fprintf(stderr, "error: malloc()\n");
        return NULL;
    }
    for(i = 1; i < n_nodes; i++){
        x->next = malloc(sizeof *x);
        if(x->next == NULL){
            fprintf(stderr, "error: malloc()\n");
            return NULL;
        }
        x = x->next;
        x->item = item;
    }
    return first;
}
```

**What are the fundamental operations that we perform on linked lists?**
- Traversing the list:
`for(t = x; t != NULL; t = t->next)` or its equivalent while form:
```
    while(t != NULL){
        t = t->next;
    }
```

- Deleting a node:
`t = x->next;`
`x->next = t->next;`
`free(t);`

- Inserting a node:
`t->next = x->next;`
`x->next = t;`

**What is classical example of the use of linked lists?**
The *Josephus problem*:
N people have decided to elect a leader by arranging themselves in a circle and eliminating every Mth person around the circle. The problem is to find out which person will be the last one remaining

**What are the commonly used convention when working with linked lists?**
- Circular, never empty:
first insert:       `head->next = head`
insert t after x:   `t->next = x->next; x->next = t`
delete after x:     `x->next = x->next->next;`
traversal loop:     `t = head;`
                    `do{... t = t->next;} while(t != head);`
test if one item:   `if(head->next == head)`

- Head pointer, null tail
initialize:         `head = NULL`
insert t after x:   `if(x == NULL) {head = t; head->next = NULL}`
                    `else{ t->next = x->next; x->next = t;}`
delete after x:     `t = x->next; x->next = t->next`
traversal loop:     `for (t = head; t != NULL; t = t->next)`
test if empty:      `if (head == NULL)`   

- Dummy head node, null tail
initialize:         `head = malloc(sizeof *head);`
                    `head->next = NULL;`
insert t after x:   `t->next = x->next; x->next = t->next;`
delete after x:     `t = x->next; x->next = t->next;`
traversal loop:     `for(t = head->next; t != NULL; t = t->next)`
test if empty:      `if (head->next == NULL)`

- Dummy head and tail nodes:
initialize:         `head = malloc(sizeof *head)`
                    `z = malloc(sizeof *z)`
                    `head->next = z; z->next = z;`
insert t after x:   `t->next = x->next; x->next = t;`
delete after x:     `x->next = x->next->next;`
traversal loop:     `for(t = head->next; t != z; t->next)`
test if empty:      `if (head->next == z)`

### 3.6 Strings

**What is a string?**
A string is a *variable length array of characters*, defined by a starting point and by a string-termination character marking the end.

**Why they are valuable as low-level data structures?**
1. Strings represent directly textual data
2. Many computer systems provide direct and efficient access to bytes of memory, which correspond directly to characters on strings

**What is the difference between a string and an array of characters?**
The *length*, both represent contiguous areas of memory but the length of an array is set at the time that array is created, whereas the length of a string may change during the execution of a program

**What is the main operations that we perform on strings?**
The *compare* operation: tells us which of two strings would appear first in the dictionary. The strings are compared using the *lexicographic order*, that means comparing the strings character-by-character from beginning to end.
The compare function can tell us if the strings are equal, by convention the compare function returns a negative number if the first argument strings appears before the second in the second in the dictionary, returns 0 if they are equal and 1 if the first appears after the second

**What are the elementary string-processing operations?**
- Compute string length (strlen(a)):
`for(i = 0; a[i] != '\0'; i++)`
- Copy (strcpy(a, b)):
`for(i = 0; (a[i] = b[i]) != '\0'; i++)` 
- Compare (strcmp(a, b)):
```
    for(i = 0; a[i] == b[i]; i++)
        if(a[i] == '\0') return 0;
    return a[i] - b[i];
```
- Compare (prefix) (strncmp(a, b, strlen(a))):
```
    for(i = 0; a[i] == b[i]; i++)
        if(a[i] == '\0') return 0;
    if(a[i] == '\0') return 0;
    return a[i] - b[i];

```
- Append (strcat(a, b)):
`strcpy(a+strlen(a), b)`

**Why is important to knowledgeable about the performance of library functions?**
Library functions might take more time than we expect intuitively. String processing provides a convincing example of that, for example determine the length of a string takes time proportional to the length of the string, ignoring this can lead to severe performance problems
```
    for(i = 0; i < strlen(a); i++){
        if(strncmp(&a[i], p, strlen(p)) == 0)
            printf("%d", i);
    }
```
This code fragment takes time proportional to at least the square of the length of a
This kind of error is known as *performance bug*, because the code is correct but it does not perform as efficiently as we expected

### 3.7 Compound Data Structures

**How can we create more complex data structures?**
Arrays, linked lists and strings provide a first level of abstraction, and we can use them in a *hierarchical fashion* to build up more complex structures

**How matrix works?**
One dimensional arrays correspond to vectors, two-dimensional arrays, with two indices, correspond to matrices. In many programming environments two dimensional arrays are stored in *row-major order* in a one dimensional array: 
In an array a[M][N], the first N positions would be occupied by the first row (elements from [0][0] through [0][N-1]) the second N positions by the second row and so forth

**How can we multiply two matrices a and b, leaving the result in matrix c?**
```
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            for(k = 0, c[i][j] = 0.0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j]; 
            }
        }
    }
```
Because of row-major order we can write the final line as:
`c[N*i*j] = a[N*i*k] + b[N*k*j]`

**How can we dynamically allocate multidimensional arrays?**
Because not all C implementations use row major order, we perform:
```
    int **malloc2d(int r, int c){
        int i;
        int **t = malloc(r * sizeof(int *));
        for(i = 0; i < r; i++){
            t[i] = malloc(c * sizeof(int));
        }
        
        return t;
    }
```

**How arrays of strings are built?**
We read the characters into a huge *one-dimensional array*, save *pointers* to individual strings (delimiting them with a string-termination character), then manipulate the pointers.
This is how the `argv[]` array is used to pass argument strings to `main` in C programs. The system stores in a string buffer the command line typed by the user and passes to main a pointer to an array of pointers to string in that buffer

**Can we build compounded data structures exclusively with links?**
Yes, we can create *multilist* where nodes have multiple link fields and belong to independently maintained linked list

**What is a graph?**
Is a fundamental *combinatorial object* that is defined as a set of objects (called vertices) and a set of connections among the vertices (called edges)
A graph with V vertices and E edges is defined by a set of E pairs of integers between 0 and V-1. -> We assume that the vertices are labeled with integers from 0 to V - 1 and that edges are specified as a pairs of vertices.

**What is an unidirected graph?**
Is a graph that has the pair i-j that define a connection between i and j and thus having the same meaning as the pair j-i

**How can we simply represent graphs?**
Using two-dimensional array called *adjacency matrix*. With it we can immediately determine whether or not there is an edge from vertex i to vertex j by checking whether row i and column j of the matrix is nonzero (for undirected graph the matrix is symmetric) 
```
    int i, j, adj[V][V];
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            adj[i][j] = 0;
    for(i = 0; i < V; i++) 
        adj[i][i] = 1;
    while(scanf("%d %d", &i, &j) == 2){
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
```

**What is another method to represent graphs?**
Using an array of linked lists, called *adjacency list*. We keep a linked list for each vertex, with a node for each vertex connected to that vertex. (for undirected graphs if there is a node for j in i's list, then there must be a node for i in the j's list)
```
    typedef struct node *link;
    struct node{
        int v;
        link next;
    };
    link NEW(int v, link next){
        link x = malloc(sizeof *x);
        x->v = v;
        x->next = next;
        return x;
    }
    main(){
        int i, j, adj[V];
        for(int i = 0; i < V; i++){
            adj[i] = NULL;
        }
        while(scanf("%d %d", &i, &j) == 2){
            adj[j] = NEW(i, adj[j]);
            adj[i] = NEW(j, adj[i]);
        }
    }
```

**What is the space tradeoff that we face by implementing one of those versions?**
The adjacency matrix uses space proportional to $V^2$
The adjacency list use space proportional to V + E
If there are few edges (the graph is *sparse*) then the list representation uses far less space; if most pairs of vertices are connected by edges (the graph is *dense*) the matrix might be preferable
