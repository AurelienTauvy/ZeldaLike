#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include <QObject>

class Interactable
{
private:
    QString dialog;
public:
    Interactable();
    virtual ~Interactable();
    Interactable(QString);
    void setDialog(QString);
    QString getDialog();
    virtual QString interact();
};

#endif // INTERACTABLE_H
