using namespace std;
int main()
{
    int t;
     int *arr=new int[10000000];
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        deque<int>dq;
        int j=0,i=0;
        while(j<=n)
        {
            if(!dq.empty()&&j>=k)
                cout<<arr[dq.front()]<<" ";
            while(!dq.empty()&&arr[dq.back()]<=arr[j])
            //always maintaining the largest element of window in front
            {
                dq.pop_back();
                i++;
            }
            dq.push_back(j);
            while(!dq.empty()&&(dq.back()-dq.front())>=k)
            //😢😢refrain from using i and j instead of dq.front()
            //and dq.back()
            {
                dq.pop_front();
            }
            j++;
        }
        cout<<"\n";
    }
    return 0;
}
