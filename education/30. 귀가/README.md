## 귀가
___
## 문제.
> 농부 창호가 키우는 소들은 각자 자신의 목장에 얌전히 있다. </br>
> 소가 없는 텅 빈 목장도 있다. 각각의 목장은 다른 목장들과 하나 혹은 더 많은 길로 연결이 되어 있다. </br>
> 때때로 두 목장은 한 개 이상의 길로 연결되어 있을 수도 있으며, 적어도 한 개 이상의 목장들은 헛간으로 가는 길이 존재한다. </br>
> 물론 소는 어떤 방향으로도 갈 수 있고, 모든 소들은 같은 속도로 걷게 된다.</br>
> 목장들에는 ‘a’부터 ‘z’까지와, ‘A’부터 ‘Y’까지로 번호가 붙여져 있다. </br>
> 소 한 마리는 대문자 알파벳이 번호 매겨진 목장에 있다. </br>
> (목장 하나 당 소 한 마리 이다) 그리고 소가 없는 목장은 소문자로 번호가 매겨져 있다. </br>
> 헛간은 그 헛간에 소가 있건 없건, ‘Z’로 번호가 매겨져 있다.</br>
> 각각 목장과 목장, 혹은 목장과 헛간을 잇는 길의 거리가 주어질 때, 헛간으로 가장 먼저 올 수 있는 소와 그 거리를 구하는 프로그램을 작성하자.</br>
> </br></br>
> 입력</br>
> 첫 줄에 P(1≤P≤10,000)개의 길 들이 입력된다. </br>
> 둘째 줄부터 P+1번째 줄까지, 한 줄에 두 문자와 숫자 하나가 입력 되는데, 이는 서로 연결 되는 두 목장(혹은 헛간)의 번호와, 그 길의 길이(1≤길이≤1,000)를 뜻한다. </br>
> 번호가 소문자인 목장과 대문자인 목장은 따로 존재한다. </br>
> 예를 들어 번호가 ‘e’인 목장과 ‘E’인 목장은 따로 존재하며, ‘e’는 소가 없는 목장이고, ‘E’는 소가 있는 목장이다. </br>
> 또한 ‘z’는 소가 없는 목장으로, 헛간 ‘Z’와는 상관없는 다른 장소이다.</br>
> </br></br>
> 출력</br>
> 가장 먼저 헛간에 도달하는 소가 원래 있던 목장의 번호와, 그 소가 걷는 거리를 출력하라.</br>
> (실제 문제 논리 상 최단 거리가 같은 목장이 여러 곳일 수 있으나, Test Case에서 최단 거리 목장이 하나만 나오는 상황을 설정하였다.)</br>
> </br></br>
> 입력예시</br>
> 5</br>
> A d 6</br>
> B d 3</br>
> C e 9</br>
> d Z 8</br>
> e Z 3</br>
> </br></br>
> 출력예시</br>
> B 11</br>