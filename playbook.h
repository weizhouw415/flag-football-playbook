#ifndef PLAYBOOK_H
#define PLAYBOOK_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class playbook; }
QT_END_NAMESPACE

class playbook : public QDialog
{
    Q_OBJECT

public:
    playbook(QWidget *parent = nullptr);
    ~playbook();

private slots:
    void on_closeBt_clicked();

private:
    Ui::playbook *ui;
    QPoint m_dragPosition;

protected:
  bool eventFilter(QObject* object, QEvent* event) override;
};
#endif // PLAYBOOK_H
