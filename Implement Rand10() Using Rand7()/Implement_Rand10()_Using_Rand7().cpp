// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution 
{
public:
    int rand10() 
    {
        while (true)
        {
            int bit1 = rand7();
            int bit2 = rand7();

            int res = (bit1 - 1) * 7 + bit2;

            if (1 <= res && res <= 40)
                return res % 10 + 1;
        }
    }
};