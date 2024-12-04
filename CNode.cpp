#include "CNode.h"

CNode::CNode(int Val)
{
	Value = Val;
	Next = nullptr;
}

CNode::~CNode()
{
	Value = -1;
	Next = nullptr;
	cout << "CNode ÒÑÎö¹¹£¡" << endl;
}

int CNode::GetNodeVal() const
{
	return Value;
}

CNode* CNode::GetNodeNext() const
{
	return Next;
}

void CNode::SetNodeNext(CNode* a)
{
	Next = a;
}
