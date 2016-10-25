
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
//#include <climits>
#include "sortAlg.h"
using namespace std;
/*****
ASCII:

int('!') = 33;
	:
	:
int('~') = 126;

*****/



//--------------------------------------------------------
//				Insertion Sort
//--------------------------------------------------------

void
sortAlg::insertionSort(string *a){
	
	for(int j=1; j<_size; j++){
		string key = a[j];
		// Insert a[j] into the sorted sequence a[1...j-1]
		int i = j - 1;
		while(i >= 0 && comStringLarge(a[i], key, 0)){
			a[i+1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}

};




//--------------------------------------------------------
//				Merge Sort
//--------------------------------------------------------

void
sortAlg::mergeSort(string *a, int p, int r){

	if(p < r){
		int q = floor((p+r)/2);
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}else return;
};

void
sortAlg::merge(string *a, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	string *L = new string[n1+1];
	string *R = new string[n2+1];
	//vector<string> L;
	//vector<string> R;
	for(int i=0; i<n1; i++) L[i] = a[p+i];
	for(int j=0; j<n2; j++) R[j] = a[q+j+1];
	L[n1] = "~"; // Max ASCII
	R[n2] = "~"; // Max ASCII
	//L.push_back("~");
	//R.push_back("~");
	int i = 0;
	int j = 0;
	for(int k=p; k<=r; k++){
		if(!comStringLarge(L[i], R[j], 0)){   // L[i] <= R[j]
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}

	delete [] L;
	delete [] R;
};




//--------------------------------------------------------
//				Heap Sort
//--------------------------------------------------------

void
sortAlg::heapSort(string *a){

	buildMaxHeap(a);
	for(int i = _size-1; i >=1; i--){

		string exchange;
		exchange = a[0];
		a[0] = a[i];
		a[i] = exchange;
		heapSize -= 1;
		maxHeapify(a, 0);
	}

};

void sortAlg::maxHeapify(string *a, int i){

	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	if(l <= heapSize-1 && comStringLarge(a[l], a[i], 0)) largest = l; // A[l] > A[i]
	else largest = i;

	if(r <= heapSize-1 && comStringLarge(a[r], a[largest], 0)) largest = r; // A[r] > A[largest]
	if(largest != i){
		string exchange;
		exchange = a[i];
		a[i] = a[largest];
		a[largest] = exchange;
		maxHeapify(a, largest);
	}
};

void sortAlg::buildMaxHeap(string *a){

	heapSize = _size;
	for(int i = floor((_size-1)/2); i>=0; i--) maxHeapify(a, i);
};



//--------------------------------------------------------
//				Quick Sort
//--------------------------------------------------------


void
sortAlg::quickSort(string *a, int p, int r){
	if(p < r){
		int q = hoarePartition(a, p, r);
		quickSort(a, p, q);
		quickSort(a, q+1, r);
	}else return;
};

int
sortAlg::hoarePartition(string *a, int p, int r){
	string x = a[p];
	int i = p - 1;
	int j = r + 1;
	while(true){
		do{j--;} while(comStringLarge(a[j], x, 0)); // Until A[j] <= x
		do{i++;} while(comStringLarge(x, a[i], 0)); // Until A[i] >= x
		if(i < j){
			string exchange = a[i];
			a[i] = a[j];
			a[j] = exchange;
		}else return j;
	}
};



//--------------------------------------------------------
//		comStringLarge
//--------------------------------------------------------

// If equal = 0 -> ">"
//    equal!= 0 -> ">="

bool
sortAlg::comStringLarge(string &a, string &b, int equal = 0){

	

		for(int i=0; i<max(a.length(), b.length()); i++){
		
			if(a[i] == ' ') return false; 				// Compare to the string end and a still not bigger than b
			else if(b[i] == ' ') return true;			// In case not to compare into the order string
		
			if(int(a[i]) == int(b[i])) continue;
			else if(int(a[i]) > int(b[i])) return true;
			else if(int(a[i]) < int(b[i])) return false;
			
		}

		return false;
	
}

