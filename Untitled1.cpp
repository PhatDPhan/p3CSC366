// Tokenizing
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
	
	//array to hold each line
	string a[100];
	
	//string to hold each line
	string x;
	//read the file

	//counter how many lines in the text file
	int number_of_lines;

	
	//read line by line
	while (getline(inFile,x))	
	//read word by word (one space => next line)
	//while (inFile >> x)
	{			
		// save the line/word to array of that number of line		
		//a[number_of_words] = x;
		a[number_of_lines] = x;
		
		//count number of line
		number_of_lines++;		
		//number_of_words++;
				
	}//end white
	
	
	//create a 2 dimensional string array
	string LineWord[100][50];
	
	
	//loop through each line and put words in each line to the array
	for(int k=0;k<number_of_lines;k++)
	{
	istringstream iss(a[k]);
    	for(int f=0; f<sizeof(a[k]);f++)
    	{
        	string word;
        	iss >> word;
	
			//2 dimensional array hold value
			// the first number is row, which is line number, second is colum, location of element in each row
			LineWord[k][f] = word;

    	}//end inner for	
	}//end outter for
	
	//Location of line
	int SymbolLine[100];
	
	//Location of line after goto
	int SymbolLineGoto[100];
	//line after goto count
	int lineGotoR;
	int lineGotoC;
	
	//Location of a literal value
	int SymbolLV[100];
	
		
	//Location of a variable
	int SymbolVar[100];
	
	//var counter 
	int varR;
	int varC;
	
	
	
	//counter how many variables
	int variable;
	
	//counter how many constants
	int cons;	
	
	
	//memory location will be the first word in each line	
        for(int r=0;r<number_of_lines;r++)
        {
				for (int c=0; c<50;c++)
				{		
				
					//array SymbolLine will hold the coordinate of line number in pair
					//and now number and the first word is a line number
					
					//do sth
					
					
					//after goto must be an line number
					if(LineWord[r][c]=="goto")	
					{
					//do sth	
					}

					//after get or if. it must be a variable name
					if(LineWord[r][c]=="get"
					{
						//do sth
					}
					
					//after if  must be variable name
					if(LineWord[r][c]=="if")
					 {
					 	//do sth. I mean store value r and c to array or linkelist
					 }
					 
					 
					 //between "=" will be variable and literal
					 if(LineWord[r][c]=="=")
					 {
					 	
					 	//store and determin variable or literal interger
					 }
					 
					 
					 //after output will be variable or literal interge
					 if(LineWord[r][c]=="output")
					 
					 
					 

				}//end inner for
		} //end outer for
	
	
	
	
	
	//close the file
	inFile.close();
    return 0;
}

