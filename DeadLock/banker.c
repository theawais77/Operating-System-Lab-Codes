#include <stdio.h>

int main()
{
    int n = 4; // number of processes
    int m = 3; // number of resources

    // Allocation Matrix
    int allocated[4][3] = {
        {3, 0, 1},
        {2, 1, 1},
        {3, 1, 2},
        {0, 1, 1}
    };

    // Maximum Matrix
    int max[4][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 2, 2},
        {2, 2, 2}
    };

    // Available Resources
    int available[3] = {4, 1, 1};

    // Need Matrix (Max - Allocation)
    int need[4][3] = {
        {4, 3, 2},
        {1, 1, 1},
        {6, 1, 0},
        {2, 1, 1}
    };

    int safeseq[4];   // to store safe sequence
    int finish[4] = {0, 0, 0, 0}; // 0 = not finished, 1 = finished

    int count = 0; // number of processes completed

    // ---------------- SAFETY ALGORITHM ----------------
    while (count < n)
    {
        int found = 0; // flag to check if any process can execute

        for (int i = 0; i < n; i++)
        {
            // Check only unfinished processes
            if (finish[i] == 0)
            {
                int j;
                // Check if need <= available
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                        break;
                }

                // If all resource needs are satisfied
                if (j == m)
                {
                    // Release resources of process i
                    for (int k = 0; k < m; k++)
                        available[k] += allocated[i][k];

                    // Add process to safe sequence
                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could execute → unsafe state
        if (found == 0)
        {
            printf("System is NOT in a safe state (Deadlock possible)\n");
            return 0;
        }
    }

    // ---------------- PRINT SAFE SEQUENCE ----------------
    printf("System is in a SAFE state\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeseq[i]);

    printf("\n");
    return 0;
}

