#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	enum class KeyCode : int32_t
	{
		Unknown = -1,

		Space = 32,
		Apostrophe = 39,
		Comma = 44,
		Minus = 45,
		Period = 46,
		Slash = 47,
		Alpha0 = 48,
		Alpha1 = 49,
		Alpha2 = 50,
		Alpha3 = 51,
		Alpha4 = 52,
		Alpha5 = 53,
		Alpha6 = 54,
		Alpha7 = 55,
		Alpha8 = 56,
		Alpha9 = 57,
		Semicolon = 59,
		Equal = 61,
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		LeftBracket = 91,
		Backslash = 92,
		RighyBracket = 93,
		GraveAccent = 96,
		World1 = 161,
		World2 = 162,

		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,
		Keypad0 = 320,
		Keypad1 = 321,
		Keypad2 = 322,
		Keypad3 = 323,
		Keypad4 = 324,
		Keypad5 = 325,
		Keypad6 = 326,
		Keypad7 = 327,
		Keypad8 = 328,
		Keypad9 = 329,
		KeypadDecimal = 330,
		KeypadDivide = 331,
		KeypadMultiply = 332,
		KeypadSubtract = 333,
		KeypadAdd = 334,
		KeypadEnter = 335,
		KeypadEqual = 336,
		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	};

	enum class MouseButton : int32_t
	{
		Unknown = -1,

		Button1 = 0,
		Button2 = 1,
		Button3 = 2,
		Button4 = 3,
		Button5 = 4,
		Button6 = 5,
		Button7 = 6,
		Button8 = 7,

		Left = Button1,
		Right = Button2,
		Middle = Button3
	};

	inline std::ostream& operator<<(std::ostream& os, KeyCode key)
	{
		switch (key)
		{
		case KeyCode::Space:
			return os << "Space";
		case KeyCode::Apostrophe:
			return os << "Apostrophe";
		case KeyCode::Comma:
			return os << "Comma";
		case KeyCode::Minus:
			return os << "Minus";
		case KeyCode::Period:
			return os << "Period";
		case KeyCode::Slash:
			return os << "Slash";
		case KeyCode::Alpha0:
			return os << "Alpha0";
		case KeyCode::Alpha1:
			return os << "Alpha1";
		case KeyCode::Alpha2:
			return os << "Alpha2";
		case KeyCode::Alpha3:
			return os << "Alpha3";
		case KeyCode::Alpha4:
			return os << "Alpha4";
		case KeyCode::Alpha5:
			return os << "Alpha5";
		case KeyCode::Alpha6:
			return os << "Alpha6";
		case KeyCode::Alpha7:
			return os << "Alpha7";
		case KeyCode::Alpha8:
			return os << "Alpha8";
		case KeyCode::Alpha9:
			return os << "Alpha9";
		case KeyCode::Semicolon:
			return os << "Semicolon";
		case KeyCode::Equal:
			return os << "Equal";
		case KeyCode::A:
			return os << "A";
		case KeyCode::B:
			return os << "B";
		case KeyCode::C:
			return os << "C";
		case KeyCode::D:
			return os << "D";
		case KeyCode::E:
			return os << "E";
		case KeyCode::F:
			return os << "F";
		case KeyCode::G:
			return os << "G";
		case KeyCode::H:
			return os << "H";
		case KeyCode::I:
			return os << "I";
		case KeyCode::J:
			return os << "J";
		case KeyCode::K:
			return os << "K";
		case KeyCode::L:
			return os << "L";
		case KeyCode::M:
			return os << "M";
		case KeyCode::N:
			return os << "N";
		case KeyCode::O:
			return os << "O";
		case KeyCode::P:
			return os << "P";
		case KeyCode::Q:
			return os << "Q";
		case KeyCode::R:
			return os << "R";
		case KeyCode::S:
			return os << "S";
		case KeyCode::T:
			return os << "T";
		case KeyCode::U:
			return os << "U";
		case KeyCode::V:
			return os << "V";
		case KeyCode::W:
			return os << "W";
		case KeyCode::X:
			return os << "X";
		case KeyCode::Y:
			return os << "Y";
		case KeyCode::Z:
			return os << "Z";
		case KeyCode::LeftBracket:
			return os << "Left Bracket";
		case KeyCode::Backslash:
			return os << "Backslash";
		case KeyCode::RighyBracket:
			return os << "Righy Bracket";
		case KeyCode::GraveAccent:
			return os << "Grave Accent";
		case KeyCode::World1:
			return os << "World1";
		case KeyCode::World2:
			return os << "World2";
		case KeyCode::Escape:
			return os << "Escape";
		case KeyCode::Enter:
			return os << "Enter";
		case KeyCode::Tab:
			return os << "Tab";
		case KeyCode::Backspace:
			return os << "Backspace";
		case KeyCode::Insert:
			return os << "Insert";
		case KeyCode::Delete:
			return os << "Delete";
		case KeyCode::Right:
			return os << "Right";
		case KeyCode::Left:
			return os << "Left";
		case KeyCode::Down:
			return os << "Down";
		case KeyCode::Up:
			return os << "Up";
		case KeyCode::PageUp:
			return os << "Page Up";
		case KeyCode::PageDown:
			return os << "Page Down";
		case KeyCode::Home:
			return os << "Home";
		case KeyCode::End:
			return os << "End";
		case KeyCode::CapsLock:
			return os << "Caps Lock";
		case KeyCode::ScrollLock:
			return os << "Scroll Lock";
		case KeyCode::NumLock:
			return os << "Num Lock";
		case KeyCode::PrintScreen:
			return os << "Print Screen";
		case KeyCode::Pause:
			return os << "Pause";
		case KeyCode::F1:
			return os << "F1";
		case KeyCode::F2:
			return os << "F2";
		case KeyCode::F3:
			return os << "F3";
		case KeyCode::F4:
			return os << "F4";
		case KeyCode::F5:
			return os << "F5";
		case KeyCode::F6:
			return os << "F6";
		case KeyCode::F7:
			return os << "F7";
		case KeyCode::F8:
			return os << "F8";
		case KeyCode::F9:
			return os << "F9";
		case KeyCode::F10:
			return os << "F10";
		case KeyCode::F11:
			return os << "F11";
		case KeyCode::F12:
			return os << "F12";
		case KeyCode::F13:
			return os << "F13";
		case KeyCode::F14:
			return os << "F14";
		case KeyCode::F15:
			return os << "F15";
		case KeyCode::F16:
			return os << "F16";
		case KeyCode::F17:
			return os << "F17";
		case KeyCode::F18:
			return os << "F18";
		case KeyCode::F19:
			return os << "F19";
		case KeyCode::F20:
			return os << "F20";
		case KeyCode::F21:
			return os << "F21";
		case KeyCode::F22:
			return os << "F22";
		case KeyCode::F23:
			return os << "F23";
		case KeyCode::F24:
			return os << "F24";
		case KeyCode::F25:
			return os << "F25";
		case KeyCode::Keypad0:
			return os << "Keypad 0";
		case KeyCode::Keypad1:
			return os << "Keypad 1";
		case KeyCode::Keypad2:
			return os << "Keypad 2";
		case KeyCode::Keypad3:
			return os << "Keypad 3";
		case KeyCode::Keypad4:
			return os << "Keypad 4";
		case KeyCode::Keypad5:
			return os << "Keypad 5";
		case KeyCode::Keypad6:
			return os << "Keypad 6";
		case KeyCode::Keypad7:
			return os << "Keypad 7";
		case KeyCode::Keypad8:
			return os << "Keypad 8";
		case KeyCode::Keypad9:
			return os << "Keypad 9";
		case KeyCode::KeypadDecimal:
			return os << "Keypad Decimal";
		case KeyCode::KeypadDivide:
			return os << "Keypad Divide";
		case KeyCode::KeypadMultiply:
			return os << "Keypad Multiply";
		case KeyCode::KeypadSubtract:
			return os << "Keypad Subtract";
		case KeyCode::KeypadAdd:
			return os << "Keypad Add";
		case KeyCode::KeypadEnter:
			return os << "Keypad Enter";
		case KeyCode::KeypadEqual:
			return os << "Keypad Equal";
		case KeyCode::LeftShift:
			return os << "Left Shift";
		case KeyCode::LeftControl:
			return os << "Left Control";
		case KeyCode::LeftAlt:
			return os << "Left Alt";
		case KeyCode::LeftSuper:
			return os << "Left Super";
		case KeyCode::RightShift:
			return os << "Right Shift";
		case KeyCode::RightControl:
			return os << "Right Control";
		case KeyCode::RightAlt:
			return os << "Right Alt";
		case KeyCode::RightSuper:
			return os << "Right Super";
		case KeyCode::Menu:
			return os << "Menu";
		}

		return os << "Unknown Keycode";
	}

	inline std::ostream& operator<<(std::ostream& os, MouseButton button)
	{
		switch (button)
		{
		case MouseButton::Left:
			return os << "Left Mouse Button";
		case MouseButton::Right:
			return os << "Right Mouse Button";
		case MouseButton::Middle:
			return os << "Middle Mouse Button";
		case MouseButton::Button4:
			return os << "Mouse Button 4";
		case MouseButton::Button5:
			return os << "Mouse Button 5";
		case MouseButton::Button6:
			return os << "Mouse Button 6";
		case MouseButton::Button7:
			return os << "Mouse Button 7";
		case MouseButton::Button8:
			return os << "Mouse Button 8";
		}

		return os << "Unknown MouseCode";
	}

}
