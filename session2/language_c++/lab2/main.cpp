#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

//
// 22ИП1Б (2)
//

struct vegetable
{
    string title;
    float price;
    float weight;
    vegetable(string title, float price, float weight){
        this->title = title;
        this->price = price;
        this->weight = weight;
    }
};

class Cart{
    public:
        vegetable* data = nullptr;
        Cart* next = nullptr;

    public:
        Cart(){};
        Cart(vegetable* data_vegetable){
            this->data = data_vegetable;
        };

    public:
        void print_all_data(){
            cout << "==== ==== ==== ==== ==== ==== ==== ==== ==== VEGETABLES ==== ==== ==== ==== ==== ==== ==== ==== ====" << endl;
            if (this->data == nullptr) return;
            Cart* result = this;
            printf("Titile\t\tWeight\t\tPrice\n");
            while (true){
                printf("%s\t\t%f\t%f\n", result->data->title.data(), result->data->weight, result->data->price);
                if (result->next == nullptr) break;
                result = result->next;
            }
            cout << "==== ==== ==== ==== ==== ==== ==== ==== == VEGETABLES END == ==== ==== ==== ==== ==== ==== ==== ====" << endl;
        }

        Cart* add_to_start(vegetable* data_vegetable){
            if (this->data == nullptr){
                this->data = data_vegetable;
                return this;
            } else {
                Cart* first_element = new Cart(data_vegetable);
                first_element->next = this;
                return first_element;
            }
        }
};

Cart* add_value(Cart* cart){
    string title;
    float weight, price;
    cout << "Input: title, weight, price" << endl;
    cin >> title >> weight >> price;
    vegetable* veg = new vegetable(title, weight, price);
    return cart->add_to_start(veg);
}

int main() {
    char menu;
    puts("╔═════════════════════════════════════════════════════╗\r\n");
    puts("║             Работа с динамическим списком           ║\r\n");
    puts("╠═════════════════════╦═════════════════════╦═════════╣\r\n");
    puts("║ 1-Добавить значение ║ 2-Показать таблицу  ║ 3-выход ║\r\n");
    puts("╚═════════════════════╩═════════════════════╩═════════╝\r\n");
    Cart* cart = new Cart();
    while (true) {
        cout << "Команда: ";
        cin >> menu;
        switch (menu) {
            case '1':
                cart = add_value(cart);
                break;
            case '2':
                cart->print_all_data();
                break;
            case '3':
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
