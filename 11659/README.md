# 백준 11659

## 구간 합 구하기 4
https://www.acmicpc.net/problem/11659
___
## 풀이 전.
> 
___
## 풀이 후.
> [풀이 전] 계산에서 홀수인 부분을 생각할 때, 이 플로우를 꼭 외워두도록 하자. </br></br>

```
    while(A > 0) {
        if (A % 2 == 1)
            ans = matmul(ans, mat);
        A /= 2;
        mat = matmul(mat, mat);
    }
```
