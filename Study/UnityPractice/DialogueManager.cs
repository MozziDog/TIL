//DialogueManager를 직접 구현해보았다.
//4.27> 첫 작성. 한줄을 출력하는 printLine함수를 만들었다.


using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DialogueManager : MonoBehaviour {

	public Text textOutput;
	public string textToOut="안녕하세요 이것은 테스트 출력입니다.";
	public AudioSource SoundManager;
	public AudioClip textSound;
	float char2charWaitSeconds=0.05f;



	// Use this for initialization
	void Start () {
		StartCoroutine(printLine(textToOut));
	}
	
	// Update is called once per frame
	void Update () {

	}

	IEnumerator printLine(string textToOut)
	{
		textOutput.text="";
		for(int i=0; i<textToOut.Length; i++)
		{
			textOutput.text+=textToOut[i];
			SoundManager.PlayOneShot(textSound);
			yield return new WaitForSeconds(char2charWaitSeconds);
		}
	}

	public void startprintLine()
	{
		StartCoroutine(printLine(textToOut));
	}
}
