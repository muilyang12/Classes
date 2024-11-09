# Java Programming Class

## Overview

This document is a structured collection of key Java programming concepts I studied while preparing for tests and quizzes. It covers essential topics such as classes, inheritance, interfaces, polymorphism, multithreading, and JDBC programming. By organizing the material in a clear and accessible format, I aim to reinforce my understanding and provide a quick reference guide to revisit these concepts as needed.

## Chapter 3: Classes and Inheritance

- **Final Fields and Methods**

  - The `final` field is used to declare constant data, requiring an initial value at declaration. It is commonly used as a static field.
  - A `final` method can be inherited by child classes but cannot be overridden.

- **Inheritance with Interfaces (implements) and Classes (extends)**

  - Interfaces can support multiple inheritance, while classes support single inheritance only.

- **`this` and `super` Keywords**

  - `this` is a variable that holds a reference to the current object and is usable in instance methods or constructors. It cannot be used in static methods.
  - `super` is a reference variable that holds the parent class type. Like `this`, it is usable in instance methods and constructors to access hidden fields or overridden methods.

  ```java
  class Cylinder extends Circle {
    ...

    public double getVolume() {
      return super.getArea() * height;
    }
  }
  ```

---

## Chapter 4: Interfaces and Polymorphism

- **Abstract Classes**

  - An abstract class is defined using the `abstract` keyword and can contain fields and methods.
  - It cannot be instantiated directly and must be subclassed, where abstract methods are implemented in child classes.
  - Used primarily when similar classes have shared data fields or methods.
  - A class containing abstract methods must be an abstract class or an interface.

  ```java
  abstract public class Shape{
    abstract public double getArea();
  }
  ```

- **Interfaces**

  - Interfaces are 100% abstract, requiring all methods to be abstract (except for default and static methods).
  - They contain only public, static, final constants.
  - Objects cannot be instantiated from interfaces; they must be subclassed with all abstract methods implemented.
  - Interfaces often group unrelated but functionally similar classes and are typically named with adjectives (e.g., `Runnable`, `Serializable`, `Comparable`).

  ```java
  interface Movable{
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight()
  }
  ```

- **Polymorphism**

  - Polymorphism allows handling multiple types of objects with the same code by having different shapes or functions.
  - Type casting is prohibited between unrelated classes, while classes in an inheritance relationship support type conversion.
  - Dynamic binding means that the method to be executed is determined at runtime based on the actual object type, even if it is referenced by a parent type variable.

  ```java
  Animal animal = (Animal) new Dog();
  animal.cry(); // "Woof Woof"
  ```

---

## Chapter 5: Generics and Lambda Expressions

- **Generics**

  - Generics allow classes, methods, or interfaces to operate with specified types at runtime, facilitating reusable, generalized code structures.

  ```java
  class Data<T> {
    private T data;

    public Data(T data) {
      this.data = data;
    }

    public void setData(T data) {
      this.data = data;
    }
    public T getData() {
      return T;
    };
  }
  ```

  - Usage of generics can look like this. If the generic type is clear, only `<>` can be used, or it can be used without specifying a type, treating the parameter as `Object` (Raw type).

    ```java
    Data<String> data1 = new Data<String>("Hello !!");
    Data<String> data2 = new Data<>("Hello !!");
    Data data3 = new Data("Hello !!");
    ```

  - The `extends` keyword can limit the types that can be used as generic parameters. For example, here, the parameter type must be a subclass of `Number`.

  ```java
  class Data<T extends Number> {
    private T data;

    public Data(T data) {
      this.data = data;
    }
  }
  ```

  - You cannot instantiate a generic type parameter, use it as a `static` variable, or create an array of generic objects.

  ```java
  class Data<T extends Number> {
    public someFunction(T data) {
      private T value = new T(); // Error
    }
  }

  class Data<T extends Number> {
    public static T value; // Error
  }

  Data<Integer>[] datas; // Error
  ```

- **Lambda Expressions**

  - Lambda expressions represent anonymous class implementations as expressions.
  - They simplify syntax for interfaces with only one abstract method, known as functional interfaces.
  - The `java.util.function` package provides standard functional interfaces like `Consumer` and `Function`.

  ```java
  interface Addable {
    int add(int a, int b);
  }

  // Anonymous class
  Addable addable1 = new Addable() {
      public int add(int a, int b) {
        return (a + b);
      }
    };
  System.out.println(addable1.add(10, 10));

  // Lambda Expression
    Addable addable2 = (int a, int b) -> {
        return (a + b);
    };
    System.out.println(addable2.add(10, 10));
  ```

---

## Chapter 11: Multithreaded Programming

- **Process and Thread**

  - A process represents a running program and serves as an isolated execution environment with its own memory space. In Java, each program is executed as a single process that can contain multiple threads.
  - A thread is a lightweight execution unit within a process, often referred to as a lightweight process. Each process can spawn multiple threads, and these threads share the same memory space and resources within the process, allowing efficient, concurrent execution.
  - Multithreading allows multiple threads to run simultaneously within a single process, meaning that the `main` thread can create child threads to perform tasks concurrently. These threads operate independently, and because they do not execute in a predetermined order, the outcomes may vary depending on the scheduling of threads by the system.
  - To create a thread in Java, you can either extend the `Thread` class or implement the `Runnable` interface. This flexibility allows for a more modular approach to multithreading.

- **Thread States**

  - `Startable`: The thread is created but the `start()` method has not been called.
  - `Runnable`: The `start()` method has been called, but the thread is waiting for CPU time.
  - `Running`: The thread is currently executing code and has acquired CPU time.
  - `Not Running`: The thread is paused or waiting.

- **Thread Synchronization**

  - In multithreading, multiple threads may need to access shared resources concurrently, which can lead to data inconsistency and unpredictable behavior. Synchronization is the process of controlling thread access to shared resources to maintain data consistency.
  - Java provides the `synchronized` keyword to ensure that only one thread can access a synchronized block or method at a time, effectively creating a lock on the resource. This approach prevents conflicts but can also reduce performance if used excessively.

  ```java
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

  ```java
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

---

## Chapter 14: JDBC Programming

- **Connecting to a DBMS**

  - To connect to a database, you need the database URL, user ID, and password. The `DriverManager.getConnection` method is used to establish a connection to the database.

  ```java
  String url = "jdbc:mysql://server_address:3306/database_name";
  String user = "username";
  String password = "password";

  Connection conn = DriverManager.getConnection(url, user, password);
  ```

- **Executing SQL Statements**

  - executeQuery()

    - Used for `SELECT` statements to retrieve data from the database.
    - Returns a `ResultSet` object, which can be iterated to access the data.

    ```java
    Statement statement = conn.createStatement();

    ResultSet rs = statement.executeQuery("SELECT * FROM Book");

    while(rs.next()) {
      System.out.print(rs.getString("title") + "\t");
      System.out.print(rs.getString("author") + "\t");
      System.out.println(rs.getInt("price") + "\t");
    }
    ```

  - executeUpdate()

    - Used for `INSERT`, `UPDATE`, or `DELETE` statements that modify data in the database.
    - Returns the number of rows affected by the SQL statement.

    ```java
      String updateQuery = "UPDATE Book SET price = 25000 WHERE title = 'Effective Java'";

      int rowsAffected = stmt.executeUpdate(updateQuery);
    ```

- **PreparedStatement Object**

  - A `PreparedStatement` is a precompiled SQL statement that can be used multiple times with different parameter values. It improves performance and helps prevent SQL injection attacks.
  - You can specify parameters using placeholders (`?`), which can be set to different values before execution.

  ```java
  String query = "INSERT INTO Book VALUES (?, ?, ?)";
  PreparedStatement ps = conn.prepareStatement(query);

  ps.setString(1, "Effective TypeScript");
  ps.setString(2, "Dan Vanderkam");
  ps.setInt(3, 22500);

  int resultCount = ps.executeUpdate();
  ```

  ```java
  String query = "SELECT * FROM Book WHERE price > ?";
  PreparedStatement ps = conn.prepareStatement(query);

  ps.setInt(1, 100);
  ResultSet rs = ps.executeQuery();

  while (rs.next()) {
    System.out.println(rs.getString("title") + ", " + rs.getInt("price"));
  }
  ```
