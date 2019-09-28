#include <iostream>

using namespace std;


class Trip
{
public:
    Trip() {}
    virtual void day1Visit() = 0;
    virtual void day2Visit() = 0;
    void displayItinerary()
    {
        day1Visit();
        day2Visit();
    }
    virtual ~Trip() {}

};

class TourPackage1:public Trip
{
public:
    void day1Visit()
    {
        std::cout << " Visit Beach \n";
    }
    void day2Visit()
    {
        std::cout << " Visit Mountain\n";
    }
};


class TourPackage2:public Trip
{
public:
    void day1Visit()
    {
        std::cout << " Visit Zoo\n";
    }
    void day2Visit()
    {
        std::cout << " Visit Mountain\n";
    }
};
int main()
{
    Trip *trip1 = new TourPackage1;
    Trip *trip2 = new TourPackage2;

    trip1->displayItinerary();
    trip2->displayItinerary();

    return 0;
}
