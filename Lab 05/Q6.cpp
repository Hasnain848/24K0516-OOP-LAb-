/*Write a program that uses composition to implement a game engine. A game engine is madeup of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/
#include <iostream>
using namespace std;
class Graphicsrenderengine
{
public:
    Graphicsrenderengine()
    {
        cout << "Graphics Render Engine has been created." << endl;
    }

    ~Graphicsrenderengine()
    {
        cout << "Graphics Render Engine has been destroyed." << endl;
    }
    void render()
    {
        cout << "Rendering game objects..." << endl;
    }
};

class InputHandler
{
public:
    InputHandler()
    {
        cout << "Input Handler has been created." << endl;
    }

    ~InputHandler()
    {
        cout << "Input Handler has been destroyed." << endl;
    }
    void processInput()
    {
        cout << "Processing user input..." << endl;
    }
};

class PhysicsEngine
{
public:
    PhysicsEngine()
    {
        cout << "Physics Engine has been created." << endl;
    }

    ~PhysicsEngine()
    {
        cout << "Physics Engine has been destroyed." << endl;
    }
    void updatePhysics()
    {
        cout << "Updating physics simulation..." << endl;
    }
};

class GameEngine
{
    Graphicsrenderengine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    GameEngine()
    {
        cout << "Game Engine has been created." << endl;
    }

    ~GameEngine()
    {
        cout << "Game Engine has been destroyed." << endl;
    }
    void run()
    {
        cout << "Game Loop Running..." << endl;
        input.processInput();
        physics.updatePhysics();
        graphics.render();
    }
};

int main()
{
    GameEngine game;
    game.run();
    return 0;
}