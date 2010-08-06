/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef EQUIRECTANGULARPROJECTOR_H
#define EQUIRECTANGULARPROJECTOR_H

#include "projector.h"


class EquirectangularProjector : public Projector
{
public:
    EquirectangularProjector(const ViewParams& p);
    virtual SkyMap::Projection type() const;
    virtual double radius() const;
    virtual Vector2f toScreenVec(SkyPoint* o, bool oRefract = true, bool* onVisibleHemisphere = 0) const;
    virtual SkyPoint fromScreen(const QPointF& p, dms* LST, const dms* lat) const;
    virtual QVector< Vector2f > groundPoly(SkyPoint* labelpoint = 0, bool* drawLabel = 0) const;
};

#endif // EQUIRECTANGULARPROJECTOR_H
