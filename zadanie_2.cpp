#include <iostream>
#include <vector>

struct Track
{
    int a, b, id;
};

void merge(std::vector<int> &id, const std::vector<Track> &t, int l, int mid, int r)
{
    int it1 = 0, it2 = 0;
    std::vector<int> result(r - l);
    while ((l + it1 < mid) && (mid + it2 < r))
    {
        int x = id[l + it1];
        int y = id[mid + it2];
        if ((t[x].a < t[y].a) || (t[x].a == t[y].a && t[x].b < t[y].b) || (t[x].a == t[y].a && t[x].b == t[y].b && t[x].id < t[y].id))
        {
            result[it1 + it2] = x;
            it1++;
        }
        else
        {
            result[it1 + it2] = y;
            it2++;
        }
    }
    while (l + it1 < mid)
    {
        result[it1 + it2] = id[l + it1];
        it1++;
    }
    while (mid + it2 < r)
    {
        result[it1 + it2] = id[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++)
    {
        id[l + i] = result[i];
    }
}

void mergeSort(std::vector<int> &id, const std::vector<Track> &t, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(id, t, l, mid);
    mergeSort(id, t, mid, r);
    merge(id, t, l, mid, r);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<Track> t(n);
    std::vector<int> id(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> t[i].a >> t[i].b;
        t[i].id = i + 1;
        id[i] = i;
    }
    mergeSort(id, t, 0, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << t[id[i]].id << " ";
    }
}