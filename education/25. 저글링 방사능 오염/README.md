## 저글링 방사능 오염
___
## 문제.
> 승훈이는 심심한 시간에 스타크래프트(Starcraft) 게임을 하며 놀고 있었다.</br>
> 스타크래프트유닛중 하나인 저글링을 한 곳에 몰아세운 뒤, 방사능 오염 공격으로 없애보려고 했다. </br>
> 그런데 좀 더 재미있게 게임을 하기 위해서 게임을 개조하여 방사능 오염 공격을 가하면 방사능은 1초마다 이웃한 저글링에 오염된다. </br>
> 그리고 방사능에 오염된 저글링은 3초 후에 죽게 된다. </br>
> 예를 들어 아래 왼쪽그림과 같이 모여 있는 저글링 중에 빨간 동그라미 표시를 한 저글링에게 방사능 오염공격을 가하면, 총 9초 후에 저글링들이 죽게 된다. </br>
> 아래 오른쪽에 있는 그림의 숫자들은 각 저글링들이 죽는 시간이다.</br>
> ![image](https://user-images.githubusercontent.com/49303504/173715729-31524153-0309-4ea2-8935-77a1c998e1ef.png)</br>
> 저글링을 모아놓은 지도의 크기와 지도상에 저글링들이 놓여 있는 격자 위치가 주어질 때, 총 몇 초 만에 저글링들을 모두 없앨 수 있는지 알아보는 프로그램을 작성하시오. </br>
> </br></br>
> 입력</br>
> 첫째 줄은 지도의 가로 세로 크기가 주어진다. 지도는 격자 구조로 이루어져 있으며 크기는 100×100칸을 넘지 않는다.</br>
> 둘째 줄부터는 지도상에 저글링들이 놓여있는 상황이 주어진다. 1은 저글링이 있는 곳의 표시이고 0은 없는 곳이다.</br>
> 마지막 줄에는 방사능오염을 가하는 위치가 가로 세로 위치로 주어진다.</br>
> 주의 사항으로, 좌표는 좌측상단이 가장 작은 위치이며 이 위치의 좌표는 (1,1)이다.</br>
> </br></br>
> 출력</br>
> 죽을 수 있는 저글링들이 모두 죽을 때까지 몇 초가 걸리는지 첫 번째 줄에 출력하고 둘째 줄에는 죽지 않고 남아 있게 되는 저글링의 수를 출력하시오.</br>
> </br></br>
> 입력예시</br>
> 7 8</br>
> 0010000</br>
> 0011000</br>
> 0001100</br>
> 1011111</br>
> 1111011</br>
> 0011100</br>
> 0011100</br>
> 0001000</br>
3 5</br>
> </br></br>
> 출력예시</br>
> 9</br>
> 0</br>