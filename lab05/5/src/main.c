#define X 25
int main () {
	int num1 = X;
	int resultFor = 0;
	for (int tempFor = 1; tempFor< num1; tempFor++) {
		if (tempFor == (tempFor + (num1 / tempFor)) / 2) {
			resultFor = tempFor;
		}
	}
return 0;
} 
			
			 
	
