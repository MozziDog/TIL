Extrude:밀어내다.

기존의 요소를 밀어내어 새로운 요소를 만들어내는 방식



0차원 요소인 점을 Extrude하면 1차원 요소인 Vertex가 새로이 형성된다.

1차원 요소인 Vertex를 Extrude하면 2차원 요소인 Face가 새로이 형성된다.



Extrude의 5가지 방식

* Region: 선택된 요소를 하나의 부위로써 밀어내는 일반적인 Extrude 방식
* Region(vertex normals): 각 요소가 바라보는 방향으로 Extrude하는 방식
* Individual Face: 각 요소를 개별적으로 Extrude하는 방식
* Vertex only: Vertex만 Extrude하는 방식
* Edge only: Edge만 Extrude하는 방식



Extrude의 단축키는 요소를 선택한 후 E이다.

X, Y, Z 단축키를 활용해서 X, Y, Z축 방향으로 Extrude를 제한 할 수 있다.

Face는 Extrude하면 면이 향하는 방향, 즉 z축으로 제한되는데 Z키를 눌러 이것을 해제할 수 있다.



시점을 정면 등으로 정렬한 뒤 Extrude할 경우 방향이 고정되므로 원하는 형태를 신속하게 만들어 낼 수 있다.



팁: 미사일, 포탄과 같은 것의 개략적인 형태는 단순히 Extrude만으로 빠르게 만들어 낼 수가 있다.



Individual Face 방식으로 Extrude하면 각 요소가 따로따로 Extrude된다.

가령 6각기둥 모양의 옆면들을 Individual 방식으로 Extrude하면 톱니바퀴 모양이 되므로 그러한 모양들을 만들어 낼 때 유용하다.



Region(vertex normals)는 각 요소(Face)가 바라보는 방향으로 Extrude한다.

Region은 기존의 Face와 Extrude를 실행한 후 튀어나온 Face의 크기가 같았지만 Region(vertex normals)는 Face의 크기가 다를 수 있다.

정육면체의 옆면들을 Region(vertex normals) 방식으로 Extrude하면 정육면체를 품은 넙적한 정사각기둥이 된다.

Tool shelf - Tools - Mesh Tools 또는 3dview - Header - Mesh - Extrude 에서 사용할 수 있다.



Vertex only와 Edge only는 각각 Vertex 선택 모드와 Edge 선택모드에서만 활성화되며, 말 그대로 Vertex 또는 Edge만 Extrude하는 것이다. 



Extrude 기능의 주의점: Extrude를 실행 취소해도 새로이 생긴 요소는 기존의 요소와 겹쳐서 존재한다. 가령 면을 Extrude 하려다가 취소했으면 해당 면이 두개 겹쳐진 형태로 존재하게 됨

이러한 상황은 의도치 않은 상황을 발생시킬 수 있으므로 몇가지 규칙을 따르는 것이 좋다.

* 인접한 Face를 개별로 Extrude할 경우 '연결된 형태'가 아니므로 Face 2개를 같이 선택 후 Extrude해야 한다.
* Remove Doubles 도구를 사용한다
  *  Remove Doubles 도구는 중첩된 요소를 제거해주는 역할을 한다. 
  * 중첩된 영역의 요소를 선택 (혹은 A키로 모두 선택)한 후 W - Remove Doubles 선택

