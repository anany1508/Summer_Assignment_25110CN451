
#include <iostream>
using namespace std;
const int MAX_CAPACITY = 100; // Fixed max capacity

void displayArray(const int arr[], int size) { /* ... */ }
void insertElement(int arr[], int &size) { /* ... */ }
void deleteElement(int arr[], int &size) { /* ... */ }
int searchElement(const int arr[], int size, int target) { /* ... */ }
void sortArray(int arr[], int size) { /* ... */ }

int main() {
    int arr[MAX_CAPACITY], size = 0, choice;
    // Initialization and loop (1-6 options)
    do {
        // Menu displaying 1. Display, 2. Insert, 3. Delete, 
        // 4. Search, 5. Sort, 6. Exit
        cin >> choice;
        switch(choice) { /* switch case calling functions */ }
    } while (choice != 6);
    return 0;
}
