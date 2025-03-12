
#include <iostream>
using namespace std;
int maximum(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int knapSack(int W, int w[], int p[], int n)
{
    int K[W+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int wt=0;wt<=W;wt++)
        {
            if(i==0 || wt==0)
            {
                K[i][wt]=0;
            }
            else if(p[i-1]<=wt)
            {
                K[i][wt] = max(p[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);

            }
            else
            {
                K[i][wt] = K[i - 1][wt];

            }
        }
    }
    return K[n][W];
}
int main() {
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n;
   int p[n], w[n];
   for (int i = 1; i <= n; i++) {
      cout << "Enter value and weight for item " << i << ":";
      cin >> p[i];
      cin >> w[i];
   }
    cout << "Enter the capacity of knapsack";
   cin >> W;
   cout << knapSack(W, w, p, n);
   return 0;
}
