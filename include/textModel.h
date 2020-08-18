#include <QObject>

class TextModel : public QObject
{
    Q_OBJECT

public:
    TextModel(QObject* parent = nullptr );

    Q_INVOKABLE   QString readFromFile(QString url);

    Q_INVOKABLE void writeToFile(QString text);

private:
    QString m_pathToFile;
};
