<h2>11. 멀티스레드 프로그래밍</h2>

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

<hr />

<h2>14. JDBC 프로그래밍</h2>

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
