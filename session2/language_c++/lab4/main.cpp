#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const char filename[] = "myfile.txt";


struct material{
    int natural;
    int artificial;
    material(){};
    material(int nat){
        this->natural = nat;
        this->artificial = 100 - nat;
    };
};


struct thing{
    string title;
    string color;
    float price;
    material materials;
    thing(string title, string color, float price, int nat){
        this->title = title;
        this->color = color;
        this->price = price;
        this->materials = material(nat);
    }
};


class Node {
    public:
        thing* data = nullptr;
        Node* next = nullptr;

    public:
        Node(){};
        Node(thing* data){
            this->data = data;
        };
    
        void add_value(string title_, string color_, float price_, int mat_){
            if (this->data == nullptr){
                this->data = new thing {title_, color_, price_, mat_};
            } else if (this->next == nullptr){
                this->next = new Node(new thing {title_, color_, price_, mat_});
            } else {
                this->next->add_value(title_, color_, price_, mat_);
            }
        }

        void print_data(){
            printf("%s\t\t%s\t\t%f\t\t%d\t\t%d\n", data->title.c_str(), data->color.c_str(), data->price, data->materials.natural, data->materials.artificial);
        }
        void print_all_data(){
            Node* keys = this;
            while (true){
                if (keys->data == nullptr) break;
                printf("%s\t\t%s\t\t%f\t\t%d\t\t%d\n", keys->data->title.c_str(), keys->data->color.c_str(), keys->data->price, keys->data->materials.natural, keys->data->materials.artificial);
                if (keys->next == nullptr) break;
                keys = keys->next;
            }
        }

    private:
        void q_string(char menuq){
            if (menuq == '1') printf("Введите название предмета: "); else printf("Введите цвет предмета: ");
            string etalon;
            cin >> etalon;
            Node* keys = this;
            while (true){
                if (keys->data == nullptr) return;
                if (menuq == '1' && keys->data->title == etalon) keys->print_data();
                if (menuq == '2' && keys->data->color == etalon) keys->print_data();
                if (keys->next == nullptr) return;
                keys = keys->next;
            }
            
        }
        void q_integer(char menuq){
            printf("[данные] {знак} {значение} => Знак для поиска данных:\n1 - >\n2 - >=\n3 - <\n4 - <=\n5 ==");
            char etalon;
            int integer;
            cin >> etalon;
            cout << "Введите значение для поиска в базе: " << endl;
            cin >> integer;
            Node* keys = this;
            while (true){
                if (keys->data == nullptr) return;
                if (menuq == '3'){
                    if (etalon == '1' && keys->data->price > integer) keys->print_data();
                    if (etalon == '2' && keys->data->price >= integer) keys->print_data();
                    if (etalon == '3' && keys->data->price < integer) keys->print_data();
                    if (etalon == '4' && keys->data->price <= integer) keys->print_data();
                    if (etalon == '5' && keys->data->price == integer) keys->print_data();
                }
                if (menuq == '4'){
                    if (etalon == '1' && keys->data->materials.natural > integer) keys->print_data();
                    if (etalon == '2' && keys->data->materials.natural >= integer) keys->print_data();
                    if (etalon == '3' && keys->data->materials.natural < integer) keys->print_data();
                    if (etalon == '4' && keys->data->materials.natural <= integer) keys->print_data();
                    if (etalon == '5' && keys->data->materials.natural == integer) keys->print_data();
                }
                if (menuq == '5'){
                    if (etalon == '1' && keys->data->materials.artificial > integer) keys->print_data();
                    if (etalon == '2' && keys->data->materials.artificial >= integer) keys->print_data();
                    if (etalon == '3' && keys->data->materials.artificial < integer) keys->print_data();
                    if (etalon == '4' && keys->data->materials.artificial <= integer) keys->print_data();
                    if (etalon == '5' && keys->data->materials.artificial == integer) keys->print_data();
                }
                //keys->print_data();
                if (keys->next == nullptr) return;
                keys = keys->next;
            }
        }

    public:
        void query(){
            cout << "Выберите номер колонки для фильтрации:" << endl;
            cout << "1 - название\n2 - цвет\n3 - цена\n4 - натуральные материалы\n5 - искуственные материалы" << endl;
            char menuq;
            cin >> menuq;
            if (menuq == '1' || menuq == '2') {
                // сравнение строк через ==
                this->q_string(menuq);
            } else if (menuq == '3' || menuq == '4' || menuq == '5') {
                // сравнение строк через >=, <=, ==, > ......
                this->q_integer(menuq);
            } else {
                printf("Колонка для фильтрации не найдена!");
            }
        }
};


class File{
    string path;
    public:
        File(string path){
            this->path = path;
        }

    public:
        Node* read(){
            string title, color;
            int mat1, mat2;
            float price;
            ifstream fout(this->path);
            Node* node = new Node();
            if (fout.is_open()){
                while (fout >> title >> color >> price >> mat1 >> mat2){
                    node->add_value(title, color, price, mat1);
                }
                fout.close();
            }
            return node;
        };

        int count_data(){
            string title;
            ifstream fout(this->path);
            int count = 0;
            Node* node = new Node();
            if (fout.is_open()){
                while (fout >> title){
                    ++count;
                }
                fout.close();
            }
            return count / 5;
        };
        
        void clear(){
            ofstream fwrite;
            fwrite.open(this->path);
            if (fwrite.is_open()) {
                fwrite.close();
            }
        };

        void write(thing data){
            ofstream fwrite;
            fwrite.open(this->path, ios::app);
            if (fwrite.is_open()) {
                fwrite << data.title << " " << data.color << " " << data.price << " " 
                        << data.materials.natural << " " << data.materials.artificial << "\n";
                fwrite.close();
            }
        };
};


void input(File* file){
    string title, color;
    float price;
    int natural;
    cout << "Название, цвет, цена, соотношение натуральных материалов в % (int) до 100%" << endl;
    cin >> title >> color >> price >> natural;
    // унифицированная инициализация
    thing item {title, color, price, natural};
    file->write(item);
}


int main(){
    File* file = new File(filename);
    char menu;
    cout << "Menu:\n1 - добавить данные в файл\n2 - прочитать и вывести данные из файла\n3 - Фильтрация данных\n4 - выход\n5 - количество записей\n6 - очистка файла" << endl;
    while (true){
        cout << "Номер команды: "; 
        cin >> menu;
        switch (menu){
        case '1':
            // write data to file
            input(file);
            break;
        case '2':
            // print_data_file
            file->read()->print_all_data();
            break;
        case '3':
            // filter_data
            file->read()->query();
            break;
        case '4':
            // filter_data
            exit(0);
            break;
        case '5':
            cout << file->count_data() << endl;
        case '6':
            file->clear();
        default:
            break;
        }
    }
    return 0;
}