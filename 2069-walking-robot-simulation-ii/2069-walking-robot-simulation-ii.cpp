class Robot {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int w, h, curDir = 0, curX = 0, curY = 0;

public:
    Robot(int width, int height) {
        w = width, h = height;
    }
    
    void step(int num) {
        num %= 2 * (w + h - 2);
        if (curX == 0 && curY == 0 && num == 0) {
            curDir = 3;
        }
        while (0 < num--) {
            int newX = curX + dx[curDir], newY = curY + dy[curDir];
            if (newX < 0 || w <= newX || newY < 0 || h <= newY) {
                curDir = (curDir + 1) % 4; 
                newX = curX + dx[curDir], newY = curY + dy[curDir];
            }
            curX = newX, curY = newY;
        }
    }
    
    vector<int> getPos() {
        return vector<int>{curX, curY};
    }
    
    string getDir() {
        switch (curDir)
        {
            case 0:
                return "East";
                break;
            case 1:
                return "North";
                break;
            case 2:
                return "West";
                break;
            case 3:
                return "South";
                break;
        }
        return {};
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */