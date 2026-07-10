#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
// Константа для взятия остатка по модулю, предотвращающая переполнение типов данных
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    cin >> l >> r;

    // dp[i] хранит количество уникальных путей из точки 1 в точку i
    vector<ll> dp(r + 1, 0);
    dp[1] = 1; // Начальное состояние: в точке 1 кузнечик находится изначально

    // Проход по всем состояниям
    for (ll i = 1; i <= r; ++i) {
        // Из точки i кузнечик может прыгнуть в точки 2*i, 3*i, 4*i и т.д.
        for (ll j = 2 * i; j <= r; j += i) {
            dp[j] += dp[i]; // Переносим накопленные пути из точки i в точку j
            dp[j] %= MOD;   // Защита от переполнения (взятие по модулю)
        }
    }

    ll ans = 0;
    // Собираем ответы для всех целевых точек на интервале [l, r]
    for (ll i = l; i <= r; ++i) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}
