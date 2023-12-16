#pragma once
#include "Control.h"
#include "Label.h"
#include <iostream>

class LinLabel : public Control, public Label {

protected:
    std::string text;

public:

    void setText(std::string& text) override {
        std::cout << "Method called from Linux Label" << std::endl;
        this->text = text;
    }

    const std::string& getText() const override {
        return text;
    }
};