#include <iostream>

using namespace std;


//receiver
class StockTrade
{
public:
    void buy()
    {
        std::cout << "Buy Stock\n";
    }

    void sell()
    {
        std::cout << "Sell Stock\n";
    }
};

class ICommandOrder
{
public:
    virtual void execute() = 0;
};

class BuyCommandOrder: public ICommandOrder
{
public:
    BuyCommandOrder(StockTrade *stock_trade)
    {
        m_stock_trade = stock_trade;
    }
    void execute()
    {
        m_stock_trade->buy();
    }
  private:
      StockTrade *m_stock_trade;
};


class SellCommandOrder: public ICommandOrder
{
public:
    SellCommandOrder(StockTrade *stock_trade)
    {
        m_stock_trade = stock_trade;
    }
    void execute()
    {
      m_stock_trade->sell();
    }
private:
    StockTrade *m_stock_trade;
};


//Invoker
class InvokerAgent
{
public:
    void placeOrder(ICommandOrder *order)
    {
        order->execute();
    }
};

int main()
{
    StockTrade *p_stock_trade = new StockTrade;
    BuyCommandOrder *buyCommand = new BuyCommandOrder(p_stock_trade);
    SellCommandOrder *sellCommand = new SellCommandOrder(p_stock_trade);

    InvokerAgent *invokerAgent = new InvokerAgent;
    invokerAgent->placeOrder(buyCommand);
    invokerAgent->placeOrder(sellCommand);
    return 0;
}
