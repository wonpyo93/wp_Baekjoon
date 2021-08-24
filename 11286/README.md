# 백준 11286

## 절댓값 힙
https://www.acmicpc.net/problem/11286
___
## 풀이 전.
> 배열에 자연수를 넣고 가장 작은 '절대값'을 호출하고 배열에 제거하는 문제. </br></br>
> (참고) 1927번은 올림차순 문제였다.</br>
> (참고) 11279번은 내림차순 문제였다.
___
## 풀이 후.
> priority queue를 그대로 구현하면 된다. </br>
> 하지만, positive 와 negative를 구분해서 QUEUE를 두개를 만들어준다.</br>
> positive일 경우 올림차순의 Queue에 넣어주고,</br>
> negative일 경우 내림차순의 Queue에 넣어준 다음에</br>
> 각각의 경우를 생각해주면 된다.