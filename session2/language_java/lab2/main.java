package session2.language_java.lab2;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String first, second;
        while (true) {
            first = scanner.nextLine();
            second = scanner.nextLine();
            if (validate(first, second)) break;
        }
        truth_table(first, second);
        scanner.close();
    }
    public static boolean validate(String first, String second){
        if (first.length() != second.length()) {
            System.out.println("Ошибка ввода");
            return false;
        }
        for (int i=0; i<first.length(); ++i){
            Boolean s1 = first.charAt(i) == '1' && first.charAt(i) == '0';
            Boolean s2 = second.charAt(i) == '1' && second.charAt(i) == '0';
            if (s1 || s2){
                System.out.println("Ошибка ввода");
                return false;
            }
        }
        return true;
    }
    public static int[][] string_convert_to_int(String first, String second){
        int[] arr1 = new int[first.length()];
        int[] arr2 = new int[second.length()];
        for (int i=0; i < first.length(); ++i) arr1[i] = Character.getNumericValue(first.charAt(i));
        for (int i=0; i < second.length(); ++i) arr2[i] = Character.getNumericValue(second.charAt(i));
        return new int[][] {arr1, arr2};
    }
    public static int logic(int integer1, int integer2){
        if (integer1 == integer2 && integer1 == 1) return 1;
        return 0;
}
    public static void truth_table(String first, String second){
        int[][] arrys = string_convert_to_int(first, second);
        System.out.println("Arg1\tArg2\tResult");
        for (int i = 0; i < first.length(); ++i){
            String text = String.format("%d\t%d\t%d", arrys[0][i], arrys[1][i], logic(arrys[0][i], arrys[1][i]));
            System.out.println(text);
    }
}
}