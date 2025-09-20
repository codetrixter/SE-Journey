/**
 * @file stackandHeap.cpp
 * @author Abhishek
 * @brief Here we discuss about the stack and heap memories in C++.
 * 
 * The memory that a typical program uses is divide into segments:
 * 1- code/text segment which is the read only area of the memory where the compiled program sits.
 * 2- bss/uninitialized data segment, where 0 initialized global/static variables reside.
 * 3- data/initialized segment, whereinitialized global/static variables reside.
 * 4- Heap is the part of the memory where dynamically allocated variables are stored.
 * 5- call stack, where function call, local variables and other function related information is stored.
 * -----------------------------------------------------------------------------------------------------------------
 * Advantages/Disadvantages of heap memory allocation:
 * 1- memory allocation in heap is slow.
 * 2- memory allocated needs to be manualy deallocated(to avoid memory leaks).
 * 3- accessing dynamically allocated memory is done via pointers, which is slower than accessing directly.
 * 4- heap memory is big hence can accomodate huge pieces of data.
 * -----------------------------------------------------------------------------------------------------------------
 * The call stack in action

    Let’s examine in more detail how the call stack works. 
    Here is the sequence of steps that takes place when a function is called:

    The program encounters a function call.
    A stack frame is constructed and pushed on the stack. The stack frame consists of:

    The address of the instruction beyond the function call (called the return address). 
    This is how the CPU remembers where to return to after the called function exits.
    All function arguments.

    Memory for any local variables
    Saved copies of any registers modified by the function that need to be restored when the function returns
    The CPU jumps to the function’s start point.
    The instructions inside of the function begin executing.
    When the function terminates, the following steps happen:

    Registers are restored from the call stack
    The stack frame is popped off the stack. This frees the memory for all local variables and arguments.
    The return value is handled.
    The CPU resumes execution at the return address.

    ---------------------------------------------------------------------------------------------------------------
 * 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
/* For normal variables like x, the compiler keeps track of x and determines where it is placed in memory. 
But variables don't actually exist in compiled code -- instead wherever the compiler sees x in our source code, it writes code that 
accesses the memory address it assigned to x.

As a gross simplification: if the compiler decides x is at memory address 140, wherever it sees x in our code, it will generate compiled 
code that uses memory address 140 instead. The compiler knows x is at 140, but once the compilation is done, that information is 
discarded and the executable code only knows "go access the value at 140".

As a slightly less gross simplification: at compilation time, the compiler will lay out where all of the 
normal variables are in memory as offsets from some base address (that will be provided at runtime). 
So the compiler will say x is at (base address + 4), y is at (base address + 8), etc...
 
Then wherever the compiler sees x in our source code, it generates compiled code that uses (base address + 4) 
instead. That way the compiler doesn't have to worry about where exactly in memory x should live, 
it just needs to make sure that all the variables used are separated enough so they don't overlap, 
and the actual final addresses are calculated at runtime. For example, when the function containing 
the variables is called, the base address gets assigned -- let's say at memory address 136. And since the 
compiler put x at (base address + 4), the executable code will access memory address (136 + 4), which is memory 
address 140. */


int main() {
	int x;
	int y;
	int z;

	x = 1;
	y = 2;
	z = 3;
}
/* compiles to this:

/// main()'s function prologue (sets up the base pointer)
push   rbp
mov    rbp,rsp

mov    DWORD PTR [rbp-0xc],0x1 ; // x = 1 ; x is at rbp-0xc
mov    DWORD PTR [rbp-0x8],0x2 ; // y = 2 ; y is at rbp-0x8
mov    DWORD PTR [rbp-0x4],0x3 ; // z = 3 ; z is at rbp-0x4

/// main()'s function epilogue
mov    eax,0x0
pop    rbp
ret
The brackets ([]) are equivalent to the C++ indirection operator(*),
so [rbp-0xc] is equivalent to *(base_address - 12) */