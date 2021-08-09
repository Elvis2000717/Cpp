class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int value  = gifts[n / 2];
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(gifts[i] == value)
            {
                count++;
            }
        }
        if(count <= (n / 2))
            return 0;
        return value;
    }
};