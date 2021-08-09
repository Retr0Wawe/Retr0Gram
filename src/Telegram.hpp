#pragma once
#include "Requests.hpp"

class Telegram : public Requests
{
    const char* bot_api;
    const char* chat_id;
    int error_counts; 
public:
    std::string past_message;
public:
    explicit Telegram(const char* bot_api = nullptr, const char* chat_id = nullptr):
             Requests("TgHelper", "api.telegram.org", 1),
                bot_api(bot_api), chat_id(chat_id), error_counts(0) 
                      {   }

    bool Check_Errors();

    std::string Get_Last_Message();

    void Send_Message(const char* message);
};