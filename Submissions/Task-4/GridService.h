//
// Created by Ivan Hromovyi on 07/09/2026.
//

#ifndef STACK_QUEUE_GRIDSERVICE_H
#define STACK_QUEUE_GRIDSERVICE_H

#include "data_structures/TQueue.h"
#include "data_structures/TStack.h"

const int GRID_SIZE = 100;
static int grid[GRID_SIZE][GRID_SIZE];
static bool visited[GRID_SIZE][GRID_SIZE];

// Time: O(n^2), Space: O(1)
static void InitializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = std::rand() % 10;
            visited[i][j] = false;
        }
    }
}

// Time: O(1), Space: O(1)
bool IsValid(int aRow, int aCol) {
    return aRow >= 0 && aRow < GRID_SIZE && aCol >= 0 && aCol < GRID_SIZE && !visited[aRow][aCol];
}

/*
 * Stack follows LIFO, that means the last pushed cell is going to be processed next.
 * The user inputs a random row and col, from where DFS begins. After the neighbors of the processed
 * cell were validated, they are being pushed to the stack, and the last neighbor that was added
 * will be processed next. This search repeats until '0' is found or every cell is checked.
 * This way, using stack it is possible to search all the way down (deep),
 * and then come back to where it started.
 */
// Time: O(n^2), Space: O(n^2)
static bool DFS(int aStartRow, int aStartCol) {
    TStack stack;
    int cellPos = aStartRow * GRID_SIZE + aStartCol;
    visited[aStartRow][aStartCol] = true;
    stack.Push(cellPos);
    while (!stack.IsEmpty()) {
        cellPos = stack.Pop();
        int row = cellPos / GRID_SIZE;
        int col = cellPos % GRID_SIZE;
        if (grid[row][col] == 0) {
            std::cout << "Found 0 at (" << row << ", " << col << ")" << std::endl;
            return true;
        }
        std::cout << "Visiting (" << row << ", " << col << ") with value " << grid[row][col] << std::endl;
        visited[row][col] = true;
        int neighborRow[4] = {-1, 0, 1, 0};
        int neighborCol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + neighborRow[i];
            int newCol = col + neighborCol[i];
            if (IsValid(newRow, newCol)) {
                std::cout << "Pushing: "
                    << newRow << ", " << newCol << std::endl;
                cellPos = newRow * GRID_SIZE + newCol;
                stack.Push(cellPos);
            }
        }
    }
    std::cout << "0 not found in DFS" << std::endl;
    return false;
}

/*
 * Queue follows FIFO, that means the first enqueued cell is going to be processed next.
 * The user inputs a random row and col, from where BFS begins. After the neighbors of the processed
 * cell were validated, they are being enqueued to the queue, and the first neighbor that was added
 * will be processed next. This search repeats until '0' is found or every cell is checked.
 * This way, using queue it is possible to start searching all the way around (breadth), level by level.
 */
// Time: O(n^2), Space: O(n^2)
static bool BFS(int aStartRow, int aStartCol) {
    TQueue queue;
    int position = aStartRow * GRID_SIZE + aStartCol;
    visited[aStartRow][aStartCol] = true;
    queue.Enqueue(position);
    while (!queue.IsEmpty()) {
        position = queue.Dequeue();
        int row = position / GRID_SIZE;
        int col = position % GRID_SIZE;
        if (grid[row][col] == 0) {
            std::cout << "Found 0 at (" << row << ", " << col << ")" << std::endl;
            return true;
        }
        std::cout << "Visiting (" << row << ", " << col << ") with value " << grid[row][col] << std::endl;
        visited[row][col] = true;
        int neighborRow[4] = {-1, 0, 1, 0};
        int neighborCol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + neighborRow[i];
            int newCol = col + neighborCol[i];
            if (IsValid(newRow, newCol)) {
                position = newRow * GRID_SIZE + newCol;
                queue.Enqueue(position);
            }
        }
    }
    std::cout << "0 not found in BFS" << std::endl;
    return false;
}

#endif //STACK_QUEUE_GRIDSERVICE_H