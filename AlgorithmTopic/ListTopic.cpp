#include <stdio.h>
#include <iostream>
#include <vector>

#include "CTimeStat.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void showListNode(ListNode* p)
{
	cout << "[";
	while (p)
	{
		cout << p->val << ", ";
		p = p->next;
	}
	cout << "]" << endl;
}

class CMergeTwoSortedList {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr) return nullptr;
		else if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;

		ListNode* pHead = nullptr;
		ListNode* pCur = nullptr;
		ListNode* pSub = nullptr;
		ListNode* pTmp = nullptr;

		if (l1->val <= l2->val)
		{
			pHead = l1;
			pSub = l2;
		} else {
			pHead = l2;
			pSub = l1;
		}
		pCur = pHead;
		
		while (pCur)
		{
			pTmp = pCur->next;
			while (pSub && pTmp)
			{
				if (pTmp->val >= pSub->val)
				{
					pCur->next = pSub;
					pSub = pSub->next;
					pCur = pCur->next;
					pCur->next = pTmp;
				}
				else
					break;
			}
			if (nullptr == pTmp && pSub != nullptr)
			{
				pCur->next = pSub;
				break;
			}
			pCur = pCur->next;
			//showListNode(pHead);
		}

		return pHead;
	}
};

void testMergeTwoSortedList()
{
	ListNode l1;
	l1.val = 1; 
	ListNode* pl1 = &l1;
	for (int i = 1; i < 10; i++)
	{
		pl1->next = new ListNode();
		pl1 = pl1->next;
		pl1->val = 2 * i + 1;
	}
	showListNode(&l1);

	ListNode l2;
	l2.val = 1;
	ListNode* pl2 = &l2;
	for (int i = 1; i < 10; i++)
	{
		pl2->next = new ListNode();
		pl2 = pl2->next;
		pl2->val = 2 * i ;
	}
	showListNode(&l2);

	CMergeTwoSortedList c;
	showListNode(c.mergeTwoLists(&l1, &l2));
}

class CReverseList {
public:
	ListNode* reverseList(ListNode* head) {
		return reverseList1(head);
	}

	static ListNode* reverseList1(ListNode* note) {
		if (nullptr == note->next) return note;

		//cout << note->val << " ";
		ListNode* last = reverseList1(note->next);
		note->next->next = note;
		note->next = nullptr;
		showListNode(note);
		showListNode(last);
		return last;
	}

	ListNode* reverseList2(ListNode* note) {
		ListNode* pCur = note->next;
		ListNode* pTail = note;
		ListNode* pHead = pTail;
		pTail->next = nullptr;
		ListNode* pTmp = 0;
		while (pCur)
		{
			pTmp = pCur;
			pCur = pCur->next;
			pTmp->next = pHead;
			pHead = pTmp;
		}
		//pTmp->next = NULL;
		return pHead;
	}
};

void testReverseList()
{
	ListNode l1;
	l1.val = 1;
	ListNode* pl1 = &l1;
	for (int i = 1; i < 10; i++)
	{
		pl1->next = new ListNode();
		pl1 = pl1->next;
		pl1->val = 2 * i + 1;
	}
	showListNode(&l1);

	CReverseList c;
	showListNode(c.reverseList(&l1));
}

class CMiddleNode {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) return head;
		return middleNode2(head);
	}

	ListNode* middleNode2(ListNode* head)
	{
		
		ListNode* pTmp = head;
		int CNT = 0;
		while (pTmp)
		{
			CNT++;
			pTmp = pTmp->next;
		}
		cout << CNT << ":ALL  ";

		int i = 0;
		pTmp = head;
		while (pTmp)
		{
			i++;
			if (i == CNT / 2 + 1)
			{
				return pTmp;
			}
			pTmp = pTmp->next;
		}
		return head;
	}

	static ListNode* middleNode1(ListNode* head)
	{
		static int CNT1 = 0;
		static int CNT2 = 0;
		static ListNode* ret = nullptr;
		CNT1++;
		CNT2++;
		if (head->next == nullptr) return head;
		middleNode1(head->next);
		CNT1--;
		cout << CNT1 << " | " << CNT2 << endl;

		if (CNT1 == (CNT2 / 2 + 1))
		{
			//showListNode(head);
			ret = head;
		}
		return ret;
	}
};

void testMiddleNode()
{
	ListNode l1;
	l1.val = 1;
	ListNode* pl1 = &l1;
	for (int i = 2; i < 7; i++)
	{
		pl1->next = new ListNode();
		pl1 = pl1->next;
		pl1->val = i;
	}
	showListNode(&l1);

	CMiddleNode c;
	showListNode(c.middleNode(&l1));
}