// a preprocessor directive. tells the compiler to include the content of a file in the source code
// one of the standard files from the standard library input output steam
#include <iostream>

// instead of this, we define the namespace directly in the scope with the scope operator(::)
using namespace std;

// this function returns an integer
int main()
{
    // cout is from the <iostream> file and allows us to print statements
    std::cout << "Hello World!"; 

    // 0 tells the operating system that we ran correctly
    return 0;
}