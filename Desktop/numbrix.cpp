#include <iostream>
#include <vector>

using namespace std;

int cellx[] = {-1,0,0,1}, celly[] = {0,1,-1,0};

struct cell{
	int val;
	int x;
	int y;
	bool stable;
};

cell puzzle[81];

typedef vector<cell> vc;


vc prioritize(int n){
	int count = 0;
	vc priority;
	for(int i = 0; i < 81; i++){
		if(puzzle[i].val != 0){
			if(n > count && count > 1){
				n = count;
				priority.clear();
				priority.push_back(puzzle[i-count]);
			}
			else if(n == count){
				priority.push_back(puzzle[i-count]);
			}
			count = 0;
		}
		count++;
	}

	return priority;
}

int main(){
	int n;
	int countl = 0, countr=0;
	while(countl != 9){
		cin >> n;
		cell current;
		current.val = n, current.x = countr; current.y = countl, current.stable = true;
		puzzle[n-1] = current;
		if(countr==8){
			countl++;
			countr = 0;
		}
		else
			countr++;
	}

	
	vc priority = prioritize(81);
	cout << priority[1].val << "  (" << priority[1].x << "," << priority[1].y << ") stable:" << priority[1].stable << endl;

	

	return 0;
}
