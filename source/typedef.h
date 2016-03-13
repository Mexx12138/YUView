/*  YUView - YUV player with advanced analytics toolset
*   Copyright (C) 2015  Institut für Nachrichtentechnik
*                       RWTH Aachen University, GERMANY
*
*   YUView is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   YUView is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with YUView.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <QPair>
#include <QSize>
#include <QString>
#include <QHash>
#include <QCache>
#include <QList>

#define INT_INVALID -1

// The default framerate that will be used when we could not guess it.
#define DEFAULT_FRAMERATE 20.0

#ifndef YUVIEW_HASH
#define VERSION_CHECK 0
#define YUVIEW_HASH 0
#else
#define VERSION_CHECK 1
#endif

#define MAX_SCALE_FACTOR 5
#define MAX_RECENT_FILES 5

template <typename T> inline T clip(const T& n, const T& lower, const T& upper) { return std::max(lower, std::min(n, upper)); }

// A pair of two strings
typedef QPair<QString, QString> ValuePair;

// A list of valuePairs (pairs of two strings)
// This class has an additional (and optional title string)
class ValuePairList : public QList<ValuePair>
{
public:
  ValuePairList(QString t="Values")
  {
    title = t;
  }
  QString title;
};

// An info item is just a pair of Strings
// For example: ["File Name", "file.yuv"] or ["Number Frames", "123"]
typedef QPair<QString, QString> infoItem;
// A index range is just a QPair of ints (minimum and maximum)
typedef QPair<int,int> indexRange;

class CacheIdx
 {
 public:
     CacheIdx(const QString &name, const unsigned int idx) { fileName=name; frameIdx=idx; }
     QString fileName;
     unsigned int frameIdx;
 };

 inline bool operator==(const CacheIdx &e1, const CacheIdx &e2)
 {
     return e1.fileName == e2.fileName && e1.frameIdx == e2.frameIdx;
 }

 inline uint qHash(const CacheIdx &cIdx)
 {
     uint tmp = qHash(cIdx.fileName) ^ qHash(cIdx.frameIdx);
     return tmp;
 }

#endif // TYPEDEF_H
