#include "Main.h"
#include "WarpEngine.h"

using WarpEngine::GameWindow;

int main() {

	GameWindow* game = new GameWindow();

	game->Init();

	return 0;
}