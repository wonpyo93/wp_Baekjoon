# 백준 1010번

## 다리 놓기
https://www.acmicpc.net/problem/1010
___
## 풀이 전.
> permutation combination 느낌이 물씬 나는 문제이다.
> combination일 가능성이 높아 보이는게, permutation을 쓸 수 없는 이유는 다리가 겹쳐지지 못한다는 점.
> N이 M보다 작다는 점에 있어서 이 문제를 다르게 해석할 수 있는데,
> M개의 choice 중에서 N개만큼 선택해라, 그런데 겹칠 수 없다.
> {1, 2, 3}과 {2, 3, 1}이 겹칠 수 없다. (다리가 겹쳐지는 모습과 같다.)
___
## 풀이 후.
> 역시 그냥 combination 이었다.
> 굳이 문제가 있었다면 워낙 !(factorial)이 커지다 보니 미리 잘라내주는 작업을 해야 했다는 것 뿐...