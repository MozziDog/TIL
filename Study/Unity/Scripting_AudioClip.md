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



다만 위

 스크립트에는 아직 부족한 점이 많다.

* 사운드가 플레이되는 위치를 지정하지 못한다.(입체 음향 구성이 불가능하다)
* 볼륨 조절등의 기능이 없다.



볼륨 조절 등의 문제는 위 스크립트에 필요한 부분을 추가하여 해결할 수 있지만 그러기 위해서는 위 코드가 포함된 스크립트마다 수정해주어야 하기 때문에 많은 양의 코드 작성이 필요하고, 나중에 로직을 변경했을 때 수정하기 힘들다.

그러므로 이를 해결하기 위해 GameManager 오브젝트에 사운드 공용 함수를 만들어서 사용한다.



```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour {
    public float sfxVolumn = 1.0f;
    public bool isSfxMute = false;
    
    public void PlaySfx(Vector3 pos, AudioClip sfx)
    {
        if (isSfxMute == true)
            return;
        //새로운 게임오브젝트 생성 및 위치 변경
        GameObject soundObj = new GameObject("Sfx");
        soundObj.transform.position = pos;
        //생성한 게임오브젝트에 AudioSource 컴포넌트 추가 및 속성 설정
        AudioSource audioSource = soundObj.AddComponent<AudioSource>();
        audioSource.clip = sfx;
        audioSource.minDistance = 10.0f;
        audioSource.maxDistance = 30.0f;
        audioSource.volume = sfxVolumn;
        //사운드 재생
        audioSource.Play();
        //sfx의 재생시간이 지나면 게임오브젝트 삭제
        Destroy(soundObj, sfx.length);
    }
    
    
}
```

이제 다양한 스크립트 상에서 원하는 오디오클립을 원하는 위치상에서 재생시킬 수 있게 되었고, 음소거와 볼륨 옵션도 제공하게 되었다.

위 스크립트 상에서는 효과음만 재생할 수 있게 만들어 놓았지만 변수와 함수를 추가해서 플레이어의 더빙된 음성을 재생하는 것도 동시에 실행할 수 있을 것이다.



다만 위의 스크립트도 아직 단점이 조금 남아있는데 우선 사운드 재생을 위해 게임오브젝트의 생성과 삭제를 한다는 점이다. 게임오브젝트의 생성과 삭제는 GC의 작동을 유발하고 이는 곧 성능의 저하로 이어질 수 있기 때문에 가급적 게임오브젝트를 생성&삭제보단 활성화&비활성화를 하는 편이 좋을 것이다. (물론 그렇게 스크립트를 다시 짤 경우 동시에 재생할 수 있는 효과음의 갯수가 한정되어 버리는 문제점이 생기겠지만 이는 충분한 갯수의 게임오브젝트를 준비함으로 해결이 가능하다.)

하지만 우리는 최적화에 신경쓸 정도로 전문적으로 개발하는 것은 아니기 때문에 그냥 이대로 쓰고 만족하도록 하자.