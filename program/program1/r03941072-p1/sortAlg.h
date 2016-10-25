


#include <iostream>
#include <map>
using namespace std;

#ifndef SORTALG_H
#define SORTALG_H



class sortAlg {

public:
	// InsertionSort member functions
	void insertionSort(string *);
	
	// MergeSort member functions
	void mergeSort(string *, int, int);
	void merge(string *, int, int, int);
	
	// HeapSort member functions
	void heapSort(string *);
	void maxHeapify(string *, int);
	void buildMaxHeap(string *);
	
	
	// QuickSort member functions
	void quickSort(string *, int, int);
	int hoarePartition(string *, int, int);
	
	bool comStringLarge(string&, string&, int);
	void getSize(int x){_size = x;};

	// Helper
	void usage(){cout << "Usage: [executable_file_name] [input_file_name] [output_file_name]" << endl;};
private:

	size_t _size;
	int heapSize;

};


#endif