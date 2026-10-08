#include <iostream>
#include <vector>

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void quicksort(std::vector<int> &a, int l, int r)
{
    int i = l, j = r;
    int p = l + rand() % (r - l + 1);
    int mid = a[p];
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
    if (l < j)
    {
        quicksort(a, l, j);
    }
    if (r > i)
    {
        quicksort(a, i, r);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}