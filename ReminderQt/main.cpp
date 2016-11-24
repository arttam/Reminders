#include "./UI/remainderdlg.h"
#include <QApplication>
#include <QtCore/QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("Reminder");
    a.setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Reminder of logins details");
    QCommandLineOption coHelp = parser.addHelpOption();
    QCommandLineOption coVersion = parser.addVersionOption();

    parser.addOptions({
      {{"t", "type"}, QCoreApplication::translate("main", "Set details source type"), QCoreApplication::translate("main", "type")},
      {{"s", "source"}, QCoreApplication::translate("main", "Set details source path"), QCoreApplication::translate("main", "source")}
    });

    parser.process(a);


    if (!parser.parse(QCoreApplication::arguments())) {
        std::cerr << parser.errorText().toStdString() << std::endl << std::endl;
        parser.showHelp(1);
        return 1;
    }

    if (parser.isSet(coHelp)) {
        parser.showHelp();
        return 0;
    }

    if (parser.isSet(coVersion)) {
        parser.showVersion();
        return 0;
    }

    std::string dType{"file"};
    std::string dSource{"data_sample"};

    if (parser.isSet("t")) {
        dType = parser.value("type").toStdString();
    }

    if (parser.isSet("s")) {
        dSource = parser.value(QString("s")).toStdString();
    }

    RemainderDlg w;
    if (!w.setProvider(dType, dSource)) {
        std::cerr << "Cannot set data provider for: type='" << dType << "', source='" << dSource << "', leaving" << std::endl;
        return 1;
    }

    w.prepare();
    w.show();

    return a.exec();
}
