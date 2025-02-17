#include<iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;
#include "H.project.h"

int main()
{
    // Vector to store product information
    vector<products> product;
    vector<products> chart;
    int int_code = 11768, i = 0;// Initialization code of products

    // Creating instances of the 'products' class with initial values
    products water("water", 1.50, 15, "11/7/2030", "egypt for life", int_code + i++);//product 1
    products Spiro_Spathis("Spiro Spathis", 10, 30, "11/12/2025", "Spiro Spats for carbonated water", int_code + i++);//product 2
    products Raw("Raw",5,50,"3/7/2024","Egypt foods", int_code + i++);//product 3
    products chips("chips",5,50,"3/6/2025","Egypt foods", int_code + i++);//product 4

    // Adding products to the 'product' vector
    product.push_back(water);
    product.push_back(Spiro_Spathis);
    product.push_back(Raw);
    product.push_back(chips);

    int x = 1; // Control the operation and modes of a program
    int w = 0;

    // Main loop to select program mode
    while (x)
    {
        cout << "please select mode you want" << endl << "1-seller\n2-customer\n0-exit\n";
        cin >> x;

        if (x == 1)
        {
            // Seller mode
            while (x == 1)
            {
                int operation;
                cout << "Select operation:\n1- Add product\n2- Delete product\n3- Stop adding\n";
                cin >> operation;

                if (operation == 1)
                {
                    // Adding a new product
                    products z1;
                    z1.set_val(); // Set values from the seller

                    // Check if the product has expired
                    if (z1.checkExpiry())
                    {
                        cout << "Product has expired. Rejecting it." << endl;
                        continue;
                    }

                    // Adding the product to the 'product' vector
                    product.push_back(z1);
                    updateProductCodes(product);
                    cout << "accepting it" << endl;
                }
                else if (operation == 2)
                {
                    // Displaying products for the seller to choose from
                    for (int j = 0; j < product.size(); j++)
                    {
                        product[j].display();
                    }

                    int deleteCode;
                    cout << "Enter the code of the product to delete: " << endl;
                    cin >> deleteCode;

                    // Deleting the product with the specified code
                    dele_product(product, deleteCode);
                    updateProductCodes(product);

                }
                else if (operation == 3)
                {
                    x = 5; // Stop adding
                }
            }
        }

        else if (x == 2)//customer mode
        {
            float sum = 0;
            while (x == 2)//loop to adding products
            {
                cout << "the products :" << endl;
                for (int j = 0; j < product.size(); j++)//to display products
                {
                    product[j].display();
                }
                cout << "choose (put the code) your products to add it to your chart" << endl;
                int p_code;
                cin >> p_code;//user select product
                for (int z = 0; z < product.size(); z++)//if he wants one or more products
                {

                    bool con = 0;
                    if (p_code == product[z].get_code())//check code he inputs
                    {
                        chart.push_back(product[z]);
                        con = 1;
                        w=1;
                    }



                    if (con)//if he enter valid code the (if) condition wiil excuite
                    {
                        cout << "How many Pieces do you want ?" << endl; //to know how much he wants
                        int quan;
                        cin >> quan;
                        if (product[z].isqun(quan))//check the amount he wants is exist
                        {
                            cout << "there is not that quantity " << endl;
                            break;
                        }
                        product[z].m_quantity(quan);
                        sum = (product[z].money(sum, quan));
                    }
                }
                if(w==0) //to check input (code) is right
                {
                    cout << "it isn't right code, try again."<<endl;
                }

                cout << "If you want to add more products, press 2. If you want to stop adding, press 1" << endl;
                cin >> x;
                w=0;
            }
            float money,rest;
            money = sum - 1;

            while (money < sum&& sum!=0)//to calc the sum of money
            {
                cout << "the total sum: " << sum << "\n" << "please enter your money" << endl;
                cin >> money;
                if (money > sum)//to calc the rest of money
                {
                    rest = money - sum;
                    cout << "your rest is " << rest << endl;
                    cout << "thank you" << endl;
                }
                else if (money == sum)
                    cout << "thank you" << endl;
                else
                    cout << "you have entered wrong cost , please enter the money again " << endl;

            }
        }
        else if (x != 0)//if input mood is wrong
        {
            cout << "wrong answer , please put 1 or 2 ." << endl;
        }
    }
    return 0;
}
