#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define LENGTH_NAME 10
#define LENGTH_PHONE 16

class Biscard //명함
{
    //1.1 멤버 변수는 name과 phone이며 문자열 포인터 변수이다.
    char *name;
    char *phone;
    //1.2 생성자를 정의한다. 생성자는 이름과 전화번호를 입력받고 동적 메모리를 할당 받아 저장하여 name과 phone 포인터 변수를 통해 접근할 수 있도록 한다.
    Biscard()
    {
        name = new char[LENGTH_NAME];
        phone = new char[LENGTH_PHONE];
        cout << "이름 입력>>";
        cin >> name;
        cout << "전화번호 입력>>";
        cin >> phone;
    }
    //1.3 복사생성자와 대입연산자를 정의한다.
    public Biscard(const Biscard &copy)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
        phone = new char[strlen(copy.phone) + 1];
        strcpy(phone, copy.phone);
    }
    public Biscard &operator=(const Biscard &a)
    {
        strcpy(name, a.name);
        strcpy(phone, a.phone);
    }
    //1.4 소멸자를 정의하며 동적 메모리를 해제한다.
    public ~Biscard()
    {
        delete[] name;
        delete[] phone;
    }
    //1.5 이름과 전화번호를 출력하는 ShowInfo() 멤버함수를 정의한다.
    ShowInfo()
    {
        cout << "이름: " << name << endl;
        cout << "전화번호: " << phone << endl;
    }
};

//program 3.6

template <class T>
class Bag
{
  public:
    //2. 프로그램 3.6에서 Bag 용량(capacity)의 초기값은 10이 아닌 3으로 수정
    Bag(int bagCapacity = 3);
    ~Bag();

    int Size() const; //const 메소드 안에서는 어떤 변수도 바꿀 수 없음
    bool IsEmpty() const;
    T &Element() const;

    void Push(const T &);//T 참조자형 인자, const
    void Pop();

  private:
    T *array;
    int capacity;
    int top;
};

//program 3.7
//3. 프로그램 3.7에서 Bag의 생성자, 소멸자, Size(), IsEmpty(), Element(), Push(), Pop() 구현
template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    if (capacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag() { delete[] array; }

template <class T>
int Bag<T>::Size()
{
    return top+1;
}

template <class T>
bool Bag<T>::IsEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

template <class T>
T& Bag<T>::Element()
{
    if(IsEmpty())
    {
        throw "Bag is empty, connot show elements";
    }
    //srand((unsigned int)time());
    int elementPos = rand()%(top+1);
    return array[elementPos];
}

template <class T>
void Bag<T>::Push(const T &x)
{
    if (capacity == top + 1)
    {
        ChangeSize1D(array, capacity, 2 * capacity);
        capacity *= 2;
    }
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2;
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    // compact array
    array[top--].~T(); // destructor for T
}

int main(){
    Bag<Biscard> cardHolder= new Bag<Biscard>;
    cout<<cardHolder.Size()<<endl;
    cout<<cardHolder.IsEmpty()<<endl;
    cardHolder.Pop();
    cout<<"POP!!"<<endl;
    
    return 0;
}