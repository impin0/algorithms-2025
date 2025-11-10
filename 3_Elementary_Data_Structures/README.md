# Chapter three Elementary data structures

## Key Concepts:
- Arrays
- Linked lists
- Strings
- Compound data structures

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
