#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct proccess
{
    int bt,ct,wt,btt;
    string pro_id;
    //bt->burst time
    //ct->compete time
    //wt->waiting time
    //btt->copy of bt

}Schedule;


int main()
{
    Schedule pro[10];
    //An array of Processes
    int n,i,j,pcom,q;
    //n = number of processes, i= iteration variable,pcom=number of complete program,q=quantum time

    cout<<"the number of Process: ";
    cin>>n;

    cout<<"quantum time: ";
    cin>>q;

    cout<<"Process and burst time : ";

    for(i=0;i<n;i++)
    {
        cin>>pro[i].pro_id;
        cin>>pro[i].bt;
        pro[i].btt=pro[i].bt;
    }

    int ctime=0;//ctime=current time
    pcom=0;
    while(pcom<n)
    {
        for(j=0;j<n;j++)
        {
            if(pro[j].bt>q){
                pro[j].bt-=q;
                ctime+=q;
            }
            else if(pro[j].bt>0){

                ctime+=pro[j].bt;
                pro[j].ct=ctime;
                pcom=pcom+1;
                pro[j].bt=0;
            }
        }
    }
     double AverageWaiting=0;
    cout<<"Pro\t\tBurst time\tWaiting time\tTotal time\n";

    for(i=0;i<n;i++)
    {

        pro[i].wt=pro[i].ct-pro[i].btt;
        AverageWaiting+=pro[i].wt;

        cout<<pro[i].pro_id<<"\t\t"<<pro[i].btt<<"\t\t"<<pro[i].wt<<"\t\t"<<pro[i].ct<<endl;

    }
    cout<<"Average waiting time :"<<AverageWaiting/n<<endl;

    return 0;
}
