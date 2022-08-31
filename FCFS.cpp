#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter process here:";
    cin>>n;
    int avt[n];
    int bst[n];
    cout<<"ENTER AT VALUES"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>avt[i];
    }
     cout<<"Arrival Time "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<avt[i]<<endl;
    }
   
    cout<<"ENTER BT VALUES"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>bst[i];
    }
    cout<<"Burst Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<bst[i]<<endl;
    }
    int wt[n], tat[n],ct[n],rt[n];
    int start_time[n];
    start_time[0]=0;
    wt[0] = 0;
    for (int i = 1; i < n ; i++)
	{
		start_time[i] = start_time[i-1] + bst[i-1];
	}
    for (int i = 0; i < n; i++)
    {
        wt[i] = start_time[i] - avt[i];
		if (wt[i] < 0)
			wt[i] = 0;
    }
    for (int i = 0; i < n ; i++)
		tat[i] = bst[i] + wt[i];
        for (int i = 0; i < n; i++)
    {
        ct[i] = bst[i] + wt[i];
    }
      for (int i = 0; i < n; i++)
    {
        rt[i] = start_time[i] - avt[i];
    }
    cout << "Processes " << " Burst Time " << " Arrival Time "
		<< " Waiting Time " << " Turn-Around Time "
		<< " Completion Time " <<"Response time\n";

    int total_wt = 0, total_tat = 0,total_ct=0,total_rt=0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
        total_ct = total_ct + ct[i];
        total_rt = total_rt + rt[i];
		int compl_time = tat[i] + avt[i];
		cout << " " << i+1 << "\t\t" << bst[i] << "\t\t"
			<< avt[i] << "\t\t" << wt[i] << "\t\t "
			<< tat[i] << "\t\t " << compl_time <<"\t\t" <<rt[i] << endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
    cout << "\nAverage completation = "
		<< (float)total_ct / (float)n;
    cout << "\nAverage response time = "
        << (float)total_rt / (float)n;
	return 0;
}
