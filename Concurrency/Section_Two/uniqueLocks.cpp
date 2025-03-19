/**
 * @file uniqueLocks.cpp
 * @author Abhishek
 * @brief Here we discuss about unique locks:
 * 1- fixing the dead lock.
 * 2- Showing the transfer of ownership via unique locks.
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <mutex>
#include <thread>
#include <string>


/***************************************************Example 1 ******************************************/
class bank_account {
	double balance;
	std::string name;
	std::mutex m;

public:
	bank_account() {};

	bank_account(double _balance, std::string _name) :balance(_balance), name(_name) {}

    int checkBalance()
    {
        return balance;
    }

	bank_account(bank_account& acc) = delete;
	bank_account& operator=(bank_account& acc) = delete;

	void withdraw(double amount)
	{
		std::lock_guard<std::mutex> lg(m);
		balance -= amount;
	}

	void deposite(double amount)
	{
		std::lock_guard<std::mutex> lg(m);
		balance += amount;
	}

	void transfer(bank_account& from, bank_account& to, double amount)
	{

		std::cout << std::this_thread::get_id() << " hold the lock for both mutex \n";

        //Possible solution to the dead lock
		std::unique_lock<std::mutex> ul_1(from.m, std::defer_lock);     //defer_lock just avoids locking a mutex while construction of unique lock.
		std::unique_lock<std::mutex> ul_2(to.m, std::defer_lock);
		std::lock(ul_1, ul_2);  //This results in acquiring a lock for either one of the unique locks, hence solving dead lock seen earlier.

		from.balance -= amount;
		to.balance += amount;
		std::cout << "transfer to - " << to.name << "   from - " << from.name << "  end \n";
	}
};

void run_code1()
{

	bank_account account;

	bank_account account_1(1000, "james");
	bank_account account_2(2000, "Mathew");

	std::thread thread_1(&bank_account::transfer, &account, std::ref(account_1), std::ref(account_2), 500);
	std::thread thread_2(&bank_account::transfer, &account, std::ref(account_2), std::ref(account_1), 200);

	thread_1.join();
	thread_2.join();

	//Fetching the balance
	std::cout << "account_1 balance : " << account_1.checkBalance() << std::endl;
	std::cout << "account_2 balance : " << account_2.checkBalance() << std::endl;
}



/***************************************************Example 2******************************************/

void x_operations()
{
	std::cout << "this is some operations \n";
}

void y_operations()
{
	std::cout << "this is some other operations \n";
}

std::unique_lock<std::mutex> get_lock()
{
	std::mutex m_local;
	std::unique_lock<std::mutex> lk(m_local);
	x_operations();
	return lk;
}

void run_code2()
{
	std::unique_lock<std::mutex> lk(get_lock());
	y_operations();
}

int main()
{
	//run_code1();
	run_code2();

	return 0;
}