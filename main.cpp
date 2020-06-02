// Проект 16: JSON парсер
// JSON е популярен текстов формат за описване на данни. Да се напише програма, която работи с файлове в такъв формат.

// След като приложението отвори даден файл, то трябва да може да извършва посочените по-долу операции, в допълнение на общите операции (open, close, save, save as, help и exit):

// -validate
// Да се направи проверка дали отворения файл е валиден спрямо синтаксиса на JSON. Ако има някакъв проблем, програмата трябва да съобщи максимално ясно какво и къде не е наред, така че потребителят да може да го поправи.
// {
//     "firstName": "John",
//     "lastName": "Smith",
//     "age": 25,
//     "address": {
//         "streetAddress": "21 2nd Street",
//         "city": "New York",
//         "state": "NY",
//         "postalCode": 10021
//     },
//     "phoneNumbers": [
//         {
//             "type": "home",
//             "number": "212 555-1234"
//         },
//         {
//             "type": "fax",
//             "number": "646 555-4567"
//         }
//     ]
// }
// -print
// Да се изведе съдържанието на обекта в максимално четим вид.
// -search <key>
// Да се провери дали в обекта се съдържат данни, записани под този ключ и ако да – да изведе списък от всички такива данни.
// -set <path> <string>
// При подаване на пълен път <path> към даден елемент, да се замени стойността на посочения елемент с нов обект, получен от низа <string> според синтаксиса на JSON стойност, ако такъв елемент съществува и е единствен и ако символният низ е коректен. В противен случай трябва да обяви каква е грешката.
// -create <path> <string>
// При подаване на пълен път <path> към даден елемент да се добави такъв елемент, получен от низа <string> според синтаксиса на JSON стойност. Ако такъв елемент съществува, това трябва да се обяви като грешка. В случай, че последните елементи от пътя не съществуват, да се създадат. Ако символният низ или пътят не са коректни, да се съобщи с подходящо описание на грешката.
// -delete <path>
// При подаване на пълен път <path> до елемент, да се изтрие, ако такъв съществува или да съобщи на потребителя при некоректен път.
// -move <from> <to>
// Всички елементи, намиращи се на път <from> да бъдат преместени на пътя <to>.
// -save [<path>]
// -saveas <file> [<path>]
// Командите save и saves да работят с произволен път, като записват в текущия или в нов файл обекта на дадения път, ако съществува. Ако <path> не е подаден, да се записва целият обект, който в момента е зареден в паметта.
#include "json.cpp"
#include "json.h"
#include "create.cpp"//
#include "command.cpp"
#include "move.cpp"//
#include "print.cpp"//
#include "save.cpp"//
#include "set.cpp"//
#include "validate.cpp"
#include "delete.cpp"
#include "exeption.cpp"


int main(){
    
    //Json json;
    //json.read_from_file("example.json");
    //json.validate("example.json");//ne rabot izcqlo
    //json.search("address:");
    //json.search("phoneNumbers:");
    //json.search("children:");
    //json.set("address:", "replace");
    //json.create("street:", "suhodolska");
    //json.deletefunc("children:");
    //json.move("firstName:", "number:");
    //json.print("experiment.json");
    //json.save("phoneNumbers");
    //json.saveas("phoneNumbers");
    //json.print_vector();

    cout<<"in to"<<endl;
    string input;
    getline(cin,input);

    Command commands;
    Json json;

    while(input != exit_command){

        string* words = split(input);
        string command = words[0];

        if(command == open_command){

            string file_name = words[1];
            commands.open(file_name);

        }else if(command == close_command){

            commands.close();

        }else if(command == save_command){

            commands.save();

        }else if(command == save_as_command){

            string file_name = words[1];
            commands.save_as(file_name);

        }else if(command == help_command){

            commands.help();

        }else if(command == read_from_file){

            all_read("experiment.json");
            json.read_from_file("experiment.json");
            //json.print_vector();

        }else if(command == move_command){

            string from_path = words[1];
            string to_path = words[2];
            json.move(from_path, to_path);
            json.save_to_file("expo.json");

        }else if(command == print){

            char* file_name = new char[words[1].length()+1];
            strcpy(file_name, words[1].c_str());
            json.print(file_name);
            delete[] file_name;

        }else if(command == create){

            string path = words[1];
            string word_for_create = words[2];
            json.create(path, word_for_create);
            json.save_to_file("expo.json");
            //json.print_vector();

        }else if(command == save){

            string path = words[1];
            json.save(path);

        }else if(command == set){

            string path = words[1];
            string word_for_repalce = words[2];
            json.set(path, word_for_repalce);

        }else if(command == validate){

            char* file_name = new char[words[1].length()+1];
            strcpy(file_name, words[1].c_str());
            json.validate(file_name);
            delete[] file_name;

        }else if(command == delete_command){

            string path = words[1];
            json.deletefunc(path);
            json.save_to_file("expo.json");
            //json.print_vector();

        }

        getline(cin, input);
    }


}