#include <iostream>

#include "GridService.h"
#include "data_structures/TQueue.h"
#include "data_structures/TStack.h"

/*  the stack is perfect for this function because it is LIFO.
    We can push elements to stack and then pop them in already reversed order */
// Time: O(n), Space: O(n)
static std::string ReverseString(const std::string& s) {
    TStack stack;

    for (int i = 0; i < s.size(); i++) {
        stack.Push(s[i]);
    }

    std::string result = "";
    while (!stack.IsEmpty()) {
        result += (char)stack.Pop();
    }

    return result;
}

// Time: O(n), Space: O(n)
static int CalculateFactorial(int n) {
    if (n < 0) {
        return -1;
    }
    TStack stack;
    for (int i = n; i > 1; i--) {
        stack.Push(i);
    }
    int result = 1;
    while (!stack.IsEmpty()) {
        result *= stack.Pop();
    }
    return result;
}

// Time: O(n), Space: O(n)
static void WaitLine(int amountOfPeople) {
    TQueue queue;
    for (int i = 1; i <= amountOfPeople; i++) {
        queue.Enqueue(i);
        std::cout << "Person with id : " << i << " arrived." << std::endl;
    }
    while (!queue.IsEmpty()) {
        int personId = queue.Dequeue();
        std::cout << "Person with id : " << personId << " was served."<< std::endl;
    }
}

int main() {
    // String Reversal with a Stack
    std::string value = "horse";
    std::cout << "Original string: " << value << ". Reversed string: "
        << ReverseString(value) << std::endl;
    // Recursive Functions with a Stack
    int num = 6;
    std::cout << "Factorial of "<< num << " is: " << CalculateFactorial(num) << std::endl;
    // Wait Line Simulation with a Queue
    int amountOfPeople = 3;
    WaitLine(amountOfPeople);
    // Setup: The 100x100 Grid
    InitializeGrid();
    int startRow = std::rand() % GRID_SIZE;
    int startCol = std::rand() % GRID_SIZE;
    // Depth-First Search (DFS) with a Stack
    DFS(startRow, startCol);
    // Breadth-First Search (BFS) with a Queue
    InitializeGrid();
    startRow = std::rand() % GRID_SIZE;
    startCol = std::rand() % GRID_SIZE;
    BFS(startRow, startCol);
    return 0;
    /* The key difference between BFS and DFS is that BFS uses a queue and DFS uses a stack.
     * BFS can be useful when it is necessary to find the shortest path, as it searches
     * level by level, gradually increasing the area of the path. DFS can be useful for depth searches,
     * when the goal is to look through branches one after another.
     */
}