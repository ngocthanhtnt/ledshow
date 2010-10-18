#include "flashProperty.h"
/*
//flash属性窗
class CflashProperty:public QWidget
{
    Q_OBJECT
private:
    QLabel *flashSourceLabel; //flash源标志
    QLineEdit *flashSourceEdit; //flash源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *frameNumLabel; //帧数标志
    QLineEdit *frameNumEdit; //帧数编辑
    QLabel *runSpeedLabel; //运行速度标志
    QLineEdit *runSpeedEdit; //运行速度编辑
    QLabel *speedUnitLabel; //速度单位

    QLabel *totalFrameNumLabel; //总帧数


public:
    CflashProperty(QWidget *parent=0);
    ~CflashProperty();
};
*/
//flash属性编辑
CflashProperty::CflashProperty(QWidget *parent):QWidget(parent)
{

    QGridLayout *gridLayout = new QGridLayout(this);
    groupBox = new QGroupBox(this);

   flashSourceLabel = new QLabel(tr("提取源"), this);
   flashSourceEdit = new QLineEdit(this);
   openButton = new QPushButton(tr("打开"), this);

   frameNumLabel = new QLabel(tr("帧数"), this);
   frameNumEdit = new QLineEdit(this);
   runSpeedLabel = new QLabel(tr("运行速度"), this);
   speedUnitLabel = new QLabel(tr("微秒"), this);

   totalFrameNumLabel = new QLabel(tr("总帧数"), this);

   gridLayout->addWidget(flashSourceLabel, 0, 0);
   gridLayout->addWidget(flashSourceEdit, 0, 1);
   gridLayout->addWidget(openButton, 0, 2);
   gridLayout->addWidget(frameNumLabel, 1, 0);
   gridLayout->addWidget(frameNumEdit, 1, 1);
   gridLayout->addWidget(runSpeedLabel, 1, 2);
   gridLayout->addWidget(speedUnitLabel, 1, 3);
   gridLayout->addWidget(totalFrameNumLabel, 3, 0);
   groupBox->setLayout(gridLayout);
}

CflashProperty::~CflashProperty()
{

}

void CflashProperty::getSettingsFromWidget(QString str)
{

}

void CflashProperty::setSettingsToWidget(QString str)
{

}


