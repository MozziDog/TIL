# Unity Game Engine #2





### 커스텀 에디터 제작

유니티에서 에디터 에디팅하기



Editor 폴더 생성하고 그 폴더에 작성해야 함. Resource 폴더처럼 사전에 지정되어 있는 폴더 명임.



MonoBehavior 클래스는 Edit 모드에서 실행되지 않음.

그래서 클래스는 EditorWindow를 상속해야함.



빈 창을 만들어서 띄우는 코드

```C#
using UnityEditor; // EditorWindow를 쓰기 위해 필요

public class MyEditorWindow : EditorWindow
{
    // 상단 메뉴바 -> Window메뉴에서 이 함수를 호출하기 위해 attributes 지정 필요함.
    [MenuItem("Window/My Editor")]
    static void Init() // 객체 생성 안된 상태에서 호출될 함수니까 static으로 선언
    {
        var myWindow = EditorWindow.GetWindow<MyEditorWindow>();
        myWindow.Show();
    }
}
```



그 빈 창에 GUI를 만들어 채워넣는 코드

```C#
public class MyEditorWindow : EditorWindow
{
    [MenuItem("Window/My Editor")] static void Init() {...}
    
    private void OnGUI() // Unity Message function
    {
        GUI.Button(new Rect(posX,posY,width,height), "Click Me!");
    }
    
}
```



```OnGUI()``` 와 ```GUI.Button()`` 함수는 MonoBehaviour에서 쓰면 UI 작성용으로도 사용할 수 있음. 

```c#
public class TestGUI : MonoBehaviour // 인게임 컴포넌트
{
	private void OnGUI()
    {
        GUI.Button(new Rect(10,10, 200, 50), "In game button")
	}
}
```

UI canvas가 있어서 요즘에 그렇게 쓸 일은 없겠지만. 어쨋든 커스텀 에디터의 UI 작성은 인 게임 UI 작성과 같은 코드로 이루어진다는 것을 알 수 있음.



버튼 입력의 감지

```c#
public class TestGUI : EditorWindow
{
	private void OnGUI()
    {
        if(GUI.Button(new Rect(10,10, 200, 50), "Click me!"))
        {
            Debug.Log("이렇게 하면 버튼 클릭을 감지할 수 있음.");
        }
	}
}
```



위 코드를 보면 ```OnGUI()```는 매 프레임(?)마다 실행되며, ```GUI.Button()```은 매 프레임마다 호출되어 버튼을 그리고, 클릭될 경우 true, 아니면 false를 리턴하는 함수임을 알 수 있다.



버튼 이외의 다른 GUI 요소들

```c#
public class TestGUI : EditorWindow
{
	private void OnGUI()
    {
        GUI.Label(new Rect(posX, posY, width, height), "This is Label");
	}
}
```



변수 활용

```C#
public class TestGUI : EditorWindow
{
    private int clickCounter = 0;
    static void Init() {...}
	private void OnGUI()
    {
        if(GUI.Button(new Rect(10,10, 200, 50), "Click me!"))
        {
            clickCounter++;
        }
        GUI.Label(new Rect(10, 70, 200, 50), $"I have been clicked {clickCounter} times");
	}
}
```

Init에서 인스턴스를 생성했으니 OnGUI에서 필드값을 사용할 수 있음.



스타일 설정

```c#
	private void OnGUI()
    {
        if(GUI.Button(new Rect(10,10, 200, 50), "Click me!"))
        {
            clickCounter++;
        }
        
        GUI.skin.label.fontSize = 36;
        GUI.Label(new Rect(10, 70, GUI.skin.label.CalcSize(
            new GUIContent($"I have been clicked {clickCounter} times"
                          ), 50), $"I have been clicked {clickCounter} times");
	}
```

GUI를 사용한 스타일 설정은 구리다. 근데 뭐 어쩔 수 없음

폰트사이즈는 한번만 설정해도 될 만한 건데 OnGUI() 함수 내부에 써야만 효과가 있어서 불필요하게 여러번 호출해야 함.

```GUI.skin.label.CalcSize()```는 인자로 주어진 GUI element context 의 적절한 크기를 계산해주는 함수.

근데 새 라벨을 만드려면 크기를 미리 지정해줘야 해서 자기 자신으로 크기 설정 안됨. ```new GUIContent()```로 새 GUI요소 만들어서 그걸로 계산해야 함. 



다시 컴파일해도 필드 값 유지됨



GUI 요소 자동 정렬

``` C#
private void OnGUI()
{
   	GUILayout.BeginVertical(); 
	// 이하 GUI 요소들을 전부 세로로 배치. 가로는 항상 가득 차게, 세로는 적절한 값으로.
   
    GUI.skin.button.fontSize = 36;
   	GUILayout.Button("button"); // GUI.foo()이 아니라 GUILayout.foo()임.
    GUI.skin.label.fontSize = 36;
    GUILayout.Label("label");// GUI 요소가 자동 정렬되므로 사이즈 지정 필요 없음.
   
   	GUILayout.EndVertical();
}
```

```C#
private void OnGUI()
{
   	GUILayout.BeginVertical(); 
	// 이하 GUI 요소들을 전부 세로로 배치
   	
    GUILayout.BeginHorizontal();
   	// 이하 GUI 요소들을 가로로 배치
   	// ...
    	
  	GUILayout.EndHorizontal();
    
   	GUILayout.EndVertical();
}
```



GUI Slider

```c#
private float mySliderValue = 0.5f;
private void OnGUI()
{
    GUILayout.BeginVertical(); 
	
	mySliderValue = GUILayout.HorizontalSlider(mySliderValue, min, Max);
	
    GUILayout.EndVertical();
}
```





### Resource Management in Unity



미세 팁: Unity에서 스크립트 생성하지 않고 VS에서 스크립트를 생성할 수 도 있다. 



에셋 포스트프로세서

```c#
using UnityEditor;

namespace Assets.Editor
{
    public class MyAssetPostProcessor : AssetPostprocessor
    {
        // 인스턴스 생성 X -> static
        static void OnPostprocessAllAssets(string[] importedAssets, string[] deletedAssets, string[] movedAssets, string[] movedFromAssetPaths)
        {
            // ....
        }
    }
}
```

새 에셋이 import되면 importedAssets에 그 에셋들이 전달됨. 나머지도 마찬가지.



예시 1 . 새로 추가되거나 삭제되거나 이동된 에셋 리스트 출력

```C#
public class MyAssetPostProcessor : AssetPostprocessor
{
    // 인스턴스 생성 X -> static
    static void OnPostprocessAllAssets(string[] importedAssets, string[] deletedAssets, string[] movedAssets, string[] movedFromAssetPaths)
    {
        foreach(var importedAsset in importedAssets)
        {
            Debug.Log(importedAsset);
        }
        foreach(var deletedAsset in deletedAssets)
        {
			Debug.Log(deletedAsset);
        }
        for(int i=0; i<movedAssets.Length; i++)
        {
            Debug.Log($"Moved {movedAssets[i]} from path {movedFromAssetPaths[i]}");
        }
    }
}
```

(폴더든 파일이던)이름 바꾸기도 시스템적으로는 새 위치로 옮기는 것으로 취급되므로 이 경우에도 Moved... 메시지가 출력될 것임. (그리고 imported도 호출됨)

폴더도 에셋으로 취급됨.



에셋 포스트 프로세서 활용안

* 에셋폴더 내부의 음원 파일은 몇개, 이미지 파일은 몇개인지 등 통계내기

* 고해상도 이미지 다운사이징

* 인스펙터 창에서 설정해줘야하는 것들을 자동으로 설정하게 하기. 
  * 예)  모든 신규 wav 파일을 mono로 설정.

* 파일명이 규칙에 맞는지 확인하기 (ex. 파일명에 공백있는지 확인)





### Unity에서 지원하지 않는 기능이 있다면



```C#
public class MyAssetPostProcessor : AssetPostprocessor
{
    // 인스턴스 생성 X -> static
    static void OnPostprocessAllAssets(string[] importedAssets, string[] deletedAssets, string[] movedAssets, string[] movedFromAssetPaths)
    {
        foreach(var importedAsset in importedAssets)
        {
            Debug.Log(importedAsset);
            arg = importedAsset
		
        	var process = new System.Diagnostics.Process();
        	process.StartInfo.FileName = "cmd";
        	process.StartInfo.Arguments = $@"/c C:\\...\\MyProgram.exe ""{arg}"" ";
        	// ↑ 유니티 외부의 별도 프로그램
        	process.StartInfo.WorkingDirectory = Directory.GetCurrentDirectory();
            // 현재 디렉토리로 작업 디렉토리 설정.
        	process.Start();
        }
    }
}
```

윈도우에서 경로 지정 시 ```\```를 사용하지만 탈출문자 때문에 ```\\``` 사용해야 함.

```@"..."``` : 스트링 리터럴. escape sequence 사용 시 문제가 되거나 여러줄 문자열을 작성하거나 할 때 사용.  ```$"...{...}..."```를 사용한 interpolate와 병행 사용 가능.

```" ..."" ... ""... "``` 리터럴 방식을 사용한 string 표현에서 double quote를 사용해서 따옴표 내부에서 따옴표를 표현할 수 있음. 이를 사용하여 arg 문자열에 공백이 있을 경우에도 하나의 argument로 인식되게 할 수 있음.

(리터럴이 아니라면 escape sequence를 사용해서 ```" ...\" ... \"... "```를 사용)



위 코드를 사용하면 새 에셋이 import될 때마다 cmd창으로 MyProgram.exe를 시작할 수 있음.

즉, Unity 엔진이 지원하지 않는 작업들도 할 수 있게 됨! (예를 들면 파일명 변경)

(안드로이드 앱은 이미지 파일명에 공백을 허용하지 않기 때문에 위 코드를 사용하여 모든 공백을 _언더바로 치환할 수 있음)

