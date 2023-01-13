#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string str;
	cin >> str;

	double sum = 0,k = str.size();
	double sum_c = 0, k_c = 0;
	int ks = 1;

	for (int i = 0; i < str.size(); i++) {
		int ts = str[i] - 48;
		sum += ts;
		if (ks % 7 == 0) {
			k_c++;
			sum_c += ts;
		}
		ks++;
	}

	double m_avr = round(sum/k);
	double c_avr = round(sum_c / k_c);

	while (m_avr > c_avr) m_avr--;
	cout << m_avr << endl;

	return 0;
}