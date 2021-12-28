class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        double smalli = min(bx2,ax2);
        double lagi = max(ax1,bx1);
        double len = abs(smalli - lagi);
        double smalli1 = max(ay1,by1);
        double lagi1 = min(ay2,by2);
        double len2 = abs(smalli1 - lagi1);
        double area3 = len * len2;
        double x1 = abs(ax2 - ax1);
        double y1 = abs(ay2 - ay1);
        double area1 = x1*y1;
        double x2 = abs(bx2 - bx1);
        double y2 = abs(by2 - by1);
        double area2 = x2*y2;
        double total = area1+area2 - area3;
        if(ax2 <= bx1 || ax1 >= bx2)
            return area1 + area2;
        if(ay1 >= by2 || ay2 <= by1)
            return area1 + area2;
        else
        return total;
    }
};