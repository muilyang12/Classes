<h2>3장. 클래스와 상속</h2>

- final 필드와 메소드

  - final 필드는 상수 데이터를 선언할 때 사용하며 선언 시 초기값을 지정하여야 합니다. 일반적으로 static을 사용하여 정적 필드로 사용됩니다.
  - final 매소드는 자식 클래스로 상속은 가능하나 오버라이딩 (재정의) 를 할 수 없는 메소드 입니다.

- 인터페이스의 상속 (implements) 은 다중 상속이 가능한 반면, 클래스의 상속 (extends) 은 단일 상속만 가능합니다.

- this와 super
  - this는 현재 객체에 대한 참조값을 가진 변수로, 인스턴스 메소드나 생성자에서만 사용할 수 있습니다. static 정적 메소드에서는 사용할 수 없습니다.
  - super은 현재 객체에 대한 참조값을 가졌는데, 자료형은 부모 클래스 유형의 변수입니다. this와 마찬가지로 인스턴스 메소드와 생성자에서만 사용할 수 있습니다. 감춰진 필드에 접근하거나 오버라이딩 되는 메소드를 호출할 때 사용합니다.

```
class Cylinder extends Circle {
  ...

  public double getVolume() {
    return super.getArea() * height;
  }
}
```

<br />

<hr />

<h2>4장. 인터페이스와 다형성</h2>

- 추상 클래스
  - 추상 클래스란 클래스 정의에 abstract 키워드를 사용한 클래스입니다.
  - 일반 데이터 필드나 일반 메소드도 포함할 수 있습니다.
  - 직접 객체 생성을 할 수는 없고, 자식 클래스로 상속하여 추상 메소드를 구현한 후에 사용할 수 있습니다.
  - 의미적으로 유사한 클래스여서 공통으로 사용할 데이터 필드나 메소드가 있는 경우에 주로 사용합니다.
  - 추상 메소드를 포함한 클래스는 반드시 추상 클래스이거나 인터페이스 이어야 합니다.

```
abstract public class Shape{
  abstract public double getArea();
}
```

- 인터페이스
  - 인터페이스의 경우 100% 추상적 클래스로 default 메소드와 static 메소드를 제외하면 모든 메소드를 abstrct 추상 메소드로 지정하여야 합니다.
  - 데이터 필드의 경우 public static final이 붙은 수정할 수 없는 클래스 상수만을 포함할 수 있습니다.
  - 직접 객체 생성을 할 수는 없고, 자식 클래스로 상속하여 모든 추상 메소드를 구현한 후에 사용할 수 있습니다.
  - 의미적으로는 관련이 없지만 기능적으로 유사한 클래스를 묶을 때 주로 사용합니다.
  - 주로 형용사를 사용하여 인터페이스의 이름을 표현합니다. (Runnable, Serializable, Comparable 등.)

```
interface Movable{
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight()
}
```

- 다형성
  - 다형성은 유사하지만 다양한 형상이나 다양한 기능을 가질 수 있다는 의미로, 동일한 코드를 사용하여 여러 타입의 객체를 다룰 수 있는 능력을 의미합니다.
  - 관련이 없는 두 클래스 간 타입 변환은 금지된 반면 상속 관계에 있는 클래스의 경우 타입 변환이 가능합니다. 하위 클래스에서 상위 클래스로의 형 변환은 업캐스팅 (Upcasting) 이라고 하여 자동으로 형 변환이 가능합니다.
  - 동적 바인딩이란 메서드 호출 시 실제 실행될 메서드가 실행 시점에 결정되는 것을 의미합니다. 상위 유형의 변수로 하위 객체를 가리키더라도 실행 시점에는 객체의 실제 유형에 따라 수행되는 메소드가 결정되는 특징을 말합니다.

```
Animal animal = (Animal) new Dog();
animal.cry(); // "Woof Woof"
```

<br />

<hr />

<h2>11장. 멀티스레드 프로그래밍</h2>

- 프로세스와 스레드

  - 프로세스는 실행 중인 프로그램을 나타냅니다. Java 프로그램은 하나의 프로세스로 만들어져 실행되며 각 프로세스는 하나 이상의 스레드를 가질 수 있습니다.
  - 스레드는 프로세스 내에서 실행되는 작은 실행 단위를 말합니다. 각 프로세스는 하나 이상의 스레드를 가질 수 있으며, 각 스레드는 동시에 실행될 수 있습니다. 스레드는 경량 프로세스라고 생각할 수도 있습니다.
  - 멀티 스레드는 하나의 프로세스 내에서 여러 개의 스레드가 동시에 실행되는 것을 의미합니다. main 스레드에서 자식 스레드를 만들어서 멀티 스레드를 시작할 수 있으면 여러 스레드는 독립적으로 실행되고 종료됩니다. 독립적으로 실행되기에 실행 결과가 하나로 결정되지 않습니다.
  - 스레드를 실행하기 위해서는 Thread 클래스를 상속 (extends Thread) 받거나 Runnable 인터페이스를 구현 (implements Runnable) 하여야 합니다.

- 스레드의 상태

  - Startable: 스레드가 생성되었지만 아직 start() 메서드가 호출되지 않은 상태.
  - Runnable: start() 메서드가 호출되었으나 CPU를 획득하기 이전 상태.
  - Running: CPU를 얻어 실행 중인 상태.
  - Not Running: CPU를 잃고 중단된 상태.

- 스레드 동기화

  - 여러 스레드가 공유 자원에 동시에 접근하는 경우 자원의 일관성이 깨질 수 있습니다. 이 문제를 막기위해 한 번에 오직 한 개의 스레드만이 공유 객체에 접근할 수 있도록 제한하는 것을 말합니다.
  - 이를 위해 synchronized 키워드를 사용할 수 있습니다. synchronized 메소드는 한 번에 오직 하나의 스레드에서만 실행이 가능한 메소드를 말합니다. 아래 코드의 increment 메소드가 synchronized 메소드의 예시입니다.

```
public class Counter {
  private int count;

  public Counter() {
    count = 0;
  }

  public synchronized void increment() {
    count++;
  }
}
```

```
Counter counter = new Counter();

Thread thread1 = new Thread(() -> {
  for (int i = 0; i < 1000; i++) {
    counter.increment();
  }
});

Thread thread2 = new Thread(() -> {
  for (int i = 0; i < 1000; i++) {
    counter.increment();
  }
});

thread1.start();
thread2.start();
```

<br />

<hr />

<h2>14장. JDBC 프로그래밍</h2>

- DBMS와 연결

```
String url = "jdbc:mysql://서버주소:3306/db이름";
String user = "사용자아이디";
String password = "비밀번호";

Connection conn = DriverManager.getConnection(url, user, password);
```

- SQL 실행
  - executeQuery()
    - select sql 문을 실행하는 데에 사용합니다.
    - ResultSet 객체를 리턴합니다. 이 객체를 순회하며 데이터를 읽을 수 있습니다.
  - executeUpdate()
    - insert, update, delete 등 데이터베이스의 값에 영향을 주는 sql 문을 실행하는 데에 사용합니다.
    - sql 문에 의해 변경된 행의 수를 반환합니다.

```
Statement stmt = conn.createStatement();

ResultSet rs = stmt.executeQuery("select * from Book");

System.out.println("Title\t\tAuthor\tPrice");
while(rs.next()) {
  System.out.print(rs.getString("title") + "\t");
  System.out.print(rs.getString("author") + "\t");
  System.out.println(rs.getInt("price") + "\t");
}
```

- PreparedStatement 객체
  - Precompile된 SQL 문을 표현한다.
  - SQL 구문을 실행할 때가 아니라 객체를 생성할 때 SQL문을 지정한다.
  - 같은 SQL 구문을 여러 번 실행할 때 효율적으로 활용할 수 있다.
  - 객체를 만들 때 SQL 문 안에 Placeholder (?) 를 넣은 후, 실행 직전에 값을 지정할 수도 있다.

```
String query = "insert into Book values(?, ?, ?)";
PreparedStatement ps = conn.prepareStatement(query);

ps.setString(1, "이펙티브 타입스크립트");
ps.setString(2, "댄 밴더캄");
ps.setInt(3, 22500);

int ResultCount = ps.executeUpdate();
```

```
String query = "select * from Book where price > ?";
PreparedStatement ps = conn.prepareStatement(query);

ps.setInt(1, 100);
ResultSet rs = ps.executeQuery();
```
