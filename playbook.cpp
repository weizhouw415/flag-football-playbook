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
    for (const QString& Type : playType) {
        ui->cbbType->addItem(Type);
    }
    ui->numPeople->setMinimum(MIN_MEMBERS);
    ui->numPeople->setMaximum(MAX_MEMBERS);
    ui->numPeople->setValue(DEFAULT_MEMBERS);
}

playbook::~playbook()
{
    delete ui;
}

void playbook::on_closeBt_clicked()
{
    accept();
}

void playbook::on_chkNoCenter_stateChanged(int checked)
{
    if (checked) {
        ui->chkCenterReceive->setChecked(false);
        ui->chkCenterReceive->hide();
        ui->numPeople->setMinimum(MIN_MEMBERS - 1);
        ui->numPeople->setMaximum(MAX_MEMBERS - 1);
    }
    else {
        ui->chkCenterReceive->show();
        ui->numPeople->setMinimum(MIN_MEMBERS);
        ui->numPeople->setMaximum(MAX_MEMBERS);
    }
}


void playbook::on_chkCenterReceive_stateChanged(int checked)
{
    if(checked) {
        ui->numPeople->setMinimum(MIN_MEMBERS - 1);
        ui->numPeople->setMaximum(MAX_MEMBERS - 1);
    }
    else {
        ui->numPeople->setMinimum(MIN_MEMBERS);
        ui->numPeople->setMaximum(MAX_MEMBERS);
    }
}


int playbook::getNumWR()
{
    int WRs = ui->numPeople->value() - 1;
    if (ui->chkCenterReceive->isChecked())
        WRs--;
    return WRs;
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
