# Unity 공부\_스크립팅\_Mathf

스크립팅을 하다 보면 Mathf 클래스를 사용할 때가 많은데, (내 기준으로) 자주 사용되는 몇가지만 추려서 정리해보았다.



### Mathf.Abs(x)

입력받은 인자의 절댓값을 리턴한다. 자료형은 인자의 것을 따라감



### Mathf.Atan2(y,x)

y, x를 입력 받고 y/x 기울기의 직선이 나타내는 각도를 **라디안**으로 리턴한다.



### Mathf.Clamp(value, min, max)

value가 min과 max 사이에 있으면 value를, min보다 작으면 min을, max보다 크면 max를 리턴한다.

즉, 리턴값은 min과 max 사이로 제한된 value값이다.



### Mathf.Cos(f)

cos(f)를 리턴한다. 여기서 f는 **라디안**이다.



### Mathf.Floor(f)

f보다 작거나 같은 최대의 정수를 리턴한다. 근데 리턴 타입은 float다.



### Mathf.FloorToInt(f)

f보다 작거다 같은 최대의 정수를 리턴한다. 리턴 타입이 Int다.



### Mathf.Lerp(a,b,t)

a와 b를 선형보간한다. 즉, 리턴값은 `a(1-t) + bt` 이다.



### Mathf.Max(a,b...)

가장 큰 녀석의 값을 리턴



### Mathf.Min(a,b...)

가장 작은 녀석의 값을 리턴



### Mathf.MoveTowards(current, target, maxDelta)

처음 리턴 값은 current이며 시간이 진행될 수록 target값에 가까워지는데, 시간당변위는 maxDelta를 넘지 않는다. Update() 같은 함수 내에서 쓰이지 단독으로는 안 쓰일... 걸?



### Mathf.Rad2Deg

읽기 전용 상수. 라디안 값에 곱하면 60분법의 각도가 된다.



### Mathf.Sin(f)

sin(f)값을 리턴, 여기서 f는 **라디안**이다.



### Mathf.SmoothDamp(current, target, currentVelocity, smoothTime, maxSpeed, deltaTime)

moveTowards 같이 시간이 지날수록 current에서 target으로 리턴값이 변하는 함수이다. 다만 인자가 조금 많은데 사실 알고보면 하는 일은 비슷함. 

* currentVelocity: C에서의 포인터와 같은 ref 레퍼런스 타입 인자로, 읽기용도로가 아닌, 쓰기 용도로 주어진 인자이다. SmoothDamp가 실행될 때마다 current에서 target으로 가는 리턴값의 시간당 변화량이 저장된다.
* maxSpeed: 생략 가능. 생략하지 않았을 시, currentVelocity가 maxSpeed를 넘지 못한다. 즉, 최대 속도에 제한이 생김.
* deltaTime: 생략 가능. 가장최근에 함수를 호출하고 지난 시간. SmoothDamp가 실행되는 주기를 주어줘야 SmoothDamp 함수가 잘 작동 할 수 있는 것 같다. (생략 시) 기본 값은 Time.deltaTime이다.



### Mathf.Sqrt(f)

f의 제곱근(Square root)을 리턴. 최적화를 위해선 a와 Sqrt(b)를 비교하는 것보단 a*a와 b를 비교하는 것이 좋다.



### Mathf.Tan(f)

tan(f)를 리턴. 여기서 f는 **라디안**이다.