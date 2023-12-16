#pragma once
#include "Control.h"
#include "Button.h"
#include <string>
#include <iostream>

class OSButton : public Button, public Control {

private:
    std::string text;

public:

    void setText(std::string& newText) override {
        text = newText;
    }

    void setOnClick() override {
        std::cout << "Method called from MacOS Button" << std::endl;
    }

    const std::string& getText() const override {
        return text;
    }

    void click() override {
        std::cout << "Button clicked" << std::endl;
    }
};