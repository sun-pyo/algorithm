/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
    char *start = (char*)malloc(sizeof(char)*5);
    char *end = (char*)malloc(sizeof(char)*5);
    int  hh1,hh2,hh3,mm1,mm2,mm3;
	for(test_case = 0; test_case  < T; test_case++)
	{

        scanf("%s %s",start, end);

        

        hh1 = start[0] - '0';
        hh1 *= 10;
        hh1 += start[1] - '0';
        

        mm1 = start[3] - '0';
        mm1 *= 10;
        mm1 += start[4]-'0';
        

        hh2 = end[0] - '0';
        hh2 *= 10;
        hh2 += end[1] - '0';
        

        mm2 = end[3] - '0';
        mm2 *= 10;
        mm2 += end[4]-'0';
        

        
        if(mm1 > mm2){
            mm3 = 60 - mm1 + mm2;
            hh3 = hh2 - hh1 - 1;
        }
        else{
            mm3 = mm2 - mm1;
            hh3 = hh2 - hh1;
        }
        
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout <<hh3/10<<hh3%10<<":"<<mm3/10<<mm3%10<< endl;
	}
	free(start);
	//free(end);

	return 0;//Your program should return 0 on normal termination.
}