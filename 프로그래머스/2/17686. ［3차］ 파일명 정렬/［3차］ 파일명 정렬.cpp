#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int n;

void splitFileName(vector<string>& v);
bool compare(const vector<string>& a, const vector<string>& b);

vector<string> solution(vector<string> files) 
{
    n = files.size();
    Dim2Vec<string> v(n, vector<string>(3, ""));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < files[i].size(); ++j)
        {
            char cur = files[i][j];
        }
        v[i][0] = files[i];
        splitFileName(v[i]);
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; ++i)
    {
        files[i] = v[i][0];
    }
    return files;
}

void splitFileName(vector<string>& v)
{
    string origin = v[0];
    int idx = 0;
    while (!('0' <= origin[idx] && origin[idx] <= '9'))
    {
        v[1] += origin[idx];
        idx++;
    }
    bool numStart = false;
    while (idx < origin.length() && '0' <= origin[idx] && origin[idx] <= '9')
    {
        if (origin[idx] == '0')
        {
            if (v[2].length() == 0 || numStart)
            {
                v[2] += origin[idx];
            }
        }
        else
        {
            if (!numStart && 0 < v[2].length())
            {
                v[2] = origin[idx];
            }
            else
            {
                v[2] += origin[idx];
            }
            numStart = true;
        }
        idx++;
    }
}

bool compare(const vector<string>& a, const vector<string>& b)
{
    string headA = a[1];
    string headB = b[1];
    for (int i = 0; i < headA.length(); ++i)
    {
        if ('a' <= headA[i] && headA[i] <= 'z')
        {
            headA[i] -= 32;
        }
    }
    for (int i = 0; i < headB.length(); ++i)
    {
        if ('a' <= headB[i] && headB[i] <= 'z')
        {
            headB[i] -= 32;
        }
    }
    
    if (headA != headB)
    {
        return headA < headB;
    }
    if (a[2] != b[2])
    {
        return stoi(a[2]) < stoi(b[2]);
    }
    return false;
}