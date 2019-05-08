# Unity공부\_Scripting\_delegate&event

delegate는 C에서의 함수 포인터와 비슷한 것이다. 다른 함수를 전달해주는 데 사용한다고 한다.

근데 사실 C 공부할 때도 함수 포인터는 열심히 안했는데

뭐 어쨋든 Unity 게임을 만들다 보면 하나 하나 접근해서 특정 동작을 하게끔 하는 것보다 이벤트가 발생만 하면 각자 알아서 특정 동작을 실행하는 것이 좋을 때가 있다. 

가령 예를 들면 슈팅게임에서 보스가 죽었을 때 탄을 삭제해야 하는 경우 탄이 많으면 보스가 죽은 뒤 한번에 화면 안의 모든 탄들을 삭제해야되는데 이 때 쓸데없이 연산량이 많아질 수 있다.

이럴 때 쓰는 것이 event이다.

그리고 event를 구현하기 위해 사용하는 것이 delegate(대리자)이다.

delegate는 C#에서 다른 메소드를 가리킬 수 있는 **타입**이다. 이를 이용하여 event를 구현한다.



아래는 예제 코드 1번

```c#
public delegate void Handler();
public static event Handler OnBossDead;
```



우선 `delegate void Handler()`를 선언한다. 이는 void 리턴형이고 인자를 받지 않는 함수를 가리키기 위한 delegate를 선언하고 그 이름을 Handler로 하겠다는 뜻이다.

그리고 마치 `Handler()`가 타입인 것처럼  `event Handler OnBossDead`를 생성한다.



예제 코드 2번

```c#
void OnEnable()
{
    ExampleClass.OnBossDead += BulletClear;
}

void BulletClear()
{
	Destroy(this.gameObject);
}

void OnDisable()
{
    ExampleClass.OnBossDead -= BulletClear;
}
```

Delegate의 특이한 점은 여러개의 함수를 가리킬 수 있다는 것이다. `+=`연산자로 가리키는 함수를 추가할 수 있으며 `OnBossDead`가 호출되면 마치 해야할 일 목록처럼 여태까지 추가되었던 함수들을 차례로 실행한다. 물론 빼는 것도 가능하다. `-=`연산자를 사용하여 뺄 수 있다. 위 예제코드 2번에서는 최적화를 위해 `OnDisable`과 조합하여 (이미 비활성화되어있기 때문에) Destroy할 필요가 없는 경우 BulletClear가 실행되지 않게 하고 있다.

이런 식으로 예제 코드 2번을 탄 오브젝트에다가 넣어두고 예제 코드 1번을 게임매니저 오브젝트 등에 넣어두면 탄은 생성될 때마다 ''자기 자신을 destory하는 행위''를 '해야 할 일 리스트'에 올려두고 개발자는 보스가 죽었을 때 `OnBossDead()`만 호출하면 '해야 할 일 리스트'에 올라간 함수들이 전부 실행되기 때문에 탄들이 알아서 청소되는 효과를 볼 수 있다.

