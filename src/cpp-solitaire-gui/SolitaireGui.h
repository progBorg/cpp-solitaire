#ifndef SOLITAIREGUI_H
#define SOLITAIREGUI_H

#include <QApplication>

class SolitaireGui
{
    //===============
    // Local variables
    QApplication app;

public:
    //===============
    // Constructors
    SolitaireGui();

    //===============
    // Methods
    QApplication createWindow(int argc, char **argv);
    void render();

};

#endif // SOLITAIREGUI_H
