#include "ScrollWindow.h"

void ScrollingWindow::onButtonClick(){
	mScrollWindowBox->Pack(sfg::RadioButton::Create("A Button", mRadioButton->GetGroup()));
}

void ScrollingWindow::run(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFGUI Scroll Window", sf::Style::Titlebar | sf::Style::Close);
	window.resetGLStates();

	auto guiWindow = sfg::Window::Create();
	guiWindow->SetTitle("Scroll Window");

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);
	auto button = sfg::Button::Create("Add a button");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&ScrollingWindow::onButtonClick, this));

	mScrollWindowBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	mRadioButton = sfg::RadioButton::Create("Button 1");
	auto scrolledWindow = sfg::ScrolledWindow::Create();
	scrolledWindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_ALWAYS | sfg::ScrolledWindow::VERTICAL_AUTOMATIC);

	scrolledWindow->AddWithViewport(mScrollWindowBox);
	scrolledWindow->SetRequisition(sf::Vector2f(100.f, 200.f));


	box->Pack(button, false, true);
	box->Pack(scrolledWindow, false, true);
	mScrollWindowBox->Pack(mRadioButton, false, true);
	sf::Clock clock;
	guiWindow->Add(box);
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			guiWindow->HandleEvent(event);
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		if (clock.getElapsedTime().asMicroseconds() >= 1000){
			auto delta = static_cast<float>(clock.getElapsedTime().asMicroseconds()) / 1000000.f;
			guiWindow->Update(delta);
			clock.restart();
		}
		window.clear();
		mSfgui.Display(window);
		window.display();

	}
}