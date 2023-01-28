#include <stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    
    //SNACKS
    string a = "(a) Footlong                      Php 62.00";
    double aPrice = 62.00;
    string b = "(b) Burger                        Php 49.50";
    double bPrice = 49.50;
    string c = "(c) Cheese burger                 Php 79.50";
    double cPrice = 79.50;
    string d = "(d) French fries                  Php 35.00";
    double dPrice = 35.00;
    //DRINKS
    string e = "(e) Orange juice                  Php 25.00";
    double ePrice = 25.00;
    string f = "(f) Coke in can                   Php 30.00";
    double fPrice = 30.00;
    string g = "(g) Mineral water                 Php 20.00";
    double gPrice = 20.00;
    string h = "(h) Iced tea                      Php 24.50";
    double hPrice = 24.50;

    //MENU
    cout <<"SNACKS"<<endl;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    cout <<d<<endl;
    cout <<"DRINKS"<<endl;
    cout <<e<<endl;
    cout <<f<<endl;
    cout <<g<<endl;
    cout <<h<<endl;
    cout <<endl<<"Input letters of your order: ";
  
    string order;
    getline(cin, order);

    Again:
    double total;
    for (int i = 0; i < order.size(); i++){
        if(order[i]=='a'){
            cout <<a<<endl;
            total = total+aPrice;
        }else if(order[i]=='b'){
            cout <<b<<endl;
            total = total+bPrice;
        }else if(order[i]=='c'){
            cout <<c<<endl;
            total = total+cPrice;    
        }else if(order[i]=='d'){
            cout <<d<<endl;
            total = total+dPrice;    
        }else if(order[i]=='e'){
            cout <<e<<endl;
            total = total+ePrice;    
        }else if(order[i]=='f'){
            cout <<f<<endl;
            total = total+fPrice;    
        }else if(order[i]=='g'){
            cout <<g<<endl;
            total = total+gPrice;    
        }else if(order[i]=='h'){
            cout <<h<<endl;
            total = total+hPrice;    
        }
    }
    
    //Total
    cout << setprecision(2) << fixed;
    cout <<"____________________________________________"<<endl;
    cout <<"TOTAL                             Php "<<total<<endl;
    
    
    char ans;
    cout<<"Remove order? [Y/N] ";
    cin>>ans;
    
    //to Again: if y||Y
    if(ans=='y' || ans=='Y'){
        total = 0;
        
        cout<<endl<<"Input letters of your order to be removed:";
        string removeOrder;
        cin.ignore();//flush
        getline(cin, removeOrder);
        
        //remove the same characters in two strings
        for (int i = 0; i < order.length(); i++) {
            for (int j = 0; j < removeOrder.length(); j++) {
                if (order[i] == removeOrder[j]) {
                    order.erase(i, 1);
                    removeOrder.erase(j, 1);
                    i--;
                    break;
                }
            }
        }
        
        system("clear");
        goto Again;
    }
    
    //Payment
    PaymentNotEnough:
    double payment;
    cout<<"Input Cash: ";
    cin>>payment;
    
    if(payment < total){
        char addMOney;
        cout<<"Add money [Y/N] ";
        cin>>addMOney;
        
        //to PaymentNotEnough: if y||Y
        if(ans=='y' || ans=='Y'){
            goto PaymentNotEnough;
        }else{
            cout<<"Sorry you don't have enough money";
        }
    }else{
        double change;
        change = total - change;
        cout<<"Change: Php "<<change;
    }
    
    return 0;
}
