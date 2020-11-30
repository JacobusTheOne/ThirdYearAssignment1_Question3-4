#ifndef JOURNALLIST_H
#define JOURNALLIST_H
#include "journal.h"
#include <QList>


class JournalList
{
public:
    JournalList();
    ~JournalList();
    void addJournal(Journal* j);
    QList<Journal*> getJournal();
private:
    QList<Journal*> list;
};

#endif // JOURNALLIST_H
