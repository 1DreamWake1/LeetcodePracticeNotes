class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = 0, y = 0;
        if(x_center > x2)
			x = x2;
        else if(x_center < x1)
			x = x1;
        else
			x = x_center;
        if(y_center > y2)
			y = y2;
        else if(y_center < y1)
			y = y1;
        else
			y = y_center;
        return ((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) <= (radius * radius);
    }
};
