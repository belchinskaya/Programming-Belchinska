#define LEN 15
int main() {
	char zap = '_';
	char strIn[] = "Ivanov";
	
	char strResult[LEN];
	
	int lenIn = 0;//кількість елементів заданого масиву

	for (int i = 0; ; i++) {//дізнаємося величину масиву
		if (strIn[i] == '\0') {//якщо елемент масиву '\0', то наступного елементу не існує
			break;
		} else if (strIn[i] != 0) {
			lenIn++;
		}
	}
	int lenZap = LEN - lenIn - 1;//кількість елементів в  масиві, виділених на заповнювач 
	int halfLenZap = lenZap / 2;//кількість заповнювачей перед заданм рядком

	for (int i = 0; i < halfLenZap; i++) {//в початок результуючого масиву вставимо необхідну кількість заповнювачей
		strResult[i] = zap;
	}

	for (int i = halfLenZap; i < (halfLenZap + lenIn);) {//вставимо заданий на початку текст по центру результуючого масиву
		for (int j = 0; j < lenIn; j++) {
			strResult[i] = strIn[j];
			i++;
		}
	}

	for (int i = (halfLenZap + lenIn); i < LEN - 1; i++) {//додаємо у результуючий масив заповнювач до його кінця
		strResult[i] = zap;
	}
	
	strResult[LEN] = '\0';//масив повинен закінчуватися '\0'

	return 0;
}
 
