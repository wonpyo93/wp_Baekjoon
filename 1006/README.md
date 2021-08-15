# 백준 1006번

## 습격자 초라기
___
## 풀이 전.
> #### 문제 캡쳐.
> ![temp](https://user-images.githubusercontent.com/49303504/129314074-38845f39-a5c0-45f5-b338-9db5ddc76702.png)

> #### 한 소대 당 W명의 특수 소대.
> #### 각 구역벌 해당 수 만큼 배치.
> #### 한 구역당 한 소대.
> #### 한 소대가 두 구역 커버 가능하지만 한 구역을 두 소대가 커버 못함.
> #### 최소 소대 개수.
> #### 전형적인 DP 냄새가 난다..!
___
## 풀이 후.
> 풀이를 만드는데 있어서 8시간은 쓴 것 같다...<br/>
> Knapsack 문제랑 비슷하다고 생각해서 DP라고 생각해서 문제에 접근했다.<br/>
> 어차피 땅따먹기를 얼마나 효율적으로 하는 문제이기에...<br/><br/>
> 이 문제에서 가장 크게 걸림돌이 되는 부분은 원형이라는 것.<br/>
> 원형인 부분은 한 쪽을 잘라서 끊어진 띠로 만든다고 생각을 한다.<br/><br/>
> 그랬을 때, 끊어진 부분은 나중에 다시 이어줘야 한다는 것만 생각을 하고,<br/>
> 일단 띠라고 생각하고 문제에 접근한다.<br/><br/>