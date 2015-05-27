/* === S Y N F I G ========================================================= */
/*!	\file synfig/rendering/primitive/transformation.h
**	\brief Transformation Header
**
**	$Id$
**
**	\legal
**	......... ... 2015 Ivan Mahonin
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_RENDERING_TRANSFORMATION_H
#define __SYNFIG_RENDERING_TRANSFORMATION_H

/* === H E A D E R S ======================================================= */

#include <ETL/handle>

#include <synfig/vector.h>

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace synfig
{
namespace rendering
{

class Transformation: public etl::shared_object
{
public:
	typedef etl::handle<Transformation> Handle;

	struct TransformedPoint
	{
		Point p;
		Real depth;
		bool visible;

		TransformedPoint(): depth(0.0), visible(true) { }
		explicit TransformedPoint(const Point &p, Real depth = 0.0, bool visible = true):
			p(p), depth(depth), visible(visible) { }
	};

protected:
	virtual TransformedPoint transform_vfunc(const Point &x) const;
	virtual Point get_derivation_vfunc(int level, const Point &x, Real epsilon) const;

public:
	TransformedPoint transform(const Point &x) const;
	Point get_derivation(int level, const Point &x, Real epsilon = 1e-6) const;
};

} /* end namespace rendering */
} /* end namespace synfig */

/* -- E N D ----------------------------------------------------------------- */

#endif