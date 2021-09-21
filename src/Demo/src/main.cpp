#include <Telegram.hpp>
#include <iostream> 

using namespace TelegramBot;

#ifdef NDEBUG
  #define main() WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
 #else
  #define main(...) main(__VA_ARGS__) //for argc, argv
#endif

int main()
{
	Telegram tg("your bot api", "your chat id");

	tg.Send_Message("The computer is on! Example commands:  /cmd  /exit  /shutdown  /pwd ");	//start message

	while (tg.Check_Errors())
	{
		delay(0.5);

		std::string last_message = tg.Get_Last_Message();

		if (last_message == "/cmd") {
			tg.Send_Message("/Succes!");
			system("start cmd");
		}

		else if (last_message == "/shutdown") {
			tg.Send_Message("/Succes!");
			system("shutdown -p");
		}

		else if (last_message == "/exit") {
			tg.Send_Message("/Succes!");
			break;
		}

		else if (last_message == "/pwd") {
			tg.Send_Message("/Succes!");
			char buffer[MAX_PATH];

			GetCurrentDirectoryA(MAX_PATH, buffer);
			tg.Send_Message(buffer);
		}
	}
}