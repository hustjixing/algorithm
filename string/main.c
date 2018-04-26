#include "sstring.h"

int main(int argc, char** argv)
{
    SString* s;
    StrAssign(s, "test sstring");
    PrintStr(s);
    return 1;
}