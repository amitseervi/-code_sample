#include <iostream>
using namespace std;

int main()
{
    int shop[]={100,200,100,1,1};
    int m = sizeof(shop)/sizeof(shop[0]);
    int k=1900;
    int n=2100;
    int count=0;
    bool happy;
    if(k <= n)
        happy = true; 
    else
        happy = false;
    for(int i=0; i<m; i++)
    {
        if(k<=n)
        {
            k += shop[i];
            cout<<"Bought "<<shop[i]<<" k "<<k<<"\n";
            if(!happy)
            {
                cout<<"Become happy :)\n";
                happy = true;
                count++;
            }
        }
        else
        {
            if(k< shop[i])
                k -= k;
            else
                k -= shop[i];
            cout<<"Sold "<<shop[i]<<" k "<<k<<"\n";
            if(happy)
            {
                cout<<"Become stressed :(\n";
                happy = false;
                count ++;
            }
        }
    }
    cout << "numof mood swings = "<<count <<endl;
    return 0;
}