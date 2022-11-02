class Solution {
public:
int minMutation(string start, string end, vector<string> &bank)
{
    if (start == end)
        return 0;
    int res = 0, n = start.length(), nb = bank.size();
    unordered_set<string> us;
    for (int i = 0; i < nb; i++)
        us.insert(bank[i]);
    queue<string> q;
    q.push(start);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            string cur = q.front();
            q.pop();
            for (auto it = us.begin(); it != us.end();)
            {
                int d = 0;
                for (int j = 0; j < n; j++)
                    if ((*it)[j] != cur[j])
                        d++;
                if(d==1)
                {
                    if((*it)==end)
                        return res+1;
                    q.push(*it);
                    it=us.erase(it);
                }
                else
                    it++;
            }
        }
        res++;
    }
    return -1;
}
};