#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

class Menu{
public:
	void							ButtonClick();
	void							ButtonToggle();
	void							ButtonCheck();
	void							ButtonSelect();
	void							Run();

private:
	sfg::SFGUI						mSfgui;
	sfg::Window::Ptr				mWindow;
	sfg::Button::Ptr				mButton;
	sfg::ToggleButton::Ptr			mToggleButton;
	sfg::CheckButton::Ptr			mCheckButton;
	sfg::RadioButton::Ptr			mRadioButton1;
	sfg::RadioButton::Ptr			mRadioButton2;
	sfg::RadioButton::Ptr			mRadioButton3;
};

