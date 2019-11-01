/**
 DSPD Project
 Authors: 
 Saumya Gandhi BT18CSE067
 Surbhi Agrawal BT18CSE072
 **/

#include <stdio.h>
#include <string.h>
//#include <conio.h>
//declaration of product structure
typedef struct
{
    char category[20];
    int ide_code;
    char brand[20];
    char prod_name[40];
    int price;
    char colour[20];
    int stock;
    char dealer[20];
    int offers[3];
    char quantity[10];
} PRODUCT;

typedef struct
{
    int ide_code;
    int quantity;
    char review[50];
    int rating;
} HISTORY;

//declaration of user structure
typedef struct
{
    char id[20];
    char password[20];
    char name[40];
    char address[100];
    HISTORY hist[20];
} USER;

// Initialization of products database
PRODUCT prod_list[20] = {{"food", 11, "cadbury", "oreo", 20, "vanilla", 5, "mani&sons", {18, 0, 0}, "20g pack"},
                         {"food", 12, "quaker", "almonds", 300, "natural", 23, "mani&sons", {270, 0, 0}, "250g"},
                         {"food", 13, "quaker", "oats", 150, "vanilla", 10, "mani&sons", {135, 0, 0}, "250g"},
                         {"food", 14, "hersheys", "nutella", 300, "chocolate", 5, "mani&sons", {270, 0, 0}, "250g"},
                         {"mobiles", 21, "apple", "iphone 11 pro", 90000, "blue", 11, "mango", {81000,100,18000}, 1},
                         {"mobiles", 22, "google", "pixel 4", 90000, "not all white", 4, "nopixel", {81000,100,18000}, "1"},
                         {"mobiles", 23, "one plus", "one plus", 50000, "black", 50, "oneplusindia", {45000,100,10000},"1"},
                         {"mobiles", 24, "samsug", "samsung galaxy s10", 80000, "black", 30, "cloudtail", {72000,100,16000},"1"},
                         {"books", 31, "bloomsbury", "the anarchy", 250, "softbound", 10, "cloudtail", {225, 0, 0},"1"},
                         {"books", 32, "bloomsburry", "the institute", 700, "hardbound", 3, "anush", {630, 0, 0},"1"},
                         {"books", 33, "harvil secker", "homo deus", 300, "softbound", 15, "kobo", {270, 0, 0},"1"},
                         {"books", 34, "random house", "norweign wood", 150, "softbound", 10, "lolo", {135, 0, 0}, "1"},
                         {"men's fashion", 41, "diesel", "tshirt-m", 1000, "black", 7, "shopclues", {900,100, 0},"1"},
                         {"men's fashion", 42, "diesel", "shirt", 2000, "blue", 13, "shopnoclues", {1800, 100, 0},"1"},
                         {"men's fashion", 43, "levis", "jeans-m", 2000, "white", 2, "shopclues", {1800, 100, 0},"1"},
                         {"men's fashion", 44, "adidas", "shoes", 5000, "yellow", 20, "dcathlon", {4500, 100, 0},"1"},
                         {"women's fashion", 51, "hnm", "dress", 3000, "black", 7, "myspace", {0,100, 0},"1"},
                         {"women's fashion", 52, "hnm", "tshirt-f", 1500, "red", 5, "seezz", {0,100, 0},"1"},
                         {"women's fashion", 53, "levis", "jeans-f", 2500, "blue", 4, "myntra", {0,100, 0},"1"},
                         {"women's fashion", 54, "forever 21", "jacket", 3000, "yellow", 10, "F21", {0,100, 0},"1"}};

//Initialization of user database
USER users[6] = {{"surbhi_145", "123new", "surbhi agrawal", "BPCL colony , Mumbai", {{11,0,"",0},{12,0,"",0},{13,0,"",0},{14,0,"",0},{21,0,"",0},{22,0,"",0},{23,0,"",0},{24,0,"",0},{31,0,"",0},{32,0,"",0},
                {33,0,"",0},{33,0,"",0},{34,0,"",0},{41,0,"",0},{42,0,"",0},{43,0,"",0},{44,0,"",0},{51, 1, "excellent", 5},{52,0,"",0},{53,0,"",0},{54,0,"",0}}},
                 {"saumballs", "66669999", "saumya gandhi", "SMGSK, Gurgaon", {{11,0,"",0},{12,0,"",0},{13,0,"",0},{14,0,"",0},{21,0,"",0},{22,0,"",0},{23,0,"",0},{24,0,"",0},{31,0,"",0},{32,0,"",0},
                 {33,0,"",0},{33,1,"excellent",4},{34,0,"",0},{41,0,"",0},{42,0,"",0},{43,0,"",0},{44,0,"",0},{51,0,"",0},{52,0,"",0},{53,0,"",0},{54,0,"",0}}},
                 {"zac", "toocoolboy", "zac efron", "PTSD, Mumbai",{{11,0,"",0},{12,0,"",0},{13,0,"",0},{14,0,"",0},{21,0,"",0},{22,0,"",0},{23,0,"",0},{24,0,"",0},{31,0,"",0},{32,0,"",0},
                 {33,0,"",0},{33,1,"excellent",4},{34,0,"",0},{41,0,"",0},{42, 1, "okayishh", 3},{43,0,"",0},{44,0,"",0},{51,0,"",0},{52,0,"",0},{53,0,"",0},{54,0,"",0}} },
                 {"shahkhan", "yesno00", "shah rukh khan", "Mannat, Mumbai", {{11,0,"",0},{12,0,"",0},{13,0,"",0},{14,0,"",0},{21,0,"",0},{22,0,"",0},{23,0,"",0},{24,0,"",0},{31, 2, "excellent", 5},{32,0,"",0},
                 {33,0,"",0},{33,0,"",0},{34,0,"",0},{41,0,"",0},{42,0,"",0},{43,0,"",0},{44,0,"",0},{51,0,"",0},{52,0,"",0},{53,0,"",0},{54,0,"",0}}},
                 {"alia", "okaybye", "alia bhatt", "221B, Baker's Street, Gurgaon", {{11,0,"",0},{12, 1, "good", 3},{13,0,"",0},{14,0,"",0},{21, 1, "the best!", 5},{22,0,"",0},{23,0,"",0},{24,0,"",0},{31,0,"",0},{32,0,"",0},
                 {33,0,"",0},{33,0,"",0},{34,0,"",0},{41,0,"",0},{42,0,"",0},{43,0,"",0},{44,0,"",0},{51,0,"",0},{52,0,"",0},{53,0,"",0},{54,0,"",0}}}};

//required global variables
int num_users = 5;

//function for purchasing products
void purchase()
{
    
}

void createHomePage()
{
    //clrscr();
    system("clear");
    printf("Hello, Welcome to the thrift shop. please select an option from the given menu to continue.\n1. Login\n2. Sign Up\n");
}

void createDispPro(int curr_user)
{
    system("clear");
    printf("Welcome to the market, %s\n", users[curr_user].name);
    printf("---------------------------------------------------------------------------------------\n");
    printf("Sr. No.   Product Name        Brand          %% off using SBI     cashback amount     EMI options\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%-10d%-20s%-15s%-20d%-20d%d\n", i + 1, prod_list[i].prod_name, prod_list[i].brand, prod_list[i].offers[0], prod_list[i].offers[1], prod_list[i].offers[2]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("enter number of the product that you wish to buy. If you wish to go back to previous page, enter 0\n");
    int op;
    scanf("%d", &op);
    if (op == 0)
    {
        createMainPage(curr_user);
    }
    else
    {
        //purchase product
    }
}

int length(char s[])
{
    int count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

int isSubstring(char s1[], char s2[])
{
    int m = length(s1);
    int n = length(s2);
    int flag_main = 0;
    /* slide one by one */
    for (int i = 0; ((i <= n - m) && (flag_main == 0)); i++)
    {
        int j;
        int flag = 1;
        /* For current index i, check for pattern match */
        for (j = 0; ((j < m) && (flag == 1)); j++)
        {    if (s2[i + j] != s1[j])
                {flag = 0;}
        }

        if(flag==0)
        j--;

        if (j == m)
            flag_main = 1;
    }
    return flag_main;
}

int partition(PRODUCT arr[], int low, int high)
{
    int pivot = arr[high].price; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].price < pivot)
        {
            i++; // increment index of smaller element
            PRODUCT temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    PRODUCT t;
    t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;
    return (i + 1);
}

void sort(PRODUCT arr[], int lo, int hi)
{
    if (lo < hi)
    {
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, lo, hi);

        // Separately sort elements before
        // partition and after partition
        sort(arr, lo, pi - 1);
        sort(arr, pi + 1, hi);
    }
}

void displaySearchMatch(PRODUCT search_match[], int count_matches)
{
    printf("----------------------------------------------------\n");
    printf("Sr. No.   Product Name        Brand Name     Price     \n");
    for (int i = 0; i < count_matches; i++)
    {
        printf("%-10d%-20s%-15s%-10d\n", i + 1, search_match[i].prod_name, search_match[i].brand, search_match[i].price);
    }
    printf("----------------------------------------------------\n");
    printf("enter number of the product that you wish to buy. If you wish to go back to previous page, enter 0\n");
}

void createSearchPage(int curr_user)
{
    system("clear");
    printf("Welcome to the market, %s\n1.Search by category\n2.Search by product name\n3.Search by colour\n4.Search by brand name\nEnter number according to the type of search required\n", users[curr_user].name);
    int op;
    scanf("%d", &op);
    int count_matches = 0;
    char search_string[20];
    PRODUCT search_match[20];
    if (op == 1)
    {
        printf("Search by category:");
        scanf("%s",search_string);
        for (int i = 0; i < 20; i++)
        {
            if (isSubstring(search_string,prod_list[i].category)==1)
            {
                search_match[count_matches] = prod_list[i];
                count_matches++;
            }
        }
    }
    else if (op == 2)
    {
        printf("Search by product name:");
        scanf("%s",search_string);
        for (int i = 0; i < 20; i++)
        {
            if (isSubstring(search_string, prod_list[i].prod_name))
            {
                search_match[count_matches] = prod_list[i];
                count_matches++;
            }
        }
    }
    else if (op == 3)
    {
        printf("Search by colour:");
        scanf("%s",search_string);
        for (int i = 0; i < 20; i++)
        {
            if (isSubstring(search_string, prod_list[i].colour))
            {
                search_match[count_matches] = prod_list[i];
                count_matches++;
            }
        }
    }
    else if (op == 4)
    {
        printf("Search by brand name:");
        scanf("%s",search_string);
        for (int i = 0; i < 20; i++)
        {
            if (isSubstring(search_string, prod_list[i].brand))
            {
                search_match[count_matches] = prod_list[i];
                count_matches++;
            }
        }
    }
//    printf("\n\n--------%d-------\n\n",length(search_string));
    sort(search_match, 0, count_matches - 1);
    displaySearchMatch(search_match,count_matches);
    scanf("%d",&op);
    if(op==0)
    {
        createMainPage(curr_user);
    }
    else
    {
        //purchase product
    }
    
}

void createMainPage(int curr_user)
{
    system("clear");
    printf("Welcome to the market, %s\n1.View all products and offers\n2.search product\n3.logout", users[curr_user].name);
    int op;
    scanf("%d", &op);
    if (op == 1)
    {
        createDispPro(curr_user);
    }
    else if (op == 2)
    {
        createSearchPage(curr_user);
    }
    else
    {
        createHomePage();
    }
}

void createLogInPage()
{
    //clrscr();
    system("clear");
    int login = 0;
    //login
    while (login == 0)
    {
        char id[20];
        char password[20];
        printf("Please Enter your user id\n");
        scanf("%s", id);
        printf("Please Enter your user password\n");
        scanf("%s", password);
        for (int i = 0; i < num_users && login == 0; i++)
        {
            if (strcmp(id, users[i].id) == 0)
            {
                if (strcmp(password, users[i].password) == 0)
                {
                    login = 1;
                    createMainPage(i);
                }
            }
        }

        if (login == 0)
            printf("The User name or password that you entered is incorrect. Please try again.\n");
    }
}

void createSignUpPage()
{
    //    clrscr();
    system("clear");
    printf("Please Enter your Full Name\n");
    scanf("%s", users[num_users].name);
    printf("Please Enter a valid Username\n");
    scanf("%s", users[num_users].id);
    printf("Please Enter a valid Password\n");
    scanf("%s", users[num_users].password);
    printf("Please Enter your Address\n");
    scanf("%s", users[num_users].address);
    num_users++;
    printf("Please select a valid option to continue \n1. continue with this account\n2. sign in to another account\n");
    int option2;
    scanf("%d", &option2);
    if (option2 == 1)
    {
        createMainPage(num_users - 1);
    }
    else
    {
        createLogInPage();
    }
}

void main()
{
    createHomePage();
    int option1;
    scanf("%d", &option1);
    int user_length = 5;

    if (option1 == 2)
    {
        createSignUpPage();
    }
    else
    {
        createLogInPage();
    }
}
