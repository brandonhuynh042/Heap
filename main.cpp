#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* This program creates max a max heap, with options to add, remove, and print.
 * Brandon Huynh, last edited 2/10/2025 */

void numberAdd(int num, int numCount, int* &heap);
void sortAdd(int num, int child, int* &heap);
void deleteRoot(int &numCount, int* &heap);
void print(int pos, int depth, int size, int* heap);
int main() {
  // initialize heap
  int* heap = new int[100];
  char input[9];
  int numCount = 0;
  bool quit = false;
  while (quit != true) {
  cout << "You can: \'ADD\' \'PRINT\' \'DELETE\' \'QUIT\'" << endl;
  cin >> input;
  if (strcmp(input, "ADD") == 0) {
    // determine which method they want to add by
     cout << "FILE or MANUAL?" << endl;
     char addInput[8];
     cin >> addInput;
     if (strcmp(addInput, "FILE") == 0) {
       // open file, add numbers in one by one
       ifstream sequence("numbers.txt");
       int number;
       while (sequence >> number) {
	 numberAdd(number, numCount, heap);
	 numCount++;
       }
     }
     // adding number by user input
     else if (strcmp(addInput, "MANUAL") == 0) {
       cout << "What number would you like to add?" << endl;
       int addNumber;
       cin >> addNumber;
       numberAdd(addNumber, numCount, heap);
       numCount++;
     }
  }
  else if (strcmp(input, "PRINT") == 0) {
    /*  for (int i = 1; i < numCount + 1; i++) {
      cout << heap[i] << " ";
    }
    cout << "\n";
    cout << numCount << endl;
    */
    // go to printing function
    print(1, 0, numCount+1, heap);
  }
   else if (strcmp(input, "DELETE") == 0) {
     // determine if they want root delete or to delete everything
     cout << "ROOT or ALL?" << endl;
     char delInput[6];
     cin >> delInput;
     if (strcmp(delInput, "ROOT") == 0) {
       // delete just the root
       deleteRoot(numCount, heap);
     }
     else if (strcmp(delInput, "ALL") == 0) {
       //cout << "there are " << numCount << endl;
       int count = numCount;
       // everything can be deleted by deleting the root over and over again until there's nothing left
       for (int i = 0; i < count; i++) {
	 deleteRoot(numCount, heap);
       }
     }
   }
   else if (strcmp(input, "QUIT") == 0) {
     quit = true;
   }
  }
  return 0;
}

void numberAdd(int num, int numCount, int* &heap) {
  // if the heap is empty
  if (numCount == 0) {
    heap[1] = num;
    return;
  }
  numCount++;
  // determine parent 
  int parent;
  if (numCount % 2 == 0) {
    parent = numCount / 2;
  }
  else {
    parent = (numCount - 1) / 2;
  }
  // go to sorting process
  heap[numCount] = num;
  if (num > heap[parent]) {
    sortAdd(num, numCount, heap);
  }
}

void sortAdd(int num, int child, int* &heap) {
  // if the new number has reached the root
  if (child <= 1) {
    return;
  }
  // find the parent
  int parent;
  if (child % 2 == 0) {
    parent = child / 2;
  }
  else {
    parent = (child - 1) / 2;
  }
  // if the number is greater than the parent, swap the nodes and go again.
  if (num > heap[parent]) {
    int temp = heap[parent];
    heap[parent] = num;
    heap[child] = temp;
    sortAdd(num, parent, heap);
  }
}


void deleteRoot(int &numCount, int* &heap) {
  // output the root
  cout << "deleting: " << heap[1] << endl;
  // swap the root and last one, delete last one
  heap[1] = heap[numCount];
  heap[numCount] = 0;
  numCount--;
  // starting with the root, find it's children
  int index = 1;
  int left = index * 2;
  int right = (index * 2) + 1;
  // if one of the children is larger than the parent
  while (heap[index] < heap[left] || heap[index] < heap[right] && index < numCount) {
    // which child is larger? swap with that one and that becomes the new parent to go through again
    if (heap[left] > heap[right]) {
      int temp = heap[index];
      heap[index] = heap[left];
      heap[left] = temp;
      index = left;
      left = index*2;
      right = (index*2) + 1;
    }
    else {
      int temp = heap[index];
      heap[index] = heap[right];
      heap[right] = temp;
      index = right;
      left = index*2;
      right = (index*2) + 1;
    }
  }
}

// uses board print function
void print(int pos, int depth, int size, int* heap) {
  // recurse through right child
  if ((pos*2) + 1 < size) {
    print ((pos*2) + 1, depth+1, size, heap); 
    }
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << heap[pos] << endl;
  // recurse through left child
  if (pos*2 < size) {
    print(pos*2, depth+1, size, heap);
  }
  }

