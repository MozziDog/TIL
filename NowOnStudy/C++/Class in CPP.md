# C++ 클래스

Java 또는 C#의 클래스와 다른 점을 중점으로



### 클래스 선언 & 접근 지정자

클래스 선언부가 끝나고 괄호를 닫을 때 세미콜론 써주어야 함. 근데 각 함수의 구현에는 중괄호 닫은 후에 세미콜론 안써도 됨. 이건 아무래도 class가 struct를 확장해서 만든 문법이라 그런 듯.

C++의 접근 지정자는 다른 언어에서 함수나 필드 하나하나에 선언해주는 것과 다르게 블록 단위로 지정한다는 특이점이 있다.

```cpp
class MyClass
{
private:
    void foo();
public:
    void bar();
};
```

물론 아래도 가능하기야 하겠다만 가능하면 C++ 스타일을 존중하도록 하자

```cpp
class foo
{
public: void function1();
public: void function2();
private: void function3();
};
```







### 선언부와 구현부의 분리

C++은 기본적으로 클래스의 선언부와 구현부가 분리되어 있다.

```cpp
//선언부
class MyClass
{
public:
    void function1();
    void function2();
};

// 구현부
void MyClass::function1()
{
    //...
}
```

또한, 특정 파일에서 선언된 클래스를 다른 파일에서 사용하려면 각각 include해줘야 함.

(C#에서 같은 프로젝트 내부에 있는 파일들의 클래스는 그냥 쓸 수 있는 것과 대조되는 부분)

이 때, cpp파일을 그냥 include 한다면 include한 모든 파일에서 구현부가 중복으로 등장하게 되므로, 프로그램의 크기도 커지고 링크 시 오류도 발생할 수 있음. 따라서 **헤더 파일과 소스 파일로 구분하여 선언부와 구현부를 분리함**

```cpp
// Circle.h
class Circle
{
private:
    int radius;
public:
    Circle();
    Circle(int r);
}
```

```cpp
// Circle.cpp
Circle::Circle()  // 생성자는 return type을 명시하지 않는다.
{
    radius = 1;
}
Circle::Circle(int r)
{
    radius = r;
}
```

이러면 헤더 파일만 가져다가 다양한 곳에서 include할 수 있고, 구현부는 링커에 의해 컴파일 과정에서 자연스럽게 한번만 포함되게 됨.

또한, 상호참조로 인해 서로가 서로를 include하는 사태가 발생하는 걸 방지하기 위해서도 선언부와 구현부를 분리해야 함.

([[C++] 클래스 상호 참조 해결 방법 : 네이버 블로그](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hyungjungkim&logNo=60202456568))

### 중복 include시 발생하는 문제의 해결

> 시나리오 A: a.h파일에서 b.h를 include하고 c.cpp에서 a.h와 b.h를 둘 다 include함.

위 시나리오를 보면, 중복으로 include를 하는 상황은 종종 발생함을 알 수 있음. 이럴 경우 전처리기를 지났을 때 코드가 이미 선언된 클래스를 다시금 선언하는 꼴이 됨. 꼼꼼이 확인하면 저런 문제를 없앨 수 있겠지만 아예 저런 문제가 발생하지 않도록 하는 방법도 있음.

```cpp
// 문제가 되는 상황
#include <Circle.h>
#include <Circle.h>
#include <Circle.h>
```

**조건부 컴파일**을 사용하면 위 문제를 해결할 수 있다.

```cpp
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H
// define문에서 사용하는 상수 이름은 다른 상수와 중복을 방지하기 위해 클래스 이름으로 하는 것이 좋다.
class Circle
{
    ...
}

#endif
```

위와같이 헤더파일에서 선언부를 전처리 지시문을 사용하여 감싸주면 여러번 include되어도 전처리 지시문으로 인하여 클래스가 한번만 선언되게 되므로 중복 include 시 발생하는 문제를 해결할 수 있다.


