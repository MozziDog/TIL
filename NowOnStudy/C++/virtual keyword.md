# 'virtual' keyword in Cpp



1 ) 상속할 때 base 클래스 앞에 붙는 virtual

CPP의 상속 개념은 자바와 많은 차이가 있는데, 몇가지만 나열해보면 다음과 같다.

* CPP에서는 다중 상속이 가능하다.
* CPP에서는 별도의 가상 클래스 또는 인터페이스를 명시하는 방법이 없다.
  * 그냥 가상 함수가 있으면 가상 클래스이다.

다중 상속에서 발생할 수 있는 문제점(예를 들어, 같은 이름의 함수 중복 선언)을 해결하기 위해 CPP에서는 virtual 키워드를 사용한다.

```cpp
class Derived : virtual public Base1, virtual public Base2 // 콤마로 구분
{
    //...
}
```

virtual 키워드를 사용하면 같은 형태의 함수가 상속된다고 하더라도 중복되는 것은 알아서 걸러주기  때문에 다중상속 시 생기는 문제를 해결할 수 있다.

```cpp
// 클래스 선언 형식에서 abstract 클래스인지 표시하는 문법은 없다.
// 그냥 클래스 내에 순수 가상함수가 존재하면 abstract 클래스임
// 필요하다면 추상 클래스는 클래스명에 접두사를 붙여서 표현해야 할 듯
class VirtualClass1 
{
    // 가상함수 : 함수 선언부 앞에 virtual로 선언
    virtual void foo();
    // 순수(pure) 가상함수 : virtual 함수에 구현이 없음을 "=0"로 명시
    virtual void bar() = 0;
}
```

상속된 함수의 동적 바인딩을 활용한 테크닉 : 가상 소멸자

```cpp
class VirtualClass
{
    // 생성자는 가상함수로 선언이 불가능하지만 소멸자는 가능함
    virtual ~VirtualClass()
    {
        ...
    }
}

class DerivedClass
{
    // base class의 소멸자를 virtual로 선언하면 파생클래스의 소멸자로 오버로딩됨.
    ~DerivedClass()
    {
		...
    }
}

int main()
{
	VirtualClass *foo = new DerivedClass(); 
    delete foo; // base 클래스의 포인터로 derived 인스턴스를 delete해도 동적 바인딩으로 인해 알아서 derived 인스턴스의 소멸자가 호출됨.
}
```

단, 소멸자는 상속을 통해 오버라이드될 수 있지만, 생성자는 상속을 통해 오버라이드될 수 없음. 여기서 알 수 있는 것은 소멸자는 다른 함수들과 달리 함수명이 적힌 대로(``~ClassName()``)가 아니라는 것.
