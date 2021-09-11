#pragma once
#include "Telegram.hpp"

namespace Tg
{
	void Delay(double seconds)
	{
		Sleep(seconds * 1000);
	}

	void Init(Telegram& start)
	{
		const char* on_start_message =
			"The computer is on! Example commands:  /cmd  /exit  /shutdown  /pwd   \\
			 ";

		start.Send_Message(on_start_message);
	}
}