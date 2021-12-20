#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h> // functions tolower toupper

// #include "menu.h" // under main instead
void uiShopMenuDisplay(char,int);
void shopMenuDisplay();
void shopMenuDisplayHeader(char []);
void shopMenuDisplayFooter();
void shopMenuLiveDisplayHeader();
void shopMenuLiveDisplay();

// symbolic name constants
#define MAX_CHARACTERS 49 // display purposes only
#define SHOPPINGLIST 10
#define MIN 20
#define MED 35
#define MAX 50

struct Product {
    char* name;
    double price;
}; // original source code

struct ProductStock {
    struct Product product;
    int quantity;
}; // original source code

struct Shop {
    double cash;
    // struct ProductStock stock[20]; // original source code
    struct ProductStock stock[MIN];
    int index;
};

struct Customer {
    char* name;
    double budget;
    // struct ProductStock shoppingList[10]; // original source code
    struct ProductStock shoppingList[SHOPPINGLIST];
    int index;
}; // original source code

/* 
 * 
 * Amend function printProduct to only display the product name via:
 * i. option 2 "Read Orders".
 *
 */
void printProduct(struct Product p) // original source code
{
    if (p.price!=0) // option 1 "Shop Inventory"
        printf("PRODUCT NAME: %s \nPRODUCT PRICE: EUR%.2f\n", p.name, p.price); // original source code
    else // option 2 "Read Orders"
        printf("PRODUCT NAME: %s \n",p.name); // display name only
    printf("-------------\n"); // original source code
}

/* 
 * 
 * Amend function printCustomer (signature: "void printCustomer(struct Customer c)") having:
 *   i. the same functionality as before;
 *  ii. updating shop state and;
 * iii. return shop state to function main. 
 *
 */
struct Shop printCustomerUpdateShopState(struct Customer c, struct Shop s)
{
    int countNoProductMatch=0; // cart shop iterations
    double shoppingCartInvoice=0; // empty until add
    int canFillFullOrder=1; // assume is true
    int countOuterCustomer=0,countInnerShop=countOuterCustomer; // then full order

    // printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget); // original source code 
    printf("\n\n\nCUSTOMER NAME: %s \nCUSTOMER BUDGET: EUR%.2f\n", c.name, c.budget);  // display purposes only
    printf("-------------\n"); // original source code

    /*
     * for each customers
     */
    for(int i = 0; i < c.index; i++) // original source code
    {
        int countShopIterations=0; // cart shop iterations
        countNoProductMatch=0; // reset next customer

        printProduct(c.shoppingList[i].product); // original source code
        printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity); // original source code
        uiShopMenuDisplay('-',13); putchar('\n'); // display purposes only     

        /*
         * iterate all stock
         */
        for (int j=0;j<s.index;j++) // update stop state
        {
            // double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price; // original source code
            double cost=c.shoppingList[i].quantity*s.stock[j].product.price; // product full cost
            countShopIterations++; // latter compare countNoProductMatch 

            if (strcmp(c.shoppingList[i].product.name,s.stock[j].product.name)==0) // shop stocks product
            {
                printf("The cost to %s will be EUR%.2f\n", c.name, cost); // original source code
                uiShopMenuDisplay('-',13); putchar('\n'); // display purposes only
            }
            else
                countNoProductMatch++; // determines product existence

            if (strcmp(c.shoppingList[i].product.name,s.stock[j].product.name)!=0) // product not exist
                continue; // continue sanity checking
            else if (c.shoppingList[i].quantity>s.stock[j].quantity) // exceed shop quantity
            {
                if (s.stock[j].quantity<=0) // product all gone
                {
                    printf("(Invalid Shop Quantity: Out of Stock)   >>> %s\n",
                        c.shoppingList[i].product.name); // thrown appropriate error
                    printf("The cost to %s will be EUR0.00\n", c.name); // thrown appropriate error
                }
                else
                {
                    printf("(Invalid Shop Quantity: Quantity Limit) >>> %d\n",
                        s.stock[j].quantity); // thrown appropriate error
                    shoppingCartInvoice+=s.stock[j].quantity*s.stock[j].product.price; // product partial cost 
                    printf("The cost to %s will be EUR%.2f\n",
                        c.name,s.stock[j].quantity*s.stock[j].product.price); // thrown appropriate error                  
                }
                uiShopMenuDisplay('-',13); putchar('\n'); // display purposes only
                canFillFullOrder=0; // partial order false
            }
            else if (c.budget<cost) // budget not allowing
            {
                int canOnlyAfford=(int)(c.budget/s.stock[j].product.price); // price into budget                
                
                if (canOnlyAfford>=(int)c.budget) // complete partial order
                {
                    printf("Unfortunately %s has a budget of EUR%0.2f\n",c.name,c.budget); // display purposes only
                    shoppingCartInvoice+=canOnlyAfford*s.stock[j].product.price; // update cart affordability 
                    c.budget-=canOnlyAfford*s.stock[j].product.price; // reduce budget accordingly
                    printf("%s can only afford %d %s at a cost of EUR%0.2f\n",
                        c.name,canOnlyAfford,s.stock[j].
                        product.name,canOnlyAfford*s.stock[j].product.price); // display purposes only
                    c.shoppingList[i].quantity=canOnlyAfford; // quanitity shop state
                }
                else
                {
                    c.shoppingList[i].quantity-=c.shoppingList[i].quantity; // quanitity shop state
                    printf("Unfortunately %s cannot purchase any %s\n",
                        c.name,s.stock[j].product.name); // display purposes only
                }
                uiShopMenuDisplay('-',13); putchar('\n'); // display purposes only
                canFillFullOrder=0; // now partial order
            }
            else if (c.budget>=cost) // all going well
            {
                shoppingCartInvoice+=cost; // add to cart
                c.budget-=shoppingCartInvoice; // reduce down budget    
            }
            
            s.stock[j].quantity-=c.shoppingList[i].quantity; // quanitity shop state

            if (s.stock[j].quantity<0) // shop negative quantities                
                s.stock[j].quantity=0; // quanitity shop state
            
            countInnerShop++; // full partial order

        } 

        /*
         * onto next customer
         */        
        if (countShopIterations==countNoProductMatch) // iteration no match
        {
            printf("(Invalid Shop Product: <NOT IN STOCK>)  >>> %s\n",
                c.shoppingList[i].product.name); // thrown appropriate error
            printf("The cost to %s will be EUR0.00\n", c.name); // thrown appropriate error
            uiShopMenuDisplay('-',13); putchar('\n'); // display purposes only
        }

        countOuterCustomer++; // full partial order

    } 

    /*
     * all customers done
     */
    if (shoppingCartInvoice>0) 
    {
        if (canFillFullOrder==1 && countInnerShop==countOuterCustomer)
            printf("(Completed <FULL> Order: Now Due)       >>> EUR%0.2f\n",
                shoppingCartInvoice); // display full order
        else
            printf("(Completed <PARTIAL> Order: Now Due)    >>> EUR%0.2f\n",
                shoppingCartInvoice); // display partial order
    }
    else
        printf("(Invalid Order: <NIL> Shopping Cart)    >>> EUR%0.2f\n",shoppingCartInvoice); // thrown appropriate error

    s.cash+=shoppingCartInvoice; // cash shop state

    return s; // full shop state
}

/* 
 * 
 * Function printShop having no original functionality changed:
 * i. minor amendments for display purposes only.
 *
 */
void printShop(struct Shop s) // original source code
{
    printf("Shop has %.2f in cash\n", s.cash); // original source code
    uiShopMenuDisplay('_',24); printf("\n\n"); // display partial order
    for (int i = 0; i < s.index; i++) // original source code
    {
        printProduct(s.stock[i].product); // original source code
        printf("The shop has %d of the above\n", s.stock[i].quantity); // original source code
        uiShopMenuDisplay('-',13); printf("\n");  // partial order display
    }
}

/* 
 * 
 * Amend function createAndStockShop (otherwise unchanged) having:
 *   i. error message displayed (before exit) if the file (stock.csv) cannot be located (or name is changed).
 * Additional:
 *  ii. memory allocation for product name returning pointer of type char via type cast (pointer of type char) and;
 * iii. using a symbolic name (MAX) of size 50 (times type char) to allocate memory on the fly.
 * Additional:
 *  iv. closing file (stock.csv) after reading (returning the shop state to main - now in memory).
 * 
 */
struct Shop createAndStockShop()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("../stock.csv", "r");
    if (fp == NULL)
    {
        shopMenuDisplayHeader("ERROR - stock.csv!"); // display purposes only
        exit(EXIT_FAILURE);
    }

    read = getline(&line, &len, fp);
    float cash = atof(line);
    // printf("cash in shop is %.2f\n", cash);
    
    struct Shop shop = { cash };

    while ((read = getline(&line, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s IS A LINE", line);
        char *n = strtok(line, ",");
        char *p = strtok(NULL, ",");
        char *q = strtok(NULL, ",");
        int quantity = atoi(q);
        double price = atof(p);

        // char *name = malloc(sizeof(char) * 50); // original source code
        char *name=(char *)malloc(sizeof(char)*MAX); // pointer not NULL

        strcpy(name, n);
        struct Product product = { name, price };
        struct ProductStock stockItem = { product, quantity };
        shop.stock[shop.index++] = stockItem;
        // printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
    }
    
    fclose(fp); // close CSV file

    return shop;
}

/* 
 * 
 * Function readCustomerCSVFile using most of the original functionality in function createAndStockShop.
 *
 */
struct Customer readCustomerCSVFile()
{   
    char *ptrNameCSV=(char *)malloc(sizeof(char)*MIN); // memory CSV name
    char filePathCSV[]="../"; // initially change directory
    FILE *fp=NULL; // CSV nullptr nil
    char *line=NULL; // address of first
    size_t len=0; // input buffer size
    ssize_t read; // size_t signed type
    printf("(Valid Input: Name - excluding '.csv')  >>> "); // CSV name only
    scanf("%s",ptrNameCSV); // scan CSV name    
    for (int i=0;ptrNameCSV[i];i++) ptrNameCSV[i]=tolower(ptrNameCSV[i]); // convert to lowercase
    strcat(filePathCSV,strcat(ptrNameCSV,".csv")); // CSV order path
    if ((fp=fopen(filePathCSV,"r"))!=NULL)  // open and test
    {
        read=getline(&line,&len,fp); // read name budget
        char *n=strtok(line,","); // break line token 
        char *b=strtok(NULL,","); 
        char *name=(char *)malloc(sizeof(char)*MAX); // memory customer name
        strcpy(name,n); // n to name
        double budget=atof(b); // make it double
        struct Customer customer={name,budget}; // declare struct Customer 
        while ((read=getline(&line,&len,fp))!=-1) // read CSV remainder
        {
            char *n=strtok(line,","); // see above code
            char *q=strtok(NULL,","); 
            int quantity=atoi(q); // make it int
            char *pname=(char *)malloc(sizeof(char)*MED); // memory product name
            strcpy(pname,n); // n to pname
            struct Product product={pname}; // for each item
            struct ProductStock customerItem={product,quantity}; // for each item
            customer.shoppingList[customer.index++]=customerItem; // increment list index
        }

        fclose(fp); // close CSV file

        if (customer.budget==0) // see customer david.csv
            puts("\n\n\n\t\t<<<<<NO MONEY>>>>>"); // display purposes only

        return customer; // finish return customer
    }
    else // file not exist
    { 
        printf("(Invalid File: CSV file does not exist) >>> %s\n",ptrNameCSV); // prompt error message
        char *name=""; // customer not exist
        int budget=0; // therefore no budget
        struct Customer notRealCustomer={name,budget}; // create non-existent customer
        return notRealCustomer; // return dummy customer
    }
}

/* 
 * 
 * Function createCustomerLiveMode via shop menu option 3 "Live Mode" and return live customer.
 *
 */
struct Customer createCustomerLiveMode()
{
    char *name=(char *)malloc(sizeof(char)*MAX); // memory customer name
    char *b=(char *)malloc(sizeof(char)*MIN); // memory customer budget

    shopMenuLiveDisplayHeader(); // display purposes only

    printf("(Valid Input: Customer Name)            >>> "); // display purposes only

    scanf("%s",name); // scan customer name
    name[0]=toupper(name[0]); // first letter uppercase
    for (int i=1;name[i];i++) name[i]=tolower(name[i]); // convert to lowercase        

    printf("(Valid Input: Customer Budget)          >>> EUR"); // display purposes only
    scanf("%s",b); // scan customer budget
    double budget=atof(b); // make it double 
    while (budget<=0) // error check budget
    {
        //printf("(Valid Input: Customer Budget)          >>> EUR"); // display purposes only
        scanf("%s",b); // rescan customer budget
        budget=atof(b); // make it double
    }

    struct Customer c={name,budget}; // declare struct Customer

    return c; // customer live mode
}

/* 
 * 
 * Function createLiveModeCheckout passing live customer via function createCustomerLiveMode and return cart.
 * 
 */
struct Customer createLiveModeCheckout(struct Customer cart)
{
    enum 
    {
        user=-2, // initial user state
        exit=0, // true then exit
        addProductToCart=1, // customer seeking product
    } customerCartChoice; // set integer values [1]
    int quantity; // cart product quantity

    shopMenuLiveDisplayHeader(); // display purposes only

    struct Product product; // declare struct Product
    struct ProductStock customerItem; // declare struct ProductStock

    while (user!=exit) // -2 != 0
    {    
        char *pname=(char *)malloc(sizeof(char)*MED); // memory product name

        shopMenuLiveDisplay(); // display purposes only

        if (scanf("%d",&customerCartChoice)!=1) // not a number
        {
            while((getchar())!='\n'); // clear input buffer [3][4]
        }  
        else // user choice good
        {
            switch(customerCartChoice) // user input dependent
            {
                case exit: // alternative case 0
                    return cart; // send back cart
                    break;
                case addProductToCart: // alternative case 1
                    printf("(Valid Input: Product Name - Case-sensitive!)\n"); // display purposes only
                    printf("(Correct Uppercase/Lowercase Letters)   >>> "); // display purposes only
                    char clearBuffer; // to clear buffer
                    scanf("%c",&clearBuffer); // buffer cleared now
                    scanf("%[^\n]",pname); // scan except newline
                    product.name=pname; // declare struct product
                    product.price=0; // not displaying price

                    printf("(Valid Input: Product Quantity)         >>> "); // display purposes only
                    while (scanf("%d",&quantity)!=1 || quantity<=0) // error sanity check
                    {
                        printf("(Valid Input: Product Quantity)         >>> "); // display purposes only
                        while((getchar())!='\n'); // clear input buffer [3][4]
                    }

                    customerItem.product=product; // add cart product
                    customerItem.quantity=quantity; // add cart quantity
                    cart.shoppingList[cart.index++]=customerItem; // full shopping cart
                    break;
                default:
                    break;                   
            }
        }

    }
    return cart; // live customer basket
}

/* 
 * 
 * Implementation ground zero.
 * 
 */
int main(void)
{
    enum 
    {
        user=-2, // initial user state
        exit=0, // false then exit
        shopInventory=1, // shop option 1
        readOrders=2, // shop option 2
        liveMode=3 // shop option 3
    } shopMenuChoice; // set integer values [1]

    struct Shop shop = createAndStockShop(); // original source code

    system("clear"); // clear screen output [2]
    shopMenuDisplay(); // display purposes only
    
    while (user!=exit) // -2 != 0
    {      
        if (scanf("%d",&shopMenuChoice)!=1) // not a number
        {
            while((getchar())!='\n'); // clear input buffer [3][4]
            shopMenuDisplayHeader("Invalid Choice!!!!"); putchar('\n'); // display purposes only
            shopMenuDisplay(); // display purposes only
        }
        else // user choice good
        {
            switch(shopMenuChoice) // user input dependent
            {
                case exit: // alternative case 0
                    shopMenuDisplayHeader("\tBye!"); putchar('\n'); // display purposes only
                    return 1; // control to main
                case shopInventory: // alternative case 1
                    shopMenuDisplayHeader("1 - Shop Inventory"); putchar('\n'); // display purposes only
                    printShop(shop); // display shop inventory
                    shopMenuDisplayFooter(); // display purposes only
                    break;
                case readOrders: // alternative case 2
                    shopMenuDisplayHeader("2 -  Read Orders"); putchar('\n'); // display purposes only
                    struct Customer customer=readCustomerCSVFile(); // file struct Customer
                    if (customer.name!="" && customer.budget!=0) // readCustomerCSVFile not notRealCustomer
                        shop=printCustomerUpdateShopState(customer,shop); // update shop state
                    shopMenuDisplayFooter(); // display purposes only
                    break;
                case liveMode: // alternative case 3 
                    shopMenuDisplayHeader("  Shop Inventory"); putchar('\n'); // display purposes only
                    printShop(shop); // display shop inventory
                    struct Customer liveCustomer=createCustomerLiveMode(); // create live customer
                    struct Customer liveCustomerCart=createLiveModeCheckout(liveCustomer); // create shopping basket
                    system("clear"); // clear screen output [2]
                    shop=printCustomerUpdateShopState(liveCustomerCart,shop); // update shop state
                    shopMenuDisplayFooter(); // display purposes only
                    break;                                  
                default: // outside range [0,3]
                    shopMenuDisplayHeader("Invalid Choice!!!!"); putchar('\n'); // display purposes only
                    shopMenuDisplay(); // display purposes only
                    break;
            }
        }
    }
    return 0;
}
    
/* 
 *
 * References:
 * [1] https://www.geeksforgeeks.org/enumeration-enum-c/
 * [2] https://www.includehelp.com/c-programming-questions/how-to-clear-output-screen-in-c.aspx
 * [3] https://www.geeksforgeeks.org/use-fflushstdin-c/
 * [4] https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
 *
 */

/* 
 * 
 * Display purposes only (no functionality).  
 *
 */

void uiShopMenuDisplay(char c, int n)
{
    for (int i=0;i<n;i++)
        putchar(c);
} // display purposes only

void shopMenuDisplay()
{
    uiShopMenuDisplay('+',MAX_CHARACTERS); 
    puts("\n\t\t------ SHOP ------");
    puts("\t\t1 - Shop Inventory");
    puts("\t\t2 -  Read Orders");
    puts("\t\t3 -   Live Mode");
    puts("\t\t0 -     Exit");
    uiShopMenuDisplay('+',MAX_CHARACTERS);
    printf("\n(Valid Input: 0 or 1 or 2 or 3)\t\t>>> ");
} // display purposes only

void shopMenuDisplayHeader(char s[])
{
    system("clear"); // clear screen output [2]
    uiShopMenuDisplay('\n',3); // display range [1,3]
    uiShopMenuDisplay('\t',2); puts(s); // display line 4
    uiShopMenuDisplay(' ',16); uiShopMenuDisplay('-',18); // display line 5
    uiShopMenuDisplay('\n',3); // display range [6,8]
} // display purposes only

void shopMenuDisplayFooter()
{
    uiShopMenuDisplay('\n',3); // display range [1,3]
    uiShopMenuDisplay(' ',16); uiShopMenuDisplay('-',18); // display line 4
    uiShopMenuDisplay('\n',4); // display range [5,7]                    
    shopMenuDisplay(); // display shop men
} // display purposes only

void shopMenuLiveDisplayHeader()
{
    uiShopMenuDisplay('\n',3);
    uiShopMenuDisplay(' ',16); uiShopMenuDisplay('-',18);
    uiShopMenuDisplay('\n',4);
} // display purposes only

void shopMenuLiveDisplay()
{ 
    uiShopMenuDisplay('+',MAX_CHARACTERS);
    puts("\n\t\t---- LIVE MODE----");
    puts("\t\t1 -  Add to Cart");
    puts("\t\t0 -     Exit");
    uiShopMenuDisplay('+',MAX_CHARACTERS);
    printf("\n(Valid Input: 0 or 1)\t\t\t>>> ");      
} // display purposes only