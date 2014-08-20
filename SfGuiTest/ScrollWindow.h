#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

class ScrollingWindow{
public:
	void						onButtonClick();
	void						run();
private:
	sfg::SFGUI					mSfgui;
	sfg::Box::Ptr				mScrollWindowBox;
	sfg::RadioButton::Ptr		mRadioButton;
};

