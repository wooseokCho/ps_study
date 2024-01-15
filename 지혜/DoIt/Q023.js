//DFS
//시간복잡도 O(V+E) [노드수 : V, 에지 수 : E ]
//한 번 방문한 노드를 다시 방문하면 안된다 -> 노드 방문 여부를 체크할 리스트가 필요
//탐색 방식은 스택 or 재귀호출
const filePath = process.platform === "linux" ? "/dev/stdin" : "example.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [V, E] = input.shift().split(" ").map(Number); //  노드수 : V, 에지 수 : E
const VisitArray = new Array(V + 1).fill(false); // 빈  방문 리스트 /// V+1 까지 만들기 !!

let AdjList = [];
for (let i = 1; i <= V; i++) {
  // 빈  인접리스트 /// V+1 까지 만들기 !!
  AdjList[i] = [];
}

// const AdjList = Array.from(Array(V), () => []); // 빈 인접 리스트 만드는 2번째 방법

// 인접리스트로 그래프 표현
for (let i = 0; i < E; i++) {
  //양방향 그래프이므로 간선 정보를 받아서 서로의 연결그래프에 추가
  let [from, to] = input[i].split(" ").map(Number);
  AdjList[from].push(to);
  AdjList[to].push(from);
}

function dfs(start) {
  VisitArray[start] = true;
  for (let i = 0; i < AdjList[start].length; i++) {
    let next = AdjList[start][i];
    if (!VisitArray[next]) {
      //방문 안했으면 방문
      dfs(next);
    }
  }
}

//전체 정점을 for문으로 돌면서 아직 방문하지 않았다면 dfs탐색을 시작하고 ans를 1증가 시켜준다.
let ans = 0;
for (let i = 1; i <= V; i++) {
  if (!VisitArray[i]) {
    dfs(i);
    ans++;
  }
}
console.log(ans);

//https://velog.io/@ywc8851/%EB%B0%B1%EC%A4%80-11724-%EC%97%B0%EA%B2%B0-%EC%9A%94%EC%86%8C%EC%9D%98-%EA%B0%9C%EC%88%98-javascript
