#include "../include/textModel.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

TextModel::TextModel(QObject *parent) : QObject(parent)
{

}

QString TextModel::readFromFile(QString url)
{
    url.remove(0, 7);
    QFile file(url);
    if(!file.open(QIODevice::ReadOnly)) {
        return "";
    }

    m_pathToFile = url;

    QString text;

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        text += line;
    }

    file.close();
    return text;
}

void TextModel::writeToFile(QString text)
{
    QFile file(m_pathToFile);
      if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
      {
          QTextStream stream(&file);
          stream << text << '\n';
          file.close();
      }
}
