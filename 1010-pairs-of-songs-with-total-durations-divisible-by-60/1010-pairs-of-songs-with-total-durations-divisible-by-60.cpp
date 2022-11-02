class Solution {
public:
int numPairsDivisibleBy60(vector<int>& time) 
{
    int d=60;
    int res=0, n=time.size();
    int freq[d];
    for(int i=0; i<d; i++)
        freq[i]=0;
    for(int i=0; i<n; i++)
        freq[time[i]%d]++;
    for(int i=0; i<=d/2; i++) 
    {
        if(i==0 || i==d/2)
            res+=(((long long)freq[i])*(freq[i]-1))/2;
        else
            res+=(freq[i]*freq[d-i]);
    }
    return res;
}

};