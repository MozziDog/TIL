# Unity 공부\_스크립팅\_AudioClip

Unity 엔진에는 기본적으로 오디오클립을 재생하기 위한 컴포넌트(Audio Source)가 존재한다.

그러나 Audio Source 컴포넌트를 효과음 등을 재생하기에는 불편한 점이 여럿 있다.

* Audio Source 컴포넌트는 오디오 클립을 하나만 지정할 수 있다.
* 재생할 타이밍을 정하기 힘들다.
* Audio Source 컴포넌트를 가진 게임오브젝트가 Destroy 되거나 하면 소리가 끊겨버린다.



물론 단점만 있는 것은 아니다.

* Volume, Pitch, Stereo Pan, Loop 등 다양한 옵션들을 제공한다.

그러나 상기한 이유들로 인해 효과음들을 재생하기 위해서는 소리를 재생시키기 위한 스크립트를 직접 작성해야할 필요가 있다.



작성해 볼 스크립트의 특징은 다음과 같다.

* 원하는 만큼 AudioSource 형 레퍼런스 변수를 만들 수 있다.
* AudioSource 컴포넌트에 의존한다.
* public 함수들을 작성하여 다른 스크립트 상에서 오디오클립 재생을 제어할 수 있게 한다.



```C#
//start
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour {

    public AudioClip[] sounds;

    AudioSource myAudio;
    public static SoundManager instance;

    private void Awake()
    {
        if (SoundManager.instance == null)
        {
            SoundManager.instance = this;
        }
        myAudio = this.GetComponent<AudioSource>();
    }

    public void PlayJumpSound(int i)
    {
            myAudio.PlayOneShot(sounds[i]);
    }
}
//end

```

이것으로 원하는 효과음을 마음껏 재생할 수 있게 되었다.