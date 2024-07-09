#include <iostream>
#include <iomanip> 
using namespace std;
const int SIZE = 5; // Array size.

class VendingMachine {
public:
    int total = 0;
    bool owe = true;
    void addItems(int num) {
      total += items[num];
    }

    void removeItem(int num) {
      total -= items[num];
    }

    int getTotal() {
      return total;
    }

    void moneyIn() {
      cout << "Enter money: \n";
      int money;
      cin >> money;
      total = money - total;

      if (total < 0) {
        total = abs(total);
        cout << "Still owe: $" <<total << endl;
        
      }else {
        cout << "Your change is: $" << total << endl;
        owe = false;
      }
    }

private:
  double items[SIZE] = {5.00, 1.00, 3.00, 2.00, 4.00};
};

int main() {
  cout << "-------- Vending Machine Project -------\n";
  cout << "--------     By: Sophia Lopez    -------\n";
  cout << "--------     Date: 07/08/2024    -------\n\n";

  cout << "Enter 1 through 5 to select your item(s) or enter -1 to exit\n";
  cout << "1. Coke             $5.00\n";
  cout << "2. Chips            $1.00\n";
  cout << "3. Candy            $3.00\n";
  cout << "4. Gum              $2.00\n";
  cout << "5. Water            $4.00\n";
  cout << "Enter 1 through 5 to select your item(s)\n";

  int input = 0;
  VendingMachine v;
  cin >> input;
  while (input != -1) {
    v.addItems(input - 1);
    cin >> input;
  }
  
  cout << "Your total is: $" << v.getTotal() << endl;
  
  while (v.owe) {
    v.moneyIn();
  }

  cout << "Thank you for using the vending machine!\n";
}
