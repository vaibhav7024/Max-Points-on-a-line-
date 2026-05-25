class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        int n=points.size();
        if(n<=2) return n;
        for(int i=0;i<n;i++){
            unordered_map<string,int> slopescount;
            int duplicates =1;
            int localMax =0;
            for(int j=i+1;j<n;j++){
                int dx = points[j][0]-points[i][0];
                int dy = points[j][1]-points[i][1];

                if(dx==0 && dy==0){
                    duplicates++;
                    continue;
                }
                int g = gcd(dx,dy);
                dx/=g;dy/=g;
                string slope = to_string(dx)+"/"+to_string(dy);
                slopescount[slope]++;
                localMax =  max(localMax,slopescount[slope]);
            }
            res = max(res,localMax+duplicates);
        }
        return res;
    }
    private:
        int gcd(int a,int b){
            return b==0?a:gcd(b,a%b);
        }
};
