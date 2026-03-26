#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);   // step size (must not be zero)
}

void insert(int table[], int key) {
    int index = hash1(key);

    // if empty, place directly
    if (table[index] == EMPTY) {
        table[index] = key;
        return;
    }

    // collision → double hashing
    int step = hash2(key);
    int i = 1;

    while (1) {
        int newIndex = (index + i * step) % SIZE;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
        i++;
    }
}

void display(int table[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, table[i]);
    }
}

int main() {
    int table[SIZE];

    // initialize table
    for (int i = 0; i < SIZE; i++) {
        table[i] = EMPTY;
    }

    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }

    display(table);
    return 0;
}