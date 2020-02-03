#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define LL long long
#define MAXSIZE 100
bool vis[MAXSIZE + 5];
int in[MAXSIZE + 11];		//��� 
int f[MAXSIZE + 11];		//���鼯ָ����ڵ� 
typedef struct
{
	int x, y;
	int cost;
}road[(MAXSIZE * MAXSIZE + MAXSIZE) >> 1], Road;

typedef struct		//�ڽӾ��� 
{
	int arcs[MAXSIZE + 5][MAXSIZE + 5];
	int vexnum, arcnum;
	void init()
	{
		CLR(this->arcs, 0);
		this->arcnum = this->vexnum = 0;
	}
}AMGraph;

typedef struct ArcNode		//�ڽӱ�������������ֱ�ʾ 
{
	int adjvex;
	struct ArcNode* nextarc;
}AdjList[MAXSIZE + 5], AdjNode;
typedef struct
{
	AdjList vectices;
	int vexnum, arcnum;		//���㡢���� 
	void init()		//��ʼ�� 
	{
		for (int i = 1; i <= MAXSIZE; i++)
			this->vectices[i].nextarc = NULL;
		this->arcnum = this->vexnum = 0;
	}
	void Insert(int pos, AdjNode& t)		//��pos�������t�ڵ�
	{
		t.nextarc = this->vectices[pos].nextarc;
		this->vectices[pos].nextarc = &t;
	}
}ALGraph;

typedef struct Queue		//���� 
{
	int data;
	struct Queue* next;
	struct Queue* end;		//����ĩ�ڵ� 
	void init()
	{
		this->end = this;
		this->next = NULL;
	}
	int GetTop()
	{
		return this->next->data;
	}
	bool Empty()
	{
		if (this->next == NULL)
			return true;
		return false;
	}
	void Pop()
	{
		Queue* t = this->next;
		this->next = this->next->next;
		free(t);
		if (this->Empty())		//�������Ϊ�գ���βָ��ָ���Լ� 
			this->end = this;
	}
	void Push(int x)
	{
		Queue* t;
		t = (Queue*)malloc(sizeof(Queue));
		t->data = x;
		t->next = NULL;
		this->end->next = t;
		this->end = t;
	}
}Queue;

void dfsSearch(AMGraph& mm, int pos)		//�ݹ���DFS 
{
	printf("%d ", pos);
	vis[pos] = true;
	for (int i = 1; i <= mm.vexnum; i++)
	{
		if (!vis[i] && mm.arcs[pos][i])
			dfsSearch(mm, i);
	}
}
void DFS(AMGraph& mm)
{
	printf("������ͼ��DFS��Ϊ:");
	dfsSearch(mm, 1);
	puts("");
}

void BFS(AMGraph& mm)
{
	printf("������ͼ��BFS��Ϊ:");
	CLR(vis, false);
	Queue q;
	q.init();
	q.Push(1);
	vis[1] = true;
	while (!q.Empty())
	{
		int pr = q.GetTop();
		q.Pop();
		printf("%d ", pr);
		for (int i = 1; i <= mm.vexnum; i++)
		{
			if (!vis[i] && mm.arcs[pr][i])		//û�б����������Ҵ��ڱ� 
			{
				q.Push(i);
				vis[i] = true;
			}
		}
	}
	printf("\n");
}

void dijkstra(AMGraph& mm)
{
	CLR(vis, false);
	int dis[MAXSIZE + 5];
	CLR(dis, INF);
	dis[1] = 0;
	while (1)
	{
		int v = -1;
		for (int i = 1; i <= mm.vexnum; i++)
		{
			if (!vis[i] && (v == -1 || dis[i] < dis[v]))
				v = i;
		}
		if (v == -1)
			break;
		vis[v] = true;		//��� 
		for (int i = 1; i <= mm.vexnum; i++)
		{
			if (vis[i] == false && mm.arcs[v][i])
				dis[i] = min(dis[i], dis[v] + mm.arcs[v][i]);
		}
	}
	printf("%d\n", dis[mm.vexnum] == INF ? -1 : dis[mm.vexnum]);		//���������·������-1 
}
void ShortestRoad(AMGraph& mm)
{
	printf("��1�㵽%d������·��Ϊ�����������-1����", mm.vexnum);
	dijkstra(mm);
}

int find(int x)		//�ݹ�Ѱ���ڵ㲢·��ѹ�� 
{
	if (x != f[x])
		f[x] = find(f[x]);
	return f[x];
}
bool join(int x, int y)		//�ϲ��ڵ�
{
	int fx, fy;
	fx = find(x);
	fy = find(y);
	if (fx != fy)
	{
		f[fx] = fy;
		return true;
	}
	return false;
}
bool cmp(Road a, Road b)
{
	return a.cost < b.cost;
}
void Kruskal(AMGraph& mm)
{
	for (int i = 1; i <= mm.vexnum; i++)
		f[i] = i;		//��ʼ�����鼯���ڵ� 
	int ant = 0;
	road d;
	for (int i = 1; i < mm.vexnum; i++)
	{
		for (int j = i + 1; j <= mm.vexnum; j++)
		{
			if (mm.arcs[i][j])
			{
				d[ant].x = i;
				d[ant].y = j;
				d[ant++].cost = mm.arcs[i][j];
			}
		}
	}
	sort(d, d + ant, cmp);
	int cost = 0;		//��С���� 
	for (int i = 0; i < ant; i++)
	{
		if (join(d[i].x, d[i].y))
			cost += d[i].cost;
	}
	printf("%d\n", cost);
}
void MiniSpanTree(AMGraph& mm)
{
	printf("��С����������С����Ϊ:");
	Kruskal(mm);
}

void Topo(ALGraph& am)
{
	printf("����������Ϊ��");
	Queue q;
	q.init();
	for (int i = 1; i <= am.vexnum; i++)
	{
		if (!in[i])
			q.Push(i);
	}
	while (!q.Empty())
	{
		int pr = q.GetTop();
		printf("%d ", pr);
		q.Pop();
		in[pr] = -1;
		AdjNode* t;
		t = am.vectices[pr].nextarc;
		while (t != NULL)
		{
			in[t->adjvex]--;
			if (!in[t->adjvex])
				q.Push(t->adjvex);
			t = t->nextarc;
		}
	}
	puts("");
}

int main()
{
	int arcnum, vexnum;
	AMGraph mm;		//Matrix map
	ALGraph am;		//Adj map
	mm.init(), am.init();
	cout << "�����붥��ı���";
	scanf("%d %d", &vexnum, &arcnum);
	am.arcnum = mm.arcnum = arcnum;
	am.vexnum = mm.vexnum = vexnum;
	printf("������%d���ߣ�DFS��BFS�����·����С�������д�Ϊ����ͼ ; ��������������ͼ��:\n", arcnum);
	for (int i = 1; i <= arcnum; i++)		//�������� 
	{
		int x = 0, y = 0, z = 0;		//���㣬�ߵ�Ȩֵ
		scanf("%d %d %d", &x, &y, &z);
		mm.arcs[x][y] = mm.arcs[y][x] = z;
		AdjNode t;
		t.adjvex = y;
		t.nextarc = NULL;
		in[y]++;
		am.Insert(x, t);		//�����ڽӱ��� 
	}
	DFS(mm);
	BFS(mm);
	ShortestRoad(mm);
	MiniSpanTree(mm);
	Topo(am);
	return 0;
}