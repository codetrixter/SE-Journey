# TOPICS COVERED

1. [Auto pointer and why was it deprecated](Auto_ptr.cpp)
2. [R-value references](R-ValueReferences.cpp)
3. [Move constructors and Move assignmenets](moveCtorAndassign.cpp)
4. [std::move](STDmove.cpp)
5. [std::unique_ptr](unique-pointer.cpp)
6. [std::shared_ptr](shared-ptr.cpp)
7. [weak pointer and its use](weak-ptr-issues-with-sharedptr.cpp)

# MOTIVATION/BENFITS OF MOVE SEMANTICS

1. The primary motivation is efficiency. Copying can be O(n) time/space for large data structures, while moving is often O(1)—just swap pointers or transfer handles. This is huge for containers like std::vector, std::string, or custom classes managing resources (files, sockets, etc.).
2. It enables return value optimization (RVO) and avoids temporary copies in chains like std::vector v = funcReturningVector();.
3. Moves aren't about deallocating the source object itself (which stays in memory until scope ends). They're about transferring ownership to avoid duplication.
4. Without moves, you'd fall back to copies, which work but are slower. Moves are an optimization for cases where the source won't be used again.

