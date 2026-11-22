class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int count = 0;

        for(int i= 0; i<n;i++)
        {
            if(visited[i] == 0) {
                count++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()) {
                    int city = q.front();
                    q.pop();

                    for(int j=0;j<n;j++) {
                        if (isConnected[city][j] == 1 && visited[j] == 0) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return count; 
    }
};