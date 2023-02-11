package session2.language_java.lab3;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        // String str1 = scanner.nextLine();
        String str1 = "Широкая электрификация южных губерний даст мощный толчок подъёму сельского хозяйства";
        Integer count_symbol = scanner.nextInt();
        String str2 = "бвгджзйклмнпрстфхцчшщ";
        String str3 = "";
        Integer count_remove = 0;
        for (String word : str1.split(" ")){
            if (word.length() == count_symbol && str2.indexOf(word.toLowerCase().charAt(0)) >= 0) {
                count_remove += 1;
                continue;
            }
            str3 = String.join(" ", str3, word);
        }
        Double y = Math.pow(str1.length() / Math.pow(count_remove, 2), 0.5);
        System.out.println(String.format("Количество удалённых слов: %d", count_remove));
        System.out.println(String.format("Новая строка: %s", str3));
        System.out.println(String.format("Y=%fl", y));
        scanner.close();
    }
}