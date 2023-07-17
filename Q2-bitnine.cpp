// Q2-bitnine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>


//recursive
// advantages of recursive is that it is simple and intuitive implementation and it directly follows the recurrence relation.
//The disadvantages are that it is inefficient for large values of n due to redundant function calls and that it recalculates the same Fibonacci numbers numerous times, resulting in exponential time complexity.
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

//Advantages of dynamic is that it Avoids redundant function calls by storing previously computed Fibonacci numbers in the memoization array and provides a significant performance improvement over the recursive approach.
//Disadvantage is that Requires additional memory to store the memoization array and adds overhead for array access and storage management.
int fibonacciDynamic(int n, int* memo) {
    if (memo[n] != -1)
        return memo[n];

    if (n <= 1)
        memo[n] = n;
    else
        memo[n] = fibonacciDynamic(n - 1, memo) + fibonacciDynamic(n - 2, memo);

    return memo[n];
}

int fibonacci(int n) {
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    int result = fibonacciDynamic(n, memo);

    free(memo);
    return result;
}

//Advantages is that it is Efficient and optimized for large values of n and avoids function call overhead and recursive stack limitations.
//Disadvantage is that the complexity might increase when dealing with more complex recurrence relations.
int fibonacciIterative(int n) {
    int first = 0;
    int second = 1;
    int result = n;  // Set initial result to n

    for (int i = 2; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

int main() {
    int n = 7;

    printf("Fibonacci using recursive = %d: %d\n", n, fibonacciRecursive(n));

    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    printf("Fibonacci using dynamic programming = %d: %d\n", n, fibonacciDynamic(n, memo));

    free(memo);

    printf("Fibonacci using iterative = %d: %d\n", n, fibonacciIterative(n));

    return 0;
}
//The recursive technique is the easiest to build, however it has performance problems because of duplicated calculations. 
//The dynamic programming approach, on the other hand, considerably boosts efficiency by leveraging memoization to prevent unnecessary calculations.
//The memoization array, however, needs additional memory to be stored. 
//The iterative method eliminates recursion and has a linear time complexity, making it the most effective and optimum strategy. 
//It might, however, be less comprehensible and more difficult to connect to the initial recurrence relation.




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
