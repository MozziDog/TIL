Loop Cut and Slide: 면 사이를 잘라 새로운 Edge Loop를 추가하는 도구

*  단축키: `Ctrl + R`
* 마우스 드래그로 Edge Loop의 위치를 정할 수 있음
* 마우스 휠 스크롤 또는 숫자 입력으로 Edge Loop의 갯수를 정할 수 있음
* Loop Cut and Slide 이후 Operator 패널 조정해서 자르는 개수와 위치 등을 다시 제어할 수 있음
* Operator 패널에서 Smoothness, Falloff 등의 옵션을 조절하여 곡면을 형성하고 조절할 수 있음
* 생성된 Edge는 `단축키 X - Edges` 또는 `단축키 X - Edge Loops` 를 통해 제거 가능
  * Edges: 단순 제거
  * Edge Loops: 주변의 면을 제거하면서 Edge 제거
* Loop Cut은 삼각면이나 Loop 조건을 불충족하는 영역에 이르면 중단됨.
  * Blender 선택 - loop 참조



Edge Slide: Edge를 인접한 요소를 따라 미끄러지듯이 이동시키는 도구

* Loop Cut 이후 자동으로 사용됨

* 개별적으로도 사용 가능

* 단축키 `G - G (G 두번)`

* 마우스 드래그로 위치 지정 후 좌클릭으로 확정

* 옵션: 보통 인접한 요소들과의 거리에 따라 인접한 요소들과 비슷한 모양으로 Slide되는데, 옵션을 통해 이를 변경할 수 있다.

  * Even(단축키 `E`): 한쪽의 요소를 따라간다. 가령 한 Edge Loop은 삐뚤빼뚤하고 다른 Edge Loop은 원에 까깝게 매끄러우면 그 사이에서 둘을 인접한 Edge Loop을 Slide 시킬 때 매끄러운 원 모양을 유지하면서 Slide 시킬 수 있다.

    ![1561826348591](F:\TIL\TIL\Study\Front\HTML\1561826348591.png) (Even이 켜져서 안쪽 Loop의 모양을 따라가는 모습)

  * Flipped(단축키 'F'): 따라갈 요소를 바꾼다. Flipped 옵션이 체크되어 있으면 매끄러운 원이 아니라 삐뚤빼뚤한 Edge Loop의 모양을 따라간다.

    ![1561826245225](F:\TIL\TIL\Study\Front\HTML\1561826245225.png) Flip이 켜져서 바깥쪽 Loop 모양을 따라가는 모습



Vertex Slide

* Vertex를 인접 Edge를 따라 Slide 시킴
* 단축키: `Shift + V` or 점을 선택한 상태에서 `G + G (G 두번)`