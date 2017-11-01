#include <stdio.h>

class Account {
	public:
		Account();
		Account(unsigned n, double b); //constructor given account number and balance
		void deposit(double amt);      //deposit amt to account
		void withdraw(double amt);     // withdraw amt from account
		unsigned id();                 // Get account number
		
	private:
		unsigned acct_no;
		double   acct_bal;
};
