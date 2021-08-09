#include "Telegram.hpp"

void Telegram::Send_Message(const char* message)
{
	std::string content = "bot" + std::string(bot_api) + "/sendMessage?text=" + message + "&chat_id=" + chat_id;

	try {
		std::string get_request = Requests::Send_Request("GET", content.c_str(), nullptr);

		if (get_request == "") {
			throw std::runtime_error("Error to send get request! Check your internet connection! ");
		}

		nlohmann::json parse_request = nlohmann::json::parse(get_request);

		if (parse_request["ok"] == false) {
			throw std::runtime_error("Bad request: " + parse_request["ok"]["result"]);
		}

	} catch(const std::exception& ex){
		std::string error_message = ex.what() + std::to_string(++error_counts);
		MessageBoxA(0, error_message.c_str(), MB_OK, 0);
	}
}

std::string Telegram::Get_Last_Message() 
{
	std::string text = "bot" + std::string(bot_api) + "/getUpdates";

	try {
		std::string get_request = Requests::Send_Request("GET", text.c_str(), nullptr);

		if (get_request == "") {
			throw std::runtime_error("Error to send get request! Check your internet connection! ");
		}

		nlohmann::json json_result = nlohmann::json::parse(get_request);

		if (json_result["ok"] == false) {
			throw std::runtime_error("Bad request: " + json_result["ok"]["result"]);
		}

		for (int i = 0; i < json_result["result"].size(); i++) {
			if (json_result["result"][i]["message"]["from"]["id"] == atoi(chat_id)) {
				text = json_result["result"][i]["message"]["text"];
			}
		}

	} catch (const std::exception& ex) {
		std::string error_message = ex.what() + std::to_string(++error_counts);
		MessageBoxA(0, error_message.c_str(), MB_OK, 0);
	} 

	return text != past_message ? past_message = text : "";
}

bool Telegram::Check_Errors()
{
	if (error_counts >= 5 && Requests::Send_Request("GET", "test", nullptr) == "") {
		MessageBoxA(0, "Emergency termination of the program!", MB_OK, 0);
		return false;
	}
	return true;
}