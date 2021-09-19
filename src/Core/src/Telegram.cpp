#include "Telegram.hpp"

#include <nlohmann/json.hpp>

namespace TelegramBot
{
	Telegram::Telegram(const char* bot_api, const char* chat_id) :
	Requests("TgHelper", "api.telegram.org", 1), bot_api(bot_api), chat_id(chat_id)
	{	
		LOG_INFO("Your bot api: [{0}]", bot_api);
		LOG_INFO("Your chat id: [{0}]", chat_id);
	}

	Telegram::~Telegram()
	{	}

	void Telegram::Send_Message(const char* message)
	{
		std::string content = "bot" + std::string(bot_api) + "/sendMessage?text=" + message + "&chat_id=" + chat_id;

		LOG_INFO("Send message: '{0}'", message);

		try {
			std::string get_request = Requests::Send_Request_Get(content.c_str(), nullptr);

			if (get_request == "") {
				throw std::runtime_error("Error to send get request! Check your internet connection! ");
			}

			nlohmann::json parse_request = nlohmann::json::parse(get_request);

			if (parse_request["ok"] == false) {
				throw std::runtime_error("Bad request: " + parse_request["ok"]["result"]);
			}
		}
		catch (const std::exception& ex) {
			LOG_WARN(ex.what());
		}
	}

	std::string Telegram::Get_Last_Message()
	{
		std::string text = "bot" + std::string(bot_api) + "/getUpdates";

		try {
			std::string get_request = Requests::Send_Request_Get(text.c_str(), nullptr);

			if (get_request == "") {
				throw std::runtime_error("Error to send get request! Check your internet connection! ");
			}

			nlohmann::json parse_request = nlohmann::json::parse(get_request);

			if (parse_request["ok"] == false) {
				throw std::runtime_error("Bad request: " + parse_request["ok"]["result"]);
			}

			for (int i = 0; i < parse_request["result"].size(); i++) {
				if (parse_request["result"][i]["message"]["from"]["id"] == atoi(chat_id)) {
					text = parse_request["result"][i]["message"]["text"];
				}
			}
		}
		catch (const std::exception& ex) {
			LOG_WARN(ex.what());
		}

		return text != past_message ? past_message = text : "";
	}

	bool Telegram::Check_Errors()
	{
		return true;
	}

	void delay(double seconds)
	{
		Sleep(seconds * 1000);
	}
}