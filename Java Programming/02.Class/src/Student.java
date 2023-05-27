public class Student {
    private static int studentNumber = 0;
    final private int studentId;
    private int enrolledSubjectIds[];

    public Student() {
        studentNumber += 1;
        studentId = studentNumber;

        enrolledSubjectIds = new int[0];

    }

    public static int getStudentNumber() {
        return studentNumber;
    }

    public int getStudentId() {
        return studentId;
    }

    public int[] getEnrolledSubjectIds() {
        return enrolledSubjectIds;
    }

    public void addClass(int subjectId) {
        int[] newEnrolledSubjectIds = new int[enrolledSubjectIds.length + 1];
        System.arraycopy(enrolledSubjectIds, 0, newEnrolledSubjectIds, 0, enrolledSubjectIds.length);
        newEnrolledSubjectIds[newEnrolledSubjectIds.length - 1] = subjectId;
        
        enrolledSubjectIds = newEnrolledSubjectIds;
    }
}
