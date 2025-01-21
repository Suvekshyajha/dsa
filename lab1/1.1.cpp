#include <iostream>
using namespace std;
#define MAX_SIZE 10

bool checkempty(int size) {
    return size == 0;
}

bool checkfull(int size) {
    return size >= MAX_SIZE;
}

void insert(int arr[], int& size) {
    if (checkfull(size)) {
        cout << "Array is full" << endl;
    } else {
        int numElements;
        cout << "How many elements do you want to enter? ";
        cin >> numElements;

        // Check if the number of elements to insert exceeds available space
        if (size + numElements > MAX_SIZE) {
            cout << "Not enough space to insert " << numElements << " elements. Array is full!" << endl;
        } else {
            for (int i = 0; i < numElements; ++i) {
                cout << "Enter the element at index " << size << ": ";
                cin >> arr[size];
                size++;
                if (checkfull(size)) {
                    cout << "Array is full. Cannot insert more elements." << endl;
                    break;
                }
            }
        }
    }
}

void del(int arr[], int& size) {
    if (checkempty(size)) {
        cout << "The list has no elements to delete" << endl;
    } else {
        int flag;
        char in;
        cout<<"do you want to 1.delete whole array or 2.only a element?"<<endl;
        cin>>in;
        if(in=='1'){
        	size=0;
        	cout<<"the array has been cleared."<<endl;
		}
		else if(in=='2'){
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
        	cout<<"after deletion:"<<endl;
        	for(int i=0;i<size;++i){
        		cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"please enter among given choices"<<endl;
			return;
		}
        
    }
    
}

void search(int arr[], int size) {
    if (checkempty(size)) {
        cout << "The array is empty so unable to search" << endl;
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
        cout << "Array is empty so can't be sorted!" << endl;
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

void merge(int arr1[], int size1, int arr2[], int size2) {
    if (checkempty(size1)) {
        cout << "First array is empty, so can't merge!" << endl;
        return;
    }

    // Input size of the second array
    cout << "Enter the number of elements in the second array: ";
    cin >> size2;

    // Input elements for the second array
    cout << "Enter elements for the second array:" << endl;
    for (int i = 0; i < size2; ++i) {
        cout << "Enter element at index " << i + 1 << ": ";
        cin >> arr2[i];
    }

    // Merge both arrays
    int final_size = size1 + size2;
    int mergearr[final_size];

    // Copy elements from the first array
    for (int i = 0; i < size1; ++i) {
        mergearr[i] = arr1[i];
    }
    // Copy elements from the second array
    for (int j = 0; j < size2; ++j) {
        mergearr[size1 + j] = arr2[j];
    }

    // Display merged array
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
                int arr2[MAX_SIZE], n2;
                cout << "Enter the size of the second array: ";
                cin >> n2;
                
                cout << "First array: ";
                display(arr1, n1);
                cout << "Second array: ";
                display(arr2, n2);
                cout << "Merging arrays..." << endl;
                merge(arr1, n1, arr2, n2);
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

