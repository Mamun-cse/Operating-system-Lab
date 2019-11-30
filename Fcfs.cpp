
#include<bits/stdc++.h>
using namespace std;
void findWaitingTime(int pro[],int n,int B[]){
    int tn[n],wt[n],i,totalTn=0,totalWt=0;
    tn[0]=0;
    wt[0]=0;

    for(i=1;i<=n;i++){
        tn[i] = tn[i-1]+B[i];
        totalTn = totalTn + tn[i];
    }

    for(i=1;i<=n;i++){
        wt[i] = (tn[i]-B[i]);
        totalWt = totalWt + wt[i];
    }

    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
    for(i=1;i<=n;i++){
        cout<<" "<<pro[i]<<"\t\t"<<B[i]<<"\t\t"
            <<wt[i]<<"\t\t"<<tn[i]<<endl;
         }
    cout<<endl;
    cout << "Average waiting time = "
         << (float)totalWt / (float)n;

    cout << "\nAverage turn around time = "
         << (float)totalTn / (float)n;
}
int main()
{
    int n,i;
    cout<<"Total number of process\n";
    cin>>n;
    int p[n],b[n];
    cout<<"processes "<<"burst time\n";
     for(i=1;i<=n;i++){
        cin>>p[i];
        cin>>b[i];
     }
     findWaitingTime(p,n,b);
}
