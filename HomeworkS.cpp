#include <iostream>
#include <Windows.h>
using namespace std;
void noDamageDealt(int arr[]);
void maxDamageDealt(int arr[]);
void minDamageDealt(int arr[]);
void healingDealt(int arr[]);
void allDamageAndHealthDealt(int arr[]);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int DamageArray[5] = { -2, 5, 2, 0, -7, };
	noDamageDealt(DamageArray);
	maxDamageDealt(DamageArray);
	minDamageDealt(DamageArray);
	healingDealt(DamageArray);
	allDamageAndHealthDealt(DamageArray);
}
void noDamageDealt(int arr[]) {
	for (int i = 0; i < 5; i++) {
		//cout << "Hit " << arr[i] << endl;
		if (arr[i] == 0)
		{
			cout << "No Damage Dealt when " << i << " acted" << endl;
		}

	}
}
void maxDamageDealt(int arr[]) {
	int max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << "Max Damage Dealt Was: " << max << endl;
}
void minDamageDealt(int arr[]) {
	int i = 0;
	int min = 0;
	for (; i < 5; i++)
	{

		if (arr[i] > 0) {
			min = arr[i];

			break;
		}
	}
	for (; i < 5; i++)
	{
		if (arr[i] < min && arr[i] > 0) {
			min = arr[i];
		}

	}if (min == 0) {
		cout << "there was no Damage dealt" << endl;
		return;
	}
	cout << "Min Damage Dealt Was: " << min << endl;
}
void healingDealt(int arr[]) {
	for (int i = 0; i < 5; i++) {
		//cout << "Hit " << arr[i] << endl;
		if (arr[i] < 0)
		{
			cout << "Healing received: " << arr[i] << endl;
		}

	}
}
void allDamageAndHealthDealt(int arr[]) {
	int totalDamage = 0;

	for (int i = 0; i < 5; i++) {
		if (arr[i] > 0) {
			totalDamage += arr[i];

		}

	}
	cout << "Total Damage Dealt Was: " << totalDamage << endl;
	int totalHeal = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] < 0) {
			totalHeal += arr[i];

		}
	}
	cout << "Total Health Received Was: " << totalHeal << endl;
}



/*Написати програму, яка запитує і запам’ятовує числа, які дорівнюють кількості шкоди(або лікуванню, якщо число від’ємне).
	Розробити для цих даних функції статистики :
Під якими номерами нам завдали найбільшу шкоду
	Під якими номерами нам завдали нам найменше шкоди
	Під якими номерами нам завдали лікування
	Скільки всього нам нанесли шкоди / лікування(в параметр функції потрібно передати обраний варіант : лікування, або шкода)
	Чи є хтось, хто нічого нам не зробив(значення дорівнює нулю)*/