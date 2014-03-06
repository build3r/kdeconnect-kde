/**
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

#ifndef CLIPBOARDPLUGIN_H
#define CLIPBOARDPLUGIN_H

#include <QObject>
#include <QClipboard>

#include "../kdeconnectplugin.h"
#include "../../networkpackage.h"
#include "../../device.h"

#define PACKAGE_TYPE_CLIPBOARD QLatin1String("kdeconnect.clipboard")

class ClipboardPlugin
    : public KdeConnectPlugin
{
    Q_OBJECT

public:
    explicit ClipboardPlugin(QObject *parent, const QVariantList &args);

public Q_SLOTS:
    virtual bool receivePackage(const NetworkPackage& np);
    virtual void connected() { }
    
private Q_SLOTS:
    void clipboardChanged(QClipboard::Mode mode);

private:
    bool ignore_next_clipboard_change;
    QClipboard *clipboard;
};

#endif
