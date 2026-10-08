#include <iostream>
#include <vector>
#include <climits>

struct Track
{
    int x, y, id;
};

void merge(std::vector<Track> &a, int l, int mid, int r)
{
    int it1 = 0, it2 = 0;
    std::vector<Track> result(r - l);
    while ((l + it1 < mid) && (mid + it2 < r))
    {
        if ((a[l + it1].x > a[mid + it2].x) || ((a[l + it1].x == a[mid + it2].x) && (a[l + it1].y >= a[mid + it2].y)))
        {
            result[it1 + it2] = a[l + it1];
            it1++;
        }
        else
        {
            result[it1 + it2] = a[mid + it2];
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

void mergeSort(std::vector<Track> &a, int l, int r)
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
    int n, max_y = INT_MIN, count = 0;

    std::cin >> n;

    std::vector<Track> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i].y > max_y)
        {
            b[count] = a[i].id;
            max_y = a[i].y;
            count += 1;
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << b[i] << " ";
    }
}