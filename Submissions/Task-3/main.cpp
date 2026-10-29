#include <iostream>

// Time: O(n), Space: O(n)
static void printNaturalNumbers(int n) {
    if (n < 1) {
        return;
    }
    printNaturalNumbers(n - 1);
    std::cout << n << std::endl;
}

// Time: O(n), Space: O(n)
static int calculateFactorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

// Time: O(log n), Space: O(log n)
static int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int half = power(base, exponent / 2);

    if (exponent % 2 == 0) {
        return half * half;
    }
    return base * half * half;
}

/*  this function uses double recursion in it,
    which leads to excessive memory usage and potential stack overflow */
// Time: O(2^n), Space: O(n)
static int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Time: O(n^2), Space: O(n^2)
static int countOccurrences(std::string s, char c) {
    if (s.size() == 0) {
        return 0;
    }
    int count = s[0] == c ? 1 : 0;
    return count + countOccurrences(s.substr(1), c);
}

// Time: O(n), Space: O(log n)
int findLargestElement(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }

    int mid = size / 2;

    int leftMax = findLargestElement(arr, mid);
    int rightMax = findLargestElement(arr + mid, size - mid);

    return leftMax > rightMax ? leftMax : rightMax;
}

// Time: O(n), Space: O(n)
static void traverseAsciiTable(char start, char end) {
    if (start > end) {
        return;
    }
    /*  prints the data in a correct order before
        the recursion func is called, from first char to last */
    std::cout << start << std::endl;
    traverseAsciiTable(start + 1, end);
    /*  prints the data in reverse order after the func
        was called, from last char to first */
    std::cout << start << std::endl;
}

int main() {
    // Natural numbers recursively
    std::cout << "Natural numbers recursively"<< std::endl;
    printNaturalNumbers(9);
    // Factorial calculation
    std::cout << "Factorial calculation"<< std::endl;
    std::cout << calculateFactorial(2) << std::endl;
    // Power calculation
    std::cout << "Power calculation"<< std::endl;
    std::cout << power(5, 4) << std::endl;
    // Fibonacci
    std::cout << "Fibonacci"<< std::endl;
    std::cout << fibonacci(9) << std::endl;
    // Count occurrences of a character in a string
    std::cout << "Occurrences in string" << std::endl;
    std::cout << countOccurrences(std::string("carcacc"), 'r') << std::endl;
    // Largest element in array
    std::cout << "Largest element in array" << std::endl;
    int arr[] = {1, 5, 66, 89, 23, 14, 15, 99};
    std::cout << findLargestElement(arr, 8) << std::endl;
    // ASCII table traversal
    std::cout << "ASCII table traversal" << std::endl;
    traverseAsciiTable('a', 'g');
    return 0;
}