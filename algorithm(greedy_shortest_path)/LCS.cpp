#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S = "AGGTAB", T="GXTXAYB";
    int n = S.size() , m = T.size();
    int solution[n+1][m+1];

    memset(solution, 0, sizeof(solution));

    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(S[i]==T[j])
            {
                solution[i][j]=solution[i-1][j-1]+1;
            }
            else
            {
                solution[i][j]=max(solution[i-1][j], solution[i][j-1]);
            }
        }
    }
    cout<<solution[n][m]<<endl;
    return 0;


}
