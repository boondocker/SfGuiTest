#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>

int main(){
	sf::RenderWindow app_window(sf::VideoMode(800, 600), "SFGUI Window Test", sf::Style::Titlebar | sf::Style::Close);
	app_window.resetGLStates();

	//Create an SFGUI object.
	sfg::SFGUI sfgui;
	sfg::Desktop sfDesktop;
	
	
	
	//Create the main sfgui window
	auto window = sfg::Window::Create();
	sfDesktop.GetEngine().LoadThemeFromFile("\example1.theme");
	
	//Set the window's title bar text
	window->SetTitle("Test Window");
	window->SetId("window1");
	
	sfDesktop.Add(window);
	sfDesktop.SetProperty("Window#window1", "BackgroundColor", sf::Color::Blue);

	//Game loop
	while (app_window.isOpen()){
		//Process Events
		sf::Event event;

		while (app_window.pollEvent(event)){
			window->HandleEvent(event);

			//Close window on exit
			if (event.type == sf::Event::Closed)
				app_window.close();
		}

		//Update the gui
		sfDesktop.Update(0.f);
		//window->Update(0.f);

		//Clear screen
		app_window.clear();

		//Render the Gui after the rest of the game
		sfgui.Display(app_window);

		//Update the window
		app_window.display();
	}

	return EXIT_SUCCESS;
}