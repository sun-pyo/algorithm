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
	char *game = (char*)calloc(42, sizeof(char));
	int i, count_A, count_B;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    count_A=0;
	    count_B=0;
	    cin>>game;
	    for(i=0;game[i];i++){
	        if(game[i]=='A')
	            count_A++;
	        if(game[i]=='B')
	            count_B++;
            if(count_A == 21 || count_B == 21)
                break;
	    }
		cout << "Case #" << test_case+1 <<"\n";
		if(count_A == 21)
		    cout <<"Alice"<<"\n";
		else if(count_B == 21)
		    cout<<"Bob\n";
		else
		    cout<<"Playing\n";
	}

	return 0;//Your program should return 0 on normal termination.
}