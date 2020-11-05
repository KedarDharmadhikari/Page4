#include "dialog.h"
#include <QRadioButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QStringList>
#include <QStringListModel>
#include <QDebug>

struct brockenrockproperties
{
    QLabel*  beginingheightlabel;
    QLabel*  peakheightlabel;
    QLabel*  peakAtlabel;
    QLabel*  endheightlabel;
    QLabel*  widthlabel;
    QDoubleSpinBox*  beginingheightspin;
    QDoubleSpinBox*  peakheightspin;
    QDoubleSpinBox*  peakAtspin;
    QDoubleSpinBox*  endheightspin;
    QDoubleSpinBox*  widthspin;
    brockenrockproperties()
    {
        beginingheightlabel = new QLabel("Begining Height");
        beginingheightspin = new QDoubleSpinBox();
        peakheightlabel = new QLabel("Peak Height");
        peakheightspin = new QDoubleSpinBox();
        peakAtlabel = new QLabel("Peak At");
        peakAtspin = new QDoubleSpinBox();
        endheightlabel = new QLabel("End Height");
        endheightspin = new QDoubleSpinBox();
        widthlabel = new QLabel("Width");
        widthspin = new QDoubleSpinBox();


        beginingheightspin->setMinimumWidth(62);
        beginingheightspin->setMaximumWidth(62);
        peakheightspin->setMinimumWidth(62);
        peakheightspin->setMaximumWidth(62);
        peakAtspin->setMinimumWidth(62);
        peakAtspin->setMaximumWidth(62);
        endheightspin->setMinimumWidth(62);
        endheightspin->setMaximumWidth(62);
        widthspin->setMinimumWidth(62);
        widthspin->setMaximumWidth(62);
    }
};

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout* mainlayout = new QVBoxLayout();
    stringlist = new QStringList(std::initializer_list<QString> {"Insitu","Air","Broken Rock"});
    model = new QStringListModel(*stringlist);

    QHBoxLayout* northlayouthor = new QHBoxLayout();
    northlabel = new QLabel("North");
    northcombo = new QComboBox();
    northcombo->setModel(model);
    northlayouthor->addWidget(northlabel);
    northlayouthor->addSpacing(10);
    northlayouthor->addWidget(northcombo);
    northlayouthor->addSpacing(5);
    northbrockenrock = new brockenrockproperties();
    createbrokenrockproperties(northlayouthor,northbrockenrock);
    hidebrokenrockproperties(northbrockenrock,false);
    QObject::connect(northcombo,SIGNAL(currentIndexChanged(int)),this, SLOT(NorthComboCurrentIndexChanged(int)));

    QHBoxLayout* eastlayouthor = new QHBoxLayout();
    eastlabel = new QLabel("East");
    eastcombo = new QComboBox();
    eastcombo->setModel(model);
    eastlayouthor->addWidget(eastlabel);
    eastlayouthor->addSpacing(10);
    eastlayouthor->addWidget(eastcombo);
    eastlayouthor->addSpacing(5);
    eastbrockenrock = new brockenrockproperties();
    createbrokenrockproperties(eastlayouthor,eastbrockenrock);
    hidebrokenrockproperties(eastbrockenrock,false);
    QObject::connect(eastcombo,SIGNAL(currentIndexChanged(int)),this, SLOT(EastComboCurrentIndexChanged(int)));

    QHBoxLayout* southlayouthor = new QHBoxLayout();
    southlabel = new QLabel("South");
    southcombo = new QComboBox();
    southcombo->setModel(model);
    southlayouthor->addWidget(southlabel);
    southlayouthor->addSpacing(10);
    southlayouthor->addWidget(southcombo);
    southlayouthor->addSpacing(5);
    southbrockenrock = new brockenrockproperties();
    createbrokenrockproperties(southlayouthor,southbrockenrock);
    hidebrokenrockproperties(southbrockenrock,false);
    QObject::connect(southcombo,SIGNAL(currentIndexChanged(int)),this, SLOT(SouthComboCurrentIndexChanged(int)));

    QHBoxLayout* westlayouthor = new QHBoxLayout();
    westlabel = new QLabel("West");
    westcombo = new QComboBox();
    westcombo->setModel(model);
    westlayouthor->addWidget(westlabel);
    westlayouthor->addSpacing(10);
    westlayouthor->addWidget(westcombo);
    westlayouthor->addSpacing(5);
    westbrockenrock = new brockenrockproperties();
    createbrokenrockproperties(westlayouthor,westbrockenrock);
    hidebrokenrockproperties(westbrockenrock,false);
    QObject::connect(westcombo,SIGNAL(currentIndexChanged(int)),this, SLOT(WestComboCurrentIndexChanged(int)));


    QHBoxLayout* toplayouthor = new QHBoxLayout();
    toplabel = new QLabel("Top");
    topcombo = new QComboBox();
    topcombo->setModel(model);
    toplayouthor->addWidget(toplabel);
    toplayouthor->addSpacing(10);
    toplayouthor->addWidget(topcombo);
    toplayouthor->addSpacing(5);
    topbrockenrock=new brockenrockproperties();
    createbrokenrockproperties(toplayouthor,topbrockenrock);
    hidebrokenrockproperties(topbrockenrock,false);

    floordimensiongroup = new QGroupBox("Floor Dimensions");
    QHBoxLayout* floorlayouthor = new QHBoxLayout();
    widthlabel = new QLabel("Width (m)");
    floorlayouthor->addWidget(widthlabel);
    widthspinbox = new QDoubleSpinBox();
    floorlayouthor->addWidget(widthspinbox);
    heightlabel= new QLabel("Height (m)");
    floorlayouthor->addWidget(heightlabel);
    heightspinbox = new QDoubleSpinBox();
    floorlayouthor->addWidget(heightspinbox);
    depthlabel= new QLabel("Depth (m)");
    floorlayouthor->addWidget(depthlabel);
    depthspinbox = new QDoubleSpinBox();
    floorlayouthor->addWidget(depthspinbox);
    floordimensiongroup->setLayout(floorlayouthor);

    brokenrockgroup = new QGroupBox("Brocken Rock Common Properties");
    QHBoxLayout* brokenrockgrouphor = new QHBoxLayout();
    cubeshrinklabel  = new QLabel("Cube Shrinkage (%)");
    brokenrockgrouphor->addWidget(cubeshrinklabel);
    cubeshrinkspinbox = new QDoubleSpinBox();
    brokenrockgrouphor->addWidget(cubeshrinkspinbox);
    displacementlabel = new QLabel("Displacement to break(time of cube size)");
    brokenrockgrouphor->addWidget(displacementlabel);
    displacementspinbox = new QDoubleSpinBox();
    brokenrockgrouphor->addWidget(displacementspinbox);
    brokenrockgroup->setLayout(brokenrockgrouphor);

    mainlayout->addItem(northlayouthor);
    mainlayout->addSpacing(20);
    mainlayout->addItem(eastlayouthor);
    mainlayout->addSpacing(20);
    mainlayout->addItem(southlayouthor);
    mainlayout->addSpacing(20);
    mainlayout->addItem(westlayouthor);
    mainlayout->addSpacing(20);
    mainlayout->addItem(toplayouthor);
    mainlayout->addSpacing(20);
    mainlayout->addWidget(floordimensiongroup);
    mainlayout->addWidget(brokenrockgroup);
    setLayout(mainlayout);
}

Dialog::~Dialog()
{
}

void Dialog::createbrokenrockproperties(QHBoxLayout* layouthor,brockenrockproperties* brokenrockprop)
{
    layouthor->addWidget(brokenrockprop->beginingheightlabel);
    layouthor->addSpacing(10);
    layouthor->addWidget(brokenrockprop->beginingheightspin);
    layouthor->addSpacing(5);
    layouthor->addWidget(brokenrockprop->peakheightlabel);
    layouthor->addSpacing(10);
    layouthor->addWidget(brokenrockprop->peakheightspin);
    layouthor->addSpacing(5);
    layouthor->addWidget(brokenrockprop->peakAtlabel);
    layouthor->addSpacing(10);
    layouthor->addWidget(brokenrockprop->peakAtspin);
    layouthor->addSpacing(5);
    layouthor->addWidget(brokenrockprop->endheightlabel);
    layouthor->addSpacing(10);
    layouthor->addWidget(brokenrockprop->endheightspin);
    layouthor->addSpacing(5);
    layouthor->addWidget(brokenrockprop->widthlabel);
    layouthor->addSpacing(10);
    layouthor->addWidget(brokenrockprop->widthspin);
    layouthor->addSpacing(5);
}

void Dialog::NorthComboCurrentIndexChanged(int x)
{
    if(northcombo->itemText(x) == "Broken Rock")
    {
        hidebrokenrockproperties(northbrockenrock,true);
    }
    else
    {
        hidebrokenrockproperties(northbrockenrock,false);
    }
}
void Dialog::SouthComboCurrentIndexChanged(int x)
{
    if(southcombo->itemText(x) == "Broken Rock")
    {
        hidebrokenrockproperties(southbrockenrock,true);
    }
    else
    {
        hidebrokenrockproperties(southbrockenrock,false);
    }
}
void Dialog::EastComboCurrentIndexChanged(int x)
{
    if(eastcombo->itemText(x) == "Broken Rock")
    {
        hidebrokenrockproperties(eastbrockenrock,true);
    }
    else
    {
        hidebrokenrockproperties(eastbrockenrock,false);
    }
}
void Dialog::WestComboCurrentIndexChanged(int x)
{
    if(eastcombo->itemText(x) == "Broken Rock")
    {
        hidebrokenrockproperties(westbrockenrock,true);
    }
    else
    {
        hidebrokenrockproperties(westbrockenrock,false);
    }
}
void Dialog::hidebrokenrockproperties(brockenrockproperties* rockproperties, bool hide)
{
    rockproperties->beginingheightlabel->setVisible(hide);
    rockproperties->beginingheightspin->setVisible(hide);
    rockproperties->endheightlabel->setVisible(hide);
    rockproperties->endheightspin->setVisible(hide);
    rockproperties->peakAtlabel->setVisible(hide);
    rockproperties->peakAtspin->setVisible(hide);
    rockproperties->peakheightlabel->setVisible(hide);
    rockproperties->peakheightspin->setVisible(hide);
    rockproperties->widthlabel->setVisible(hide);
    rockproperties->widthspin->setVisible(hide);
}
