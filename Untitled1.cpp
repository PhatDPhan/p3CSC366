// Simple C++ program to display "Hello World"
 
// Header file for input output functions
#include <iostream>
#include <iomanip>
#include <fstream> 
 
using namespace std;
 
// main function -
// where the execution of program begins
int main()
{
    // streaming file
    ifstream inFile;
    
    //inFile point to the location of file you want to read
    inFile.open("C:\\Users\\phand\\Desktop\\cpp\\p3.txt");
    
    //check if the file is not readable
    if (!inFile) 
	{
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
	}
	
	string a[1000];
	string x;
	
	//read the file

	//counter how many lines in the text file
	int number_of_lines;
	
	//read line by line
	//while (getline(inFile,x))	
	//read word by word (one space => next line)
	while (inFile >> x)
	{
			
	//	print the x to screen;
		//std:: cout << x << endl;
		
		std:: cout << x << endl;
		
		number_of_lines++;
				
	}
	
	
	std:: cout << number_of_lines;
	
	
	//close the file
	inFile.close();
    return 0;
}

