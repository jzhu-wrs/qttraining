#include <QApplication>
#include <QPushButton>
#include <QStateMachine>
#include <QState>
#include <QSignalTransition>
#include <QPropertyAnimation>
int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    QPushButton *button = new QPushButton("Animated Button");
    button->show();
    QStateMachine *machine = new QStateMachine;
//QState *state1 = new QState(machine->rootState());
    QState *state1 = new QState(machine);
    state1->assignProperty(button, "geometry", QRect(0, 0, 150, 30));
    machine->setInitialState(state1);
//QState *state2 = new QState(machine->rootState());
    QState *state2 = new QState(machine);
    state2->assignProperty(button, "geometry", QRect(250, 250, 150, 30));
    QSignalTransition *transition1 = state1->addTransition(button,
    SIGNAL(clicked()), state2);
    transition1->addAnimation(new QPropertyAnimation(button, "geometry"));
    QSignalTransition *transition2 = state2->addTransition(button, SIGNAL(clicked()), state1);
    transition2->addAnimation(new QPropertyAnimation(button, "geometry"));
    machine->start();
    app.exec();
}
