#include <bits/stdc++.h>

long long inversions = 0;

const int MAXN = 1'000'000; // максимум n по условию
uint32_t arr[MAXN];

uint32_t cur = 0; // текущее значение генератора

// Генератор 24-битных чисел по условию задачи
uint32_t nextRand24(uint32_t a, uint32_t b)
{
    // 32-битные переполнения (uint32_t автоматически усекает до 2^32)
    cur = cur * a + b;
    return cur >> 8; // берём старшие 24 бита (сдвиг вправо на 8)
}

void merge(uint32_t a[], int l, int mid, int r)
{
    int it1 = 0, it2 = 0;
    std::vector<int> result(r - l);
    while ((l + it1 < mid) && (mid + it2 < r))
    {
        if (a[l + it1] <= a[mid + it2])
        {
            result[it1 + it2] = a[l + it1];
            it1++;
        }
        else
        {
            result[it1 + it2] = a[mid + it2];
            inversions = inversions + (mid - (l + it1));
            it2++;
        }
    }
    while (l + it1 < mid)
    {
        result[it1 + it2] = a[l + it1];
        it1++;
    }
    while (mid + it2 < r)
    {
        result[it1 + it2] = a[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++)
    {
        a[l + i] = result[i];
    }
}

void mergeSort(uint32_t a[], int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid, r);
    merge(a, l, mid, r);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, m, a, b;
    std::cin >> n >> m >> a >> b;

    // Генерируем n элементов
    for (uint32_t i = 0; i < n; i++)
    {
        uint32_t x = nextRand24(a, b) % m; // получаем 24-битное значение по модулю m
        arr[i] = x;                        // записываем в массив
    }
    mergeSort(arr, 0, n);
    std::cout << inversions;
    // Далее используйте arr[0..n-1] для подсчёта инверсий
}