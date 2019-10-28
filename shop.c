/**
 DSPD Project
 Authors: 
 Saumya Gandhi BT18CSE067
 Surbhi Agrawal BT18CSE072
 **/

#include<stdio.h>

//declaration of product structure
typedef struct 
{
    char category[20];
    char ide_code[5];
    char brand[20];
    char prod_name[40];
    float price;
    char colour[20];
    int stock;
    char dealer[20];
    int offers[3];
    char quantity[10];
}PRODUCT;

typedef struct 
{
    char ide_code[5];
    int quantity;
    char review[50];
    int rating;
}HISTORY;

//declaration of user structure
typedef struct
{
    int id;
    char password[20];
    char name[40];
    char address[100];
    HISTORY hist[20];
}USER;

void main()
{
    // Initialization of products database
    PRODUCT prod_list[20]={{"food","F1","cadbury","oreo",20,"vanilla",5,"mani&sons",{0,0,0},"20g pack"},
    {"food","F2","quaker","almonds",300,"natural",23,"mani&sons",{0,0,0},"250g"},
    {"food","F3","quaker","oats",150,"vanilla",10,"mani&sons",{0,0,0},"250g"},
    {"food","F4","hersheys","nutella",300,"chocolate",5,"mani&sons",{0,0,0},"250g"},
    {"mobiles","M1","apple","iphone 11 pro",90000,"blue",11,"mango",{0,0,0},1},
    {"mobiles","M2","google","pixel 4",90000,"not all white",4,"nopixel",{0,0,0},1},
    {"mobiles","M3","one plus","one plus",50000,"black",50,"oneplusindia",{0,0,0},1},
    {"mobiles","M4","samsug","samsung galaxy s10",80000,"black",30,"cloudtail",{0,0,0},1},
    {"books","B1","bloomsbury","the anarchy",250,"softbound",10,"cloudtail",{0,0,0},1},
    {"books","B2","bloomsburry","the institute",700,"hardbound",3,"anush",{0,0,0},1},
    {"books","B3","harvil secker","homo deus",300,"softbound",15,"kobo",{0,0,0},1},
    {"books","B4","random house","norweign wood",150,"softbound",10,"lolo",{0,0,0},1},
    {"men's fashion","MF1","diesel","tshirt",1000,"black",7,"shopclues",{0,0,0},1},
    {"men's fashion","MF2","diesel","shirt",2000,"blue",13,"shopnoclues",{0,0,0},1},
    {"men's fashion","MF3","levis","jeans",2000,"white",2,"shopclues",{0,0,0},1},
    {"men's fashion","MF4","adidas","shoes",5000,"yellow",20,"dcathlon",{0,0,0},1},
    {"women's fashion","WF1","hnm","dress",3000,"black",7,"myspace",{0,0,0},1},
    {"women's fashion","WF2","hnm","tshirt",1500,"red",5,"seezz",{0,0,0},1},
    {"women's fashion","WF3","levis","jeans",2500,"blue",4,"myntra",{0,0,0},1},
    {"women's fashion","WF4","forever 21","jacket",3000,"yellow",10,"F21",{0,0,0},1},
    };


}




