#include  <iostream>

using std::cout;
using std::cin;
using std::endl;

class Kvartal {
public:
	float income, outcome, yearStart, all;
};

float inputFNG() {
	float fng;
	cout << "  Ââåäèòå ÔÍÃ: ";
	cin >> fng;
	return fng;
}

float findNKv(float fng, float nkv, float income, float outcome, int kv) {
	switch (kv) {
	case 2: return fng + income - outcome; break;
	case 3: return nkv + income - outcome; break;
	case 4: return nkv + income - outcome; break;
	}
	return 0;
}

float findKvAll(float fng, float nkv, float income, float outcome, int kv) {

	switch (kv) {
	case 1: return fng + (income - outcome) / 2.0; break;
	case 2: return nkv + (income - outcome) / 2.0; break;
	case 3: return nkv + (income - outcome) / 2.0; break;
	case 4: return nkv + (income - outcome) / 2.0; break;
	}
	return 0;
}

void showNKv(float fng, float income, float outcome, float answer, int kv) {
	switch (kv) {
	case 2: cout << "  Ôí2êâ=Ôíã+Ôââ1êâ-Ôâûá1êâ=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	case 3: cout << "  Ôí3êâ=Ôí2êâ+Ôââ2êâ-Ôâûá2êâ=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	case 4: cout << "  Ôí4êâ=Ôí3êâ+Ôââ3êâ-Ôâûá3êâ=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	}
}

void showKv(float nkv, float income, float outcome, float answer, int kv) {
	switch (kv) {
	case 1: cout << "  Ô1êâ=Ôíã+(Ôââ1êâ-Ôâûá1êâ)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 2: cout << "  Ô2êâ=Ôí2êâ+(Ôââ2êâ-Ôâûá2êâ)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 3: cout << "  Ô3êâ=Ôí3êâ+(Ôââ3êâ-Ôâûá3êâ)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 4: cout << "  Ô4êâ=Ôí4êâ+(Ôââ4êâ-Ôâûá4êâ)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	}
}
