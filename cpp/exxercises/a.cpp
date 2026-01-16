#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <chrono>

#include <ostream>

struct character
{
    std::string name;
    short star;
};

void init_text(int *opt); // prototipo para evitar error en compilacion
void loading();

void show_character(
    double roll,
    std::mt19937_64 &rng,
    const std::vector<std::string> &characters_5,
    const std::vector<std::string> &characters_4,
    const std::vector<std::string> &items,
    std::vector<character> &account);

std::ostream &operator<<(std::ostream &os, const character &c)
{
    os << c.name << " (" << c.star << "⭐)";
    return os;
}

double CHANCE_CHARACTER = 0.6;
double CHANCE_4_STAR = 5.7;

int main()
{
    int opt, prob_n, count_deseos = 0;
    short MAX_PITTY = 90, MIN_PITTY = 65;

    bool gacha_time = true;

    std::mt19937_64 rng(std::random_device{}());

    std::vector<character> account;
    std::vector<int> pitty_v = {90};
    std::vector<std::string> characters_5 = {"Varesa", "Furina", "Hu tao", "Miyabi"};
    std::vector<std::string> characters_4 = {"Nekomata", "Barbara", "Yuzuha", "Alice", "Shun gua"};
    std::vector<std::string> items = {"sword-1", "arrow", "arco-2", "sword-3", "sword-2"};

    std::uniform_real_distribution<double> prob(0.0, 100.0);

    std::uniform_int_distribution<int> pitty_n(0, pitty_v.size() - 1);

    while (gacha_time)
    {
        init_text(&opt);

        if (opt > 3 || opt == 0)
        {
            std::cout << "No se encuentra esa opcion" << std::endl;
            continue;
        }

        double roll = prob(rng);

        prob_n = 70 + (roll / 100) * (MAX_PITTY - MIN_PITTY);
        std::cout << "El pitty que salio es:  " << prob_n << std::endl;
        pitty_v.push_back(prob_n);

        switch (opt)
        {
        case 1:
        {
            std::cout << "Tiro de 10 deseos" << std::endl;

            bool obtain = true;

            for (int i = 0; i < 10; i++)
            {
                count_deseos++;
                std::cout << "tiro " << count_deseos << std::endl;

                double roll = prob(rng);
                loading();
                int pitty_prob = pitty_v[pitty_n(rng)];
                if (count_deseos == prob_n || count_deseos == MAX_PITTY || count_deseos == pitty_prob)
                {
                    std::uniform_int_distribution<int> pick_5(0, characters_5.size() - 1);
                    std::string star_5 = characters_5[pick_5(rng)];
                    std::cout << "⭐⭐⭐⭐⭐ " << star_5 << "\n";
                    account.push_back({star_5, 5});
                }
                else if (obtain)
                {
                    obtain = false;
                    std::uniform_int_distribution<int> pick_4(0, characters_4.size() - 1);
                    std::string star_4 = characters_4[pick_4(rng)];
                    std::cout << "⭐⭐⭐⭐ " << star_4 << "\n";
                    account.push_back({star_4, 4});
                }
                else
                {
                    show_character(roll, rng, characters_5, characters_4, items, account);
                }
            }

            break;
        }

        case 2:
        {
            std::cout << "Tirando un deseo" << std::endl;
            count_deseos++;

            double roll = prob(rng);
            std::cout << "tiro " << count_deseos << std::endl;

            show_character(roll, rng, characters_5, characters_4, items, account);

            break;
        }

        case 3:
        {
            for (const character &x : account)
            {
                std::cout << x << std::endl;
            }
            break;
        }

        case 4:
        {
            std::cout << "Salio del gacha" << std::endl;
            gacha_time = false;
            break;
        }

        default:
        {
            gacha_time = false;
            break;
        }
        }

        if (count_deseos >= 90)
        {
            count_deseos = 0;
        }
    }

    return 0;
}

void init_text(int *opt)
{
    std::cout << R"(
        1.- Tirar 10 deseos
        2.- Tirar 1 deseo
        3.- Show my wish's
        4.- Salir
    )" << std::endl;

    std::cin >> *opt;
}

void show_character(
    double roll,
    std::mt19937_64 &rng,
    const std::vector<std::string> &characters_5,
    const std::vector<std::string> &characters_4,
    const std::vector<std::string> &items,
    std::vector<character> &account)
{
    std::uniform_int_distribution<int> pick_5(0, characters_5.size() - 1);
    std::uniform_int_distribution<int> pick_3(0, characters_4.size() - 1);
    std::uniform_int_distribution<int> pick_item(0, items.size() - 1);

    std::string ch;
    character personaje{};

    if (roll < CHANCE_CHARACTER)
    {
        ch = characters_5[pick_5(rng)];
        std::cout << "⭐⭐⭐⭐⭐ "
                  << ch << "\n";
        personaje.star = 5;
    }
    else if (roll < CHANCE_CHARACTER + CHANCE_4_STAR)
    {
        ch = characters_4[pick_3(rng)];
        std::cout << "⭐⭐⭐⭐ "
                  << ch << "\n";
        personaje.star = 4;
    }
    else
    {
        std::cout << "⭐⭐⭐ "
                  << items[pick_item(rng)] << "\n";
        return;
    }

    personaje.name = ch;

    account.push_back(personaje);
}

void loading()
{
    std::cout << "Tirando deseo";
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "." << std::endl;
}