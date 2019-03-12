/*****************************************

  Stack.h and Stack.c implement a stack of doubles.

  A client program accesses the stack via the interface defined below.

*********************************************/ 

/************************
 * Push
 *
 * Pushes "d" onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs because the stack is full.
 */
int push (double d);


/************************
 * pop
 *
 * Pops next double off the stack.
 * Returns the double if successful.
 * Returns NAN if an error occurs.  (Stack empty).
 */
double pop ();


/************************
 * isStackEmpty
 *
 * If the stack is empty, returns 1 (true).  
 * Otherwise, returns 0 (false). 
 */
int isStackEmpty ();


/************************
 * getStackSize
 *
 * Returns the current size of the stack. 
 */
int getStackSize();


/************************
 * emptyStack
 *
 * Empties the stack entirely.  
 * After this call, getStackSize() should equal 0.
 */
void emptyStack();

/************************
 * printStack
 *
 * For debugging purposes.
 * Prints out the indexes and contents of the stack, 
 * from the top of the stack to the bottom. For example:
 * 3:   5.1
 * 2:  12.2
 * 1:  -1.4
 * 0:   0.3
 */
void printStack();