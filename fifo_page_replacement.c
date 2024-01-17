#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10

int main() {
    int pages[MAX_PAGES];
    int n, capacity;

    // Get the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Get the page references
    printf("Enter the page references:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Get the capacity of memory
    printf("Enter the capacity of memory: ");
    scanf("%d", &capacity);

    int pageTable[MAX_PAGES];
    int pageFaults = 0;
    int pageTableIndex = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageHit = 0;

        // Check if the page is already in the page table
        for (int j = 0; j < capacity; j++) {
            if (pageTable[j] == currentPage) {
                pageHit = 1;
                break;
            }
        }

        if (!pageHit) {
            // Page fault, replace the oldest page in the page table
            pageTable[pageTableIndex] = currentPage;
            pageTableIndex = (pageTableIndex + 1) % capacity;
            pageFaults++;

            // Print the page table after each page fault
            printf("Page Fault %d: ", pageFaults);
            for (int j = 0; j < capacity; j++) {
                printf("%d ", pageTable[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
