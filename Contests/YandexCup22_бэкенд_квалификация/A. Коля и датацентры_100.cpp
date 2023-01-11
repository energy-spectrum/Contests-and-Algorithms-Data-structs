﻿#include <iostream>

#include <vector>
#include <deque>

#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <cmath>

#include <string>

using namespace std;

struct V {
public:
	int numerDC;
	long long ra;
};

struct opMax {
	bool operator()(const V& el1, const V& el2) const {
		if (el1.ra < el2.ra) {
			return true;
		}

		if (el1.ra == el2.ra) {
			return el1.numerDC > el2.numerDC;
		}

		return false;
	}
};

struct opMin {
	bool operator()(const V& el1, const V& el2) const {
		if (el1.ra < el2.ra) {
			return true;
		}

		if (el1.ra == el2.ra) {
			return el1.numerDC < el2.numerDC;
		}

		return false;
	}
};

int main()
{
	int n, m, q;
	cin >> n >> m >> q;

	vector<unordered_set<int>> dataCenters = vector<unordered_set<int>>(n, unordered_set<int>{});
	vector<vector<long long>> infoDC(n, { 0, m });

	multiset<V, opMax> RAMax;
	multiset<V, opMin> RAMin;

	for (int i = 0; i < n; i++) {
		RAMax.insert({ i, 0 });
		RAMin.insert({ i, 0 });
	}
	vector<long long> res;

	for (int k = 0; k < q; k++) {
		string req;
		cin >> req;
		
		if (req == "RESET") {
			int i;
			cin >> i;
			i -= 1;

			dataCenters[i].clear();

			long long ra = infoDC[i][0] * infoDC[i][1];
			V v = { i, ra };
			auto it = RAMin.find(v);
			RAMin.erase(it);

			it = RAMax.find(v);
			RAMax.erase(it);

			infoDC[i][0] += 1;
			infoDC[i][1] = m;

			v.ra = infoDC[i][0] * infoDC[i][1];
			RAMin.insert(v);
			RAMax.insert(v);
		}
		else if (req == "DISABLE") {
			int i, j;
			cin >> i >> j;
			i -= 1;
			j -= 1;

			if (dataCenters[i].find(j) == dataCenters[i].end()) {
				dataCenters[i].insert(j);

				long long ra = infoDC[i][0] * infoDC[i][1];
				V v = { i, ra };
				auto it = RAMin.find(v);
				RAMin.erase(it);

				it = RAMax.find(v);
				RAMax.erase(it);

				infoDC[i][1] -= 1;

				v.ra = infoDC[i][0] * infoDC[i][1];
				RAMin.insert(v);
				RAMax.insert(v);
			}
		}
		else if (req == "GETMAX") {
			auto it = RAMax.end();
			it--;
			res.push_back((*it).numerDC +1);
		}
		else { //req == "GETMIN"
			auto it = RAMin.begin();
			res.push_back((*it).numerDC +1);
		}
	}

	for (auto r : res) {
		cout << r << '\n';
	}

	return 0;
}
