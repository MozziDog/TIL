#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

template <typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}

	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const // const T 참조를 리턴하는 const함수 (멤버 변수를 수정하지 않음)
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index > n)
			return data[index];
		throw "Index out of range";
	}

	size_t size() const
	{
		return n;
	}

	~dynamic_array()
	{
		delete[] data; // 메모리 누수 방지
	}

	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	// friend 전역함수 선언은 사실 이 클래스의 멤버 함수 선언이 아니라 이 함수의 private field에 접근할 수 있는 '전역' 함수 선언임
	friend dynamic_array<T> operator+ (const dynamic_array<T>& arr1, dynamic_array<T>& arr2) 
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
		return result;
	}

	std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";
		std::ostringstream os; // ostringstream은 output string stream인데 주로 string을 합칠 때 많이 사용함.
		os << data[0];
		
		for (int i = 1; i < n; i++)
		{
			os << sep << data[i];
		}
		return os.str();
	}
};

struct student
{
	std::string name;
	int standard;
};

// Q: 이 연산자 오버로딩을 student 구조체 내부에 숨길 수 없을까?
std::ostream& operator<<(std::ostream& os, const student& s)
{
	return (os << "[" << s.name << "," << s.standard << "]");
}


int main()
{
	int nStudents;
	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{ name, standard };
	}

	// 배열 크기보다 큰 인덱스에 접근 실험
	try
	{
		class1.at(nStudents) = student{ "John", 8 };
	}
	catch (...)
	{
		std::cout<<"exception occured!"<<std::endl;
	}
	

	// 깊은 복사 실험
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

	// 두 학급 합치기
	auto class3 = class1 + class2;
	std::cout << "1반 2반 합쳐서 3반 생성" << class3.to_string() << std::endl;

	return 0;
}