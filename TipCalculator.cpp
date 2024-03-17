#include <iostream>
#include <iomanip>
using namespace std;

class Tips
{
private:
	double taxRate;		 

public:
	Tips(double rate)    		
	{                          	
		if (rate >= 0)
			taxRate = rate;
		else
			taxRate = .065;
	}
	double computeTip(double, double);
};

double Tips::computeTip(double price, double tipA)
{
	double mealCost = price * (1 + taxRate);
	double tipAmount = mealCost + tipA;
	cout << "Cost without tax is: " << mealCost << "\n";
	cout << "The total cost is: \n" << tipAmount << "\n";

	return tipAmount;
}
int main()
{

	char choice;

	double taxRate = 0.0;
	double tipAmount = 0.0;
	double price = 0.0;
	double tipPercent = 0.0;
	double mealCost = 0.0;

	cout << "Enter the tax rate.";
	cin >> taxRate;
	taxRate /= 100;

	Tips rates(taxRate);

	do
	{
		cout << "\n\n************* Tip Helper *********** \n\n";

		cout << "Enter the total amount of the meal: ";
		cin >> price;

		cout << "Enter the % tip you want to leave: ";
		cin >> tipPercent;

		tipAmount = rates.computeTip(price, tipPercent);

		cout << "Do you want to compute another tip (Y/N)?";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	return 0;
}
