#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // associative type
    // map, unordered_map
    // multimap, unordered_multimap -> allows dups, isnert() always succeeds
    unordered_map<string, double> products{
        {"Apples", 0.65},
        {"Oranges", 0.85},
        {"Bananas", 0.45},
        {"Pears", 0.50},
    };

    cout.precision(2);
    cout << std::fixed;

    for (;;)
    {
        cout << "Choose: Add Product, Calc Price, Quit\nEnter A, C or Q: ";
        char opt;
        cin >> opt;
        opt = toupper(opt);
        // this is why they didn't use switch for this
        // switch(opt) {
        //     case 'Q':
        //         break; // -> won't break out of loop, need to use some var or goto
        //     ...
        // }

        if (opt == 'Q')
        {
            break;
        }
        else if (opt == 'A')
        {
            cout << "Enter product and price: ";
            string product;
            double price;
            cin >> product >> price;
            // front() returns ref
            product.front() = toupper(product.front());

            if (products.find(product) != products.end())
            {
                cout << "Product already exists, updating price...\n";
                products[product] = price;
                continue;
            }

            // insert() is called with a temporary pair{}
            // usually preferred over products[product] = price which isn't the most efficient
            products.insert(pair{product, price});
        }
        else if (opt == 'C')
        {
            for (const auto &p : products)
            {
                cout << p.first << '\t' << p.second << "/kg\n";
            }

            cout << "Enter product and quantity: ";
            string product;
            double quantity;
            cin >> product >> quantity;
            product.front() = toupper(product.front());

            // alternates to find():
            // auto price_per_prod = products["Apples"]; // find() is better
            // price_per_prod = products["Missing1"];    // creates entry Missing with value 0.0
            // price_per_prod = products.at("Missing2"); // might throw exception
            auto iter = products.find(product);
            if (iter != end(products))
            {
                cout << "Price: " << iter->second * quantity << '\n';
            }
            else
            {
                cout << "Could not find \"" << product << "\"\n";
            }
        }
        else
        {
            cout << "No such option.\n";
        }
    }
}