#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int c[101] = {0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i <n; i++){
        int pos  = 0;
        for (int j = 0; j<=a[i];j++){
            pos+=c[j];
        }
        std::cout<< pos<< " ";
        c[a[i]]+=1;
    }
}