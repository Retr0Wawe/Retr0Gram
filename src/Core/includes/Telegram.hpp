#ifndef TG_HPP
#define TG_HPP

#include "Requests.hpp"

namespace TelegramBot
{
    class Telegram : public Requests
    {
    private:
        std::string past_message;
        const char* bot_api;
        const char* chat_id;
    public:
        Telegram(const char* bot_api, const char* chat_id);

        ~Telegram();

        Telegram& operator=(const Telegram&) = delete;
        Telegram& operator=(const Telegram&&) = delete;

        Telegram(const Telegram&) = delete;
        Telegram(Telegram&&) = delete;

        bool Check_Errors();

        std::string Get_Last_Message();

        void Send_Message(const char* message);
    };

    void delay(double seconds);
}

#endif