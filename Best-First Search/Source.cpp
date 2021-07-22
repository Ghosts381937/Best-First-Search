#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int>  pi;
vector <vector<pi>> graph;
void addedge(int x, int y, int cost) {
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}
void bestfirstsearch(int src, int dest,int numberOfVertex) {
	//��l��visited�}�C
	vector <bool> visited(numberOfVertex,false);

	//��l��priority queue�A�é�Jsrc
	priority_queue <pi, vector<pi>, greater<pi>> pq;
	pq.push(make_pair(0, src));
	visited[pq.top().second] = true;
	cout << "The path is ";
	while (!pq.empty()) {
		//�qpq���X�`�I
		pi node = pq.top();
		pq.pop();

		//��X���X�L�{
		cout << " -> " << node.second;

		//if it was found
		if (node.second == dest) {
			cout << "\nfound!";
			return;
		}

		//�����h�M���۾F�`�I�A�Y�`�I�����X�h��Jpq�ñNvisited�̪����I�]��true
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

	//�Ы�graph
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