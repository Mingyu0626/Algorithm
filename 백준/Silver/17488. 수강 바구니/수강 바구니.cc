#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
struct subject
{
    int limit;
    vector<int> basket;
};
vector<subject> subjectArray;
vector<set<int, less<int>>> enroll;

void enrollCourseBasket();
void applyCourseBasketResult();
void printCourseBasketResult();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    subjectArray.assign(m + 1, {}), enroll.assign(n + 1, set<int, less<int>>());
    for (int i = 1; i <= m; i++) cin >> subjectArray[i].limit;
    
    for (int i = 0; i < 2; i++)
    {
        enrollCourseBasket();
        applyCourseBasketResult();
    }
    printCourseBasketResult();
    return 0;
}

void enrollCourseBasket()
{
    for (int studentNum = 1; studentNum <= n; studentNum++)
    {
        int curSubject;
        while (cin >> curSubject && curSubject != -1)
        {
            subjectArray[curSubject].basket.emplace_back(studentNum);
        }
    }
}

void applyCourseBasketResult()
{
    for (int subjectNum = 1; subjectNum <= m; subjectNum++)
    {
        if (subjectArray[subjectNum].basket.size() <= subjectArray[subjectNum].limit)
        {
            for (auto& studentNum : subjectArray[subjectNum].basket)
            {
                enroll[studentNum].insert(subjectNum);
            }
        }
    }
}

void printCourseBasketResult()
{
    for (int i = 1; i <= n; i++)
    {
        if (enroll[i].size() == 0)
        {
            cout << "망했어요\n";
        }
        else
        {
            for (auto& studentNumber : enroll[i]) cout << studentNumber << ' ';
            cout << '\n';
        }
    }
}