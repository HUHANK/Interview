#include <stdio.h>
#include <iostream>
#include <vector>

#include "CTimeStat.h"

using namespace std;

class CValidPHeses {
public:
    bool isValid(string s) {
        const string PUSH_FLAG = "(,{,[";
        const string POP_FLAG = "),},]";

        vector<char> stack;

        for (int i = 0; i<s.length(); i++)
        {
            char c = s[i];
            if (stack.empty())
            {
                if (POP_FLAG.find(c) != string::npos)
                {
                    return false;
                }
            }
            if (PUSH_FLAG.find(c, 0) != string::npos)
            {
                stack.push_back(c);
            }
            else if (POP_FLAG.find(c) != string::npos)
            {
                char ct = stack.back();
                stack.pop_back();
                if (c != getCorrespondFlag(ct)) return false;
            }
            else
            {
                return false;
            }
        }
        if (stack.empty())
            return true;
        else
            return false;
    }

    char getCorrespondFlag(const char c)
    {
        if (c == '(') return ')';
        else if (c == '{') return '}';
        else if (c == '[') return ']';
        return 0;
    }
};

void TestValidPHeses()
{
    string str = "(){}[](";
    CValidPHeses c;
    bool result =  c.isValid(str);

    cout << endl << "Result: " << result << endl;
}