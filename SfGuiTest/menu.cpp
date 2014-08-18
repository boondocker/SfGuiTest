#include "menu.h"

void Menu::ButtonClick(){
	mButton->SetLabel("Button Clicked");
}

void Menu::ButtonToggle(){
	if (mToggleButton->IsActive()){
		mWindow->SetStyle(mWindow->GetStyle() ^ sfg::Window::TITLEBAR);
	}
	else{
		mWindow->SetStyle(mWindow->GetStyle() | sfg::Window::TITLEBAR);
	}
}

void Menu::ButtonCheck(){
	if (mCheckButton->IsActive()){
		mWindow->SetStyle(mWindow->GetStyle() ^ sfg::Window::BACKGROUND);
	}
	else{
		mWindow->SetStyle(mWindow->GetStyle() | sfg::Window::BACKGROUND);
	}
}

void Menu::ButtonSelect(){
	if(mRadioButton1->IsActive()){
		mWindow->SetTitle("First Button Selected");
}
	else if (mRadioButton2->IsActive()){
		mWindow->SetTitle("Second Button Selected");
	}
	else if (mRadioButton3->IsActive()){
		mWindow->SetTitle("Third Button is Selected");
	}
}

void Menu::Run(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Example", sf::Style::Titlebar | sf::Style::Close);
	window.resetGLStates();

	mWindow = sfg::Window::Create();
	mWindow->SetTitle("Title");

	//Create a Box to contain all the buttons.
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
		mButton = sfg::Button::Create("Click me");
	//add the button to the box
		box->Pack(mButton);
	//Connect the button with a callback of our choosing
		mButton->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Menu::ButtonClick, this));
		mToggleButton = sfg::ToggleButton::Create("Toggle me");

		mToggleButton->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Menu::ButtonToggle, this));
		box->Pack(mToggleButton);
		mCheckButton = sfg::CheckButton::Create("Check me");
		mCheckButton->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Menu::ButtonCheck, this));
		box->Pack(mCheckButton);
		box->Pack(sfg::Separator::Create());

		mRadioButton1 = sfg::RadioButton::Create("Either this");
		mRadioButton2 = sfg::RadioButton::Create("Or this", mRadioButton1->GetGroup());
		mRadioButton3 = sfg::RadioButton::Create("Or maybe even this", mRadioButton1->GetGroup());

		mRadioButton3->SetActive(true);

		mRadioButton1->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Menu::ButtonSelect, this));
		mRadioButton2->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Menu::ButtonSelect, this));
		mRadioButton3->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Menu::ButtonSelect, this));

		box->Pack(mRadioButton1);
		box->Pack(mRadioButton2);
		box->Pack(mRadioButton3);

		mWindow->Add(box);

		while (window.isOpen()){
			sf::Event event;

			while (window.pollEvent(event)){
				mWindow->HandleEvent(event);

				if (event.type == sf::Event::Closed){
					window.close();
				}
			}

			mWindow->Update(0.f);
			window.clear();
			mSfgui.Display(window);
			window.display();
		}


}