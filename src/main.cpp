#include <stdio.h>
#include <tgbot/tgbot.h>
#include "dotenv.h"
using namespace std;
using namespace TgBot;
using namespace dotenv;

int main() {
	env.load_dotenv('config.env');
	
	Bot bot("TOKEN");
	
	bot.getEvents().onCommand("start", [&bot](Message::Ptr message)
	{
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });
    
    bot.getEvents().onAnyMessage([&bot](Message::Ptr message)
    {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });

    return 0;
    }
    