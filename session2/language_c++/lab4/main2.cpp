#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct materials{
    int natural;
    int artificial;
    materials(int nat){
        this->natural = nat;
        this->artificial = 100 - nat;
    };
};


struct thing{
    string title, color;
    int price;
    materials material {0};
    thing* next;
    thing(string title, string color, int price, int natural){
        this->title = title;
        this->color = color;
        this->price = price;
        this->material = materials(natural);
    }
};


class Node{
    public:
        int count;
        thing* data = nullptr;
    
    public:
        void add_value(string title, string color, int price, int natural_mat){
            thing* current_thing = this->data;
            while (true){
                if (current_thing == nullptr){
                    this->data = new thing {title, color, price, natural_mat};
                    return; 
                } else if (current_thing->next == nullptr){
                    current_thing->next = new thing {title, color, price, natural_mat};
                    return;
                }
                current_thing = current_thing->next;
            }
        }
};


class File{
    string path = "myfile.txt";
    public:
        Node* read(){
            string title, color;
            int price, nat_m, art_m, count_data = 0;
            ifstream fout(this->path);
            Node* node = new Node();
            while (fout >> title >> color >> price >> nat_m >> art_m){
                node->add_value(title, color, price, nat_m);
                ++count_data;
            }
            fout.close();
            node->count = count_data;
            return node;
        }

        void print_all_data(){
            thing* thing = this->read()->data;
            printf("№\tназвание\tцвет\t\tцена\t\tматериал(n/a) \n");
            for (int i = 1, j = this->read()->count + 1; i < j; ++i){
                printf("%d\t%s\t\t%s\t\t%d\t\t%d\\%d\n", 
                        i, 
                        thing->title.c_str(), 
                        thing->color.c_str(), 
                        thing->price, 
                        thing->material.natural, 
                        thing->material.artificial);
                thing = thing->next;
            }
        }

        void clear(){
            ofstream fwrite;
            fwrite.open(this->path);
            fwrite.close();
        }

        void write(){
            string title, color;
            int price, nat_m, art_m;
            ofstream fwrite;
            cout << "Название => цвет => цена => % соотношение натуральных материалов"<< endl;
            cin >> title >> color >> price >> nat_m;
            fwrite.open(this->path, ios::app);
            fwrite << title << " " << color << " " << price << " " << nat_m << " " << 100 - nat_m << "\n";
            fwrite.close();
        }
};


class Filter{
    private:
    void print(int i, thing* thing){
        printf("%d\t%s\t\t%s\t\t%d\t\t%d\\%d\n", 
                        i,
                        thing->title.c_str(),
                        thing->color.c_str(),
                        thing->price,
                        thing->material.natural,
                        thing->material.artificial);
    }
    void filter_title_or_color(File file, char menu_q){
        string etalon;
        cout << "Что будем искать?: ";
        cin >> etalon;
        Node* node = file.read();
        thing* thing = node->data;
        printf("№\tназвание\tцвет\t\tцена\t\tматериал(n/a) \n");
        for (int i = 1, j = node->count + 1; i < j; ++i){
            if (menu_q == '1' && etalon == thing->title) print(i, thing);
            if (menu_q == '2' && etalon == thing->color) print(i, thing);
            thing = thing->next;
        }
    }
    bool filter(char et, int dg, int integer_){
        // etalon_equels
        // data_get
        bool success = false;
        if (et == '1' && dg > integer_ || et == '2' && dg >= integer_ ||
            et == '3' && dg < integer_ || et == '4' && dg <= integer_ ||
            et == '5' && dg == integer_)
            success = true;
        return success;
    }
    void filter_other(File file, char menu_q){
        char sign;
        int integer_;
        int data_inf;
        cout << "Формула поиска: {запись из бд} {знак} {число}" << endl;
        cout << "Какой знак будем рассматривать?" << endl
            << "1 - >" << endl << "2 - >=" << endl
            << "3 - <" << endl << "4 - <=" << endl
            << "5 - ==" << endl << "Введите номер знака: ";
        cin >> sign;
        cout << "ВВедите число: ";
        cin >> integer_;
        Node* node = file.read();
        thing* thing = node->data;
        printf("№\tназвание\tцвет\t\tцена\t\tматериал(n/a) \n");
        for (int i = 1, j = node->count + 1; i < j; ++i){
            if (menu_q == '3') data_inf = thing->price;
            if (menu_q == '4') data_inf = thing->material.natural;
            if (menu_q == '5') data_inf = thing->material.artificial;
            if (filter(sign, data_inf, integer_))
                this->print(i, thing);
            thing = thing->next;
        }
    }
    char input_menu_title(){
        char menu_title;
        cout << "Конструктор фильтрации запроса:" << endl
            << "1 - по названию" << endl
            << "2 - по цвету" << endl
            << "3 - по цене" << endl
            << "4 - по % натуральности" << endl
            << "5 - по % искуственности" << endl
            << "Введите номер столбца для фильтрации: ";
        cin >> menu_title;
        if (5 >= menu_title - 48 && 1 <= menu_title - 48) return menu_title;
        return 'n';
    }
    public:
    void query(File file){
        char menu = input_menu_title();
        if (menu == 'n') {
            cout << "Фильтр не найден!\n";
            return ;
        }
        if (menu == '1' || menu == '2') filter_title_or_color(file, menu);
        else filter_other(file, menu);
        
    }
};


void print_menu(){
    cout << "Menu:" << endl
        << "1 - добавить данные в файл" << endl
        << "2 - прочитать и вывести данные из файла" << endl
        << "3 - фильтрация и вывод данных" << endl
        << "4 - количество записей" << endl
        << "5 - очистка файла" << endl
        << "6 - выход" << endl
        << "m - вызов помощи" << endl;
}


int main(){
    File file = File();
    char menu;
    print_menu();
    while(true){
        cout << "Напишите номер команды (m - menu): ";
        cin >> menu;
        system("clear");
        switch (menu){
        case '1':
            file.write();
            break;
        case '2':
            file.print_all_data();
            break;
        case '3':
            Filter().query(file);
            break;
        case '4':
            cout << "Количество записей: "<< file.read()->count << endl;
            break;
        case '5':
            file.clear();
            break;
        case '6':
            exit(0);
            break;
        case 'm':
            print_menu();
        default:
            break;
        }
    }
}
