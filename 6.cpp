#include <iostream>
#include <vector>
#include <algorithm> // Обязательный заголовок для функций работы с перестановками

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Создаем маску для генерации сочетаний. 
    // Заполняем первые k позиций единицами (элементы выбраны), остальные — нулями.
    vector<int> mask(n, 0);
    for (int i = 0; i < k; i++) {
        mask[i] = 1;
    }

    int max_xor = 0; // Переменная для хранения максимального значения XOR

    // Цикл do-while перебирает все уникальные сочетания элементов
    do {
        int current_xor = 0;
        // Вычисляем XOR-сумму элементов, попавших под маску
        for (int i = 0; i < n; i++) {
            if (mask[i] == 1) {
                current_xor ^= a[i]; // Операция побитового исключающего ИЛИ
            }
        }
        // Обновляем глобальный максимум
        max_xor = max(max_xor, current_xor);
        
    // Функция prev_permutation генерирует следующую по величине маску.
    // Так как мы начали с [1,1,..,0,0], мы движемся в сторону убывания до [0,0,..,1,1]
    } while (prev_permutation(mask.begin(), mask.end()));

    cout << max_xor << "\n";
    return 0;
}
