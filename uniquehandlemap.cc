/*
 * This file is part of the telepathy-nonsense connection manager.
 * Copyright (C) 2015 Niels Ole Salscheider <niels_ole@salscheider-online.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>
 */
#include "uniquehandlemap.hh"

UniqueHandleMap::UniqueHandleMap()
{
}

const QString UniqueHandleMap::operator[] (const uint handle) const
{
    if (!contains(handle)) {
        return QString();
    }
    return m_knownHandles[handle - 1];
}

uint UniqueHandleMap::operator[] (const QString &bareJid)
{
    int idx = m_knownHandles.indexOf(bareJid);
    if (idx != -1) {
        return idx + 1;
    }

    m_knownHandles.append(bareJid);
    return m_knownHandles.size();
}

bool UniqueHandleMap::contains(const uint handle) const
{
    return (handle > 0u) && (static_cast<uint>(m_knownHandles.size()) > handle - 1);
}

bool UniqueHandleMap::contains(const QString &bareJid) const
{
    return m_knownHandles.contains(bareJid, Qt::CaseInsensitive);
}
