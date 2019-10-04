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

##### 디자인 패턴 적용

- 전략 패턴

  배열의 순회순서를 정하는 여러가지 방식을 공통의 추상클래스를 상속받는 개별의 객체로 분리해서 사용.

- 옵저버 패턴

  게임내 요소들이 플레이어 캐릭터 상태의 변경에 따라 행동할수 있도록 공통의 인터페이스를 구현.

##### 객체지향 요소 적용

- 캡슐화

  캐릭터의 위치를 변경시키는 게임 요소가 캐릭터의 데이터를 직접 다루지 않고 캐릭터의 함수를 호출.

##### 자료구조 특성에 따라 자료구조 사용

- Queue

  여러개의 원소를 반복적으로 순환하는 상황에서 인덱스를 신경쓰지 않을수 있고 FIFO인 Queue를 사용.

- Set

  배열에서 원소를 하나씩 골라 랜덤하게 담기 위해 중복이 없는 특성을 가진 Set을 사용.

##### 언리얼 엔진 패러다임 이해

- 단순 API 사용이 아닌 액터의 수명주기와 GC개념을 이해하고 이용할수 있음.

  에디터에서 실행(PIE)와 아닐때, 액터가 스폰될때 등 각각에 대한 매커니즘의 차이 학습.

- 언리얼 빌드 시스템에 대한 이해.

  빌드 모드에 따라 다르게 작동하는 언리얼 키워드에 대한 학습.

- UPROPERTY, UCLASS, UFUNCTION 매크로에 대한 이해. 

  매크로가 확장되었을때 실제 C++ 신택스에 대한 학습.



---



### 게임소개

#### RGB

캐릭터에 색에 따라 각종 게임 요소와 상호작용해 목적지에 도달.

#### 조작

WASD로 이동, 스페이스바로 점프, 마우스로 시점 회전

#### 게임화면

![](readme/Images/01.gif)![](readme/Images/02.gif)

#### 설치

구글 드라이브 링크

[Windows32bit](https://drive.google.com/file/d/1-6Yo3nQBUCMEz2hPzw9e176aLst65hUI/view?usp=sharing)

[Widows64bit](https://drive.google.com/file/d/1bLgYt-Dd5DMp09LzmV89BvLB-tLBDeXV/view?usp=sharing)

