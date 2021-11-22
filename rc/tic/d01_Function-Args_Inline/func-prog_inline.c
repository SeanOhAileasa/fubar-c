/* all involve processing overhead:
 * i.   calling a function and
 * ii)  passing argument values to a function and
 * iii) returning a value from a function 
 * using inline functions eliminates function overheads */
#include <stdio.h>
#include <stdlib.h>
float accountBalance, amount;
/* precede the function declaration/prototype with the keyword ``inline`` */
inline void initializeAccount();
inline void getBalance(void);
inline void askCustomer(void);
inline void updateAccount(float);
inline void addGift(float);
inline void thankYou(void);
int main(void)
{
    initializeAccount(); // accountBalance set zero
    getBalance(); // display current accountBalance
    askCustomer(); // transaction obtain amount
    updateAccount(amount); // update accountBalance amount
    getBalance(); 
    askCustomer(); 
    updateAccount(amount); 
    addGift(5.0); // update accountBalance gift
    getBalance();
    askCustomer();
    updateAccount(amount); 
    addGift(2.0);
    getBalance();
    thankYou(); // output display message
    return 0;
}
void initializeAccount(void)
{
    accountBalance=0.0;
}
void getBalance(void)
{
    printf("\nThe current balance in the account is $%.2f\n",accountBalance);
}
void askCustomer(void)
{
    printf("Next transaction please...\n");
    printf("Enter amount to credit (positive) or debit (negative): ");
    scanf("%f",&amount); // check for number
}
void updateAccount(float amount)
{
    accountBalance+=amount;
    printf("The account was updated with $%.2f\n",amount);
}
void addGift(float giftAmount)
{
    accountBalance+=giftAmount;
    printf("Congratulations! A gift of $%.2f has been added to your account\n",giftAmount);
}
void thankYou(void)
{
    puts("------  Thank you!  ------");
}
