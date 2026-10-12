#include <iostream>
#include <fstream>
using namespace std;
class product
{
private:
    int product_id = 0;
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
    string name;
    cout << "enter the name of productt u want to search" << endl;
    cin >> name;

    ifstream products("product.txt");
    int product_id;
    string product_name;
    float price;
    int quantity;
    bool found = false;
    while (products >> product_id >> product_name >> price >> quantity)
    {
        if (product_name == name)
        {
            found = true;
            cout << "product id is:" << product_id << endl;
            cout << "product name is:" << product_name << endl;
            cout << "product price is:" << price << endl;
            cout << "product quantity is:" << quantity << endl;
            cout << endl;
        }
    }
    if (found == false)
    {
        cout << "no product found" << endl;
    }
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
        cout << endl;
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

class customer
{
private:
    int customer_id = 0;
    string customer_name;
    long int phone_number;
    void add_customer();
    void search_customer();
    void display_all_customer();

public:
    void customer_menu();
};

void customer::customer_menu()
{

    while (true)
    {
        cout << "---------------------" << endl;
        cout << " Customer Management " << endl;
        cout << "---------------------" << endl;
        cout << "1.add customer" << endl;
        cout << "2.search customer" << endl;
        cout << "3.display all customer" << endl;
        cout << "4.exit" << endl;

        int choice;
        cout << "enter the choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_customer();
            break;
        case 2:
            search_customer();
            break;
        case 3:
            display_all_customer();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
        }
    }
}
void customer::add_customer()
{
    ofstream customers("customers.txt", ios::app);
    customer_id++;
    cout << "enter customer name" << endl;
    cin >> customer_name;
    cout << "enter phone number" << endl;
    cin >> phone_number;

    customers << customer_name << endl;
    customers << phone_number << endl;
    customers << endl;

    customers.close();
}
void customer::search_customer()
{
    ifstream customers("customer.txt");
    string name;
    cout << "enter name of customer u  want to search" << endl;
    cin >> name;

    string customer_name;
    long int phone_number;
    bool found = false;

    while (customers >> customer_name >> phone_number)
    {
        if (customer_name == name)
        {
            found = true;
            cout << "customer name is :" << customer_name << endl;
            cout << "mobile number is :" << phone_number << endl;
        }
    }
    if (found == false)
    {
        cout << "no customer found" << endl;
    }
}
void customer::display_all_customer()
{
    ifstream customers("customer.txt");

    string customer_name;
    long int phone_number;

    while (customers >> customer_name >> phone_number)
    {
        cout << "customer name is :" << customer_name << endl;
        cout << "mobile number is :" << phone_number << endl;
        cout << endl;
    }
}

class bill
{
    string que;
    int billing_id = 0;
    string product;
    int buy_quantity;
    void add_product();
    void show_cart();
    void total_bill();

public:
    void bill_menu();
};
string buy_product;
int buy_quantity;
void bill::bill_menu()
{
    cout << "--------------------" << endl;
    cout << "   Bill Management  " << endl;
    cout << "--------------------" << endl;
    cout << "1.add items" << endl;
    cout << "2.show items" << endl;
    cout << "3.total bill" << endl;
    cout << "4.exit" << endl;
    int choice;
    cout << "enter the value" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        add_product();
        break;

    case 2:
        show_cart();
        break;

    case 3:
        total_bill();
        break;

    case 4:
        return;
        break;

    default:
        cout << "invalid choice" << endl;
    }
}
void bill::add_product()
{
    char que;
    cout << "are u a regular customer(y/n)" << endl;
    cin >> que;
    string name;
    if (que == 'y')
    {
        cout << "please enter your name" << endl;
        cin >> name;
    }
    ifstream customers("customers.txt");
    string customer_name;
    bool found = false;
    while (customers >> customer_name)
    {
        if (customer_name == name)
        {
            found = true;
        }
    }
    if (found == false)
    {
        cout << "you are not regular customer" << endl;
    }

    cout<<"enter the product u want to purchase"<<endl;
    cin>>buy_product;


    
}
int main()
{

    product p;
    customer c;
    bill b;

    while (true)
    {
        cout << "---------------------------" << endl;
        cout << " Billing Management System " << endl;
        cout << "---------------------------" << endl;
        cout << "1.product management" << endl;
        cout << "2.customer management" << endl;
        cout << "3.bill management" << endl;
        cout << "4.exit" << endl;

        int choice;
        cout << "enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.product_menu();
            break;
        case 2:
            c.customer_menu();
            break;
        case 3:
            // c.customer_menu();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
        }
    }
}