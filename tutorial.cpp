// a preprocessor directive. tells the compiler to include the content of a file in the source code
// one of the standard files from the standard library input output steam
#include <iostream>

// instead of this, we define the namespace directly in the scope with the scope operator(::)
using namespace std;

// this function returns an integer
// int main()
// {
//     // declaring a variable 
//     int file_size = 100;
    
//     double sales = 9.99;

//     // cout is from the <iostream> file and allows us to print statements
//     std::cout << file_size; 

//     // 0 tells the operating system that we ran correctly
//     return 0;
// }

int main()
{
   
    // constants 
    const double pi = 3.14;
    

    // writing math expressions 
    int x = 10;
    int y = 3;

    int z = x + y;
    
    std::cout << z;
    // 0 tells the operating system that we ran correctly
    return 0;
}