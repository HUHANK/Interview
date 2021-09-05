#include "CTimeStat.h"

#include <iostream>
#include <ctime>
using namespace std;

CTimeStat::CTimeStat()
{
	m_startTime = clock();
}

CTimeStat::~CTimeStat()
{
	printf("The Program Run Time is: %fs\n", (double)(clock() - m_startTime)/ CLOCKS_PER_SEC);
}