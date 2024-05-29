int main()
{
    Game* game = new Game();
    game->start();
    delete game;
    game = nullptr;
    return 0;
}
