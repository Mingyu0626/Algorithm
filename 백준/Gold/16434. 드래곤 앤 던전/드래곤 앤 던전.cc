#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

struct roomInfo
{
    long long roomType;
    long long damage;
    long long hp;
};

long long n, playerDamage, playerMaxHP, playerCurHP;
roomInfo v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> playerDamage;
    for (int i = 0; i < n; i++)
    {
        cin >> v.roomType >> v.damage >> v.hp;

        if (v.roomType == 1)
        {
            long long numOfPlayerAttack = v.hp / playerDamage;
            numOfPlayerAttack += (v.hp % playerDamage == 0) ? 0 : 1;
            long long receivedDamage = (numOfPlayerAttack - 1) * v.damage;

            if (playerCurHP == 0)
            {
                playerMaxHP = receivedDamage + 1;
                playerCurHP = 1;
            }
            else
            {
                if (playerCurHP > receivedDamage) playerCurHP -= receivedDamage;
                else
                {
                    playerMaxHP += (receivedDamage - playerCurHP) + 1;
                    playerCurHP = 1;
                }
            }
        }
        else
        {
            playerDamage += v.damage;
            playerCurHP = min(playerMaxHP, playerCurHP + v.hp);
        }
    }
    cout << playerMaxHP;
}