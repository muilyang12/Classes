public class App {
    public static void main(String[] args) throws Exception {
        Employee employee01, employee02, employee03;

        employee01 = new Employee();
        employee02 = new Sales();
        employee03 = new Development();

        employee01.doJob();
        employee02.doJob();
        // employee02.doJob("midas Civil"); // Error occurs
        employee03.doJob();
        // employee03.doJob("midas Civil"); // Error occurs

        System.out.println("=========================");

        Development development = new Development();
        development.doJob();
        development.doJob("midas Civil");
    }
}
