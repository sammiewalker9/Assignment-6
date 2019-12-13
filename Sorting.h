using namespace std;

class Sorting{
public:
  Sorting();
  ~Sorting();

  void bubbleSort(double array[], int n);
  void insertionSort(double array[], int n);
  void selectionSort(double array[], int n);
  void quickSort(double array[], int left, int right, int n);
  int partition(double array[], int left, int right);
  void swap(double array[], int a, int b);

  void readFile(string fileName);
  void timer();

  double *bubbleArray;
  double *insertArray;
  double *selectionArray;
  double *quickSortArray;

  int nElems;
  int n;


};
