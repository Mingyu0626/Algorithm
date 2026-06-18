class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHand = 30.0 * hour + 0.5 * minutes;
        double minuteHand = 6 * minutes;
        double diff = abs(hourHand - minuteHand);
        return min(360.0 - diff, diff);
    }
};