#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#define LENGTH_NAME 10
#define LENGTH_PHONE 16

template <class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    //if (newSize < 0)
    //    throw "New length must be >= 0";

    T *temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

class Biscard //명함
{
    //1.1 멤버 변수는 name과 phone이며 문자열 포인터 변수이다.
    char *name;
    char *phone;
    //1.2 생성자를 정의한다. 생성자는 이름과 전화번호를 입력받고 
    //동적 메모리를 할당 받아 저장하여 name과 phone 포인터 변수를 
    //통해 접근할 수 있도록 한다.
public:
    Biscard(char *nameInput, char *phoneInput)
    {
        name = new char[LENGTH_NAME];
        phone = new char[LENGTH_PHONE];
        strcpy(name, nameInput);
        strcpy(phone, phoneInput);
    }
    //Bag의 생성과 크기 확장시 name과 phone입력을 받는 것을 
    //방지하기 위한 추가 생성자

    Biscard()
    {
        name = new char[LENGTH_NAME];
        phone = new char[LENGTH_PHONE];
    }
    //1.3 복사생성자와 대입연산자를 정의한다.
    Biscard(const Biscard &copy)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
        phone = new char[strlen(copy.phone) + 1];
        strcpy(phone, copy.phone);
    }
    Biscard &operator=(const Biscard &a)
    {
        strcpy(name, a.name);
        strcpy(phone, a.phone);
    }
    //1.4 소멸자를 정의하며 동적 메모리를 해제한다.
    ~Biscard()
    {
        delete[] name;
        delete[] phone;
    }
    //1.5 이름과 전화번호를 출력하는 ShowInfo() 멤버함수를 정의한다.
    void ShowInfo()
    {
        cout << "이름: " << name << endl;
        cout << "전화번호: " << phone << endl;
    }
};

//이하 program 3.6

template <class T>
class Bag
{
public:
    //2. 프로그램 3.6에서 Bag 용량(capacity)의 초기값은 10이 아닌 
    //3으로 수정
    Bag(int bagCapacity = 3);
    ~Bag();

    int Size() const; //const 메소드 안에서는 어떤 변수도 바꿀 수 없음
    bool IsEmpty() const;
    T &Element() const;

    void Push(const T &); //T 참조자형 인자, const
    void Pop();

private:
    T *array;
    int capacity;
    int top;
};

//이하 program 3.7
//3. 프로그램 3.7에서 Bag의 생성자, 소멸자, Size(), IsEmpty(), 
//Element(), Push(), Pop() 구현

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
int Bag<T>::Size() const
{
    return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const
{
    if (top == -1)
        return true;
    else
        return false;
}

template <class T>
T &Bag<T>::Element() const
{
    if (IsEmpty())
    {
        throw "Bag is empty, connot show elements";
    }
    srand((unsigned int)time(NULL));
    int elementPos = rand() % (top + 1);
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

//이하 직접 작성
void Push(Bag<Biscard> *cardHolder)
{
    char *nameInput = new char[LENGTH_NAME];
    char *phoneInput = new char[LENGTH_PHONE];
    cout << "이름>>";
    cin >> nameInput;
    cout << "전화번호>>";
    cin >> phoneInput;
    Biscard newBiscard(nameInput, phoneInput);
    cardHolder->Push(newBiscard);
}
int main()
{
    Biscard *b1;
    char *name = new char[LENGTH_NAME];
    char *phone = new char[LENGTH_PHONE];
    Bag<Biscard> *cardHolder = new Bag<Biscard>;

    //4. 빈 Bag에 대해 Size(0), IsEmpty(), Element() 연산 결과 확인
    cout << "\n::빈 Bag에 대한 연산 결과::\n";
    cout << "Size: " << cardHolder->Size() << endl;
    cout << "IsEmpty: " << cardHolder->IsEmpty() << endl;
    cout << "Element:\n";
    try
    {
        Biscard &b2 = cardHolder->Element();
        b2.ShowInfo();
    }
    catch (char const *errcode)
    {
        cout << errcode << endl;
    }
    //5. Push()연산을 3번 수행하여 Bizcard 객체를 3개 추가한 후,
    //Size(), IsEmpty(), Element() 연산 결과 확인
    cout << "\nPush()연산을 3번 수행합니다.\n";
    for (int i = 0; i < 3; i++)
    {
        Push(cardHolder);
    }
    cout << "\n::3번 Push한 Bag에 대한 연산 결과::\n";
    cout << "Size: " << cardHolder->Size() << endl;
    cout << "IsEmpty: " << cardHolder->IsEmpty() << endl;
    cout << "Elemet:\n";
    try
    {
        Biscard &b2 = cardHolder->Element();
        b2.ShowInfo();
    }
    catch (char const *errcode)
    {
        cout << errcode << '\n';
    }
    //여기까지는 잘 됨.

    //6. Push()연산을 4번 수행하여 Bizcard 객체를 총 7개 추가한 후,
    //Size(), IsEmpty(), Element() 연산 결과 확인
    cout<<"\nPush()연산을 4회 추가 수행합니다.\n";
    Push(cardHolder);
    Push(cardHolder);
    Push(cardHolder);
    Push(cardHolder);
    cout << "\n::7번 Push한 Bag에 대한 연산 결과::\n";
    cout << "Size: " << cardHolder->Size() << endl;
    cout << "IsEmpty: " << cardHolder->IsEmpty() << endl;
    cout << "Element:\n";
    try
    {
        Biscard &b2 = cardHolder->Element();
        b2.ShowInfo();
    }
    catch (char const *errcode)
    {
        cout << errcode << endl;
    }
    //7. Pop()연산을 2번 수행하여 Bizcard 객체를 2개 삭제한 후,
    // Size(), IsEmpty(), Element() 연산 결과 확인
    cout << "\nPop()연산을 2번 수행합니다.\n";
    try
    {
        cardHolder->Pop();
        cardHolder->Pop();
    }
    catch (char const *errcode)
    {
        cout << errcode << endl;
    }
    cout << "\n::2번 Pop한 Bag에 대한 연산 결과::\n";
    cout << "Size: " << cardHolder->Size() << endl;
    cout << "IsEmpty: " << cardHolder->IsEmpty() << endl;
    cout << "Element:\n";
    try
    {
        Biscard &b2 = cardHolder->Element();
        b2.ShowInfo();
    }
    catch (char const *errcode)
    {
        cout << errcode << endl;
    }

    cout << "\n\n 프로그램 종료\n";
    return 0;
}