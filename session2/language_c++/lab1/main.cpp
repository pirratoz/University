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

        Cart* add_value(vegetable* data_vegetable){
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
    Cart* cart = new Cart();
    string title;
    float weight, price;
    cout << "Input: title, weight, price" << endl;
    for (int i = 0; i < 2; ++i){
        cin >> title >> weight >> price;
        vegetable* veg = new vegetable(title, weight, price);
        cart = cart->add_value(veg);
    }
    // cart = cart->add_value(new vegetable("Огурец", 65.52f, 0.751f));
    // cart = cart->add_value(new vegetable("Помидор", 90.53f, 0.34f));
    // cart = cart->add_value(new vegetable("Капуста", 13.28f, 2.565f));
    // cart = cart->add_value(new vegetable("Лук", 10.2f, 1.5f));
    cart->print_all_data();
    return 0;
}