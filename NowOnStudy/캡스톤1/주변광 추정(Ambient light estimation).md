주변광 추정(Ambient light estimation)

다수의 AR SDK들은 주변광 추정기능이 있음.

근데 안드로이드로 빌드하니까 주변광 추정이 되긴 되는데 일부만 되더라

S21 기준 되는 거

* light Intensity : 주변광 세기
* color : 평균 컬러 밸런스

안되는 거

* main light direction : 메인광 방향
* main light brightness : 메인광 밝기
* color temp : 색온도
* 등등

안드로이드에서는 ARcore를 사용하고 ARcore는 후면 카메라 사용 시에 main light direction estimation도 된다던데 테스트해보니 값이 안나옴. 좀 더 찾아봐야 하겠지만 아마 ARcore와 ARkit 등 여러 SDK들을 묶는 과정에서 공통된 것만 지원하는 듯? 메인광 방향 추정이 안되는 게 상당히 아쉽다 ㅜㅜ

그래도 주변광 밝기 정도만 해도 충분히 괜찮은 듯?