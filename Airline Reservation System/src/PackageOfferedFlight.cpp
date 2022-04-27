#include <PackageOfferedFlight.h>
string PackageOfferedFlight:: getPackage()
{
	return package;
}

void  PackageOfferedFlight::setPackage(string package)
{
	this->package = package;
}
int  PackageOfferedFlight::getPrice()
{
	return price;

}
void  PackageOfferedFlight::setPrice(int price)
{
	this->price = price;
}