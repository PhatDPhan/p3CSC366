// Tokenizing
// Phat Phan, La Salle University
// project 3 - CSC366
 
// Header file for input output functions
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>


using namespace std;
 
 
 
// Returns true if string is a number else false
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
    
    //inFile point to the location of the file you want to read
    // can be the path or just name of the file if it's in the same folder of the program
    // path checked: C:\\Users\\phand\\Desktop\\cpp\\p3.txt
    inFile.open("p3.txt");
    
    //check if the file is readable or not
    if (!inFile) 
	{
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
	}
	
	//array to hold each line
	string a[50];
	
	//string to hold each line
	// it's somehow has dynamic lenght ?!
	string x;

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
	//number_of_lines of code as max, assuming each line has as most 10 words
	//it's a waste, but didn't find better solutions at the moment
	string LineWord[number_of_lines][20];
	
	
	//loop through each line and put words in each line to the array
	//this will populate squence of token into 2D array
	for(int k=0;k<number_of_lines;k++)
	{
		//read each line
	istringstream iss(a[k]);
		//loop through each word in each line
    	for(int f=0; f<sizeof(a[k]);f++)
    	{
    		
        	string word;
        	iss >> word;	
			//2 dimensional array hold value
			// the first number is row, which is the number of line (not the line number in IML), second is colum, location of element in each row(words, tokens)
			LineWord[k][f] = word;

    	}//end inner for	
	}//end outter for
	
	
	
	//RL stands for row location
	//CL stands for column location
	
	//arrray to hold variable location row
	int varlocationR[100];
	//arrray to hold variable location second array
	int varlocationC[100];
	//counter of variable row/line location
	int varRL=0;
	//counter of literal integer colum location;
	int varCL=0;
	 
	 
	//array to hold literal integer location in 2darray
	int numR[100];
	int numC[100];
	
	//counter 
	int numCountR=0;
	int numCountC=0;
	
	//array to hold line number of IML after "goto"
	int gotoR[100];
	int gotoC[100];
	
	//counter
	int gotoCountR=0;
	int gotoCountC=0;
	
	//loop through the 2D array to store the location of the symbol you want	
        for(int r=0;r<number_of_lines;r++)
        {
				for (int c=0; c<20;c++)
				{	
									
					//after get . it must be a variable name
					if(!LineWord[r][c].compare("get"))
					{
						varlocationR[varRL] = r;
						varlocationC[varCL] = c+1 ;
						varRL++;
						varCL++;
					}
					
					//after if  must be variable name
					if(!LineWord[r][c].compare("if"))
					 {
					 	varlocationR[varRL] = r;
						varlocationC[varCL] = c+1 ;
						varRL++;
						varCL++;
					 }
					 
					//after let  must be variable name
					if(!LineWord[r][c].compare("let"))
					 {
					 	varlocationR[varRL] = r;
						varlocationC[varCL] = c+1 ;
						varRL++;
						varCL++;
					 }
					 
					//after "=, >, <, or !=.  ", must be variable or literal integer
					if(!LineWord[r][c].compare("=") || !LineWord[r][c].compare(">") || !LineWord[r][c].compare("<") ||!LineWord[r][c].compare("!="))
					 {
					 	if(!isNumber(LineWord[r][c+1]))
					 	{
					 	varlocationR[varRL] = r;
						varlocationC[varCL] = c+1 ;
						varRL++;
						varCL++;
						}else
						{
							numR[numCountR] = r;
							numC[numCountC] = c+1;
							
							numCountR++;
							numCountC++;
						}
					 }
					
					//after "+,-,*,/", must be variable or literal integer
					if(!LineWord[r][c].compare("-") || !LineWord[r][c].compare("+") || !LineWord[r][c].compare("/") || !LineWord[r][c].compare("*") )
					 {
					 	if(!isNumber(LineWord[r][c+1]))
					 	{
					 	varlocationR[varRL] = r;
						varlocationC[varCL] = c+1 ;
						varRL++;
						varCL++;
						}else
						{
							numR[numCountR] = r;
							numC[numCountC] = c+1;
							
							numCountR++;
							numCountC++;
						}
					 }
					 
					 
					//after goto . it must be a IML line number
					if(!LineWord[r][c].compare("goto"))
					{
						gotoR[gotoCountR] = r;
						gotoC[gotoCountC] = c+1 ;
						gotoCountR++;
						gotoCountC++;
					}
					 
			
				}//end inner for
	
		} //end outer for
			


	cout<< "I have " << varRL << " variable/s. Below are these location in 2D array";
	
	cout << endl;
	
	//the location of each variable, what line it on and what elecment is it
	for (int i=0;i<varRL;i++)
	{
		cout << varlocationR[i];
		cout << varlocationC[i];
		cout << endl;
	}
	
	cout << endl;
	
	cout<< "I have " << numCountR << " literal integer/s. Below are these location in 2D array";
	
	cout << endl;
	
	//the location of each variable, what line it on and what elecment is it
	for (int i=0;i<numCountR;i++)
	{
		cout << numR[i];
		cout << numC[i];
		cout << endl;
	}
	
	cout << endl;
	cout << "Below are line number in IML location in 2D array after 'goto' ";
	cout << endl;
		//the location of each variable, what line it on and what elecment is it
	for (int i=0;i<gotoCountR;i++)
	{
		cout << gotoR[i];
		cout << gotoC[i];
		cout << endl;
	}
	
	cout << endl;
	
	cout <<"to get the actual value of literal integer name of variable of all above we just need to plug the number in 2Darray. For example";
	cout << endl;
	cout<< "This is the value of second literal integer in the plain text: ";
	cout<< LineWord[numR[1]][numC[1]];
	cout << endl;
	cout<< "its location in 2D array is: " << numR[1] << numC[1];
	
	cout << endl;
	cout << endl;
	cout << "Below are line number in IML. Line number of IML is the first word on each code line so don't need to remember";
	cout << endl;
	//first word of each line is a line number in IML. No need to store	
	for(int i=0;i<number_of_lines;i++)
	{
		cout << LineWord[i][0];
		cout << endl;
	}
	
	
	inFile.close();
    return 0;
}

