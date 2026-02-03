/**
 * Unlike constructors, where throwing exceptions can be a useful way to indicate that object creation did not succeed, exceptions should never be thrown in
 * destructors.
 * The problem occurs when an exception is thrown out of a destructor during the stack unwinding process. If that happens, the compiler is put in a situation where
 * it doesn't know whether to continue the stack unwinding process or handle the new exception. The end result is that your program will be terminated immediately.
 * Consequently, the best course of action is just to abstain from using exceptions in destructors altogether. Write a message to a log file instead
 */

#include <iostream>
#include <stdexcept>
#include <string>

// ============================================
// BAD EXAMPLE: Throwing exception in destructor
// ============================================
class BadResource
{
private:
    std::string name;

public:
    BadResource(const std::string &n) : name(n)
    {
        std::cout << "BadResource '" << name << "' constructed\n";
    }

    ~BadResource()
    {
        std::cout << "BadResource '" << name << "' destructor called\n";
        // DANGEROUS: Throwing exception in destructor!
        throw std::runtime_error("Exception in destructor of " + name);
    }
};

void demonstrateBadPractice()
{
    std::cout << "\n=== BAD PRACTICE EXAMPLE ===\n";
    std::cout << "This will cause program termination!\n";

    try
    {
        BadResource res1("Resource1");
        BadResource res2("Resource2");

        // Throw an exception to trigger stack unwinding
        throw std::runtime_error("Main exception");

        // During stack unwinding:
        // 1. res2's destructor will be called -> throws exception
        // 2. Now we have TWO active exceptions (main + destructor)
        // 3. C++ cannot handle this -> std::terminate() is called
        // 4. Program crashes!
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
        // This catch block will likely never be reached!
    }
}

// ============================================
// GOOD EXAMPLE: Proper error handling in destructor
// ============================================
class GoodResource
{
private:
    std::string name;
    bool hasError;

    void cleanup()
    {
        // Simulate cleanup that might fail
        std::cout << "Cleaning up '" << name << "'\n";
        // Simulate potential error condition
        if (name == "FailResource")
        {
            hasError = true;
        }
    }

public:
    GoodResource(const std::string &n) : name(n), hasError(false)
    {
        std::cout << "GoodResource '" << name << "' constructed\n";
    }

    ~GoodResource() noexcept
    { // Mark as noexcept to indicate no exceptions
        std::cout << "GoodResource '" << name << "' destructor called\n";

        try
        {
            cleanup();

            // If cleanup had issues, log them instead of throwing
            if (hasError)
            {
                std::cerr << "ERROR: Failed to cleanup '" << name
                          << "' - logging to error stream instead of throwing\n";
                // In real code: write to log file, set error flag, etc.
            }
        }
        catch (const std::exception &e)
        {
            // Catch any exceptions that might occur during cleanup
            std::cerr << "ERROR in destructor of '" << name
                      << "': " << e.what()
                      << " - swallowing exception to prevent termination\n";
            // Never re-throw!
        }
        catch (...)
        {
            // Catch everything else
            std::cerr << "UNKNOWN ERROR in destructor of '" << name
                      << "' - swallowing exception\n";
        }
    }
};

void demonstrateGoodPractice()
{
    std::cout << "\n=== GOOD PRACTICE EXAMPLE ===\n";

    try
    {
        GoodResource res1("GoodResource1");
        GoodResource res2("FailResource"); // This one will have cleanup error
        GoodResource res3("GoodResource3");

        // Throw an exception to trigger stack unwinding
        throw std::runtime_error("Main exception");

        // During stack unwinding:
        // 1. res3's destructor called -> handles errors internally
        // 2. res2's destructor called -> logs error but doesn't throw
        // 3. res1's destructor called -> completes successfully
        // 4. Exception is caught properly below
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught main exception: " << e.what() << "\n";
        std::cout << "All destructors completed safely!\n";
    }
}

// ============================================
// ALTERNATIVE: Explicit cleanup with error reporting
// ============================================
class ManagedResource
{
private:
    std::string name;
    bool isReleased;

public:
    ManagedResource(const std::string &n) : name(n), isReleased(false)
    {
        std::cout << "ManagedResource '" << name << "' constructed\n";
    }

    // Explicit release method that CAN throw
    void release()
    {
        if (isReleased)
            return;

        std::cout << "Explicitly releasing '" << name << "'\n";

        // This method CAN throw exceptions since it's not a destructor
        if (name == "BadResource")
        {
            throw std::runtime_error("Failed to release " + name);
        }

        isReleased = true;
    }

    ~ManagedResource() noexcept
    {
        if (!isReleased)
        {
            std::cerr << "WARNING: '" << name
                      << "' not explicitly released - doing cleanup in destructor\n";
            // Do safe cleanup, but don't throw
            try
            {
                // Perform cleanup without throwing
                std::cout << "Emergency cleanup of '" << name << "'\n";
            }
            catch (...)
            {
                std::cerr << "ERROR during emergency cleanup - swallowing\n";
            }
        }
    }
};

void demonstrateExplicitCleanup()
{
    std::cout << "\n=== EXPLICIT CLEANUP PATTERN ===\n";

    try
    {
        ManagedResource res1("Resource1");
        ManagedResource res2("Resource2");

        // Explicitly release resources - these CAN throw
        res1.release();
        res2.release();

        std::cout << "All resources released successfully\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught during explicit release: " << e.what() << "\n";
    }
    // Destructors run here but do nothing since resources already released
}

int main()
{
    std::cout << "DEMONSTRATION: Why Exceptions in Destructors are Dangerous\n";
    std::cout << "============================================================\n";

    // Example 1: Good practice - no exceptions in destructors
    // demonstrateGoodPractice();

    // Example 2: Explicit cleanup pattern
    demonstrateExplicitCleanup();

    // UNCOMMENT AT YOUR OWN RISK - This will terminate the program!
    // demonstrateBadPractice();

    std::cout << "\n=== KEY TAKEAWAYS ===\n";
    std::cout << "1. NEVER throw exceptions from destructors\n";
    std::cout << "2. Mark destructors as 'noexcept' to document this\n";
    std::cout << "3. Catch and log errors in destructors instead of throwing\n";
    std::cout << "4. Use explicit cleanup methods for operations that might fail\n";
    std::cout << "5. If two exceptions are active, std::terminate() is called\n";

    return 0;
}
