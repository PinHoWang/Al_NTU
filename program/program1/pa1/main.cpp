#include <cstdio>
#include <iostream>
#include <fstream>
//#include <string>
#include "parser.h"
#include "sortAlg.h"


int main( int argc, char** argv )
{

    sortAlg object;

    if(argc == 3){

    // Declare the functional objects
        AlgParser p;
        AlgTimer t;
    // Pass the arguement 1 as the input file name
        p.Parse( argv[1] );
    // Start timer
        t.Begin();
    // Display all strings and word numbers
        string *a = new string[p.QueryTotalStringCount()];

        //string *b = new string[5];
        //b[0] = "4"; b[1] = "1"; b[2] = "3"; b[3] = "2"; b[4] = "16";
        for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
        {
            //cout << p.QueryString(i) << " " << p. QueryWordOrder(i) << endl;
            a[i] = p.QueryString(i) + " " + to_string(i+1);
            //cout << a[i] << endl;
        }

        object.getSize(p.QueryTotalStringCount());
        //object.insertionSort(a);
        //object.mergeSort(a, 0, p.QueryTotalStringCount());
        //cout << argv[0][0] << endl;

        /*
        object.getSize(5);
        object.heapSort(b);
        for(int i=4; i>=0; i--) cout << b[i] << endl;
        */
    
        
        if(argv[0][2] == 'i') object.insertionSort(a);
        else if(argv[0][2] == 'm') object.mergeSort(a, 0, p.QueryTotalStringCount()-1);
        else if(argv[0][2] == 'h') object.heapSort(a);
        else if(argv[0][2] == 'q') object.quickSort(a, 0, p.QueryTotalStringCount()-1);
        else cout << "Wrong executable file name!" << endl;
        

        //cout << p.QueryTotalStringCount() << endl << endl;
     
        //for(int j=0; j<p.QueryTotalStringCount(); j++) cout << a[j] << endl;
        
        


        
        // Write into a .dat file
        ofstream outFile;
        outFile.open(argv[2], ios::app);

        if(outFile.is_open()){

            outFile << p.QueryTotalStringCount() << "\n\n";

            for(int i=0; i<p.QueryTotalStringCount(); i++)
                outFile << a[i] << "\n";

        }else {
            cout << "Error: cannot write in .dat file!" << endl;
            exit(-1);
        }
        
    
    
        delete [] a;
        //delete [] b;
		//getchar();
    // Display the accumulated time
        cout << "The execution spends " << t.End() << " seconds" << endl;

    }else {
        cout << "Error: illegal number of argument!" << endl;
        object.usage();
        exit(-1);
    }

    
    return 1; 

}

