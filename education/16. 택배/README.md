## 택배
___
## 문제.
> 아래 그림과 같이 직선 도로상에 왼쪽부터 오른쪽으로 1번부터 차례대로 번호가 붙여진 마을들이 있다. </br>
> 마을에 있는 물건을 배송하기 위한 트럭 한대가 있고, 트럭이 있는 본부는 1번 마을 왼쪽에 있다. </br>
> 이 트럭은 본부에서 출발하여 1번 마을부터 마지막 마을까지 오른쪽으로 가면서 마을에 있는 물건을 배송한다.</br>
> ![image](https://user-images.githubusercontent.com/49303504/173714082-78b72bc8-3442-4f5c-bde5-cc9f7edd80c2.png)</br>
> 각 마을은 배송할 물건들을 박스에 넣어 보내며, 본부에서는 박스를 보내는 마을번호, 박스를 받는 마을번호와 보낼 박스의 개수를 알고 있다. 박스들은 모두 크기가 같다. </br>
> 트럭에 최대로 실을 수 있는 박스의 개수, 즉 트럭의 용량이 있다. 이 트럭 한대를 이용하여 다음의 조건을 모두 만족하면서 최대한 많은 박스들을 배송하려고 한다.</br>
> 조건 1: 박스를 트럭에 실으면, 이 박스는 받는 마을에서만 내린다.</br>
> 조건 2: 트럭은 지나온 마을로 되돌아가지 않는다.</br>
> 조건 3: 박스들 중 일부만 배송할 수도 있다.</br>
> 마을의 개수, 트럭의 용량, 박스 정보(보내는 마을번호, 받는 마을번호, 박스 개수)가 주어질 때, 트럭 한 대로 배송할 수 있는 최대 박스 수를 구하는 프로그램을 작성하시오. </br>
> 단, 받는 마을번호는 보내는 마을번호보다 항상 크다.</br>
> 예를 들어, 트럭 용량이 40이고 보내는 박스들이 다음 표와 같다고 하자.</br>
> ![image](https://user-images.githubusercontent.com/49303504/173714097-1e9619d0-f635-4978-beec-5750d9e04006.png)</br>
> 이들 박스에 대하여 다음과 같이 배송하는 방법을 고려해 보자.</br>
> (1) 1번 마을에 도착하면</br>
> ■ 다음과 같이 박스들을 트럭에 싣는다. (1번 마을에서 4번 마을로 보내는 박스는 30개 중 10개를 싣는다.)</br>
> ![image](https://user-images.githubusercontent.com/49303504/173714132-b113f024-5a16-40a3-9e25-2aec330c7d75.png)</br>
> (2) 2번 마을에 도착하면</br>
> ■ 트럭에 실려진 박스들 중 받는 마을번호가 2인 박스 10개를 내려 배송한다. (이때 트럭에 남아있는 박스는 30개가 된다.)</br>
> ■ 그리고 다음과 같이 박스들을 싣는다. (이때 트럭에 실려 있는 박스는 40개가 된다.)</br>
> ![image](https://user-images.githubusercontent.com/49303504/173714172-ca8f4a7d-0f33-4f06-afde-fc085af31a4d.png)</br>
> (3) 3번 마을에 도착하면</br>
> ■ 트럭에 실려진 박스들 중 받는 마을번호가 3인 박스 30개를 내려 배송한다. (이때 트럭에 남아있는 박스는 10개가 된다.)</br>
> ■ 그리고 다음과 같이 박스들을 싣는다. (이때 트럭에 실려 있는 박스는 30개가 된다.)</br>
> ![image](https://user-images.githubusercontent.com/49303504/173714190-7cc0afcb-efb9-4feb-8220-1174d34e9089.png)</br>
> (4) 4번 마을에 도착하면</br>
> ■ 받는 마을번호가 4인 박스 30개를 내려 배송한다.</br>
> 위와 같이 배송하면 배송한 전체 박스는 70개이다. 이는 배송할 수 있는 최대 박스 개수이다.</br>
> </br></br>
> 입력</br>
> 입력의 첫 줄은 마을 수 N과 트럭의 용량 C가 빈칸을 사이에 두고 주어진다.</br>
> N은 2이상 2,000이하 정수이고, C는 1이상 10,000이하 정수이다.</br>
> 다음 줄에, 보내는 박스 정보의 개수 M이 주어진다. M은 1이상 10,000이하 정수이다.</br>
> 다음 M개의 각 줄에 박스를 보내는 마을번호, 박스를 받는 마을번호, 보내는 박스 개수(1이상 10,000이하 정수)를 나타내는 양의 정수가 빈칸을 사이에 두고 주어진다.</br>
> 박스를 받는 마을번호는 보내는 마을번호보다 크다.</br>
> </br></br>
> 출력</br>
> 트럭 한 대로 배송할 수 있는 최대 박스 수를 한 줄에 출력한다</br>
> </br></br>
> 입력예시</br>
> 4 40</br>
> 6</br>
> 3 4 20</br>
> 1 2 10</br>
> 1 3 20</br>
> 1 4 30</br>
> 2 3 10</br>
> 2 4 20</br>
> </br></br>
> 출력예시</br>
> 70</br>