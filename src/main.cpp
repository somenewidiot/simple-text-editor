#include "editor/editor.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    EditorWindow editor;
    editor.show();
    return app.exec();
}
