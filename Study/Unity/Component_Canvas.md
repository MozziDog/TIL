# 유니티 공부\_컴포넌트\_Canvas

![image](./Component_Canvas.jpg)

유니티에서 UI는 캔버스(게임오브젝트) 상에 그려지는데, 게임오브젝트를 캔버스로 만들고 설정할 수 있는 컴포넌트이다.



## Render Mode

캔버스를 어떻게 렌더링할지를 선택한다.

* Screen Space - Overlay : 캔버스를 화면(=스크린=씬) 위에 출력한다.
* Screen Space - Camera : 캔버스를 특정 카메라(Render Camera)의 앞에 출력한다. 특정 카메라의 렌즈 앞에 캔버스를 테이프로 붙여 놓았다고 생각하면 쉽다.
* World Space : 캔버스를 월드 공간에 배치한다. 즉, 카메라가 움직여도 캔버스가 따라오지 못하고 반대방향으로 움직이는 것처럼 보이게 된다.



### Screen Space - Overlay

캔버스를 화면 위에 출력합니다. 가령, 화면이 둘로 분할되어 두개의 카메라 화상이 각각 출력되고 있다고 하더라도 Render Mode가 Screen Space - Ovelay인 캔버스에 작성된 UI는 화면 분할에 상관 없이 전체 화면에 걸처 하나만 표시됩니다.

##### Pixel perfect

정밀도를 위해 UI가 안티엘리어싱 없이 랜더링되어야 할 지의 여부입니다.



### Screen Space - Camera

캔버스를 `Render Camera`의 앞에 출력합니다. 카메라 설정이 UI가 표시되는 데에 영향을 줍니다. 가령, 카메라가 `Perspective`로 설정되어 있을 경우 `Field of View`의 값에 따라 캔버스가 왜곡되는 정도가 달라질 수 있습니다.

##### Render Camera

UI를 표시할 카메라를 지정합니다.



### World Space

캔버스가 화면이나 카메라에 붙어서 움직이지 않고 월드 공간에 위치하며 씬에 있는 다른 오브젝트들처럼 동작합니다. UI가 월드의 일부를 이루게 됩니다. VR세계 상에서의 상호작용 UI들에 대한 이미지와 비슷합니다.