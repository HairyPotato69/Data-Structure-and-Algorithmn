#include <iostream>

int recursion(int n);

int main(){
    std::cout << "hello\n";
    std::cout << recursion(5);
    return 0;
}

int recursion(int n) {
    // base case to end the loop
    if (n > 0)
        return n * recursion(n - 1);
    // base case
    return 1;
}