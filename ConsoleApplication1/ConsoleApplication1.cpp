#include "pch.h"
#include "formuls.h"
#include <iostream>

using namespace std;

Kvartal kv1, kv2, kv3, kv4;
float fng, pg1, pg2, f9, fAll, amort;

int menu();

int main()
{
	setlocale(LC_ALL, "ru");
	fng=inputFNG();
	for (int kv = 1; kv < 5; kv++) {
		cout << "  Вводимые и выбывшие за " << kv << " квартал: ";
		switch (kv) {
		case 1: cin >> kv1.income >> kv1.outcome; break;
		case 2: cin >> kv2.income >> kv2.outcome; break;
		case 3: cin >> kv3.income >> kv3.outcome; break;
		case 4: cin >> kv4.income >> kv4.outcome; break;
		default: cout << "Какой-то косяк"; return 0;
		}
	}
	cout << "  Норма амортизации (если нет, ввести 0): ";
	cin >> amort;
	// расчет фондов на начало кварталов
	kv2.yearStart = findNKv(fng, 0, kv1.income, kv1.outcome, 2);
	kv3.yearStart = findNKv(fng, kv2.yearStart, kv2.income, kv2.outcome, 3);
	kv4.yearStart = findNKv(fng, kv3.yearStart, kv3.income, kv3.outcome, 4);
	// расчет фондов на год (передается так: фнг, фнкв, фвв, фвыб, номер квартала)
	kv1.all = findKvAll(fng, 0, kv1.income, kv1.outcome, 1);
	kv2.all = findKvAll(fng, kv2.yearStart, kv2.income, kv2.outcome, 2);
	kv3.all = findKvAll(fng, kv3.yearStart, kv3.income, kv3.outcome, 3);
	kv4.all = findKvAll(fng, kv4.yearStart, kv4.income, kv4.outcome, 4);
	//подробное решение 
	//showNKv(фнг или фнкв, фвв, фвыб, ответ, номер квартала), showKv аналогично
	int choice = menu();

}

int menu() {
	int choice, subchoice;
	cout << "  1. Показать решение (полное)\n  2. Показать решение для всех Фнкв\n  3. Показать решение для всех Фкв\n";
	cin >> choice;
	switch (choice)
	{
	case 1: showKv(fng, kv1.income, kv1.outcome, kv1.all, 1);
		showNKv(fng, kv2.income, kv2.outcome, kv2.yearStart, 2);
		showKv(kv2.yearStart, kv2.income, kv2.outcome, kv2.all, 2);
		showNKv(kv2.yearStart, kv2.income, kv2.outcome, kv3.yearStart, 3);
		showKv(kv3.yearStart, kv3.income, kv3.outcome, kv3.all, 3);
		showNKv(kv3.yearStart, kv3.income, kv3.outcome, kv4.yearStart, 4);
		showKv(kv4.yearStart, kv4.income, kv4.outcome, kv4.all, 4);
		cout << "  Фг=Ф1кв+Ф2кв+Ф3кв+Ф4кв=";
		cout << kv1.all << "+" << kv2.all << "+" << kv3.all << "+" << kv4.all << "=" << (kv1.all + kv2.all + kv3.all + kv4.all) / 4 << endl;
		choice = menu();
		break;
	case 2: showNKv(fng, kv2.income, kv2.outcome, kv2.yearStart, 2);
		showNKv(kv2.yearStart, kv2.income, kv2.outcome, kv3.yearStart, 3);
		showNKv(kv3.yearStart, kv3.income, kv3.outcome, kv4.yearStart, 4);
		choice = menu();
		break;
	case 3: showKv(fng, kv1.income, kv1.outcome, kv1.all, 1);
		showKv(kv2.yearStart, kv2.income, kv2.outcome, kv2.all, 2);
		showKv(kv3.yearStart, kv3.income, kv3.outcome, kv3.all, 3);
		showKv(kv4.yearStart, kv4.income, kv4.outcome, kv4.all, 4);
		choice = menu();
		break;
	}
	return choice;
}