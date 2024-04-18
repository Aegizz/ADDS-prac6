#include "BigNumCalc.h"



BigNumCalc::BigNumCalc(){

}
BigNumCalc::~BigNumCalc(){

}


std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> num;
    for (int i = 0; i < numString.length(); i++){
        num.push_back(numString[i] - '0');
    }
    return num;
}
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    std::list<int> res;
    int carry = 0;
    while ((!num1.empty() || !num2.empty()) || carry){
        int temp = carry;
        if (!num1.empty()){
            temp+= num1.back();
            num1.pop_back();
        }
        if (!num2.empty()){
            temp+=num2.back();
            num2.pop_back();
        }
        res.push_front(temp % 10);
        carry = temp/10;
    }
    return res;
}
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    std::list<int> res;
    int borrow = 0;
    while (!num1.empty() || !num2.empty()){
        int sub = borrow;
        if (!num1.empty()){
            sub+=num1.back();
            num1.pop_back();
        }
        if (!num2.empty()){
            sub-=num2.back();
            num2.pop_back();
        }
        if (sub < 0){
            sub +=10;
            borrow = -1;
        } else{
            borrow= 0;
        }
        res.push_front(sub);

    }
    while (!res.empty() && res.front() == 0){
        res.pop_front();
    }
    return res;
}
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    int digit = num2.front();
    num2.pop_front();

    std::list<int> res;
    res.push_back(0);

    for (int i = 0; i < digit; i++){
        res = this->add(res, num1);
    }


    return res;
}