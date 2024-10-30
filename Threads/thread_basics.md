# Thread operations include:
1. Creation - pthread_create()
2. Termination - pthread_exit()
3. Synchronization (joins, blocking) - pthread_join()
4. Scheduling
5. Data management and process interaction

* A thread does not maintain list of created threads, nor does it know the thread that created it
* All threads within a process share:
    - Same address space
    - Process instructions
    - Open files (descriptors)
    - Signals and signal handlers
    - Current working directory
    - User and group id

* Each thread has a unique
    - thread Id
    - set of registers, stack pointer
    - stack for local variables, return addresses
    - signal mask
    - priority
    - return value: errno

* pthread function return "0" if OK
- pthread_self() : return identifier of current thread

## Thread Attributes:
By default, a thread is created with certain attributes. Some of these attributes can be changed by the programmer via the thread attribute object.

pthread_attr_init and pthread_attr_destroy are used to initialize/destroy the thread attribute object.

## Terminating Threads
There are several ways in which a thread may be terminated:
    - The thread returns normally from its starting routine. Its work is done.
    - The thread makes a call to the pthread_exit subroutine - whether its work is done or not.
    - The thread is canceled by another thread via the pthread_cancel routine.
    - The entire process is terminated due to making a call to either the exec() or exit()
    - If main() finishes first, without calling pthread_exit explicitly itself

# Thread Synchornization

Three synchronization mechanisms:
1. mutexes - pthread_mutex_t
2. joins
3. condition variables 

## Mutexes
* prevent race condition, when two or more threads need to perform operations on same memory area, result depends on order in which these operations are performed.
* pthread_mutex_lock() : acquire a lock on mutex variable
* pthread_mutex_unlock() : unlock mutex variable
* pthread_mutex_trylock() : attempt to lock a mutex or will return error code if busy. Useful for preventing deadlock conditions

## Join
* way to accomplish synchronization between threads.
* performed when one wants to wait for a thread to finish.
* The pthread_join() subroutine blocks the calling thread until the specified thread terminates.
* A thread can only be joined once.
* If a thread is created as detached, it can never be joined.
* To explicitly create a thread as joinable or detached, the attr argument in the pthread_create() routine is used
The typical 4-step process is:
   - Declare a pthread attribute variable of the pthread_attr_t data type
   - Initialize the attribute variable with pthread_attr_init()
   - Set the attribute detached status with pthread_attr_setdetachstate()
   - When done, free library resources used by the attribute with pthread_attr_destroy()


## Condition Variables
* pthread_cond_t : condition variable
* suspend execution and relinquish the processor until some condition is true
* must be associated with mutex to avoid a race condition
* One thread preparing to wait and another thread which may signal the condition before the first thread actually waits on it resulting in deadlock. Any mutex can be used.
- Creating and Destroying
    pthread_cond_init
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    pthread_cond_destroy

- Waiting on condition
    pthread_cond_wait : unlocks mutex and waits for condition var to be signaled
    pthread_cond_timedwait : place limit on how long it will block

- Waking thread based on condition
    pthread_cond_signal : restart one of the threads that are waiting on condition variable
    pthread_cond_broadcast : wake up all threads blocked by specefied condition variable

## Thread Scheduling

Question: After a thread has been created, how do you know a) when it will be scheduled to run by the operating system, and b) which processor/core it will run on?
*Unless you are using the Pthreads scheduling mechanism, it is up to the implementation and/or operating system to decide where and when threads will execute. Robust programs should not depend upon threads executing in a specific order or on a specific processor/core.
Scheduling attributes may be specified: 
- during thread creation
- by dynamically changing attributes of thread already created
- by defining the effect of a mutex on thread's scheduling when creating a mutex
- by dynamically changing the scheduling of a thread during sync operations
