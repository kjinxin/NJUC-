#include<isotream>
using namespace std;

struct node
{
    int x,y;
}

node g[30]
int main()
{
    int n;
    cin>>n;
    while (n!=-1)
    {
        for (int i=0; i<n; i++)
        {
            cin>>g[i].x>>g[i].y;
        }
        for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        for (int k=0; k<n; k++)
        for (int l=0; l<n; l++)
        {
            if (i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
            {
                if ()
            }
        }
        int ans=0;
        cout<<ans<<endl;
    }
}
