## 네트워크

- 문제번호: 43162
- 난이도: Level 3
- 유형: 그래프, DFS (연결 요소 개수 세기)

### 문제
`n`개의 컴퓨터가 있고, `computers[i][j] == 1`이면 `i`번과 `j`번 컴퓨터가 직접 또는 간접적으로 연결되어 있다는 뜻이다(인접 행렬). 네트워크란 서로 정보를 주고받을 수 있도록 연결된 컴퓨터들의 집합이며, 독립된 네트워크(연결 요소)가 몇 개인지 리턴하는 함수를 완성하라.

### DFS(깊이 우선 탐색)란?
그래프나 트리에서 한 지점(정점)에서 시작해서, **갈 수 있는 만큼 최대한 깊이 들어갔다가** 더 갈 곳이 없으면 되돌아오는(백트래킹) 탐색 방법이다.

- "너비 우선(BFS)"이 옆으로 넓게 퍼지면서 탐색하는 거라면, DFS는 한 방향으로 끝까지 파고드는 느낌
- 보통 재귀 함수로 구현하거나, 스택(stack)을 직접 써서 구현
- 이 문제처럼 "연결된 것들을 한 그룹으로 묶고 싶을 때" 아주 자주 쓰인다: 시작점에서 DFS를 한 번 돌리면, 그 시작점과 (직접이든 간접이든) 연결된 노드를 전부 방문하게 되기 때문

### 기본 DFS 코드 틀
```cpp
vector<bool> visited(n, false);   // 방문 여부 기록

void dfs(int cur) {
    visited[cur] = true;          // 1. 현재 노드를 방문 처리

    for (/* cur과 연결된 next 노드들 */) {
        if (!visited[next]) {     // 2. 아직 안 가본 곳이면
            dfs(next);            // 3. 그쪽으로 더 들어간다 (재귀)
        }
    }
    // 더 갈 곳이 없으면 자동으로 함수가 끝나면서 이전 호출로 되돌아감(백트래킹)
}
```

인접 행렬(`vector<vector<int>>`)로 그래프가 주어질 때는 "연결된 next 노드들"을 이렇게 찾는다:
```cpp
for (int next = 0; next < n; next++) {
    if (graph[cur][next] == 1 && !visited[next]) {
        dfs(next);
    }
}
```

### 이 문제에서의 접근
1. `visited(n, false)`로 컴퓨터별 방문 여부를 기록한다 (`n x n`이 아니라 컴퓨터 개수만큼, 즉 `n`짜리 1차원 배열)
2. `0`번부터 `n-1`번까지 순서대로 보면서, **아직 방문 안 한 컴퓨터**를 만나면:
   - 새로운 네트워크를 하나 발견한 것이므로 `answer++`
   - 그 컴퓨터에서 `dfs()`를 시작해서, 직접·간접으로 연결된 컴퓨터를 전부 방문 처리한다
3. 끝까지 돌고 나면 `answer`가 곧 네트워크(연결 요소)의 개수

```cpp
void dfs(int i, vector<vector<int>>& computers, vector<bool>& visit){
    visit[i] = true;
    for (int next = 0; next < computers.size(); next++) {
        if (computers[i][next] == 1 && visit[next] == false) {
            dfs(next, computers, visit);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i = 0; i < n; i++) {
        if (visit[i] == false) {
            dfs(i, computers, visit);
            answer++;
        }
    }

    return answer;
}
```

### 왜 단순히 간선 개수를 세면 안 되는가
처음엔 `answer = n`에서 시작해서 간선을 하나 찾을 때마다 `answer--` 하는 방식으로 접근했는데, 이건 그래프에 **사이클(순환 연결)** 이나 **허브 구조**(한 노드가 여러 노드와 연결되어 있는데 그 노드들끼리는 서로 연결 안 된 경우)가 있으면 틀린다.

예: 0번이 1번, 2번과 각각 연결되어 있지만 1번과 2번은 서로 연결되지 않은 경우 → 실제로는 0을 통해 셋 다 이어진 네트워크 1개인데, 간선 개수(2개)만큼 빼면 `3 - 2 = 1`이 아니라 계산 방식에 따라 틀린 값이 나올 수 있다. DFS로 직접 그래프를 타고 들어가야 이런 케이스를 놓치지 않는다.

### 시간복잡도
O(n²) — 인접 행렬 전체를 DFS로 순회 (n은 컴퓨터 개수, 최대 200)
