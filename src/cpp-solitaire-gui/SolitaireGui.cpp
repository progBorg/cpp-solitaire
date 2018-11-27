#include "SolitaireGui.h"

SolitaireGui::SolitaireGui() {

}

QApplication SolitaireGui::createWindow(int argc, char **argv) {
    this->app(argc, **argv);
    return app;
}

void SolitaireGui::render() {

}
