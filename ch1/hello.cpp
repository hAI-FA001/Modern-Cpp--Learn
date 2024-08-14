import std;

int main()
{
    // must be positioned anywhere before using its functions
    // using namespace std;
    // using std::print;
    // using std::println;

    // previously, stream objects would be used
    // the zero byte/null terminator is required for print/println to know when the string ends
    std::println("Hello, world!");
    std::print("Hello, world!\n");
    std::print("Hello, world!\x0A"); // newline's ASCII in hex
    std::print("Hello, world!\12");  // newline's ASCII in octal
    std::println("Last sentence.");
    std::print("\n\n");

    std::println("Hello\0, world!"); // stops at Hello but prints newline too
    std::print("Hello, world!\0");   // no difference w/ and w/o \0 at the end
    // on Windows, need to type `chcp 65001` so it uses UTF-8 on the console
    std::println("$(USD) £(GBP) €(EUR)");
    std::println("π has the value 3.14159...");
    std::print("\n\n");

    // string literals are interpreted at compile time, escape characters are translated
    // result is raw string, stored in read-only memory
    // program uses a ptr to the first character, the ptr is a variable
    std::println("Hello, world!" + 7); // will print "world!" cuz we shift the ptr
    std::println(R"(This    is  a   raw string \ no need to escape special \c\h\a\r\a\c\t\e\r\s)");
    std::println(R"someUniqueSeq(( this uses )" )someUniqueSeq"); // need to put a unique char/sequence if want to use )"
}
