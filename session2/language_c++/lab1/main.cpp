#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

//
// 22ИП1Б
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
            printf("Title\t\tWeight\t\tPrice\n");
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

int main(){
    string title;
    int count_vegetable;
    float weight, price;
    Cart* cart = new Cart();
    cout << "Введите количество овощей для добавления" << endl;
    cin >> count_vegetable;
    for (int i = 0; i < count_vegetable; ++i){
        cout << "Input: title, weight, price" << endl;
        cin >> title >> weight >> price;
        vegetable* veg = new vegetable(title, weight, price);
        cart = cart->add_to_start(veg);
    }
    // cart = cart->add_to_start(new vegetable("Огурец", 65.52f, 0.751f));
    // cart = cart->add_to_start(new vegetable("Помидор", 90.53f, 0.34f));
    // cart = cart->add_to_start(new vegetable("Капуста", 13.28f, 2.565f));
    // cart = cart->add_to_start(new vegetable("Лук", 10.2f, 1.5f));
    cart->print_all_data();
    return 0;
}