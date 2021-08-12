# 백준 1004번

## 어린 왕자
___
## 풀이 전.
> #### 어린왕자라고 쓰지만 역시 어린왕자하고 전혀 관련히 없는 문제...
> #### 원들이 존재하는 Map이 존재하고, 두 좌표가 주어졌을 때,
> #### 두 좌표 사이의 이동 경로에 있어서 원들과 교차하게 되는지를 구하는 문제.
> #### 여기서 "*행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다*" 는 가정이 매우 중요할 듯 하다.
> #### 다시 말해, 하나의 원 안에 각 점이 없다면 무조건적으로 피할 수 있다. 
> 
___
## 풀이 후.
> #### 한 원에 있어서 세 가지의 케이스로 생각할 수 있다.
> + 두 점 모두 원 밖에 있을 경우
>   + 무조건적으로 피할 수 있기 때문에 count하지 않는다.
> + 두 점 모두 원 안에 있을 경우
>   + 원 밖으로 나갈 일이 없기 때문에 count하지 않는다. 
> + 한 점만 원 안에 있을 경우
>   + 어쩔수 없이 만나기 때문에 count해준다.
> #### 결국 한 점만 원 안에 있는 경우만 count하면 끝!