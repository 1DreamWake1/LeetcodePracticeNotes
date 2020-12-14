class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
		vector<int> v(5, 0);
		for(const auto& x : croakOfFrogs){
			switch(x){
				case 'c':
					if(v[4])
						--v[4];
					++v[0];
					break;
				case 'r':
					if(!v[0])
						return -1;
					--v[0];
					++v[1];
					break;
				case 'o':
					if(!v[1])
						return -1;
					--v[1];
					++v[2];
					break;
				case 'a':
					if(!v[2])
						return -1;
					--v[2];
					++v[3];
					break;
				case 'k':
					if(!v[3])
						return -1;
					--v[3];
					++v[4];
					break;
			}
		}
		return (v[0] | v[1] | v[2] | v[3]) ? -1 : v[4];
    }
};
