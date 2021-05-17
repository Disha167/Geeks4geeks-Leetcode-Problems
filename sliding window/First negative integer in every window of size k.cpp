//If we calculate every window of size k for negative number then it can be solved in O(n*k) , by considering all n-k+1 windows , traversing it and finding negative in it.
//But, we cna optimise it further. As, we can see that we are doing repetitive work like in first window in below example 12 -1 -7, we have already checked -1 and -7 for
//negative no so we don't need ot check it again in 2nd window -1 -7 8 again. So, we maintain a queue for storing the first negatives and move the window one step forward at 
//a time. If the element that we remove is negative, we also pop it from the queue and if the new element added is negative, it is pushed in the queue.
//Basically, queue will contain all the negative numbers of the current window always and for the first negative element, we can simply access the front of the queue.
/*
n=8
{12, -1, -7, 8, -15, 30, 16, 28}
k=3
s=0 e=0 q 
s=0 e=1 q {-1}
s=0 e=2 q{-1 -7} ans{-1}
s=1 e=3 q{-1 -7} ans{-1 -1}
s=2 e=4 q{-7 -15} ans{-1 -1 -7}
s=3 e=5 q{ -15} ans{-1 -1 -7 -15}
s=4 e=6 q{-15} ans{-1 -1 -7 -15 -15}
s=4 e=6 q{} ans{-1 -1 -7 -15 -15}
s=5 e=8 ans{-1 -1 -7 -15 -15 0}
*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long>ans;
        long long int start=0,end=0;
        queue<long long int>q; //for storing the negtive nos.
        while(end<N)
        {
            if(A[end]<0)
              q.push(A[end]);
            if((end-start+1)<K)
              end++;
            else if((end-start+1)==K)
            {
                if(!q.empty()) //this condition is important to check to avoid error in queue
                   ans.push_back(q.front());
                else
                   ans.push_back(0);
                if(A[start]<0)
                    q.pop();
                end++;
                start++;
            }
        }
        return ans;
 }
