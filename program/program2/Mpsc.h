
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Mpsc
{
public:
	
	Mpsc(int size, map<int, int> m, map<int, int> og){ 
		numVec = size; _map = m; _OGmap = og;

		mis = new int*[numVec];
		s = new int*[numVec];
		for(int i=0; i<size; i++){
			mis[i] = new int[size];
			s[i] = new int[size];
		}
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++) mis[i][j] = 0;

	}
	
	~Mpsc(){ delete [] mis;}

	int findVectices(int j){

		map<int, int>::iterator it;
		it = _map.find(j);
		int k = it->second;
		return k;
	}

	void findMaxPlanar()
	{
		int j;
		for(int l=1; l<numVec; l++){
			for(int i=0; i<(numVec-l); i++){
				j = i + l;
				mis[i][j] = mis[i][j-1];
				s[i][j] = 1;

				int k = findVectices(j);

				if(!(j == 0 && k == 0)){
					if(k > j || k < i) { s[i][j] = 1;}
					else if(k < j && k > i){
						//cout << "Case 2." << endl;
						int temp;
						temp = mis[i][k-1] + 1 + mis[k+1][j-1];
						if(temp > mis[i][j]){
							//cout << "Case 2. if." << endl;
							mis[i][j] = temp;
							s[i][j] = 2;
						}
					}
					else if(k == i) {
						//cout << "Case 3." << endl;
						++mis[i][j];
						s[i][j] = 3;
					}
				}
			}
			//cout << "l = " << l << endl;
			//(*this).print();
		}

	}

	int numOfMpsc(){ 
		
		/*
		cout << "mis: " << endl;

		for(int i =0; i<numVec; i++){
			for(int j=0; j<numVec; j++){
				//cout << mis[i][j] << ' ';
				cout << s[i][j] << ' ';
				if((j+1) % numVec == 0) cout << endl;
			}
		}
		
		cout << endl << endl;
		*/
		
		return mis[0][numVec-1];
		
	}	

	void traceChords(int i, int j)
	{
		if(i < j){
			if(s[i][j] == 1) traceChords(i, j-1);
			else if(s[i][j] == 2){

				int k = findVectices(j);
				chord.insert(pair<int, int>(j, k));
				traceChords(i, k-1);
				traceChords(k+1, j);
			}
			else if(s[i][j] == 3){

				int k = findVectices(j);
				chord.insert(pair<int, int>(j, k));
				traceChords(i+1, j-1);
			}
			else if(s[i][j] == 4) traceChords(i-1, j);
		}
	}

	void getChords() { traceChords(0, numVec-1); }

	map<int, int> returnChords(){ 
		
		map<int, int>::iterator it1;
		map<int, int>::iterator it2;
		for(it1 = chord.begin(); it1 != chord.end(); it1++){
			for(it2 = _OGmap.begin(); it2 != _OGmap.end(); it2++){
				if(it1->first == it2->first) break;
				else if(it1->first == it2->second){
					chord.erase(it1);
					chord.insert(pair<int, int>(it2->first, it2->second));
					//cout << "Swap" << endl;
				}
			}
		}
		return chord;
	}

private:
	
	int numVec;
	map<int, int> _map;
	map<int, int> _OGmap;
	map<int, int> chord;
	int **mis;
	int **s;
	int _numOfPlanar;
};
