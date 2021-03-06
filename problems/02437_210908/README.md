# 백준 2437 번

## 저울
https://www.acmicpc.net/problem/2437
___
## 문제
![temp](https://user-images.githubusercontent.com/49303504/132465142-81d06910-a2fd-430b-9728-48ee07d1ee57.png)
> 하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다. </br>
> 이 저울의 양 팔의 끝에는 물건이나 추를 올려놓는 접시가 달려 있고, 양팔의 길이는 같다.</br>
> 또한, 저울의 한쪽에는 저울추들만 놓을 수 있고,</br>
> 다른 쪽에는 무게를 측정하려는 물건만 올려놓을 수 있다.</br>
> 무게가 양의 정수인 N개의 저울추가 주어질 때,</br>
> 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구하는 프로그램을 작성하시오.</br></br>
> 예를 들어, 무게가 각각 3, 1, 6, 2, 7, 30, 1인 7개의 저울추가 주어졌을 때,</br>
> 이 추들로 측정할 수 없는 양의 정수 무게 중 최솟값은 21이다. </br></br>
> 입력</br>
> 첫 째 줄에는 저울추의 개수를 나타내는 양의 정수 N이 주어진다.</br>
> N은 1 이상 1,000 이하이다.</br>
> 둘째 줄에는 저울추의 무게를 나타내는 N개의 양의 정수가 빈칸을 사이에 두고 주어진다.</br>
> 각 추의 무게는 1이상 1,000,000 이하이다.</br></br>
> 출력</br>
> 첫째 줄에 주어진 추들로 측정할 수 없는 양의 정수 무게 중 최솟값을 출력한다.</br>
___
## 풀이 전.
> 전형적인 그리디 알고리즘으로 풀 수 있을 듯 하다</br>
> 내가 N에 대해서 알고 싶을때 N-1을 통해 유추 가능하다는 뜻.</br>
> 예를 들어, 내가 만약 (0)~(10)까지 다 무게를 잴 수 있다고 했을 때, 7이라는 '추'가 추가됐을 때,</br>
> 0 부터 10까지 만들어낸 무게에 각각 7을 더해서 각각의 무게를 만들 수 있기에 0부터 17까지 무게를 잴 수 있을 것이다.</br>
> (0)~(10)</br>
> (7)~(10+7)</br>
> ==> (0)~(17)</br>
> 이렇게 해서 (0)~(17)이 탄생한다.</br></br>
> 하지만 만약 이제 (0)~(17)에서 다음 추가 19이 온다면</br>
> (0)~(17)</br>
> (19)~(19+17)</br>
> ==> (0)~(17) + (19)~(36)</br>
> 이 되기 때문에 18을 만들 수가 없다.</br></br>
> 이 논리를 이용해서 문제를 풀면 일일이 다 더해보는 방식을 피할 수 있다.
___
## 풀이 후.
> [풀이 전] 방식을 이용해서 풀 수 있었다.