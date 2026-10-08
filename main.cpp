#include <iostream>
#include <fstream>
using namespace std;
class product
{
private:
    int product_id=0;
    string product_name;
    float price;
    int quantity;
    void add_product();
    void search_product();
    void display_all_products();

public:
    void product_menu();
};
void product::search_product()
{
    cout << "searching" << endl;
}
void product::add_product()
{

    ofstream products("product.txt", ios::app);
    product_id++;
    cout << "enter the product name" << endl;
    cin >> product_name;
    cout << "enter the product price" << endl;
    cin >> price;
    cout << "enter the quantiy of product" << endl;
    cin >> quantity;
    products << product_id << endl;
    products << product_name << endl;
    products << price << endl;
    products << quantity << endl;
    products << endl;
    products << endl;
    products << endl;
    products.close();
}
void product::display_all_products()

{
    ifstream products("product.txt");
    int product_id;
    string product_name;
    float price;
    int quantity;
    while (products >> product_id >> product_name >> price >> quantity)
    {

        cout << "product id is:" << product_id << endl;
        cout << "product name is:" << product_name << endl;
        cout << "product price is:" << price << endl;
        cout << "product quantity is:" << quantity << endl;
        cout<<endl;
    }
}

void product::product_menu()

{
    while (true)
    {
        cout << "--------------------" << endl;
        cout << " Product Management " << endl;
        cout << "--------------------" << endl;
        cout << "1.Add product" << endl;
        cout << "2.search product" << endl;
        cout << "3.display all products" << endl;
        cout << "4.back" << endl;
        int choice;
        cout << "enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_product();
            break;
        case 2:
            search_product();
            break;
        case 3:
            display_all_products();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
        }
    }
}

int main()
{
    product p;
    p.product_menu();
}