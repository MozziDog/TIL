# C++ 입출력 스트림

입출력 방식은 버퍼가 있는 것과 버퍼가 없는 것으로 나뉜다.

C++ 표준안은 ''버퍼가 있는 입출력'' ( = stream) 만 정의한다.

ios, iostream, fstream  등이 C++ 표준안에서 정의된 입출력 스트림.



### basic_ios

basic_ios, basic_iostream, basic_fstream 등등은 C++ 03 부터 정의된 입출력 스트림으로, 다국어 호환성을 위해 1바이트 char 이상을 읽고 쓸 수 있게 만든 입출력 스트림이다.

`basic_`이 붙은 클래스들은 템플릿으로 선언되어 사용자가 specialization해서 사용해야 한다.

기존의 ios 클래스등의 입출력 스트림은 char 타입으로 구체화된 클래스로 typedef되어 기존 코드와의 호환성을 유지한다.

그러니 기존의 ios 클래스를 써도 딱히 문제는 없음.

```cpp
typedef basic_iostream<char, char_traits<char>> iostream;
```



### 출력 스트림

출력 스트림에 문자, 또는 문자열 넣기

```cpp
std::cout.put('A');
std::cout.write(str, 5); // str 배열의 앞에서부터 5글자
```

출력 버퍼에 있는 내용을 강제로 출력하고 버퍼 비우기

```cpp
std::cout.flush();
```



### 입력 스트림

한글자(char 1개) 읽기  (1byte 이상을 사용하는 한글 등 유니코드 문자는 읽기 불가능)

```
int get()  // 입력 스트림에서 문자(공백문자 포함)를 읽거나 또는 -1(EOF) 리턴 
istream& get(char& ch) // 한글자 읽기 (char 참조 타입을 인자로 받음)
```

입력 스트림이 없으면 입력 스트림이 들어올 때까지 대기함.

입력 스트림은 엔터를 쳐야 들어감.



여러글자 읽기 (중간에 'delim'을 만나면 지정된 개수를 못채워도 리턴)

```cpp
// 문자열의 끝에 /0을 포함하여 길이 n만큼 읽기 (즉, 입력된 문자 n-1개)
istream& get(char* s, int n, char delim='/n');
// get과 동일하지만 delim 문자를 입력 버퍼에서 제거함
istream& getline(char* s int n, char delim='/n');
```



리턴 타입이 istream& 타입인 함수들은 체인해서 사용이 가능함

```cpp
cin.get(ch1).get(ch2).get(ch3);
```



입력 버퍼에 있는 내용을 받지 않고 지우기

```cpp
// n개의 문자를 입력버퍼에서 삭제, delim을 만났을 경우 delim을 입력 버퍼에서 제거하고 즉시 리턴
cin.ignore(int n=1, int delim=EOF); 
```

특히 get() 등의 함수가  '/n' (delim으로 설정된 문자)을 만나거나 하는 경우 바로 리턴하지만 버퍼의 '/n'을 지우지는 않아서 문제가 생길 수 있으므로 그러한 경우 `cin.ignore()` 사용 필요



`get()`은 읽기 도중 오류가 발생하거나 EOF(end of file / ctrl + z)를 만나면 배열에 '/0'를 삽입하고 리턴.



### 입출력 플래그

```cpp
long setf(long flags);
long unsetf(longflags);
```

위 두 함수를 사용하여 입출력 포멧을 제어할 수 있음. (= 옵션 설정)

몇가지 플래그 예시. (플래그는 `|` (or) 연산자로 합칠 수 있음)

```
ios::skipws  // 입력 시 공백문자 무시
ios::unitbuf // 출력 시 버퍼링 거치지 않고 바로 출력
ios::uppercase // 16진수의 a~f나 지수 표현의 e를 대문자로
ios::showbase // 16진수면 0x, 8진수면 0을 앞에 붙여서 출력
ios::showpoint // 소수점 이하의 0 생략 안함
ios::showpos // 양수일 때 +기호 생략 안함
ios::left	// 좌로 정렬해서 출력
ios::internal  // 부호는 왼쪽, 숫자는 오른쪽 정렬하여 출력
ios::hex // 16진수로 출력
ios::boolalpha // true를 "1"이 아니라 "true"로 출력
```



### 포맷 함수 활용

```cpp
int width(int minwidth);		// 출력되는 필드의 최소 너비를 설정하고 기존 설정값 리턴
char fill(char cFill);			// 필드의 빈칸을 지정된 문자로 채우고 기존 설정값 리턴
int precision(int np);			// 유효자리 숫자 자리수를 설정. 소숫점 아래 숫자 갯수가 아님에 주의
```



### 스트림 조작자 (manipulator)

cin이나 cout 등에 <<, >> 연산자와 함께 사용되며, 특별한 기능을 지닌 함수

```cpp
// 매개 변수가 없는 조작자는 <iostream>에 정의되어있음
endl	// 출력 버퍼의 내용을 전부 출력하고 개행
oct, dec, hex	// 정수 필드를 n진수 기반으로 출력
left, right		// 좌우로 정렬
flush			// 출력 버퍼의 내용을 강제 출력
showbase, noshowbase		// 숫자 앞에 8진수(0)나 16진수(0x) 표시 출력 / 출력 안함
boolalpha		// true를 '1'이 아니라 "true"로 출력

skipws, noskipws			// 입력 스트림에서 공백문자를 읽지 않고 건너뜀 / 취소
```

사용 예시

```cpp
cout << "Hello, world!" << endl;
cout << hex << showbase << 255 << endl;		// 0xff
cin >> skipws >> str;
```

조작자는 함수이기 때문에 매개변수를 가질 수도 있음

```cpp
// 매개 변수가 있는 조작자는 <iomanip>에 정의되어있음.
setioflags(long flags)		// flags에 지정된 플래그 설정
resetioflags(long flags)	// flags에 지정된 플래그 해제
setw(int minw)				// 최소 너비 설정
setfill(char cFill)			// 채우기 문자 설정
setbase(int base)			// 숫자 출력시 사용할 기본 진수를 설정 (10진수, 8진수, 16진수)
setprecision(int np)		// 숫자 출력시 유효숫자 갯수를 설정
```

조작자는 위 플래그 설정함수나 포맷함수들보다 편하게 쓸 수 있지만 대신에 1회용임에 주의할 것.



### '<<'(삽입) , '>>'(추출) 연산자 오버로딩하여 사용자 클래스 입출력

```cpp
ostream& operator << (ostream& stream, Myclass a)
{
    stream << "출력할 내용";
    return stream;
}
istream& operator >> (istream& stream, Myclass& a)
{
    stream >> a.(입력할 멤버);
    return stream;
}
```



### 사용자 커스텀 조작자 

`endl`과 같은 조작자를 사용자가 직접 원하는 대로 만들 수도 있다.

```
cout << manip; // 이 문장은 아래와 같이 해석된다.
cout.<< (manip);  // 여기서 << 연산자(함수)의 원형을 살펴보면 아래와 같이 함수 포인터를 사용해서 함수를 인자로 받는 함수임을 알 수 있다.
ostream& ostream::operator << (ostream& (*_f)(ostream&)) 
{
	(*_f)(*this); // 그리고 << 연산자의 본문에서 함수포인터로 받은 함수에 *this를 인자로 넣어 실행한다.
	return *this; // this는 cout 객체의 주소
}

그러므로...

istream& myManipulator(istream& ins)		// 매개변수가 없는 조작자 원형
ostream& myManipulator(ostream& outs)

위 두개의 원형으로 새로운 조작자를 선언하면 사용자 커스텀 조작자를 만들 수 있다.
```

