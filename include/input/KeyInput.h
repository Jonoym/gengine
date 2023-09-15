#pragma once

#include <input/Input.h>
#include <core/KeyCodes.h>

namespace Gengine
{
    class KeyInput : public Input
    {
    public:
        KeyCode GetKeyCode() const { return mKeyCode; }

    protected:
        KeyInput(const KeyCode keyCode) : mKeyCode(keyCode) {}
        KeyCode mKeyCode;
    };

	class KeyPressedInput : public KeyInput
	{
	public:
		KeyPressedInput(const KeyCode keycode, bool isRepeat = false)
			: KeyInput(keycode), mIsRepeat(isRepeat) {}

		bool IsRepeat() const { return mIsRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedInput: " << mKeyCode << " (repeat = " << mIsRepeat << ")";
			return ss.str();
		}

	private:
		bool mIsRepeat;
	};

class KeyReleasedInput : public KeyInput
	{
	public:
		KeyReleasedInput(const KeyCode keycode)
			: KeyInput(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedInput: " << mKeyCode;
			return ss.str();
		}
	};

	class KeyTypedInput : public KeyInput
	{
	public:
		KeyTypedInput(const KeyCode keycode)
			: KeyInput(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedInput: " << mKeyCode;
			return ss.str();
		}
	};
}