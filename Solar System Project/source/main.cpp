/**************************************************************
 * COM324 - Computer Graphics and Multimedia
 * Assignment: Solar System Application
 * Student: [Your Name]
 * Registration Number: [Your Reg Number]
 **************************************************************/

#include "../headers/Application.h"

int main() {
    Application app;
    app.Initialise(800, 600, "COM324 - Solar System");
    app.Run();
    app.Shutdown();
    return 0;
}