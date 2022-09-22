#include <stdio.h>
#include <tgbot/tgbot.h>
using namespace std;
using namespace TgBot;

int main() {
	//env.load_dotenv('config.env');
	
	Bot bot("2135413408:AAFvc7enJjvSqP8xj8HUY64EA1QM7yY8rBY");
	
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
    