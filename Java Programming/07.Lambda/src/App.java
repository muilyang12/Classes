import java.util.function.Function;

public class App {
    public static void main(String[] args) throws Exception {

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
        Addable addable3 = (int a, int b) -> (a + b);
        System.out.println(addable2.add(10, 10));
        System.out.println(addable3.add(10, 10));

        // Function Interface
        Function<String, Integer> stringToInteger = (str) -> Integer.parseInt(str);
        System.out.println(stringToInteger.apply("12345"));
        System.out.println(stringToInteger.apply("12345").getClass());
    }
}
