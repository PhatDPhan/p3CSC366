// Tokenzing
// Phat Phan, La Salle University
// project 3 - CSC366
 
// Header file for input output functions
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <string>

using namespace std;
 
 
 
 // Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}
 
 
 
 
 
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
	
	string tableEntry[60];
	
	//read the file

	//counter how many lines in the text file
	int number_of_lines;
	//
	int number_of_words;
	
	//read line by line
	//while (getline(inFile,x))	
	//read word by word (one space => next line)
	while (inFile >> x)
	{
			
		//	print the x to screen;		
		// checked - worked
		//std:: cout << x << endl;
		
		// save the damn line to array of that number of line		
		a[number_of_words] = x;
		
		//count number of line
		//number_of_lines++;
		
		number_of_words++;
				
	}
	
	//checked-worked. print line 2
	//std:: cout << a[2];
	
	
	
	string y;
	for(int i=0; i<number_of_words; i++)
	{
		if(a[i] == "cmt")
		{
			cout << i << endl;
			cout << a[i] << endl;
			cout << "this is a comment"<< endl;			
		}else if(a[i] == "get")
		{
			cout << i<< endl;
			cout << a[i] << endl;
			cout << "this is a read method"<< endl;
		}else if(a[i] == "output")
		{
			cout << i<< endl;
			cout << a[i] << endl;
			cout << "this is a write method"<< endl;
		}else if(a[i] == "goto")
		{
			cout << i<< endl;
			cout << a[i] << endl;
			cout << "this is a branch"<< endl;
		}else if (a[i] == "stop")
		{
			cout << i<< endl;
			cout << a[i] << endl;
			cout << "this is a halt method"<< endl;
		}else if (isNumber(a[i]))
		{
			//do sth
			//cout << "move to this line number"<< endl;
		}
		
		
		
	}
	//print total number of line
	//checked - worked
	//std:: cout << number_of_lines;
	
	
	//close the file
	inFile.close();
    return 0;
}

