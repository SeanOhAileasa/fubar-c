#include <stdio.h>
#include <stdlib.h> // include function system

#define MAX_CHARACTERS 49 // max per line

void uiShopMenuDisplay(char c,int s)
{
    for (int i=0;i<s;i++)
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
    system("clear"); // clear screen output []
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
    shopMenuDisplay();
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