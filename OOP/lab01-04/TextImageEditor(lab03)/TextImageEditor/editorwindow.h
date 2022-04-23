#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EditorWindow; }
QT_END_NAMESPACE

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    EditorWindow(QWidget *parent = nullptr);
    ~EditorWindow();

private slots:
    void on_actionNew_text_file_triggered();

    void on_actionOpen_file_triggered();

    void on_textEditTextChanged();

    void on_tabContainer_tabCloseRequested(int index);

    void on_actionSave_file_triggered();
    void on_actionSave_as_triggered();

    void on_actionZoom_in_triggered();

    void on_actionZoom_out_triggered();

    void on_actionOf_current_tab_triggered();

    void on_actionGlobally_triggered();

    void on_actionPrint_triggered();

    void on_actionQuit_triggered();

    void on_actionColor_selected_text_triggered();

    void on_actionSearch_and_replace_triggered();

    void on_actionSearch_triggered();

    void on_actionRemove_color_from_text_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

private:
    Ui::EditorWindow *ui;
};
#endif // EDITORWINDOW_H
