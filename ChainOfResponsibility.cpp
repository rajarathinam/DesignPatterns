#include <iostream>
class Number
{
public:
    Number(int number):m_number(number){}
    int getNumber()
    {
        return m_number;
    }
private:
    int m_number;
};

class  IProcessingObject
{
    public:
    virtual  void process(Number* number) = 0;
    virtual void setNext(IProcessingObject* ) = 0;

};

class NegativeNumberProcessor: public IProcessingObject
{
public:
    void process(Number* number)
    {
        if( number->getNumber() < 0)
        {
            std::cout << "processed -ve number\n";
        } else {
       std::cout << "Forwarding to another processor";
        }
    }
    void setNext(IProcessingObject* nextProcessor)
    {
        m_nextProcessor = nextProcessor;
    }
private:
    IProcessingObject *m_nextProcessor;
};

class ZeroNumberProcessor: public IProcessingObject
{
public:
    void process(Number* number)
    {
        if( number->getNumber() == 0)
        {
            std::cout << "processed zero number\n";
        } else {
            std::cout << "Forwarding to another processor";
        }
    }
    void setNext(IProcessingObject* nextProcessor)
    {
        m_nextProcessor = nextProcessor;
    }
private:
    IProcessingObject *m_nextProcessor;
};

class PositiveNumberProcessor: public IProcessingObject
{
public:
    void process(Number* number)
    {
        if( number->getNumber() > 0)
        {
            std::cout << "processed positive number\n";
        } else {
            std::cout << "Forwarding to another processor";
        }
    }
    void setNext(IProcessingObject* nextProcessor)
    {
        m_nextProcessor = nextProcessor;
    }
private:
    IProcessingObject *m_nextProcessor;
};


#include <map>
#include <string>
int main()
{

    std::map<std::string, int> words;
    words.insert(std::make_pair("raja", 10));
    words.insert(std::make_pair("raja2", 20));
    words.insert(std::make_pair("raja", 30));
    words["raja"] = 100;
    IProcessingObject *processor1 = new NegativeNumberProcessor;
    IProcessingObject *processor2 = new ZeroNumberProcessor;
    IProcessingObject *processor3 = new PositiveNumberProcessor;

    processor1->setNext(processor2);
    processor2->setNext(processor3);

    return 0;
}
