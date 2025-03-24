/**
 * *GLOBAL VARIABLES:
 * - These are the variables define at the start of the file
 * - These can also be defined in a namesapce.
 * - These have global scope or file scope.
 * - These have static duration meaning starts when main begins and ends when program is destroyed.
 */

 // Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly value-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global constexpr

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
