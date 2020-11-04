#define X 25
int main () {
	int num1 = X;
	int sqrtFor = 0;
	int sqrtWhile = 0;
	int sqrtDo = 0;
	int tempWhile = 1;
	int tempDo = 1;
	for (int tempFor = 1; tempFor< num1; tempFor++) {
		if (tempFor == (tempFor + (num1 / tempFor)) / 2) {
			sqrtFor = tempFor;
		}
	}
	num1 = X;
	while (tempWhile < num1) {
		if (tempWhile == (tempWhile + (num1 / tempWhile)) / 2) {
			sqrtWhile = tempWhile;
		}
	tempWhile++;
	}
	num1 = X;
	do {
		if (tempDo == (tempDo + (num1 / tempDo)) / 2) {
			sqrtDo = tempDo;
		}
	tempDo++;
	} while (tempDo < num1);
return 0;
} 
			
			 
	
