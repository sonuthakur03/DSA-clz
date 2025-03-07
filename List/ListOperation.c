#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void create(int[], int *);
void insert(int[], int *);
void deleteElement(int[], int *); // Renamed from 'delete' to 'deleteElement' delete is a keyword
//void update(int[], int *);
//void traverse(int[], int *);
//void searching(int[], int *);
//void merging(int[], int[], int *, int *);

int main() {
    int a[100], b[100], n = 0, m, choice;

    printf("\nMenu for program:\n");
    printf("1: Create\n2: Insert\n3: Delete\n4: Update\n5: Traverse\n6: Searching\n7: Merging\n0: Exit\n");

    while (1) {         
        printf("\nEnter your choice: ");        
        scanf("%d", &choice);                

        switch (choice) {            
            case 1:
                create(a, &n);
                break;
            case 2:
                insert(a, &n);
                break;
            case 3:
                deleteElement(a, &n);
                break;
            /*case 4:
                update(a, &n);
                break;
            case 5:
                traverse(a, &n);
                break;
            case 6:
                searching(a, &n);
                break;
            case 7:
                printf("Enter size of second array: ");
                scanf("%d", &m);
                create(b, &m);
                merging(a, b, &n, &m);
                break;*/
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }    
    }    

    return 0;
}

// Function to create an array
void create(int arr[], int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);
    printf("Enter the elements: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to insert an element at a specific position
void insert(int arr[], int *n) {
    int pos, val;
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &pos);
    
    if (pos > *n || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = val;
    (*n)++;
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *n) { // Renamed function
    int pos;
    printf("Enter the position to delete (0-based index): ");
    scanf("%d", &pos);
    
    if (pos >= *n || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
}

/* Function to update an element at a specific position
void update(int arr[], int *n) {
    int pos, val;
    printf("Enter the position to update (0-based index): ");
    scanf("%d", &pos);
    
    if (pos >= *n || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter the new value: ");
    scanf("%d", &val);
    
    arr[pos] = val;
}

// Function to display all elements
void traverse(int arr[], int *n) {
    if (*n == 0) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Current list: ");
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element
void searching(int arr[], int *n) {
    int val, found = 0;
    printf("Enter the value to search: ");
    scanf("%d", &val);
    
    for (int i = 0; i < *n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Element not found.\n");
    }
}

// Function to merge two arrays
void merging(int a[], int b[], int *n, int *m) {
    for (int i = 0; i < *m; i++) {
        a[*n + i] = b[i];
    }
    
    *n += *m;
    printf("Merged array: ");
    traverse(a, n);
}
*/