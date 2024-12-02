#include <iostream>
#include "rulecheck.h"
#include <memory>

int main()
{
    std::unique_ptr<RuleCheck> check = std::make_unique<RuleCheck>();
    check->checkValidIP("192.168.1.20");
}