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
	cout << "  ������� ���: ";
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
	case 2: cout << "  ��2��=���+���1��-����1��=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	case 3: cout << "  ��3��=��2��+���2��-����2��=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	case 4: cout << "  ��4��=��3��+���3��-����3��=" << fng << "+" << income << "-" << outcome << "=" << answer << endl; break;
	}
}

void showKv(float nkv, float income, float outcome, float answer, int kv) {
	switch (kv) {
	case 1: cout << "  �1��=���+(���1��-����1��)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 2: cout << "  �2��=��2��+(���2��-����2��)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 3: cout << "  �3��=��3��+(���3��-����3��)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	case 4: cout << "  �4��=��4��+(���4��-����4��)/2=" << nkv << "+(" << income << "-" << outcome << ")/2=" << answer << endl; break;
	}
}
