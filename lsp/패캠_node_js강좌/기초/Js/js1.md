# 자바스크립트 복습
## 1강
 - 동적언어
 - 자료형 필요없음 , 중간에 바꿔주는 과정이있음 
 - boolean , null , undefined, 등등 
 - 3 = 11(2) 와 같이 이진수 표현도 가능함 

## 2강
- 배열 
- 인덱싱 가능 , js 배열에서는 자료형 상관없이 넣을 수 있다.

## 3강
- 반복문
- while, do while문
- for , 이중 for 문 

## 4강
- 함수
- 함수 표현식과 함수 선언식 
- 객체적 속성, JS는  프로토타입 기반언어임 
- this.속성이름 => 공용변수 => public 변수 
- 함수 내부에서 선언한 변수는 private 변수 

## 5강
- 프로토 타입 
- 만든 함수로 새로운 객체를 만들 수 있고 거기서 프로토타입을 추가하여 사용할 수 있다.
- 기존에 있는 표준객체에도 프로토타입으로 기능 및 속성을 추가 할 수 있다.

## 6강
- 리터럴 객체
- 안에 내용은 맴버
- 다양한 자료형이 들어감  , 기초는 Object

## 7강
- 조건문
- == , === 일때는 타입까지 맞아야함  

## 8강
- 콜백함수 및 클로저
- 인자로 함수를 받아 실행됨
- 클로저 : 함수내부에서 익명함수를 리턴함
- 클로저 : pagenation 처리할때 사용했다함 , 용도에 따라서 어떤 함수를 호출하는데 증가되는 어떠한 공간이 필요하다 싶으면 씀 

## 9강 
- dom controll 
- html 이 동작하고 불러와라 
- DomContentLoaded => html 로드가 됬을때 

## 10강
- jQuery : 요즘에는 생산성이 높지만 , 소스가독성이 떨어짐 요즘 지양하는 추세
- 그래도 한번 배워나 보자 
- jQuery Cdn으로 가져와서 사용 / minified 버전은 공백제거한 조금 데이터 짧은버전
- 여러가지 파생된 라이브러리를 사용할 수 있다 . ex) datepicker , 
- 파생된 라이브러리들은 prototype을 사용 jquery는 $.fn.~으로 접근가능 

## 11강
- es6
- js는 원래 언어의 한계를 극복하는 방법으로 사용되어 왔었음
- 요즘 많이 쓰이면서 es6처럼 공용화됨 
- 클래스 문법 추가됨 : 프로토타입 기반
- 하위 브라우저에서는 안될때가 있음 -> babel  사용 
- const는 재지정 불가 , let은 가능 => 블락변수 
- ``사용  `${}`
- arrow function 
- spread 연산자 ...b , 유연하게 함수 매개변수로 사용가능 