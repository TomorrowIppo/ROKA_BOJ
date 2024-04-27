# ROKA_BOJ
전역(23.05.30 ~ 24.11.29)하기 전까지 백준 문제 풀기 및 유형 정리<br/><br/><br/><br/>

# :rocket:알고리즘 시간복잡도 실압근
### C++ STL
- 중복 제거(unique) : unique 자체는 $O(N)$이지만, erase(unique()) 형태면 $O(NM)$
<br/> 기본 형태 : ***v1.erase(unique(v1.begin(), v1.end()), v1.end());***

### Graph & Search
- DFS / BFS : $O(V + E)$
- 위상정렬 : $O(V + E)$
- Union-Find : 기본적으로 Find 함수에 의해 시간복잡도가 좌우되며, $O(logN)$, 최악의 경우 $O(N)$이다. 

### Data Structure
- 우선순위 큐 : 삽입, 삭제, front 가져오기 $O(logN)$
- 이분탐색 : $O(logN)$
- 투 포인터 : $O(N)$<br/><br/><br/><br/>

# :rocket:문제 유형 실압근
## Graph
### Flood Fill
### 위상정렬(Topological Sort)
### 다익스트라(Dijkstra)
<br/><br/>
## Tree
### 분리집합(Union Find)
### 최소 스패닝 트리(Minimum Spanning Tree)
<br/><br/>
## DP
### Knapsack Problem
- 0-1 Knapsack Problem
### Tree DP
- 임의의 간선을 지나는 횟수를 이용하는 유형 ([BOJ_7812](https://www.acmicpc.net/problem/7812), [BOJ_20188](https://www.acmicpc.net/problem/20188))

```mermaid
graph TD
    A(["A"]) --- B(["B"]) 
    B(["B"]) --- C(["C"])
    B(["B"]) --- D(["D"])
    C(["C"]) --- E(["E"])
    C(["C"]) --- F(["F"])
    D(["D"]) --- G(["G"])
``` 
A가 루트인 트리에서 임의의 한 정점으로부터 다른 모든 정점까지의 거리의 합을 구하기<br/>
(N : 정점의 개수, weight : 간선의 길이, subTree[x] : x가 루트인 서브트리의 정점 개수)
    
우선, basis로 쓸 dist[A]를 누적합으로 미리 구한다.

B to Others를 구할 때 C를 제외한 나머지 간선들의 방문 횟수와 C to Others를 구할 때 B를 제외한 나머지 간선들의 방문 횟수는 일치한다. 
B to Others 기준 B-C를 지나는 횟수는 subTree[C], C to Others 기준 B-C를 지나는 횟수는 N - subTree[C]이므로 DFS로 구현하면 점화식은 다음과 같다.

    dist[child] = dist[parent] + (N - 2 * subTree[child]) * weight
    

### Graph DP
### LIS
### LCS
