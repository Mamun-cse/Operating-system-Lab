#include<iostream>
using namespace std;
void sortp(int p[],int n,int b[]){
    int i,j,pos,temp;
    for(i=1;i<=n;i++){
        pos = i;
        for(j = i+1;j<=n;j++){
            if(b[j]<b[pos])
                pos = j;
        }
        temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
}
void findWaitingTime(int pro[],int n,int B[]){
    int tn[n],wt[n],i,totalTn=0,totalWt=0;
    tn[0]=0;
    wt[0]=0;
    for(i=1;i<=n;i++){
        tn[i] = tn[i-1]+ B[i];
        //c= tn[i];
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

}
int main()
{
     int n,i;
    cout<<"Total number of processes\n";
    cin>>n;
    int p[n],b[n];
    cout<<"processes "<<"burst time\n";
     for(i=1;i<=n;i++){
        cin>>p[i];
        cin>>b[i];
     }
     sortp(p,n,b);
     findWaitingTime(p,n,b);
     return 0;
}
