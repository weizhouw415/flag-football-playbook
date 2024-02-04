#ifndef PLAYBOOK_H
#define PLAYBOOK_H

#include <QDialog>
#include <vector>

#define MAX_MEMBERS 7
#define MIN_MEMBERS 3
#define DEFAULT_MEMBERS 5

QT_BEGIN_NAMESPACE
namespace Ui { class playbook; }
QT_END_NAMESPACE

class playbook : public QDialog
{
    Q_OBJECT

public:
    playbook(QWidget *parent = nullptr);
    ~playbook();
//    void Init();

private slots:
    void on_closeBt_clicked();
    void on_chkNoCenter_stateChanged(int checked);
    void on_chkCenterReceive_stateChanged(int checked);

private:
    Ui::playbook *ui;
    const std::vector<QString> playType = {"Pass", "Run", "RPO", "Others"};
    int getNumWR();
    QPoint m_dragPosition;

protected:
  bool eventFilter(QObject* object, QEvent* event) override;
};
#endif // PLAYBOOK_H
