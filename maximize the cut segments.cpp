//Problem link:- https://practice.geeksforgeeks.org/problems/cutted-segments/0

//Just add **IMP CONDITION** more in the classical unbounded knapsack


//Unbounded knapsack has just one difference with 01 Knapsack , when
//the element is included, it is not processed, it can be added any no.
//of times more
//This problem also follows the identification rule of knapsack,
//we can either cut the rod in the piece of given size or not and the max.
//length of rod is given
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int length_of_line_segment;
        cin>>length_of_line_segment;
        int len[3],val[length_of_line_segment+1]={0};
        for(int i=0;i<=2;i++)
        {
            cin>>len[i];
            if(len[i]<=length_of_line_segment)
               val[len[i]]=1;
        }
        int t[4][length_of_line_segment+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<=3;i++)
        {
            for(int j=0;j<=length_of_line_segment;j++)
            {
                if(i==0||j==0)
                   t[i][j]=0;
                else if(len[i-1]<=j)
                {
                    //****IMP CONDITION****
                    //condition for checking that jab hum rod ko divide
                    //kar rahe hain toh saare elements uske array me hona
                    //chahiye
                    //agr j-a[i-1] not equal to 0 hua... matlab ki apn
                    //currently jis piece k liye loop chala rahe h uske
                    //bina bhi apni rod valid h (mtlb agar puri rod mai
                    //se apan ne a[i-1] element nikal diya toh jo rod
                    //bachi hai uski length prices array mai honi chahiye
                    //ya fir usko further break kiya ja sakta h !!)
                    if(t[i][j-len[i-1]]!=0||(j==len[i-1]))
                       t[i][j]=max(t[i-1][j],1+t[i][j-len[i-1]]);
                    else
                    //agar t[i-1][j-len[i-1]] equal to 0 hua matlab ki
                    //j-len[i-1]. ko apan valid nahi bol sakte kyunki woh
                    //pieces array mai bhi nahi hoga aur usko pieces array
                    //k elements use karke bhi break nahi kiya ja sakta
                    //(use element ko apan ne pehle hi process kar liye h)
                       t[i][j]=t[i-1][j];
                }

                else
                    t[i][j]=t[i-1][j];
            }
        }
        cout<<t[3][length_of_line_segment]<<endl;

    }
	return 0;
}
