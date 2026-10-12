#include<bits/stdc++.h>

using namespace std;

class DSU{
    public:
        vector<int> data{};
        int length=0;

        DSU(int x){
            length = x;
            data.assign(length,-1);
        }

        ~DSU(){}

        int find(int x){
            if ( data[x]<0 ) return x;
            return data[x] = find(data[x]);
        }

        void unite(int x,int y){
            if (isConnected(x,y)) return;

            int root_x = find(x), root_y = find(y);
            if ( size(root_x) < size(root_y) ) return unite(root_y,root_x);

            data[root_x] += data[root_y];
            data[root_y] = root_x;
        }

        bool isConnected(int x,int y){
            return find(x)==find(y);
        }

        int size(int x){
            return (-1) * data[find(x)];
        }

        int count(){
            int cnt = 0;
            for (int i=0;i<length;i++){
                if ( data[i]<0 ) cnt++;
            }
            return cnt;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // vector<vector<char>> grid = {
    //     {1}
    // };
    
    int N = grid.size() , M = grid[0].size();
    DSU d( N*M );
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    int cut = 0;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){

            if ( grid[i][j]=='0' ) {
                cut++;
                continue;
            }

            for (int t=0;t<4;t++){
                int nx = i + dx[t];
                int ny = j + dy[t];
                if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
                else {
                    if (grid[i][j]==grid[nx][ny]){
                        d.unite(nx*M+ny,i*M+j);
                    } 
                }
            }
        }
    }
    cout << d.count() << endl;
    cout << (d.count() - cut) << "\n";

    return 0;
}