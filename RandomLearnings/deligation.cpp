#include <iostream>
class receiver
{
    private:
    static receiver *mSelfReceiver;
    receiver()
    {}

    public:
    static receiver* getInstance()
    {
        if(!mSelfReceiver)
            mSelfReceiver = new receiver();
        return mSelfReceiver;
    }

  void do_actual_work()
  {
    std::cout << "Doing actual work for sender: " << std::endl;
  }
};
receiver *receiver::mSelfReceiver = 0;

class sender
{
private:
 receiver *_delegate;
public:
void init()
{
    _delegate = receiver::getInstance();
    _delegate->do_actual_work();
}
  void do_work()
  {
    _delegate->do_actual_work();
  }
};

int main(int argc, char const *argv[])
{
    sender *send = new sender();
    send->init();
    return 0;
}


