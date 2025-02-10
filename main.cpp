#include <iostream>
#include <cstring>
using namespace std;
void numberAdd(int num, int numCount, int* &heap);
void sortAdd(int num, int child, int* &heap);
int main() {
  int* heap = new int[100];
  char input[9];
  int numCount = 0;
  bool quit = false;
  while (quit != true) {
  cout << "You can: \'ADD\' \'PRINT\' \'DELETE\' \'QUIT\'" << endl;
  cin >> input;
  if (strcmp(input, "ADD") == 0) {
     cout << "FILE or MANUAL?" << endl;
     char addInput[8];
     cin >> addInput;
     if (strcmp(addInput, "FILE") == 0) {

     }
     else if (strcmp(addInput, "MANUAL") == 0) {
       cout << "What number would you like to add?" << endl;
       int addNumber;
       cin >> addNumber;
       numberAdd(addNumber, numCount, heap);
       numCount++;
     }
  }
  else if (strcmp(input, "PRINT") == 0) {
    for (int i = 1; i < numCount + 1; i++) {
      cout << heap[i] << " ";
    }
    cout << "\n";
  }
   else if (strcmp(input, "DELETE") == 0) {

   }
   else if (strcmp(input, "QUIT") == 0) {
     quit = true;
   }
  }
  return 0;
}

void numberAdd(int num, int numCount, int* &heap) {
  if (numCount == 0) {
    heap[1] = num;
    return;
  }
  numCount++;
  int parent;
  if (numCount % 2 == 0) {
    parent = numCount / 2;
  }
  else {
    parent = (numCount - 1) / 2;
  }
  heap[numCount] = num;
  if (num > heap[parent]) {
    sortAdd(num, numCount, heap);
  }
}

void sortAdd(int num, int child, int* &heap) {
  if (child <= 1) {
    return;
  }
  int parent;
  if (child % 2 == 0) {
    parent = child / 2;
  }
  else {
    parent = (child - 1) / 2;
  }
  if (num > heap[parent]) {
    int temp = heap[parent];
    heap[parent] = num;
    heap[child] = temp;
    sortAdd(num, parent, heap);
  }
}


