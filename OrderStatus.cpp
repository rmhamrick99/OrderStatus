#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Order
{
public: 
	void mainLine(void);

private:
	void calculateOrder(int iSpoolsOrdered, int iStock, double dShipping);
	void gatherData();

	int iSpoolsReady;
	int iSpoolsBO;
	double dSubTotal;
	double dTotShip;
	double dTotal;
	int iSpoolsOrdered;
	int iStock;
	string sSpecial;
	double dShipping;

};
void main(void)
{
	Order r1;
	r1.mainLine();
	system("pause");
	return;
}

void Order::mainLine()
{
	gatherData();
}

void Order::calculateOrder(int iSpoolsOrdered, int iStock, double dShipping)
{
	
	if (iSpoolsOrdered < iStock)
	{
		iSpoolsReady = iSpoolsOrdered;
		iSpoolsBO = 0;
	}
	else
	{
		iSpoolsReady = iStock;
		iSpoolsBO = iSpoolsOrdered - iStock;
	}
	dSubTotal = iSpoolsReady * 100;
	dTotShip = iSpoolsReady * 10 + iSpoolsReady * dShipping;
	dTotal = dSubTotal + dTotShip;
	cout << "Spools ready for shipment: " << iSpoolsReady << endl;
	cout << "Spools on backorder: " << iSpoolsBO << endl;
	cout << "Subtotal: " << dSubTotal << endl;
	cout << "Total Shipping Cost: " << dTotShip << endl;
	cout << "Grand Total: " << dTotal << endl;
}

void Order::gatherData()
{
	

	cout << "How many spools where ordered?" << endl;
	cin >> iSpoolsOrdered;
	cout << "How many spools are currently in stock?" << endl;
	cin >> iStock;
	cout << "Are there any special shipping charges?" << endl;
	cin >> sSpecial;
	if (sSpecial == "yes")
	{
		cout << "How much are the special shipping charges per spool?" << endl;
		cin >> dShipping;
	}
	else
	{
		dShipping = 0;
	}
	calculateOrder(iSpoolsOrdered, iStock, dShipping);
}

