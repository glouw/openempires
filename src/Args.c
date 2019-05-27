#include "Args.h"

#include "Util.h"

#include <assert.h>

static bool Check(const char* const arg, const char* const full, const char* const hyphen)
{
    return Util_StringEqual(arg, full)
        || Util_StringEqual(arg, hyphen);
}

Args Args_Parse(int32_t argc, char* argv[])
{
    static Args zero;
    Args args = zero;
    args.path = "/home/gl/.steam/steam/steamapps/common/Age2HD/Directory/data/";
    for(int32_t i = 0; i < argc; i++)
    {
        char* const arg = argv[i];
        if(Check(arg, "--demo", "-d"))
        {
            args.demo = true;
            if(i != argc - 1)
                args.color = (Color) atoi(argv[++i]);
        }
        else
        if(Check(arg, "--path", "-p"))
            args.path = argv[i + 1];
    }
    assert(args.path);
    return args;
}
