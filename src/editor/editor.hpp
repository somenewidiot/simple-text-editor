#pragma once

#include <QMainWindow>
#include <QString>

class QTextEdit;

class EditorWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = nullptr);

private slots:
    void newFile();
    void openFile();
    void saveFile();

private:
    QTextEdit *editor;
    QString currentFilePath;

    void createMenus();
    bool saveToPath(const QString &path);
};
