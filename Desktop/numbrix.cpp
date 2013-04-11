#include <iostream>

using namespace std;

int cellx[] = {-1,0,0,1}, celly[] = {0,1,-1,0};

struct cell{
	int val;
	int x;
	int y;
};

cell puzzle[81];

int main(){
	int n;
	int countl = 0, countr=0;
	while(countl != 9){
		cin >> n;
		cell current;
		current.val = n, current.x = countr; current.y = countl;
		puzzle[n-1] = current;
		if(countr==8){
			countl++;
			countr = 0;
		}
		else
			countr++;
	}

	

	

	return 0;
}
