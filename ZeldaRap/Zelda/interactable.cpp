#include "interactable.h"
#include <QDebug>

Interactable::Interactable()
{

}
Interactable::~Interactable(){
    qDebug()<<"Destroying Interactable";
}
Interactable::Interactable(QString dial){
    this->dialog = dial;
}

void Interactable::setDialog(QString dial){
    this->dialog = dial;
}

QString Interactable::getDialog(){
    return this->dialog;
}
QString Interactable::interact(){
    return "";
}
