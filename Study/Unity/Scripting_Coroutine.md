# Unity공부\_Scripting\_Coroutine

C#에는 코루틴이란 것이 존재한다. 개인적인 경험에 의거하면 코루틴은 주로 다음과 같은 경우에 쓰인다.

* 비동기적인 작업을 하려고 할 때
* 일정 시간(여러 프레임)에 걸쳐서 이뤄지는 일련의 작업을 수행할 때 

물론 아직 초보 프로그래머다 보니 정확하지는 않을 수 있다만 암튼 코루틴이 비동기적인 작업을 위해 쓰이는 것은 거의 사실이다.



코루틴의 사용방법은 다음과 같다.

```c#
void Start()
{
    float a=1;
    StartCoroutine(MyCoroutine(a));
    //or
    //StartCoroutine("MyCoroutine");
    //(전달할 인자가 없는 경우)
}

//코루틴 함수의 리턴형은 반드시 IEnumerator이다.
IEnumerator MyCoroutine(float waitTime)
{
    Debug.Log("Start Coroutine");
    //코루틴 함수에는 반드시 yield return 문이 포함되어야 한다.
    yield return new WaitForSeconds(WaitTime);
    Debug.Log("End Coroutine");
}
```

위 코드는 다음과 같은 동작을 수행한다.

1. 시작하자마자 코루틴을 호출한다.
2. 호출된 코루틴은 "Start Coroutine"을 출력한다.
3. a=1이므로 1초만큼 대기한다.
4. 코루틴이 "End Coroutine"을 출력한다.
5. 코루틴 종료



이론적인 부분을 짚지 않고 간단히 사용법만 알아보면 다음과 같다.

* IEnumerator형으로 코루틴함수를 선언한다.
* 코루틴에는 반드시 `yield return`(또는 `yield break`) 이 있어야 한다.
* `StartCoroutine( )`으로 선언한 코루틴을 실행한다.
* 코루틴 실행 중 `yield return`을 만나면 일단 멈춘다. 
* 만약 `yield return new WaitForSeconds(time)`라면 주어진 `time`만큼 대기한다.
* `yield return`문 다음 문장부터 이어서 처리한다.
* `yield break`를 만나면 코루틴을 아예 종료한다.





이후부터는 [여기](https://m.blog.naver.com/dlwhdgur20/221016139917)를 참고

