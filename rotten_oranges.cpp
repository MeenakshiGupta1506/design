using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--){
        int r,c; 
        cin>>r>>c;
        vector<vector<int>> grid(r,vector<int>(c));
        for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
        cin>>grid[i][j];
        int s = 0;
        bool are2 = 0;
        for(int X=r+c+1;X--;){
            int cnt = 0;
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    if(grid[i][j]==2){
                            are2 = 1;
                            if(i>0&&grid[i-1][j]==1)
                            {
                                ++cnt;
                                grid[i-1][j]=3;
                            }
                            if(j>0&&grid[i][j-1]==1)
                            {
                                ++cnt;
                                grid[i][j-1]=3;
                            }
                            if(i<r-1&&grid[i+1][j]==1)
                            {
                                ++cnt;
                                grid[i+1][j]=3;
                            }
                            if(j<c-1&&grid[i][j+1]==1)
                            {
                                ++cnt;
                                grid[i][j+1]=3;
                            }
                    }
                }
            }
            for(int i=0;i<r;++i)
                for(int j=0;j<c;++j)
                    if(grid[i][j]==3)
                            grid[i][j] = 2;
            if(cnt==0)
            break;
            ++s;
        }
        for(int i=0;i<r;++i)
                for(int j=0;j<c;++j)
                    if(grid[i][j]==1)
                            s = -1;
        if(s==0 && are2==0)
        cout<<-1<<endl;
        else cout<<s<<endl;

    }
}