# Blender : Select

Edit 모드에서 Vertex, Edge, Face를 선택함에 있어서 단순히 우클릭하는 것이 아닌, 더 효율적으로 선택을 하면 그만큼 작업 효율이 오른다. 그러므로 선택하는 방법은 매우 중요하다고 할 수 있다.



###### 이하의 내용들은 전부 Select Mode에 따라 Vertex, Edge, Face중 하나의 종류에 적절하게 대응됨



### 범위 지정 선택

B: border select. 네모 범위 드래그해서 지정하고 그 내부 선택. 좌클릭으로 결정 우클릭으로 취소, Shift로 다수 선택 or 선택 해제

C: Circle select. 원형 선택. 마우스 주위 둥근 구역 내부의 요소 선택. 마우스 스크롤로 동그라미의 크기 조절 가능. 좌클릭으로 취소, Shift로 다수 선택 or 선택 해제

Ctrl : Lasso select. 올가미 선택. 마우스로 드래그하여 그린 올가미 내부의 요소 선택



### Edge loop & Edge ring

Alt + 우클릭(선택) : Edge loop, 주어진 Edge 방향으로 쭉 따라가며 나오는 Edge들을 전부 선택. 

Ctrl + Alt + 우클릭(선택) : Edge ring, 주어진 Edge 위아래로 마주한 Edge와 그 Edge가 마주한 Edge 등등을 전부 선택. 



상기한 단축키 말고도 3D view-Heade-Select 메뉴에 보면 Edge loop과 Edge ring이 있다. 기준이 될 Vertex 하나를 선택해놓고 Select 메뉴를 열어서 Edge loop (또는 Edge ring)을 선택해서도 사용 가능.



여기서 주어진 Edge의 방향대로 쭉 갈 경우 Edge 5개가 모인 Vertex 등에서는 어떻게 되는 지 의문이 생길 수 있다. 이 때는 더이상 선택을 이어나가지 않고 그냥 멈춘다. 

Edge가 4개가 아닌 Vertex가 나올 시 더 이상 진행하지 않는 Blender의 알고리즘 때문이다. 

Edge가 2개 모인(삼각형의 꼭짓점 같은 것) Vertex에서도 멈춘다. 오로지 Edge 4개가 모인 Vertex에서만 Edge loop 과 Edge ring이 다음 Vertex로 진행할 수 있다.



![image](./Edge_loop&Edge_ring Algorithm.jpg)

출처: blenderboop 유튜브



만일 위와 같은 이유로 끊기면 그냥 Shift 눌러서 다중선택으로 선택을 이어나가면 된다. 

Edge ring과 Edge loop은 그 자체로도 쓸 수 있지만 다른 선택 방법과 조합하여 사용할 수 있다. 

예를 들어 Alt + 우클릭으로 구의 Edge들 중 수박의 줄 하나에 해당하는 Edge들을 선택했다고 하자. 여기서 Select mode가 Edge로 되어있다면 3D View-header-Select-Edge rings 으로 수박의 모든 줄들을 다 선택할 수 있다.



### 다양한 선택 도구들

위에서 언급했지만 Select 메뉴에서 다양한 선택 방법들을 제공하고 있다.

여기서는 단축키만 기록한다

`Ctrl + Num +/-` : Select more/less. 선택된 요소를 중심으로 선택 범위를 확장하거나 축소한다. 

`Shift + Ctrl + Num +/-` : Next/Previous Active. 선택된 요소'들'을 바탕으로 그 다음 요소를 선택하거나 선택 해제한다.

`Ctrl + I` : 선택 반전

`Ctrl + 우클릭` : 첫 선택요소를 기준으로 마지막 선택 요소까지 가장 가까운 거리를 측정해 그 경로내의 요소들을 선택함. 윈도우의 Shift 좌클릭과 비슷함. 패널에서 여러 옵션을 선택할 수 있다. 

* Face Stepping : 경로가 끊어져도 상관없으니 첫지점에서 끝지점까지 가로질러 선택함. 가령 Grid상에서 서로 평행한 Edge 두개의 경우 Face Stepping 옵션이 꺼져있으면 ㄷ자처럼 생긴 경로의 Edge들이 선택되지만 Face Stepping 옵션이 켜져있을 경우 lllllll 같이 평행한 Edge들 사이의 다른 평행한 Edge들이 선택되게 됨.
* Topology Distance : 공간적인 거리가 대신 최소한의 선택단계를 위주로 선택합니다.
* Fill Region : 사각형 ABCD에서 A와 C를 선택했을 때 대각선 AC를 선택하지 말고 사각형 ABCD 전체를 선택합니다. 



아래는 단축키는 없는 것들



Random : 무작위로 선택한다. 패널에서 무작위 선택률등 여러 옵션을 조절할 수 있다.

Checker Deselect : 선택된 요소 내에서 격자무늬가 되게끔 일부를 선택 해제한다. 패널에서 옵션을 여럿 조절할 수 있어 체스판처럼 선택할 수도 있고 물고기 비늘무늬처럼 되게 할 수도 있다.

Mirror  : 선택된 요소를 X, Y, Z 축의 각 방향으로 동일하게 선택함. 패널에서 기준이 될 축을 지정할 수 있다. Shift키로 한 개 이상 지정도 가능

boundary Loop : 선택 영역의 테두리부분을 선택

Loop Inner-Region : 선택 테두리의 내부(테두리 기준으로 작은 쪽) 영역을 선택. 패널에서 Select Bigger를 체크하면 선택된 영역을 기준으로 더 큰 영역을 선택합니다.

Sharp Edge : 특정 조건(면 사이의 각도가 Operator Panel의 Sharpness값보다 작음)을 만족한 Edge들을 선택.



