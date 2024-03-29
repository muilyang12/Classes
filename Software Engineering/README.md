<h2>10강. 유스케이스다이어그램 및 명세</h2>

- 유스케이스 (Use Case)

  - 유스케이스란 시스템이 어떻게 사용되어야 하는지를 포함한 시스템의 모든 가능한 시나리오를 명세한 것으로, 사용자 관점에서 시스템을 모델링하기 위해 사용하는 도구입니다.
  - 액터와 시스템 간의 상호작용을 이벤트 흐름으로 기술하여 포함합니다.

- 유스케이스 간 관계

  - 확장 관계: 특정 조건하에서 확장된 행위를 포함하는 경우 '확장 유스케이스'로 분리합니다. 쉽게 말해 확장 유스케이스는 기본 유스케이스에서 예외적이고 선택적인 사건의 흐름을 떼어 내 표현한 것을 말합니다. (나는 저기에서 나왔다.)

    <img src="https://github.com/muilyang12/Classes/assets/78548830/0e6c652f-9380-4d95-bc4e-406d69fbb90e" art="extension-use-case">

  - 포함 관계: 유스케이스들에 공통의 기능이 존재하는 경우 '공통 유스케이스'로 분리합니다. 중복성을 줄이기 위해 재사용 가능한 부분을 공통 유스케이스로 분리하는 것입니다. (내가 쟤를 포함한다.)

    <img src="https://github.com/muilyang12/Classes/assets/78548830/9871e14a-113f-4818-8cd7-1577749aba12" art="extension-use-case">

<br />

<hr />

<h2>11강. 액티비티 다이어그램</h2>

- 액티비티 다이어그램

  - 액티비티 다이어그램이란 작업 수행에 필요한 일련의 액션들과 그들의 제어 흐름을 표현하는 다이어그램입니다.
  - 비즈니스 프로세스나 업무 흐름같은 시스템의 동적인 행위를 표현하는 다이어그램입니다.

<br />

<img src="https://github.com/muilyang12/Classes/assets/78548830/f907c4c3-c014-4d65-a483-dc0cce52a823" art="activity-diagram">

- 액티비티와 액션

  - 액티비티는 사용자의 작업을 의미하는 것으로 일련의 액션들과 이들의 제어 흐름으로 표현됩니다.
  - 위 다이어그램에서 Approve Payment는 액티비티에 해당하고 그를 구성하는 Calculate Total, Authorize Credit Card같은 동작은 액션에 해당합니다.

- 객체는 액션의 입력이나 출력으로 사용되는 데이터를 의미하며, 위 다이어그램에서는 Order가 객체에 해당합니다.

- 호출 액티비티 액션

  - 호출 액티비티 액션은 액티비티 다이어그램에서 다른 액티비티를 호출하는 액션입니다.
  - 가독성과 재사용성을 높이기 위해 공통적으로 사용되는 액티비티를 별도의 다이어그램으로 분리하고 하나의 액션처럼 호출하는 것을 의미합니다.
  - 위 다이어그램에서 Approve Payment가 호출 액티비티 액션이며, 액션 표기법 내에 표시한 포크 모양 기호가 해당 액션이 호출 액티비티 액션임을 보여주는 기호입니다.

<br />

<hr />

<h2>12강. 상호작용 다이어그램</h2>

- 상호작용 다이어그램

  - 상호작용 다이어그램이란 시스템 내의 개체들 간의 상호작용을 시각적으로 표현하는 UML 다이어그램입니다.
  - 대표적인 상호작용 다이어그램으로는 시퀀스 다이어그램과 통신 다이어그램이 있습니다. 이 두 다이어그램은 의미적으로 동일하여 1:1로 변환이 가능합니다.
  - 시퀀스 다이어그램은 시스템 내의 객체들 간의 상호작용을 시간의 순서에 따라 표현하는 다이어그램입니다. 객체 간의 메시지 교환과 호출 순서를 보여주며, 시스템의 동작과 흐름을 시각화합니다. 하나의 유스케이스 기능을 수행하기 위해 객체들이 어떻게 상호작용하는가를 보일 수 있는 다이어그램입니다.

    <br />

    <img src="https://github.com/muilyang12/Classes/assets/78548830/6765065c-686a-467f-8932-a5ef92886e61" alt="sequence-diagram" />

  - 통신 다이어그램은 객체들 간의 상호작용을 객체들 사이의 연결과 메시지 교환을 중심으로 표현하는 다이어그램입니다. 객체들의 상호작용을 객체들 사이의 관계와 메시지 흐름으로 나타냅니다.

  <br />

  <img src="https://github.com/muilyang12/Classes/assets/78548830/4cd41c6f-c079-4f1e-b53e-6c37b6fd3834" alt="communication-diagram">

<br />

<hr />

<h2>13강. 클래스 다이어그램</h2>

- 클래스 다이어그램

  - 시스템의 클래스, 인터페이스, 관계, 상태, 동작 등을 나타내는 다이어그램으로 시스템의 정적인 구조를 표현할 때 사용합니다.
  - 클래스를 표기할 때는 아래와 같이 사각형으로 표현하며 3개의 영역으로 나누어 표현합니다. 위에서부터 순서대로 클래스의 이름, 클래스 내 속성, 클래스 내 메소드를 포함합니다. 속성이나 메소드의 이름에 밑줄을 그어 static 속성이나 메소드를 선언할 수도 있습니다.

    <br />

    <img src="https://github.com/muilyang12/Classes/assets/78548830/80582ca7-0088-47a8-bc21-09f94ce60faf" alt="class" />

  - 클래스 간의 관계를 표현할 때는 아래와 같은 종류의 관계들을 표현할 수 있습니다.

    - 의존 관계: 클래스 A에서 파라미터나 지역 변수로 클래스 B를 사용하는 경우처럼 단순한 사용이나 참조 관계를 의미합니다. (일시적 사용 관계)
    - 연관 관계: 클래스 A의 속성으로 클래스 B의 객체를 사용하는 경우를 의미합니다. (EX. Player -> Team)
    - 집합체 연관 관계: 강한 형태의 연관 관계로 전체와 부품의 관계를 의미합니다. (EX. Segment -> Rectangle)
    - 구성 집합체 연관 관계: 보다 강한 집합체 연관 관계로 부품은 공유되지 않으며 전체가 삭제되면 부품이 함께 삭제되는 정도의 강한 관계를 의미합니다. (EX. File -> Folder)

    <br />

    <img src="https://github.com/muilyang12/Classes/assets/78548830/7147d293-7aed-48e4-882c-3238823fb128" alt="class-relation" />

<br />

<hr />

<h2>14강. 상태 머신 다이어그램</h2>

- 상태 머신 다이어그램

  - 상태 머신 다이어그램이란 시스템이나 객체의 동작을 상태 (State) 와 상태 전이 (Transition) 의 조합으로 나타내는 다이어그램입니다. 시스템이나 객체가 어떤 상태에서 시작하여 어떤 이벤트에 응답하는지, 어떤 상태로 전이하는지 등 객체의 동작을 모델링하여 표현합니다.
  - 상태: 특정 시점에의 객체나 시스템의 상황을 의미하는 것으로 주어진 시점에의 객체의 속성 값들로 표현합니다.
  - 상태 전이: 한 상태에서 다른 상태로 상태가 변경되는 것으로, 트리거에 의해서 발생하거나 이전 상태의 내부 행위가 종료되어 발생할 수 있습니다.
  - 아래 그림에서 Playing, Stopped, Paused가 상태를 의미하며 press stop이나 press play가 상태 전이를 일으키는 트리거 입니다. 트리거 옆에 [] 대괄호를 사용하여 조건을 명시할 수도 있습니다. press play [disc in tray] 이렇게 작성할 경우 disk가 있는 경우에만 press play 버튼을 클릭하였을 때 상태 전이가 일어난다는 조건을 설정할 수도 있습니다.

  <br />

  <img src="https://github.com/muilyang12/Classes/assets/78548830/dea26af1-722c-445c-a11d-782d995aa7c7" alt="state-diagram" />

- 복합 상태

  - 복합 상태는 특정 상태를 세분화하여 여러 개의 하위 상태로 나타낸 것을 말합니다.
  - 복합 상태의 상세한 내용을 감추어 표현한 후 별도의 상태 머신 다이어그램 (하위 상태 머신 다이어그램) 을 그려서 표현합니다.

  <br />

  <img src="https://github.com/muilyang12/Classes/assets/78548830/f3437a47-4998-4110-8eb3-04ef530206a5" alt="composite-state">
