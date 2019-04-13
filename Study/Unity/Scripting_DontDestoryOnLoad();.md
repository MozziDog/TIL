# Unity 공부\_스크립팅\_Object.DontDestoryOnLoad();

씬이 전환될 때 유지해야하는 것들이 있다. 가령 예를 들면

* 이전 씬에서 플레이어가 선택한 정보를 다음씬에 넘겨줄 때
* 씬이 바뀌어도 재생중인 배경음악이 계속되어야 할 때
* 서로 다른 씬에서 동일한 게임매니저 오브젝트를 사용할 때 

등등이 있다. 

그럴 때 DontDestroyOnLoad(Object)를 사용하여 싱글톤 패턴을 활용한다.

---

##### 싱글톤 패턴이란

일반적인 의미로는 '애플리케이션이 시작될 때 어떤 클래스가 최초 한번만 메모리를 할당하고(Static) 그 메모리에 인스턴스를 만들어 사용하는 디자인 패턴'이다.

여기서는 클래스(=컴포넌트)와 게임오브젝트를 최초 한번만 생성하고 이후에 (특히 씬 전환할 때) Destroy하지 않으면서 재활용하는 방식이라고 생각하면 되겠다.

이에 관해선 [링크](https://jeong-pro.tistory.com/86) 참고

---



사용법은 다음과 같다.

```C#
using UnityEngine;
using System.Collections;

public class ExampleClass : MonoBehaviour {
    void Awake() {
        DontDestroyOnLoad(transform.gameObject);
    }
}
```

위와 같이 스크립트를 작성하여 원하는 게임오브젝트에 넣어주면 해당 게임오브젝트는 다른 씬으로 넘어갈 때 파괴되지 않게 된다.



그러나 다음 시나리오에서는 이것만으로는 부족하다.

* 씬 A에서 B로 넘어갈 때 배경음악이 바뀌지 않는 것을 원해서 SoundManager 오브젝트에 위 스크립트를 넣어주었는데, 씬 B(또는 A)에서 씬 C로 넘어갈 땐 배경음악이 바뀌길 원해서 씬 C에 SoundManager 오브젝트를 넣어주었더니 씬 C에서 두개의 BGM이 동시에 재생되는 문제가 생겼다.
* GameManager 오브젝트를 씬 A에 넣고 위 스크립트를 넣어주었다. 씬 B나 씬 C에서는 GameManager 오브젝트를 넣어주지 않았는데 유니티 에디터상에서 테스트할 때 문제가 생겼다.



위 시나리오들은 전부 다른 방식으로 해결할 수 있는 문제지만 여기서는 다음과 같이 해결하도록 하자

1. 씬이 전환되어도 삭제되지 않기를 원하는 오브젝트들에는 위 스크립트를 넣어준다.
2. 모든 씬에 SceneManager 오브젝트를 배치한다. 이는 다음과 같은 역할을 수행한다.
   * 오브젝트 A가 이미 씬에 존재하는지 확인한다.
   * A가 씬에 존재한다면 아무것도 하지 않고 A가 씬에 존재하지 않는다면 프리팹으로 만들어진 A를 인스턴스화한다.



이 경우 SceneManager 오브젝트에 들어가야 하는 스크립트는 다음과 같다.



```C#
using UnityEngine;
using System.Collections;

public class ExampleClass : MonoBehaviour {
    
    public GameObject SoundManager;
    public Vector3 position;
    public Quaternion rotation;
    void Awake() {
        if(GameObject.FindGameObjectWithTag("SoundManager")==null)
		{
			Instantiate(SoundManager, position, rotation);
		}
    }
}
```



이것으로 유니티 에디터상에서 게임을 테스트할 때에도 배경음악이 원활히 나오게 되었다.

개발과정 상에서 이점은 있어도 릴리즈 상에서의 이점은 거의 없긴 하지만... 뭐 어때