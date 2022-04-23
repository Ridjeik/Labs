#include "editorwindow.h"
#include "searchreplacedialog.h"
#include "ui_editorwindow.h"

#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QScrollArea>
#include <Qt>
#include <QTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>


EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::on_textEditTextChanged()
{
    QString tabText = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabText.endsWith("*"))
        ui->tabContainer->setTabText(ui->tabContainer->currentIndex(), tabText + "*");
}

void EditorWindow::on_actionNew_text_file_triggered()
{
    QWidget *tabWidget = new QWidget;

    QVBoxLayout *tabLayout = new QVBoxLayout;
    QTextEdit *tabTextEdit = new QTextEdit;

    connect(tabTextEdit, &QTextEdit::textChanged, this, &EditorWindow::on_textEditTextChanged);

    tabLayout->setContentsMargins(2,2,2,2);
    tabLayout->addWidget(tabTextEdit);

    tabWidget->setLayout(tabLayout);
    ui->tabContainer->addTab(tabWidget, "[Text] Untitled");
    ui->tabContainer->setCurrentIndex(ui->tabContainer->count() - 1);
}

void EditorWindow::on_actionOpen_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "C:\\", "Text files (*.txt);;Image files(*.png *.jpg)");
    if(filename.size() == 0) return;

    for(int i = 0; i < ui->tabContainer->count(); i++)
    {
        qDebug() << filename << " " << ui->tabContainer->tabText(i);
        if(ui->tabContainer->tabText(i).endsWith(filename))
        {
            qDebug() << "Here";
            ui->tabContainer->setCurrentIndex(i);
            return;
        }
    }

    QWidget *tabWidget = new QWidget;
    QVBoxLayout *tabLayout = new QVBoxLayout;
    tabLayout->setContentsMargins(2,2,2,2);

    if(filename.endsWith(".txt"))
    {
        QTextEdit *tabTextEdit = new QTextEdit;
        FILE *openedFile = fopen(filename.toStdString().data(), "r");
        char currentChar;
        QString fileText;
        while((currentChar = getc(openedFile)) != EOF)
        {
            fileText.append(currentChar);
        }
        tabTextEdit->setText(fileText);
        tabLayout->addWidget(tabTextEdit);

        tabWidget->setLayout(tabLayout);
        ui->tabContainer->addTab(tabWidget, "[Text] " + filename);
        ui->tabContainer->setCurrentIndex(ui->tabContainer->count() - 1);
        connect(tabTextEdit, &QTextEdit::textChanged, this, &EditorWindow::on_textEditTextChanged);
        fclose(openedFile);
    }
    else
    {
        QScrollArea *tabScrollArea = new QScrollArea;
        QPixmap tabImage(filename);
        QLabel *tabLabel = new QLabel;
        tabLabel->setScaledContents(true);
        tabLabel->setPixmap(tabImage);
        tabScrollArea->setAlignment(Qt::AlignCenter);

        tabScrollArea->setWidget(tabLabel);
        tabLayout->addWidget(tabScrollArea);
        tabWidget->setLayout(tabLayout);
        ui->tabContainer->addTab(tabWidget, "[Image] " + filename);
        ui->tabContainer->setCurrentIndex(ui->tabContainer->count() - 1);
    }

}


void EditorWindow::on_tabContainer_tabCloseRequested(int index)
{
    QString tabText = ui->tabContainer->tabText(index);
    if(tabText.endsWith("*"))
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Save)
        {
            on_actionSave_file_triggered();
        }
        if(!(ret == QMessageBox::Cancel))
        {
            ui->tabContainer->removeTab(index);
        }
    }
    else
    {
        ui->tabContainer->removeTab(index);
    }

}


void EditorWindow::on_actionSave_file_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;

    if(tabName.endsWith('*'))
    {
        tabName.chop(1);
        ui->tabContainer->setTabText(ui->tabContainer->currentIndex(), tabName);
    }
    if(tabName == "[Text] Untitled")
    {
        on_actionSave_as_triggered();
    }
    else
    {
        char *filename = strchr(tabName.toStdString().data(), ' ') + 1;
        FILE *openedFile = fopen(filename, "w");

        QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
        fputs(textField->toPlainText().toStdString().c_str(), openedFile);

        fclose(openedFile);
    }

}



void EditorWindow::on_actionSave_as_triggered()
{
    if(!ui->tabContainer->currentWidget()) return;
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());

    if(tabName.startsWith("[Text]"))
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save file as..", "C:\\", "Text files (*.txt)");
        if(filename.size() == 0) return;
        FILE* openedFile = fopen(filename.toStdString().data(), "w");
        QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
        fputs(textField->toPlainText().toStdString().c_str(), openedFile);
        ui->tabContainer->setTabText(ui->tabContainer->currentIndex(), "[Text] " + filename);
        fclose(openedFile);
    }
    else
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save file as..", "C:\\", "Image files(*.png *.jpg)");
        if(filename.size() == 0) return;

        QScrollArea *scrollWidget = qobject_cast<QScrollArea*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
        QPixmap pixmap = qobject_cast<QLabel*>(scrollWidget->widget())->pixmap();
        pixmap.save(filename);

        ui->tabContainer->setTabText(ui->tabContainer->currentIndex(), "[Image] " + filename);
    }
}

static double zoomFactor = 1;
void EditorWindow::on_actionZoom_in_triggered()
{
    if(zoomFactor > 3) return;

    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Image]")) return;
    QScrollArea *scrollWidget = qobject_cast<QScrollArea*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
    QLabel *label = qobject_cast<QLabel*>(scrollWidget->widget());
    zoomFactor *= 1.25;
    qDebug() << zoomFactor;
    label->resize(label->size()*1.25);
}


void EditorWindow::on_actionZoom_out_triggered()
{

    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Image]")) return;
    QScrollArea *scrollWidget = qobject_cast<QScrollArea*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
    QLabel *label = qobject_cast<QLabel*>(scrollWidget->widget());
    if(label->size().width() < 100 || label->size().height() < 100) return;
    zoomFactor /= 1.25;
    qDebug() << zoomFactor;
    label->resize(label->size()/1.25);
}


void EditorWindow::on_actionOf_current_tab_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    bool gotFont;
    QFont newFont = QFontDialog::getFont(&gotFont);
    if(gotFont) ui->tabContainer->currentWidget()->setFont(newFont);
}


void EditorWindow::on_actionGlobally_triggered()
{
    bool gotFont;
    QFont newFont = QFontDialog::getFont(&gotFont);
    if(gotFont) setFont(newFont);
}


void EditorWindow::on_actionPrint_triggered()
{
    on_actionSave_file_triggered();
    QPrinter printer;
    if(!ui->tabContainer->currentWidget()) return;
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted)
        return;

    QPainter painter;
    painter.begin(&printer);

    if(tabName.startsWith("[Text]"))
    {
        QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
        painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, textField->toPlainText());
    }
    else
    {
        QScrollArea *scrollWidget = qobject_cast<QScrollArea*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
        QPixmap pixmap = qobject_cast<QLabel*>(scrollWidget->widget())->pixmap();
        painter.drawPixmap(0,0,pixmap.width(), pixmap.height(), pixmap);
    }

    painter.end();
}


void EditorWindow::on_actionQuit_triggered()
{
    close();
}


void EditorWindow::on_actionColor_selected_text_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QColor color = QColorDialog::getColor();

    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());
    textField->setTextColor(color);
}


void EditorWindow::on_actionSearch_and_replace_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    SearchReplaceDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        QString *res = dialog.getValues();
        if(res[0].size() != 0 && res[1].size() != 0)
        {
            QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

            QString text = textField->toPlainText();
            text.replace(res[0], res[1]);

            textField->setText(text);
        }
        delete[] res;
    }
}


void EditorWindow::on_actionSearch_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    bool gotText;
    QString textToFind = QInputDialog::getText(this, "Find text..", "Text to find:", QLineEdit::Normal, "", &gotText);

    if(!gotText) return;

    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    QString text = textField->toPlainText();
    qDebug() << text.indexOf(textToFind);

    int startPos = text.indexOf(textToFind, 0, Qt::CaseInsensitive);
    if(startPos == -1)
    {
        QMessageBox::information(this, "Text not found", "Specified text wasn't found!");
        return;
    }

    while(startPos != -1){
        QTextCursor c = textField->textCursor();
        c.setPosition(startPos);
        c.setPosition(startPos + textToFind.size(), QTextCursor::KeepAnchor);
        textField->setTextCursor(c);
        textField->setTextColor(Qt::red);
        startPos = text.indexOf(textToFind, startPos + textToFind.size(), Qt::CaseInsensitive);
    }

}


void EditorWindow::on_actionRemove_color_from_text_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->setTextColor(Qt::black);
}


void EditorWindow::on_actionUndo_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->undo();
}


void EditorWindow::on_actionRedo_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->redo();
}


void EditorWindow::on_actionCopy_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->copy();
}


void EditorWindow::on_actionCut_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->cut();
}


void EditorWindow::on_actionPaste_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->paste();
}




void EditorWindow::on_actionSelect_All_triggered()
{
    QString tabName = ui->tabContainer->tabText(ui->tabContainer->currentIndex());
    if(!tabName.startsWith("[Text]")) return;
    QTextEdit* textField = qobject_cast<QTextEdit*>(ui->tabContainer->currentWidget()->layout()->itemAt(0)->widget());

    textField->selectAll();
}





