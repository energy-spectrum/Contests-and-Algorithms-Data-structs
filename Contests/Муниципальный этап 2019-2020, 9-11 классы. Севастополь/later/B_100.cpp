#include <iostream>
using namespace std;

int main()
{
	int n, m, k, x = 0, c = -1;
	char t;
	const int SIZE = 100000;
	bool ans[SIZE];
	
// Ввод
	cin >> n >> m;
// Код
	for (int i = 0; i < m; i++)
	{
		cin >> t >> k;
		if (t == '1')
			x = k - x;
		else
		{
			c++;
			if (k > x)
				ans[c] = 0;
			else
				ans[c] = 1;			
		}
	}
	for (int i = 0; i <= c; i++)
		cout << ans[i] << endl;
	
	return 0;
}