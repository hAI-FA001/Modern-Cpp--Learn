#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <iostream>

// check shared-ptr_incorrect-code first
// weak_ptr can solve its problem

class Pupil;

struct Class
{
    Class(int r, std::string_view s, std::string_view t) : room{r}, subject{s}, teacher_name{t} {}
    ~Class()
    {
        std::cout << "~Class(): " << subject << '\n';
    }

    int room;
    std::string subject, teacher_name;
    std::vector<std::shared_ptr<Pupil>> pupils;
};

class Pupil
{
public:
    Pupil(std::string_view n) : name{n} {};
    ~Pupil()
    {
        std::cout << "~Pupil(): " << name << '\n';
    }

    std::string name;
    // only need to change it to weak_ptr
    std::vector<std::weak_ptr<Class>> classes;

    static void add_to_class(const std::shared_ptr<Class> &cls, std::string_view p, std::vector<std::shared_ptr<Pupil>> pupils)
    {
        auto iter_p = std::find_if(std::cbegin(pupils), std::cend(pupils), [&p](auto ec)
                                   { return p == ec->name; });
        cls->pupils.push_back(*iter_p);
        (*iter_p)->classes.push_back(cls);
    };
};

void print_classes(const std::vector<std::shared_ptr<Class>> &classes)
{
    for (const auto &c : classes)
    {
        std::cout << "Room: " << c->room << "\nSubject: " << c->subject
                  << "\nTeacher: " << c->teacher_name << "\nPupils: ";

        for (const auto &p : c->pupils)
        {
            std::cout << p->name << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    // for vec of shared_ptr, factory func needs to be used to generate its elements
    // func template make_shared is used, it forwards its args to ctor for specified type
    std::vector<std::shared_ptr<Class>> classes{
        std::make_shared<Class>(101, "English", "Mr White"),
        std::make_shared<Class>(150, "Math", "Ms Black")};

    std::vector<std::shared_ptr<Pupil>> pupils{
        std::make_shared<Pupil>("Paul"),
        std::make_shared<Pupil>("Percy"),
        std::make_shared<Pupil>("Perry"),
        std::make_shared<Pupil>("Phoebe"),
        std::make_shared<Pupil>("Penny"),
        std::make_shared<Pupil>("Patricia"),
    };

    // if we capture classes by value, then adding new classes won't update the copy of classes
    // so it won't add pupil to any classes we add after this point
    auto add_to_class = [&classes, &pupils](std::string_view c, std::string_view p)
    {
        // std::find() can't easily be used to search for a matching shared_ptr
        // so std::find_if() is used
        // this func iterates through the captured vecs w/ a "predicate" lambda
        auto iter_c = std::find_if(std::cbegin(classes), std::cend(classes),
                                   [&c](auto ec)
                                   { return c == ec->subject; });

        auto iter_p = std::find_if(std::cbegin(pupils), std::cend(pupils),
                                   [&p](auto ep)
                                   { return p == ep->name; });

        if (iter_c != std::cend(classes) and iter_p != std::cend(pupils))
        {
            // *iter_c gives shared_ptr to Class
            // then we deref the ptr to get pupils member var
            (*iter_c)->pupils.push_back(*iter_p);
            // similarly
            (*iter_p)->classes.push_back(*iter_c);
        }
        else
        {
            std::cerr << "Could not add " << p << " to " << c << '\n';
            if (iter_c == std::cend(classes))
            {
                std::cerr << "Class not found\n";
            }
            if (iter_p == std::cend(pupils))
            {
                std::cerr << "Pupil not found\n";
            }
        }
    };

    auto iter_eng = std::find_if(std::cbegin(classes), std::cend(classes), [](auto ec)
                                 { return "English" == ec->subject; });
    auto eng = *iter_eng;
    Pupil::add_to_class(eng, "Paul", pupils);
    Pupil::add_to_class(eng, "Percy", pupils);
    Pupil::add_to_class(eng, "Phoebe", pupils);
    Pupil::add_to_class(eng, "Penny", pupils);

    add_to_class("Math", "Paul");
    add_to_class("Math", "Perry");
    add_to_class("Math", "Phoebe");
    add_to_class("Math", "Patricia");

    classes.emplace_back(std::make_shared<Class>(260, "IT", "Mrs Brown"));
    add_to_class("IT", "Percy");
    add_to_class("IT", "Perry");

    print_classes(classes);
    std::cout << '\n';
    // classes.erase(classes.begin() + 1, classes.begin() + 2);
    // std::cout << '\n';
    // print_classes(classes);

    auto third_class = std::find(classes.cbegin(), classes.cend(), classes[2]);
    if (third_class != classes.cend())
    {
        std::cout << "subject of classes[2]:  " << (*third_class)->subject << '\n';
    }

    for (;;)
    {
        std::cout << "Enter a pupil name (blank line to quit): ";

        std::string s;
        std::getline(std::cin, s);

        if (s.empty())
        {
            break;
        }

        auto iter_p = std::find_if(std::cbegin(pupils), std::cend(pupils),
                                   [&](auto ep)
                                   { return s == ep->name; });

        if (iter_p != std::cend(pupils))
        {
            std::cout << "Classes: ";

            // the classes member var is a vector of *weak_ptr*
            for (const auto &c : (*iter_p)->classes)
            {
                // a shared_ptr is obtained from weak_ptr using lock()
                if (auto pc = c.lock(); pc)
                {
                    std::cout << pc->subject << ' ';
                }
            }
            std::cout << '\n';
        }
        else
        {
            std::cout << "Name not recognized\n";
        }
    }
}