#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, team, leadTeam, minutes, seconds;
string minAndSec, result[2];
int score[2];
pair<int, int> leadTime[2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    int newMinutes, newSeconds, termMinutes, termSeconds;
    for (int i = 0; i < n; i++)
    {
        cin >> team >> minAndSec;
        score[team - 1]++;
        newMinutes = stoi(minAndSec.substr(0, 2));
		newSeconds = stoi(minAndSec.substr(3, 2));
        termMinutes = newMinutes - minutes;
        termSeconds = newSeconds - seconds;
        minutes = newMinutes, seconds = newSeconds;
        if (termSeconds < 0)
        {
            termSeconds += 60;
            termMinutes--;
        }

        if (leadTeam != 0)
        {
            leadTime[leadTeam - 1].first += termMinutes;
            leadTime[leadTeam - 1].second += termSeconds;
        }

        if (score[0] < score[1])
        {
            leadTeam = 2;
        }
        else if (score[0] == score[1])
        {
			leadTeam = 0;
		}
        else
        {
            leadTeam = 1;
        }
    }

    termMinutes = 48 - minutes, termSeconds = 0 - seconds;
    if (termSeconds < 0)
    {
        termSeconds += 60;
        termMinutes--;
    }
    if (leadTeam != 0)
    {
        leadTime[leadTeam - 1].first += termMinutes;
        leadTime[leadTeam - 1].second += termSeconds;
    }

    for (int i = 0; i < 2; i++)
    {
        if (0 < leadTime[i].second / 60)
        {
            int changeMin = leadTime[i].second / 60;
            leadTime[i].first += changeMin;
            leadTime[i].second -= changeMin * 60;
        }

        if (leadTime[i].first < 10) cout << '0';
        cout << leadTime[i].first << ':';

        if (leadTime[i].second < 10) cout << '0';
        cout << leadTime[i].second << '\n';
    }
    return 0;
}