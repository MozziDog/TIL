# Unity 공부\_스크립팅\_SceneManager.LoadSceneAsync();

Unity에서 씬 전환이 일어날 경우 씬 하나에 담긴 데이터의 양이 크지 않다면 SceneManager.LoadScene();을 사용해서 바로 넘겨버리만 만약 씬 하나에 담긴 데이터가 커져서 로딩이 눈깜짝할 새 일어나지 않게 된다면 플레이어는 그 시간동안 로딩이 되는 건지 게임이 튕긴 건지 모르고 검은 화면만 바라보고 있어야 하는 문제점이 생기게 된다.

그래서 로딩씬이 필요하다. 로딩씬을 구현하기 위한 핵심은 `AsyncOperation` 형의 변수와 `SceneManager.LoadSceneAsync();`함수이다



로딩씬을 구현하기 위해서 먼저 로딩화면 전용씬을 만든다.

당연히 다른 씬으로 넘어가는 스크립트들은 다 로딩화면을 거치게 수정한다.

그리고 로딩씬에 로딩바의 역할을 할 이미지를 배치하고 다음과 같은 스크립트를 추가해준다.



```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LoadingScene : MonoBehaviour
{
  

    [SerializeField]
    Image progressBar;

    private void Start()
    {
        StartCoroutine(LoadScene());
    }

  

    IEnumerator LoadScene()
    {
        yield return null;

        AsyncOperation oper = SceneManager.LoadSceneAsync("TargetScene");
//LoadSceneAsync ("게임씬이름"); 입니다.
        oper.allowSceneActivation = false;
//allowSceneActivation 이 true가 되는 순간이 바로 다음 씬으로 넘어가는 시점입니다.

        float timer = 0.0f;
        while (!oper.isDone)
        {
            yield return null;

            timer += Time.deltaTime;

            if (oper.progress >= 0.9f)
            {
                progressBar.fillAmount = Mathf.Lerp(progressBar.fillAmount, 1f, timer);
                //Image가 아니라 Slider의 경우 progressBar.value로 간단히 구현이 가능
                if (progressBar.fillAmount == 1.0f)
                    oper.allowSceneActivation = true;
            }
            else
            {
                progressBar.fillAmount = Mathf.Lerp(progressBar.fillAmount, oper.progress, timer);
                if (progressBar.fillAmount >= oper.progress)
                {
                    timer = 0f;
                }
            }
        }
    }
}

```

[출처](http://ym7596.blog.me/221049233769)



위 코드의 경우 Image 컴포넌트에서 Image Type 옵션을 Filled로 하고 Fill Amount로 게이지의 양을 조절했지만 Slider를 사용할 경우 `progressBar.value`로 간단히 조절이 가능하다. 다만 Slider-Fill Area-Fill 게임오브젝트의 Image컴포넌트의 Image Type옵션을 미리 Filled로 설정해놓아야한다. 그렇지 않으면 찌그러뜨린 이미지를 펴는 모습이 될 수 있기 때문.