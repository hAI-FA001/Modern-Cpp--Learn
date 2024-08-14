#include <iostream>
import std;

using namespace std;

int main()
{
    // using ptr arithmentic, we can skip the first newline before the title
    print(1 + R"(
                   Alice's
                Adventures In
                 Wonderland
 
                     by
                LEWIS CARROLL
)");
    println("\n");

    print(1 + R"(
        All in the golden afternoon
Full leisurely we glide;
        For both our oars, with little skill,
By little arms are plied,
        While little hands make vain pretence
Our wanderings to guide.
)");
    println("\n");

    // compiler automatically concatenates adjacent literals
    print("\t\tAll in the golden afternoon\n"
          "Full leisurely we glide;\n"
          "\t\tFor both our oars, with little skill,\n"
          "By little arms are plied,\n"
          "\t\tWhile little hands make vain pretence\n"
          "Our wanderings to guide.\n");
    println("\n");

    print("\t\t\t\tLearn Modern C++");
    println("\n");

    // char types
    // for conversion, codecvt is deprecated, could check International Components for UniCode (ICU)
    char oneByte = 'a';
    wchar_t wideChar_notStandardizedSize = L'a'; // print() only works with 8b, can use wcout
    char8_t oneByteExplicit_forUTF8 = u8'a';
    char16_t forUTF16 = u'a';
    char32_t forUTF32 = U'a';

    const wstring rawStr_wideChar_notStandardizedSize = LR"(a)"; // print() only works with 8b, can use wcout
    const u8string rawStr_oneByteExplicit_forUTF8 = u8R"(a)";
    const u16string rawStr_forUTF16 = uR"(a)";
    const u32string rawStr_forUTF32 = UR"(a)";

    cout << oneByte << '\n';
    cout << static_cast<char>(oneByteExplicit_forUTF8) << '\n';
    cout << static_cast<char>(wideChar_notStandardizedSize) << '\n';
    wcout << static_cast<char>(forUTF16) << '\n';
    wcout << static_cast<char>(forUTF32) << '\n';
}