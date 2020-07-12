#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

/*
Compile: g++ -std=c++11 -pthread -o main.exe main.cpp
Run: ./main.exe
*/

// print function prototype
void read_print(string infile);

int main ()
{
	/*
	1. List file names into variables
	2. Initiate I/O streams
	3. Read & print each input as threads
	4. Close I/O streams
	*/

	// set to true to wait for threads to finish (makes output better, but defeats the purpose of multi-threading)
	bool wait_between_threads = true;
	
	// input files
	string f1 = "sample1.txt";
	string f2 = "sample2.txt";
	string f3 = "sample3.txt";

	// streams
	ifstream in1(f1);
	ifstream in2(f2);
	ifstream in3(f3);

	// start & run threads
	if (wait_between_threads) {
		thread th1(read_print, f1);
		th1.join();
		thread th2(read_print, f2);
		th2.join();
		thread th3(read_print, f3);
		th3.join();
	} else {
		thread th1(read_print, f1);
		thread th2(read_print, f2);
		thread th3(read_print, f3);
			th1.join();
		th2.join();
		th3.join();
	}

	return 0;
}

// open and print function definition
void read_print(string infile)
{
	ifstream input(infile);
	string line;
	if (input.is_open()) {	
		while (getline(input,line)) {
		cout << line << endl;
		}
		input.close();
  	}
	return;
}