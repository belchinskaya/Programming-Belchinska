#define X 25
int main () {
	int num1 = X;
	int rootFor = 1;
	int rootWhile = 1;
	int rootDo = 1;
	int tempWhile = 0;
	int tempDo = 0;
	for (int tempFor = 0; tempFor != rootFor;) {
		tempFor = num1 / rootFor;
		if (tempFor == rootFor) {
			break;
		}
	rootFor++;
	}
	int resultFor = -1;
	if (rootFor * rootFor == num1) {
		resultFor = rootFor; 
	}
	num1 = X;
	while (tempWhile != rootWhile) {
		tempWhile = num1 / rootWhile;
		if (tempWhile == rootWhile) {
			break;
		}
	rootWhile++;
	}
	int resultWhile = -1;
	if (rootWhile * rootWhile == num1) {
		resultWhile = rootWhile;
	}
	num1 = X;
	do {
		tempDo = num1 / rootDo;
		if (tempDo == rootDo) {
			break;
		}
	rootDo++;
	} while (tempDo != rootDo);
	int resultDo = -1;
	if (rootDo * rootDo == num1) {
		resultDo = rootDo;
	}
return 0;
} 
			
			 
	
