#include <iostream>
#include <string>

#include "filesystem.h"

using std::cout;
using std::endl;
using std::string;

/*
* pattern and path
*/
bool valid_args(int argc, char** argv);

/*
* help output
*/
void print_usage();

/*
* command line arguments
*/
struct Args {
    char* pattern;
    char* path;
    bool dir;
};

/*
* populate args struct
*/
void extract_args(struct Args* args, int argc, char** argv);

/*
* driver
*/
int main(int argc, char** argv)
{
    if (!valid_args(argc, argv)) {
        print_usage();
        return 1;
    }

    struct Args args;
    extract_args(&args, argc, argv);

    if (args.dir) {
        traverse_dir(args.path, args.pattern);
    } else {
        search_file(args.path, args.pattern);
    }

    return 0;
}

bool valid_args(int argc, char** argv)
{
    if (argc < 3) {
        return false;
    }

    return true;
}

void print_usage()
{
    cout << "usage: ./a.out <pattern> <path>" << endl;
}

void extract_args(struct Args* args, int argc, char** argv)
{
    args->pattern = argv[1];
    args->path = argv[2];
    args->dir = is_dir(argv[2]);
}
