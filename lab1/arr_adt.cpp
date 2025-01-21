#include <iostream>
using namespace std;
#define MAX_SIZE 10

bool checkempty(int size) {
    return size == 0;
}

bool checkfull(int size) {
    return size == MAX_SIZE;
}

void insert(int arr[], int& size) {
    if (checkfull(size)) {
        cout << "Array is full" << endl;
    } else {
        int n;
        cout << "Enter the number of elements to insert: ";
        cin >> n;

        if (size + n > MAX_SIZE) {
            cout << "Not enough space to insert " << n << " elements." << endl;
            return;
        }

        for (int i = 0; i < n; ++i) {
            cout << "Enter the element at index " << size << ": ";
            cin >> arr[size++];
        }
    }
}

void del(int arr[], int& size) {
    if (checkempty(size)) {
        cout << "The list has no elements to delete" << endl;
    } else {
        int flag;
        cout << "Enter the index of the element to delete: ";
        cin >> flag;
        int index = flag - 1;
        if (index >= size || index < 0) {
            cout << "Index you entered is out of range." << endl;
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void search(int arr[], int size) {
    if (checkempty(size)) {
        cout << "The array is empty, so unable to search." << endl;
    } else {
        int element;
        cout << "Enter the element you want to search: ";
        cin >> element;
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == element) {
                cout << "The element was found at index " << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "The element does not exist in the array." << endl;
        }
    }
}

void sort(int arr[], int size) {
    if (checkempty(size)) {
        cout << "Array is empty, so can't be sorted!" << endl;
    } else {
        for (int i = 0; i < size - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                int temp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = temp;
            }
        }
    }
}

void display(int arr[], int size) {
    if (checkempty(size)) {
        cout << "Array has no elements." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void merge(int arr1[], int size1) {
    if (checkempty(size1)) {
        cout << "First array is empty, so can't merge!" << endl;
        return;
    }

    int arr2[MAX_SIZE], size2;
    cout << "Enter the number of elements in the second array: ";
    cin >> size2;

    if (size2 > MAX_SIZE) {
        cout << "Exceeded maximum size for second array. Adjusting to MAX_SIZE." << endl;
        size2 = MAX_SIZE;
    }

    cout << "Enter the elements of the second array:" << endl;
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    cout << "First array: ";
    display(arr1, size1);
    cout << "Second array: ";
    display(arr2, size2);

    int final_size = size1 + size2;
    int mergearr[final_size];
    for (int i = 0; i < size1; ++i) {
        mergearr[i] = arr1[i];
    }
    for (int j = 0; j < size2; ++j) {
        mergearr[size1 + j] = arr2[j];
    }
    cout << "Merged array: ";
    for (int j = 0; j < final_size; ++j) {
        cout << mergearr[j] << " ";
    }
    cout << endl;
}

int main() {
    char ch;
    int arr1[MAX_SIZE];
    int n1 = 0; // Initialize size to 0

    do {
        cout << "----- MENU ------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sort" << endl;
        cout << "5. Display" << endl;
        cout << "6. Merge" << endl;
        cout << "Enter your choice (1-6) or press 'n' to exit: ";
        cin >> ch;

        switch (ch) {
            case '1': {
                cout << "----- INSERT ELEMENT -----" << endl;
                insert(arr1, n1);
                break;
            }
            case '2': {
                cout << "----- DELETE ELEMENT -----" << endl;
                del(arr1, n1);
                cout << "Array after deletion: ";
                display(arr1, n1);
                break;
            }
            case '3': {
                cout << "----- SEARCH ELEMENT -----" << endl;
                search(arr1, n1);
                break;
            }
            case '4': {
                cout << "----- SORT ELEMENT -----" << endl;
                cout << "Before sorting:" << endl;
                display(arr1, n1);
                cout << "After sorting:" << endl;
                sort(arr1, n1);
                display(arr1, n1);
                break;
            }
            case '5': {
                cout << "----- DISPLAY ELEMENT -----" << endl;
                display(arr1, n1);
                break;
            }
            case '6': {
                cout << "----- MERGE ELEMENTS -----" << endl;
                merge(arr1, n1);
                break;
            }
            case 'n': {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (ch != 'n');

    return 0;
}

