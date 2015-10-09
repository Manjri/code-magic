class Solution
{
public:
    
    int strStr(string haystack, string needle)
    {
        // calculate the length of the haystack and the needle
        unsigned int lenHay = haystack.length();
        unsigned int lenNeed = needle.length();
        
        if(lenHay < lenNeed)
            return -1;
        
        // traverse all the possible starting points of haystack
        //(from 0 to haystack.length() - needle.length())
        for(int i=0; i<(lenHay - (lenNeed-1)); i++)
        {
            int j = 0;
            for(; j < lenNeed; j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == lenNeed)
                return i;
        }
        return -1;
    }
};