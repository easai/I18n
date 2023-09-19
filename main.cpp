#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include <QLibraryInfo>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "I18n_" + QLocale(locale).name();
    if (translator.load(baseName)) {
      a.installTranslator(&translator);
      break;
    }
  }
  QTranslator stdTranslator;
  for (const QString &locale : uiLanguages) {
    const QString baseName = "qt_" + QLocale(locale).name();
    if (stdTranslator.load(baseName,QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
      qDebug()<<"std";
      a.installTranslator(&stdTranslator);
      break;
    }
  }
  MainWindow w;
  w.show();
  return a.exec();
}
