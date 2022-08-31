#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int curr[5][5];
    int max_claim[5][5];
    int avl[5];
    int avl0[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int processes[5];
int resourse[5];
    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;
 
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);
 
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        processes[i] = 1;
        count++;
    }
 
 
    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &curr[i][j]);
    }
 
    printf("\nEnter Maximum Claim table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }
     printf("\nEnter resourse table: ");
 for (i = 0; i < r; i++) {
            scanf("%d", &resourse[i]);
    }

 
    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }
 
    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];
 
    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++){
        printf("%d ", alloc[i]);
    }
 
    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++){
        printf("%d ", resourse[i]-=alloc[i]);
    }
    printf("\n");
      printf("\nRemaining of Need: ");
      for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++){
           printf("%d  ", max_claim[i][j]-=curr[i][j]);
        }

      }

    return 0;
}