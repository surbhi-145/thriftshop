/**
 DSPD Project
 Authors: 
 Saumya Gandhi BT18CSE067
 Surbhi Agrawal BT18CSE072
 **/

#include <stdio.h>
#include <string.h>

//declaration of product structure
typedef struct
{
    char category[20];
    int ide_code;
    char brand[20];
    char prod_name[40];
    float price;
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

void main()
{
    // Initialization of products database
    PRODUCT prod_list[20] = {{"food", 11, "cadbury", "oreo", 20, "vanilla", 5, "mani&sons", {0, 0, 0}, "20g pack"},
                             {"food", 12, "quaker", "almonds", 300, "natural", 23, "mani&sons", {0, 0, 0}, "250g"},
                             {"food", 13, "quaker", "oats", 150, "vanilla", 10, "mani&sons", {0, 0, 0}, "250g"},
                             {"food", 14, "hersheys", "nutella", 300, "chocolate", 5, "mani&sons", {0, 0, 0}, "250g"},
                             {"mobiles", 21, "apple", "iphone 11 pro", 90000, "blue", 11, "mango", {0, 0, 0}, 1},
                             {"mobiles", 22, "google", "pixel 4", 90000, "not all white", 4, "nopixel", {0, 0, 0}, 1},
                             {"mobiles", 23, "one plus", "one plus", 50000, "black", 50, "oneplusindia", {0, 0, 0}, 1},
                             {"mobiles", 24, "samsug", "samsung galaxy s10", 80000, "black", 30, "cloudtail", {0, 0, 0}, 1},
                             {"books", 31, "bloomsbury", "the anarchy", 250, "softbound", 10, "cloudtail", {0, 0, 0}, 1},
                             {"books", 32, "bloomsburry", "the institute", 700, "hardbound", 3, "anush", {0, 0, 0}, 1},
                             {"books", 33, "harvil secker", "homo deus", 300, "softbound", 15, "kobo", {0, 0, 0}, 1},
                             {"books", 34, "random house", "norweign wood", 150, "softbound", 10, "lolo", {0, 0, 0}, 1},
                             {"men's fashion", 41, "diesel", "tshirt", 1000, "black", 7, "shopclues", {0, 0, 0}, 1},
                             {"men's fashion", 42, "diesel", "shirt", 2000, "blue", 13, "shopnoclues", {0, 0, 0}, 1},
                             {"men's fashion", 43, "levis", "jeans", 2000, "white", 2, "shopclues", {0, 0, 0}, 1},
                             {"men's fashion", 44, "adidas", "shoes", 5000, "yellow", 20, "dcathlon", {0, 0, 0}, 1},
                             {"women's fashion", 51, "hnm", "dress", 3000, "black", 7, "myspace", {0, 0, 0}, 1},
                             {"women's fashion", 52, "hnm", "tshirt", 1500, "red", 5, "seezz", {0, 0, 0}, 1},
                             {"women's fashion", 53, "levis", "jeans", 2500, "blue", 4, "myntra", {0, 0, 0}, 1},
                             {"women's fashion", 54, "forever 21", "jacket", 3000, "yellow", 10, "F21", {0, 0, 0}, 1}};

    //Initialization of user database
    USER users[6] = {{"surbhi_145", "123new", "surbhi agrawal", "BPCL colony , Mumbai", {{51, 1, "excellent", 5}}},
                     {"saumballs", "66669999", "saumya gandhi", "SMGSK, Gurgaon", {{33, 1, "excellent", 4}}},
                     {"zac", "toocoolboy", "zac efron", "PTSD, Mumbai", {{33, 1, "excellent", 4}, {42, 1, "okayishh", 3}}},
                     {"shahkhan", "yesno00", "shah rukh khan", "Mannat, Mumbai", {{31, 2, "excellent", 5}}},
                     {"alia", "okaybye", "alia bhatt", "221B, Baker's Street, Gurgaon", {{21, 1, "the best!", 5}, {12, 1, "good", 3}}}};

    //Homepage
    int user_length = 5;
    int login = 0; //flag for successful login
    printf("Hello, Welcome to the thrift shop. please select an option from the given menu to continue.\n1. Login\n2. Sign Up\n");
    int option1;
    scanf("%d", &option1);

    //sign up
    if (option1 == 2)
    {
        user_length++;
        printf("Please Enter your Full Name\n");
        scanf("%s", users[6].name);
        printf("Please Enter a valid Username\n");
        scanf("%s", users[6].id);
        printf("Please Enter a valid Password\n");
        scanf("%s", users[6].password);
        printf("Please Enter your Address\n");
        scanf("%s", users[6].address);

        printf("Please select a valid option to continue \n1. continue with this account\n2. sign in to another account\n");
        int option2;
        scanf("%d", &option2);

        if (option2 == 1)
            login = 1;
    }

    //login
    while (login == 0)
    {
        char id[20];
        char password[20];
        printf("Please Enter your user id\n");
        scanf("%s", id);
        printf("Please Enter your user password\n");
        scanf("%s", password);
        for (int i = 0; i < user_length && login == 0; i++)
        {
            if (strcmp(id, users[i].id) == 0)
            {
                if (strcmp(password, users[i].password) == 0)
                {
                    login = 1;
                    printf("Congratulations! You have successfully logged in!\n");
                }
            }
        }

        if (login == 0)
            printf("The User name or password that you entered is incorrect. Please try again.\n");
    }
}
//checking commmit