#include "OSControlFactory.h"
#include "LinControlFactory.h"
#include "WindowsControlFactory.h"

int main()
{
	std::cout << "Linux" << '\n' << '\n';

	std::unique_ptr<ControlFactory> controlFactory(new LinControlFactory());

	std::unique_ptr<Label> label(controlFactory->createLabel());
	std::unique_ptr<TextBox> textBox(controlFactory->createTextBox());
	std::unique_ptr<ComboBox> comboBox(controlFactory->createComboBox());
	std::unique_ptr<Button> button(controlFactory->createButton());

	if (dynamic_cast<LinControlFactory*>(controlFactory.get()) != nullptr)
	{
		LinButton* linButton = dynamic_cast<LinButton*>(button.get());
		if (linButton != nullptr)
		{
			linButton->click();
		}
		else
		{
			std::cout << "Error: Button is not a LinButton object" << std::endl;
		}
	}
	else
	{
		std::cout << "Error: Unexpected ControlFactory type" << std::endl;
	}

	std::cout << "\nWindows" << '\n' << '\n';

	std::unique_ptr<ControlFactory> controlFactory2(new WindowsControlFactory());

	std::unique_ptr<Label> label2(controlFactory2->createLabel());
	std::unique_ptr<TextBox> textBox2(controlFactory2->createTextBox());
	std::unique_ptr<ComboBox> comboBox2(controlFactory2->createComboBox());
	std::unique_ptr<Button> button2(controlFactory2->createButton());
	
	if (dynamic_cast<WindowsControlFactory*>(controlFactory2.get()) != nullptr)
	{
		WindowsButton* WindowsButton1 = dynamic_cast<WindowsButton*>(button2.get());
		if (WindowsButton1 != nullptr)
		{
			WindowsButton1->click();
		}
		else
		{
			std::cout << "Error: Button is not a WindowsButton object" << std::endl;
		}
	}
	else
	{
		std::cout << "Error: Unexpected ControlFactory type" << std::endl;
	}

	std::cout << "\nMacOS" << '\n' << '\n';

	std::unique_ptr<ControlFactory> controlFactory1(new OSControlFactory());

	std::unique_ptr<Label> label1(controlFactory1->createLabel());
	std::unique_ptr<TextBox> textBox1(controlFactory1->createTextBox());
	std::unique_ptr<ComboBox> comboBox1(controlFactory1->createComboBox());
	std::unique_ptr<Button> button1(controlFactory1->createButton());

	if (dynamic_cast<OSControlFactory*>(controlFactory1.get()) != nullptr)
	{
		OSButton* OSButton1 = dynamic_cast<OSButton*>(button1.get());
		if (OSButton1 != nullptr)
		{
			OSButton1->click();
		}
		else
		{
			std::cout << "Error: Button is not a OSButton object" << std::endl;
		}
	}
	else
	{
		std::cout << "Error: Unexpected ControlFactory type" << std::endl;
	}



	return 0;
}