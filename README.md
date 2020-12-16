# COMP312 / 운영체제 / 2020 / 1학기 / 강순주

---

## [HW1_array](HW01_2016113832_윤동준/array.c) / [HW1_LinkedList](HW01_2016113832_윤동준/linkedlist.c)
 
array와 LinkedList를 이용하여, 이름을 입력하면 구조체에 저장되어 있는 문자열인 학번이 출력되고, 학번을 입력하면, 구조체에 저장되어 있는 문자열인 이름이 출력이 되는 프로그램이다. 

---

## HW2
 
#### myShell 프로그램 짜기
#### [Sum.c](HW02_2016113832_윤동준/sum.c), [Subtraction.c](HW02_2016113832_윤동준/sub.c), [Division.c](HW02_2016113832_윤동준/div.c), [Factorial.c](HW02_2016113832_윤동준/fact.c) 함수를 만들어서 argc와 argv[]를 통하여 command창에서 입력을 받아서 원하는 연산을 수행하는 실행파일 [myshell.exe](HW02_2016113832_윤동준/myshell.c)을 만들었다. 

---

## HW3

Argument로 특정 정수를 받아서, 10,000개의 thread를 만들었고, 5000개의 thread에서는 add라는 함수를 실행하였고, 다른 5,000개의 thread에선 sub라는 함수를 실행하였다. 실행한 것을 30번 반복하여 마지막으로 나온 전역변수 first의 값을 출력해보았다.

[CountHun.c](HW03_2016113832_윤동준/HW03_2016113832_윤동준/CountHun.c)
[CountTen.c](HW03_2016113832_윤동준/HW03_2016113832_윤동준/CountTen.c)
[CountThou.c](HW03_2016113832_윤동준/HW03_2016113832_윤동준/CountThou.c)

#### [test.c](HW03_2016113832_윤동준/HW03_2016113832_윤동준/test.c)

## HW3 (B)

과제3에서 thread의 수가 현저히 적어도 race condition이 일어날 수 있음을 확인하고 race condition을 mutex를 사용하여 해결하는 걸 보여준다. 

swap함수를 사용하여 전역 변수를 계속 다른 값에 넣어주고 해서 원래는 create,threadadd, threadsub, join이 실행되고 있는데, swap이란 함수가 들어가게 되면서 우선순위가 바뀌어서이다. 계산이 선점이 되는 확률을 높이면서 쉽게 깨지게 preemption


[Race.c](HW3(B)_2016113832_윤동준/Race.c)
[Race1.c](HW3(B)_2016113832_윤동준/Race1.c)

---

## HW4

Heap영역을 사용하는 코드와 Stack영역을 사용하는 코드를 하나의 실행 프로그램에서 실행시켰을 때, 메모리에서 Heap영역과 Stack영역이 충돌하는 지점을 확인하는 과제이다.

[memory.c](HW04_2016113832_윤동준/memory.c)

---

## HW5

첫번째 과제1번은 user프로그램에서 키보드 입력 A또는 B를 입력받아서 led를 제어하는 프로그램을 만들었고, 

과제2번은 led_module를 수정하여 회로 내에서 switch를 누르면 그 값을 device driver에 저장하여 LED를 키게 하였다.

#### hw5-1

[led_module.c](HW05_2016113832_윤동준/HW5-1/led_module.c)
[main.c](HW05_2016113832_윤동준/HW5-1/main.c)

#### hw502

[led_module.c](HW05_2016113832_윤동준/HW5-2/led_module.c)
[main.c](HW05_2016113832_윤동준/HW5-2/main.c)