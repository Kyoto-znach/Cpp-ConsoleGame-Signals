
// ааауауфауафкпшощук

#include <iostream>
#include "getRandomInRange.h"

bool devMode = false; // false true

using namespace std;

struct Item {
    int count;
    int price;
    int foodRestore;
    int waterRestore;
    int healthRestore;
    string name;
};

enum ItemID {
    ITEM_DOSHIK,
    ITEM_PASTA,
    ITEM_RAMEN,
    ITEM_WIPPASTA,
    ITEM_PEOPLEMEAT,
    ITEM_COFFEE,
    ITEM_COCA,
    ITEM_BLOOD,
    ITEM_MONSTER,
    ITEM_COUNT
};

struct InventarFood {
    Item doshik = { 0, 500, 25, 0, 10, "doshik" };   // дешёвый сраный
    Item pasta = { 0, 1000, 40, 0, 0, "Pasta"};   // норм еда
    Item goldenRamen = { 0, 8000, 80, 80, 80, "Gold ramen"};  // элитная еда
    Item aWIPpasta = { 0, 3000, 50, 0, 0, "W.I.P pasta"};   // экспериментальная
    Item aWIPpeopleMeat = { 0, 1000000, 100, 100, 100, "W.I.P peopel Meat"}; // даёт много еды
};


struct InventarWater {
    Item coffee = { 0, 1350, 0, 25, -5, "Coffe"};   // бодрит
    Item coca = { 0, 950, 0, 20, 0, "CocaCola"};    // обычный напиток
    Item blood = { 0, 70000, 80, 80, 80, "BLOODD"};   // восстанавливает здоровье
    Item monsterEnergy = { 0, 990, 10, 30, -5, "Monster Energy"};  // даёт всего по чуть, но вредный
};

struct Inventar
{
    InventarFood food;
    InventarWater water;
};

struct Actor {
    string name;
    int health, sleep, food, water, level, blood, scary, laky, day;
    unsigned int cash;
    Inventar inventory;
};

Actor player;


enum ActionType {
    ACTION_SIGNALS = 1,
    ACTION_JOB,
    ACTION_CASINO,
    ACTION_SLEEP,
    ACTION_SHOP,
    ACTION_UPGRADE,
    ACTION_USE
};

struct Signal
{
    string name;
    int Xpoly;
    int ypoly;
    int rare;
    string text;

};

Signal signal;

string signalRandomText[10] {"wow", "DEEEAATHH", "END IS NEAR", "we are beihnd you", "hes coming", "##############", "im.... du#$#&fh#&" , "hehehhe" , "GITLERR" , "Linkin park top" };

struct Ubgrate
{
    int price, level, maxlevel;
};

Ubgrate ubwork;

void useItem(Item& item) {
    if (item.count <= 0) {
        cout << "You don't have this item!\n";
        return;
    }

    item.count--;

    player.food = min(100, player.food + item.foodRestore);
    player.water = min(100, player.water + item.waterRestore);
    player.health = min(100, player.health + item.healthRestore);

    cout << "Used item!" << endl;
    cout << "+Food: " << item.foodRestore
        << "  +Water: " << item.waterRestore
        << "  +Health: " << item.healthRestore << endl;
}

double getPercentRange(int a, int b) {
    int diff = a - b;
    if (diff < 0) diff = -diff; // модуль разницы

    int maxVal;
    if (a > b)
        maxVal = a;
    else
        maxVal = b;

    if (maxVal == 0) return 100.0;

    return (1.0 - (double)diff / maxVal) * 100.0;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

void playerStats()
{
    

    cout << "======== Player Info ========" << endl;
    cout << "Name     : " << player.name << endl;
    cout << "Health   : " << player.health << endl;
    cout << "Sleep    : " << player.sleep << endl;
    cout << "Food     : " << player.food << endl;
    cout << "Water     : " << player.water << endl;
    cout << "Level    : " << player.level << endl;
    cout << "Cash     : " << player.cash << " $" << endl;
    cout << "day      : " << player.day << endl;
    cout << "==============================" << endl;

    if (devMode) {
        cout << endl << "--- [DEBUG INFO] ---" << endl;
        cout << "Memory address: " << &player << endl;
        cout << "Blood    : " << player.blood << " %" << endl;
        cout << "Scary    : " << player.scary << endl;
        cout << "Lucky    : " << player.laky << endl;
        cout << "---------------------" << endl << endl;
    }
}

void casino() {
        cout << "======== CASINO MANY GO ========" << endl;
        playerStats();
        int selectSlots;
        int slots;
        int select;
        
        cout << "1. GO DAPE" << endl;
        cout << "2. GO EXIT" << endl;
        cin >> select;
        switch (select)
        {
        case 1:

            cout << "======== CASINO MANY GO ========" << endl;
            int enterDapCash;
            cout << "You Heav cash: " << player.cash << endl;
            cout << "Enter DAP cash:" << endl;
            cin >> enterDapCash;
            cout << "enter slots: " << endl;
            cin >> selectSlots;           
            if (enterDapCash > player.cash) {
                cout << "BESPLATNYI SIR TILKO W MISHELOWKE!!" << endl;
                    break;
            }
            if (enterDapCash < player.cash) {
                while(true)
                {
                    slots = selectSlots / player.laky;
                    int winNum = getRandomInRange(1, slots);
                    int dap = getRandomInRange(1, slots);
                    if (dap == winNum)
                    {                        
                        player.cash += enterDapCash * selectSlots;
                        cout << "You WINNREER DAP DAP DPA!!" << endl;
                        cout << "You cash: " << player.cash << endl;
                    }
                    else
                    {
                        if (player.cash < enterDapCash * selectSlots)
                        {
                            player.cash = 0;
                        }
                        else
                        {
                            player.cash -= enterDapCash * selectSlots;
                        }
                        cout << "You lose GO DODEP!" << endl;
                        cout << "You cash: " << player.cash << endl;
                        if (player.cash < enterDapCash) {
                            cout << "You not heav money" << endl;
                            break;
                        }

                    }
                    cout << "1 try anether" << endl;
                    cout << "2 go back" << endl;
                    cin >> select;
                    if (select == 2) {
                        break;
                    }
                }
            }
                
            break;
        case 2:
            break;
        default:
            break;
        }
 }

void shop() {
    while (true)
    {
        int useInput;
        cout << "======= MEGA CULT SHOP ======" << endl;
        cout << "You cash        : " << player.cash << "$" << endl;
        cout << "1) doshik        " << " price: " << player.inventory.food.doshik.price << endl;
        cout << "2) pasta         " << " price: " << player.inventory.food.pasta.price << endl;
        cout << "3) goldenRamen   " << " price: " << player.inventory.food.goldenRamen.price << endl;
        cout << "4) aWIPpasta     " << " price: " << player.inventory.food.aWIPpasta.price << endl;
        cout << "5) aWIPpeopleMeat" << " price: " << player.inventory.food.aWIPpeopleMeat.price << endl;
        cout << "6) coffee        " << " price: " << player.inventory.water.coffee.price << endl;
        cout << "7) coca          " << " price: " << player.inventory.water.coca.price << endl;
        cout << "8) blood         " << " price: " << player.inventory.water.blood.price << endl;
        cout << "9) monsterEnergy " << " price: " << player.inventory.water.monsterEnergy.price << endl;
        cout << "10) Exit" << endl;

        cin >> useInput;

        if (useInput == 10) {
            break;
        }

        useInput -= 1;

        ItemID id = static_cast<ItemID>(useInput);
        cout << endl;
        switch (id)
        {
        case ITEM_DOSHIK:
            if (player.cash < player.inventory.food.doshik.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.food.doshik.count++;
            player.cash -= player.inventory.food.doshik.price;
            cout << "you buy: " << player.inventory.food.doshik.name << endl;
            break;
        case ITEM_PASTA:
            if (player.cash < player.inventory.food.pasta.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.food.pasta.count++;
            player.cash -= player.inventory.food.pasta.price;
            cout << "you buy: " << player.inventory.food.pasta.name << endl;
            break;
        case ITEM_RAMEN:
            if (player.cash < player.inventory.food.goldenRamen.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.food.goldenRamen.count++;
            player.cash -= player.inventory.food.goldenRamen.price;
            cout << "you buy: " << player.inventory.food.goldenRamen.name << endl;
            break;
        case ITEM_WIPPASTA:
            if (player.cash < player.inventory.food.aWIPpasta.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.food.aWIPpasta.count++;
            player.cash -= player.inventory.food.aWIPpasta.price;
            cout << "you buy: " << player.inventory.food.aWIPpasta.name << endl;
            break;
        case ITEM_PEOPLEMEAT:
            if (player.cash < player.inventory.food.aWIPpeopleMeat.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.food.aWIPpeopleMeat.count++;
            player.cash -= player.inventory.food.aWIPpeopleMeat.price;
            cout << "you buy: " << player.inventory.food.aWIPpeopleMeat.name << endl;
            break;
        case ITEM_COFFEE:
            if (player.cash < player.inventory.water.coffee.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.water.coffee.count++;
            player.cash -= player.inventory.water.coffee.price;
            cout << "you buy: " << player.inventory.water.coffee.name << endl;
            break;
        case ITEM_COCA:
            if (player.cash < player.inventory.water.coca.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.water.coca.count++;
            player.cash -= player.inventory.water.coca.price;
            cout << "you buy: " << player.inventory.water.coca.name << endl;
            break;
        case ITEM_BLOOD:
            if (player.cash < player.inventory.water.blood.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.water.blood.count++;
            player.cash -= player.inventory.water.blood.price;
            cout << "you buy: " << player.inventory.water.blood.name << endl;
            break;
        case ITEM_MONSTER:
            if (player.cash < player.inventory.water.monsterEnergy.price)
            {
                cout << "You noy heav money" << endl;
                break;
            }
            player.inventory.water.monsterEnergy.count++;
            player.cash -= player.inventory.water.monsterEnergy.price;
            cout << "you buy: " << player.inventory.water.monsterEnergy.name << endl;
            break;
        case ITEM_COUNT:
            break;
        default:
            break;
        }
    }
}

void inventar()
{
    while (true)
    {
        int useInput;
        cout << "======= INVENTAR ======" << endl;
        cout << "1 count: " << player.inventory.food.doshik.count << " " << "doshik" << endl;
        cout << "2 count: " << player.inventory.food.pasta.count << " " << "pasta" << endl;
        cout << "3 count: " << player.inventory.food.goldenRamen.count << " " << "goldenRamen" << endl;
        cout << "4 count: " << player.inventory.food.aWIPpasta.count << " " << "aWIPpasta" << endl;
        cout << "5 count: " << player.inventory.food.aWIPpeopleMeat.count << " " << "aWIPpeopleMeat" << endl;
        cout << "6 count: " << player.inventory.water.coffee.count << " " << "coffee" << endl;
        cout << "7 count: " << player.inventory.water.coca.count << " " << "coca" << endl;
        cout << "8 count: " << player.inventory.water.blood.count << " " << "blood" << endl;
        cout << "9 count: " << player.inventory.water.monsterEnergy.count << " " << "monsterEnergy" << endl;
        cout << "10 close " << endl;
        cin >> useInput;

        if (useInput == 10) {
            break;
        }

        useInput -= 1;

        ItemID id = static_cast<ItemID>(useInput);
        cout << endl;
        switch (id)
        {
        case ITEM_DOSHIK:
            useItem(player.inventory.food.doshik);
            break;
        case ITEM_PASTA:
            useItem(player.inventory.food.pasta);
            break;
        case ITEM_RAMEN:
            useItem(player.inventory.food.goldenRamen);
            break;
        case ITEM_WIPPASTA:
            useItem(player.inventory.food.aWIPpasta);
            break;
        case ITEM_PEOPLEMEAT:
            useItem(player.inventory.food.aWIPpeopleMeat);
            break;
        case ITEM_COFFEE:
            useItem(player.inventory.water.coffee);
            break;
        case ITEM_COCA:
            useItem(player.inventory.water.coca);
            break;
        case ITEM_BLOOD:
            useItem(player.inventory.water.blood);
            break;
        case ITEM_MONSTER:
            useItem(player.inventory.water.monsterEnergy);
            break;
        case ITEM_COUNT:
            break;
            break;
        default:
            break;
        }
    }
}

void signalSell() {
    int price = power(5, signal.rare); 
    if (signal.rare > 5) {
        price *= price;
    }
    cout << "Signal Price: " << price << endl;
    player.cash += price;
    player.level += 1;
}


void GetSignal() {
    signal.text = signalRandomText[getRandomInRange(0, 9)];
    signal.rare = getRandomInRange(1, 10);
    signal.Xpoly = getRandomInRange(1, 1000);
    signal.ypoly = getRandomInRange(1, 1000);
}

void signalsMain() {

    int rezXpoly;
    int rezYpoly;
    
    while (true)
    {
        
        int inputAction;
        cout << "++++++++ SIGNALS MAIN ++++++++" << endl;
        cout << "enter you action" << endl;
        cout << "1)     :" << "Get signal" << "" << endl;
        cout << "2)     :" << "get X polariti" << "" << endl;
        cout << "3)     :" << "get Y polariti" << "" << endl;
        cout << "4)     :" << "get signal text" << "" << endl;
        cout << "5)     :" << "exit" << "" << endl;

        if (devMode == true) {
            cout << "s.name    :" << signal.name << endl;
            cout << "s.rare    :" << signal.rare << endl;
            cout << "s.Xpoly   :" << signal.Xpoly << endl;
            cout << "s.ypoly   :" << signal.ypoly << endl;
        }

        cin >> inputAction;
        
        if (inputAction == 1)
        {
            GetSignal();
        }
        if (inputAction == 2)
        {
            while (true)
            {
                int playerAction;
                int playerXpoly;         
                cout << "======== X POLARITY ========" << endl;
                cout << "1)    :Enter X polarity" << endl;
                cout << "2)    :Exit" << endl;
                cin >> playerAction;
                if (playerAction == 1) {
                    cout << "Set X polarity: " << endl;
                    cin >> playerXpoly;
                    rezXpoly = getPercentRange(playerXpoly, signal.Xpoly);
                    cout << "Percen: " << rezXpoly << "%" << endl;
                    if (playerXpoly > signal.Xpoly) { cout << "-"; }
                    if (playerXpoly < signal.Xpoly) { cout << "+"; }
                    cout << endl;
                }
                if (playerAction == 2) {
                    break;
                }
            }
        }
        if (inputAction == 3)
        {
            while (true)
            {
                int playerAction;
                int playerYpoly;
                cout << "======== Y POLARITY ========" << endl;
                cout << "1)    :Enter Y polarity" << endl;
                cout << "2)    :Exit" << endl;
                cin >> playerAction;
                if (playerAction == 1) {
                    cout << "Set Y polarity: " << endl;
                    cin >> playerYpoly;
                    rezYpoly = getPercentRange(playerYpoly, signal.ypoly);
                    cout << "Percen: " << rezYpoly << "%" ;
                    if (playerYpoly > signal.ypoly) { cout << "-"; }
                    if (playerYpoly < signal.ypoly) { cout << "+"; }
                    cout << endl;
                }
                if (playerAction == 2) {
                    break;
                }
            }
        }
        if (inputAction == 4)
        {
            if (rezXpoly > 90 && rezYpoly > 90)
            {
                cout << "Signal rare: " << signal.rare << endl;
                cout << "Signal text: " << endl;
                cout << "=================================" << endl;
                cout << signal.text << endl;
                cout << "=================================" << endl;
                signalSell();
                GetSignal();
            }    
            else {
                cout << "polarity no founded. " << endl;
            }
        }
        if (inputAction == 5)
        {
            break;
        }
    }    
}

void ubgrateMain() {   
    while (true)
    {   
        int action;
        cout << "===== UBGRATE MENU ====" << endl;
        cout << "1)     : " << "Work up" << " Youre: " << ubwork.level  << " Level" << endl;
        cout << "2)     : " << "" << endl;
        cout << "3)     : " << "" << endl;
        cout << "4)     : " << "" << endl;
        cout << "5)     : " << "" << endl;
        cin >> action;
        if (action == 1)
        {
            while (true)
            {
                int a;
                cout << "youre level :" << ubwork.level << "/" << ubwork.maxlevel << endl;
                cout << "New level price :" << ubwork.price << endl;
                cout << "youre money :" << player.cash << endl;
                cout << "1.   :" << "bou new level" << endl;
                cout << "2.   :" << "Exit" << endl;
                cin >> a;
                if (a == 1)
                {
                    if (player.cash > ubwork.price)
                    {
                        player.cash -= ubwork.price;
                        ubwork.level += 1;
                        ubwork.price = ubwork.price * ubwork.level;                        
                        cout << "EEE LEVEL up" << endl;
                    }
                    else
                    {
                        cout << "ypu not heve maney" << endl;
                    }
                }
                if (a == 2)
                {
                    break;
                }
                
            }
        }
        if (action == 1)
        {

        }
        if (action == 1)
        {

        }
        if (action == 1)
        {

        }
        if (action == 5)
        {
            break;
        }
    }
}

void Actions() {
    int userInput;

    cout << endl;
    cout << "======== ACTION MENU ========" << endl;
    cout << "1. Enter Signals Zone" << endl;
    cout << "2. Take Easy Job" << endl;
    cout << "3. Visit Casino" << endl;
    cout << "4. Sleep/Rest" << endl;
    cout << "5. Go to Shop" << endl;
    cout << "6. Upgrade Abilities" << endl;
    cout << "7. Use inventar" << endl;
    cout << "=============================" << endl;
    cout << "Select your action: ";
    cin >> userInput;

    ActionType action = static_cast<ActionType>(userInput);  // кастуем в enum

    cout << endl;

    switch (action) {
    case ACTION_SIGNALS:
        cout << "[ Signals Zone ]" << endl;
        signalsMain();
        break;
    case ACTION_JOB:
        cout << "[ Easy Job Started ]" << endl;
        player.cash += (1000 * ubwork.level) * (player.level * ubwork.level);
        break;
    case ACTION_CASINO:
        cout << "[ Welcome to Casino ]" << endl;
        casino();
        break;
    case ACTION_SLEEP:
        cout << "[ You take a rest... ]" << endl;
        player.sleep = 100;
        player.day += 1;
        break;
    case ACTION_SHOP:
        cout << "[ Entering Shop... ]" << endl;
        shop();
        break;
    case ACTION_UPGRADE:
        cout << "[ Upgrade Menu ]" << endl;
        ubgrateMain();
        break;
    case ACTION_USE:
        cout << "[ Inventar ]" << endl;
        inventar();
        break;
    default:
        cout << "Invalid action. Try again." << endl;
        break;
    }
}

void tickPlayerStatus() {
    player.food -= 5;
    player.sleep -= 5;
    player.water -= 3;

    if (player.food < 0) player.food = 0;
    if (player.sleep < 0) player.sleep = 0;
    if (player.water < 0) player.water = 0;

    if (player.food <= 0 || player.sleep <= 0 || player.water <= 0) {
        player.health -= 2;
        if (player.health < 0) player.health = 0;

        if (player.health == 0) {
            cout << "\n*** You collapsed from exhaustion. ***\n";
            cout << "Game Over.\n";
            exit(0);
        }
    }
}


void start() {
    while (true) {
        playerStats();
        Actions();
        tickPlayerStatus();

    }
}


int main()
{
    cout << "======== Welcome to the club body! ========" << endl << endl;
    cout << "Enter YOU name:\n";
    cin >> player.name;

    player.health = 100;
    player.level = 1;
    player.food = 100;
    player.water = 100;
    player.sleep = 100;
    player.cash = getRandomInRange(100, 10000);
    player.blood = 100;
    player.scary = 0;
    player.laky = getRandomInRange(0, 300);
    player.day = 1;


    ubwork.level = 1;
    ubwork.maxlevel = 10;
    ubwork.price = 1000000;

    start();
}
 
// это еще не конец
