#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

struct RoomInfo
{
    int masterLevel;
    map<string, int> userInfoMap;

    RoomInfo(int masterLevel, int userLevel, string userName)
    {
        this->masterLevel = masterLevel;
        userInfoMap.insert({ userName, userLevel });
    }
};

int p, m, l, roomNumber = 1;
string n;
vector<int> v;
map<int, RoomInfo> roomInfoMap;

bool tryEnterableRoom(int userLevel, string userName);
void makeRoom(int userLevel, string userName);
void print();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> p >> m;
    for (int i = 0; i < p; i++)
    {
        cin >> l >> n;
        if (!tryEnterableRoom(l, n))
        {
            makeRoom(l, n);
        }
    }
    print();
    return 0;
}

bool tryEnterableRoom(int userLevel, string userName)
{
    for (auto& a : roomInfoMap)
    {
        RoomInfo roomInfo = a.second;
        if (roomInfo.masterLevel - 10 <= userLevel &&
            userLevel <= roomInfo.masterLevel + 10 &&
            roomInfo.userInfoMap.size() < m)
        {
            a.second.userInfoMap.insert({ userName, userLevel });
            return true;
        }
    }
    return false;
}

void makeRoom(int userLevel, string userName)
{
    roomInfoMap.insert
    ({ roomNumber, RoomInfo(userLevel, userLevel, userName)});
    roomNumber++;
}

void print()
{
    for (auto& roomInfo : roomInfoMap)
    {
        if (roomInfo.second.userInfoMap.size() == m)
        {
            cout << "Started!\n";
        }
        else
        {
            cout << "Waiting!\n";
        }
        for (auto& userInfo : roomInfo.second.userInfoMap)
        {
            cout << userInfo.second << ' ' << userInfo.first << '\n';
        }
    }
}