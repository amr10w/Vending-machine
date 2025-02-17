
class products
{

public:
    products() {}
    products(string name,float Price,int pieces,string exp_date,string outlet,int code)//set values of Prepared products
    {
        this -> name = name;
        this -> Price = Price;
        this -> pieces= pieces;
        this -> exp_date= exp_date;
        this ->outlet  = outlet;
        this ->code = code;
    }
    void set_val() //set values of seller products
    {

        cout<<"Please, enter the name of the product"<<endl;
        cin.ignore();
        getline(cin,name);

        cout<<"Please, enter its price"<<endl;
        cin>>Price;
        cout<<"Please, enter its quantity"<<endl;
        cin >>pieces;
        cout<<"Please, enter its expiry date (DD/MM/YYYY)"<<endl;
        cin.ignore();
        getline(cin,exp_date);
        cout<<"Please, enter its distribution company or sales outlet in order"<<endl;
        getline(cin,outlet);
    }
    void set_code(int code)//set code of products
    {
        this -> code =code;
    }
    void display()//display products
    {

        cout<<"name of product is : "<< name <<"\n"<<"price of product is : "<<Price<<"\n"<<"amount of product is : "<<pieces<<"\n"<<"expiry date of product is : "<<exp_date<<"\n"<<"outlet of product is : "<<outlet<<"\n"<<code<<endl;
        cout<<"===========================\n";
    }
    void m_quantity(int n)//Calculate shortage of quantities
    {
        pieces -=n ;
    }
    int get_code()//get code of products
    {
        return code;
    }

    bool isqun (int c_money)//check the amount he wants is exist
    {
        if (c_money > pieces)
            return 1;
        if (c_money <= pieces)
            return 0;
    }
    float money(float e_money,int quantity)//sum
    {
        return e_money+Price*quantity ;
    }
    bool checkExpiry()  // Function to check the expiry date
    {

        time_t currentTime = time(nullptr); // Get the current time
        tm* localTime = localtime(&currentTime);


        tm expiryDate = {};
        sscanf(exp_date.c_str(), "%d/%d/%d", &expiryDate.tm_mday, &expiryDate.tm_mon, &expiryDate.tm_year); // Convert the product's expiry date to a tm structure
        expiryDate.tm_mon -= 1; // Adjust for 0-based month
        expiryDate.tm_year -= 1900; // Adjust for year starting from 1900


        return difftime(mktime(&expiryDate), currentTime) < 0; // Compare the expiry date with the current date
    }



private:
    string name;
    float Price;
    int pieces;
    string exp_date;
    string outlet;
    int code;





};

  void dele_product(vector<products>& v, int ci_code)
  // Function to delete a product based on its code
{
    int pos = -1;

    // Find the position of the product with the specified code
    for (int j = 0; j < v.size() ; j++)
    {
        if (v[j].get_code() == ci_code)
        {
            pos = j;
            break;
        }
    }

    // Check if the product with the specified code was found
    if (pos == -1)
    {
        cout << "Invalid code. Product not found." << endl;
    }

    // Shift products to overwrite the product at the specified position
    for (int i = pos; i < v.size() - 1; i++)
    {
        v[i] = v[i + 1];
    }
    if (pos != -1)
   {
       v.pop_back(); // Remove the last product (which is now a duplicate)
       cout <<"Deleted product"<<endl;
   }
}

 // Function to update product codes to ensure they are in order
 void updateProductCodes(vector<products>& productList)
{
    int newCode = 11768;

    // Update product codes in ascending order
    for (auto& product : productList)
    {
        product.set_code(newCode++);
    }
}
