#include <iostream>
#include <vector>

using namespace std;

class Memento;
class CareTaker
{
public:
    void addMementoToList(Memento *memento)
    {
        m_mementoList.push_back(memento);
    }
    Memento* getMementoFromList(int index)
    {
        return m_mementoList[index];
    }

private:
    std::vector<Memento*> m_mementoList;


};

class Memento
{
public:
    Memento(const std::string& state):m_state (state) {}


    std::string getState()
    {
        return m_state;
    }
        ~Memento(){}
private:

    std::string m_state;
};

class Originator
{
public:
    void  setState(const std::string& state)
    {
        m_state = state;
    }
    std::string getState()
    {
        return m_state;
    }
    Memento* saveStateToMemento()
    {
       return new Memento(m_state);
    }
    void restoreStateFromMemento(Memento* memento)
    {
        m_state = memento->getState();
    }
 private:
    std::string m_state;
};

int main()
{
    CareTaker *careTaker = new CareTaker;
    Originator *originator = new Originator;
    originator->setState("1PM");
    originator->setState("2PM");
    careTaker->addMementoToList(originator->saveStateToMemento());
    originator->setState("3PM");
    originator->setState("4PM");
    careTaker->addMementoToList(originator->saveStateToMemento());
    originator->restoreStateFromMemento(careTaker->getMementoFromList(0));



    return 0;
}
