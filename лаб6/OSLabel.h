#pragma once
#include "Control.h"
#include "Label.h"
#include <iostream>

class OSLabel : public Control, public Label {

protected:
    std::string text;

public:

    void setText(std::string& text) override {
        std::cout << "Method called from MacOS Label" << std::endl;
    }

    const std::string& getText() const override {
        return text;
    }
};