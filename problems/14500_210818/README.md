# 백준 14500번

## 테트로미노
https://www.acmicpc.net/problem/14500
___
## 풀이 전.
> 딱히 떠오르는 좋은 방법은 없고 그냥 나올 수 있는 모든 테트로미노 경우의 수를 구하고 max를 찾으면 될 것 같다.</br>
___
## 풀이 후.
> 솔직히 16236번을 풀 때 보다 더... brute force 같은 문제였다...</br>
> ![temp](https://user-images.githubusercontent.com/49303504/129855107-4f78a52f-4ecd-441f-813d-8836dd6fee4e.png)</br>
> 이렇게 1이 있는 칸을 첫 칸으로 시작했을 때 총 19가지의 경우의 수가 존재한다. </br>
> 거기서 1이 시작하는 칸이 어떤 칸인지에 따라 경우의 수가 줄어든다. </br>
> 그거에 맞춰서 그냥 싹다 찾아주고 거기서 max를 찾도록 했다.</br>
> 냈는데 되는걸 보고 오히려 기분이 나빴던 문제...</br>