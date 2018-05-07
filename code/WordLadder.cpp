// WordLadder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <set>
#include <string>
#include <queue>
using namespace std;

//����cur�ĺ��ӽ�㣬����children��
void Extend(const string& cur, vector<string>& children, const set<string>& dict,
			const string& end, set<string>& visit)
{
	string child = cur;
	children.clear();
	int i;
	char c,t;
	for(i = 0; i < (int)cur.size(); i++)
	{
		t = child[i];
		for(c = 'a'; c != 'z'; c++)
		{
			if(c == t)
				continue;
			child[i] = c;
			if(((child == end) || (dict.find(child) != dict.end()))
				&& (visit.find(child) == visit.end()))
			{
				children.push_back(child);
				visit.insert(child);
			}
		}
		child[i] = t;
	}
}

int CalcLadderLength(const string& start, const string& end, const set<string>& dict)
{
	queue<string> q;
	q.push(start);
	vector<string> children;	//�ӵ�ǰ��������չ�õ����½�㼯��
	set<string> visit;
	int step = 0;
	string cur;
	while(!q.empty())
	{
		cur = q.front();	//��cur��ʼ��չ
		q.pop();
		Extend(cur, children, dict, end, visit);
		for(vector<string>::const_iterator it = children.begin(); it != children.end(); it++)
		{
			if(*it == end)
				return step;
			q.push(*it);
		}
		step++;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	string start = "hit";
	string end = "cog";
	cout << CalcLadderLength(start, end, dict);
	return 0;
}