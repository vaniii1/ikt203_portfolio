
#include "controller/TMovieController.h"
#include "list/TMovieList.h"
#include "view/TMovieMenu.h"

int main() {
    TMovieList movieList;
    TMovieController controller(&movieList);
    controller.SeedMovies();

    TMovieMenu menu(&controller);
    menu.GenerateMenu();

    return 0;
}
