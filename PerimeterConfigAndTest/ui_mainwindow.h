/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <generic_table.h>
#include "motor_pos_table.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_chooseDevice;
    QAction *action_saveConfig;
    QAction *action_readConfigFromLocal;
    QAction *action_updateConfigToLower;
    QAction *action_downloadConfig;
    QAction *action_readLocalData;
    QAction *action_saveLocalData;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget_5;
    QWidget *tab_13;
    QHBoxLayout *horizontalLayout_21;
    QComboBox *comboBox_lightSelect_1;
    QSpacerItem *horizontalSpacer_38;
    QLabel *label_da_RGB_2;
    QSpinBox *spinBox_centerLightAndOtherDA;
    QCheckBox *checkBox_centerLightAndOtherDASync;
    QPushButton *pushButton_light1;
    QWidget *tab_14;
    QHBoxLayout *horizontalLayout_24;
    QComboBox *comboBox_lightSelect_2;
    QComboBox *comboBox_lampIndex;
    QSpacerItem *horizontalSpacer_40;
    QLabel *label_da_RGB_3;
    QSpinBox *spinBox_bigAndSmallDiamondDA;
    QCheckBox *checkBox_spinBox_bigAndSmallDiamondDASync;
    QPushButton *pushButton_light2;
    QWidget *tab_15;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_da_RGB_4;
    QSpinBox *spinBox_lightR;
    QSpinBox *spinBox_lightG;
    QSpinBox *spinBox_lightB;
    QSpacerItem *horizontalSpacer_43;
    QCheckBox *checkBox_whiteLightDASync;
    QPushButton *pushButton_light3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_5;
    QCheckBox *checkBox_testChinHoz;
    QCheckBox *checkBox_testChinVert;
    QSpinBox *spinBox_hozChinMotorPos;
    QSpinBox *spinBox_vertChinMotorPos;
    QSpinBox *spinBox_hosChinMotorSpeed;
    QSpinBox *spinBox_vertChinMotorSpeed;
    QSplitter *splitter_15;
    QPushButton *pushButton_relativeMoveChin;
    QPushButton *pushButton_absoluteMoveChin;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox_testColor;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *checkBox_testFocus;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_12;
    QCheckBox *checkBox_testSpot;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QCheckBox *checkBox_testX;
    QCheckBox *checkBox_testY;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_14;
    QSpinBox *spinBox_XMotorPos;
    QSpinBox *spinBox_YMotorPos;
    QSpinBox *spinBox_focalMotorPos;
    QSpinBox *spinBox_colorMotorPos;
    QSpinBox *spinBox_spotMotorPos;
    QSpinBox *spinBox_XMotorSpeed;
    QSpinBox *spinBox_YMotorSpeed;
    QSpinBox *spinBox_focalMotorSpeed;
    QSpinBox *spinBox_colorMotorSpeed;
    QSpinBox *spinBox_spotMotorSpeed;
    QSplitter *splitter_14;
    QPushButton *pushButton_relativeMove5Motors;
    QPushButton *pushButton_absoluteMove5Motors;
    QGroupBox *groupBox_resetMotor;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_xMotor;
    QRadioButton *radioButton_focusMotor;
    QRadioButton *radioButton_spotMotor;
    QRadioButton *radioButton_chinHozMotor;
    QRadioButton *radioButton_yMotor;
    QRadioButton *radioButton_colorMotor;
    QRadioButton *radioButton_shutterMotor;
    QRadioButton *radioButton_chinVertMotor;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_32;
    QSpinBox *spinBox_resetSpeed;
    QPushButton *pushButton_resetCheckedMotors;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_8;
    QLabel *label_xMotorRange;
    QLabel *label_focalMotorRange;
    QLabel *label_chinVertMotorRange;
    QLabel *label_colorMotorRange;
    QLabel *label_58;
    QLabel *label_yMotorRange;
    QLabel *label_spotMotorRange;
    QLabel *label_52;
    QLabel *label_shutterMotorRange;
    QLabel *label_62;
    QLabel *label_65;
    QLabel *label_68;
    QLabel *label_54;
    QLabel *label_56;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_chinHozMotorRange;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_64;
    QSpacerItem *horizontalSpacer_24;
    QTabWidget *tabWidget_3;
    QWidget *tab_8;
    QGridLayout *gridLayout_7;
    QLabel *label_87;
    QLabel *label_posX;
    QLabel *label_85;
    QLabel *label_posFocus;
    QLabel *label_90;
    QLabel *label_posSpot;
    QLabel *label_88;
    QLabel *label_posChinHoz;
    QLabel *label_84;
    QLabel *label_posY;
    QLabel *label_89;
    QLabel *label_posColor;
    QLabel *label_86;
    QLabel *label_posShutter;
    QLabel *label_75;
    QLabel *label_posChinVert;
    QWidget *tab_7;
    QGridLayout *gridLayout_2;
    QLabel *label_47;
    QLabel *label_stateX;
    QLabel *label_48;
    QLabel *label_stateFocus;
    QLabel *label_51;
    QLabel *label_stateSpot;
    QLabel *label_53;
    QLabel *label_stateChinHoz;
    QLabel *label_57;
    QLabel *label_stateY;
    QLabel *label_61;
    QLabel *label_stateColor;
    QLabel *label_55;
    QLabel *label_stateShutter;
    QLabel *label_59;
    QLabel *label_stateChinVert;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_6;
    QLabel *label_VID;
    QLabel *label_36;
    QLabel *label_castLightDA;
    QLabel *label_34;
    QLabel *label_connectionStatus;
    QLabel *label_eyeglassStatus;
    QLabel *label_60;
    QLabel *label_69;
    QLabel *label_devVer;
    QLabel *label_environmentDA;
    QLabel *label_67;
    QLabel *label_answerState;
    QLabel *label_33;
    QLabel *label_66;
    QLabel *label_devType;
    QLabel *label_PID;
    QLabel *label_63;
    QLabel *label_50;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_57;
    QSpacerItem *horizontalSpacer_81;
    QOpenGLWidget *openGLWidget;
    QSpacerItem *horizontalSpacer_82;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_chinMoveLeft;
    QPushButton *pushButton_chinMoveUp;
    QPushButton *pushButton_chinMoveDown;
    QPushButton *pushButton_chinMoveRight;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label_38;
    QLabel *label_videoSize;
    QLabel *label_20;
    QSpinBox *spinBox_speedChinMove;
    QPushButton *pushButton_cameraSwitch;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QComboBox *comboBox_color;
    QLabel *label_18;
    QSpinBox *spinBox_colorSlot;
    QLabel *label_71;
    QSpinBox *spinBox_colorMotorPos_2;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBox_colorConfigSync;
    QPushButton *pushButton_colorTest;
    QGroupBox *groupBox_s;
    QHBoxLayout *horizontalLayout;
    QLabel *label_16;
    QComboBox *comboBox_spotSize;
    QLabel *label_19;
    QSpinBox *spinBox_spotSlot;
    QLabel *label_44;
    QSpinBox *spinBox_spotMotorPos_2;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBox_spotConfigSync;
    QPushButton *pushButton_spotTest;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_46;
    QSpinBox *spinBox_DbSetting;
    QLabel *label_82;
    QSpinBox *spinBox_DbColorPos;
    QLabel *label_83;
    QSpinBox *spinBox_DbSpotPos;
    QCheckBox *checkBox_DbConfigSync;
    QPushButton *pushButton_dbTest;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_staticCastPos;
    QGridLayout *gridLayout_11;
    QSpinBox *spinBox_YMotorPos_2;
    QPushButton *pushButton_staticCastTest;
    QLineEdit *lineEdit_coordY;
    QLabel *label_72;
    QSpinBox *spinBox_XMotorPos_2;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_23;
    QLineEdit *lineEdit_coordX;
    QCheckBox *checkBox_calcFocalDist;
    QLabel *label_73;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_moveCastPos;
    QGridLayout *gridLayout_3;
    QLabel *label_41;
    QSpacerItem *horizontalSpacer_44;
    QLabel *label_42;
    QLineEdit *lineEdit_endCoordX;
    QLineEdit *lineEdit_beginCoordX;
    QLabel *label_40;
    QLineEdit *lineEdit_beginCoordY;
    QLabel *label_43;
    QLineEdit *lineEdit_endCoordY;
    QSpacerItem *horizontalSpacer_20;
    QGroupBox *groupBox_focalTest;
    QGridLayout *gridLayout_13;
    QSpinBox *spinBox_focalDist;
    QSpinBox *spinBox_focalMotorPos_2;
    QLabel *label_37;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *pushButton_focalTest;
    QLabel *label_39;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_26;
    QSpinBox *spinBox_shutterOpenDuration;
    QLabel *label_27;
    QSpinBox *spinBox_shutterOpenPos;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkBox_shutterConfigSync;
    QPushButton *pushButton_shuterTest;
    QGroupBox *groupBox_24;
    QGridLayout *gridLayout_10;
    QLabel *label_77;
    QSpinBox *spinBox_YMotorSpeed_2;
    QSpinBox *spinBox_XMotorSpeed_2;
    QSpinBox *spinBox_colorMotorSpeed_2;
    QLabel *label_78;
    QLabel *label_80;
    QSpinBox *spinBox_focalMotorSpeed_2;
    QLabel *label_79;
    QLabel *label_81;
    QSpinBox *spinBox_spotMotorSpeed_2;
    QSpacerItem *horizontalSpacer_41;
    QSpacerItem *horizontalSpacer_42;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_45;
    QComboBox *comboBox_testFucntion;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_testStart;
    QPushButton *pushButton_readCache;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_21;
    QTextBrowser *textBrowser_infoText;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_27;
    QCheckBox *checkBox_IO;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_10;
    QTextBrowser *textBrowser_refreshInfoText;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_36;
    QCheckBox *checkBox_startRefreshInfo;
    QCheckBox *checkBox_RefreshIO;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_23;
    QGroupBox *groupBox_83;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_19;
    QVBoxLayout *verticalLayout_57;
    QHBoxLayout *horizontalLayout_58;
    QLabel *label_21;
    QLineEdit *lineEdit_deviceSerialNo;
    QSpacerItem *horizontalSpacer_21;
    QGroupBox *groupBox_84;
    QVBoxLayout *verticalLayout_46;
    QHBoxLayout *horizontalLayout_59;
    QLabel *label_24;
    QLineEdit *lineEdit_centralLightDA;
    QSpacerItem *horizontalSpacer_84;
    QHBoxLayout *horizontalLayout_60;
    QLabel *label_25;
    QLineEdit *lineEdit_bigDiamond1DA;
    QLineEdit *lineEdit_bigDiamond2DA;
    QLineEdit *lineEdit_bigDiamond3DA;
    QLineEdit *lineEdit_bigDiamond4DA;
    QSpacerItem *horizontalSpacer_85;
    QHBoxLayout *horizontalLayout_61;
    QLabel *label_29;
    QLineEdit *lineEdit_smallDiamond1DA;
    QLineEdit *lineEdit_smallDiamond2DA;
    QLineEdit *lineEdit_smallDiamond3DA;
    QLineEdit *lineEdit_smallDiamond4DA;
    QSpacerItem *horizontalSpacer_86;
    QVBoxLayout *verticalLayout_59;
    QGroupBox *groupBox_85;
    QHBoxLayout *horizontalLayout_62;
    QLabel *label_30;
    QLineEdit *lineEdit_yellowBackGroundLampDa;
    QLabel *label_31;
    QLineEdit *lineEdit_whiteBackGroundLampR;
    QLineEdit *lineEdit_whiteBackGroundLampG;
    QLineEdit *lineEdit_whiteBackGroundLampB;
    QSpacerItem *horizontalSpacer_83;
    QGroupBox *groupBox_86;
    QGridLayout *gridLayout_36;
    QSpacerItem *horizontalSpacer_29;
    QLineEdit *lineEdit_centerInfraredLampDA;
    QLabel *label_363;
    QLabel *label_364;
    QLineEdit *lineEdit_borderLampDA;
    QLineEdit *lineEdit_eyeGlassLampDa;
    QLabel *label_362;
    QGroupBox *groupBox_81;
    QHBoxLayout *horizontalLayout_64;
    QLabel *label_368;
    QLineEdit *lineEdit_whiteLampEnvLightAlarm;
    QLabel *label_369;
    QLineEdit *lineEdit_yellowLampEnvLightAlarm;
    QSpacerItem *horizontalSpacer_119;
    QGroupBox *groupBox_82;
    QHBoxLayout *horizontalLayout_63;
    QLabel *label_367;
    QLineEdit *lineEdit_whiteLampPupilGray;
    QLabel *label_366;
    QLineEdit *lineEdit_yellowLampPupilGray;
    QSpacerItem *horizontalSpacer_120;
    QVBoxLayout *verticalLayout_58;
    QGroupBox *groupBox_87;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_65;
    QLabel *label_133;
    QLineEdit *lineEdit_focusUnite;
    QLabel *label_132;
    QLineEdit *lineEdit_shutterOpen;
    QSpacerItem *horizontalSpacer_28;
    QSpacerItem *horizontalSpacer_92;
    QGridLayout *gridLayout_37;
    QLineEdit *lineEdit_centerX;
    QLineEdit *lineEdit_centerY;
    QLabel *label_358;
    QLabel *label_354;
    QLabel *label_355;
    QLineEdit *lineEdit_secondaryCenterY;
    QSpacerItem *horizontalSpacer_95;
    QSpacerItem *horizontalSpacer_96;
    QLineEdit *lineEdit_secondaryCenterX;
    QLabel *label_359;
    QSpacerItem *horizontalSpacer_34;
    QSpacerItem *horizontalSpacer_35;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_9;
    QLabel *label_360;
    QLabel *label_357;
    QLineEdit *lineEdit_lightCorrectionY;
    QLineEdit *lineEdit_lightCorrectionFocus;
    QLabel *label_131;
    QLineEdit *lineEdit_lightCorrectionX;
    QLineEdit *lineEdit_castLightDA;
    QLabel *label_356;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_37;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_18;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_16;
    GenericTable *tableView_XYDistTable;
    GenericTable *tableView_focalPosTable;
    QHBoxLayout *horizontalLayout_18;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_11;
    GenericTable *tableView_colorSlotPos;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_13;
    GenericTable *tableView_spotSlotPos;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_33;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_18;
    GenericTable *tableView_speedStepTimeTable;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_31;
    QLabel *label_70;
    QLineEdit *lineEdit_stepLength;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_22;
    QVBoxLayout *verticalLayout_24;
    GenericTable *tableView_diamondFocalPosTable;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_76;
    QLineEdit *lineEdit_diamondCenterX;
    QLabel *label_74;
    QLineEdit *lineEdit_diamondCenterY;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_30;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_14;
    GenericTable *tableView_dbColorSpotPosTable;
    QSpacerItem *horizontalSpacer_32;
    QGroupBox *groupBox_19;
    QVBoxLayout *verticalLayout_20;
    GenericTable *tableView_dbAngleDampingTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_16;
    MotorPosTable *tableView_mainMotorPosTable;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_11;
    MotorPosTable *tableView_secondaryPosTable;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 843);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        action_chooseDevice = new QAction(MainWindow);
        action_chooseDevice->setObjectName(QStringLiteral("action_chooseDevice"));
        action_saveConfig = new QAction(MainWindow);
        action_saveConfig->setObjectName(QStringLiteral("action_saveConfig"));
        action_readConfigFromLocal = new QAction(MainWindow);
        action_readConfigFromLocal->setObjectName(QStringLiteral("action_readConfigFromLocal"));
        action_updateConfigToLower = new QAction(MainWindow);
        action_updateConfigToLower->setObjectName(QStringLiteral("action_updateConfigToLower"));
        action_downloadConfig = new QAction(MainWindow);
        action_downloadConfig->setObjectName(QStringLiteral("action_downloadConfig"));
        action_readLocalData = new QAction(MainWindow);
        action_readLocalData->setObjectName(QStringLiteral("action_readLocalData"));
        action_saveLocalData = new QAction(MainWindow);
        action_saveLocalData->setObjectName(QStringLiteral("action_saveLocalData"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_12 = new QHBoxLayout(tab);
        horizontalLayout_12->setSpacing(4);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(380, 0));
        groupBox->setMaximumSize(QSize(380, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        tabWidget_5 = new QTabWidget(groupBox);
        tabWidget_5->setObjectName(QStringLiteral("tabWidget_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_5->sizePolicy().hasHeightForWidth());
        tabWidget_5->setSizePolicy(sizePolicy1);
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        horizontalLayout_21 = new QHBoxLayout(tab_13);
        horizontalLayout_21->setSpacing(3);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(3, 3, 3, 3);
        comboBox_lightSelect_1 = new QComboBox(tab_13);
        comboBox_lightSelect_1->setObjectName(QStringLiteral("comboBox_lightSelect_1"));
        comboBox_lightSelect_1->setMinimumSize(QSize(90, 0));

        horizontalLayout_21->addWidget(comboBox_lightSelect_1);

        horizontalSpacer_38 = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_38);

        label_da_RGB_2 = new QLabel(tab_13);
        label_da_RGB_2->setObjectName(QStringLiteral("label_da_RGB_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_da_RGB_2->sizePolicy().hasHeightForWidth());
        label_da_RGB_2->setSizePolicy(sizePolicy2);
        label_da_RGB_2->setMinimumSize(QSize(25, 0));
        label_da_RGB_2->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_21->addWidget(label_da_RGB_2);

        spinBox_centerLightAndOtherDA = new QSpinBox(tab_13);
        spinBox_centerLightAndOtherDA->setObjectName(QStringLiteral("spinBox_centerLightAndOtherDA"));
        spinBox_centerLightAndOtherDA->setMinimumSize(QSize(40, 0));
        spinBox_centerLightAndOtherDA->setMaximumSize(QSize(50, 16777215));
        spinBox_centerLightAndOtherDA->setMinimum(0);
        spinBox_centerLightAndOtherDA->setMaximum(65535);
        spinBox_centerLightAndOtherDA->setValue(0);

        horizontalLayout_21->addWidget(spinBox_centerLightAndOtherDA);

        checkBox_centerLightAndOtherDASync = new QCheckBox(tab_13);
        checkBox_centerLightAndOtherDASync->setObjectName(QStringLiteral("checkBox_centerLightAndOtherDASync"));

        horizontalLayout_21->addWidget(checkBox_centerLightAndOtherDASync);

        pushButton_light1 = new QPushButton(tab_13);
        pushButton_light1->setObjectName(QStringLiteral("pushButton_light1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_light1->sizePolicy().hasHeightForWidth());
        pushButton_light1->setSizePolicy(sizePolicy3);
        pushButton_light1->setMinimumSize(QSize(40, 0));
        pushButton_light1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_21->addWidget(pushButton_light1);

        tabWidget_5->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        horizontalLayout_24 = new QHBoxLayout(tab_14);
        horizontalLayout_24->setSpacing(3);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(3, 3, 3, 3);
        comboBox_lightSelect_2 = new QComboBox(tab_14);
        comboBox_lightSelect_2->setObjectName(QStringLiteral("comboBox_lightSelect_2"));
        comboBox_lightSelect_2->setMinimumSize(QSize(90, 0));

        horizontalLayout_24->addWidget(comboBox_lightSelect_2);

        comboBox_lampIndex = new QComboBox(tab_14);
        comboBox_lampIndex->setObjectName(QStringLiteral("comboBox_lampIndex"));
        comboBox_lampIndex->setEnabled(true);
        comboBox_lampIndex->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_24->addWidget(comboBox_lampIndex);

        horizontalSpacer_40 = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_40);

        label_da_RGB_3 = new QLabel(tab_14);
        label_da_RGB_3->setObjectName(QStringLiteral("label_da_RGB_3"));
        sizePolicy2.setHeightForWidth(label_da_RGB_3->sizePolicy().hasHeightForWidth());
        label_da_RGB_3->setSizePolicy(sizePolicy2);
        label_da_RGB_3->setMinimumSize(QSize(25, 0));
        label_da_RGB_3->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_24->addWidget(label_da_RGB_3);

        spinBox_bigAndSmallDiamondDA = new QSpinBox(tab_14);
        spinBox_bigAndSmallDiamondDA->setObjectName(QStringLiteral("spinBox_bigAndSmallDiamondDA"));
        spinBox_bigAndSmallDiamondDA->setMinimumSize(QSize(40, 0));
        spinBox_bigAndSmallDiamondDA->setMaximumSize(QSize(50, 16777215));
        spinBox_bigAndSmallDiamondDA->setMinimum(0);
        spinBox_bigAndSmallDiamondDA->setMaximum(65535);
        spinBox_bigAndSmallDiamondDA->setValue(0);

        horizontalLayout_24->addWidget(spinBox_bigAndSmallDiamondDA);

        checkBox_spinBox_bigAndSmallDiamondDASync = new QCheckBox(tab_14);
        checkBox_spinBox_bigAndSmallDiamondDASync->setObjectName(QStringLiteral("checkBox_spinBox_bigAndSmallDiamondDASync"));

        horizontalLayout_24->addWidget(checkBox_spinBox_bigAndSmallDiamondDASync);

        pushButton_light2 = new QPushButton(tab_14);
        pushButton_light2->setObjectName(QStringLiteral("pushButton_light2"));
        sizePolicy3.setHeightForWidth(pushButton_light2->sizePolicy().hasHeightForWidth());
        pushButton_light2->setSizePolicy(sizePolicy3);
        pushButton_light2->setMinimumSize(QSize(40, 0));
        pushButton_light2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_24->addWidget(pushButton_light2);

        tabWidget_5->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        horizontalLayout_25 = new QHBoxLayout(tab_15);
        horizontalLayout_25->setSpacing(3);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(3, 3, 3, 3);
        label_da_RGB_4 = new QLabel(tab_15);
        label_da_RGB_4->setObjectName(QStringLiteral("label_da_RGB_4"));
        sizePolicy2.setHeightForWidth(label_da_RGB_4->sizePolicy().hasHeightForWidth());
        label_da_RGB_4->setSizePolicy(sizePolicy2);
        label_da_RGB_4->setMinimumSize(QSize(25, 0));
        label_da_RGB_4->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_25->addWidget(label_da_RGB_4);

        spinBox_lightR = new QSpinBox(tab_15);
        spinBox_lightR->setObjectName(QStringLiteral("spinBox_lightR"));
        spinBox_lightR->setMinimumSize(QSize(40, 0));
        spinBox_lightR->setMaximumSize(QSize(50, 16777215));
        spinBox_lightR->setMinimum(0);
        spinBox_lightR->setMaximum(65535);
        spinBox_lightR->setValue(0);

        horizontalLayout_25->addWidget(spinBox_lightR);

        spinBox_lightG = new QSpinBox(tab_15);
        spinBox_lightG->setObjectName(QStringLiteral("spinBox_lightG"));
        spinBox_lightG->setEnabled(true);
        spinBox_lightG->setMinimumSize(QSize(40, 0));
        spinBox_lightG->setMaximumSize(QSize(50, 16777215));
        spinBox_lightG->setMinimum(0);
        spinBox_lightG->setMaximum(65535);
        spinBox_lightG->setValue(0);

        horizontalLayout_25->addWidget(spinBox_lightG);

        spinBox_lightB = new QSpinBox(tab_15);
        spinBox_lightB->setObjectName(QStringLiteral("spinBox_lightB"));
        spinBox_lightB->setEnabled(true);
        spinBox_lightB->setMinimumSize(QSize(40, 0));
        spinBox_lightB->setMaximumSize(QSize(50, 16777215));
        spinBox_lightB->setMinimum(0);
        spinBox_lightB->setMaximum(65535);
        spinBox_lightB->setValue(0);

        horizontalLayout_25->addWidget(spinBox_lightB);

        horizontalSpacer_43 = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_43);

        checkBox_whiteLightDASync = new QCheckBox(tab_15);
        checkBox_whiteLightDASync->setObjectName(QStringLiteral("checkBox_whiteLightDASync"));

        horizontalLayout_25->addWidget(checkBox_whiteLightDASync);

        pushButton_light3 = new QPushButton(tab_15);
        pushButton_light3->setObjectName(QStringLiteral("pushButton_light3"));
        sizePolicy3.setHeightForWidth(pushButton_light3->sizePolicy().hasHeightForWidth());
        pushButton_light3->setSizePolicy(sizePolicy3);
        pushButton_light3->setMinimumSize(QSize(40, 0));
        pushButton_light3->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_25->addWidget(pushButton_light3);

        tabWidget_5->addTab(tab_15, QString());

        verticalLayout_3->addWidget(tabWidget_5);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        groupBox_3->setMinimumSize(QSize(0, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 3, 3, 3);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 3, 5, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 5, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_4->addWidget(label_2, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 3, 0, 1, 1);

        checkBox_testChinHoz = new QCheckBox(groupBox_3);
        checkBox_testChinHoz->setObjectName(QStringLiteral("checkBox_testChinHoz"));

        gridLayout_4->addWidget(checkBox_testChinHoz, 1, 4, 1, 1);

        checkBox_testChinVert = new QCheckBox(groupBox_3);
        checkBox_testChinVert->setObjectName(QStringLiteral("checkBox_testChinVert"));

        gridLayout_4->addWidget(checkBox_testChinVert, 3, 4, 1, 1);

        spinBox_hozChinMotorPos = new QSpinBox(groupBox_3);
        spinBox_hozChinMotorPos->setObjectName(QStringLiteral("spinBox_hozChinMotorPos"));
        spinBox_hozChinMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_hozChinMotorPos->setMaximumSize(QSize(16777215, 16777215));
        spinBox_hozChinMotorPos->setMinimum(-200000);
        spinBox_hozChinMotorPos->setMaximum(200000);
        spinBox_hozChinMotorPos->setSingleStep(1);

        gridLayout_4->addWidget(spinBox_hozChinMotorPos, 1, 1, 1, 1);

        spinBox_vertChinMotorPos = new QSpinBox(groupBox_3);
        spinBox_vertChinMotorPos->setObjectName(QStringLiteral("spinBox_vertChinMotorPos"));
        spinBox_vertChinMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_vertChinMotorPos->setMinimum(-200000);
        spinBox_vertChinMotorPos->setMaximum(200000);

        gridLayout_4->addWidget(spinBox_vertChinMotorPos, 3, 1, 1, 1);

        spinBox_hosChinMotorSpeed = new QSpinBox(groupBox_3);
        spinBox_hosChinMotorSpeed->setObjectName(QStringLiteral("spinBox_hosChinMotorSpeed"));
        spinBox_hosChinMotorSpeed->setMinimum(1);
        spinBox_hosChinMotorSpeed->setMaximum(7);

        gridLayout_4->addWidget(spinBox_hosChinMotorSpeed, 1, 3, 1, 1);

        spinBox_vertChinMotorSpeed = new QSpinBox(groupBox_3);
        spinBox_vertChinMotorSpeed->setObjectName(QStringLiteral("spinBox_vertChinMotorSpeed"));
        spinBox_vertChinMotorSpeed->setMinimum(1);
        spinBox_vertChinMotorSpeed->setMaximum(7);

        gridLayout_4->addWidget(spinBox_vertChinMotorSpeed, 3, 3, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);

        splitter_15 = new QSplitter(groupBox_3);
        splitter_15->setObjectName(QStringLiteral("splitter_15"));
        splitter_15->setOrientation(Qt::Horizontal);
        pushButton_relativeMoveChin = new QPushButton(splitter_15);
        pushButton_relativeMoveChin->setObjectName(QStringLiteral("pushButton_relativeMoveChin"));
        splitter_15->addWidget(pushButton_relativeMoveChin);
        pushButton_absoluteMoveChin = new QPushButton(splitter_15);
        pushButton_absoluteMoveChin->setObjectName(QStringLiteral("pushButton_absoluteMoveChin"));
        splitter_15->addWidget(pushButton_absoluteMoveChin);

        verticalLayout_6->addWidget(splitter_15);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        checkBox_testColor = new QCheckBox(groupBox_2);
        checkBox_testColor->setObjectName(QStringLiteral("checkBox_testColor"));

        gridLayout_5->addWidget(checkBox_testColor, 3, 4, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_16, 4, 5, 1, 1);

        checkBox_testFocus = new QCheckBox(groupBox_2);
        checkBox_testFocus->setObjectName(QStringLiteral("checkBox_testFocus"));

        gridLayout_5->addWidget(checkBox_testFocus, 2, 4, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_13, 1, 5, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 0, 5, 1, 1);

        checkBox_testSpot = new QCheckBox(groupBox_2);
        checkBox_testSpot->setObjectName(QStringLiteral("checkBox_testSpot"));

        gridLayout_5->addWidget(checkBox_testSpot, 4, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_14, 2, 5, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_15, 3, 5, 1, 1);

        checkBox_testX = new QCheckBox(groupBox_2);
        checkBox_testX->setObjectName(QStringLiteral("checkBox_testX"));

        gridLayout_5->addWidget(checkBox_testX, 0, 4, 1, 1);

        checkBox_testY = new QCheckBox(groupBox_2);
        checkBox_testY->setObjectName(QStringLiteral("checkBox_testY"));

        gridLayout_5->addWidget(checkBox_testY, 1, 4, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(label_4, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(label_8, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(label_10, 2, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 4, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(label_12, 3, 2, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(label_14, 4, 2, 1, 1);

        spinBox_XMotorPos = new QSpinBox(groupBox_2);
        spinBox_XMotorPos->setObjectName(QStringLiteral("spinBox_XMotorPos"));
        spinBox_XMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_XMotorPos->setMinimum(-200000);
        spinBox_XMotorPos->setMaximum(200000);

        gridLayout_5->addWidget(spinBox_XMotorPos, 0, 1, 1, 1);

        spinBox_YMotorPos = new QSpinBox(groupBox_2);
        spinBox_YMotorPos->setObjectName(QStringLiteral("spinBox_YMotorPos"));
        spinBox_YMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_YMotorPos->setMinimum(-200000);
        spinBox_YMotorPos->setMaximum(200000);

        gridLayout_5->addWidget(spinBox_YMotorPos, 1, 1, 1, 1);

        spinBox_focalMotorPos = new QSpinBox(groupBox_2);
        spinBox_focalMotorPos->setObjectName(QStringLiteral("spinBox_focalMotorPos"));
        spinBox_focalMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_focalMotorPos->setMinimum(-200000);
        spinBox_focalMotorPos->setMaximum(200000);

        gridLayout_5->addWidget(spinBox_focalMotorPos, 2, 1, 1, 1);

        spinBox_colorMotorPos = new QSpinBox(groupBox_2);
        spinBox_colorMotorPos->setObjectName(QStringLiteral("spinBox_colorMotorPos"));
        spinBox_colorMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_colorMotorPos->setMinimum(-200000);
        spinBox_colorMotorPos->setMaximum(200000);

        gridLayout_5->addWidget(spinBox_colorMotorPos, 3, 1, 1, 1);

        spinBox_spotMotorPos = new QSpinBox(groupBox_2);
        spinBox_spotMotorPos->setObjectName(QStringLiteral("spinBox_spotMotorPos"));
        spinBox_spotMotorPos->setMinimumSize(QSize(60, 0));
        spinBox_spotMotorPos->setMinimum(-200000);
        spinBox_spotMotorPos->setMaximum(200000);

        gridLayout_5->addWidget(spinBox_spotMotorPos, 4, 1, 1, 1);

        spinBox_XMotorSpeed = new QSpinBox(groupBox_2);
        spinBox_XMotorSpeed->setObjectName(QStringLiteral("spinBox_XMotorSpeed"));
        spinBox_XMotorSpeed->setMinimum(1);
        spinBox_XMotorSpeed->setMaximum(7);

        gridLayout_5->addWidget(spinBox_XMotorSpeed, 0, 3, 1, 1);

        spinBox_YMotorSpeed = new QSpinBox(groupBox_2);
        spinBox_YMotorSpeed->setObjectName(QStringLiteral("spinBox_YMotorSpeed"));
        spinBox_YMotorSpeed->setMinimum(1);
        spinBox_YMotorSpeed->setMaximum(7);

        gridLayout_5->addWidget(spinBox_YMotorSpeed, 1, 3, 1, 1);

        spinBox_focalMotorSpeed = new QSpinBox(groupBox_2);
        spinBox_focalMotorSpeed->setObjectName(QStringLiteral("spinBox_focalMotorSpeed"));
        spinBox_focalMotorSpeed->setMinimum(1);
        spinBox_focalMotorSpeed->setMaximum(7);

        gridLayout_5->addWidget(spinBox_focalMotorSpeed, 2, 3, 1, 1);

        spinBox_colorMotorSpeed = new QSpinBox(groupBox_2);
        spinBox_colorMotorSpeed->setObjectName(QStringLiteral("spinBox_colorMotorSpeed"));
        spinBox_colorMotorSpeed->setMinimum(1);
        spinBox_colorMotorSpeed->setMaximum(7);

        gridLayout_5->addWidget(spinBox_colorMotorSpeed, 3, 3, 1, 1);

        spinBox_spotMotorSpeed = new QSpinBox(groupBox_2);
        spinBox_spotMotorSpeed->setObjectName(QStringLiteral("spinBox_spotMotorSpeed"));
        spinBox_spotMotorSpeed->setMinimum(1);
        spinBox_spotMotorSpeed->setMaximum(7);

        gridLayout_5->addWidget(spinBox_spotMotorSpeed, 4, 3, 1, 1);


        verticalLayout_5->addLayout(gridLayout_5);

        splitter_14 = new QSplitter(groupBox_2);
        splitter_14->setObjectName(QStringLiteral("splitter_14"));
        splitter_14->setOrientation(Qt::Horizontal);
        pushButton_relativeMove5Motors = new QPushButton(splitter_14);
        pushButton_relativeMove5Motors->setObjectName(QStringLiteral("pushButton_relativeMove5Motors"));
        splitter_14->addWidget(pushButton_relativeMove5Motors);
        pushButton_absoluteMove5Motors = new QPushButton(splitter_14);
        pushButton_absoluteMove5Motors->setObjectName(QStringLiteral("pushButton_absoluteMove5Motors"));
        splitter_14->addWidget(pushButton_absoluteMove5Motors);

        verticalLayout_5->addWidget(splitter_14);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_resetMotor = new QGroupBox(groupBox);
        groupBox_resetMotor->setObjectName(QStringLiteral("groupBox_resetMotor"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_resetMotor->sizePolicy().hasHeightForWidth());
        groupBox_resetMotor->setSizePolicy(sizePolicy4);
        groupBox_resetMotor->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_15 = new QVBoxLayout(groupBox_resetMotor);
        verticalLayout_15->setSpacing(2);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(3, 3, 3, 3);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_xMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_xMotor->setObjectName(QStringLiteral("radioButton_xMotor"));

        gridLayout->addWidget(radioButton_xMotor, 0, 0, 1, 1);

        radioButton_focusMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_focusMotor->setObjectName(QStringLiteral("radioButton_focusMotor"));

        gridLayout->addWidget(radioButton_focusMotor, 0, 1, 1, 1);

        radioButton_spotMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_spotMotor->setObjectName(QStringLiteral("radioButton_spotMotor"));

        gridLayout->addWidget(radioButton_spotMotor, 0, 2, 1, 1);

        radioButton_chinHozMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_chinHozMotor->setObjectName(QStringLiteral("radioButton_chinHozMotor"));

        gridLayout->addWidget(radioButton_chinHozMotor, 0, 3, 1, 1);

        radioButton_yMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_yMotor->setObjectName(QStringLiteral("radioButton_yMotor"));

        gridLayout->addWidget(radioButton_yMotor, 1, 0, 1, 1);

        radioButton_colorMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_colorMotor->setObjectName(QStringLiteral("radioButton_colorMotor"));

        gridLayout->addWidget(radioButton_colorMotor, 1, 1, 1, 1);

        radioButton_shutterMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_shutterMotor->setObjectName(QStringLiteral("radioButton_shutterMotor"));

        gridLayout->addWidget(radioButton_shutterMotor, 1, 2, 1, 1);

        radioButton_chinVertMotor = new QRadioButton(groupBox_resetMotor);
        radioButton_chinVertMotor->setObjectName(QStringLiteral("radioButton_chinVertMotor"));

        gridLayout->addWidget(radioButton_chinVertMotor, 1, 3, 1, 1);


        verticalLayout_15->addLayout(gridLayout);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_26 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_26);

        label_32 = new QLabel(groupBox_resetMotor);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_14->addWidget(label_32);

        spinBox_resetSpeed = new QSpinBox(groupBox_resetMotor);
        spinBox_resetSpeed->setObjectName(QStringLiteral("spinBox_resetSpeed"));

        horizontalLayout_14->addWidget(spinBox_resetSpeed);

        pushButton_resetCheckedMotors = new QPushButton(groupBox_resetMotor);
        pushButton_resetCheckedMotors->setObjectName(QStringLiteral("pushButton_resetCheckedMotors"));

        horizontalLayout_14->addWidget(pushButton_resetCheckedMotors);


        verticalLayout_15->addLayout(horizontalLayout_14);


        verticalLayout_3->addWidget(groupBox_resetMotor);

        groupBox_16 = new QGroupBox(groupBox);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        groupBox_16->setMinimumSize(QSize(0, 0));
        groupBox_16->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_16);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        label_xMotorRange = new QLabel(groupBox_16);
        label_xMotorRange->setObjectName(QStringLiteral("label_xMotorRange"));
        label_xMotorRange->setMinimumSize(QSize(105, 0));

        gridLayout_8->addWidget(label_xMotorRange, 0, 1, 1, 1);

        label_focalMotorRange = new QLabel(groupBox_16);
        label_focalMotorRange->setObjectName(QStringLiteral("label_focalMotorRange"));
        label_focalMotorRange->setMinimumSize(QSize(105, 0));

        gridLayout_8->addWidget(label_focalMotorRange, 0, 3, 1, 1);

        label_chinVertMotorRange = new QLabel(groupBox_16);
        label_chinVertMotorRange->setObjectName(QStringLiteral("label_chinVertMotorRange"));
        label_chinVertMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_chinVertMotorRange, 3, 3, 1, 1);

        label_colorMotorRange = new QLabel(groupBox_16);
        label_colorMotorRange->setObjectName(QStringLiteral("label_colorMotorRange"));
        label_colorMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_colorMotorRange, 1, 3, 1, 1);

        label_58 = new QLabel(groupBox_16);
        label_58->setObjectName(QStringLiteral("label_58"));

        gridLayout_8->addWidget(label_58, 0, 2, 1, 1);

        label_yMotorRange = new QLabel(groupBox_16);
        label_yMotorRange->setObjectName(QStringLiteral("label_yMotorRange"));
        label_yMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_yMotorRange, 1, 1, 1, 1);

        label_spotMotorRange = new QLabel(groupBox_16);
        label_spotMotorRange->setObjectName(QStringLiteral("label_spotMotorRange"));
        label_spotMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_spotMotorRange, 2, 1, 1, 1);

        label_52 = new QLabel(groupBox_16);
        label_52->setObjectName(QStringLiteral("label_52"));

        gridLayout_8->addWidget(label_52, 0, 0, 1, 1);

        label_shutterMotorRange = new QLabel(groupBox_16);
        label_shutterMotorRange->setObjectName(QStringLiteral("label_shutterMotorRange"));
        label_shutterMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_shutterMotorRange, 3, 1, 1, 1);

        label_62 = new QLabel(groupBox_16);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setMinimumSize(QSize(0, 0));

        gridLayout_8->addWidget(label_62, 2, 0, 1, 1);

        label_65 = new QLabel(groupBox_16);
        label_65->setObjectName(QStringLiteral("label_65"));

        gridLayout_8->addWidget(label_65, 3, 2, 1, 1);

        label_68 = new QLabel(groupBox_16);
        label_68->setObjectName(QStringLiteral("label_68"));
        sizePolicy1.setHeightForWidth(label_68->sizePolicy().hasHeightForWidth());
        label_68->setSizePolicy(sizePolicy1);
        label_68->setMinimumSize(QSize(80, 0));

        gridLayout_8->addWidget(label_68, 2, 2, 1, 1);

        label_54 = new QLabel(groupBox_16);
        label_54->setObjectName(QStringLiteral("label_54"));

        gridLayout_8->addWidget(label_54, 1, 0, 1, 1);

        label_56 = new QLabel(groupBox_16);
        label_56->setObjectName(QStringLiteral("label_56"));

        gridLayout_8->addWidget(label_56, 1, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_22, 1, 4, 1, 1);

        label_chinHozMotorRange = new QLabel(groupBox_16);
        label_chinHozMotorRange->setObjectName(QStringLiteral("label_chinHozMotorRange"));
        label_chinHozMotorRange->setMinimumSize(QSize(70, 0));

        gridLayout_8->addWidget(label_chinHozMotorRange, 2, 3, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_25, 0, 4, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_23, 2, 4, 1, 1);

        label_64 = new QLabel(groupBox_16);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setMinimumSize(QSize(0, 0));

        gridLayout_8->addWidget(label_64, 3, 0, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_24, 3, 4, 1, 1);


        verticalLayout_3->addWidget(groupBox_16);

        tabWidget_3 = new QTabWidget(groupBox);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_7 = new QGridLayout(tab_8);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(5, 5, 3, 3);
        label_87 = new QLabel(tab_8);
        label_87->setObjectName(QStringLiteral("label_87"));

        gridLayout_7->addWidget(label_87, 0, 0, 1, 1);

        label_posX = new QLabel(tab_8);
        label_posX->setObjectName(QStringLiteral("label_posX"));

        gridLayout_7->addWidget(label_posX, 0, 1, 1, 1);

        label_85 = new QLabel(tab_8);
        label_85->setObjectName(QStringLiteral("label_85"));

        gridLayout_7->addWidget(label_85, 0, 2, 1, 1);

        label_posFocus = new QLabel(tab_8);
        label_posFocus->setObjectName(QStringLiteral("label_posFocus"));

        gridLayout_7->addWidget(label_posFocus, 0, 3, 1, 1);

        label_90 = new QLabel(tab_8);
        label_90->setObjectName(QStringLiteral("label_90"));

        gridLayout_7->addWidget(label_90, 0, 4, 1, 1);

        label_posSpot = new QLabel(tab_8);
        label_posSpot->setObjectName(QStringLiteral("label_posSpot"));

        gridLayout_7->addWidget(label_posSpot, 0, 5, 1, 1);

        label_88 = new QLabel(tab_8);
        label_88->setObjectName(QStringLiteral("label_88"));

        gridLayout_7->addWidget(label_88, 0, 6, 1, 1);

        label_posChinHoz = new QLabel(tab_8);
        label_posChinHoz->setObjectName(QStringLiteral("label_posChinHoz"));

        gridLayout_7->addWidget(label_posChinHoz, 0, 7, 1, 1);

        label_84 = new QLabel(tab_8);
        label_84->setObjectName(QStringLiteral("label_84"));

        gridLayout_7->addWidget(label_84, 1, 0, 1, 1);

        label_posY = new QLabel(tab_8);
        label_posY->setObjectName(QStringLiteral("label_posY"));

        gridLayout_7->addWidget(label_posY, 1, 1, 1, 1);

        label_89 = new QLabel(tab_8);
        label_89->setObjectName(QStringLiteral("label_89"));

        gridLayout_7->addWidget(label_89, 1, 2, 1, 1);

        label_posColor = new QLabel(tab_8);
        label_posColor->setObjectName(QStringLiteral("label_posColor"));

        gridLayout_7->addWidget(label_posColor, 1, 3, 1, 1);

        label_86 = new QLabel(tab_8);
        label_86->setObjectName(QStringLiteral("label_86"));

        gridLayout_7->addWidget(label_86, 1, 4, 1, 1);

        label_posShutter = new QLabel(tab_8);
        label_posShutter->setObjectName(QStringLiteral("label_posShutter"));

        gridLayout_7->addWidget(label_posShutter, 1, 5, 1, 1);

        label_75 = new QLabel(tab_8);
        label_75->setObjectName(QStringLiteral("label_75"));

        gridLayout_7->addWidget(label_75, 1, 6, 1, 1);

        label_posChinVert = new QLabel(tab_8);
        label_posChinVert->setObjectName(QStringLiteral("label_posChinVert"));

        gridLayout_7->addWidget(label_posChinVert, 1, 7, 1, 1);

        tabWidget_3->addTab(tab_8, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_2 = new QGridLayout(tab_7);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 3, 3);
        label_47 = new QLabel(tab_7);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_2->addWidget(label_47, 0, 0, 1, 1);

        label_stateX = new QLabel(tab_7);
        label_stateX->setObjectName(QStringLiteral("label_stateX"));

        gridLayout_2->addWidget(label_stateX, 0, 1, 1, 1);

        label_48 = new QLabel(tab_7);
        label_48->setObjectName(QStringLiteral("label_48"));

        gridLayout_2->addWidget(label_48, 0, 2, 1, 1);

        label_stateFocus = new QLabel(tab_7);
        label_stateFocus->setObjectName(QStringLiteral("label_stateFocus"));

        gridLayout_2->addWidget(label_stateFocus, 0, 3, 1, 1);

        label_51 = new QLabel(tab_7);
        label_51->setObjectName(QStringLiteral("label_51"));

        gridLayout_2->addWidget(label_51, 0, 4, 1, 1);

        label_stateSpot = new QLabel(tab_7);
        label_stateSpot->setObjectName(QStringLiteral("label_stateSpot"));

        gridLayout_2->addWidget(label_stateSpot, 0, 5, 1, 1);

        label_53 = new QLabel(tab_7);
        label_53->setObjectName(QStringLiteral("label_53"));

        gridLayout_2->addWidget(label_53, 0, 6, 1, 1);

        label_stateChinHoz = new QLabel(tab_7);
        label_stateChinHoz->setObjectName(QStringLiteral("label_stateChinHoz"));

        gridLayout_2->addWidget(label_stateChinHoz, 0, 7, 1, 1);

        label_57 = new QLabel(tab_7);
        label_57->setObjectName(QStringLiteral("label_57"));

        gridLayout_2->addWidget(label_57, 1, 0, 1, 1);

        label_stateY = new QLabel(tab_7);
        label_stateY->setObjectName(QStringLiteral("label_stateY"));

        gridLayout_2->addWidget(label_stateY, 1, 1, 1, 1);

        label_61 = new QLabel(tab_7);
        label_61->setObjectName(QStringLiteral("label_61"));

        gridLayout_2->addWidget(label_61, 1, 2, 1, 1);

        label_stateColor = new QLabel(tab_7);
        label_stateColor->setObjectName(QStringLiteral("label_stateColor"));

        gridLayout_2->addWidget(label_stateColor, 1, 3, 1, 1);

        label_55 = new QLabel(tab_7);
        label_55->setObjectName(QStringLiteral("label_55"));

        gridLayout_2->addWidget(label_55, 1, 4, 1, 1);

        label_stateShutter = new QLabel(tab_7);
        label_stateShutter->setObjectName(QStringLiteral("label_stateShutter"));

        gridLayout_2->addWidget(label_stateShutter, 1, 5, 1, 1);

        label_59 = new QLabel(tab_7);
        label_59->setObjectName(QStringLiteral("label_59"));

        gridLayout_2->addWidget(label_59, 1, 6, 1, 1);

        label_stateChinVert = new QLabel(tab_7);
        label_stateChinVert->setObjectName(QStringLiteral("label_stateChinVert"));

        gridLayout_2->addWidget(label_stateChinVert, 1, 7, 1, 1);

        tabWidget_3->addTab(tab_7, QString());

        verticalLayout_3->addWidget(tabWidget_3);

        groupBox_13 = new QGroupBox(groupBox);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy5);
        groupBox_13->setMinimumSize(QSize(0, 0));
        groupBox_13->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_6 = new QGridLayout(groupBox_13);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(2);
        gridLayout_6->setVerticalSpacing(3);
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        label_VID = new QLabel(groupBox_13);
        label_VID->setObjectName(QStringLiteral("label_VID"));
        label_VID->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(label_VID, 0, 1, 1, 1);

        label_36 = new QLabel(groupBox_13);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMaximumSize(QSize(100, 16777215));

        gridLayout_6->addWidget(label_36, 0, 2, 1, 1);

        label_castLightDA = new QLabel(groupBox_13);
        label_castLightDA->setObjectName(QStringLiteral("label_castLightDA"));

        gridLayout_6->addWidget(label_castLightDA, 1, 3, 1, 1);

        label_34 = new QLabel(groupBox_13);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_6->addWidget(label_34, 1, 4, 1, 1);

        label_connectionStatus = new QLabel(groupBox_13);
        label_connectionStatus->setObjectName(QStringLiteral("label_connectionStatus"));

        gridLayout_6->addWidget(label_connectionStatus, 1, 5, 1, 1);

        label_eyeglassStatus = new QLabel(groupBox_13);
        label_eyeglassStatus->setObjectName(QStringLiteral("label_eyeglassStatus"));

        gridLayout_6->addWidget(label_eyeglassStatus, 2, 3, 1, 1);

        label_60 = new QLabel(groupBox_13);
        label_60->setObjectName(QStringLiteral("label_60"));

        gridLayout_6->addWidget(label_60, 2, 4, 1, 1);

        label_69 = new QLabel(groupBox_13);
        label_69->setObjectName(QStringLiteral("label_69"));
        label_69->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_69, 2, 0, 1, 1);

        label_devVer = new QLabel(groupBox_13);
        label_devVer->setObjectName(QStringLiteral("label_devVer"));

        gridLayout_6->addWidget(label_devVer, 2, 5, 1, 1);

        label_environmentDA = new QLabel(groupBox_13);
        label_environmentDA->setObjectName(QStringLiteral("label_environmentDA"));

        gridLayout_6->addWidget(label_environmentDA, 1, 1, 1, 1);

        label_67 = new QLabel(groupBox_13);
        label_67->setObjectName(QStringLiteral("label_67"));

        gridLayout_6->addWidget(label_67, 1, 2, 1, 1);

        label_answerState = new QLabel(groupBox_13);
        label_answerState->setObjectName(QStringLiteral("label_answerState"));

        gridLayout_6->addWidget(label_answerState, 2, 1, 1, 1);

        label_33 = new QLabel(groupBox_13);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMaximumSize(QSize(100, 16777215));

        gridLayout_6->addWidget(label_33, 0, 0, 1, 1);

        label_66 = new QLabel(groupBox_13);
        label_66->setObjectName(QStringLiteral("label_66"));

        gridLayout_6->addWidget(label_66, 2, 2, 1, 1);

        label_devType = new QLabel(groupBox_13);
        label_devType->setObjectName(QStringLiteral("label_devType"));

        gridLayout_6->addWidget(label_devType, 0, 5, 1, 1);

        label_PID = new QLabel(groupBox_13);
        label_PID->setObjectName(QStringLiteral("label_PID"));

        gridLayout_6->addWidget(label_PID, 0, 3, 1, 1);

        label_63 = new QLabel(groupBox_13);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_63, 1, 0, 1, 1);

        label_50 = new QLabel(groupBox_13);
        label_50->setObjectName(QStringLiteral("label_50"));

        gridLayout_6->addWidget(label_50, 0, 4, 1, 1);


        verticalLayout_3->addWidget(groupBox_13);


        horizontalLayout_12->addWidget(groupBox);

        groupBox_15 = new QGroupBox(tab);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_15->sizePolicy().hasHeightForWidth());
        groupBox_15->setSizePolicy(sizePolicy6);
        groupBox_15->setMinimumSize(QSize(0, 0));
        groupBox_15->setMaximumSize(QSize(450, 16777215));
        verticalLayout_9 = new QVBoxLayout(groupBox_15);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(3, 3, 3, 3);
        groupBox_14 = new QGroupBox(groupBox_15);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        sizePolicy4.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy4);
        groupBox_14->setMinimumSize(QSize(320, 0));
        groupBox_14->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_14);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setSpacing(6);
        horizontalLayout_57->setObjectName(QStringLiteral("horizontalLayout_57"));
        horizontalSpacer_81 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_57->addItem(horizontalSpacer_81);

        openGLWidget = new QOpenGLWidget(groupBox_14);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(320, 240));
        openGLWidget->setMaximumSize(QSize(320, 240));

        horizontalLayout_57->addWidget(openGLWidget);

        horizontalSpacer_82 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_57->addItem(horizontalSpacer_82);


        verticalLayout_2->addLayout(horizontalLayout_57);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(3);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        pushButton_chinMoveLeft = new QPushButton(groupBox_14);
        pushButton_chinMoveLeft->setObjectName(QStringLiteral("pushButton_chinMoveLeft"));

        horizontalLayout_10->addWidget(pushButton_chinMoveLeft);

        pushButton_chinMoveUp = new QPushButton(groupBox_14);
        pushButton_chinMoveUp->setObjectName(QStringLiteral("pushButton_chinMoveUp"));

        horizontalLayout_10->addWidget(pushButton_chinMoveUp);

        pushButton_chinMoveDown = new QPushButton(groupBox_14);
        pushButton_chinMoveDown->setObjectName(QStringLiteral("pushButton_chinMoveDown"));

        horizontalLayout_10->addWidget(pushButton_chinMoveDown);

        pushButton_chinMoveRight = new QPushButton(groupBox_14);
        pushButton_chinMoveRight->setObjectName(QStringLiteral("pushButton_chinMoveRight"));

        horizontalLayout_10->addWidget(pushButton_chinMoveRight);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        label_38 = new QLabel(groupBox_14);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_9->addWidget(label_38);

        label_videoSize = new QLabel(groupBox_14);
        label_videoSize->setObjectName(QStringLiteral("label_videoSize"));
        label_videoSize->setMinimumSize(QSize(45, 0));
        label_videoSize->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_9->addWidget(label_videoSize);

        label_20 = new QLabel(groupBox_14);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_9->addWidget(label_20);

        spinBox_speedChinMove = new QSpinBox(groupBox_14);
        spinBox_speedChinMove->setObjectName(QStringLiteral("spinBox_speedChinMove"));
        spinBox_speedChinMove->setMinimum(1);
        spinBox_speedChinMove->setValue(1);

        horizontalLayout_9->addWidget(spinBox_speedChinMove);

        pushButton_cameraSwitch = new QPushButton(groupBox_14);
        pushButton_cameraSwitch->setObjectName(QStringLiteral("pushButton_cameraSwitch"));

        horizontalLayout_9->addWidget(pushButton_cameraSwitch);

        horizontalSpacer_2 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_9->addWidget(groupBox_14);

        groupBox_7 = new QGroupBox(groupBox_15);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_7);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_3->addWidget(label_17);

        comboBox_color = new QComboBox(groupBox_7);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));
        comboBox_color->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(comboBox_color);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_3->addWidget(label_18);

        spinBox_colorSlot = new QSpinBox(groupBox_7);
        spinBox_colorSlot->setObjectName(QStringLiteral("spinBox_colorSlot"));
        spinBox_colorSlot->setMinimumSize(QSize(40, 0));
        spinBox_colorSlot->setMinimum(0);
        spinBox_colorSlot->setMaximum(6);

        horizontalLayout_3->addWidget(spinBox_colorSlot);

        label_71 = new QLabel(groupBox_7);
        label_71->setObjectName(QStringLiteral("label_71"));

        horizontalLayout_3->addWidget(label_71);

        spinBox_colorMotorPos_2 = new QSpinBox(groupBox_7);
        spinBox_colorMotorPos_2->setObjectName(QStringLiteral("spinBox_colorMotorPos_2"));
        spinBox_colorMotorPos_2->setMinimumSize(QSize(40, 0));
        spinBox_colorMotorPos_2->setMinimum(-200000);
        spinBox_colorMotorPos_2->setMaximum(200000);

        horizontalLayout_3->addWidget(spinBox_colorMotorPos_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        checkBox_colorConfigSync = new QCheckBox(groupBox_7);
        checkBox_colorConfigSync->setObjectName(QStringLiteral("checkBox_colorConfigSync"));
        checkBox_colorConfigSync->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_colorConfigSync);

        pushButton_colorTest = new QPushButton(groupBox_7);
        pushButton_colorTest->setObjectName(QStringLiteral("pushButton_colorTest"));
        pushButton_colorTest->setMinimumSize(QSize(40, 0));
        pushButton_colorTest->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(pushButton_colorTest);


        verticalLayout_9->addWidget(groupBox_7);

        groupBox_s = new QGroupBox(groupBox_15);
        groupBox_s->setObjectName(QStringLiteral("groupBox_s"));
        horizontalLayout = new QHBoxLayout(groupBox_s);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        label_16 = new QLabel(groupBox_s);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout->addWidget(label_16);

        comboBox_spotSize = new QComboBox(groupBox_s);
        comboBox_spotSize->setObjectName(QStringLiteral("comboBox_spotSize"));
        comboBox_spotSize->setMaximumSize(QSize(40, 16777215));
        comboBox_spotSize->setEditable(false);

        horizontalLayout->addWidget(comboBox_spotSize);

        label_19 = new QLabel(groupBox_s);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout->addWidget(label_19);

        spinBox_spotSlot = new QSpinBox(groupBox_s);
        spinBox_spotSlot->setObjectName(QStringLiteral("spinBox_spotSlot"));
        spinBox_spotSlot->setMinimumSize(QSize(40, 0));
        spinBox_spotSlot->setMinimum(0);
        spinBox_spotSlot->setMaximum(8);

        horizontalLayout->addWidget(spinBox_spotSlot);

        label_44 = new QLabel(groupBox_s);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout->addWidget(label_44);

        spinBox_spotMotorPos_2 = new QSpinBox(groupBox_s);
        spinBox_spotMotorPos_2->setObjectName(QStringLiteral("spinBox_spotMotorPos_2"));
        spinBox_spotMotorPos_2->setMinimumSize(QSize(40, 0));
        spinBox_spotMotorPos_2->setMinimum(-200000);
        spinBox_spotMotorPos_2->setMaximum(200000);

        horizontalLayout->addWidget(spinBox_spotMotorPos_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        checkBox_spotConfigSync = new QCheckBox(groupBox_s);
        checkBox_spotConfigSync->setObjectName(QStringLiteral("checkBox_spotConfigSync"));
        checkBox_spotConfigSync->setChecked(false);

        horizontalLayout->addWidget(checkBox_spotConfigSync);

        pushButton_spotTest = new QPushButton(groupBox_s);
        pushButton_spotTest->setObjectName(QStringLiteral("pushButton_spotTest"));
        pushButton_spotTest->setMinimumSize(QSize(40, 0));
        pushButton_spotTest->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_spotTest);


        verticalLayout_9->addWidget(groupBox_s);

        groupBox_4 = new QGroupBox(groupBox_15);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 40));
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_13 = new QHBoxLayout(groupBox_4);
        horizontalLayout_13->setSpacing(3);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(3, 3, 3, 3);
        label_46 = new QLabel(groupBox_4);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setMinimumSize(QSize(30, 0));
        label_46->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_13->addWidget(label_46);

        spinBox_DbSetting = new QSpinBox(groupBox_4);
        spinBox_DbSetting->setObjectName(QStringLiteral("spinBox_DbSetting"));
        spinBox_DbSetting->setMinimumSize(QSize(40, 0));
        spinBox_DbSetting->setMinimum(0);
        spinBox_DbSetting->setMaximum(51);

        horizontalLayout_13->addWidget(spinBox_DbSetting);

        label_82 = new QLabel(groupBox_4);
        label_82->setObjectName(QStringLiteral("label_82"));
        label_82->setMinimumSize(QSize(50, 0));

        horizontalLayout_13->addWidget(label_82);

        spinBox_DbColorPos = new QSpinBox(groupBox_4);
        spinBox_DbColorPos->setObjectName(QStringLiteral("spinBox_DbColorPos"));
        spinBox_DbColorPos->setMinimumSize(QSize(60, 0));
        spinBox_DbColorPos->setMinimum(-200000);
        spinBox_DbColorPos->setMaximum(200000);

        horizontalLayout_13->addWidget(spinBox_DbColorPos);

        label_83 = new QLabel(groupBox_4);
        label_83->setObjectName(QStringLiteral("label_83"));
        label_83->setMinimumSize(QSize(50, 0));

        horizontalLayout_13->addWidget(label_83);

        spinBox_DbSpotPos = new QSpinBox(groupBox_4);
        spinBox_DbSpotPos->setObjectName(QStringLiteral("spinBox_DbSpotPos"));
        spinBox_DbSpotPos->setMinimumSize(QSize(60, 0));
        spinBox_DbSpotPos->setMinimum(-200000);
        spinBox_DbSpotPos->setMaximum(200000);

        horizontalLayout_13->addWidget(spinBox_DbSpotPos);

        checkBox_DbConfigSync = new QCheckBox(groupBox_4);
        checkBox_DbConfigSync->setObjectName(QStringLiteral("checkBox_DbConfigSync"));
        checkBox_DbConfigSync->setChecked(false);

        horizontalLayout_13->addWidget(checkBox_DbConfigSync);

        pushButton_dbTest = new QPushButton(groupBox_4);
        pushButton_dbTest->setObjectName(QStringLiteral("pushButton_dbTest"));
        pushButton_dbTest->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_13->addWidget(pushButton_dbTest);


        verticalLayout_9->addWidget(groupBox_4);

        stackedWidget = new QStackedWidget(groupBox_15);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_7 = new QHBoxLayout(page);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        groupBox_staticCastPos = new QGroupBox(page);
        groupBox_staticCastPos->setObjectName(QStringLiteral("groupBox_staticCastPos"));
        sizePolicy2.setHeightForWidth(groupBox_staticCastPos->sizePolicy().hasHeightForWidth());
        groupBox_staticCastPos->setSizePolicy(sizePolicy2);
        gridLayout_11 = new QGridLayout(groupBox_staticCastPos);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(3, 0, 3, 0);
        spinBox_YMotorPos_2 = new QSpinBox(groupBox_staticCastPos);
        spinBox_YMotorPos_2->setObjectName(QStringLiteral("spinBox_YMotorPos_2"));
        spinBox_YMotorPos_2->setMinimumSize(QSize(40, 0));
        spinBox_YMotorPos_2->setMaximumSize(QSize(60, 16777215));
        spinBox_YMotorPos_2->setMinimum(-200000);
        spinBox_YMotorPos_2->setMaximum(200000);

        gridLayout_11->addWidget(spinBox_YMotorPos_2, 1, 3, 1, 1);

        pushButton_staticCastTest = new QPushButton(groupBox_staticCastPos);
        pushButton_staticCastTest->setObjectName(QStringLiteral("pushButton_staticCastTest"));
        pushButton_staticCastTest->setMaximumSize(QSize(40, 16777215));

        gridLayout_11->addWidget(pushButton_staticCastTest, 0, 8, 1, 1);

        lineEdit_coordY = new QLineEdit(groupBox_staticCastPos);
        lineEdit_coordY->setObjectName(QStringLiteral("lineEdit_coordY"));
        lineEdit_coordY->setMaximumSize(QSize(60, 16777215));

        gridLayout_11->addWidget(lineEdit_coordY, 1, 1, 1, 1);

        label_72 = new QLabel(groupBox_staticCastPos);
        label_72->setObjectName(QStringLiteral("label_72"));

        gridLayout_11->addWidget(label_72, 0, 2, 1, 1);

        spinBox_XMotorPos_2 = new QSpinBox(groupBox_staticCastPos);
        spinBox_XMotorPos_2->setObjectName(QStringLiteral("spinBox_XMotorPos_2"));
        spinBox_XMotorPos_2->setMinimumSize(QSize(40, 0));
        spinBox_XMotorPos_2->setMaximumSize(QSize(60, 16777215));
        spinBox_XMotorPos_2->setMinimum(-200000);
        spinBox_XMotorPos_2->setMaximum(200000);

        gridLayout_11->addWidget(spinBox_XMotorPos_2, 0, 3, 1, 1);

        label_22 = new QLabel(groupBox_staticCastPos);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(40, 0));
        label_22->setMaximumSize(QSize(40, 16777215));

        gridLayout_11->addWidget(label_22, 0, 0, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_19, 0, 4, 1, 1);

        label_23 = new QLabel(groupBox_staticCastPos);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(40, 0));
        label_23->setMaximumSize(QSize(40, 16777215));

        gridLayout_11->addWidget(label_23, 1, 0, 1, 1);

        lineEdit_coordX = new QLineEdit(groupBox_staticCastPos);
        lineEdit_coordX->setObjectName(QStringLiteral("lineEdit_coordX"));
        lineEdit_coordX->setMaximumSize(QSize(60, 16777215));

        gridLayout_11->addWidget(lineEdit_coordX, 0, 1, 1, 1);

        checkBox_calcFocalDist = new QCheckBox(groupBox_staticCastPos);
        checkBox_calcFocalDist->setObjectName(QStringLiteral("checkBox_calcFocalDist"));
        checkBox_calcFocalDist->setChecked(true);

        gridLayout_11->addWidget(checkBox_calcFocalDist, 0, 7, 1, 1);

        label_73 = new QLabel(groupBox_staticCastPos);
        label_73->setObjectName(QStringLiteral("label_73"));

        gridLayout_11->addWidget(label_73, 1, 2, 1, 1);


        horizontalLayout_7->addWidget(groupBox_staticCastPos);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_5 = new QHBoxLayout(page_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_moveCastPos = new QGroupBox(page_2);
        groupBox_moveCastPos->setObjectName(QStringLiteral("groupBox_moveCastPos"));
        groupBox_moveCastPos->setEnabled(true);
        groupBox_moveCastPos->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_moveCastPos);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        label_41 = new QLabel(groupBox_moveCastPos);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMinimumSize(QSize(50, 0));
        label_41->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_41, 0, 0, 1, 1);

        horizontalSpacer_44 = new QSpacerItem(129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_44, 0, 8, 1, 2);

        label_42 = new QLabel(groupBox_moveCastPos);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setMinimumSize(QSize(50, 0));
        label_42->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_42, 0, 4, 1, 1);

        lineEdit_endCoordX = new QLineEdit(groupBox_moveCastPos);
        lineEdit_endCoordX->setObjectName(QStringLiteral("lineEdit_endCoordX"));
        lineEdit_endCoordX->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_endCoordX, 0, 5, 1, 1);

        lineEdit_beginCoordX = new QLineEdit(groupBox_moveCastPos);
        lineEdit_beginCoordX->setObjectName(QStringLiteral("lineEdit_beginCoordX"));
        lineEdit_beginCoordX->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_beginCoordX, 0, 1, 1, 1);

        label_40 = new QLabel(groupBox_moveCastPos);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(50, 0));
        label_40->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_40, 1, 0, 1, 1);

        lineEdit_beginCoordY = new QLineEdit(groupBox_moveCastPos);
        lineEdit_beginCoordY->setObjectName(QStringLiteral("lineEdit_beginCoordY"));
        lineEdit_beginCoordY->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_beginCoordY, 1, 1, 1, 1);

        label_43 = new QLabel(groupBox_moveCastPos);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setMinimumSize(QSize(50, 0));
        label_43->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_43, 1, 4, 1, 1);

        lineEdit_endCoordY = new QLineEdit(groupBox_moveCastPos);
        lineEdit_endCoordY->setObjectName(QStringLiteral("lineEdit_endCoordY"));
        lineEdit_endCoordY->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_endCoordY, 1, 5, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_20, 1, 8, 1, 2);


        horizontalLayout_5->addWidget(groupBox_moveCastPos);

        stackedWidget->addWidget(page_2);

        verticalLayout_9->addWidget(stackedWidget);

        groupBox_focalTest = new QGroupBox(groupBox_15);
        groupBox_focalTest->setObjectName(QStringLiteral("groupBox_focalTest"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_focalTest->sizePolicy().hasHeightForWidth());
        groupBox_focalTest->setSizePolicy(sizePolicy7);
        groupBox_focalTest->setMinimumSize(QSize(0, 0));
        gridLayout_13 = new QGridLayout(groupBox_focalTest);
        gridLayout_13->setSpacing(3);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(3, 3, 3, 3);
        spinBox_focalDist = new QSpinBox(groupBox_focalTest);
        spinBox_focalDist->setObjectName(QStringLiteral("spinBox_focalDist"));
        spinBox_focalDist->setMinimumSize(QSize(60, 0));
        spinBox_focalDist->setMaximumSize(QSize(60, 16777215));
        spinBox_focalDist->setMinimum(-200000);
        spinBox_focalDist->setMaximum(200000);

        gridLayout_13->addWidget(spinBox_focalDist, 1, 1, 1, 1);

        spinBox_focalMotorPos_2 = new QSpinBox(groupBox_focalTest);
        spinBox_focalMotorPos_2->setObjectName(QStringLiteral("spinBox_focalMotorPos_2"));
        spinBox_focalMotorPos_2->setMinimumSize(QSize(60, 0));
        spinBox_focalMotorPos_2->setMaximumSize(QSize(60, 16777215));
        spinBox_focalMotorPos_2->setMinimum(-200000);
        spinBox_focalMotorPos_2->setMaximum(200000);

        gridLayout_13->addWidget(spinBox_focalMotorPos_2, 1, 3, 1, 1);

        label_37 = new QLabel(groupBox_focalTest);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setMinimumSize(QSize(50, 0));
        label_37->setMaximumSize(QSize(50, 16777215));

        gridLayout_13->addWidget(label_37, 1, 0, 1, 1);

        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_39, 1, 4, 1, 1);

        pushButton_focalTest = new QPushButton(groupBox_focalTest);
        pushButton_focalTest->setObjectName(QStringLiteral("pushButton_focalTest"));
        pushButton_focalTest->setMaximumSize(QSize(40, 16777215));

        gridLayout_13->addWidget(pushButton_focalTest, 1, 5, 1, 1);

        label_39 = new QLabel(groupBox_focalTest);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_13->addWidget(label_39, 1, 2, 1, 1);


        verticalLayout_9->addWidget(groupBox_focalTest);

        groupBox_8 = new QGroupBox(groupBox_15);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        sizePolicy2.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy2);
        horizontalLayout_4 = new QHBoxLayout(groupBox_8);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(3, 3, 3, 3);
        label_26 = new QLabel(groupBox_8);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(50, 0));
        label_26->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(label_26);

        spinBox_shutterOpenDuration = new QSpinBox(groupBox_8);
        spinBox_shutterOpenDuration->setObjectName(QStringLiteral("spinBox_shutterOpenDuration"));
        spinBox_shutterOpenDuration->setMinimumSize(QSize(60, 0));
        spinBox_shutterOpenDuration->setMinimum(0);
        spinBox_shutterOpenDuration->setMaximum(65535);
        spinBox_shutterOpenDuration->setValue(200);

        horizontalLayout_4->addWidget(spinBox_shutterOpenDuration);

        label_27 = new QLabel(groupBox_8);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_4->addWidget(label_27);

        spinBox_shutterOpenPos = new QSpinBox(groupBox_8);
        spinBox_shutterOpenPos->setObjectName(QStringLiteral("spinBox_shutterOpenPos"));
        spinBox_shutterOpenPos->setMinimumSize(QSize(60, 0));
        spinBox_shutterOpenPos->setMaximumSize(QSize(60, 16777215));
        spinBox_shutterOpenPos->setMinimum(-200000);
        spinBox_shutterOpenPos->setMaximum(200000);

        horizontalLayout_4->addWidget(spinBox_shutterOpenPos);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        checkBox_shutterConfigSync = new QCheckBox(groupBox_8);
        checkBox_shutterConfigSync->setObjectName(QStringLiteral("checkBox_shutterConfigSync"));
        checkBox_shutterConfigSync->setEnabled(true);
        checkBox_shutterConfigSync->setChecked(false);

        horizontalLayout_4->addWidget(checkBox_shutterConfigSync);

        pushButton_shuterTest = new QPushButton(groupBox_8);
        pushButton_shuterTest->setObjectName(QStringLiteral("pushButton_shuterTest"));
        pushButton_shuterTest->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(pushButton_shuterTest);


        verticalLayout_9->addWidget(groupBox_8);

        groupBox_24 = new QGroupBox(groupBox_15);
        groupBox_24->setObjectName(QStringLiteral("groupBox_24"));
        gridLayout_10 = new QGridLayout(groupBox_24);
        gridLayout_10->setSpacing(3);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(3, 3, 3, 3);
        label_77 = new QLabel(groupBox_24);
        label_77->setObjectName(QStringLiteral("label_77"));
        label_77->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(label_77, 0, 0, 1, 1);

        spinBox_YMotorSpeed_2 = new QSpinBox(groupBox_24);
        spinBox_YMotorSpeed_2->setObjectName(QStringLiteral("spinBox_YMotorSpeed_2"));
        spinBox_YMotorSpeed_2->setMinimumSize(QSize(50, 0));
        spinBox_YMotorSpeed_2->setMaximumSize(QSize(50, 16777215));
        spinBox_YMotorSpeed_2->setMinimum(1);
        spinBox_YMotorSpeed_2->setMaximum(7);

        gridLayout_10->addWidget(spinBox_YMotorSpeed_2, 0, 4, 1, 1);

        spinBox_XMotorSpeed_2 = new QSpinBox(groupBox_24);
        spinBox_XMotorSpeed_2->setObjectName(QStringLiteral("spinBox_XMotorSpeed_2"));
        spinBox_XMotorSpeed_2->setMinimumSize(QSize(50, 0));
        spinBox_XMotorSpeed_2->setMaximumSize(QSize(50, 16777215));
        spinBox_XMotorSpeed_2->setMinimum(1);
        spinBox_XMotorSpeed_2->setMaximum(7);

        gridLayout_10->addWidget(spinBox_XMotorSpeed_2, 0, 1, 1, 1);

        spinBox_colorMotorSpeed_2 = new QSpinBox(groupBox_24);
        spinBox_colorMotorSpeed_2->setObjectName(QStringLiteral("spinBox_colorMotorSpeed_2"));
        spinBox_colorMotorSpeed_2->setMinimumSize(QSize(50, 0));
        spinBox_colorMotorSpeed_2->setMaximumSize(QSize(50, 16777215));
        spinBox_colorMotorSpeed_2->setMinimum(1);
        spinBox_colorMotorSpeed_2->setMaximum(7);

        gridLayout_10->addWidget(spinBox_colorMotorSpeed_2, 0, 9, 1, 1);

        label_78 = new QLabel(groupBox_24);
        label_78->setObjectName(QStringLiteral("label_78"));
        label_78->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(label_78, 0, 3, 1, 1);

        label_80 = new QLabel(groupBox_24);
        label_80->setObjectName(QStringLiteral("label_80"));

        gridLayout_10->addWidget(label_80, 0, 8, 1, 1);

        spinBox_focalMotorSpeed_2 = new QSpinBox(groupBox_24);
        spinBox_focalMotorSpeed_2->setObjectName(QStringLiteral("spinBox_focalMotorSpeed_2"));
        spinBox_focalMotorSpeed_2->setMinimumSize(QSize(50, 0));
        spinBox_focalMotorSpeed_2->setMaximumSize(QSize(50, 16777215));
        spinBox_focalMotorSpeed_2->setMinimum(1);
        spinBox_focalMotorSpeed_2->setMaximum(7);

        gridLayout_10->addWidget(spinBox_focalMotorSpeed_2, 0, 7, 1, 1);

        label_79 = new QLabel(groupBox_24);
        label_79->setObjectName(QStringLiteral("label_79"));

        gridLayout_10->addWidget(label_79, 0, 6, 1, 1);

        label_81 = new QLabel(groupBox_24);
        label_81->setObjectName(QStringLiteral("label_81"));

        gridLayout_10->addWidget(label_81, 0, 10, 1, 1);

        spinBox_spotMotorSpeed_2 = new QSpinBox(groupBox_24);
        spinBox_spotMotorSpeed_2->setObjectName(QStringLiteral("spinBox_spotMotorSpeed_2"));
        spinBox_spotMotorSpeed_2->setMinimumSize(QSize(50, 0));
        spinBox_spotMotorSpeed_2->setMaximumSize(QSize(50, 16777215));
        spinBox_spotMotorSpeed_2->setMinimum(1);
        spinBox_spotMotorSpeed_2->setMaximum(7);

        gridLayout_10->addWidget(spinBox_spotMotorSpeed_2, 0, 11, 1, 1);

        horizontalSpacer_41 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_41, 0, 2, 1, 1);

        horizontalSpacer_42 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_42, 0, 5, 1, 1);


        verticalLayout_9->addWidget(groupBox_24);

        groupBox_6 = new QGroupBox(groupBox_15);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        sizePolicy2.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(groupBox_6);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        label_45 = new QLabel(groupBox_6);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_2->addWidget(label_45);

        comboBox_testFucntion = new QComboBox(groupBox_6);
        comboBox_testFucntion->setObjectName(QStringLiteral("comboBox_testFucntion"));

        horizontalLayout_2->addWidget(comboBox_testFucntion);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        pushButton_testStart = new QPushButton(groupBox_6);
        pushButton_testStart->setObjectName(QStringLiteral("pushButton_testStart"));

        horizontalLayout_2->addWidget(pushButton_testStart);

        pushButton_readCache = new QPushButton(groupBox_6);
        pushButton_readCache->setObjectName(QStringLiteral("pushButton_readCache"));

        horizontalLayout_2->addWidget(pushButton_readCache);


        verticalLayout_9->addWidget(groupBox_6);


        horizontalLayout_12->addWidget(groupBox_15);

        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_21 = new QVBoxLayout(tab_5);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        textBrowser_infoText = new QTextBrowser(tab_5);
        textBrowser_infoText->setObjectName(QStringLiteral("textBrowser_infoText"));
        sizePolicy4.setHeightForWidth(textBrowser_infoText->sizePolicy().hasHeightForWidth());
        textBrowser_infoText->setSizePolicy(sizePolicy4);
        textBrowser_infoText->setMinimumSize(QSize(0, 0));

        verticalLayout_21->addWidget(textBrowser_infoText);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_27);

        checkBox_IO = new QCheckBox(tab_5);
        checkBox_IO->setObjectName(QStringLiteral("checkBox_IO"));
        checkBox_IO->setIconSize(QSize(16, 12));
        checkBox_IO->setCheckable(true);
        checkBox_IO->setChecked(false);
        checkBox_IO->setTristate(true);

        horizontalLayout_19->addWidget(checkBox_IO);


        verticalLayout_21->addLayout(horizontalLayout_19);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_10 = new QVBoxLayout(tab_6);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        textBrowser_refreshInfoText = new QTextBrowser(tab_6);
        textBrowser_refreshInfoText->setObjectName(QStringLiteral("textBrowser_refreshInfoText"));
        textBrowser_refreshInfoText->setMinimumSize(QSize(0, 0));

        verticalLayout_10->addWidget(textBrowser_refreshInfoText);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_36);

        checkBox_startRefreshInfo = new QCheckBox(tab_6);
        checkBox_startRefreshInfo->setObjectName(QStringLiteral("checkBox_startRefreshInfo"));
        checkBox_startRefreshInfo->setTristate(false);

        horizontalLayout_20->addWidget(checkBox_startRefreshInfo);

        checkBox_RefreshIO = new QCheckBox(tab_6);
        checkBox_RefreshIO->setObjectName(QStringLiteral("checkBox_RefreshIO"));
        checkBox_RefreshIO->setEnabled(false);
        checkBox_RefreshIO->setTristate(false);

        horizontalLayout_20->addWidget(checkBox_RefreshIO);


        verticalLayout_10->addLayout(horizontalLayout_20);

        tabWidget_2->addTab(tab_6, QString());

        horizontalLayout_12->addWidget(tabWidget_2);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_23 = new QHBoxLayout(tab_3);
        horizontalLayout_23->setSpacing(0);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        groupBox_83 = new QGroupBox(tab_3);
        groupBox_83->setObjectName(QStringLiteral("groupBox_83"));
        sizePolicy.setHeightForWidth(groupBox_83->sizePolicy().hasHeightForWidth());
        groupBox_83->setSizePolicy(sizePolicy);
        groupBox_83->setMinimumSize(QSize(0, 0));
        groupBox_83->setMaximumSize(QSize(350, 16777215));
        verticalLayout_12 = new QVBoxLayout(groupBox_83);
        verticalLayout_12->setSpacing(5);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(5, 5, 5, 5);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_57 = new QVBoxLayout();
        verticalLayout_57->setSpacing(6);
        verticalLayout_57->setObjectName(QStringLiteral("verticalLayout_57"));
        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setSpacing(6);
        horizontalLayout_58->setObjectName(QStringLiteral("horizontalLayout_58"));
        label_21 = new QLabel(groupBox_83);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout_58->addWidget(label_21);

        lineEdit_deviceSerialNo = new QLineEdit(groupBox_83);
        lineEdit_deviceSerialNo->setObjectName(QStringLiteral("lineEdit_deviceSerialNo"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(lineEdit_deviceSerialNo->sizePolicy().hasHeightForWidth());
        lineEdit_deviceSerialNo->setSizePolicy(sizePolicy8);
        lineEdit_deviceSerialNo->setMinimumSize(QSize(80, 0));
        lineEdit_deviceSerialNo->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_58->addWidget(lineEdit_deviceSerialNo);

        horizontalSpacer_21 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_58->addItem(horizontalSpacer_21);


        verticalLayout_57->addLayout(horizontalLayout_58);

        groupBox_84 = new QGroupBox(groupBox_83);
        groupBox_84->setObjectName(QStringLiteral("groupBox_84"));
        sizePolicy1.setHeightForWidth(groupBox_84->sizePolicy().hasHeightForWidth());
        groupBox_84->setSizePolicy(sizePolicy1);
        verticalLayout_46 = new QVBoxLayout(groupBox_84);
        verticalLayout_46->setSpacing(6);
        verticalLayout_46->setContentsMargins(11, 11, 11, 11);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        verticalLayout_46->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setSpacing(6);
        horizontalLayout_59->setObjectName(QStringLiteral("horizontalLayout_59"));
        label_24 = new QLabel(groupBox_84);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_59->addWidget(label_24);

        lineEdit_centralLightDA = new QLineEdit(groupBox_84);
        lineEdit_centralLightDA->setObjectName(QStringLiteral("lineEdit_centralLightDA"));
        sizePolicy8.setHeightForWidth(lineEdit_centralLightDA->sizePolicy().hasHeightForWidth());
        lineEdit_centralLightDA->setSizePolicy(sizePolicy8);
        lineEdit_centralLightDA->setMinimumSize(QSize(40, 0));
        lineEdit_centralLightDA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_59->addWidget(lineEdit_centralLightDA);

        horizontalSpacer_84 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_59->addItem(horizontalSpacer_84);


        verticalLayout_46->addLayout(horizontalLayout_59);

        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setSpacing(6);
        horizontalLayout_60->setObjectName(QStringLiteral("horizontalLayout_60"));
        label_25 = new QLabel(groupBox_84);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_60->addWidget(label_25);

        lineEdit_bigDiamond1DA = new QLineEdit(groupBox_84);
        lineEdit_bigDiamond1DA->setObjectName(QStringLiteral("lineEdit_bigDiamond1DA"));
        sizePolicy8.setHeightForWidth(lineEdit_bigDiamond1DA->sizePolicy().hasHeightForWidth());
        lineEdit_bigDiamond1DA->setSizePolicy(sizePolicy8);
        lineEdit_bigDiamond1DA->setMinimumSize(QSize(40, 0));
        lineEdit_bigDiamond1DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_60->addWidget(lineEdit_bigDiamond1DA);

        lineEdit_bigDiamond2DA = new QLineEdit(groupBox_84);
        lineEdit_bigDiamond2DA->setObjectName(QStringLiteral("lineEdit_bigDiamond2DA"));
        sizePolicy8.setHeightForWidth(lineEdit_bigDiamond2DA->sizePolicy().hasHeightForWidth());
        lineEdit_bigDiamond2DA->setSizePolicy(sizePolicy8);
        lineEdit_bigDiamond2DA->setMinimumSize(QSize(40, 0));
        lineEdit_bigDiamond2DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_60->addWidget(lineEdit_bigDiamond2DA);

        lineEdit_bigDiamond3DA = new QLineEdit(groupBox_84);
        lineEdit_bigDiamond3DA->setObjectName(QStringLiteral("lineEdit_bigDiamond3DA"));
        sizePolicy8.setHeightForWidth(lineEdit_bigDiamond3DA->sizePolicy().hasHeightForWidth());
        lineEdit_bigDiamond3DA->setSizePolicy(sizePolicy8);
        lineEdit_bigDiamond3DA->setMinimumSize(QSize(40, 0));
        lineEdit_bigDiamond3DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_60->addWidget(lineEdit_bigDiamond3DA);

        lineEdit_bigDiamond4DA = new QLineEdit(groupBox_84);
        lineEdit_bigDiamond4DA->setObjectName(QStringLiteral("lineEdit_bigDiamond4DA"));
        sizePolicy8.setHeightForWidth(lineEdit_bigDiamond4DA->sizePolicy().hasHeightForWidth());
        lineEdit_bigDiamond4DA->setSizePolicy(sizePolicy8);
        lineEdit_bigDiamond4DA->setMinimumSize(QSize(40, 0));
        lineEdit_bigDiamond4DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_60->addWidget(lineEdit_bigDiamond4DA);

        horizontalSpacer_85 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_60->addItem(horizontalSpacer_85);


        verticalLayout_46->addLayout(horizontalLayout_60);

        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setSpacing(6);
        horizontalLayout_61->setObjectName(QStringLiteral("horizontalLayout_61"));
        label_29 = new QLabel(groupBox_84);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_61->addWidget(label_29);

        lineEdit_smallDiamond1DA = new QLineEdit(groupBox_84);
        lineEdit_smallDiamond1DA->setObjectName(QStringLiteral("lineEdit_smallDiamond1DA"));
        sizePolicy8.setHeightForWidth(lineEdit_smallDiamond1DA->sizePolicy().hasHeightForWidth());
        lineEdit_smallDiamond1DA->setSizePolicy(sizePolicy8);
        lineEdit_smallDiamond1DA->setMinimumSize(QSize(40, 0));
        lineEdit_smallDiamond1DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_61->addWidget(lineEdit_smallDiamond1DA);

        lineEdit_smallDiamond2DA = new QLineEdit(groupBox_84);
        lineEdit_smallDiamond2DA->setObjectName(QStringLiteral("lineEdit_smallDiamond2DA"));
        lineEdit_smallDiamond2DA->setMinimumSize(QSize(40, 0));
        lineEdit_smallDiamond2DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_61->addWidget(lineEdit_smallDiamond2DA);

        lineEdit_smallDiamond3DA = new QLineEdit(groupBox_84);
        lineEdit_smallDiamond3DA->setObjectName(QStringLiteral("lineEdit_smallDiamond3DA"));
        lineEdit_smallDiamond3DA->setMinimumSize(QSize(40, 0));
        lineEdit_smallDiamond3DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_61->addWidget(lineEdit_smallDiamond3DA);

        lineEdit_smallDiamond4DA = new QLineEdit(groupBox_84);
        lineEdit_smallDiamond4DA->setObjectName(QStringLiteral("lineEdit_smallDiamond4DA"));
        lineEdit_smallDiamond4DA->setMinimumSize(QSize(40, 0));
        lineEdit_smallDiamond4DA->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_61->addWidget(lineEdit_smallDiamond4DA);

        horizontalSpacer_86 = new QSpacerItem(0, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_61->addItem(horizontalSpacer_86);


        verticalLayout_46->addLayout(horizontalLayout_61);


        verticalLayout_57->addWidget(groupBox_84);


        verticalLayout_19->addLayout(verticalLayout_57);

        verticalLayout_59 = new QVBoxLayout();
        verticalLayout_59->setSpacing(6);
        verticalLayout_59->setObjectName(QStringLiteral("verticalLayout_59"));
        groupBox_85 = new QGroupBox(groupBox_83);
        groupBox_85->setObjectName(QStringLiteral("groupBox_85"));
        sizePolicy1.setHeightForWidth(groupBox_85->sizePolicy().hasHeightForWidth());
        groupBox_85->setSizePolicy(sizePolicy1);
        horizontalLayout_62 = new QHBoxLayout(groupBox_85);
        horizontalLayout_62->setSpacing(6);
        horizontalLayout_62->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_62->setObjectName(QStringLiteral("horizontalLayout_62"));
        horizontalLayout_62->setContentsMargins(5, 5, 5, 5);
        label_30 = new QLabel(groupBox_85);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(55, 0));
        label_30->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_62->addWidget(label_30);

        lineEdit_yellowBackGroundLampDa = new QLineEdit(groupBox_85);
        lineEdit_yellowBackGroundLampDa->setObjectName(QStringLiteral("lineEdit_yellowBackGroundLampDa"));
        lineEdit_yellowBackGroundLampDa->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_62->addWidget(lineEdit_yellowBackGroundLampDa);

        label_31 = new QLabel(groupBox_85);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(50, 0));

        horizontalLayout_62->addWidget(label_31);

        lineEdit_whiteBackGroundLampR = new QLineEdit(groupBox_85);
        lineEdit_whiteBackGroundLampR->setObjectName(QStringLiteral("lineEdit_whiteBackGroundLampR"));
        lineEdit_whiteBackGroundLampR->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_62->addWidget(lineEdit_whiteBackGroundLampR);

        lineEdit_whiteBackGroundLampG = new QLineEdit(groupBox_85);
        lineEdit_whiteBackGroundLampG->setObjectName(QStringLiteral("lineEdit_whiteBackGroundLampG"));
        lineEdit_whiteBackGroundLampG->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_62->addWidget(lineEdit_whiteBackGroundLampG);

        lineEdit_whiteBackGroundLampB = new QLineEdit(groupBox_85);
        lineEdit_whiteBackGroundLampB->setObjectName(QStringLiteral("lineEdit_whiteBackGroundLampB"));
        lineEdit_whiteBackGroundLampB->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_62->addWidget(lineEdit_whiteBackGroundLampB);

        horizontalSpacer_83 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_62->addItem(horizontalSpacer_83);


        verticalLayout_59->addWidget(groupBox_85);

        groupBox_86 = new QGroupBox(groupBox_83);
        groupBox_86->setObjectName(QStringLiteral("groupBox_86"));
        sizePolicy1.setHeightForWidth(groupBox_86->sizePolicy().hasHeightForWidth());
        groupBox_86->setSizePolicy(sizePolicy1);
        gridLayout_36 = new QGridLayout(groupBox_86);
        gridLayout_36->setSpacing(6);
        gridLayout_36->setContentsMargins(11, 11, 11, 11);
        gridLayout_36->setObjectName(QStringLiteral("gridLayout_36"));
        gridLayout_36->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_36->addItem(horizontalSpacer_29, 0, 6, 1, 1);

        lineEdit_centerInfraredLampDA = new QLineEdit(groupBox_86);
        lineEdit_centerInfraredLampDA->setObjectName(QStringLiteral("lineEdit_centerInfraredLampDA"));
        lineEdit_centerInfraredLampDA->setMinimumSize(QSize(40, 0));
        lineEdit_centerInfraredLampDA->setMaximumSize(QSize(40, 16777215));

        gridLayout_36->addWidget(lineEdit_centerInfraredLampDA, 0, 1, 1, 1);

        label_363 = new QLabel(groupBox_86);
        label_363->setObjectName(QStringLiteral("label_363"));

        gridLayout_36->addWidget(label_363, 0, 2, 1, 1);

        label_364 = new QLabel(groupBox_86);
        label_364->setObjectName(QStringLiteral("label_364"));

        gridLayout_36->addWidget(label_364, 0, 4, 1, 1);

        lineEdit_borderLampDA = new QLineEdit(groupBox_86);
        lineEdit_borderLampDA->setObjectName(QStringLiteral("lineEdit_borderLampDA"));
        lineEdit_borderLampDA->setMinimumSize(QSize(40, 0));
        lineEdit_borderLampDA->setMaximumSize(QSize(40, 16777215));

        gridLayout_36->addWidget(lineEdit_borderLampDA, 0, 3, 1, 1);

        lineEdit_eyeGlassLampDa = new QLineEdit(groupBox_86);
        lineEdit_eyeGlassLampDa->setObjectName(QStringLiteral("lineEdit_eyeGlassLampDa"));
        lineEdit_eyeGlassLampDa->setMinimumSize(QSize(40, 0));
        lineEdit_eyeGlassLampDa->setMaximumSize(QSize(40, 16777215));

        gridLayout_36->addWidget(lineEdit_eyeGlassLampDa, 0, 5, 1, 1);

        label_362 = new QLabel(groupBox_86);
        label_362->setObjectName(QStringLiteral("label_362"));

        gridLayout_36->addWidget(label_362, 0, 0, 1, 1);


        verticalLayout_59->addWidget(groupBox_86);

        groupBox_81 = new QGroupBox(groupBox_83);
        groupBox_81->setObjectName(QStringLiteral("groupBox_81"));
        sizePolicy1.setHeightForWidth(groupBox_81->sizePolicy().hasHeightForWidth());
        groupBox_81->setSizePolicy(sizePolicy1);
        horizontalLayout_64 = new QHBoxLayout(groupBox_81);
        horizontalLayout_64->setSpacing(6);
        horizontalLayout_64->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_64->setObjectName(QStringLiteral("horizontalLayout_64"));
        horizontalLayout_64->setContentsMargins(5, 5, 5, 5);
        label_368 = new QLabel(groupBox_81);
        label_368->setObjectName(QStringLiteral("label_368"));

        horizontalLayout_64->addWidget(label_368);

        lineEdit_whiteLampEnvLightAlarm = new QLineEdit(groupBox_81);
        lineEdit_whiteLampEnvLightAlarm->setObjectName(QStringLiteral("lineEdit_whiteLampEnvLightAlarm"));
        lineEdit_whiteLampEnvLightAlarm->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_64->addWidget(lineEdit_whiteLampEnvLightAlarm);

        label_369 = new QLabel(groupBox_81);
        label_369->setObjectName(QStringLiteral("label_369"));

        horizontalLayout_64->addWidget(label_369);

        lineEdit_yellowLampEnvLightAlarm = new QLineEdit(groupBox_81);
        lineEdit_yellowLampEnvLightAlarm->setObjectName(QStringLiteral("lineEdit_yellowLampEnvLightAlarm"));
        lineEdit_yellowLampEnvLightAlarm->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_64->addWidget(lineEdit_yellowLampEnvLightAlarm);

        horizontalSpacer_119 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_64->addItem(horizontalSpacer_119);


        verticalLayout_59->addWidget(groupBox_81);

        groupBox_82 = new QGroupBox(groupBox_83);
        groupBox_82->setObjectName(QStringLiteral("groupBox_82"));
        sizePolicy1.setHeightForWidth(groupBox_82->sizePolicy().hasHeightForWidth());
        groupBox_82->setSizePolicy(sizePolicy1);
        horizontalLayout_63 = new QHBoxLayout(groupBox_82);
        horizontalLayout_63->setSpacing(6);
        horizontalLayout_63->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_63->setObjectName(QStringLiteral("horizontalLayout_63"));
        horizontalLayout_63->setContentsMargins(5, 5, 5, 5);
        label_367 = new QLabel(groupBox_82);
        label_367->setObjectName(QStringLiteral("label_367"));

        horizontalLayout_63->addWidget(label_367);

        lineEdit_whiteLampPupilGray = new QLineEdit(groupBox_82);
        lineEdit_whiteLampPupilGray->setObjectName(QStringLiteral("lineEdit_whiteLampPupilGray"));
        lineEdit_whiteLampPupilGray->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_63->addWidget(lineEdit_whiteLampPupilGray);

        label_366 = new QLabel(groupBox_82);
        label_366->setObjectName(QStringLiteral("label_366"));

        horizontalLayout_63->addWidget(label_366);

        lineEdit_yellowLampPupilGray = new QLineEdit(groupBox_82);
        lineEdit_yellowLampPupilGray->setObjectName(QStringLiteral("lineEdit_yellowLampPupilGray"));
        lineEdit_yellowLampPupilGray->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_63->addWidget(lineEdit_yellowLampPupilGray);

        horizontalSpacer_120 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_63->addItem(horizontalSpacer_120);


        verticalLayout_59->addWidget(groupBox_82);


        verticalLayout_19->addLayout(verticalLayout_59);

        verticalLayout_58 = new QVBoxLayout();
        verticalLayout_58->setSpacing(6);
        verticalLayout_58->setObjectName(QStringLiteral("verticalLayout_58"));

        verticalLayout_19->addLayout(verticalLayout_58);


        verticalLayout_12->addLayout(verticalLayout_19);

        groupBox_87 = new QGroupBox(groupBox_83);
        groupBox_87->setObjectName(QStringLiteral("groupBox_87"));
        verticalLayout_17 = new QVBoxLayout(groupBox_87);
        verticalLayout_17->setSpacing(3);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_65 = new QHBoxLayout();
        horizontalLayout_65->setSpacing(6);
        horizontalLayout_65->setObjectName(QStringLiteral("horizontalLayout_65"));
        label_133 = new QLabel(groupBox_87);
        label_133->setObjectName(QStringLiteral("label_133"));
        label_133->setMinimumSize(QSize(65, 0));

        horizontalLayout_65->addWidget(label_133);

        lineEdit_focusUnite = new QLineEdit(groupBox_87);
        lineEdit_focusUnite->setObjectName(QStringLiteral("lineEdit_focusUnite"));
        lineEdit_focusUnite->setMinimumSize(QSize(50, 0));
        lineEdit_focusUnite->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_65->addWidget(lineEdit_focusUnite);

        label_132 = new QLabel(groupBox_87);
        label_132->setObjectName(QStringLiteral("label_132"));

        horizontalLayout_65->addWidget(label_132);

        lineEdit_shutterOpen = new QLineEdit(groupBox_87);
        lineEdit_shutterOpen->setObjectName(QStringLiteral("lineEdit_shutterOpen"));
        sizePolicy8.setHeightForWidth(lineEdit_shutterOpen->sizePolicy().hasHeightForWidth());
        lineEdit_shutterOpen->setSizePolicy(sizePolicy8);
        lineEdit_shutterOpen->setMinimumSize(QSize(50, 0));
        lineEdit_shutterOpen->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_65->addWidget(lineEdit_shutterOpen);

        horizontalSpacer_28 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_65->addItem(horizontalSpacer_28);

        horizontalSpacer_92 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_65->addItem(horizontalSpacer_92);


        verticalLayout_17->addLayout(horizontalLayout_65);

        gridLayout_37 = new QGridLayout();
        gridLayout_37->setSpacing(6);
        gridLayout_37->setObjectName(QStringLiteral("gridLayout_37"));
        lineEdit_centerX = new QLineEdit(groupBox_87);
        lineEdit_centerX->setObjectName(QStringLiteral("lineEdit_centerX"));
        lineEdit_centerX->setMinimumSize(QSize(50, 0));
        lineEdit_centerX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_37->addWidget(lineEdit_centerX, 0, 1, 1, 1);

        lineEdit_centerY = new QLineEdit(groupBox_87);
        lineEdit_centerY->setObjectName(QStringLiteral("lineEdit_centerY"));
        lineEdit_centerY->setMinimumSize(QSize(50, 0));
        lineEdit_centerY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_37->addWidget(lineEdit_centerY, 0, 3, 1, 1);

        label_358 = new QLabel(groupBox_87);
        label_358->setObjectName(QStringLiteral("label_358"));
        label_358->setMinimumSize(QSize(65, 0));

        gridLayout_37->addWidget(label_358, 1, 0, 1, 1);

        label_354 = new QLabel(groupBox_87);
        label_354->setObjectName(QStringLiteral("label_354"));

        gridLayout_37->addWidget(label_354, 0, 2, 1, 1);

        label_355 = new QLabel(groupBox_87);
        label_355->setObjectName(QStringLiteral("label_355"));
        label_355->setMinimumSize(QSize(65, 0));

        gridLayout_37->addWidget(label_355, 0, 0, 1, 1);

        lineEdit_secondaryCenterY = new QLineEdit(groupBox_87);
        lineEdit_secondaryCenterY->setObjectName(QStringLiteral("lineEdit_secondaryCenterY"));
        lineEdit_secondaryCenterY->setMinimumSize(QSize(50, 0));
        lineEdit_secondaryCenterY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_37->addWidget(lineEdit_secondaryCenterY, 1, 3, 1, 1);

        horizontalSpacer_95 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_37->addItem(horizontalSpacer_95, 0, 4, 1, 2);

        horizontalSpacer_96 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_37->addItem(horizontalSpacer_96, 1, 4, 1, 2);

        lineEdit_secondaryCenterX = new QLineEdit(groupBox_87);
        lineEdit_secondaryCenterX->setObjectName(QStringLiteral("lineEdit_secondaryCenterX"));
        lineEdit_secondaryCenterX->setMinimumSize(QSize(50, 0));
        lineEdit_secondaryCenterX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_37->addWidget(lineEdit_secondaryCenterX, 1, 1, 1, 1);

        label_359 = new QLabel(groupBox_87);
        label_359->setObjectName(QStringLiteral("label_359"));

        gridLayout_37->addWidget(label_359, 1, 2, 1, 1);

        horizontalSpacer_34 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_37->addItem(horizontalSpacer_34, 0, 6, 1, 1);

        horizontalSpacer_35 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_37->addItem(horizontalSpacer_35, 1, 6, 1, 1);


        verticalLayout_17->addLayout(gridLayout_37);


        verticalLayout_12->addWidget(groupBox_87);

        groupBox_21 = new QGroupBox(groupBox_83);
        groupBox_21->setObjectName(QStringLiteral("groupBox_21"));
        groupBox_21->setMinimumSize(QSize(0, 0));
        gridLayout_9 = new QGridLayout(groupBox_21);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(5);
        gridLayout_9->setVerticalSpacing(3);
        gridLayout_9->setContentsMargins(3, 3, 3, 3);
        label_360 = new QLabel(groupBox_21);
        label_360->setObjectName(QStringLiteral("label_360"));
        label_360->setMinimumSize(QSize(30, 0));

        gridLayout_9->addWidget(label_360, 0, 4, 1, 1);

        label_357 = new QLabel(groupBox_21);
        label_357->setObjectName(QStringLiteral("label_357"));
        label_357->setMinimumSize(QSize(10, 0));

        gridLayout_9->addWidget(label_357, 0, 8, 1, 1);

        lineEdit_lightCorrectionY = new QLineEdit(groupBox_21);
        lineEdit_lightCorrectionY->setObjectName(QStringLiteral("lineEdit_lightCorrectionY"));
        lineEdit_lightCorrectionY->setMinimumSize(QSize(50, 0));
        lineEdit_lightCorrectionY->setMaximumSize(QSize(50, 16777215));

        gridLayout_9->addWidget(lineEdit_lightCorrectionY, 0, 9, 1, 1);

        lineEdit_lightCorrectionFocus = new QLineEdit(groupBox_21);
        lineEdit_lightCorrectionFocus->setObjectName(QStringLiteral("lineEdit_lightCorrectionFocus"));
        lineEdit_lightCorrectionFocus->setMinimumSize(QSize(50, 0));
        lineEdit_lightCorrectionFocus->setMaximumSize(QSize(50, 16777215));

        gridLayout_9->addWidget(lineEdit_lightCorrectionFocus, 0, 5, 1, 1);

        label_131 = new QLabel(groupBox_21);
        label_131->setObjectName(QStringLiteral("label_131"));
        label_131->setMinimumSize(QSize(50, 0));

        gridLayout_9->addWidget(label_131, 0, 0, 1, 1);

        lineEdit_lightCorrectionX = new QLineEdit(groupBox_21);
        lineEdit_lightCorrectionX->setObjectName(QStringLiteral("lineEdit_lightCorrectionX"));
        sizePolicy8.setHeightForWidth(lineEdit_lightCorrectionX->sizePolicy().hasHeightForWidth());
        lineEdit_lightCorrectionX->setSizePolicy(sizePolicy8);
        lineEdit_lightCorrectionX->setMinimumSize(QSize(50, 0));
        lineEdit_lightCorrectionX->setMaximumSize(QSize(50, 16777215));

        gridLayout_9->addWidget(lineEdit_lightCorrectionX, 0, 7, 1, 1);

        lineEdit_castLightDA = new QLineEdit(groupBox_21);
        lineEdit_castLightDA->setObjectName(QStringLiteral("lineEdit_castLightDA"));
        sizePolicy8.setHeightForWidth(lineEdit_castLightDA->sizePolicy().hasHeightForWidth());
        lineEdit_castLightDA->setSizePolicy(sizePolicy8);
        lineEdit_castLightDA->setMinimumSize(QSize(50, 0));
        lineEdit_castLightDA->setMaximumSize(QSize(50, 16777215));

        gridLayout_9->addWidget(lineEdit_castLightDA, 0, 1, 1, 1);

        label_356 = new QLabel(groupBox_21);
        label_356->setObjectName(QStringLiteral("label_356"));
        label_356->setMinimumSize(QSize(10, 0));

        gridLayout_9->addWidget(label_356, 0, 6, 1, 1);


        verticalLayout_12->addWidget(groupBox_21);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);


        horizontalLayout_23->addWidget(groupBox_83);

        horizontalSpacer_37 = new QSpacerItem(33, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_37);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_18 = new QGroupBox(tab_3);
        groupBox_18->setObjectName(QStringLiteral("groupBox_18"));
        sizePolicy1.setHeightForWidth(groupBox_18->sizePolicy().hasHeightForWidth());
        groupBox_18->setSizePolicy(sizePolicy1);
        groupBox_18->setMinimumSize(QSize(0, 0));
        groupBox_18->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_22 = new QHBoxLayout(groupBox_18);
        horizontalLayout_22->setSpacing(3);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        tableView_XYDistTable = new GenericTable(groupBox_18);
        tableView_XYDistTable->setObjectName(QStringLiteral("tableView_XYDistTable"));
        sizePolicy2.setHeightForWidth(tableView_XYDistTable->sizePolicy().hasHeightForWidth());
        tableView_XYDistTable->setSizePolicy(sizePolicy2);
        tableView_XYDistTable->setMinimumSize(QSize(123, 524));
        tableView_XYDistTable->setMaximumSize(QSize(123, 16777215));
        tableView_XYDistTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_XYDistTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_XYDistTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_XYDistTable->horizontalHeader()->setStretchLastSection(true);
        tableView_XYDistTable->verticalHeader()->setVisible(false);
        tableView_XYDistTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_XYDistTable->verticalHeader()->setMinimumSectionSize(20);
        tableView_XYDistTable->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_16->addWidget(tableView_XYDistTable);

        tableView_focalPosTable = new GenericTable(groupBox_18);
        tableView_focalPosTable->setObjectName(QStringLiteral("tableView_focalPosTable"));
        sizePolicy2.setHeightForWidth(tableView_focalPosTable->sizePolicy().hasHeightForWidth());
        tableView_focalPosTable->setSizePolicy(sizePolicy2);
        tableView_focalPosTable->setMinimumSize(QSize(483, 524));
        tableView_focalPosTable->setMaximumSize(QSize(483, 16777215));
        tableView_focalPosTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_focalPosTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_focalPosTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_focalPosTable->horizontalHeader()->setHighlightSections(true);
        tableView_focalPosTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_focalPosTable->horizontalHeader()->setStretchLastSection(true);
        tableView_focalPosTable->verticalHeader()->setVisible(false);
        tableView_focalPosTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_focalPosTable->verticalHeader()->setMinimumSectionSize(20);
        tableView_focalPosTable->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_16->addWidget(tableView_focalPosTable);


        horizontalLayout_22->addLayout(horizontalLayout_16);


        verticalLayout_7->addWidget(groupBox_18);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setMaximumSize(QSize(136, 16777215));
        verticalLayout_11 = new QVBoxLayout(groupBox_9);
        verticalLayout_11->setSpacing(5);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(5, 5, 5, 5);
        tableView_colorSlotPos = new GenericTable(groupBox_9);
        tableView_colorSlotPos->setObjectName(QStringLiteral("tableView_colorSlotPos"));
        tableView_colorSlotPos->setMinimumSize(QSize(123, 143));
        tableView_colorSlotPos->setMaximumSize(QSize(16777215, 16777215));
        tableView_colorSlotPos->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_colorSlotPos->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_colorSlotPos->horizontalHeader()->setDefaultSectionSize(60);
        tableView_colorSlotPos->horizontalHeader()->setHighlightSections(false);
        tableView_colorSlotPos->horizontalHeader()->setMinimumSectionSize(60);
        tableView_colorSlotPos->horizontalHeader()->setStretchLastSection(true);
        tableView_colorSlotPos->verticalHeader()->setVisible(false);
        tableView_colorSlotPos->verticalHeader()->setCascadingSectionResizes(true);
        tableView_colorSlotPos->verticalHeader()->setDefaultSectionSize(20);
        tableView_colorSlotPos->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_11->addWidget(tableView_colorSlotPos);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        horizontalLayout_18->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(tab_3);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setMaximumSize(QSize(136, 16777215));
        verticalLayout_13 = new QVBoxLayout(groupBox_10);
        verticalLayout_13->setSpacing(5);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(5, 5, 5, 5);
        tableView_spotSlotPos = new GenericTable(groupBox_10);
        tableView_spotSlotPos->setObjectName(QStringLiteral("tableView_spotSlotPos"));
        tableView_spotSlotPos->setMinimumSize(QSize(123, 183));
        tableView_spotSlotPos->setMaximumSize(QSize(16777215, 16777215));
        tableView_spotSlotPos->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_spotSlotPos->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_spotSlotPos->horizontalHeader()->setDefaultSectionSize(60);
        tableView_spotSlotPos->horizontalHeader()->setHighlightSections(false);
        tableView_spotSlotPos->horizontalHeader()->setMinimumSectionSize(60);
        tableView_spotSlotPos->horizontalHeader()->setStretchLastSection(true);
        tableView_spotSlotPos->verticalHeader()->setVisible(false);
        tableView_spotSlotPos->verticalHeader()->setDefaultSectionSize(20);
        tableView_spotSlotPos->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_13->addWidget(tableView_spotSlotPos);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_2);


        horizontalLayout_18->addWidget(groupBox_10);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_33);

        groupBox_20 = new QGroupBox(tab_3);
        groupBox_20->setObjectName(QStringLiteral("groupBox_20"));
        groupBox_20->setMaximumSize(QSize(136, 16777215));
        verticalLayout_18 = new QVBoxLayout(groupBox_20);
        verticalLayout_18->setSpacing(5);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(5, 5, 5, 5);
        tableView_speedStepTimeTable = new GenericTable(groupBox_20);
        tableView_speedStepTimeTable->setObjectName(QStringLiteral("tableView_speedStepTimeTable"));
        tableView_speedStepTimeTable->setMinimumSize(QSize(123, 163));
        tableView_speedStepTimeTable->setMaximumSize(QSize(16777215, 16777215));
        tableView_speedStepTimeTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_speedStepTimeTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_speedStepTimeTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_speedStepTimeTable->horizontalHeader()->setHighlightSections(false);
        tableView_speedStepTimeTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_speedStepTimeTable->horizontalHeader()->setStretchLastSection(true);
        tableView_speedStepTimeTable->verticalHeader()->setVisible(false);
        tableView_speedStepTimeTable->verticalHeader()->setCascadingSectionResizes(true);
        tableView_speedStepTimeTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_speedStepTimeTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_18->addWidget(tableView_speedStepTimeTable);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_31 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_31);

        label_70 = new QLabel(groupBox_20);
        label_70->setObjectName(QStringLiteral("label_70"));

        horizontalLayout_8->addWidget(label_70);

        lineEdit_stepLength = new QLineEdit(groupBox_20);
        lineEdit_stepLength->setObjectName(QStringLiteral("lineEdit_stepLength"));
        lineEdit_stepLength->setMinimumSize(QSize(60, 0));
        lineEdit_stepLength->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_8->addWidget(lineEdit_stepLength);


        verticalLayout_18->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_3);


        horizontalLayout_18->addWidget(groupBox_20);

        groupBox_22 = new QGroupBox(tab_3);
        groupBox_22->setObjectName(QStringLiteral("groupBox_22"));
        groupBox_22->setMaximumSize(QSize(138, 16777215));
        verticalLayout_24 = new QVBoxLayout(groupBox_22);
        verticalLayout_24->setSpacing(5);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(5, 5, 5, 5);
        tableView_diamondFocalPosTable = new GenericTable(groupBox_22);
        tableView_diamondFocalPosTable->setObjectName(QStringLiteral("tableView_diamondFocalPosTable"));
        tableView_diamondFocalPosTable->setMinimumSize(QSize(123, 163));
        tableView_diamondFocalPosTable->setMaximumSize(QSize(16777215, 16777215));
        tableView_diamondFocalPosTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_diamondFocalPosTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_diamondFocalPosTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_diamondFocalPosTable->horizontalHeader()->setHighlightSections(false);
        tableView_diamondFocalPosTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_diamondFocalPosTable->horizontalHeader()->setStretchLastSection(true);
        tableView_diamondFocalPosTable->verticalHeader()->setVisible(false);
        tableView_diamondFocalPosTable->verticalHeader()->setCascadingSectionResizes(true);
        tableView_diamondFocalPosTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_diamondFocalPosTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_24->addWidget(tableView_diamondFocalPosTable);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_76 = new QLabel(groupBox_22);
        label_76->setObjectName(QStringLiteral("label_76"));
        label_76->setMinimumSize(QSize(15, 0));

        horizontalLayout_17->addWidget(label_76);

        lineEdit_diamondCenterX = new QLineEdit(groupBox_22);
        lineEdit_diamondCenterX->setObjectName(QStringLiteral("lineEdit_diamondCenterX"));
        lineEdit_diamondCenterX->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_17->addWidget(lineEdit_diamondCenterX);

        label_74 = new QLabel(groupBox_22);
        label_74->setObjectName(QStringLiteral("label_74"));
        label_74->setMinimumSize(QSize(15, 0));

        horizontalLayout_17->addWidget(label_74);

        lineEdit_diamondCenterY = new QLineEdit(groupBox_22);
        lineEdit_diamondCenterY->setObjectName(QStringLiteral("lineEdit_diamondCenterY"));
        lineEdit_diamondCenterY->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_17->addWidget(lineEdit_diamondCenterY);


        verticalLayout_24->addLayout(horizontalLayout_17);

        verticalSpacer_4 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_24->addItem(verticalSpacer_4);


        horizontalLayout_18->addWidget(groupBox_22);


        verticalLayout_7->addLayout(horizontalLayout_18);


        horizontalLayout_23->addLayout(verticalLayout_7);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_30);

        groupBox_17 = new QGroupBox(tab_3);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        groupBox_17->setMinimumSize(QSize(0, 0));
        groupBox_17->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_14 = new QVBoxLayout(groupBox_17);
        verticalLayout_14->setSpacing(3);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(3, 3, 3, 3);
        tableView_dbColorSpotPosTable = new GenericTable(groupBox_17);
        tableView_dbColorSpotPosTable->setObjectName(QStringLiteral("tableView_dbColorSpotPosTable"));
        tableView_dbColorSpotPosTable->setMinimumSize(QSize(206, 0));
        tableView_dbColorSpotPosTable->setMaximumSize(QSize(206, 16777215));
        tableView_dbColorSpotPosTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_dbColorSpotPosTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_dbColorSpotPosTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_dbColorSpotPosTable->horizontalHeader()->setHighlightSections(false);
        tableView_dbColorSpotPosTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_dbColorSpotPosTable->horizontalHeader()->setStretchLastSection(true);
        tableView_dbColorSpotPosTable->verticalHeader()->setVisible(false);
        tableView_dbColorSpotPosTable->verticalHeader()->setCascadingSectionResizes(true);
        tableView_dbColorSpotPosTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_dbColorSpotPosTable->verticalHeader()->setMinimumSectionSize(20);
        tableView_dbColorSpotPosTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout_14->addWidget(tableView_dbColorSpotPosTable);


        horizontalLayout_23->addWidget(groupBox_17);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_32);

        groupBox_19 = new QGroupBox(tab_3);
        groupBox_19->setObjectName(QStringLiteral("groupBox_19"));
        verticalLayout_20 = new QVBoxLayout(groupBox_19);
        verticalLayout_20->setSpacing(3);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(3, 3, 3, 3);
        tableView_dbAngleDampingTable = new GenericTable(groupBox_19);
        tableView_dbAngleDampingTable->setObjectName(QStringLiteral("tableView_dbAngleDampingTable"));
        tableView_dbAngleDampingTable->setMinimumSize(QSize(143, 0));
        tableView_dbAngleDampingTable->setMaximumSize(QSize(143, 16777215));
        tableView_dbAngleDampingTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_dbAngleDampingTable->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_dbAngleDampingTable->horizontalHeader()->setDefaultSectionSize(60);
        tableView_dbAngleDampingTable->horizontalHeader()->setHighlightSections(false);
        tableView_dbAngleDampingTable->horizontalHeader()->setMinimumSectionSize(60);
        tableView_dbAngleDampingTable->horizontalHeader()->setStretchLastSection(true);
        tableView_dbAngleDampingTable->verticalHeader()->setVisible(false);
        tableView_dbAngleDampingTable->verticalHeader()->setDefaultSectionSize(20);
        tableView_dbAngleDampingTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_20->addWidget(tableView_dbAngleDampingTable);


        horizontalLayout_23->addWidget(groupBox_19);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_16 = new QVBoxLayout(tab_2);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        tableView_mainMotorPosTable = new MotorPosTable(tab_2);
        tableView_mainMotorPosTable->setObjectName(QStringLiteral("tableView_mainMotorPosTable"));

        verticalLayout_16->addWidget(tableView_mainMotorPosTable);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_11 = new QHBoxLayout(tab_4);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        tableView_secondaryPosTable = new MotorPosTable(tab_4);
        tableView_secondaryPosTable->setObjectName(QStringLiteral("tableView_secondaryPosTable"));

        horizontalLayout_11->addWidget(tableView_secondaryPosTable);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(action_chooseDevice);
        mainToolBar->addAction(action_saveConfig);
        mainToolBar->addAction(action_readConfigFromLocal);
        mainToolBar->addAction(action_updateConfigToLower);
        mainToolBar->addAction(action_downloadConfig);
        mainToolBar->addAction(action_saveLocalData);
        mainToolBar->addAction(action_readLocalData);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_5->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        comboBox_color->setCurrentIndex(0);
        comboBox_spotSize->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_chooseDevice->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\256\276\345\244\207", Q_NULLPTR));
        action_saveConfig->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
        action_saveConfig->setIconText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_saveConfig->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256\346\226\207\344\273\266\345\210\260\346\234\254\345\234\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_readConfigFromLocal->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_readConfigFromLocal->setToolTip(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\234\254\345\234\260\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_updateConfigToLower->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_updateConfigToLower->setToolTip(QApplication::translate("MainWindow", "\344\270\212\344\274\240\351\205\215\347\275\256\346\226\207\344\273\266\345\210\260\344\270\213\344\275\215\346\234\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_downloadConfig->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_downloadConfig->setToolTip(QApplication::translate("MainWindow", "\344\273\216\344\270\213\344\275\215\346\234\272\344\270\213\350\275\275\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_readLocalData->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\234\254\345\234\260\346\225\260\346\215\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_readLocalData->setToolTip(QApplication::translate("MainWindow", "\344\273\216\346\234\254\345\234\260\350\257\273\345\217\226\346\225\260\346\215\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_saveLocalData->setText(QApplication::translate("MainWindow", "\345\255\230\345\202\250\346\234\254\345\234\260\346\225\260\346\215\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_saveLocalData->setToolTip(QApplication::translate("MainWindow", "\345\255\230\345\202\250\346\225\260\346\215\256\344\277\241\346\201\257\350\241\250\345\210\260\346\234\254\345\234\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\345\222\214\347\201\257\345\205\211\346\265\213\350\257\225", Q_NULLPTR));
        comboBox_lightSelect_1->clear();
        comboBox_lightSelect_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\255\345\277\203\345\233\272\350\247\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\350\203\214\346\231\257\347\201\257", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\255\345\277\203\347\272\242\345\244\226\347\201\257", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\276\271\347\274\230\347\272\242\345\244\226", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\225\234\346\236\266\347\272\242\345\244\226", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\212\225\345\260\204\345\205\211", Q_NULLPTR)
        );
        label_da_RGB_2->setText(QApplication::translate("MainWindow", "DA:", Q_NULLPTR));
        checkBox_centerLightAndOtherDASync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_light1->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_13), QApplication::translate("MainWindow", "\344\270\255\345\277\203\345\233\272\350\247\206\347\255\211", Q_NULLPTR));
        comboBox_lightSelect_2->clear();
        comboBox_lightSelect_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\244\247\350\217\261\345\275\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\260\217\350\217\261\345\275\242", Q_NULLPTR)
        );
        comboBox_lampIndex->clear();
        comboBox_lampIndex->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
        );
        label_da_RGB_3->setText(QApplication::translate("MainWindow", "DA:", Q_NULLPTR));
        checkBox_spinBox_bigAndSmallDiamondDASync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_light2->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_14), QApplication::translate("MainWindow", "\345\244\247\345\260\217\350\217\261\345\275\242", Q_NULLPTR));
        label_da_RGB_4->setText(QApplication::translate("MainWindow", "RGB:", Q_NULLPTR));
        checkBox_whiteLightDASync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_light3->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_15), QApplication::translate("MainWindow", "\347\231\275\350\211\262\350\203\214\346\231\257\345\205\211", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\224\265\346\234\272", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\347\253\226\345\220\221\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        checkBox_testChinHoz->setText(QString());
        checkBox_testChinVert->setText(QString());
        pushButton_relativeMoveChin->setText(QApplication::translate("MainWindow", "\347\233\270\345\257\271\347\247\273\345\212\250", Q_NULLPTR));
        pushButton_absoluteMoveChin->setText(QApplication::translate("MainWindow", "\347\273\235\345\257\271\347\247\273\345\212\250", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\344\272\224\347\224\265\346\234\272", Q_NULLPTR));
        checkBox_testColor->setText(QString());
        checkBox_testFocus->setText(QString());
        checkBox_testSpot->setText(QString());
        checkBox_testX->setText(QString());
        checkBox_testY->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "X\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Y\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", Q_NULLPTR));
        pushButton_relativeMove5Motors->setText(QApplication::translate("MainWindow", "\347\233\270\345\257\271\347\247\273\345\212\250", Q_NULLPTR));
        pushButton_absoluteMove5Motors->setText(QApplication::translate("MainWindow", "\347\273\235\345\257\271\347\247\273\345\212\250", Q_NULLPTR));
        groupBox_resetMotor->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\345\244\215\344\275\215", Q_NULLPTR));
        radioButton_xMotor->setText(QApplication::translate("MainWindow", "X\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_focusMotor->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_spotMotor->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_chinHozMotor->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\346\260\264\345\271\263\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_yMotor->setText(QApplication::translate("MainWindow", "Y\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_colorMotor->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_shutterMotor->setText(QApplication::translate("MainWindow", "\345\277\253\351\227\250\347\224\265\346\234\272", Q_NULLPTR));
        radioButton_chinVertMotor->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\253\226\345\220\221\347\224\265\346\234\272", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215\351\200\237\345\272\246:", Q_NULLPTR));
        pushButton_resetCheckedMotors->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215\347\224\265\346\234\272", Q_NULLPTR));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\347\247\273\345\212\250\350\214\203\345\233\264", Q_NULLPTR));
        label_xMotorRange->setText(QString());
        label_focalMotorRange->setText(QString());
        label_chinVertMotorRange->setText(QString());
        label_colorMotorRange->setText(QString());
        label_58->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\347\224\265\346\234\272:", Q_NULLPTR));
        label_yMotorRange->setText(QString());
        label_spotMotorRange->setText(QString());
        label_52->setText(QApplication::translate("MainWindow", "x\347\224\265\346\234\272:", Q_NULLPTR));
        label_shutterMotorRange->setText(QString());
        label_62->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\347\224\265\346\234\272:", Q_NULLPTR));
        label_65->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\253\226\345\220\221\347\224\265\346\234\272:", Q_NULLPTR));
        label_68->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\346\260\264\345\271\263\347\224\265\346\234\272:", Q_NULLPTR));
        label_54->setText(QApplication::translate("MainWindow", "y\347\224\265\346\234\272:", Q_NULLPTR));
        label_56->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\224\265\346\234\272:", Q_NULLPTR));
        label_chinHozMotorRange->setText(QString());
        label_64->setText(QApplication::translate("MainWindow", "\345\277\253\351\227\250\347\224\265\346\234\272:", Q_NULLPTR));
        label_87->setText(QApplication::translate("MainWindow", "X\347\224\265\346\234\272:", Q_NULLPTR));
        label_posX->setText(QString());
        label_85->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\347\224\265\346\234\272:", Q_NULLPTR));
        label_posFocus->setText(QString());
        label_90->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\347\224\265\346\234\272:", Q_NULLPTR));
        label_posSpot->setText(QString());
        label_88->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\346\260\264\345\271\263:", Q_NULLPTR));
        label_posChinHoz->setText(QString());
        label_84->setText(QApplication::translate("MainWindow", "Y\347\224\265\346\234\272;", Q_NULLPTR));
        label_posY->setText(QString());
        label_89->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\224\265\346\234\272:", Q_NULLPTR));
        label_posColor->setText(QString());
        label_86->setText(QApplication::translate("MainWindow", "\345\277\253\351\227\250\347\224\265\346\234\272:", Q_NULLPTR));
        label_posShutter->setText(QString());
        label_75->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\253\226\345\220\221:", Q_NULLPTR));
        label_posChinVert->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "\347\224\265\346\234\272\345\275\223\345\211\215\344\275\215\347\275\256", Q_NULLPTR));
        label_47->setText(QApplication::translate("MainWindow", "X\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateX->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_48->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateFocus->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_51->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateSpot->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\346\260\264\345\271\263\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateChinHoz->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_57->setText(QApplication::translate("MainWindow", "Y\347\224\265\346\234\272;", Q_NULLPTR));
        label_stateY->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_61->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateColor->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "\345\277\253\351\227\250\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateShutter->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        label_59->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\253\226\345\220\221\347\224\265\346\234\272:", Q_NULLPTR));
        label_stateChinVert->setText(QApplication::translate("MainWindow", "\351\227\262", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "\347\224\265\346\234\272\347\212\266\346\200\201", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "\345\205\266\345\256\203\347\212\266\346\200\201", Q_NULLPTR));
        label_VID->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "PID:", Q_NULLPTR));
        label_castLightDA->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201:", Q_NULLPTR));
        label_connectionStatus->setText(QApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245", Q_NULLPTR));
        label_eyeglassStatus->setText(QApplication::translate("MainWindow", "\346\224\276\344\270\213", Q_NULLPTR));
        label_60->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254:", Q_NULLPTR));
        label_69->setText(QApplication::translate("MainWindow", "\345\272\224\347\255\224\345\231\250\347\212\266\346\200\201:", Q_NULLPTR));
        label_devVer->setText(QApplication::translate("MainWindow", "0x00", Q_NULLPTR));
        label_environmentDA->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_67->setText(QApplication::translate("MainWindow", "\346\212\225\345\260\204\345\205\211DA:", Q_NULLPTR));
        label_answerState->setText(QApplication::translate("MainWindow", "\346\235\276\345\274\200", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "VID:", Q_NULLPTR));
        label_66->setText(QApplication::translate("MainWindow", "\351\225\234\346\236\266\347\212\266\346\200\201:", Q_NULLPTR));
        label_devType->setText(QApplication::translate("MainWindow", "\346\212\225\345\260\204", Q_NULLPTR));
        label_PID->setText(QString());
        label_63->setText(QApplication::translate("MainWindow", "\347\216\257\345\242\203\345\205\211DA:", Q_NULLPTR));
        label_50->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213:", Q_NULLPTR));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        pushButton_chinMoveLeft->setText(QApplication::translate("MainWindow", "\345\267\246", Q_NULLPTR));
        pushButton_chinMoveUp->setText(QApplication::translate("MainWindow", "\344\270\212", Q_NULLPTR));
        pushButton_chinMoveDown->setText(QApplication::translate("MainWindow", "\344\270\213", Q_NULLPTR));
        pushButton_chinMoveRight->setText(QApplication::translate("MainWindow", "\345\217\263", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\345\260\272\345\257\270:", Q_NULLPTR));
        label_videoSize->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "\350\205\256\346\211\230\347\247\273\345\212\250\351\200\237\345\272\246:", Q_NULLPTR));
        pushButton_cameraSwitch->setText(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264 \345\274\200/\345\205\263", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\351\242\234\350\211\262", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262:", Q_NULLPTR));
        comboBox_color->clear();
        comboBox_color->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "R", Q_NULLPTR)
         << QApplication::translate("MainWindow", "G", Q_NULLPTR)
         << QApplication::translate("MainWindow", "B", Q_NULLPTR)
         << QApplication::translate("MainWindow", "--", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("MainWindow", "\345\255\224\344\275\215:", Q_NULLPTR));
        label_71->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        checkBox_colorConfigSync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_colorTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_s->setTitle(QApplication::translate("MainWindow", "\345\205\211\346\226\221", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\345\260\272\345\257\270:", Q_NULLPTR));
        comboBox_spotSize->clear();
        comboBox_spotSize->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "--", Q_NULLPTR)
        );
        label_19->setText(QApplication::translate("MainWindow", "\345\255\224\344\275\215:", Q_NULLPTR));
        label_44->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        checkBox_spotConfigSync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_spotTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "DB", Q_NULLPTR));
        label_46->setText(QApplication::translate("MainWindow", "\345\244\247\345\260\217:", Q_NULLPTR));
        label_82->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\344\275\215\347\275\256:", Q_NULLPTR));
        label_83->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221\344\275\215\347\275\256:", Q_NULLPTR));
        checkBox_DbConfigSync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_dbTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_staticCastPos->setTitle(QApplication::translate("MainWindow", "\351\235\231\346\200\201\346\212\225\345\260\204\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_staticCastTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        label_72->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "X\345\235\220\346\240\207:", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Y\345\235\220\346\240\207:", Q_NULLPTR));
        checkBox_calcFocalDist->setText(QApplication::translate("MainWindow", "\347\256\227\345\207\272\347\204\246\350\267\235", Q_NULLPTR));
        label_73->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        groupBox_moveCastPos->setTitle(QApplication::translate("MainWindow", "\347\247\273\345\212\250\346\212\225\345\260\204\344\275\215\347\275\256", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271X\345\235\220\346\240\207:", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271X\345\235\220\346\240\207:", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271Y\345\235\220\346\240\207:", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271Y\345\235\220\346\240\207:", Q_NULLPTR));
        groupBox_focalTest->setTitle(QApplication::translate("MainWindow", "\347\204\246\350\267\235", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235:", Q_NULLPTR));
        pushButton_focalTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\345\277\253\351\227\250", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\227\266\351\227\264:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\275\215\347\275\256:", Q_NULLPTR));
        checkBox_shutterConfigSync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_shuterTest->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_24->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\351\200\237\345\272\246\346\216\247\345\210\266", Q_NULLPTR));
        label_77->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        label_78->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_80->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262:", Q_NULLPTR));
        label_79->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235:", Q_NULLPTR));
        label_81->setText(QApplication::translate("MainWindow", "\345\205\211\346\226\221:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275\346\265\213\350\257\225", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\351\241\271\347\233\256:", Q_NULLPTR));
        comboBox_testFucntion->clear();
        comboBox_testFucntion->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\235\231\346\200\201\346\212\225\345\260\204\346\265\213\350\257\225", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\247\273\345\212\250\346\212\225\345\260\204\346\265\213\350\257\225", Q_NULLPTR)
        );
        pushButton_testStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\265\213\350\257\225", Q_NULLPTR));
        pushButton_readCache->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\347\274\223\345\255\230", Q_NULLPTR));
        checkBox_IO->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "\346\216\247\345\210\266\344\277\241\346\201\257", Q_NULLPTR));
        checkBox_startRefreshInfo->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\210\267\346\226\260", Q_NULLPTR));
        checkBox_RefreshIO->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\267\346\226\260\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_83->setTitle(QApplication::translate("MainWindow", "\344\270\200\350\210\254\351\205\215\347\275\256", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\274\226\345\217\267:", Q_NULLPTR));
        groupBox_84->setTitle(QApplication::translate("MainWindow", "\345\233\272\350\247\206\347\201\257DA", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\347\202\271:", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "\345\244\247\350\217\261\345\275\242:", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "\345\260\217\350\217\261\345\275\242:", Q_NULLPTR));
        groupBox_85->setTitle(QApplication::translate("MainWindow", "\350\203\214\346\231\257\347\201\257", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "\351\273\204\350\211\262DA:", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\347\231\275\350\211\262RGB:", Q_NULLPTR));
        groupBox_86->setTitle(QApplication::translate("MainWindow", "\347\272\242\345\244\226\347\201\257DA", Q_NULLPTR));
        label_363->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\347\272\242\345\244\226:", Q_NULLPTR));
        label_364->setText(QApplication::translate("MainWindow", "\351\225\234\346\236\266\347\272\242\345\244\226:", Q_NULLPTR));
        label_362->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\347\272\242\345\244\226:", Q_NULLPTR));
        groupBox_81->setTitle(QApplication::translate("MainWindow", "\347\216\257\345\242\203\345\205\211\346\212\245\350\255\246\351\230\210\345\200\274DA:", Q_NULLPTR));
        label_368->setText(QApplication::translate("MainWindow", "\347\231\275\350\203\214\346\231\257\345\205\211:", Q_NULLPTR));
        label_369->setText(QApplication::translate("MainWindow", "\351\273\204\350\203\214\346\231\257\345\205\211:", Q_NULLPTR));
        groupBox_82->setTitle(QApplication::translate("MainWindow", "\347\236\263\345\255\224\347\201\260\345\272\246\351\230\210\345\200\274:", Q_NULLPTR));
        label_367->setText(QApplication::translate("MainWindow", "\347\231\275\350\203\214\346\231\257\345\205\211:", Q_NULLPTR));
        label_366->setText(QApplication::translate("MainWindow", "\351\273\204\350\203\214\346\231\257\345\205\211:", Q_NULLPTR));
        groupBox_87->setTitle(QApplication::translate("MainWindow", "\344\275\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        label_133->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235\350\201\224\345\212\250:", Q_NULLPTR));
        label_132->setText(QApplication::translate("MainWindow", "\345\277\253\351\227\250\345\274\200\344\275\215:", Q_NULLPTR));
        label_358->setText(QApplication::translate("MainWindow", "\345\211\257\344\270\255\345\277\203\344\275\215 X:", Q_NULLPTR));
        label_354->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_355->setText(QApplication::translate("MainWindow", "\346\255\243\344\270\255\345\277\203\344\275\215 X:", Q_NULLPTR));
        label_359->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        groupBox_21->setTitle(QApplication::translate("MainWindow", "\345\205\211\345\274\272\346\240\241\346\255\243", Q_NULLPTR));
        label_360->setText(QApplication::translate("MainWindow", "\347\204\246\350\267\235:", Q_NULLPTR));
        label_357->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_131->setText(QApplication::translate("MainWindow", "\346\212\225\345\260\204\345\205\211DA:", Q_NULLPTR));
        label_356->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        groupBox_18->setTitle(QApplication::translate("MainWindow", "\347\204\246\350\267\235\345\217\202\346\225\260\350\241\250", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\351\242\234\350\211\262\350\241\250", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\345\205\211\346\226\221\350\241\250", Q_NULLPTR));
        groupBox_20->setTitle(QApplication::translate("MainWindow", "\346\212\225\345\260\204\346\257\217\346\255\245\346\227\266\351\227\264\350\241\250", Q_NULLPTR));
        label_70->setText(QApplication::translate("MainWindow", "\346\255\245\351\225\277:", Q_NULLPTR));
        groupBox_22->setTitle(QApplication::translate("MainWindow", "\350\217\261\345\275\242\344\270\255\345\277\203", Q_NULLPTR));
        label_76->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        label_74->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        groupBox_17->setTitle(QApplication::translate("MainWindow", "DB\345\217\202\346\225\260\350\241\250", Q_NULLPTR));
        groupBox_19->setTitle(QApplication::translate("MainWindow", "0-90\345\272\246DB\350\241\260\345\207\217\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\344\275\215\347\275\256\347\224\265\346\234\272\346\255\243\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\344\275\215\347\275\256\347\224\265\346\234\272\345\211\257\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
