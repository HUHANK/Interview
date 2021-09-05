#include <stdio.h>
#include <iostream>
#include "CTimeStat.h"

using namespace std;

class WordsCount {
public:
    int countSegments(string s) {
        if (0 == s.length()) return 0;
        int wc = 0;
        
        int ContiSpaces = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                ContiSpaces++;
            }
            else
            {
                if (ContiSpaces > 0)
                {
                    wc++;
                    ContiSpaces = 0;
                }
            }
        }
        if (' ' != s[0]) 
            wc++;
        return wc;
    }
};

void testWordsCount()
{
    CTimeStat t;
    string str = "Hello,  my name is  John ";
    WordsCount c;
    printf("[%s]:%d\n", str.c_str(), c.countSegments(str));
}