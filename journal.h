#ifndef SOFTWARE_H
#define SOFTWARE_H
#include <QString>

class Journal
{
public:
    Journal();
    Journal(QString author,QString title,QString journal,QString pages,
             double year,double volume,double issue);
    void setAuthor(QString author);
    QString getAuthor();

    void setTitle(QString title);
    QString getTitle();

    void setJournal(QString journal);
    QString getJournal();

    void setYear(double year);
    double getYear();

    void setVolume(double volume);
    double getVolume();

    void setIssue(double issue);
    double getIssue();
private:
    QString m_author,m_title,m_journal,m_pages;
    double m_year,m_volume,m_issue;

};

#endif // SOFTWARE_H
