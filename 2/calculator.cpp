#include "calculator.hpp"
    bool is_number(const std::string &s) {
        return !s.empty() && (std::all_of(s.begin(), s.end(), [](char c) { return ::isdigit(c); }) ||
                              (s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return ::isdigit(c); })));
    }
void pop::cmd(Context &context, std::vector<std::string> str) {
    if (!context.mystack.empty()){
        context.mystack.pop();
    }
    else
        throw popexc();
}
void push::cmd(Context &context, std::vector<std::string> str) {
    if (is_number(str[1])){
        context.mystack.push(std::stoll(str[1]));
    }
    else if (!is_number(str[1]))
    {
        context.mystack.push(context.mp[str[1]]);
    }
    else
        throw pushexc();

}
void plus::cmd(Context &context, std::vector<std::string> str){
    if (context.mystack.size()<2)
        throw plusexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    int64_t res;
    SafeAdd(v2,v1,res);
    context.mystack.push(res);
}
void minus::cmd(Context &context, std::vector<std::string> str){
    if (context.mystack.size()<2)
        throw minusexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    int64_t res;
    SafeSubtract(v2,v1,res);
    context.mystack.push(res);
}
void mul::cmd(Context &context, std::vector<std::string> str){
    if (context.mystack.size()<2)
        throw pushexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    int64_t res;
    SafeMultiply(v2,v1,res);
    context.mystack.push(res);
}
void divn::cmd(Context &context, std::vector<std::string> str){
    if (context.mystack.size()<2)
        throw divexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    if (v2 == 0){
        throw DivideByZero();
    }
    int64_t res;
    SafeDivide(v2,v1,res);
    context.mystack.push(res);
}
void print::cmd(Context &context, std::vector<std::string> str){
    if(!context.mystack.empty()){
        std::cout<<std::to_string((int64_t)context.mystack.top())<<std::endl;
    }
    else
        throw printexc();
}
void peek::cmd(Context &context, std::vector<std::string> str){
    if(context.mystack.empty() || str.size() < 2 ){
        throw peekexc();
    }
    else
        context.mp[str[1]] = context.mystack.top();
}
void abss::cmd(Context &context, std::vector<std::string> str){
    if(!context.mystack.empty()){
        SafeInt <int64_t> val = context.mystack.top();
        context.mystack.pop();
        val = val > 0? val : - val;
        context.mystack.push(val);
    }
    else
        absexc();
}
void read::cmd(Context &context, std::vector<std::string> str){
    try{
        context.mystack.push(std::stoll(str[1]));
    } catch (...){
        throw readexc();
    }
}
void com::cmd(Context &context, std::vector<std::string> str){
   //navalny.com
}
Command *Cmdcreate::Fmethod(std::vector<std::string> vec) {
    if (vec[0] =="#"){
        return new com();
    }
    else if (vec[0] =="MUL"){
        return new mul();
    }
    else if (vec[0] =="MINUS"){
        return new minus();
    }
    else if (vec[0] =="PLUS"){
        return new plus();
    }
    else if (vec[0] =="DIV"){
        return new divn();
    }
    else if (vec[0] =="PUSH"){
        return new push();
    }
    else if (vec[0] =="POP"){
        return new pop();
    }
    else if (vec[0] =="PRINT"){
        return new print();
    }
    else if (vec[0] =="PEEK"){
        return new peek();
    }
    else if (vec[0] =="READ"){
        return new read();
    }
    else if (vec[0] =="ABS"){
        return new abss();
    }
    else
        throw commandexc();

}