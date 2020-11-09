int main() {
	char strIn[] = "Hello  World and others";
	int len = 0;//довжина масиву
	int count = 0;//кількість слів

	for (int i = 0; ; i++) {//знайдемо довжину масиву
		if (strIn[i] == '\0') {
			break;
		} else {
			len++;
		}
	}
	for (int i = 0; i < len; i++) {//знайдемо кількість слів за допомогою останньої букви слова
		if (strIn[i] != ' ' && (strIn[i + 1] == ' ' || strIn[i + 1] == '\0')) {
			count++;
		} 
	}
	return 0;
} 
