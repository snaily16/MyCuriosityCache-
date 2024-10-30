# C

## typedef

The C typedef keyword is used to redefine the name of already existing data types. 
Typedef is used with user-defined datatypes, which behave similarly to defining an alias for commands.

Syntax: typedef existing\_name alias name;

Example: typedef long long ll

## Dynamic Memory Allocation in C
size of data structure is changed during the runtime
library funcitons under <stdlib.h> : malloc(), calloc(), free(), realloc()

### malloc() method - "memory allocation"
Allocates a single large block of memory with specified size
Returns a pointer of type void which can be cast into a pointer of any form.
Doesn't initialize memory at execution time, so that it has iniitalized each block with default garbage value initially.

Syntax: ptr = (cast-type\*) malloc(byte-size);

Example: ptr = (int \*) malloc(100 * sizeof(int));

The type of this pointer depends on whether you are using an older K&R compiler or the newer ANSI type compiler. With the older compiler the type of the returned pointer is char, with the ANSI compiler it is void.
If you are using an ANSI compliant compiler, malloc() returns a void pointer and since a void pointer can be assigned to a pointer variable of any object type, the (int \*) cast shown above is not needed.

### calloc() method - "contiguous allocation"
Dynamically allocate the specified number of blocks of memory of the specified type
Initializes each block with a default value '0'

Syntax: ptr = (cast-type\*) calloc(n, element-size);

Example: ptr = (float\*) calloc(10, sizeof(float));

### free() method
Dynamically de-allocate the memory.
Memory allocated by malloc() and calloc() is not de-allocated on their own.
Reduce wastage of memory

Syntax: free(ptr)

### realloc() method - "re-allocation"
Dynamically change the memory allocation of previously allocated memory.
Maintains the already present value and new blocks will be initialized with default garbage value.
If space is insufficient, allocation fails and returns a NULL pointer.

Syntax: ptr = realloc(ptr, newSize); 

Example: ptr = realloc(ptr, 10\*sizeof(int));

