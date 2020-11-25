#define NUM 4
void compareNums(int arrayNums[], int len);
int copyOne(char numAsString[], int iStart, char numStr[], int size) {
	for (int t = 0; t < size; t++) {
		numAsString[iStart] = numStr[t];
		iStart++;
	}
	return iStart;
}

int copyNum(int num, char numAsString[], int iStart) {
	char one[3] = {'o','n','e'};
	char two[3] = {'t','w','o'};
	char three[5] = {'t','h','r','e','e'};
	char four[4] = {'f','o','u','r'};
	char five[4] = {'f','i','v','e'};
	char six[3] = {'s','i','x'};
	char seven[5] = {'s','e','v','e','n'};
	char eight[5] = {'e','i','g','h','t'};
	char nine[4] = {'n','i','n','e'};
	switch (num) {
		case 1:
			iStart = copyOne(numAsString, iStart, one, 3);
			break;
		case 2:
			iStart = copyOne(numAsString, iStart, two, 3);
			break;
		case 3:
			iStart = copyOne(numAsString, iStart, three, 5);
			break;
		case 4:
			iStart = copyOne(numAsString, iStart, four, 4);
			break;
		case 5:
			iStart = copyOne(numAsString, iStart, five, 4);
			break;
		case 6:
			iStart = copyOne(numAsString, iStart, six, 3);
			break;
		case 7:
			iStart = copyOne(numAsString, iStart, seven, 5);
			break;
		case 8:
			iStart = copyOne(numAsString, iStart, eight, 5);
			break;
		case 9:
			iStart = copyOne(numAsString, iStart, nine, 4);
			break;
		}
	return iStart;
}


void fillStr(char numAsString[], int num) {
	short size = 0;

	char thousand[10] = {' ','t','h','o','u','s','a','n','d',' '};
	char hundred[9] = {' ','h','u','n','d','r','e','d',' '};
	char decade[8] = {' ','d','e','c','a','d','e',' '};
	int cond = 0;

	for (int i = 10000; i > 0; i /= 10) {
		if (num > 0) {
			cond = num % i;
			if (cond != num) {
				size++;
			}
			num %= i;
		}
	}

	num = NUM;
	int iStart = 0;

	if (size == 4) {
		num = NUM / 1000;
		iStart = copyNum(num, numAsString, iStart);
		iStart = copyOne(numAsString, iStart, thousand, 10);
		size--;
		num = NUM % 1000;
	}
	if (size == 3) {
		num = num / 100;
		iStart = copyNum(num, numAsString, iStart);
		iStart = copyOne(numAsString, iStart, hundred, 9);
		size--;
		num = NUM % 100;
	}

	if (size == 2) {
		num = num / 10;
		iStart = copyNum(num, numAsString, iStart);
		iStart = copyOne(numAsString, iStart, decade, 8);
		size--;
	}

	if (size == 1) {
		num = NUM % 10;
		iStart = copyNum(num, numAsString, iStart);
		numAsString[iStart] = '\0';
	}
}

int main() {
	char arr[50] = {0};
	fillStr(arr, NUM);
	int len = rand() % 10 - 5;
	char arrayNums[len];
	compareNums(arrayNums, len);
	return 0;
	
	
}

void compareNums(int arrayNums[], int len) {
	int count = 0;
	len = rand() % 10 - 5;
	int arrayNumsOut[len];
	
	for (int i = 0; i < len; i++) {
		if (arrayNumsOut[i] < arrayNumsOut[i + 1]) {
			count++;
		}
	}
}
