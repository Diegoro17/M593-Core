/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#include <QDebug>
#include "darkstyle.h"

DarkStyle::DarkStyle():
  DarkStyle(styleBase())
{ }

DarkStyle::DarkStyle(QStyle *style):
  QProxyStyle(style)
{ }

QStyle *DarkStyle::styleBase(QStyle *style) const {
  static QStyle *base = !style ? QStyleFactory::create(QStringLiteral("Fusion")) : style;
  return base;
}

QStyle *DarkStyle::baseStyle() const
{
  return styleBase();
}

void DarkStyle::polish(QPalette &palette)
{
  // modify palette to dark
  palette.setColor(QPalette::Window,QColor("#071F2B"));
  palette.setColor(QPalette::WindowText,QColor("#F7F3E8"));/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/
  palette.setColor(QPalette::Disabled,QPalette::WindowText,QColor("#6F8588"));
  palette.setColor(QPalette::Base,QColor("#0B1720"));
  palette.setColor(QPalette::AlternateBase,QColor("#102B31"));
  palette.setColor(QPalette::ToolTipBase,QColor("#FFF7E2"));
  palette.setColor(QPalette::ToolTipText,QColor("#071F2B"));
  palette.setColor(QPalette::Text,QColor("#F7F3E8"));
  palette.setColor(QPalette::Disabled,QPalette::Text,QColor("#6F8588"));
  palette.setColor(QPalette::Dark,QColor("#06161E"));
  palette.setColor(QPalette::Shadow,QColor("#020B10"));
  palette.setColor(QPalette::Button,QColor("#102B31"));
  palette.setColor(QPalette::ButtonText,QColor("#F7F3E8"));
  palette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor("#6F8588"));
  palette.setColor(QPalette::BrightText,QColor("#F5C451"));
  palette.setColor(QPalette::Link,QColor("#E4BC62"));
  palette.setColor(QPalette::Highlight,QColor("#0F766E"));
  palette.setColor(QPalette::Disabled,QPalette::Highlight,QColor("#31565A"));
  palette.setColor(QPalette::HighlightedText,QColor("#FFFFFF"));
  palette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor("#9BA9A9"));
}

void DarkStyle::polish(QApplication *app)
{
  if (!app) return;

// increase font size for better reading,
// setPointSize was reduced from +2 because when applied this way in Qt5, the font is larger than intended for some reason
//  QFont defaultFont = QApplication::font();
//  defaultFont.setPointSize(defaultFont.pointSize()+1);
//  app->setFont(defaultFont);

  // loadstylesheet
  QFile qfDarkstyle(QStringLiteral(":/darkstyle/qss"));
  if (qfDarkstyle.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    // set stylesheet
    QString qsStylesheet = QString::fromLatin1(qfDarkstyle.readAll());
    app->setStyleSheet(qsStylesheet);
    qfDarkstyle.close();
  }
}
