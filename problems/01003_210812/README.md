# 백준 1003번

## 피보나치 함수
> #### 문제 캡쳐.
> ![temp](https://user-images.githubusercontent.com/49303504/129040756-def7f784-0cf4-4229-a43c-2c6deb31257e.png)

___
## 풀이 전.
> #### fibonacci(N)에서 끝에 나오는 0과 1이 몇번이 출력되는지에 대한 문제이다.
> #### 쉽게 생각하면 피보나치를 구현한 다음에 마지막에 0과 1이 호출될때마다 그냥 count를 하면 되겠지만
> #### 조금 더 생각하여 그 자체의 의미를 파악해보도록 하자.
___
## 풀이 후.
|N|ZERO|ONE|
|---|---|---|
|0|1|0|
|1|0|1|
|2|1|1|
|3|1|2|
|4|2|3|
|5|3|5|
|6|5|8|
> #### 위의 표를 보면 알 수 있듯이 zero와 one도 얼마 지나지 않으면 Fibonacci 형식을 띄게 된다.
> #### 각 ZERO와 ONE의 변수를 지정해주고 각자 Fibonacci로 구해주면 끝!
> #### 물론 N이 40밖에 안되는걸 이용해서 아예 숫자 array를 만들어놓고 뽑아오는 형식을 써도 되겠다...