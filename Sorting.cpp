#include <iostream>
#include <fstream>
#include <time.h> // in order to use clock function
#include "Sorting.h"

using namespace std;

Sorting::Sorting(){

}

Sorting::~Sorting(){

  delete [] bubbleArray;
  delete [] insertArray;
  delete [] selectionArray;
  delete [] quickSortArray;
}

// this function will open the file and create the arrays
void Sorting::readFile(string fileName){
  string numElems;
  string line;
  double size; // will be the first line in the file
  int lineNumber = 1;

  ifstream inputFile;
  inputFile.open(fileName.c_str());

  getline(inputFile, numElems);

  nElems = atoi(numElems.c_str()); // convert string to int

  // create arrays for each type of sorting algorithm, make size the first number in the file
  bubbleArray = new double[nElems];
  insertArray = new double[nElems];
  selectionArray = new double[nElems];
  quickSortArray = new double[nElems];

  for(int i = 0; i < nElems; ++i){
    lineNumber ++;

    getline(inputFile, line);
    size = stod(line); // the num of elems to sort

    bubbleArray[i] = size;
    insertArray[i] = size;
    selectionArray[i] = size;
  }

  inputFile.close();

  timer(); // call function to run all algorithms

}

/* Bubble Sort:
- move through array comparing neighboring pairs of elements and swap them if they are not in the correct order
- time complexity: O(n^2)
*/
void Sorting::bubbleSort(double array[], int n){
  for(int i = 0; i <  n; ++i){
    double temp = 0;
    for(int j = 0; j < (n-1); ++j){
      if(array[j] > array[j+1]){
        temp = array[j+1];
        array[j+1] = array[j];
        array[j] = temp;
      }
    }
  }

// check to make sure it's sorting correctly:

  /*cout << "Bubble Sort: " << endl;
  for(int f = 1; f < n; ++f){
    cout<< array[f] << endl;
  }*/
}

/* Insertion Sort:
- use a marker, paritally sorted to left of marker
- check elem to right of marker and move it to it's place on the left
- time complexity: O(n^2)
*/
void Sorting::insertionSort(double array[], int n ){
  for(int i = 1; i < nElems; ++i){ // marker
    double temp = array[i]; // store marked item
    int marker = i; // where to start shiftting
    while(marker > 0 && array[marker-1] >= temp){ // while the thing to the left is larger, shift
      array[marker] = array[marker-1];
      --marker;
    }
    array[marker] = temp; // put marked item in the right spot
  }

}

/*
Selection Sort:
- find the smallest element in the array, bring it to the front, and recurse on rest of array
- time complexity: O(n^2)
*/
void Sorting::selectionSort(double array[], int n){
  int i;
  int j;
  int minIndex;
  int temp;

  for(i = 0; i < n-1; i++){
    minIndex = i;
    for(j = i +1; j < n; j++){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }

    }
    if(minIndex!=i){
      temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }

}


/*
Quick Sort:
- selecting a pivot element and move all elements bigger than the pivot into the right list and smaller than pivot in the left list
- preform this recursively on the two new lists until list size reaches 0 or 1.
- there are different methods for selecting the piovt, in this one we use the median value.
- time complexity: most of the time it is O(nlogn) with randomized pivot. With a very bad pivot it ends up being O(n^2).
*/
void Sorting::quickSort(double array[], int left, int right, int n){
  int index = partition(array, left, right);

  if(left < index-1){ // sort left half
    int idx = index - 1;
    quickSort(array, left, index-1, n);
  }

  if(index < right){ // sort right half
    quickSort(array, index, right, n);
  }

}


int Sorting::partition(double array[], int left, int right){
  //choose middle value as pivot
  int pivot = array[(left+right)/2];

  while(left <= right){
    while(array[left] < pivot){
      // objects to left of pivot
      left ++;
    }
    while(array[right] > pivot){
      // objects to right of pivot
      right --;
    }

    if(left <= right){
      // move elements and swap left and right
      swap(array, left, right);
      left ++;
      right--;
    }
  }
  return left;
}

void Sorting::swap(double array[], int a, int b){
  double temp = array[a];
     array[a] = array[b];
     array[b] = temp;
}



// this function times each sorting algorithm and outputs the time
void Sorting::timer(){
  clock_t start;
  clock_t stop;

  float amntOfTime;

  // bubble sort
  start = clock();
  bubbleSort(bubbleArray, nElems);
  stop = clock();
  amntOfTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000; // 1 second = 1 millisecond
  cout << "Bubble Sort: " << endl;
  cout << "Start time: " << start << endl;
  cout << "Stop time: " << stop << endl;
  cout << "Total amount of time: \n " << amntOfTime << " \n " << endl;

  // insertion sort
  start = clock();
  insertionSort(insertArray, nElems);
  stop = clock();
  amntOfTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000; // 1 second = 1 millisecond
  cout << "Insertion Sort: " << endl;
  cout << "Start time: " << start << endl;
  cout << "Stop time: " << stop << endl;
  cout << "Total amount of time: \n" << amntOfTime << " \n " << endl;

  // selection sort
  start = clock();
  selectionSort(selectionArray, nElems);
  stop = clock();
  amntOfTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000; // 1 second = 1 millisecond
  cout << "Selection Sort: " << endl;
  cout << "Start time: " << start << endl;
  cout << "Stop time: " << stop << endl;
  cout << "Total amount of time: " << amntOfTime << " \n " << endl;

  // quick sort
  start = clock();
  quickSort(quickSortArray, 0, nElems-1, nElems);
  stop = clock();
  amntOfTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000; // 1 second = 1 millisecond
  cout << "Quick Sort: " << endl;
  cout << "Start time: " << start << endl;
  cout << "Stop time: " << stop << endl;
  cout << "Total amount of time: " << amntOfTime << " \n " << endl;


  cout << "\n Done sorting. \n" << endl;

}
