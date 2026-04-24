class Solution {
public:
    bool judgeCircle(string moves) {
        int dx = 0, dy = 0;
        for (int i = 0; i < moves.length(); ++i) {
            switch (moves[i])
            {
                case 'R':
                    dx++;
                    break;
                case 'L':
                    dx--;
                    break;
                case 'U':
                    dy++;
                    break;
                case 'D':
                    dy--;
                    break;
            }
        }
        return dx == 0 && dy == 0;
    }
};