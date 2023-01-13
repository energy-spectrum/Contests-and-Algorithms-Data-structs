//28 ноября 2020
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

const int MAX_N = 1000*1000*1000 + 10;

set<int> square, triangle;
int main(){
    int n; cin >> n;

    int sqrt_N = sqrt(MAX_N);

    triangle.insert(1);
    square.insert(1);
    int last_treangle = 1;
    int r = 2;
    bool flag = true;
    while(flag){
        flag = false;
       
        last_treangle += r;
        triangle.insert(last_treangle);
        
        if(r < sqrt_N){
            square.insert(r * r);
            flag = true;
        }
        r++;
    }
    auto it_square = square.end();
    auto it_triangle = triangle.end();
    it_square--;
    while (it_triangle == triangle.end()){
        if(*it_square <= n)
            it_triangle = triangle.find(*it_square);
        it_square--;
    }
    cout << *it_triangle;
    return 0;
}

