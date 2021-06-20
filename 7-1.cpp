#include <bits/stdc++.h>
using namespace std;
typedef struct result
{
    vector<int> data;
    int cmpnum;
    int swapnum;
    result(vector<int> b, int c, int d) : data(b), cmpnum(c), swapnum(d) {}
} re;
void input(vector<int> &a)
{
    string s = "";
    for (char c = getchar();; c = getchar())
    {
        if (c == ' ')
        {
            a.push_back(stoi(s));
            s = "";
            continue;
        }
        if (c == '\n')
        {
            a.push_back(stoi(s));
            break;
        }
        s = s + c;
    }
}
void output(re a)
{
    for (int i = 0; i < a.data.size(); i++)
    {
        cout << a.data[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons:" << a.cmpnum << endl;
    cout << "Number of exchanges:" << a.swapnum << endl;
}
re directInsert(vector<int> a)
{
    vector<int> b(a);
    int cmp = 0, swp = 0;
    for (int i = 1; i < b.size(); i++)
        for (int j = i; j > 0; j--)
            if ((++cmp, true) && b[j] < b[j - 1])
            {
                swap(b[j], b[j - 1]);
                swp++;
            }
    return result(b, cmp, swp);
}
re shellSort(vector<int> a)
{
    vector<int> b(a);
    int j, gap, n = b.size();
    int cmp = 0, swp = 0;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (j = gap; j < n; j++)
            if ((++cmp, true) && b[j] < b[j - gap])
            {
                int temp = b[j];
                int k = j - gap;
                while ((++cmp, true) && k >= 0 && b[k] > temp)
                {
                    b[k + gap] = b[k];
                    k -= gap;
                    swp++;
                }
                b[k + gap] = temp;
                swp++;
            }
    return result(b, cmp, swp);
}
re bubbleSort(vector<int> a)
{
    vector<int> b(a);
    bool flag = true;
    int n = b.size();
    int cmp = 0, swp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if ((++cmp, true) && b[j] < b[j - 1])
            {
                flag = true;
                swap(b[j], b[j - 1]);
                swp++;
            }
        }
        if (!flag)
            return result(b, cmp, swp);
    }
    return result(b, cmp, swp);
}
void qsort(vector<int> &a, int l, int r, int &cmp, int &swp)
{
    if (l < r)
    {
        int key = a[l];
        int i = l + 1, j = r;
        while (true)
        {
            while ((++cmp, true) && i <= j && a[i] <= key)
                i++;
            while ((++cmp, true) && i <= j && a[j] >= key)
                j--;
            if (i > j)
                break;
            (swp++, true) && (swap(a[j], a[i]), true);
        }
        (swp++, true) && (swap(a[l], a[j]), true);
        qsort(a, l, j - 1, cmp, swp);
        qsort(a, j + 1, r, cmp, swp);
    }
}
re quickSort(vector<int> a)
{
    vector<int> b(a);
    int cmp = 0, swp = 0;
    qsort(b, 0, b.size() - 1, cmp, swp);
    return result(b, cmp, swp);
}
re directSelect(vector<int> a)
{
    vector<int> b(a);
    int cmp = 0, swp = 0;
    int n = b.size();
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((++cmp, true) && b[k] > b[j])
                k = j;
        }
        if (k != i)
            (++swp, true) && (swap(b[k], b[i]), true);
    }
    return result(b, cmp, swp);
}
void adjust(vector<int> &a, int n, int root, int &cmp, int &swp)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int max = root;
    if (left < n && a[left] > a[max] && (++cmp, true))
        max = left;
    if (right < n && a[right] > a[max] && (++cmp, true))
        max = right;
    if (max != root)
    {
        swap(a[max], a[root]);
        swp++;
        adjust(a, n, max, cmp, swp);
    }
}
re heapSort(vector<int> a)
{
    vector<int> b(a);
    int n = b.size();
    int cmp = 0, swp = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        adjust(b, n, i, cmp, swp);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        swap(b[0], b[i]);
        swp++;
        adjust(b, i, 0, cmp, swp);
    }
    return result(b, cmp, swp);
}
int main()
{
    vector<int> a;
    input(a);
    cout << "***************************\n";
    cout << "Direct Insert Sort:\n";
    output(directInsert(a));
    cout << "***************************\n";
    cout << "Shell Sort:\n";
    output(shellSort(a));
    cout << "***************************\n";
    cout << "Bubble Sort:\n";
    output(bubbleSort(a));
    cout << "***************************\n";
    cout << "Quick Sort:\n";
    output(quickSort(a));
    cout << "***************************\n";
    cout << "Direct Select Sort:\n";
    output(directSelect(a));
    cout << "***************************\n";
    cout << "Heap Sort:\n";
    output(heapSort(a));
    cout << "***************************\n";
    return 0;
}