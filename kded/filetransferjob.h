/*
 * Copyright 2013 Albert Vaca <albertvaka@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILETRANSFERJOB_H
#define FILETRANSFERJOB_H

#include <QIODevice>
#include <QTime>
#include <QTemporaryFile>

#include <KJob>
#include <KUrl>
#include <KIO/FileJob>
#include <KIO/Job>
#include <KSharedPtr>

class FileTransferJob
    : public KJob
{
    Q_OBJECT

public:
    FileTransferJob(const QSharedPointer<QIODevice>& origin, int size, const KUrl& destination);
    virtual void start();
    KUrl destination() const { return mDestination; }
    void setDeviceName(const QString &deviceName) {mDeviceName = deviceName;};

public Q_SLOTS:
    void doStart();
    void renameDone(int result);
    void readyRead();
    void open(KIO::Job*);
    void sourceFinished();
    void openFinished(KJob*);

protected:
    virtual bool doKill();
private:
    void startTransfer();
    QSharedPointer<QIODevice> mOrigin;
    KIO::FileJob* mDestinationJob;
    QString mDeviceName;
    KUrl mDestination;
    QTime m_time;
    qulonglong m_speedBytes;
    int mSize;
    int mWritten;

};

#endif
