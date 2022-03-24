# 참조

```c++
int n = 2;
int &refn = n;
```

참조는 기존 변수에 이름을 하나 더 붙여서 두개 이상의 이름으로 같은 메모리 공간에 접근할 수 있게 하는 것이다.

위 예시와 같이 &를 변수명 앞에 (= 타입명 뒤에) 붙이고, 선언과 동시에 원본 변수로 초기화함으로 참조 변수를 선언할 수 있다.

C++에서 참조자는 위와 같이 기존 변수에 별명을 붙이기보단 보통 함수의 인자 또는 리턴값으로 쓰인다.



### 참조에 의한 호출

C에서는 Call by value만 가능해서 포인터를 통해 간접적으로 원본 변수에 접근했던 것과 달리 C++에서는 Call by Reference가 가능하다.

```
void swap(int &a, int &b); // 함수 원형에 &를 붙임으로 참조변수임을 나타낸다.

swap(a, b); // 사용할 때에는 다른 언어의 일반적인 Call by Reference 함수처럼 사용하면 된다.
```



만약, 함수의 호출에서 인자 객체를 Call by value로 전달하면 기존 생성자가 아닌 별개의 복사 생성자가 호출되며, 소멸자는 똑같이 호출되는 비대칭 구조가 되어버린다.

```c++
#include <iostream>

class Circle
{
private:
	int radius;
public:
	Circle(int r)
	{
		this->radius = r;
		std::cout << "생성자 호출, r : " << radius << "\n";
	}
	Circle(const Circle& copyc)
	{
		radius = copyc.radius;
		std::cout << "복사 생성자 호출, r : " << radius << "\n";
	}
	void SetRadius(int r)
	{
		this->radius = r;
	}
	~Circle()
	{
		std::cout << "소멸자 호출, r : " << radius << "\n";
	}
};

void foo(Circle c)
{
	c.SetRadius(2);
}

int main()
{
	Circle circle(1);
	foo(circle);
	return 0;
}

// 실행 결과
생성자 호출, r : 1 // 최초 객체의 생성자
복사 생성자 호출, r : 1
소멸자 호출, r : 2
소멸자 호출, r : 1 // 최초 객체의 소멸자
```



그러나, 참조를 활용하면 불필요한 생성자 및 소멸자의 호출을 막을 수 있으며, 복사 생성자를 정의하지 않음으로써 생길 수 있는, 생성자는 호출되지 않았지만 소멸자는 호출되는 상황을 막을 수 있다.

```C++
// 이 위의 코드는 동일
void foo(Circle &c) // <- 참조에 의한 호출로 변경
{
	c.SetRadius(2);
}

int main()
{
	Circle circle(1);
	foo(circle);
	return 0;
}

// 실행 결과
생성자 호출, r : 1
소멸자 호출, r : 2
```



### 참조 리턴

C++은 C와 다르게 함수가 값 뿐만 아니라 참조도 리턴할 수 있다. 이게 무슨 말이냐면, 함수의 리턴값이 변수의 이름처럼 쓰일 수 있다는 말이다.

```C++
char someChar = 'a';
char& find() { return someChar; } // 참조 리턴

int main()
{
	find() = 'b'; // 함수의 리턴값이 변수명처럼 쓰였다.
    std::cout << someChar;
}

// 실행 결과
b
```

다른 예시

```C++
char a = 'a';
char& find() { return a; }

int main()
{
    char b = find(); // char b = 'a'; 와 같은 문장. 
    char &c = find(); // char &c = a; 와 같은 문장. 새 참조자 선언 및 a로 초기화
}
```

