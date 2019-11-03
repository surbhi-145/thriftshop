/**
 DSPD Project
 Authors: 
 Saumya Gandhi BT18CSE067
 Surbhi Agrawal BT18CSE072
 **/

#include <stdio.h>
#include <string.h>
//#include <conio.h>

//declaration of dealer struct
typedef struct 
{   
    int id;
    char category[20];
    char brand[20];
}RECCOMENDATION;

typedef struct 
{
    char name[40];
    int quantity;
}DEALER;

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
    DEALER dealer[5];
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
PRODUCT prod_list[20] = {{"food", 11, "cadbury", "oreo", 20, "vanilla", 24, {{"mani&sons",5},{"AP&sons",5},{"KOOOL",4},{"bare",2},{"hen",8}}, {18, 0, 0}, "20g pack"},
                         {"food", 12, "quaker", "almonds", 300, "natural", 24,{{"mani&sons",3},{"AP&sons",8},{"KOOOL",2},{"bare",10},{"hen",1}}, {270, 0, 0}, "250g"},
                         {"food", 13, "quaker", "oats", 150, "vanilla", 24, {{"mani&sons",5},{"AP&sons",5},{"KOOOL",4},{"bare",2},{"hen",8}}, {135, 0, 0}, "250g"},
                         {"food", 14, "hersheys", "nutella", 300, "chocolate", 33, {{"mani&sons",5},{"AP&sons",4},{"KOOOL",4},{"bare",9},{"hen",11}}, {270, 0, 0}, "250g"},
                         {"mobiles", 21, "apple", "iphone 11 pro", 90000, "blue", 24,{{"mango",5},{"Aer",5},{"gvenvhy",4},{"boulder",2},{"heist",8}}, {81000, 100, 18000}, 1},
                         {"mobiles", 22, "google", "pixel 4", 90000, "not all white", 57, {{"nopixel",8},{"banna",15},{"poltic",14},{"boulder",12},{"heist",8}}, {81000, 100, 18000}, "1"},
                         {"mobiles", 23, "one plus", "one plus", 50000, "black", 24, {{"oneplusindia",5},{"banna",5},{"poltic",4},{"flipmart",2},{"rakesh electronics",8}}, {45000, 100, 10000}, "1"},
                         {"mobiles", 24, "samsug", "samsung galaxy s10", 80000, "black", 48, {{"cloudtail",7},{"banna",15},{"applebottle",6},{"flipmart",2},{"rollo",18}}, {72000, 100, 16000}, "1"},
                         {"books", 31, "bloomsbury", "the anarchy", 250, "softbound", 48, {{"cloudtail",17},{"banna",5},{"applebottle",16},{"flipmart",3},{"rollo",6}}, {225, 0, 0}, "1"},
                         {"books", 32, "bloomsburry", "the institute", 700, "hardbound", 49, {{"anush",17},{"paperboy",15},{"applebottle",2},{"flipmart",12},{"bakehouse",3}}, {630, 0, 0}, "1"},
                         {"books", 33, "harvil secker", "homo deus", 300, "softbound", 49, {{"kobo",17},{"paperboy",15},{"applebottle",2},{"flipmart",12},{"bakehouse",3}}, {270, 0, 0}, "1"},
                         {"books", 34, "random house", "norweign wood", 150, "softbound", 49, {{"lolo",17},{"paperboy",15},{"applebottle",2},{"flipmart",12},{"bakehouse",3}}, {135, 0, 0}, "1"},
                         {"men's fashion", 41, "diesel", "tshirt-m", 1000, "black", 62, {{"shopclues",30},{"pboy",15},{"applebottle",2},{"flipmart",12},{"nowear",3}}, {900, 100, 0}, "1"},
                         {"men's fashion", 42, "diesel", "shirt", 2000, "blue", 62, {{"shopclues",30},{"pboy",15},{"applebottle",2},{"flipmart",12},{"nowear",3}}, {1800, 100, 0}, "1"},
                         {"men's fashion", 43, "levis", "jeans-m", 2000, "white", 62, {{"shopclues",30},{"pboy",15},{"applebottle",2},{"flipmart",12},{"nowear",3}}, {1800, 100, 0}, "1"},
                         {"men's fashion", 44, "adidas", "shoes", 5000, "yellow", 62, {{"dcathlon",30},{"pboy",15},{"applebottle",2},{"flipmart",12},{"nowear",3}}, {4500, 100, 0}, "1"},
                         {"women's fashion", 51, "hnm", "dress", 3000, "black", 100, {{"myspace",40},{"dcathlon",30},{"pboy",15},{"flipmart",12},{"nowear",3}}, {0, 100, 0}, "1"},
                         {"women's fashion", 52, "hnm", "tshirt-f", 1500, "red", 80,{{"seez",20},{"dcathlon",30},{"pboy",15},{"flipmart",12},{"nowear",3}}, {0, 100, 0}, "1"},
                         {"women's fashion", 53, "levis", "jeans-f", 2500, "blue", 90, {{"myntra",30},{"dcathlon",30},{"pboy",15},{"flipmart",12},{"nowear",3}}, {0, 100, 0}, "1"},
                         {"women's fashion", 54, "forever 21", "jacket", 3000, "yellow", 110, {{"F21",50},{"dcathlon",30},{"pboy",15},{"flipmart",12},{"nowear",3}}, {0, 100, 0}, "1"}};

//Initialization of user database
USER users[6] = {{"surbhi_145", "123new", "surbhi agrawal", "BPCL colony , Mumbai", {{11, 0, "", 0}, {12, 0, "", 0}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 0, "", 0}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 0, "", 0}, {32, 0, "", 0}, {33, 0, "", 0}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 0, "", 0}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 1, "excellent", 5}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}},
                 {"saumballs", "66669999", "saumya gandhi", "SMGSK, Gurgaon", {{11, 0, "", 0}, {12, 0, "", 0}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 0, "", 0}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 0, "", 0}, {32, 0, "", 0}, {33, 1, "excellent", 4}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 0, "", 0}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 0, "", 0}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}},
                 {"zac", "toocoolboy", "zac efron", "PTSD, Mumbai", {{11, 0, "", 0}, {12, 0, "", 0}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 0, "", 0}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 0, "", 0}, {32, 0, "", 0}, {33, 1, "excellent", 4}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 1, "okayishh", 3}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 0, "", 0}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}},
                 {"shahkhan", "yesno00", "shah rukh khan", "Mannat, Mumbai", {{11, 0, "", 0}, {12, 0, "", 0}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 0, "", 0}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 2, "excellent", 5}, {32, 0, "", 0}, {33, 0, "", 0}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 0, "", 0}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 0, "", 0}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}},
                 {"alia", "okaybye", "alia bhatt", "221B, Baker's Street, Gurgaon", {{11, 0, "", 0}, {12, 1, "good", 3}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 1, "the best!", 5}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 0, "", 0}, {32, 0, "", 0}, {33, 0, "", 0}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 0, "", 0}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 0, "", 0}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}},
                 {"", "", "", "", {{11, 0, "", 0}, {12, 0, "", 0}, {13, 0, "", 0}, {14, 0, "", 0}, {21, 0, "", 0}, {22, 0, "", 0}, {23, 0, "", 0}, {24, 0, "", 0}, {31, 0, "", 0}, {32, 0, "", 0}, {33, 0, "", 0}, {34, 0, "", 0}, {41, 0, "", 0}, {42, 0, "", 0}, {43, 0, "", 0}, {44, 0, "", 0}, {51, 0, "", 0}, {52, 0, "", 0}, {53, 0, "", 0}, {54, 0, "", 0}}}};

//required global variables
int num_users = 5;

//function for reccomendation
void recommend(int curr_user, int i)
{   
    system("clear");
    printf("Thank you for your feedback\nHere is a list of reccomended products based on your previous purchases\n");
    printf("---------------------------------------------------------------------------------------\n");
    int reccomendation_count = 0;
    RECCOMENDATION rec_ar[20];

    for (int j = 0; j < 20; j++)
    {
        if (users[curr_user].hist[j].quantity != 0)
        {   
            rec_ar[reccomendation_count].category=prod_list[j].category;
            rec_ar[reccomendation_count].brand=prod_list[j].brand;
            rec_ar[reccomendation_count].id=prod_list[j].ide_code;
            reccomendation_count++;
        }

    }

    for(int j=0; j<20; j++)
    {
        for(int i=0; i<reccomendation_count; i++)
        {
            if((prod_list[j].brand==rec_ar[reccomendation_count].brand || prod_list[j].category==rec_ar[reccomendation_count].category) && prod_list[j].ide_code!=rec_ar[reccomendation_count].id)
            {
                printf("Category:%s\nProduct Code:%d\nBrand:%s\nProduct Name:%s\nPrice:%d\nColour:%s\nQuantity:%s\n",
                   prod_list[j].category, prod_list[j].ide_code, prod_list[j].brand, prod_list[j].prod_name, prod_list[j].price,
                    prod_list[j].colour,prod_list[j].quantity);
                printf("---------------------------------------------------------------------------------------\n");
            }
        }
    }

    printf("To continue Further shopping press 1 , to exit press 0\n");
    int end_option;
    scanf("%d", &end_option);
    if (end_option == 0)
    {
        system("clear");
        printf("Thank you for shopping with us\n");
    }

    else
    {
        createSearchPage(curr_user);
    }
}

//function for purchasing products
void purchase(int curr_user, int i)
{
    printf("Welcome to the checkout counter, %s\n", users[curr_user].name);
    printf("This is a summary of the product you wish to buy\n");
    printf("Category:%s\nProduct Code:%d\nBrand:%s\nProduct Name:%s\nPrice:%d\nColour:%s\nDealer:%s\nQuantity:%s\n",
           prod_list[i].category, prod_list[i].ide_code, prod_list[i].brand, prod_list[i].prod_name, prod_list[i].price, prod_list[i].colour,
           prod_list[i].dealer[0].name, prod_list[i].quantity);
    printf("Enter quantity of the product that you would like to buy\n");
    int quantity;
    scanf("%d",&quantity);
    printf("Here are the available payement offers that you can avail:\n");
    printf("----------10 perecnt off using SBI----------\nReduced price: Rs.%d\n----------100 Cashback on using Ppay----------\nReduced price: Rs.%d\n----------5 Month EMI----------\nPrice per month: Rs.%d\n",
           prod_list[i].offers[0]*quantity, prod_list[i].offers[1], prod_list[i].offers[2]*quantity);
    printf("Please select a Payment method from below:\n");
    printf("1.SBI card\n2.Ppay\n3.EMI\n4.Cash\n");
    int pay_option;
    scanf("%d", &pay_option);
    system("clear");
    printf("Congratulations on successful transaction! We will notify you with the time of delivery\n");
    prod_list[i].stock-=quantity;
    users[curr_user].hist[i].quantity+=quantity;
    prod_list[i].dealer[0].quantity-=quantity
    printf("Please Enter a review for the purchased product\n");
    while ((getchar()) != '\n');
    scanf("%[^\n]s",users[curr_user].hist[i].review);
    printf("Please Enter a Rate the product out of 5\n");
    scanf("%d", &users[curr_user].hist[i].rating);
    recommend(curr_user,i);
}

void idConverter(int curr_user, int id)
{
    for (int i = 0; i < 20; i++)
    {
        if (prod_list[i].ide_code == id)
        {
            purchase(curr_user, i);
        }
    }
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
    printf("Sr. No.   Product Name        Brand          10%% off using SBI   cashback amount     EMI installment\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%-10d%-20s%-15s", i + 1, prod_list[i].prod_name, prod_list[i].brand);
        if (prod_list[i].offers[0] == 0)
            printf("-                   ");
        else
        {
            printf("%-20d", prod_list[i].offers[0]);
        }
        if (prod_list[i].offers[1] == 0)
            printf("-                   ");
        else
        {
            printf("%-20d", prod_list[i].price - prod_list[i].offers[1]);
        }
        if (prod_list[i].offers[2] == 0)
            printf("-\n");
        else
        {
            printf("%-20d\n", prod_list[i].offers[2]);
        }
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
        purchase(curr_user, op - 1);
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
        {
            if (s2[i + j] != s1[j])
            {
                flag = 0;
            }
        }

        if (flag == 0)
            j--;

        if (j == m)
            flag_main = 1;
    }
    return flag_main;
}

int partition(PRODUCT arr[], int low, int high)
{
    int pivot = arr[high].price; // pivot
    int i = (low - 1);           // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].price < pivot)
        {
            i++; // increment index of smaller element
            PRODUCT temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    PRODUCT t;
    t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
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
    int flag = 0;
    while (flag == 0)
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
            while ((getchar()) != '\n');
            scanf("%[^\n]s", search_string);
            for (int i = 0; i < 20; i++)
            {
                if (isSubstring(search_string, prod_list[i].category) == 1)
                {
                    search_match[count_matches] = prod_list[i];
                    count_matches++;
                }
            }
        }
        else if (op == 2)
        {
            printf("Search by product name:");
            while ((getchar()) != '\n');
            scanf("%[^\n]s", search_string);
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
            while ((getchar()) != '\n');
            scanf("%[^\n]s", search_string);
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
            while ((getchar()) != '\n');
            scanf("%[^\n]s", search_string);
            for (int i = 0; i < 20; i++)
            {
                if (isSubstring(search_string, prod_list[i].brand))
                {
                    search_match[count_matches] = prod_list[i];
                    count_matches++;
                }
            }
        }

        if (count_matches == 0)
        {
            printf("NO SEARCH RESULTS FOUND\n");
            //creating delay before screen refreshes
            for (long long int i = 0; i < 1000000000; i++)
            {
            }
        }
        else
        {
            flag = 1;
            sort(search_match, 0, count_matches - 1);
            displaySearchMatch(search_match, count_matches);
            scanf("%d", &op);
            if (op == 0)
            {
                createMainPage(curr_user);
            }
            else
            {
                idConverter(curr_user, search_match[op - 1].ide_code);
            }
        }
    }
}

void createMainPage(int curr_user)
{
    system("clear");
    printf("Welcome to the market, %s\n1.View all products and offers\n2.search product\n3.logout\n", users[curr_user].name);
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
        char tc;
        char id[20];
        char password[20];
        printf("Please Enter your user id:");
        while ((getchar()) != '\n');
        scanf("%[^\n]s", id);
        printf("Please Enter your user password:");
        while ((getchar()) != '\n');
        scanf("%[^\n]s", password);
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
    while ((getchar()) != '\n');    
    scanf("%[^\n]s", users[num_users].name);
    printf("Please Enter a valid Username\n");
    while ((getchar()) != '\n');
    scanf("%[^\n]s", users[num_users].id);
    printf("Please Enter a valid Password\n");
    while ((getchar()) != '\n');
    scanf("%[^\n]s", users[num_users].password);
    printf("Please Enter your Address\n");
    while ((getchar()) != '\n');
    scanf("%[^\n]s", users[num_users].address);
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
