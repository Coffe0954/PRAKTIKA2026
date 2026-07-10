#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0; //проверка успешности чтения

    // dp[j] хранит количество уникальных способов собрать сумму длин j
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // База динамики: сумму 0 можно собрать единственным пустым способом

    // Внешний цикл: перебираем размер нового куска доски
    for (int i = 1; i <= n; ++i) {
        // Внутренний цикл: обход справа налево гарантирует, 
        // что кусок размера i будет взят не более одного раза
        for (int j = n; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD; // Пересчет состояний
        }
    }

    cout << dp[n] << "\n"; // Вывод ответа для исходной длины n

    return 0;
}
