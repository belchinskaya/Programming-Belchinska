#include <stdlib.h>
#include <time.h>


void get_prime_num_array(int len, int PD, int KD);//попереднє оголошення функції

int main() {
	int const PD = 1;//початок діапазону для знаходження простих чисел
	int const KD = 50;//кінець діапазону для знаходження простих чисел
	srand(time(NULL));
	int len = rand() % 101 + 10;//за допомогою генератора псевдорандомноих чисел оприділяємо довжину результуючого масиву
	get_prime_num_array(len, PD, KD);//функція нічого не повертає, лиш змінює значення змінних всередині себе
	return 0;
}



void get_prime_num_array(int len, int PD, int KD) {
	int prime[len];// = {0};//результуючий масив з простих чисел спочатку повністю заповнений нулями
	int j = 0;
	for (int diap = PD; diap < KD; diap++ ) {//в заданому діапазоні вводимо змінну, щоб оприділяти чи є число простим
		int flag = 0;
		for (int i = 2; i < diap; i++) {//якщо число ділиться націло хоч на якесь число менше за нього, воно не може бути простим
			if (diap % i == 0) {
				flag = 0;//false
				break;
			} else {
				flag = 1;//true
				
			}
		}
		if (flag == 1) {
			prime[j] = diap;//якщо число просте - вписуємо його у масив
			j++;
		}
	}
	get_prime_num_array(len, PD, KD);
}
