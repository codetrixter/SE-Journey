# TOPICS COVERED

1. [Basic Exception Handling](exceptionHandlingBasics.cpp)

2. [Exceptions, Functions and Stack unwinding](exceptionsAndStackUnwinding.cpp)

3. [Uncaught Exceptions and Catch-all-handlers](uncaughtExcCatchAllhandler.cpp)

4. [Exceptions, classes and Inheritance](classAndInheritanceExceptions.cpp)

5. [Rethrowing Exceptions](rethrowExceptions.cpp)

6. [Function Try Blocks](functionTryBlock.cpp)

7. ## Exception Dangers and Downsides:
    ### There are couple of downsides to using exceptions some of them are as follows:
    1. Cleaning up resources.
    2. Performance Concerns: It increases the size of the executable and has a heavy performance penalty when an exception is thrown.
    ### When should the exceptions be used:
    1. The error being handled is likely to occur only infrequently.
    2. The error is serious and execution could not continue otherwise.
    3. The error cannot be handled at the place where it occurs.
    4. There isn’t a good alternative way to return an error code back to the caller.
    
8. ## noexcept
### noexcept qualifier, it just basically informs the programmer about whether the function will throw exception or not.