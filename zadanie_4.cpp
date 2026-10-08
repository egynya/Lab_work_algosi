#include <bits/stdc++.h>
using namespace std;

uint32_t cur = 0; // беззнаковое 32-битное число

// Генератор 24-битного числа
uint32_t nextRand24(uint32_t a, uint32_t b)
{
    cur = cur * a + b; // вычисляется с переполнениями по модулю 2^32
    return cur >> 8;   // число от 0 до 2^24 - 1
}

// Генератор 32-битного числа на основе двух 24-битных
uint32_t nextRand32(uint32_t a, uint32_t b)
{
    uint32_t x = nextRand24(a, b);
    uint32_t y = nextRand24(a, b);
    return (x << 8) ^ y; // число от 0 до 2^32 - 1
}
void swap(uint32_t &a, uint32_t &b)
{
    uint32_t c = a;
    a = b;
    b = c;
}

uint32_t quickselect(vector<uint32_t> &a, int k, int l, int r)
{
    if (l >= r)
    {
        return a[l];
    }
    int i = l, j = r;
    int p = l + rand() % (r - l + 1);
    uint32_t mid = a[p];
    while (i <= j)
    {
        while (a[i] < mid)
        {
            i++;
        }
        while (a[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (k <= j)
    {
        return quickselect(a, k, l, j);
    }
    else if (k >= i)
    {
        return quickselect(a, k, i, r);
    }
    else
    {
        return a[k];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n, a, b;
    long long sum = 0;
    cin >> n >> a >> b;

    vector<uint32_t> arr(n);

    for (uint32_t i = 0; i < n; i++)
    {
        arr[i] = nextRand32(a, b); // генерируем i-й элемент
    }
    uint32_t mediana = quickselect(arr, n / 2, 0, n - 1);
    for (uint32_t i = 0; i < n; i++)
    {
        sum += (llabs((long long)arr[i] - (long long)mediana));
    }
    cout << sum;
}