#include "editor.hpp"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>

EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Central text editor
    editor = new QTextEdit(this);
    setCentralWidget(editor);

    // Setup menus
    createMenus();

    resize(800, 600);
    setWindowTitle("Simple Text Editor");
}

void EditorWindow::createMenus() {
    // File menu
    QMenu *fileMenu = menuBar()->addMenu("&File");

    QAction *newAction  = fileMenu->addAction("&New");
    QAction *openAction = fileMenu->addAction("&Open");
    QAction *saveAction = fileMenu->addAction("&Save");
    fileMenu->addSeparator();
    QAction *quitAction = fileMenu->addAction("&Quit");

    // Keyboard shortcuts
    newAction->setShortcut(QKeySequence::New);
    openAction->setShortcut(QKeySequence::Open);
    saveAction->setShortcut(QKeySequence::Save);

    // Connect actions
    connect(newAction,  &QAction::triggered, this, &EditorWindow::newFile);
    connect(openAction, &QAction::triggered, this, &EditorWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &EditorWindow::saveFile);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
}

void EditorWindow::newFile() {
    editor->clear();
    currentFilePath.clear();
    setWindowTitle("Simple Text Editor");
}

void EditorWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Open File",
        "",
        "Text Files (*.txt);;All Files (*)"
    );

    if (path.isEmpty())
        return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file");
        return;
    }

    QTextStream in(&file);
    editor->setPlainText(in.readAll());
    file.close();

    currentFilePath = path;
    setWindowTitle(path);
}

void EditorWindow::saveFile() {
    if (currentFilePath.isEmpty()) {
        QString path = QFileDialog::getSaveFileName(
            this,
            "Save File",
            "",
            "Text Files (*.txt);;All Files (*)"
        );

        if (path.isEmpty())
            return;

        currentFilePath = path;
    }

    if (!saveToPath(currentFilePath)) {
        QMessageBox::warning(this, "Error", "Could not save file");
        return;
    }

    setWindowTitle(currentFilePath);
}

bool EditorWindow::saveToPath(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << editor->toPlainText();
    file.close();

    return true;
}
