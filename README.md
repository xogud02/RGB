# RGB

### 프로젝트 소개

3인칭 3D 퍼즐 게임

#### 프로젝트 목적

- 디자인 패턴 학습 및 적용
- 객체지향 기법 학습 및 적용
- 언리얼 엔진 API를 이용한 설계 및 학습
- 자료구조의 개별 특징 학습 및 적용

#### 사용기술

- C++

- 언리얼 API

#### 개발환경

- Unreal Engine 4.22.3
- Visual Studio Code

####  프로젝트 기간

2019.07.29 ~ 2019.09.30 (2개월)

#### 프로젝트 특징

##### 객체지향 요소 적용

- 캡슐화

  - 캐릭터를 이동시키는 워프 객체가 캐릭터의 위치와 방향(필드)를 직접 변경하지 않고 캐릭터에서 구현한 함수를 이용하도록 작성해 구현로직에 대한 유연성을 얻었다.
  - 캐릭터 생성자의 복잡한 초기화 작업을 내부 메서드로 감싸 가독성과 구현 코드변경에 도움이 되었다.

  ##### 적용 코드

  [RGBCharacter.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBCharacter.cpp), [RGBWarp.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBWarp.cpp)

- 디자인 패턴 적용

  - 여러 디자인 패턴을 적용하며 타입 은닉을 통한 유연성을 확보할 수 있었다.

##### 디자인 패턴

- 전략 패턴

  배열의 순회순서를 정하는 여러가지 패턴(알고리즘)을 공통의 추상클래스(인터페이스)를 구현해 작성했다. 클라이언트에선 공통 인터페이스에 의존하기 때문에 새로운 패턴이 추가될때 유연함을 확보할 수 있었다.  특히, 인터페이스 타입의 멤버를 UE 에디터에 노출했을때, 구현된 객체를 드롭다운 메뉴로 고를수 있어서 에디터 상으로도 편리함을 확보할 수 있었다.

  ##### 적용 코드

  - 클라이언트

    [RGBObjectMover.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBObjectMover.cpp)

  - 인터페이스

    [PositionArrayTraveler.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/PositionArrayTraveler.cpp)

  - 구현 클래스

    [PingPongPAT.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/PingPongPAT.cpp), [RandomPAT.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RandomPAT.cpp), [RotationPAT.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RotationPAT.cpp)

- 옵저버 패턴

  게임내 요소들(관찰자)이 플레이어 캐릭터(관찰대상) 상태의 변경에 따라 행동할수 있도록 관찰자 인터페이스를 구현했다. 관찰자 객체들은 Push방식의 이점을 얻을수 있었고, 관찰대상 객체에선 개별의 구현객체가 아닌 관찰자 인터페이스에 의존해 유연성을 확보할 수 있었다.
  
  ##### 적용 코드
  
  - 관찰대상 객체
  
    [RGBCharacter.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBCharacter.cpp)
  
  - 관찰자 객체
  
    [RGBWarp.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBWarp.cpp), [RGBItem.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBItem.cpp), [RGBBarrier.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RGBBarrier.cpp)

##### 자료구조 특성에 따라 자료구조 사용

- Queue

  정해진 순서의 원소를 반복적으로 순환하는 상황에서 인덱스를 신경쓰지 않을수 있고 FIFO인 Queue를 사용.

  인덱스 계산코드가 없어 코드가 간결해졌다.

  ##### 적용 코드

  [PositionArrayTraveler.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/PositionArrayTraveler.cpp)

- Set

  배열에서 원소를 하나씩 골라 랜덤하게 담기 위해 중복이 없는 특성을 가진 Set을 사용.
  
  **중복 검사**라는 로직이 자료구조 Set에 감싸져있어 코드가 간결해지고 전체 로직을 알아보기 쉬워졌다.
  
  ##### 적용 코드
  
  [RandomPAT.cpp](https://github.com/xogud02/RGB/blob/master/Source/RGB/RandomPAT.cpp)

##### 언리얼 엔진 패러다임 이해

- 언리얼 빌드 시스템의 이해

  - .uproject파일과 UBT(Unreal Build Tool)의 동작방식 이해

  - 모듈과 cs 타겟파일의 이해
- 언리얼 오브젝트의 이해
  - 네이티브 C++ 클래스와의 차이
  - UHT(Unreal Header Tool)의 동작방식 이해

---



### 게임소개

#### RGB

캐릭터에 색에 따라 각종 게임 요소와 상호작용해 목적지에 도달.

#### 조작

WASD로 이동, 스페이스바로 점프, 마우스 이동으로 시점 회전, 마우스 휠로 시점 확대/축소

#### 게임화면

![](readme/Images/01.gif)![](readme/Images/02.gif)

#### 설치

구글 드라이브 링크

[Windows32bit](https://drive.google.com/file/d/1-6Yo3nQBUCMEz2hPzw9e176aLst65hUI/view?usp=sharing)

[Widows64bit](https://drive.google.com/file/d/1bLgYt-Dd5DMp09LzmV89BvLB-tLBDeXV/view?usp=sharing)

