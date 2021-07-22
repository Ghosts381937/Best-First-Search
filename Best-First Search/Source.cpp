#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int>  pi;
vector <vector<pi>> graph;
void addedge(int x, int y, int cost) {
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}
void bestfirstsearch(int src, int dest,int numberOfVertex) {
	//初始化visited陣列
	vector <bool> visited(numberOfVertex,false);

	//初始化priority queue，並放入src
	priority_queue <pi, vector<pi>, greater<pi>> pq;
	pq.push(make_pair(0, src));
	visited[pq.top().second] = true;
	cout << "The path is ";
	while (!pq.empty()) {
		//從pq取出節點
		pi node = pq.top();
		pq.pop();

		//輸出走訪過程
		cout << " -> " << node.second;

		//if it was found
		if (node.second == dest) {
			cout << "\nfound!";
			return;
		}

		//未找到則遍歷相鄰節點，若節點未走訪則放入pq並將visited裡的該點設為true
		else {
			for (pi i : graph[node.second]) {
				if (visited[i.second] == false) {
					pq.push(i);
					visited[i.second] = true;
				}
			}
		}
	}

}
int main() {
	int x = 0, y = 0;
	int cost = 0;
	int numberOfVertex = 0;

	//創建graph
	cout << "enter the amount of vertex:";
	cin >> numberOfVertex;
	graph.resize(numberOfVertex);
	while (1) {
		cin >> x >> y >> cost;
		if (cost == -1)
			break;
		addedge(x, y, cost);
	}

	int src, dest;
	cout << "enter the source:\n";
	cin >> src;
	cout << "enter the destination:\n";
	cin >> dest;
	int count = 0;
	bestfirstsearch(src, dest, numberOfVertex);
}