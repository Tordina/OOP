#pragma once
#include "Control.h"
#include "ComboBox.h"
#include <iostream>

class WindowsComboBox : public Control, public ComboBox {

private:
    int selectedIndex;

    std::vector<std::string> items;

public:

    void setSelectedIndex(int index) override {
        std::cout << "Method called from Windows ComboBox" << std::endl;
        selectedIndex = index;
    }

    void setItems(std::vector<std::string> items) override {
        std::cout << "Method called from Windows ComboBox" << std::endl;
        this->items = items;
    }

    const int getSelectedIndex() const override {
        return selectedIndex;
    }

    const std::vector<std::string>& getItems() const override {
        return items;
    }
};