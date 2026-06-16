/**
 * @file commandLineArguments.cpp
 * @author Abhishek
 * @brief Here we look at how command line arguments work:
 * 1- the command line arguments are the arguments that are part of the main function and they
 * process the arguments which are passed while executing program.
 * 2- there are two parameters:
 *  a- argc -> this keeps count of the number of arguments passed after the executable file name.
 *  b- argv -> this is the pointer to c-style chars which contains the strings divided by spaces.
 * 3- Usually stings passed as arguments while executing the code is parsed by the shell, hence for different 
 * type of results we can do:
 *  a- for passing a single string with multiple words use "abhishek is good" argv1 = abhishek is good
 *  b- for taking double quote as a string use \"abhihsek is good\" -> argv1 = \"abhishek, argv2 = is, argv3 = good\" 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <sstream>
//****************basic command line example***
 int main(int argc, char const *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        std::cout << i << ' ' << argv[i] << "\n";
    }
    return 0;
} 
//****************basic command line example***
//****************Dealing with numerc arguments***
/*
int main(int argc, char* const argv[])
{
    if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		return 1;
	}

	std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myint{};
	if (!(convert >> myint)) // do the conversion
		myint = 0; // if conversion fails, set myint to a default value

	std::cout << "Got integer: " << myint << '\n';

	return 0;
}*/
//****************Dealing with numerc arguments***

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║              CONCEPT ANALYSIS — commandLineArguments.cpp                   ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. `argc` and `argv`
- `argc` = count of arguments (including program name).
- `argv` = array of C-strings; `argv[0]` = program name.

### 2. Parsing Numeric Arguments with `std::stringstream`
`std::stringstream convert{argv[1]}; convert >> myint;` — converts string to int.

#### Alternatives / Idiomatic C++
- C++17: `std::from_chars` is faster and doesn't allocate:
  ```cpp
  int val; std::from_chars(argv[1], argv[1]+strlen(argv[1]), val);
  ```
- Use libraries like **CLI11**, **cxxopts**, or **Boost.Program_options** for
  robust argument parsing.
- `std::stoi`/`std::stol` are simpler than stringstream for single conversions.

#### Real-World Usage
- **Every CLI tool** uses argc/argv.
- **LLVM tools** (clang, opt): Use their own `cl::opt` command-line library.

---

## 🔁 Quick Revision
- `argv[0]` = program name; `argv[argc]` = nullptr.
- Shell handles quoting: `"hello world"` → single argv entry.
- Use `std::from_chars` (C++17) for fast numeric parsing.

### ⚠️ Gotchas
- `argv[0]` can be empty on some systems.
- Always check `argc` before accessing `argv[n]`.
*/
