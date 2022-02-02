*혼자 공부하는 파이썬을 참고하여 정리했습니다*

# 1. 자료형

## 1) 자료형과 문자열

### (1) 자료형과 기본 자료형
- 문자열(string): 메일 제목, 메시지 내용 등 ex) "안녕하세요" 
- 숫자(number): 물건의 가격, 학생의 성적 등 ex) 52, 273, 103.32
- 불(boolean): 친구의 로그인 상태 등 ex) True, False
- 자료형(data type): 자료의 형식

### (2) 문자열 만들기
이스케이프 문자: 역슬래시(\) 기호와 함께 조합해서 사용하는 특수한 문자   
ex) \”: 큰 따옴표, \’: 작은 따옴표, \n: 줄바꿈, \t: 탭, \\: 역슬래시(\)

```python
print("""동해물과 백두산이 마르고 닳도록
하느님이 보우하사 우리나라 만세
무궁화 삼천리 화려강산
대한사람 대한으로 길이 보전하세""")

동해물과 백두산이 마르고 닳도록   
하느님이 보우하사 우리나라 만세   
무궁화 삼천리 화려강산   
대한사람 대한으로 길이 보전하세
```

### (3) 문자열 연산자
>문자열 연결 연산자: +   
> 문자열 반복 연산자: *    
> 문자 선택 연산자(인덱싱): []   
> 문자열 범위 선택 연산자(슬라이싱): [:]   
> 문자열 길이 구하는 함수: len()

## 2) 숫자

### (1) 숫자 연산자
정수(int), 실수(floating point)
 >정수 나누기 연산자: //   
 > 나머지 연산자: %   
 > 제곱 연산자: **

## 3) 변수와 입력

### (1) 변수 만들기/사용하기
변수 = 값   
ex) pi = 3.141592

### (2) 복합 대입 연산자
기존의 연산자와 조합해서 사용
>+=, -=, *=, /=, %=, **=

### (3) 사용자 입력: input()
사용자 입력(프롬프트 문자열): input()   
input() 함수는 무조건 문자열 자료형

### (4) 문자열을 숫자로, 숫자를 문자열로 바꾸기
>int(): 문자열 → int   
> float(): 문자열 → float   
> str(): 숫자 → 문자열

## 4) 숫자와 문자열의 다양한 기능

### (1) 문자열의 format() 함수
format()을 이용하여 숫자와 문자를 다양한 형태로 출력   
{}가 매개변수보다 많으면 Index Error

```python
string_a = "{}".format(10)
print(string_a)
print(type(string_a))

10   
<class 'str'>
```

#### cf) 또다른 포매팅(formating) 방법
#### - %
```python
name: Yeziii
age: 22
weight: 47.3
print("My name is %s, age: %d, weight: %f"%(name, age, weight))

My name is Yeziii, age: 22, weight: 47.3
```

#### - f-string
```python
s = 'coffee'
n = 5
print(f"저는 {s}를 좋아합니다. 하루 {n}잔 마셔요.")

저는 coffee를 좋아합니다. 하루 5잔 마셔요. 
``` 
출처) https://blockdmask.tistory.com/429

### (2) 대소문자 바꾸기: upper()와 lower()
upper(): 문자열의 알파벳을 대문자로    
lower(): 문자열의 알파벳을 소문자로

```python
a = "Hello World!"
print(a.upper())
print(a.lower())

HELLO WORLD!   
hello wolrd!
```

### (3) 문자열 양옆의 공백 제거하기
strip(): 문자열 양옆의 공백 제거

```python
input_a = """
     안녕하세요
문자열의 함수를 알아봅니다
"""
print(input_a)
print(input_a.strip())

     안녕하세요
문자열의 함수를 알아봅니다

안녕하세요
문자열의 함수를 알아봅니다
```

### (4) 문자열 찾기: find()와 rfind()
find(): 왼쪽부터 찾아서 처음 등장하는 위치 확인
rfind(): 오른쪽부터 찾아서 처음 등장하는 위치 확인

```python
output_a = "안녕안녕하세요".find("안녕")
output_b = "안녕안녕하세요".find("안녕")
print(output_a)
print(output_b)

0
2
```

### (5) 문자열 in 연산자
in 연산자: 문자열 내부에 어떤 문자열이 있는지 확인
```python
print("안녕" in "안녕하세요")
print("잘자" in "안녕하세요")

True   
False
```

### (6) 문자열 자르기: split()
split(): 문자열울 특정한 문자로 자름
```python
a = "10 20 30 40 50".split(" ")
print(a)

['10', '20', '30', '40', '50']
```
---

# 2. 조건문

## 1) 불 자료형과 if 조건문

### (1) 불 만들기: 비교 연산자, 논리 연산자
불: 참(True)과 거짓(False) 값만 가질 수 있음
>비교 연산자 ex) ==, !=, <, >, <=, >=    
> 논리 연산자 ex) not, and, or   

### (2) if 조건문이란?
```python
if 불 값이 나오는 표현식:
    불 값이 참일 때 실행할 문장
```

if 조건문 뒤에는 반드시 콜론(:)을 붙여야 함

### (3) 날짜/시간 활용하기
```python
import datetime   #모듈을 이용
now = datetime.datetime.now()
print(now.year, "년")
print(now.month, "월")
print(now.day, "일")
print(now.hour, "시")
print(now.minute, "분")
print(now.second, "초")

2022년
1 월
22 일
00 시
15 분
43 초
```

## 2) if~else와 elif 구문

### (1) else, elif 구문
else 구문: if 조건문의 조건이 거짓일 때 실행    
elif 구문: 세 개 이상의 조건을 연결해서 사용

### (2) False로 변환되는 값
None, 0, 0.0, 빈 컨테이너(빈 문자열, 빈 바이트열, 빈 리스트, 빈 튜플, 빈 딕셔너리 등)

### (3) pass 키워드
pass: 진짜로 아무것도 안함, 곧 개발하겠음

---

# 3. 반복문

## 1) 리스트와 반복문

### (1) 리스트 선언하고 요소에 접근하기
리스트(list): 여러 가지 자료를 저장할 수 있는 자료  
요소(element): 대괄호[ ] 내부에 넣는 자료
인덱스: [ ] 안에 들어간 숫자 
```python
list_a[0]
```
음수 인덱스는 뒤에서부터 선택

### (2) 리스트 연산자: 연결(+), 반복(*), len()

### (3) 리스트에 요소 추가하기: append, insert
append(): 리스트 뒤에 요소 추가   
insert(): 리스트의 중간에 요소 추가
```python
리스트명.append(요소)
리스트명.insert(위치, 요소)
```

### (4) 리스트에 요소 제거하기
- 인덱스로 제거하기
>del: 리스트의 특정 인덱스에 있는 요소 제거   
> pop(): 제거할 위치에 있는 요소 제거, 매개변수 미입력 시 마지막 요소 제거
```python
del 리스트명[인덱스]
리스트명.pop(인덱스)
```

- 값으로 제거하기 
>remove(): 값으로 제거
```python
리스트.remove(값)
```

- 모두 제거하기
>clear(): 리스트 내부의 요소 모두 제거
```python
리스트.clear()
```

### (5) 리스트 내부에 있는지 확인하기: in/not in 연산자
in/not in 연산자: 특정 값이 리스트 내부에 있는지 확인 
```python
값 in/not in 리스트
```

### (6) for 반복문
```python
for 반복자 in 반복할 수 있는 것: 
    코드
```

## 2) 딕셔너리와 반복문

### (1) 딕셔너리 선언하기 
딕셔너리: 키를 기반으로 값을 지정하는 것
```python
dict_a = {
    "name": "어벤져스 엔드게임",
    "type": "히어로 무비"
}
```

### (2) 딕셔너리 요소에 접근하기
```python
print(dict_a)

{'name': '어벤져스 엔드게임', 'type': '히어로 무비'}
```

### (3) 딕셔너리에 값 추가하기/제거하기
```python
딕셔너리[새로운 키] = 새로운 값   #추가
del 딕셔너리[제거할 키]   #제거
```

### (4) 딕셔너리 내부에 키가 있는지 확인하기
in 키워드:  딕셔너리 내부에 키가 있는지 없는지 확인    
get(): 존재하지 않는 키에 접근, 존재하지 않으면 None 출력
```python
if key in dicionary:
    print(dictionary[key])
    
딕셔너리.get(키)
```
### (5) for 반복문 
```python
for 키 변수 in 딕셔너리:
    코드
```

## 3) 반복문과 while 반복문

### (1) 범위
>range(A): 0부터 A-1까지    
> range(A, B): A부터 B-1까지    
> range(A, B, C): A부터 B-1까지 C만큼    
> 리스트 안에 범위: list(range(10)) ex) [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

### (2) for 반복문 
```python
for 숫자 변수 in 범위:
    코드
```

### (3) for 반복문과 리스트 조합 
```python
for element in 리스트명:
    코드
```

### (4) for 반복문: 반대로 반복하기
reversed(): 역반복문 
```python
for i in reversed(range(A)):
    코드
```

### (5) while 반복문 
```python
while 불 표현식:
    문장
```
```python
while True:
    print(".", end = "")   
    #end가 "\n"이라 줄바꿈이 일어나는데 빈 문자열 ""로 바꿔서 줄바꿈이 일어나지 않게 함
```
무한 반복될 경우 Ctrl + C로 강제 종료

### (6) while 반복문: for 반복문처럼 사용하기
```python
i = 0
while i <3:
    print("{}번째 반복입니다.".format(i))
    i += 1

0번째 반복입니다.
1번째 반복입니다.
2번째 반복입니다.
```

### (7) while 반복문: 상태를 기반으로 반복하기
```python
list_test = [1, 2, 1, 2]
value = 2
while value in list_test:
    list_test.remove(value)
print(list_test)

[1, 1]
```

### (8) while 반복문: 시간을 기반으로 반복하기
유닉스 타임: 세계 표준시
```python
import time
```

### (9) while 반복문: break 키워드/continue 키워드
break: 현재 반복문을 벗어날 때 사용   
continue: 현재 반복문을 생략하고, 다음 반복으로 넘어갈 때 사용

## 4) 문자열, 리스트, 딕셔너리와 관련된 기본 함수

### (1) 리스트에 적용할 수 있는 기본 함수: min(), max(), sum()
min(): 리스트 내부에서 최솟값을 찾음    
max(): 리스트 내부에서 최댓값을 찾음    
sum(): 리스트 내부에서 값을 모두 더함

### (2) reversed() 함수로 리스트 뒤집기
reversed(): 리스트에서 요소의 순서를 뒤집고 싶을 때 사용
```python
numbers = [1, 2, 3, 4, 5]
for i in reversed(numbers): 
    print("첫 번째 반복문: {}".format(i))
#reversed() 함수와 반복문을 조합할 때는 반복문 구문 내부에 reversed 함수를 곧바로 넣어 사용함

첫 번째 반복문: 5
첫 번째 반복문: 4
첫 번째 반복문: 3
첫 번째 반복문: 2
첫 번째 반복문: 1
```

### (3) enumerate() 함수와 반복문 조합하기
```python
example_list = ["요소A", "요소B", "요소C"]
for i, value in enumerate(example_list)):   #enumerate() 함수를 사용하면 반복 변수를 이런 형태로 넣을 수 있음
    print("{}번째 요소는 {}입니다."format(i, value))

0번째 요소는 요소A입니다.
1번째 요소는 요소B입니다. 
2번째 요소는 요소C입니다.
```

### (4) 리스트 내포
```python
리스트 이름 = [표현식 for 반복자 in 반복할 수 있는 것]
```
```python
array = [i * i for i in range(0, 20, 2)]
#최종 결과를 앞에 작성
print(array)

[0, 4, 16, 36, 64, 100, 144, 196, 256, 324]
```

```python
리스트 이름 = [표현식 for 반복자 in 반복할 수 있는 것 if 조건문]
```
```python
array = ["사과", "자두", "초콜릿", "바나나", "체리"]
output = [fruit for fruit in array if fruit != "초콜릿"]
print(output)

['사콰', '자두', '바나나', '체리']
```

#### cf) 문자열의 join() 함수
```python
문자열.join(문자열로 구성된 리스트)
```
```python
print("::".join(["1", "2", "3", "4", "5"]))

1::2::3::4::5
```

#### cf) 이터레이터
이터러블(iterable): 반복할 수 있는 것
```python
for 반복자 in 반복할 수 있는 것
```
```python
numbers = [1, 2, 3, 4, 5]
r_num = reversed(numbers)
print(next(r_num))
print(next(r_num))
print(next(r_num))
print(next(r_num)) 

5
4
3
2

```

# 4. 함수

## 1) 함수 만들기

### (1) 함수의 기본 
```python
def 함수 이름():
    문장
```
```python
def print_3_times():
    print("안녕하세요")
    print("안녕하세요")
    print("안녕하세요")
print_3_times()

안녕하세요
안녕하세요
안녕하세요
```

### (2) 함수에 매개변수 만들기
```python
def 함수 이름(매개변수, 매개변수, ...):
    문장
```
```python
def print_n_times(value, n):
    for i in range(n):
        print(value)
print_n_times("안녕하세요", 5)

안녕하세요
안녕하세요
안녕하세요
안녕하세요
안녕하세요
```
매개변수의 개수는 꼭 맞춰줘야 함

### (3) 가변 매개변수
가변 매개변수: 매개변수를 원하는 만큼 받을 수 있는 함수
```python
def 함수 이름(매개변수, 매개변수, ..., *가변 배개변수):
    문장
```
- 가변 매개변수 뒤에는 일반 매개변수가 올 수 없음
- 가변 매개변수는 하나만 사용 가능
```python
def print_n_times(n, *values):
    for i in range(n):
        for value in values:
            print(value)
        print()
print_n_times(2, "안녕하세요", "즐거운", "파이썬 프로그래밍")

안녕하세요
즐거운
파이썬 프로그래밍

안녕하세요
즐거운
파이썬 프로그래밍
```

### (4) 기본 매개변수
기본 매개변수: 매개변수를 입력하지 않았을 경우 매개변수에 들어가는 기본값
- 기본 매개변수 뒤에는 일반 매개변수가 올 수 없음
```python
def print_n_times(value, n=2)   #n=2가 기본 매개변수
    for i in range(n):
        print(value)
print_n_times("안녕하세요")

안녕하세요 
안녕하세요
```

### (5) 키워드 매개변수
- 기본 매개변수가 가변 매개변수보다 앞에 올 때
```python
def print_n_times(n=2, *values):
    for i in range(n):
        for value in values:
            print(value)
        print()
print_n_times("안녕하세요", "즐거운", "파이썬 프로그래밍")

오류 발생
#기본 매개변수는 가변 매개변수 앞에 써도 의미 없음
```

- 가변 매개변수가 기본 매개변수보다 앞에 올 때
```python
def print_n_times(*value, n=2):
    for i in range(n):
        for value in values:
            print(value)
        print()
print_n_times("안녕하세요", "즐거운", "파이썬 프로그래밍", 3)

안녕하세요
즐거운
파이썬 프로그래밍
3

안녕하세요
즐거운
파이썬 프로그래밍
3
```

- 키워드 매개변수: 매개변수 이름을 지정해서 입력하는 매개변수
```python
def print_n_times(*value, n=2):
    for i in range(n):
        for value in values:
            print(value)
        print()
print_n_times("안녕하세요", "즐거운", "파이썬 프로그래밍", n=3)
#n=3이 키워드 매개변수
#n=2라는 기본 매개변수에 키워드 매개변수를 지정하여 새로운 인자를 줌

안녕하세요
즐거운
파이썬 프로그래밍

안녕하세요
즐거운
파이썬 프로그래밍

안녕하세요
즐거운
파이썬 프로그래밍
```

### (6) 리턴
- 자료 없이 리턴하기   
return 키워드를 만나는 순간 함수 종료
```python
def return_test():
    print("A 위치입니다.")
    return  
    print("B 위치입니다.")
return_test()

A 위치입니다.
```

- 자료와 함께 리턴하기
```python
def return_test():
    return 100
value = return_test()
print(value)

100
```

- 아무것도 리턴하지 않기    
None 출력
```python
def return_test()
    return  
value = return_test()
print(value)

None
```

### (7) 기본적인 함수의 활용
```python
def 함수(매개변수):
    변수 = 초깃값
    여러 가지 처리
    return 변수
```
```python
def sum_all(start=0, end=100, step=1):
    output = 0
    for i in range(start, end+1, step):
        output += i
        return output
print("A. ", sum_all(0, 100, 10))
print("B. ", sum_all(end=100))
print("C. ", sum_all(end=100, step=2))

A. 550
B. 5050
C. 2550
```

## 2) 함수의 활용

### (1) 재귀 함수
팩토리얼: n! = n * (n-1) * (n-2) * ... * 1    
- 반복문으로 팩토리얼 구하기
```python
def factorial(n):
    output = 1
    for i in range(1, n+1):
        output *= i
    return output
print("3!:", factorial(3))

3! = 6
```

- 재귀 함수로 팩토리얼 구하기
```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
print("3!:". factorial(3))

3! = 6
```

### (2) 재귀 함수의 문제
피보나치 수열
```python
def fibonacci(n):
    if n == 1:
        return 1
    if n == 2:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
print("fibonacci(1):", fibonacci(1))
print("fibonacci(2):", fibonacci(2))
print("fibonacci(3):", fibonacci(3))
print("fibonacci(4):", fibonacci(4))
print("fibonacci(5):", fibonacci(5))

fibonacci(1): 1
fibonacci(2): 1
fibonacci(3): 2
fibonacci(4): 3
fibonacci(5): 5
```
트리(tree) - 노드(node) -  리프(leaf)

global 키워드: 함수 내부에서 함수 외부에 있는 변수를 참조할 때 사용
```python
global 변수 이름
```

메모(memo): 딕셔너리를 사용해서 한 번 계산한 값을 저장하는 것
```python
dictionary = {
    1: 1, 
    2: 1
}
def fibonacci(n):
    if n in dictionary:
        return dictionary[n]
    else:
        output = fibonacci(n-1) + fibonacci(n-2)
        dictionary[n] = output
        return output
```

### (3) 조기 리턴
```python
def fibonacci(n):
    if n in dictionary:
        return dictionary[n]
    output = fibonacci(n-1) + fibonacci(n-2)
    dictionary[n] = output
    return output
```

### (4) 코드에 이름 붙이기
가독성 때문에 함수를 많이 사용함

1. 주석 사용하기
2. 함수 활용하기

### (5) 코드 유지보수
```python
def get_circumference(radius):
    return 2 * 3.14 * radius
def get_circle_area(radius):
    return 3.14 * radius * radius
#3.14를 pi로 설정해주면 나중에 유지보수를 하기 편함
```

## 3) 함수 고급

### (1) 튜플 
튜플: 한번 결정된 요소를 바꿀 수 없는 자료형
```
(데이터, 데이터, 데이터, ...)
```
```python
tuple_test = (10, 20, 30)
print(tuple_test[1])

20
```

요소를 하나만 가지는 튜플
```python
(273) (X)   #273이란 숫자를 괄호로 감싼 것으로 인식
(273, ) (O)
```

리스트와 튜플은 할당 구문으로 사용 가능
```python
[a, b] = [10, 20]
(c, d) = (10, 20)
print("a:", a)
print("b:", b)
print("c:", c)
print("d:", d)

a: 10
b: 20
c: 10
d: 20
```

튜플은 괄호를 생략할 수 있음
```python
tuple_test = 10, 20, 30, 40
print("tuple_test:", tuple_test)

tuple_test: (10, 20, 30, 30)
```
```python
a, b = 10, 20
a, b= b, a   #값 교환
print("a:", a)
print("b:", b)

a: 20
b: 10
```

튜플과 함수
```python
def test():
    return (10, 20)
a, b = test()
print("a:", a)
print("b:", b)

a: 10
b: 20
```

### (2) 람다
함수의 매개변수로 함수 전달하기
```python
#매개변수로 받은 함수를 3번 호출하는 함수
def call_3_times(func):
    for i in range(3):
            func()
def print_hello():
    print("안녕하세요")
call_10_times(print_hello)

안녕하세요
안녕하세요
안녕하세요
```

map() 함수: 리스트의 요소를 함수에 넣고 리턴값으로 새로운 리스트를 구성해 주는 함수    
filter() 함수: 리스트의 요소를 함수에 넣고 리턴된 값이 True인 것으로, 새로운 리스트를 구성해주는 함수
```python
map(함수, 리스트)
filter(함수, 리스트)
```
```python
#함수 선언
def power(item):
    retunr item * item
def under_3(item):
    return item < 3
#변수 선언
list_input_a = [1, 2, 3, 4, 5]
#map() 함수 사용
output_a = map(power, list_input_a)
print("map(power, list_input_a):", output_a)
print("map(power, list_input_a):", list(output_a))
print()
#filter() 함수 사용
output_b = filter(under_3, list_input_a)
print("filter(under_3, list_input_a):", output_b)
print("filter(under_3, list_input_a):", list(output_b))

map(power, list_input_a): <map object at 0x03862270>
map(power, list_input_a): [1, 4, 9, 16, 25]

filter(under_3, list_input_a): <filter object at 0x03862290>
filter(under_3, list_input_a): [1, 2]
# <map object>, <filter object>: 제너레이터(generator)
```
제너레이터: 이터레이터를 직접 만들 때 사용하는 코드

람다: 간단한 함수를 쉽게 선언하는 방법
```python
lambda 매개변수: 리턴값
```
```python
#함수 선언
power = lambda x: x * x
under_3 = lambda x: x < 3
#변수 선언
list_input_a = [1, 2, 3, 4, 5]
#map() 함수 사용
output_a = map(power, list_input_a)
print("map(power, list_input_a):", output_a)
print("map(power, list_input_a):", list(output_a))
print()
#filter() 함수 사용
output_b = filter(under_3, list_input_a)
print("filter(under_3, list_input_a):", output_b)
print("filter(under_3, list_input_a):", list(output_b))

map(power, list_input_a): <map object at 0x03862270>
map(power, list_input_a): [1, 4, 9, 16, 25]

filter(under_3, list_input_a): <filter object at 0x03862290>
filter(under_3, list_input_a): [1, 2]
```
```python
#변수 선언
list_input_a = [1, 2, 3, 4, 5]
#map() 함수 사용
output_a = map(lambda x: x * x, list_input_a)
print("map(power, list_input_a):", output_a)
print("map(power, list_input_a):", list(output_a))
print()
#filter() 함수 사용
output_b = filter(lambda x: x < 3, list_input_a)
print("filter(under_3, list_input_a):", output_b)
print("filter(under_3, list_input_a):", list(output_b))

map(power, list_input_a): <map object at 0x03862270>
map(power, list_input_a): [1, 4, 9, 16, 25]

filter(under_3, list_input_a): <filter object at 0x03862290>
filter(under_3, list_input_a): [1, 2]
```

매개변수가 여러 개인 람다
```python
lambda x, y: x * y
```

### (3) 파일 처리
파일 열고 닫기
- open() 함수
```python
파일 객체 = open(문자열: 파일 경로, 문자열: 읽기 모드)
```
w: write 모드(새로 쓰기 모드)   
a: append 모드(뒤에 이어서 쓰기 모드)   
r: read 모드(읽기 모드)
 
- close() 함수
```python
파일 객체.close()
```
```python
#파일을 엽니다.
file = open("basic.txt", "w")
#파일에 텍스트를 씁니다.
file.write("Hello Python Programming...!")
#파일을 닫습니다.
file.close()
```

with 키워드: 파일을 열고 닫지 않는 실수를 방지
```python
with open(문자열: 파일 경로, 문자열: 모드) as 파일 객체:
    문장
```
```python
#파일을 엽니다.
with open("basic.txt", "w") as file:
    #파일에 텍스트를 씁니다.
    file.write("Hello Python Programming...!")
```

텍스트 읽기
```python
파일 객체.read()
```

텍스트 한 줄씩 읽기    
- CSV, XML, JSON 등이 있음
```python
#랜덤한 숫자를 만들기 위해 가져옵니다.
import random#간단한 한글 리스트를 만듭니다.
hanguls = list("가나다라마바사아자차카타파하")
#파일을 쓰기 모드로 엽니다.
with open("info.txt", "w") as file:
    for i in range(1000):
        #랜덤한 값으로 변수를 생성합니다.
        name = random.choice(hanguls) + random.choice(hanguls)
        weight = random.randrange(40, 100)
        height = random.randrange(140, 200)
        #텍스트를 씁니다.
        file.write("{}, {}, {}\n".format(name, weight, height))

다자, 98, 171
나차, 60, 171
타카, 56, 153
...생략...
```
```python
for 한 줄을 나타내는 문자열 in 파일 객체:
    처리
```
---

# 5. 예외 처리

## 1) 구문 오류와 예외

### (1) 오류의 종류
- 구문 오류(syntax error): 프로그램 실행 전에 발생하는 오류    
- 예외(exception), 런타임 오류(runtime error): 프로그램 실행 중에 발생하는 오류

### (2) 기본 예외 처리
- 조건문을 사용하는 방법
- try 구문을 사용하는 방법

### (3) try except 구문
```python
try:
    예외가 발생할 가능성이 있는 코드
except:
    예외가 발생했을 떄 실행할 코드
```
```python
try:    
    예외가 발생할 가능성이 있는 코드
except:
    pass
```

### (4) try except else 구문
```python
try:
    예외가 발생할 가능성이 있는 코드
except:
    예외가 발생했을 때 실행할 코드
else: 
    예외가 발생하지 않았을 때 실행할 코드
```

### (5) finally 구문
```python
try:
    예외가 발생할 가능성이 있는 코드
except:
    예외가 발생했을 때 실행할 코드
else:
    예외가 발생하지 않았을 때 실행할 코드
finally:
    무조건 실행할 코드
```

- try 구문은 단독으로 사용할 수 없으며, 반드시 except 구문 또는 finally 구문과 함께 사용해야 함
- else 구문은 반드시 except 구문 뒤에 사용해야 함

