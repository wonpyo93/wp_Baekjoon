## 구슬 집어넣기 게임
___
## 문제.
> 철수의 동생이 다니는 학교에서는 ‘구슬 집어넣기 게임’이 선풍적인 인기를 끌고 있다. </br>
> 철수 동생은 반 친구들과 이 게임의 성적을 놓고 경쟁을 하고 있다.</br>
> 어느 날, 철수의 동생이 시무룩한 얼굴을 하고 집에 들어왔다. 친구들보다 좋은 성적을 내지 못했다고 우울했던 것이다. </br>
> 그래서 철수는 동생을 위해 게임에서 최고 성적을 내는 방법을 알려주는 프로그램을 만들기로 했다.</br>
> 게임은 다음 룰에 의해 진행된다.</br>
> 1.게임판에는 빨간구슬, 파란구슬, 벽, 그리고 목표구멍이 있다.</br>
> 2. 플레이어는 총 10회 게임판을 기울일 수 있다. (방향 : 상하좌우)</br>
> 3. 플레이어가 게임판을 기울이게 되면 해당 방향으로 빨간구슬과 파란구슬이 한 칸 이동한다.</br>
> 4. 이동방향에 벽이 있는 구슬은 움직일 수 없다.</br>
> 5. 이동 시 빨간 구슬과 파란 구슬이 같은 위치로 움직여 부딪히는 경우 구슬이 깨지므로, 게임 실패다.</br>
> 6. 파란구슬이 목표구멍으로 들어가는 것은 게임 실패다.</br>
> 7. 기울임 횟수가 10회를 넘어서면 게임 실패다.</br>
> 8. 빨간 구슬이 목표구멍으로 들어가는 것이 이 게임의 목표이다.</br>
> 9. 적은 횟수를 기울여 해결할수록 많은 높은 점수를 얻을 수 있다.</br>
> 기본적으로 게임판의 가장자리는 구슬이 게임판 밖으로 빠져나가지 못하도록 벽으로 둘러쌓여 있다.</br>
> 철수는 우선 이 게임에서 문제를 해결할 수 있는 가장 적은 횟수를 알고 싶다. 이를 출력하는 프로그램을 작성하시오.</br>
> </br></br>
> 첫 번째 줄에 테스트 케이스 개수 T(1≤T≤10)가 주어진다.</br>
> 이후부터 T개의 테스트 케이스 셋트가 주어진다.</br>
> 셋트의 첫 번째 줄에는 게임판의 행(R)과 열(C)이 순서대로 주어진다. (3<=R,C<=15)</br>
> 셋트의 두 번째 줄부터 게임판의 행만큼 게임판의 상황이 주어진다.</br>
> (B – 파란구슬, R – 빨간구슬, . – 이동가능지역, # - 벽, H-목표구멍)</br>
> </br></br>
> 출력</br>
> T줄에 걸쳐 각 테스트 케이스의 게임성공 최단 기울임 횟수를 출력하게 된다.</br>
> 게임해결이 불가능한 경우 -1을 출력한다.</br>
> </br></br>
> 입력예시</br>
> 2</br>
> 6 15</br>
> ###############</br>
> #..#R#..B.....#</br>
> #..#.#.H......#</br>
> #....#.#......#</br>
> #.............#</br>
> ###############</br>
> 6 15</br>
> ###############</br>
> #..#R#.B......#</br>
> #..#.#.H......#</br>
> #....#.#......#</br>
> #.............#</br>
> ###############</br>
> </br></br>
> 출력예시</br>
> 8</br>
> 9</br>