
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <vector>
class QCheckBox;
class QLabel;
class QDoubleSpinBox;
class QFrame;
class QPushButton;
class QComboBox;
struct brockenrockproperties;
class QGroupBox;
class QHBoxLayout;
class QStringList;
class QStringListModel;

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QStringList* stringlist;
    QStringListModel* model;

    QLabel* northlabel;
    QComboBox* northcombo;
    brockenrockproperties* northbrockenrock;
    QGroupBox* northgroup;

    QLabel* eastlabel;
    QComboBox* eastcombo;
    brockenrockproperties* eastbrockenrock;
    QLabel* southlabel;
    QComboBox* southcombo;
    brockenrockproperties* southbrockenrock;
    QLabel* westlabel;
    QComboBox* westcombo;
    brockenrockproperties* westbrockenrock;
    QLabel* toplabel;
    QComboBox* topcombo;
    brockenrockproperties* topbrockenrock;
    QGroupBox* floordimensiongroup;
    QLabel* widthlabel;
    QDoubleSpinBox*  widthspinbox;
    QLabel* heightlabel;
    QDoubleSpinBox*  heightspinbox;
    QLabel* depthlabel;
    QDoubleSpinBox*  depthspinbox;
    QGroupBox* brokenrockgroup;
    QLabel* cubeshrinklabel;
    QDoubleSpinBox*  cubeshrinkspinbox;
    QLabel* displacementlabel;
    QDoubleSpinBox*  displacementspinbox;
private slots:
        void NorthComboCurrentIndexChanged(int);
        void SouthComboCurrentIndexChanged(int);
        void EastComboCurrentIndexChanged(int);
        void WestComboCurrentIndexChanged(int);
public:
    Dialog(QWidget *parent = nullptr);
    void createbrokenrockproperties(QHBoxLayout*,brockenrockproperties*);
    void hidebrokenrockproperties(brockenrockproperties*,bool hide);

    ~Dialog();
};
#endif // DIALOG_H
