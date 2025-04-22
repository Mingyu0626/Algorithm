#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct nutrition
{
    int dan, ji, tan, vitamin, price;
};
int n, mp, mf, ms, mv, result = 1e9;
vector<int> resultIngredientNum;
vector<nutrition> v;

void recursion(int idx, nutrition cur, vector<int> ingredientNum);

bool check(nutrition cur);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> mp >> mf >> ms >> mv;
    v.assign(n + 1, {});
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].dan >> v[i].ji 
            >> v[i].tan >> v[i].vitamin 
            >> v[i].price;
    }
    nutrition current = { 0, 0, 0, 0, 0 };
    for (int i = 1; i <= n; i++)
    {
        recursion(i, current, vector<int>());
    }

    if (result == 1e9)
    {
        cout << -1;
        return 0;
    }
    cout << result << '\n';
	for (int i = 0; i < resultIngredientNum.size(); i++)
	{
		cout << resultIngredientNum[i] << ' ';
	}
    return 0;
}

void recursion(int idx, nutrition cur, vector<int> ingredientNum)
{
    cur.dan += v[idx].dan;
    cur.ji += v[idx].ji;
    cur.tan += v[idx].tan;
    cur.vitamin += v[idx].vitamin;
    cur.price += v[idx].price;
	ingredientNum.emplace_back(idx);

    if (check(cur) && cur.price < result)
    {
        result = cur.price;
		resultIngredientNum = ingredientNum;
    }

    for (int i = idx + 1; i <= n; i++)
    {
        recursion(i, cur, ingredientNum);
    }
}

bool check(nutrition cur)
{
    return mp <= cur.dan && mf <= cur.ji && ms <= cur.tan
        && mv <= cur.vitamin;
}