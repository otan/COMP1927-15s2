#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Written by Oliver Tan (otan@cse.unsw.edu.au)
 *
 * Two part question
 *
 * You are given a graph, akin to this:
 * 1 1 0 0 0
 * 1 0 1 1 0
 * 0 0 1 1 0
 *
 * Part 1) Find how many of the same type of number is in the graph connected
 *         to (0,0). e.g., in above, if top left was (0, 0), (0,0) contains 1.
 *         Connecting to that, (1, 0) and (0, 1) contain 1 as well. You thus
 *         return 3.
 *
 *         Implement this in the "count" function.
 *
 *         Mark using: ./mark part1
 *
 * Part 2) [Interview-Style Question] Write a program that finds the largest
 *         island of 1's. For example, in above, the largest island is of size 4
 *
 *         Implement this in the "biggest_island_size" function.
 *         Uncomment #define PART2 to do it.
 *
 *         Mark using: ./mark part2
 * 
 * Assume for all graphs, rows >= 1, cols >= 1
 * Compile: gcc -Wall -Werror -O -o test test.c
 */

//#define PART2

// Hint: you may need these!
int **make_2d_array(int cols, int rows) {
    int y;
    int **arr;
    arr = malloc(sizeof(int*) * rows);
    for (y = 0; y < rows; ++y) {
        arr[y] = calloc(sizeof(int), cols);
    }
    return arr;
}

void free_2d_array(int **arr, int rows) {
    int y;
    for (y = 0; y < rows; ++y) {
        free(arr[y]);
    }
    free(arr);
}

// HINT: you may not need all these arguments for part 1 or 2.
int dfs(int **graph, int x, int y, int **visited, int type, int rows, int cols) {
    if (x < 0 || y < 0 || x >= cols || y >= rows || visited[y][x] || graph[y][x] != type) {
        return 0;
    }
    int total = (graph[y][x] == type);
    visited[y][x] = 1;

    total += dfs(graph, x-1, y, visited, type, rows, cols);
    total += dfs(graph, x+1, y, visited, type, rows, cols);
    total += dfs(graph, x, y-1, visited, type, rows, cols);
    total += dfs(graph, x, y+1, visited, type, rows, cols);
    return total;
}

// This is for part 1.
int count(int **graph, int rows, int cols) {
    int **visited = make_2d_array(cols, rows);
    int ret = dfs(graph, 0, 0, visited, graph[0][0], rows, cols);
    free_2d_array(visited, rows);
    return ret;
}

// This is for part 2
int biggest_island_size(int **graph, int rows, int cols) {
    int max = INT_MIN;
    int **visited = make_2d_array(cols, rows);
    int y, x;
    for (y = 0; y < rows; ++y) {
        for (x = 0; x < cols; ++x) {
            int ret = dfs(graph, x, y, visited, 1, rows, cols);
            if (ret > max) {
                max = ret;
            }
        }
    }
    free_2d_array(visited, rows);
    return max;
}


int main(void) {
    int rows, cols;
    scanf("%d %d", &cols, &rows);
    int x, y;

    // make graph
    int **graph = make_2d_array(cols, rows);
    for (y = 0; y < rows; ++y) {
        for (x = 0; x < cols; ++x) {
            scanf("%d", &graph[y][x]);
        }
    }

    // print graph
    printf("Graph:\n");
    for (y = 0; y < rows; ++y) {
        for (x = 0; x < cols; ++x) {
            printf("%d ", graph[y][x]);
        }
        printf("\n");
    }
    
#ifdef PART2
    printf("Biggest: %d\n", biggest_island_size((int**)graph, rows, cols));
#else
    printf("Total: %d\n", count((int**)graph, rows, cols));  
#endif
    
    free_2d_array(graph, rows);

    return EXIT_SUCCESS;
}
