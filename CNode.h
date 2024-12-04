#pragma once
#include<iostream>
using namespace std;

class CNode
{
private:
	int Value;
	CNode* Next;

public:
	CNode(int Val);
	~CNode();
	int GetNodeVal()const;
	CNode* GetNodeNext()const;
	void SetNodeNext(CNode* a);
};

