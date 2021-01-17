class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
		if(coordinates.size() == 2)
			return true;
		for(int i = 2; i < coordinates.size(); ++i){
#ifndef LCX
#define LCX
#define X1 coordinates[i - 2][0]
#define Y1 coordinates[i - 2][1]
#define X2 coordinates[i - 1][0]
#define Y2 coordinates[i - 1][1]
#define X3 coordinates[i][0]
#define Y3 coordinates[i][1]
#endif
		if((Y2 - Y1) * (X3 - X2) != (Y3 - Y2) * (X2 - X1))
			return false;
		}
		return true;
    }
};
