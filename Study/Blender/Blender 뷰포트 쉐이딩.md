# Blender 공부\_Viewport Shading

쉐이딩 : 물체에 음영을 부여하는 기법

쉐이딩 모드에는 기본적으로 6가지가 있다.

* Rendered : 실시간 렌더링 미리보기, 물체를 정확하게 묘사. 빛의 영향 O
* Material : Texture와 Material(색상이나 반사율 등) 포함, 빛의 영향 X
* Texture : 오브젝트에 적용된 텍스쳐 표현, Material X, 빛의 영향 X
* Solid : 기본 모드. 모델링 등에 적합. Texture, Material, 빛의 영향 X
* Wireframe : 와이어프레임으로 묘사됨
* Bounding Box : 오브젝트 크기에 맞게 Box형태의 Edge로 표현함.



Viewport Shading은 3DView - Header - Viewport Shading 아이콘을 눌러서 변경할 수 있다.

또, 자주 쓰이는 몇몇 모드들은 단축키를 사용할 수도 있다.

* `Shift + Z` : Solid와 Rendered 간의 전환
* `Z` : Solid 와 Wireframe 간의 전환
* `Alt + Z` : Solid 와 Texture 간의 전환



Viewport Shading은 3Dview Editor를 분할하여 각 구역별로 다른 모드를 설정할 수 있다.