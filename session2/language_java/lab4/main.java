package session2.language_java.lab4;

class Pupil{
    String type_man;    // Ученик, Школьник, Студент
    String name;        // Имя
    Integer age;        // Возраст
    Character sex;      // Пол
    Pupil(String name, Integer age, Character sex){
        this.name = name;
        this.age = age;
        this.sex = sex;
        if (sex == 'm') type_man = "ученик"; else type_man = "ученица";
    }
    public void print_data(){
        System.out.println(String.format("Pupil:\nName: %s\nSex: %s\nAge: %d", this.name, this.sex, this.age));
    }
    public void greetings(){
        System.out.println(String.format("%s: Здравствуйте, я %s!", name, type_man));
    }
    public Boolean agree_with_mark(Integer a){
        if (a == 2 || a == 3) return false;
        return true;
    }
}

class SchoolMan extends Pupil{
    Integer grade;  // 3 класс
    SchoolMan(String name, Integer age, Character sex){
        super(name, age, sex);
        if (sex == 'm') type_man = "школьник"; else type_man = "школьница";
    }
    public void go_to_olympiad(){
        System.out.println("Топаю на олимпиаду, надеюсь на 1 место.");
    }
}

class Student extends Pupil{
    Integer course = 1; // 1 курс

    Student(String name, Integer age, Character sex){
        super(name, age, sex);
        if (sex == 'm') type_man = "студент"; else type_man = "студентка";
    }
    Student(String name, Integer age, Character sex, Integer course){
        super(name, age, sex);
        if (sex == 'm') type_man = "студент"; else type_man = "студентка";
        this.course = course;
    }
    public Boolean agree_with_mark(Integer a){
        if (a == 2) return false;
        return true;
    }
    public Boolean agree_with_mark(String a){
        a = a.toLowerCase();
        if (a.equals("a") || a.equals("b") || a.equals("c") || a.equals("5") || a.equals("4") || a.equals("3")) return true; //5, 4, 3
        return false;
    }
    public void go_to_work(){
        System.out.println("Работаю по 8 часов в сутки!! (");
    }
}


class Main{
    public static void main(String[] args){
        Pupil man_1 = new Pupil("Кирилл", 12, 'm');
        SchoolMan man_2 = new SchoolMan("Олег", 16, 'm');
        Student man_3 = new Student("Мария", 18, 'w');
        man_1.greetings();
        man_2.greetings();
        man_3.greetings();
        Boolean result = man_1.agree_with_mark(5);
        System.out.println(result);
        result = man_2.agree_with_mark(3);
        System.out.println(result);
        result = man_3.agree_with_mark("3");
        System.out.println(result);
    }
}