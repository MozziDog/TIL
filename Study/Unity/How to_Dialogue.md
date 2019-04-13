# Unity 공부\_How to\_대화 시스템

대화 시스템을 만들려고 한다. 원하는 조건은 다음과 같다.

* 주어진 문장을 받아다가 한 문장씩 출력한다.
* 출력은 1글자씩 하고 1글자씩 출력할 때마다 소리를 낸다.
* 문장을 출력할 때 발언하는 캐릭터의 스프라이트를 띄운다.

구현 방법은 다음과 같다. 

1. DialogueManager를 만든다. DialogueManager는 다음을 제어한다.
   * 대화창의 On/Off 여부
   * 대화창의 Text 내용
   * 대화창과 함께 표시되는 캐릭터의 스프라이트
2. Dialogue에서 필요로 하는 Dialogue 클래스(라기보단 구조체)를 만든다. 이 클래스는 다음을 포함한다.
   * Text에 출력할 문장들
   * 각 문장을 출력할 때 표시해야될 캐릭터의 스프라이트
   * 각 캐릭터의 이름이 적힌 대화창 스프라이트
3. 다른 컴포넌트에서 Dialogue 인스턴스를 만들고, 거기에 내용물을 채워넣어 DialogueManager를 통해 출력한다. 



DialogueManager.cs는 별첨한다.



Dialogue.cs의 내용은 다음과 같다.

```c#
//----------처음----------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//컴포넌트로 사용할 것이 아닌 커스텀 클래스이므로 MonoBehavior를 상속받지 않는다.
[System.Serializable]
public class Dialogue{
    public string[] sentences;
    public Sprite[] sprites;
    public Sprite[] dialogueWindows;
}

//----------끝----------
```

