#include<bits/stdc++.h>
using namespace std;
void sortp(int p[],int n,int b[],int priority[]){
    int i,j,pos,temp;
    for(i=1;i<=n;i++){
        pos = i;
        for(j = i+1;j<=n;j++){
            if(priority[j]<priority[pos])
                pos = j;
        }
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;

         temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;


    }
   /* for( i= 0;i<n;i++){
        cout<<p[i]<<" "<<b[i]<<" "<<priority[i]<<endl;
    }*/
}
void findWaitingTime(int pro[],int n,int B[]){
    int tn[n],wt[n],i,totalTn=0,totalWt=0,c=0;
    tn[0]=0;
    wt[0]=0;
    for(i=1;i<=n;i++){
        tn[i] = tn[i-1] + B[i];
       // c= tn[i];
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
    int p[n],b[n],priority[n];
    cout<<"processes "<<"burst time "<<"priority\n";
     for(i=1;i<=n;i++){
        cin>>p[i];
        cin>>b[i];
        cin>>priority[i];
     }
     sortp(p,n,b,priority);
     findWaitingTime(p,n,b);
     return 0;
}


   
       
