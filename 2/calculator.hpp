#pragma once
#include <stack>
#include <sstream>
#include <map>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include "exception.hpp"
#include "C:\projects\engnr-nsu-cpp-2021\2\SafeInt\SafeInt.hpp"
#include "C:\projects\engnr-nsu-cpp-2021\2\googletest\googletest\include\gtest\gtest.h"
struct Context{
    std::stack<SafeInt<int64_t>> mystack;
    std::map<std::string, SafeInt<int64_t>> mp;
};
class Command{
public:
    virtual void cmd(Context& context,  std::vector<std::string> str)=0;
    virtual ~Command() =default;
};
class pop final: public Command{
    void cmd(Context& context,  std::vector<std::string> str) override;
};
class push final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class plus final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class minus final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class mul final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class divn final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class print final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class peek final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class abss final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class read final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class com final: public Command{
    void cmd(Context& context, std::vector<std::string> str) override;
};
class calc {
public:
    calc() = default;
    virtual  Command *Fmethod(std::vector<std::string> vec) = 0;
};
class Cmdcreate : calc{
public:
    Command *Fmethod(std::vector<std::string> vec) override;
};