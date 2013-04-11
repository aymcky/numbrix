#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cellx[] = {-1,0,0,1}, celly[] = {0,1,-1,0};

struct cell{
	int val, x, y;
	bool stable;
};

cell puzzle[81];

typedef vector<cell> vc;
typedef queue<cell> qc;

/*
Prioritizes paths between cells by proximity of next path target

Candice wuz here
*/

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

/*
 *  Loads puzzle from stdin
 *  @connorgreenwell
 */
void loadpuzzle () {
  	int n;
	int countl = 0, countr=0;
	while(countl != 9){
		cin >> n;
		cell current;
		current.val = n, current.x = countr; current.y = countl, current.stable = true;
		if(n != 0)
			puzzle[n-1] = current;
		if(countr==8){
			countl++;
			countr = 0;
		}
		else
			countr++;
	}
}

/* 
Path finding?

-Candice
*/
bool pathform(cell start, cell target){
	if(target.val - start.val > 1){
		pathform(start, puzzle
	}
}

int main(){
  	loadpuzzle();
	
	vc priority = prioritize(81);
	int pos = priority[1].val, count = 1;
	while(pos != 0){
		if(puzzle[pos].val > 0)
			pos = 0;
		pos++;
		count++;
	}

	pathform(puzzle[priority[1].val], puzzle[priority[1].val+count]);

	for(int i = 0; i < 9; i++){
		for(int j=0; j < 9; j++){
			cout << puzzle[i+j].val << " ";
		}
		cout << endl;
	}

	return 0;
}
