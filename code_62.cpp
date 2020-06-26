#include<iostream>
#include<string>
using namespace std;
struct Activity{
    int startTime;
    int endTIme;
    int index;
    int maxConcurrent;
};
int main(){
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n;
        cin>>n;
        Activity activities[n];
        for(int i=0;i<n;i++){
            cin>>activities[i].startTime>>activities[i].endTIme;
            activities[i].index=i;
        }
        bool possible=true;
        string ans="";
        for(int i=0;i<n;i++){
            int overlapping=0;
            for(int j=0;j<n;j++){
                if(activities[i].startTime>= activities[j].startTime && activities[j].endTIme>activities[i].startTime){
                    overlapping++;
                }else if(activities[j].startTime>= activities[i].startTime && activities[i].endTIme>activities[j].startTime){
                    overlapping++;
                }
            }
            if(overlapping==1){
                ans = ans+"C";
            }else if(overlapping==2){
                ans = ans+"J";
            }else{
                possible=false;
                ans = ans+"X";
            }
            cout<<"overlapping "<<overlapping<<"\n";
        }
        if(possible){
            cout<<"Case #"<<test<<":"<<" "<<ans<<"\n";
        }else{
            cout<<"Case #"<<test<<":"<<" "<<"IMPOSSIBLE"<<"\n";
        }
    }
}