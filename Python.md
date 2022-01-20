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
>변수 = 값   
> ex) pi = 3.141592

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
name: Yeji Shin
age: 22
weight: 47.3
print("My name is %s, age: %d, weight: %f"%(name, age, weight))

My name is Yeji Shin, age: 22, weight: 47.3
```

#### - f-string
```python
s = 'coffee'
n = 5
print(f"저는 {s}를 좋아합니다. 하루 {n}잔 마셔요.")

저는 coffee를 좋아합니다. 하루 5잔 마셔요. 
``` 
>출처) https://blockdmask.tistory.com/429

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

- 불: 참(True)과 거짓(False) 값만 가질 수 있음
- 비교연산자 ex) ==, !=, <, >, <=, >=
- 논리연산자 ex) not, and, or
- if 조건문 뒤에는 반드시 콜론(:)을 붙여야 함
- 날짜/시간 활용하기

if~else와 elif 구문

- else 구문: if 조건문의 조건이 거짓일 때 실행
- elif 구문: 세 개 이상의 조건을 연결해서 사용
- False로 변환되는 값: None, 0, 0.0, 빈 컨테이너(빈 문자열, 빈 바이트열, 빈 리스트, 빈 튜플, 빈 딕셔너리 등)
- pass: 진짜로 아무것도 안함, 곧 개발하겠음

---

# 3. 반복문

## 1) 리스트와 반복문

- 리스트: 여러 가지 자료를 저장할 수 있는 자료
- [ ] 에 자료(요소)를 쉼표로 구분해서 입력
- 인덱스: [ ] 안에 들어간 숫자 ex) list_a[0]
- 음수 인덱스는 뒤에서부터 선택
- 리스트 연산자: 연결(+), 반복(*), len()
- append(): 리스트 뒤에 요소 추가 ex) 리스트명.append(요소)
- insert(): 리스트의 중간에 요소 추가 ex) 리스트명.insert(위치, 요소)
- del: 리스트의 특정 인덱스에 있는 요소 제거 ex) del 리스트명[인덱스]
- pop(): 제거할 위치에 있는 요소 제거, 매개변수 미입력 시 마지막 요소 제거 ex) 리스트명.pop(인덱스)
- remove(): 값으로 제거 ex) 리스트.remove(값)
- clear(): 리스트 내부의 요소 모두 제거 ex) 리스트.clear()
- in/not in 연산자: 특정 값이 리스트 내부에 있는지 확인 ex) 값 in/not in 리스트
- for 반복문 ex) for 반복자 in 반복할 수 있는 것: 코드

## 2) 딕셔너리와 반복문

- 딕셔너리: 키를 기반으로 값을 지정하는 것

![20220118_185704.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1795ba6-e850-4f14-bf81-3117623614d1/20220118_185704.jpg)

- 딕셔너리 출력 ex) dict_a, dict_a[”name”]
- 딕셔너리에 값 추가: 딕셔너리[새로운 키] = 새로운 값
- 딕셔너리에 값 제거: del 딕셔너리[키]
- in 키워드:  딕셔너리 내부에 키가 있는지 없는지 확인
- get(): 존재하지 않는 키에 접근, 존재하지 않으면 None 출력 ex) 딕셔너리.get(키)
- for 반복문 ex) for 키 변수 in 딕셔너리: 코드

반복문과 while 반복문

- range(A): 0부터 A-1까지
- range(A, B): A부터 B-1까지
- range(A, B, C): A부터 B-1까지 C만큼
- 리스트 안에 범위: list(range(10)) ex) [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- for 반복문 ex) for 숫자 변수 in 범위: 코드
- for 반복문과 리스트 조합 ex) for element in 리스트명
- reversed(): 역반복문 ex) for i in reversed(range(A)): 코드
- while 반복문 ex) while 불 표현식: 문장

![20220119_150847.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a67d40b9-294d-496f-9f0d-cd3fb32b4b74/20220119_150847.jpg)

- Ctrl + C로 강제 종료

![20220119_151232.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8d4b065d-7a68-4c63-9860-81326c2f2d14/20220119_151232.jpg)

![20220119_151311.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f365031f-4034-4050-9b03-5268bb9a173b/20220119_151311.jpg)

- 유닉스 타임: 세계 표준시 ex) import time
- break: 현재 반복문을 벗어날 때 사용
- continue: 현재 반복문을 생략하고, 다음 반복으로 넘어갈 때 사용

- format 함수

[https://blockdmask.tistory.com/424](https://blockdmask.tistory.com/424)