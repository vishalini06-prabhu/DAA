#include <stdio.h>
#include <stdlib.h> // Required for abs() function

int x[20]; // Array to store positions (supports up to 20 queens)

// Logic for 'Place(k, i)' from your image
int Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        // Checks if another queen is in the same column or same diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return 0; // 0 means False (cannot place here)
        }
    }
    return 1; // 1 means True (safe to place)
}

// Logic for 'Algorithm NQueens(k, n)' from your image
void NQueens(int k, int n) {
    // Line 6: for i := 1 to n do
    for (int i = 1; i <= n; i++) {
        // Line 8: if Place(k, i) then
        if (Place(k, i)) {
            // Line 10: x[k] := i
            x[k] = i;

            // Line 11: if (k = n) then write (x[1 : n])
            if (k == n) {
                printf("Solution found: ");
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            // Line 12: else NQueens(k + 1, n)
            else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("--- N-Queens Solver ---\n");
    printf("Enter the number of queens (e.g., 4): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a number greater than 0.\n");
    } else {
        printf("\nSearching for all possible ways to place %d queens...\n", n);
        printf("--------------------------------------------------\n");

        // Start the algorithm with the 1st queen
        NQueens(1, n);

        printf("--------------------------------------------------\n");
        printf("Search complete.\n");
    }

    return 0;
}
