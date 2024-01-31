#include "playbook.h"
#include "ui_playbook.h"
#include <QKeyEvent>

playbook::playbook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::playbook)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    ui->tytle->installEventFilter(this);
}

playbook::~playbook()
{
    delete ui;
}

void playbook::on_closeBt_clicked()
{
    accept();
}

bool playbook::eventFilter(QObject* object, QEvent* event)
{

    if (object == ui->tytle &&
        (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseMove))
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (event->type() == QEvent::MouseButtonPress && mouseEvent->button() == Qt::LeftButton)
        {
            m_dragPosition = mouseEvent->globalPos() - frameGeometry().topLeft();
            return true;
        }
        else if (event->type() == QEvent::MouseMove && mouseEvent->buttons() & Qt::LeftButton)
        {
            move(mouseEvent->globalPos() - m_dragPosition);
            return true;
        }
    }
    return true;
}

