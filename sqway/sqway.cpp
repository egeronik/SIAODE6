#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
    return c > (a > b ? b : a)? a > b ? b : a : c;
}

int main()
{
    int n=10;
    cout << "Write matrix size:";
    cin >> n;
    vector<vector<int>> v;
    int inp;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        tmp.clear();
        for (int j = 0; j < n; ++j) {
            cin >> inp;
            tmp.push_back(inp);
        }
        v.push_back(tmp);
    }
    //Проход по самой нижней строчке матрицы
    for (int i = n-2; i >= 0; --i) {
        v[n - 1][i] += v[n - 1][i + 1];
    }
    //Проход по правому столбцу
    for (int i = n - 2; i >= 0; --i) {
        v[i][n-1] += v[i + 1][n - 1];
    }
    
    //Проход по оставшейся матрице
    
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            v[i][j] += min(v[i][j + 1], v[i + 1][j], v[i + 1][j + 1]);
        }
    }
    /*Debug output
    for (auto& i : v) {
        for (auto& j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }*/
    cout << v[0][0];

}

