import java.util.Arrays;

public class App {
    public static void main(String[] args) throws Exception {
        Student student01 = new Student();
        System.out.println("Student Number: " + Student.getStudentNumber());

        System.out.println("Student ID: " + student01.getStudentId());
        System.out.println(Arrays.toString(student01.getEnrolledSubjectIds()));

        student01.addClass(10);
        student01.addClass(20);
        student01.addClass(30);

        System.out.println(Arrays.toString(student01.getEnrolledSubjectIds()));

        Student student02 = new Student();
        Student student03 = new Student();
        System.out.println("Student Number: " + Student.getStudentNumber());
    }
}
