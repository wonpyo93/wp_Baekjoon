# 백준 11660

## 구간 합 구하기 5
https://www.acmicpc.net/problem/11660
___
## 풀이 전.
> 단순히 하나하나 더해가면 분명 time limit이 뜰 것 같은 문제. </br>
> 하지만, 직사각형 모양의 합을 계속 저장해준 다음, 차이를 구하는 문제로 변형하여 풀 수 있다.
___
## 풀이 후.
> 풀이 전의 생각과 동일하게 문제를 풀었다. </br>
> ![temp](https://user-images.githubusercontent.com/49303504/130469951-3b3bf49b-0be1-4c2f-8dec-dc5b41d8b162.png) </br>
> 이 그림처럼 왼쪽의 회색 부분을 구하고 싶을 때 초록색을 더하고 빨간색을 빼는 형식으로 구할 수 있다. </br>
> 경악스러운 점은,
> 
    ios::sync_with_stdio(0);
    cin.tie(0);
> 이거를 안 썼다고 계속 time limit이 떴었다... 앞으론 무조건 이걸 붙이는걸 default로 생각해야겠다.