//1자리부터 N자리까지 재귀 함수 형태로 탐색하는 DFS의 형태라는걸 파악하는게 포인트

const filePath = process.platform === "linux" ? "/dev/stdin" : "example.txt";
const N = Number(require("fs").readFileSync(filePath).toString().trim());

const IsPrime = (n) => {
  if (n === 1) {
    return false;
  } else if (n === 2) {
    return false;
  } else {
    for (let i = 2; i <= Math.floor(Math.sqrt(n)); i++) {
      if (n % i === 0) {
        return false;
      }
    }
    return true;
  }
};

const DFS = (n) => {
  if (String(n).length === N) {
    console.log(n);
  } else {
    for (let i = 1; i <= 9; i++) {
      if (i % 2 === 0) {
        continue; // 짝수라면 더 탐색 불필요 -> 다음 숫자로 깊이있게 탐색 시도
      }
      if (IsPrime(n * 10 + i)) {
        //현재 깊이가 소수라면 -> 다음 깊이 소수 여부 탐색
        DFS(n * 10 + i);
      }
    }
  }
};
DFS(2);
DFS(3);
DFS(5);
DFS(7);

// 백준 제출시 메모리 초과가 뜬다..
