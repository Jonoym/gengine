#include <stdlib.h>
#include <iostream>

#include <core/Application.h>

int main(int argc, char* args[]) {

    Gengine::Application app;

    app.Initialise();

    app.Run();

    return 0;
}