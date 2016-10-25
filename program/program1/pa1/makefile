
I = insertionsort
MER = mergesort
H = heapsort
Q = quicksort
P = parser
S = sortAlg
M = main

all:
	@g++ -o $(I) $(M).cpp $(P).cpp $(S).cpp 
	@g++ -o $(MER) $(M).cpp $(P).cpp $(S).cpp 
	@g++ -o $(H) $(M).cpp $(P).cpp $(S).cpp 
	@g++ -o $(Q) $(M).cpp $(P).cpp $(S).cpp 
clean:
	@echo "Cleaning Executable Binary ..."
	@rm -f $(I) $(MER) $(H) $(Q) 

