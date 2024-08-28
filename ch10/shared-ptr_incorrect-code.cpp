#include <string>
#include <vector>
#include <memory>

struct Pupil;

struct Class
{
    int room;
    std::string subject, teacher_name;
    std::vector<std::shared_ptr<Pupil>> pupils;
};

struct Pupil
{
    std::string name;

    // this compiles but is incorrect
    // pointee points back to ptr, shared_ptr is unsuitable here
    // cuz of *dependency cycles*
    // symptom: objects aren't deleted within lifetime of the program
    //   cuz ref count can't drop to 0 for either the pointee or ptr

    // this is also cuz the semantics are wrong:
    //   a Class can't "own" its Pupils if Pupils also "own" the Class
    std::vector<std::shared_ptr<Class>> subjects;
};

int main()
{
    std::vector<std::shared_ptr<Class>> classes;
    std::vector<std::shared_ptr<Pupil>> pupils;

    // containers will be destroyed
    // but ref count won't drop to 0 cuz of dependency cycle
    // so objs won't be destroyed
}