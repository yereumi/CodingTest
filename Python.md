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
name: Yejiii
age: 22
weight: 47.3
print("My name is %s, age: %d, weight: %f"%(name, age, weight))

My name is Yejiii, age: 22, weight: 47.3
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