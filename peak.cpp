#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int length = 0; //length of vector
ifstream in_stream; //input stream object

void getInput(vector <double>& myNum);

int getTarget(int low, int high, vector <double>& myNum);
//getTarget returns the index of the target value p


int main() {
	//declare vector
	vector <double> myNum;

	//open and read file
	in_stream.open("peak.txt");
	if (in_stream.fail()) {
		cout << "Unable to find input file" << endl;
		exit(1);
	}

	//apply values in file
	getInput(myNum);


	int low = 0; //lowest index
	int high = length - 1; //highest index
	int finalTarget = getTarget(low, high, myNum); 
	int finalValue = myNum[finalTarget];
	cout << "p value is" << " " << finalValue << " " << "and its index is" << " " << finalTarget << endl;

	in_stream.close();
	return 0;
}

void getInput(vector <double>& myNum) { //loads vector with data from input file
	double next;
	while (in_stream >> next) {
		myNum.push_back(next);
		length = length + 1;
	}
}


//this is a recursive funtion that continuously "splits" until p is found
int getTarget(int low, int high, vector <double>& myNum) {
	//set target to vector's middle value
	int target = (low + high) / 2;

	//base case
	if (target == high) {
		return target;
	}

	//if left value is higher, p must be in left half
	if (myNum[target] < myNum[target - 1]) {
		high = target - 1;
		getTarget(low, high, myNum);
	}//if right value is higher, p must be in right half
	else if (myNum[target] < myNum[target + 1]) {
		low = target + 1;
		getTarget(low, high, myNum);
	}
	else {
		return target;
	}

}
