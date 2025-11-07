# Chapter three Elementary data structures

## Key Concepts:
- Arrays
- Linked lists
- Strings
- Compound data structures

**What is a string?**
A string is a ==variable length array of characters==, defined by a starting point and by a string-termination character marking the end.

**Why they are valuable as low-level data structures?**
1. Strings represent directly textual data
2. Many computer systems provide direct and efficient access to bytes of memory, which correspond directly to characters on strings

**What is the difference between a string and an array of characters?**
The ==length==, both represent contiguous areas of memory but the length of an array is set at the time that array is created, whereas the length of a string may change during the execution of a program

**What is the main operations that we perform on strings?**
The ==compare== operation: tells us which of two strings would appear first in the dictionary. The strings are compared using the ==lexicographic order==, that means comparing the strings character-by-character from beginning to end.
The compare function can tell us if the strings are equal, by convention the compare function returns a negative number if the first argument strings appears before the second in the second in the dictionary, returns 0 if they are equal and 1 if the first appears after the second

**What are the elementary string-processing operations?**
- Compute string length (strlen(a)):    `for(i = 0; a[i] != '\0'; i++)`
- Copy (strcpy(a, b)):  `for(i = 0; (a[i] = b[i]) != '\0'; i++)` 
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
- Append (strcat(a, b)): `strcpy(a+strlen(a), b)`

**Why is important to knowledgeable about the performance of library functions?**
Library functions might take more time than we expect intuitively. String processing provides a convincing example of that, for example determine the length of a string takes time proportional to the length of the string, ignoring this can lead to severe performance problems
```
    for(i = 0; i < strlen(a); i++){
        if(strncmp(&a[i], p, strlen(p)) == 0)
            printf("%d", i);
    }
```
This code fragment takes time proportional to at least the square of the length of a
This kind of error is known as ==performance bug==, because the code is correct but it does not perform as efficiently as we expected


